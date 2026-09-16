# Copyright 2026 R4. SPDX-License-Identifier: Apache-2.0
function Get-R4VKNativeCInputs {
    param(
        [Parameter(Mandatory)]$Mesa,
        [Parameter(Mandatory)][string]$CompilerRoot,
        [Parameter(Mandatory)][string]$MesaRoot,
        [Parameter(Mandatory)][string]$ShaderRoot,
        [Parameter(Mandatory)][string]$Clang
    )
    # Reuse the compiler owner's ABI flags and NIR/SPIR-V source selection.
    # Dot-sourced variables stay inside this function's scope.
    $unit = Join-Path $Mesa.libraries 'R4NAK'
    $buildRoot = $CompilerRoot
    $source = $Mesa.source
    $overlay = Join-Path $CompilerRoot 'CSource'
    $hostName = if ($IsWindows) { 'Windows-x64' } else { 'Linux-x64' }
    $hostBuild = Join-Path ([IO.Path]::GetDirectoryName($source)) ('Build-' + $hostName)
    $tools = @{clang = $Clang}
    . (Join-Path $unit 'Tools/CInputs.ps1')

    $settings = @{}
    foreach ($line in Get-Content -LiteralPath (Join-Path $Mesa.libraries 'Settings.R4S')) {
        if ($line -match '^([A-Z_]+)=(.+)$') { $settings[$Matches[1]] = $Matches[2] }
    }
    function Resolve([string]$Base, [string]$Name) {
        [IO.Path]::GetFullPath($settings[$Name].Replace('\', [IO.Path]::DirectorySeparatorChar), $Base)
    }
    $repositories = Resolve $Mesa.libraries 'REPOSITORIES_ROOT'
    $sdk = Resolve $repositories 'SDK_ROOT'
    $contract = Resolve $repositories 'CONTRACT_ROOT'
    $headers = @((Join-Path $Mesa.unit 'Port/Include'), (Join-Path $MesaRoot 'CSource'),
        (Join-Path $ShaderRoot '.'), (Join-Path $MesaRoot 'Generated'),
        (Join-Path $sdk 'Shared/C/include'), (Join-Path $contract 'Generated/SDK/C/include'),
        (Join-Path $Mesa.libraries 'R4NV/Bindings/C'))
    foreach ($directory in @('src/vulkan/util', 'src/vulkan/runtime', 'src/nouveau/vulkan',
                             'src', 'src/compiler', 'src/compiler/nir', 'src/util')) {
        $headers += Join-Path $MesaRoot ('CSource/' + $directory)
    }
    $cArgs = @('-DR4OS_VULKAN=1', '-UNDEBUG', '-Werror', '-DVK_LITE_RUNTIME_INSTANCE=1',
        '-DMESA_VK_LOG=0', '-DPACKAGE_BUGREPORT="https://github.com/R4OSDev"') +
        @($headers | ForEach-Object { '-I' + $_ }) + $cArgs
    foreach ($directory in @('src/vulkan/util', 'src/vulkan/runtime', 'src/vulkan/wsi',
                             'src/nouveau/vulkan', 'src/nouveau/winsys', 'src/nouveau/mme')) {
        $cArgs += '-I' + (Join-Path $source $directory)
    }
    function PrivateSource([string]$Path) {
        $relative = [IO.Path]::GetRelativePath($source, $Path)
        if ($relative.StartsWith('..')) { $relative = [IO.Path]::GetRelativePath($overlay, $Path) }
        $private = Join-Path $MesaRoot ('CSource/' + $relative)
        if (!$relative.StartsWith('..') -and (Test-Path -LiteralPath $private)) { $private } else { $Path }
    }
    function MesonFiles([string]$Directory, [string]$Variable) {
        $text = [IO.File]::ReadAllText((Join-Path $source ($Directory + '/meson.build')))
        $match = [regex]::Match($text, '(?s)' + [regex]::Escape($Variable) + ' = files\((.*?)\n\)')
        if (!$match.Success) { throw "Missing pinned Mesa source set: $Variable" }
        foreach ($name in [regex]::Matches($match.Groups[1].Value, "'([^']+\.c)'")) {
            $relative = $Directory + '/' + $name.Groups[1].Value
            # Native owners replace DRM discovery. WSI, RMV and experimental
            # CUBIN support are not part of the admitted native provider.
            if ($relative -match '/nvkmd/nouveau/|/nvk_wsi\.c$|/nvk_cubin\.c$|/rmv/') { continue }
            PrivateSource (Join-Path $source $relative)
        }
    }
    $files = @(MesonFiles 'src/nouveau/vulkan' 'nvk_files') +
        @(MesonFiles 'src/vulkan/runtime' 'vulkan_lite_runtime_files') +
        @(MesonFiles 'src/vulkan/runtime' 'vulkan_runtime_files')
    $files += Join-Path $MesaRoot 'CSource/src/vulkan/runtime/vk_instance.c'
    $files += @(Get-ChildItem -LiteralPath (Join-Path $MesaRoot 'Generated') -File -Filter '*.c' |
        Where-Object Name -ne nvk_drirc.c | ForEach-Object FullName)
    $files += Join-Path $ShaderRoot 'nvkcl.c'
    foreach ($directory in @('src/nouveau/mme', 'src/vulkan/util')) {
        $files += @(Get-ChildItem -LiteralPath (Join-Path $source $directory) -File -Filter '*.c' |
            Where-Object Name -notmatch 'test_|method_dumper|drm' | ForEach-Object { PrivateSource $_.FullName })
    }
    $files += @(MesonFiles 'src/util/format' 'files_mesa_format' | Where-Object { $_ -notmatch 'tests|_neon' })
    foreach ($name in @('cache_ops_x86.c', 'sparse_array.c', 'vma.c')) { $files += PrivateSource (Join-Path $source ('src/util/' + $name)) }
    $files += Join-Path $hostBuild 'src/util/format_srgb.c'
    $files += Join-Path $source 'src/nouveau/headers/nv_push.c'
    $files += @(Get-ChildItem -LiteralPath (Join-Path $hostBuild 'src/nouveau/headers') -File -Filter 'nv_push_cl*.c' | ForEach-Object FullName)
    $files += @(Get-ChildItem -LiteralPath (Join-Path $Mesa.unit 'Port') -File -Filter '*.c' | ForEach-Object FullName)
    $excluded = @((Join-Path $unit 'Source/native.c'), (Join-Path $unit 'Port/libc.c'), (Join-Path $unit 'Port/cpu.c'))
    $files += @($cPaths | Where-Object { $_ -notin $excluded } | ForEach-Object { PrivateSource $_ })
    [pscustomobject]@{
        sources = @($files | Sort-Object -Unique); arguments = $cArgs; host_build = $hostBuild
        header_roots = @((Join-Path $unit 'Port/Include'), (Join-Path $CompilerRoot 'NativeBindings'),
            $hostBuild, (Join-Path $sdk 'Shared/C/include'), (Join-Path $contract 'Generated/SDK/C/include'),
            (Join-Path $Mesa.libraries 'R4NV/Bindings/C'), (Join-Path (& $Clang -print-resource-dir) 'include'))
    }
}
