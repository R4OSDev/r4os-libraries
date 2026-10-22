#![cfg(test)]
use r4os_library_helpers::{
    graphics::Receiver,
    media::{BuiltinShader, Mux, Nv12, shader},
    video::Clock,
};
#[path = "native.rs"]
mod previous;
unsafe extern "C" {
    fn r4libraries60_transport() -> i32;
    fn r4libraries60_mux(bytes: *const u8, length: usize) -> u64;
    fn R4LibrariesAvcOracle(bytes: *mut u8, capacity: usize) -> usize;
    fn R4LibrariesRecordingOracle() -> i32;
}
#[test]
fn aligned_storage_and_named_error_are_not_private_layout_guesses() {
    assert_eq!(unsafe { r4libraries60_transport() }, 0);
}
#[test]
fn original_recording_oracles_and_identical_c_rust_mux_bytes() {
    assert_eq!(unsafe { R4LibrariesRecordingOracle() }, 0);
    let mut packet = [0u8; 512];
    let length = unsafe { R4LibrariesAvcOracle(packet.as_mut_ptr(), packet.len()) };
    assert!(length > 6 && length <= packet.len());
    let packet = &packet[..length];
    let mut output = Vec::new();
    let mut writer = Mux::new(64, 64).unwrap();
    writer
        .packet(packet, true, 0, 1, |bytes| {
            output.extend_from_slice(bytes);
            true
        })
        .unwrap();
    let hash = output.iter().fold(14695981039346656037u64, |h, &b| {
        (h ^ u64::from(b)).wrapping_mul(1099511628211)
    });
    assert_eq!(
        unsafe { r4libraries60_mux(packet.as_ptr(), packet.len()) },
        hash
    );
    assert_eq!(writer.frames().unwrap(), 1);
    let mut failed = Mux::new(64, 64).unwrap();
    let mut calls = 0;
    let mut partial = 0;
    assert!(
        failed
            .packet(packet, true, 0, 1, |bytes| {
                calls += 1;
                if calls == 1 {
                    partial += bytes.len();
                    true
                } else {
                    false
                }
            })
            .is_err()
    );
    assert!(partial > 0 && failed.failed().unwrap());
    assert_eq!(failed.frames().unwrap(), 0);
    assert!(
        failed
            .packet(packet, true, 0, 1, |_| panic!(
                "closed writer must not write"
            ))
            .is_err()
    );
    let layout = Nv12::new(18, 16, false).unwrap();
    let mut nv12 = vec![0; layout.bytes().unwrap()];
    layout.rows(&[0u32; 20 * 16], 20, &mut nv12, 0, 16).unwrap();
    assert_eq!(nv12[0], 16);
    assert_eq!(nv12[layout.uv_offset().unwrap()], 128);
    assert!(
        layout
            .rows(&[0u32; 20 * 16], 20, &mut [0; 1], 0, 16)
            .is_err()
    );
    assert_eq!(shader(BuiltinShader::Copy).unwrap()[0], 0x07230203);
}
#[test]
fn receiver_and_media_clock_keep_original_data_and_progress() {
    let bytes = include_bytes!("../../R4GFX/Tests/Display/Fixtures/qemu.edid");
    let receiver = Receiver::parse(bytes).unwrap();
    assert!(receiver.complete().unwrap());
    assert!(receiver.digital().unwrap() && receiver.mode_count().unwrap() > 0);
    assert!(
        receiver
            .manufacturer()
            .unwrap()
            .iter()
            .all(u8::is_ascii_uppercase)
    );
    let (w, h, rate) = receiver.timing(0).unwrap();
    assert!(w > 0 && h > 0 && rate > 0);
    assert!(Receiver::parse(b"invalid").is_err());
    let mut clock = Clock::new(100, 1000).unwrap();
    assert_eq!(clock.position(150).unwrap(), 1050);
    clock.pause(150, true).unwrap();
    assert_eq!(clock.position(200).unwrap(), 1050);
    clock.seek(200, 100).unwrap();
    assert_eq!(clock.position(250).unwrap(), 100);
    assert!(clock.position(249).is_err());
}
