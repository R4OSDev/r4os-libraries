@echo off
setlocal EnableExtensions DisableDelayedExpansion

for %%I in ("%~dp0.") do set "R4OS_LIBRARIES_ROOT=%%~fI"
set "R4OS_SETTINGS=%R4OS_LIBRARIES_ROOT%\Settings.R4S"

set "R4OS_LIBRARY=ALL"
if /i "%~1"=="R4STD" (
    set "R4OS_LIBRARY=R4STD"
    shift
)
if /i "%~1"=="R4IMG" (
    set "R4OS_LIBRARY=R4IMG"
    shift
)
if /i "%~1"=="R4FONT" (
    set "R4OS_LIBRARY=R4FONT"
    shift
)

set "R4OS_BUILD_ARGS="
:collect_build_args
if "%~1"=="" goto resolve_settings
set "R4OS_BUILD_ARGS=%R4OS_BUILD_ARGS% "%~1""
shift
goto collect_build_args

:resolve_settings

if not exist "%R4OS_SETTINGS%" (
    echo ERROR: Settings file not found: "%R4OS_SETTINGS%"
    exit /b 1
)

set "R4OS_CONTRACT_SETTING="
set "R4OS_DEVKIT_SETTING="
set "R4OS_REPOSITORIES_SETTING="
set "R4OS_SDK_SETTING="
set "R4OS_WORKSPACE_SETTING="
set "R4OS_ZIG_SETTING="

for /f "usebackq tokens=1,* delims==" %%A in ("%R4OS_SETTINGS%") do (
    if /i "%%A"=="CONTRACT_ROOT" set "R4OS_CONTRACT_SETTING=%%B"
    if /i "%%A"=="DEVKIT_ROOT" set "R4OS_DEVKIT_SETTING=%%B"
    if /i "%%A"=="REPOSITORIES_ROOT" set "R4OS_REPOSITORIES_SETTING=%%B"
    if /i "%%A"=="SDK_ROOT" set "R4OS_SDK_SETTING=%%B"
    if /i "%%A"=="WORKSPACE_ROOT" set "R4OS_WORKSPACE_SETTING=%%B"
    if /i "%%A"=="ZIG_ROOT" set "R4OS_ZIG_SETTING=%%B"
)

for %%K in (WORKSPACE REPOSITORIES CONTRACT SDK DEVKIT ZIG) do if not defined R4OS_%%K_SETTING (
    echo ERROR: %%K_ROOT is missing in "%R4OS_SETTINGS%".
    exit /b 1
)

pushd "%R4OS_LIBRARIES_ROOT%" >nul || exit /b 1
for %%I in ("%R4OS_WORKSPACE_SETTING%") do set "R4OS_WORKSPACE_ROOT=%%~fI"
for %%I in ("%R4OS_REPOSITORIES_SETTING%") do set "R4OS_REPOSITORIES_ROOT=%%~fI"
popd

pushd "%R4OS_REPOSITORIES_ROOT%" >nul || (
    echo ERROR: Repositories root not found: "%R4OS_REPOSITORIES_ROOT%"
    exit /b 1
)
for %%I in ("%R4OS_CONTRACT_SETTING%") do set "R4OS_CONTRACT_ROOT=%%~fI"
for %%I in ("%R4OS_SDK_SETTING%") do set "R4OS_SDK_ROOT=%%~fI"
popd

pushd "%R4OS_WORKSPACE_ROOT%" >nul || (
    echo ERROR: Workspace root not found: "%R4OS_WORKSPACE_ROOT%"
    exit /b 1
)
for %%I in ("%R4OS_DEVKIT_SETTING%") do set "R4OS_DEVKIT_ROOT=%%~fI"
popd

pushd "%R4OS_DEVKIT_ROOT%" >nul || (
    echo ERROR: DevKit root not found: "%R4OS_DEVKIT_ROOT%"
    exit /b 1
)
for %%I in ("%R4OS_ZIG_SETTING%") do set "R4OS_ZIG_ROOT=%%~fI"
popd

if not exist "%R4OS_CONTRACT_ROOT%\build.zig.zon" (
    echo ERROR: Contract repository not found: "%R4OS_CONTRACT_ROOT%"
    exit /b 1
)

if not exist "%R4OS_SDK_ROOT%\build.zig.zon" (
    echo ERROR: SDK repository not found: "%R4OS_SDK_ROOT%"
    exit /b 1
)

set "R4OS_ZIG_EXE=%R4OS_ZIG_ROOT%\zig.exe"
if not exist "%R4OS_ZIG_EXE%" (
    echo ERROR: Zig executable not found: "%R4OS_ZIG_EXE%"
    exit /b 1
)

call :run_library R4STD
if errorlevel 1 exit /b %ERRORLEVEL%
call :run_library R4IMG
if errorlevel 1 exit /b %ERRORLEVEL%
call :run_library R4FONT
if errorlevel 1 exit /b %ERRORLEVEL%

exit /b 0

:run_library
if /i "%R4OS_LIBRARY%"=="ALL" goto run_selected_library
if /i "%R4OS_LIBRARY%"=="%~1" goto run_selected_library
exit /b 0

:run_selected_library
echo === %~1 ===
pushd "%R4OS_LIBRARIES_ROOT%\%~1" >nul || exit /b 1
"%R4OS_ZIG_EXE%" build --fork="%R4OS_SDK_ROOT%" --fork="%R4OS_CONTRACT_ROOT%" %R4OS_BUILD_ARGS%
set "R4OS_EXIT_CODE=%ERRORLEVEL%"
popd

exit /b %R4OS_EXIT_CODE%
