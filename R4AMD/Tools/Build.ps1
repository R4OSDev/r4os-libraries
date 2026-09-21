# Copyright 2026 R4. SPDX-License-Identifier: Apache-2.0
$ErrorActionPreference = 'Stop'
& (Join-Path $PSScriptRoot '../../Shared/Native/BuildPortability.ps1') -UnitRoot ([IO.Path]::GetFullPath('..', $PSScriptRoot))
