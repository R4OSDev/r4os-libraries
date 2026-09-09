# Shared Windows/Linux entry point; each runtime library owns its build.
$ErrorActionPreference = 'Stop'
Set-StrictMode -Version Latest
$settings = @{}
foreach ($line in Get-Content -LiteralPath (Join-Path $PSScriptRoot 'Settings.R4S')) {
    if ($line -match '^([A-Z_]+)=(.+)$') { $settings[$Matches[1]] = $Matches[2] }
}
function Resolve-Setting([string]$base, [string]$name) {
    if (!$settings.ContainsKey($name)) { throw "Missing $name in Settings.R4S" }
    $value = $settings[$name].Replace('\', [IO.Path]::DirectorySeparatorChar)
    return [IO.Path]::GetFullPath($value, $base)
}
$workspace = Resolve-Setting $PSScriptRoot 'WORKSPACE_ROOT'
$repositories = Resolve-Setting $PSScriptRoot 'REPOSITORIES_ROOT'
$devkit = Resolve-Setting $workspace 'DEVKIT_ROOT'
$zigRoot = Resolve-Setting $devkit 'ZIG_ROOT'
$sdk = Resolve-Setting $repositories 'SDK_ROOT'
$contract = Resolve-Setting $repositories 'CONTRACT_ROOT'
$zig = Join-Path $zigRoot $(if ($IsWindows) { 'zig.exe' } else { 'zig' })
$units = @('R4STD', 'R4IMG', 'R4FONT', 'R4GFX')
$forward = @($args)
if ($forward.Count -gt 0 -and ($forward[0] -in $units -or $forward[0] -eq 'ALL')) {
    if ($forward[0] -ne 'ALL') { $units = @($forward[0]) }
    $forward = @($forward | Select-Object -Skip 1)
}
foreach ($unit in $units) {
    Push-Location (Join-Path $PSScriptRoot $unit)
    try {
        Write-Host "Building $unit in $PWD"
        & $zig build "--fork=$sdk" "--fork=$contract" @forward
        if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }
    } finally { Pop-Location }
}
