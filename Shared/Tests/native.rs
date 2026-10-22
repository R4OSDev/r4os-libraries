#![cfg(test)]
use r4os_library_helpers::{Heap, font, standard::Graphemes};
mod fixtures;
unsafe extern "C" {
    fn r4libraries59_pure() -> i32;
}
#[test]
fn c_rust_share_pinned_graphemes_and_boundary_validation() {
    assert_eq!(unsafe { r4libraries59_pure() }, 0);
    let text = "A\u{308}B";
    let actual = Graphemes::new(text.as_bytes())
        .unwrap()
        .collect::<Result<Vec<_>, _>>()
        .unwrap();
    assert_eq!(actual, vec!["A\u{308}".as_bytes(), b"B"]);
    assert_eq!(Graphemes::prefix(text.as_bytes(), 2).unwrap(), 0);
    assert!(Graphemes::prefix(&[b'A', 0xff], 1).is_err());
}
#[test]
fn native_font_import_retains_allocator_and_releases_owned_bytes() {
    let heap = Heap::new().unwrap();
    let source = fixtures::fnt();
    let output = font::import(&heap, &source, b"test.fnt", 0).unwrap();
    assert_eq!(&output.bytes()[..4], b"R4F1");
    assert!(font::import(&heap, b"invalid", b"bad.fnt", 0).is_err());
    drop(output);
    assert_eq!(&fixtures::PNG[..8], b"\x89PNG\r\n\x1a\n");
    assert!(fixtures::FONT.len() > 100);
}
