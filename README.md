# R4OS Runtime Libraries

This repository contains the independent Runtime-R4L units R4STD, R4IMG, and
R4FONT. Each library owns its implementation, contract, baseline, Zig and C
bindings, manifest, and tests.

## Build and validation

Build and test all libraries on Windows:

    Build.bat test

Build and test one unit:

    Build.bat R4STD test
    Build.bat R4IMG test
    Build.bat R4FONT test

The host-neutral starter is `./Build.sh`. Dependency paths are mapped by
`Settings.R4S`.

Detailed German migration notes are preserved in
`DOCUMENTATION.de.txt`.

## License

Original R4OS material is licensed under Apache License 2.0. Vendored code and
test fixtures retain their upstream licenses; see `THIRD_PARTY_NOTICES.md`
and the license files beside that material.
