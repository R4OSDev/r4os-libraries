# R4STD resident text core

This allocation-free Rust library belongs to R4STD and exposes the same pinned
CP437/Windows-1252 mapping facts for native resident consumers. Unicode scalar
validation uses Rust core; negative incremental results preserve state.
The optional Output helper holds three independent streams, rejects an encoding
change with a pending prefix, and reports malformed/truncated sequences using
U+FFFD. Presentation, controls, cell width and lifetime remain with callers.
The dynamic CODEC_V1 interface and existing Zig provider remain unchanged.

Tests compare every mapping against the original vendored tables and every
Unicode scalar/split against strict core UTF-8. Use the workspace pinned Rust
starter with cargo test --manifest-path R4STD/Rust/Cargo.toml.
