# Copyright 2026 R4. SPDX-License-Identifier: Apache-2.0
[CmdletBinding()]
param(
    [Parameter(Mandatory)][string]$CompilerRoot,
    [Parameter(Mandatory)][string]$MesaRoot,
    [Parameter(Mandatory)][string]$ShaderRoot,
    [Parameter(Mandatory)][string]$OutputRoot,
    [ValidateRange(1,32)][int]$Jobs = 4
)
Set-StrictMode -Version Latest
$ErrorActionPreference = 'Stop'
if (!$IsWindows -and !$IsLinux) { throw 'Supported hosts: Windows and Linux.' }
. (Join-Path $PSScriptRoot 'MesaSource.ps1')
. (Join-Path $PSScriptRoot 'CInputs.ps1')
. (Join-Path $PSScriptRoot 'Archive.ps1')
$mesa = Get-R4VKMesaSource
$compiler = [IO.Path]::GetFullPath($CompilerRoot, $mesa.workspace)
$prepared = [IO.Path]::GetFullPath($MesaRoot, $mesa.workspace)
$shaders = [IO.Path]::GetFullPath($ShaderRoot, $mesa.workspace)
$output = [IO.Path]::GetFullPath($OutputRoot, $mesa.workspace)
foreach ($protected in @($mesa.unit, $mesa.source, $compiler, $prepared, $shaders)) {
    $prefix = $protected.TrimEnd([IO.Path]::DirectorySeparatorChar) + [IO.Path]::DirectorySeparatorChar
    if ($output -eq $protected -or $output.StartsWith($prefix, [StringComparison]::OrdinalIgnoreCase)) {
        throw 'Native output must be outside source and dependency trees.'
    }
}
$clang = (Get-Command $(if ($IsWindows) { 'clang.exe' } else { 'clang-19' }) -CommandType Application -ErrorAction Stop | Select-Object -First 1).Source
$reported = @(& $clang --version)
if ($LASTEXITCODE -or !$reported.Count -or [string]$reported[0] -notmatch ('(?<![0-9.])' + [regex]::Escape([string]$mesa.lock.host_tools.clang) + '(?![0-9.])')) { throw 'Pinned clang required.' }
$settings = @{}
foreach ($line in Get-Content -LiteralPath (Join-Path $mesa.libraries 'Settings.R4S')) {
    if ($line -match '^([A-Z_]+)=(.+)$') { $settings[$Matches[1]] = $Matches[2] }
}
$zigRoot = [IO.Path]::GetFullPath($settings.ZIG_ROOT.Replace('\', [IO.Path]::DirectorySeparatorChar), $mesa.devkit)
$zig = Join-Path $zigRoot $(if ($IsWindows) { 'zig.exe' } else { 'zig' })
$nakRecord = Get-Content -Raw -LiteralPath (Join-Path $compiler 'build.json') | ConvertFrom-Json
if ($nakRecord.inputs.mesa_lock -ne (Get-R4VKFileHash $mesa.lock_path) -or
    $nakRecord.inputs.mesa_patch -ne (Get-R4VKFileHash (Join-Path $mesa.libraries 'R4NV/Tools/Compiler/MesaStandalone.patch')) -or
    $nakRecord.archive_sha256 -ne (Get-R4VKFileHash (Join-Path $compiler 'R4NAK.a'))) { throw 'NAK dependency differs from its build record.' }
foreach ($item in $nakRecord.inputs.inputs) {
    if ((Get-R4VKFileHash (Join-Path $mesa.libraries ('R4NAK/' + $item.path))) -ne $item.sha256) { throw "NAK input changed: $($item.path)" }
}
$prepare = Get-Content -Raw -LiteralPath (Join-Path $prepared 'prepare.json') | ConvertFrom-Json
$shader = Get-Content -Raw -LiteralPath (Join-Path $shaders 'shaders.json') | ConvertFrom-Json
foreach ($record in @($prepare, $shader)) {
    if ($record.source_manifest_sha256 -ne (Get-R4VKFileHash $mesa.manifest_path) -or
        $record.mesa_lock_sha256 -ne (Get-R4VKFileHash $mesa.lock_path) -or
        $record.source_helper_sha256 -ne (Get-R4VKFileHash (Join-Path $PSScriptRoot 'MesaSource.ps1'))) { throw 'Mesa input preparation is stale.' }
}
if ($prepare.runtime_patch_sha256 -ne (Get-R4VKFileHash (Join-Path $mesa.unit 'Port/MesaRuntime.patch')) -or
    $prepare.prepare_script_sha256 -ne (Get-R4VKFileHash (Join-Path $PSScriptRoot 'Prepare.ps1')) -or
    $shader.generator_patch_sha256 -ne (Get-R4VKFileHash (Join-Path $mesa.unit 'Port/MesaGenerators.patch')) -or
    $shader.prepare_script_sha256 -ne (Get-R4VKFileHash (Join-Path $PSScriptRoot 'PrepareShaders.ps1')) -or
    $shader.shader_tools_lock_sha256 -ne (Get-R4VKFileHash (Join-Path $PSScriptRoot 'ShaderTools.lock.json'))) { throw 'Native generators or patches changed; prepare their outputs again.' }
foreach ($item in $shader.standalone_inputs) {
    if ((Get-R4VKFileHash (Join-Path $mesa.libraries $item.path)) -ne $item.sha256) { throw 'Shader generator source changed.' }
}
foreach ($pair in @(@($prepared, $prepare), @($shaders, $shader))) {
    foreach ($item in $pair[1].outputs) {
        if ((Get-R4VKFileHash (Join-Path $pair[0] $item.path)) -ne $item.sha256) { throw "Prepared input changed: $($item.path)" }
    }
}
$inputs = Get-R4VKNativeCInputs -Mesa $mesa -CompilerRoot $compiler -MesaRoot $prepared -ShaderRoot $shaders -Clang $clang
$paths = @($inputs.sources) + @($mesa.lock_path, $mesa.manifest_path, $zig, $clang,
    (Join-Path $compiler 'build.json'), (Join-Path $prepared 'prepare.json'), (Join-Path $shaders 'shaders.json'),
    (Join-Path $mesa.libraries 'R4NAK/Tools/CInputs.ps1'))
foreach ($directory in @('Port', 'Tools', 'Source', 'Contract')) {
    $path = Join-Path $mesa.unit $directory
    if (Test-Path -LiteralPath $path) {
        $paths += @(Get-ChildItem -LiteralPath $path -Recurse -File | Where-Object Extension -in '.c','.h','.zig','.json','.ps1','.patch' | ForEach-Object FullName)
    }
}
foreach ($directory in $inputs.header_roots) {
    $paths += @(Get-ChildItem -LiteralPath $directory -Recurse -File -Filter '*.h' | ForEach-Object FullName)
}
$records = @(foreach ($path in $paths | Sort-Object -Unique) {
    [ordered]@{path = [IO.Path]::GetRelativePath($mesa.workspace, $path).Replace('\', '/'); sha256 = (Get-R4VKFileHash $path)}
})
$identity = [ordered]@{schema = 1; host = $(if ($IsWindows) { 'Windows-x64' } else { 'Linux-x64' });
    compiler = [string]$reported[0]; nak = $nakRecord.identity; inputs = $records;
    arguments = @($inputs.arguments | ForEach-Object { $_.Replace($mesa.workspace, '<workspace>') })}
$digest = [Security.Cryptography.SHA256]::HashData([Text.Encoding]::UTF8.GetBytes(($identity | ConvertTo-Json -Depth 8 -Compress)))
$id = [Convert]::ToHexString($digest).ToLowerInvariant()
$recordPath = Join-Path $output 'native.json'
if (Test-Path -LiteralPath $recordPath) {
    $previous = Get-Content -Raw -LiteralPath $recordPath | ConvertFrom-Json
    if ($previous.identity -eq $id) {
        $names = @($previous.outputs.path)
        if ($previous.schema -ne 1 -or $previous.c_units -ne $inputs.sources.Count -or
            $names.Count -ne $inputs.sources.Count + 4 -or @($names | Sort-Object -Unique).Count -ne $names.Count -or
            'R4VK-C.a' -notin $names -or 'R4VK-C.whole.o' -notin $names -or 'build_identity.c' -notin $names) {
            throw 'Native cache output inventory is incomplete.'
        }
        foreach ($item in $previous.outputs) {
            if ((Get-R4VKFileHash (Join-Path $output $item.path)) -ne $item.sha256) { throw "Native cache changed: $($item.path)" }
        }
        Write-Host "Verified native Vulkan C cache: $output"
        return
    }
    Remove-Item -LiteralPath $recordPath
}
$objects = Join-Path $output 'Objects'
[IO.Directory]::CreateDirectory($objects) | Out-Null
$identitySource = Join-Path $output 'build_identity.c'
[IO.File]::WriteAllText($identitySource, 'const unsigned char r4vk_build_identity[32] = {' +
    (@($digest | ForEach-Object { [string]$_ }) -join ',') + "};`n", [Text.UTF8Encoding]::new($false))
$sources = @($inputs.sources) + @($identitySource)
$options = $inputs.arguments
$workspace = $mesa.workspace
$results = @($sources | ForEach-Object -Parallel {
    $file = $_
    $relative = [IO.Path]::GetRelativePath($using:workspace, $file).Replace('\', '/')
    $name = [Convert]::ToHexString([Security.Cryptography.SHA256]::HashData([Text.Encoding]::UTF8.GetBytes($relative))).Substring(0, 12).ToLowerInvariant()
    $object = Join-Path $using:objects ($name + '-' + [IO.Path]::GetFileName($file) + '.o')
    $log = $object + '.log'
    $compileOptions = $using:options
    & $using:clang @compileOptions -c $file -o $object 2> $log
    [ordered]@{source = $relative; success = ($LASTEXITCODE -eq 0); object = $object; log = $log}
} -ThrottleLimit $Jobs)
$results = @($results | Sort-Object source)
$failed = @($results | Where-Object { !$_.success })
if ($failed.Count) {
    foreach ($failure in $failed) { Write-Host $failure.source; Get-Content -LiteralPath $failure.log | Write-Host }
    throw "Native C compilation failed: $($failed.Count)/$($sources.Count)"
}
$archive = Join-Path $output 'R4VK-C.a'
New-R4VKDispatchArchive -Zig $zig -OutputFile $archive -Objects @($results.object)
$outputs = @(foreach ($path in @($results.object) + @($archive, [IO.Path]::ChangeExtension($archive, '.whole.o'), $identitySource)) {
    [ordered]@{path = [IO.Path]::GetRelativePath($output, $path).Replace('\', '/'); sha256 = (Get-R4VKFileHash $path)}
})
[ordered]@{schema = 1; identity = $id; inputs = $identity; c_units = $inputs.sources.Count;
    outputs = $outputs; scope = 'Native C dispatch archive and build identity. Link with the matching native NAK/NIL archives and R4VK Zig runtime. No fixture or failure injection; no installed module or feature admission.'} |
    ConvertTo-Json -Depth 12 | Set-Content -LiteralPath $recordPath -Encoding utf8NoBOM
Write-Host "Built native Vulkan C archive: $archive ($($inputs.sources.Count) C units plus build identity)"
