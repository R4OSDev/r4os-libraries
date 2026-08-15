#!/bin/sh
set -eu

libraries_root=$(CDPATH= cd "$(dirname "$0")" && pwd -P)
settings_file="$libraries_root/Settings.R4S"

selected_library=ALL
case "${1-}" in
    R4STD|R4IMG|R4FONT)
        selected_library=$1
        shift
        ;;
esac

if [ ! -f "$settings_file" ]; then
    echo "ERROR: Settings file not found: $settings_file" >&2
    exit 1
fi

contract_setting=
devkit_setting=
repositories_setting=
sdk_setting=
workspace_setting=
zig_setting=

while IFS='=' read -r key value; do
    case "$key" in
        CONTRACT_ROOT) contract_setting=$value ;;
        DEVKIT_ROOT) devkit_setting=$value ;;
        REPOSITORIES_ROOT) repositories_setting=$value ;;
        SDK_ROOT) sdk_setting=$value ;;
        WORKSPACE_ROOT) workspace_setting=$value ;;
        ZIG_ROOT) zig_setting=$value ;;
    esac
done < "$settings_file"

require_setting() {
    if [ -z "$2" ]; then
        echo "ERROR: $1 is missing in $settings_file" >&2
        exit 1
    fi
}

resolve_path() {
    case "$2" in
        /*) printf '%s\n' "$2" ;;
        *) printf '%s/%s\n' "$1" "$2" ;;
    esac
}

require_setting WORKSPACE_ROOT "$workspace_setting"
require_setting REPOSITORIES_ROOT "$repositories_setting"
require_setting CONTRACT_ROOT "$contract_setting"
require_setting SDK_ROOT "$sdk_setting"
require_setting DEVKIT_ROOT "$devkit_setting"
require_setting ZIG_ROOT "$zig_setting"

workspace_root=$(resolve_path "$libraries_root" "$workspace_setting")
repositories_root=$(resolve_path "$libraries_root" "$repositories_setting")
contract_root=$(resolve_path "$repositories_root" "$contract_setting")
sdk_root=$(resolve_path "$repositories_root" "$sdk_setting")
devkit_root=$(resolve_path "$workspace_root" "$devkit_setting")
zig_root=$(resolve_path "$devkit_root" "$zig_setting")

if [ ! -f "$contract_root/build.zig.zon" ]; then
    echo "ERROR: Contract repository not found: $contract_root" >&2
    exit 1
fi

if [ ! -f "$sdk_root/build.zig.zon" ]; then
    echo "ERROR: SDK repository not found: $sdk_root" >&2
    exit 1
fi

zig_exe=$zig_root/zig
if [ ! -x "$zig_exe" ]; then
    echo "ERROR: Zig executable not found: $zig_exe" >&2
    exit 1
fi

run_library() {
    library=$1
    shift
    if [ "$selected_library" != ALL ] && [ "$selected_library" != "$library" ]; then
        return 0
    fi
    echo "=== $library ==="
    (
        cd "$libraries_root/$library"
        "$zig_exe" build "--fork=$sdk_root" "--fork=$contract_root" "$@"
    )
}

run_library R4STD "$@"
run_library R4IMG "$@"
run_library R4FONT "$@"
