R4ACO Runtime-R4L API
=====================

AMD ACO compiler library foundation. INFO_V1 reports the built source profile; runtime shader compilation is not exposed yet.

INFO_V1
-------

Independent immutable library identity, append-only interface.

- ELF-Symbol: `r4aco_info_v1`
- ABI-Major: 1
- Revision: 1
- Interface-ID: `0x52344f53:0x41434f31`
- Tabellengroesse: 40 Byte

- Slot 0, Offset 32: `get_info` - Return source/build identity. Zero capabilities is deliberate until real implementation; source compatibility is not device admission.
  Semantik: nonblocking, thread_safe, reentrant; Fehlerdomaene `R4ACO_STATUS`; Besitz: No retained memory, allocation, hardware access or shared mutable state..

Typen
-----

- `R4AcoInfo`: 32 Byte, Alignment 4. Fixed ABI1 source/build identity, not a measured hardware profile.

Besitzregeln
------------

- hardware: Only AMDGPU.R4D owns hardware. The foundation interface touches no device.
- provider: Table pointers live for the loaded provider generation. No pointer is retained from the caller.
