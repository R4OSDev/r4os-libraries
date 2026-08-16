R4STD.R4L
=========

R4STD is an independent Runtime-R4L for text, R4S settings, dates, time zones,
and atomic configuration files. Its contract, baseline, implementation, Zig
and C bindings, and tests belong entirely to this library. The kernel, central
platform Contract, and core SDK contain no R4STD implementation.

Versioned interfaces:

- R4STD:TEXT_V1:1
- R4STD:SETTINGS_V1:1
- R4STD:DATE_V1:1
- R4STD:TIME_V1:1
- R4STD:CONFIG_V1:1

Applications import only the interfaces they use and bind
Bindings/Zig/r4std.zig or Bindings/C/r4std.h. Query:1 is the technical module
identity, not a functional R4STD import.

Important paths:

- Contract: Contract/LibraryContract.json
- Compatibility baseline: Contract/LibraryContract.baseline.json
- Implementation: Source
- Bindings: Bindings/Zig and Bindings/C
- Generated reference: Docs/API.md
- Tests: Tests

CONFIG_V1 receives the opaque caller-owned R4XStart context per call and uses
it to resolve R4SYS. R4STD retains neither that context nor any other supplied
pointer. Buffers and state objects remain caller-owned.

Build and test:

    Build.bat R4STD test
