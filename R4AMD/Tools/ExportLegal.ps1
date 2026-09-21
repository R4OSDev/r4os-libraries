param([Parameter(Mandatory)][string]$OutputDirectory)
$ErrorActionPreference='Stop'
Set-StrictMode -Version Latest
$unit=[IO.Path]::GetFullPath('..',$PSScriptRoot)
$catalog=Get-Content -Raw (Join-Path $unit 'ThirdParty/Sources.json')|ConvertFrom-Json
$original=Join-Path $unit $catalog.original_root
$sections=[Collections.Generic.List[string]]::new()
$sections.Add("R4AMD SDMA encoder notices (also compiled into AMDGPU)`nMesa $($catalog.upstream_version); original identities in ThirdParty/Sources.json.`n")
foreach($name in @('src/amd/common/ac_cmdbuf_sdma.c','src/amd/common/ac_cmdbuf_sdma.h','src/amd/common/sid.h','licenses/MIT')){
    $entry=@($catalog.files|Where-Object {$_.path -ceq $name})
    if($entry.Count -ne 1){throw "Missing source $name"}
    $path=Join-Path $original $name
    if((Get-FileHash $path).Hash.ToLowerInvariant() -cne $entry[0].sha256){throw "Source drift $name"}
    $source=[IO.File]::ReadAllText($path)
    if($name -eq 'licenses/MIT'){$notice=$source}else{
        $match=[regex]::Match($source,'(?s)\A(?:/\*.*?\*/\s*)+')
        if(!$match.Success){throw "Missing original notice $name"};$notice=$match.Value.Trim()
    }
    $sections.Add($name+"`nSHA256 "+$entry[0].sha256+"`n"+$notice.Replace("`r`n","`n")+"`n")
}
[IO.Directory]::CreateDirectory($OutputDirectory)|Out-Null
[IO.File]::WriteAllText((Join-Path $OutputDirectory 'R4AMD-NOTICES.txt'),($sections -join "`n"),[Text.UTF8Encoding]::new($true))
Write-Host 'R4AMD original SDMA source notices and complete MIT text exported.'
