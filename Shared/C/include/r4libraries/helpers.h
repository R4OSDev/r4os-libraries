/* Compiler-generated library helper boundary. Do not edit.
 * Private objects are native storage: use MaybeUninit in Rust. Never read
 * their bytes or assume padding initialized. Initialize all required fields
 * through the typed constructor before use. Borrowed strings/arrays/contexts
 * must outlive every referencing object. Stateful contexts/frames stay at
 * their exact address; inspect native status before release/reuse. Raw field
 * mutation requires preservation of the original owner's invariants.
 * Slot.status is transport status; bits retain native scalar return values,
 * including negative i32. PRESENT marks optional payloads, NATIVE_ERROR
 * exposes a resident error-name view. A returned view borrows its inputs or
 * exact native owner. Float values cross only through pointers. */
#ifndef R4LIBRARIES_HELPERS_H
#define R4LIBRARIES_HELPERS_H
#include "r4os/abi.h"
#define R4LIBRARIES_PRESENT 1u
#define R4LIBRARIES_NATIVE_ERROR 2u
#define R4LIBRARIES_DEFAULT 4u
typedef struct R4LibrariesSlot { void *ptr; uint64_t length,bits; int32_t status; uint32_t flags; } R4LibrariesSlot;
R4LibrariesSlot R4LibrariesInvoke(uint64_t,uint32_t,const R4LibrariesSlot *,uint32_t,void *);
R4LibrariesSlot R4LibrariesConstruct(uint64_t,uint32_t,const R4LibrariesSlot *,uint32_t,void *);
R4LibrariesSlot R4LibrariesInspect(uint64_t,uint32_t,void *,void *);
R4LibrariesSlot R4LibrariesField(uint64_t,uint32_t,uint32_t,void *,const R4LibrariesSlot *,void *);
/* *const abi_generated.R4XStartContext; native size 8, alignment 8. */
typedef struct R4Lib_Value0 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value0;
#define R4Lib_Value0_TYPE 0u
/* R4STD.Bindings.Zig.text.Encoding; native size 1, alignment 1. */
typedef struct R4StdTextEncoding { _Alignas(1) uint8_t opaque_bytes[1]; } R4StdTextEncoding;
#define R4StdTextEncoding_TYPE 2u
/* R4STD.Bindings.Zig.text.LineEnding; native size 1, alignment 1. */
typedef struct R4StdTextLineEnding { _Alignas(1) uint8_t opaque_bytes[1]; } R4StdTextLineEnding;
#define R4StdTextLineEnding_TYPE 3u
/* R4STD.Bindings.Zig.text.Bytes; native size 16, alignment 8. */
typedef struct R4StdTextBytes { _Alignas(8) uint8_t opaque_bytes[16]; } R4StdTextBytes;
#define R4StdTextBytes_TYPE 4u
/* []const u8; native size 16, alignment 8. */
typedef struct R4Lib_Value5 { _Alignas(8) uint8_t opaque_bytes[16]; } R4Lib_Value5;
#define R4Lib_Value5_TYPE 5u
/* R4STD.Bindings.Zig.text.Utf8Text; native size 24, alignment 8. */
typedef struct R4StdTextUtf8Text { _Alignas(8) uint8_t opaque_bytes[24]; } R4StdTextUtf8Text;
#define R4StdTextUtf8Text_TYPE 6u
/* R4STD.Bindings.Zig.text.UiText8; native size 16, alignment 8. */
typedef struct R4StdTextUiText8 { _Alignas(8) uint8_t opaque_bytes[16]; } R4StdTextUiText8;
#define R4StdTextUiText8_TYPE 7u
/* R4STD.Bindings.Zig.text.SystemText; native size 40, alignment 8. */
typedef struct R4StdTextSystemText { _Alignas(8) uint8_t opaque_bytes[40]; } R4StdTextSystemText;
#define R4StdTextSystemText_TYPE 8u
/* R4STD.Bindings.Zig.text.DocumentText; native size 24, alignment 8. */
typedef struct R4StdTextDocumentText { _Alignas(8) uint8_t opaque_bytes[24]; } R4StdTextDocumentText;
#define R4StdTextDocumentText_TYPE 9u
/* error{BufferTooSmall,EmbeddedNul,InvalidLineEnding,InvalidUiText8,InvalidUtf8,RuntimeUnavailable}!void; native size 2, alignment 2. */
typedef struct R4Lib_Value11 { _Alignas(2) uint8_t opaque_bytes[2]; } R4Lib_Value11;
#define R4Lib_Value11_TYPE 11u
/* error{BufferTooSmall,EmbeddedNul,InvalidLineEnding,InvalidUiText8,InvalidUtf8,RuntimeUnavailable}!R4STD.Bindings.Zig.text.Utf8Text; native size 32, alignment 8. */
typedef struct R4Lib_Value12 { _Alignas(8) uint8_t opaque_bytes[32]; } R4Lib_Value12;
#define R4Lib_Value12_TYPE 12u
/* error{BufferTooSmall,EmbeddedNul,InvalidLineEnding,InvalidUiText8,InvalidUtf8,RuntimeUnavailable}!R4STD.Bindings.Zig.text.SystemText; native size 48, alignment 8. */
typedef struct R4Lib_Value13 { _Alignas(8) uint8_t opaque_bytes[48]; } R4Lib_Value13;
#define R4Lib_Value13_TYPE 13u
/* []u8; native size 16, alignment 8. */
typedef struct R4Lib_Value14 { _Alignas(8) uint8_t opaque_bytes[16]; } R4Lib_Value14;
#define R4Lib_Value14_TYPE 14u
/* error{BufferTooSmall,EmbeddedNul,InvalidLineEnding,InvalidUiText8,InvalidUtf8,RuntimeUnavailable}![]const u8; native size 24, alignment 8. */
typedef struct R4Lib_Value15 { _Alignas(8) uint8_t opaque_bytes[24]; } R4Lib_Value15;
#define R4Lib_Value15_TYPE 15u
/* error{BufferTooSmall,EmbeddedNul,InvalidLineEnding,InvalidUiText8,InvalidUtf8,RuntimeUnavailable}!R4STD.Bindings.Zig.text.DocumentText; native size 32, alignment 8. */
typedef struct R4Lib_Value16 { _Alignas(8) uint8_t opaque_bytes[32]; } R4Lib_Value16;
#define R4Lib_Value16_TYPE 16u
/* error{BufferTooSmall,EmbeddedNul,InvalidLineEnding,InvalidUiText8,InvalidUtf8,RuntimeUnavailable}!R4STD.Bindings.Zig.text.UiText8; native size 24, alignment 8. */
typedef struct R4Lib_Value17 { _Alignas(8) uint8_t opaque_bytes[24]; } R4Lib_Value17;
#define R4Lib_Value17_TYPE 17u
/* R4STD.Bindings.Zig.settings.paths; native size 0, alignment 1. */
typedef struct R4StdSettingspaths { _Alignas(1) uint8_t opaque_bytes[1]; } R4StdSettingspaths;
#define R4StdSettingspaths_TYPE 18u
/* R4STD.Bindings.Zig.settings.Entry; native size 32, alignment 8. */
typedef struct R4StdSettingsEntry { _Alignas(8) uint8_t opaque_bytes[32]; } R4StdSettingsEntry;
#define R4StdSettingsEntry_TYPE 19u
/* R4STD.Bindings.Zig.settings.EntryIterator; native size 24, alignment 8. */
typedef struct R4StdSettingsEntryIterator { _Alignas(8) uint8_t opaque_bytes[24]; } R4StdSettingsEntryIterator;
#define R4StdSettingsEntryIterator_TYPE 20u
/* R4STD.Bindings.Zig.settings.Document; native size 16, alignment 8. */
typedef struct R4StdSettingsDocument { _Alignas(8) uint8_t opaque_bytes[16]; } R4StdSettingsDocument;
#define R4StdSettingsDocument_TYPE 21u
/* R4STD.Bindings.Zig.settings.Writer; native size 32, alignment 8. */
typedef struct R4StdSettingsWriter { _Alignas(8) uint8_t opaque_bytes[32]; } R4StdSettingsWriter;
#define R4StdSettingsWriter_TYPE 22u
/* R4STD.Bindings.Zig.settings.WritebackDurability; native size 1, alignment 1. */
typedef struct R4StdSettingsWritebackDurability { _Alignas(1) uint8_t opaque_bytes[1]; } R4StdSettingsWritebackDurability;
#define R4StdSettingsWritebackDurability_TYPE 23u
/* R4STD.Bindings.Zig.settings.WritebackAction; native size 1, alignment 1. */
typedef struct R4StdSettingsWritebackAction { _Alignas(1) uint8_t opaque_bytes[1]; } R4StdSettingsWritebackAction;
#define R4StdSettingsWritebackAction_TYPE 24u
/* R4STD.Bindings.Zig.settings.WritebackFlush; native size 8, alignment 4. */
typedef struct R4StdSettingsWritebackFlush { _Alignas(4) uint8_t opaque_bytes[8]; } R4StdSettingsWritebackFlush;
#define R4StdSettingsWritebackFlush_TYPE 25u
/* R4STD.Bindings.Zig.settings.WritebackPolicy; native size 24, alignment 8. */
typedef struct R4StdSettingsWritebackPolicy { _Alignas(8) uint8_t opaque_bytes[24]; } R4StdSettingsWritebackPolicy;
#define R4StdSettingsWritebackPolicy_TYPE 26u
/* R4STD.Bindings.Zig.settings.Writeback; native size 48, alignment 8. */
typedef struct R4StdSettingsWriteback { _Alignas(8) uint8_t opaque_bytes[48]; } R4StdSettingsWriteback;
#define R4StdSettingsWriteback_TYPE 27u
/* ?[]const u8; native size 16, alignment 8. */
typedef struct R4Lib_Value28 { _Alignas(8) uint8_t opaque_bytes[16]; } R4Lib_Value28;
#define R4Lib_Value28_TYPE 28u
/* ?R4STD.Bindings.Zig.settings.Entry; native size 40, alignment 8. */
typedef struct R4Lib_Value29 { _Alignas(8) uint8_t opaque_bytes[40]; } R4Lib_Value29;
#define R4Lib_Value29_TYPE 29u
/* ?bool; native size 2, alignment 1. */
typedef struct R4Lib_Value30 { _Alignas(1) uint8_t opaque_bytes[2]; } R4Lib_Value30;
#define R4Lib_Value30_TYPE 30u
/* ?u32; native size 8, alignment 4. */
typedef struct R4Lib_Value31 { _Alignas(4) uint8_t opaque_bytes[8]; } R4Lib_Value31;
#define R4Lib_Value31_TYPE 31u
/* ?i32; native size 8, alignment 4. */
typedef struct R4Lib_Value32 { _Alignas(4) uint8_t opaque_bytes[8]; } R4Lib_Value32;
#define R4Lib_Value32_TYPE 32u
/* R4STD.Bindings.Zig.date.Date; native size 4, alignment 2. */
typedef struct R4StdDateDate { _Alignas(2) uint8_t opaque_bytes[4]; } R4StdDateDate;
#define R4StdDateDate_TYPE 33u
/* R4STD.Bindings.Zig.date.TimeOfDay; native size 3, alignment 1. */
typedef struct R4StdDateTimeOfDay { _Alignas(1) uint8_t opaque_bytes[3]; } R4StdDateTimeOfDay;
#define R4StdDateTimeOfDay_TYPE 34u
/* R4STD.Bindings.Zig.date.DateTime; native size 8, alignment 2. */
typedef struct R4StdDateDateTime { _Alignas(2) uint8_t opaque_bytes[8]; } R4StdDateDateTime;
#define R4StdDateDateTime_TYPE 35u
/* R4STD.Bindings.Zig.date.Weekday; native size 1, alignment 1. */
typedef struct R4StdDateWeekday { _Alignas(1) uint8_t opaque_bytes[1]; } R4StdDateWeekday;
#define R4StdDateWeekday_TYPE 36u
/* R4STD.Bindings.Zig.date.ShiftedDateTime; native size 12, alignment 4. */
typedef struct R4StdDateShiftedDateTime { _Alignas(4) uint8_t opaque_bytes[12]; } R4StdDateShiftedDateTime;
#define R4StdDateShiftedDateTime_TYPE 37u
/* R4STD.Bindings.Zig.date.FatDateTime; native size 4, alignment 2. */
typedef struct R4StdDateFatDateTime { _Alignas(2) uint8_t opaque_bytes[4]; } R4StdDateFatDateTime;
#define R4StdDateFatDateTime_TYPE 38u
/* ?R4STD.Bindings.Zig.date.Weekday; native size 2, alignment 1. */
typedef struct R4Lib_Value39 { _Alignas(1) uint8_t opaque_bytes[2]; } R4Lib_Value39;
#define R4Lib_Value39_TYPE 39u
/* ?R4STD.Bindings.Zig.date.ShiftedDateTime; native size 16, alignment 4. */
typedef struct R4Lib_Value40 { _Alignas(4) uint8_t opaque_bytes[16]; } R4Lib_Value40;
#define R4Lib_Value40_TYPE 40u
/* ?R4STD.Bindings.Zig.date.DateTime; native size 10, alignment 2. */
typedef struct R4Lib_Value42 { _Alignas(2) uint8_t opaque_bytes[10]; } R4Lib_Value42;
#define R4Lib_Value42_TYPE 42u
/* ?abi_generated.TimeState; native size 40, alignment 8. */
typedef struct R4Lib_Value43 { _Alignas(8) uint8_t opaque_bytes[40]; } R4Lib_Value43;
#define R4Lib_Value43_TYPE 43u
/* ?abi_generated.R4UtcTime; native size 24, alignment 8. */
typedef struct R4Lib_Value44 { _Alignas(8) uint8_t opaque_bytes[24]; } R4Lib_Value44;
#define R4Lib_Value44_TYPE 44u
/* ?R4STD.Bindings.Zig.date.Date; native size 6, alignment 2. */
typedef struct R4Lib_Value46 { _Alignas(2) uint8_t opaque_bytes[6]; } R4Lib_Value46;
#define R4Lib_Value46_TYPE 46u
/* ?R4STD.Bindings.Zig.date.TimeOfDay; native size 4, alignment 1. */
typedef struct R4Lib_Value47 { _Alignas(1) uint8_t opaque_bytes[4]; } R4Lib_Value47;
#define R4Lib_Value47_TYPE 47u
/* R4STD.Bindings.Zig.r4std_abi.R4StdDateTime; native size 8, alignment 2. */
typedef struct R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdDateTime { _Alignas(2) uint8_t opaque_bytes[8]; } R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdDateTime;
#define R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdDateTime_TYPE 48u
/* R4STD.Bindings.Zig.r4std_abi.R4StdTimeState; native size 16, alignment 4. */
typedef struct R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdTimeState { _Alignas(4) uint8_t opaque_bytes[16]; } R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdTimeState;
#define R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdTimeState_TYPE 49u
/* R4STD.Bindings.Zig.time.Zone; native size 40, alignment 8. */
typedef struct R4StdTimeZone { _Alignas(8) uint8_t opaque_bytes[40]; } R4StdTimeZone;
#define R4StdTimeZone_TYPE 50u
/* R4STD.Bindings.Zig.time.ClockTime; native size 3, alignment 1. */
typedef struct R4StdTimeClockTime { _Alignas(1) uint8_t opaque_bytes[3]; } R4StdTimeClockTime;
#define R4StdTimeClockTime_TYPE 51u
/* R4STD.Bindings.Zig.time.Config; native size 16, alignment 8. */
typedef struct R4StdTimeHelpersConfig { _Alignas(8) uint8_t opaque_bytes[16]; } R4StdTimeHelpersConfig;
#define R4StdTimeHelpersConfig_TYPE 52u
/* ?usize; native size 16, alignment 8. */
typedef struct R4Lib_Value53 { _Alignas(8) uint8_t opaque_bytes[16]; } R4Lib_Value53;
#define R4Lib_Value53_TYPE 53u
/* error{ComponentTooLong,EmbeddedNul,Empty,ExpectedAbsolute,ExpectedRelative,InvalidCharacter,RootTraversal,TooLong}!r4os.path.FilePath; native size 1030, alignment 2. */
typedef struct R4Lib_Value54 { _Alignas(2) uint8_t opaque_bytes[1030]; } R4Lib_Value54;
#define R4Lib_Value54_TYPE 54u
/* r4os.path.FilePath; native size 1028, alignment 2. */
typedef struct R4Lib_r4os_path_FilePath { _Alignas(2) uint8_t opaque_bytes[1028]; } R4Lib_r4os_path_FilePath;
#define R4Lib_r4os_path_FilePath_TYPE 55u
/* error{ComponentTooLong,EmbeddedNul,Empty,ExpectedAbsolute,ExpectedRelative,InvalidCharacter,RootTraversal,TooLong}!r4os.path.AbsoluteFilePath; native size 1030, alignment 2. */
typedef struct R4Lib_Value56 { _Alignas(2) uint8_t opaque_bytes[1030]; } R4Lib_Value56;
#define R4Lib_Value56_TYPE 56u
/* r4os.path.AbsoluteFilePath; native size 1028, alignment 2. */
typedef struct R4Lib_r4os_path_AbsoluteFilePath { _Alignas(2) uint8_t opaque_bytes[1028]; } R4Lib_r4os_path_AbsoluteFilePath;
#define R4Lib_r4os_path_AbsoluteFilePath_TYPE 57u
/* error{ComponentTooLong,EmbeddedNul,Empty,ExpectedAbsolute,ExpectedRelative,InvalidCharacter,RootTraversal,TooLong}!r4os.path.RelativeFilePath; native size 1030, alignment 2. */
typedef struct R4Lib_Value58 { _Alignas(2) uint8_t opaque_bytes[1030]; } R4Lib_Value58;
#define R4Lib_Value58_TYPE 58u
/* r4os.path.RelativeFilePath; native size 1028, alignment 2. */
typedef struct R4Lib_r4os_path_RelativeFilePath { _Alignas(2) uint8_t opaque_bytes[1028]; } R4Lib_r4os_path_RelativeFilePath;
#define R4Lib_r4os_path_RelativeFilePath_TYPE 59u
/* error{ComponentTooLong,EmbeddedNul,Empty,ExpectedAbsolute,ExpectedRelative,InvalidCharacter,RootTraversal,TooLong}!r4os.path.RegistryPath; native size 262, alignment 2. */
typedef struct R4Lib_Value60 { _Alignas(2) uint8_t opaque_bytes[262]; } R4Lib_Value60;
#define R4Lib_Value60_TYPE 60u
/* r4os.path.RegistryPath; native size 260, alignment 2. */
typedef struct R4Lib_r4os_path_RegistryPath { _Alignas(2) uint8_t opaque_bytes[260]; } R4Lib_r4os_path_RegistryPath;
#define R4Lib_r4os_path_RegistryPath_TYPE 61u
/* R4STD.Bindings.Zig.codec.Codepage; native size 4, alignment 4. */
typedef struct R4StdCodecCodepage { _Alignas(4) uint8_t opaque_bytes[4]; } R4StdCodecCodepage;
#define R4StdCodecCodepage_TYPE 62u
/* R4STD.Bindings.Zig.codec.Mode; native size 4, alignment 4. */
typedef struct R4StdCodecMode { _Alignas(4) uint8_t opaque_bytes[4]; } R4StdCodecMode;
#define R4StdCodecMode_TYPE 63u
/* R4STD.Bindings.Zig.codec.Scalar; native size 16, alignment 8. */
typedef struct R4StdCodecScalar { _Alignas(8) uint8_t opaque_bytes[16]; } R4StdCodecScalar;
#define R4StdCodecScalar_TYPE 64u
/* R4STD.Bindings.Zig.codec.Decoded; native size 24, alignment 8. */
typedef struct R4StdCodecDecoded { _Alignas(8) uint8_t opaque_bytes[24]; } R4StdCodecDecoded;
#define R4StdCodecDecoded_TYPE 65u
/* @typeInfo(R4STD.Bindings.Zig.codec.Decoded).@"union".tag_type.?; native size 1, alignment 1. */
typedef struct R4Lib__typeInfo_R4STD_Bindings_Zig_codec_Decoded____union__tag_type__ { _Alignas(1) uint8_t opaque_bytes[1]; } R4Lib__typeInfo_R4STD_Bindings_Zig_codec_Decoded____union__tag_type__;
#define R4Lib__typeInfo_R4STD_Bindings_Zig_codec_Decoded____union__tag_type___TYPE 66u
/* error{BufferTooSmall,InvalidArgument,InvalidScalar,InvalidUtf8,RangesOverlap,RuntimeUnavailable,UndefinedByte,Unrepresentable}!u32; native size 8, alignment 4. */
typedef struct R4Lib_Value67 { _Alignas(4) uint8_t opaque_bytes[8]; } R4Lib_Value67;
#define R4Lib_Value67_TYPE 67u
/* error{BufferTooSmall,InvalidArgument,InvalidScalar,InvalidUtf8,RangesOverlap,RuntimeUnavailable,UndefinedByte,Unrepresentable}!u8; native size 4, alignment 2. */
typedef struct R4Lib_Value68 { _Alignas(2) uint8_t opaque_bytes[4]; } R4Lib_Value68;
#define R4Lib_Value68_TYPE 68u
/* error{BufferTooSmall,InvalidArgument,InvalidScalar,InvalidUtf8,RangesOverlap,RuntimeUnavailable,UndefinedByte,Unrepresentable}!R4STD.Bindings.Zig.codec.Decoded; native size 32, alignment 8. */
typedef struct R4Lib_Value69 { _Alignas(8) uint8_t opaque_bytes[32]; } R4Lib_Value69;
#define R4Lib_Value69_TYPE 69u
/* error{BufferTooSmall,InvalidArgument,InvalidScalar,InvalidUtf8,RangesOverlap,RuntimeUnavailable,UndefinedByte,Unrepresentable}![]const u8; native size 24, alignment 8. */
typedef struct R4Lib_Value70 { _Alignas(8) uint8_t opaque_bytes[24]; } R4Lib_Value70;
#define R4Lib_Value70_TYPE 70u
/* R4STD.Bindings.Zig.codec.Stream; native size 16, alignment 4. */
typedef struct R4StdCodecStream { _Alignas(4) uint8_t opaque_bytes[16]; } R4StdCodecStream;
#define R4StdCodecStream_TYPE 71u
/* R4STD.Bindings.Zig.r4std_abi.R4StdUtf8State; native size 16, alignment 4. */
typedef struct R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdUtf8State { _Alignas(4) uint8_t opaque_bytes[16]; } R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdUtf8State;
#define R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdUtf8State_TYPE 72u
/* error{BufferTooSmall,InvalidArgument,InvalidScalar,InvalidUtf8,RangesOverlap,RuntimeUnavailable,UndefinedByte,Unrepresentable}!usize; native size 16, alignment 8. */
typedef struct R4Lib_Value73 { _Alignas(8) uint8_t opaque_bytes[16]; } R4Lib_Value73;
#define R4Lib_Value73_TYPE 73u
/* R4STD.Bindings.Zig.grapheme.State; native size 6, alignment 1. */
typedef struct R4StdGraphemeState { _Alignas(1) uint8_t opaque_bytes[6]; } R4StdGraphemeState;
#define R4StdGraphemeState_TYPE 74u
/* ?R4STD.Bindings.Zig.grapheme_properties.Gcb; native size 2, alignment 1. */
typedef struct R4Lib_Value75 { _Alignas(1) uint8_t opaque_bytes[2]; } R4Lib_Value75;
#define R4Lib_Value75_TYPE 75u
/* R4STD.Bindings.Zig.grapheme_properties.Gcb; native size 1, alignment 1. */
typedef struct R4Lib_R4STD_Bindings_Zig_grapheme_properties_Gcb { _Alignas(1) uint8_t opaque_bytes[1]; } R4Lib_R4STD_Bindings_Zig_grapheme_properties_Gcb;
#define R4Lib_R4STD_Bindings_Zig_grapheme_properties_Gcb_TYPE 76u
/* R4STD.Bindings.Zig.grapheme.State__enum_; native size 1, alignment 1. */
typedef struct R4Lib_Value77 { _Alignas(1) uint8_t opaque_bytes[1]; } R4Lib_Value77;
#define R4Lib_Value77_TYPE 77u
/* R4STD.Bindings.Zig.grapheme.Range; native size 16, alignment 8. */
typedef struct R4StdGraphemeRange { _Alignas(8) uint8_t opaque_bytes[16]; } R4StdGraphemeRange;
#define R4StdGraphemeRange_TYPE 78u
/* R4STD.Bindings.Zig.grapheme.Iterator; native size 32, alignment 8. */
typedef struct R4StdGraphemeIterator { _Alignas(8) uint8_t opaque_bytes[32]; } R4StdGraphemeIterator;
#define R4StdGraphemeIterator_TYPE 79u
/* error{Incomplete,InvalidUtf8}!usize; native size 16, alignment 8. */
typedef struct R4Lib_Value80 { _Alignas(8) uint8_t opaque_bytes[16]; } R4Lib_Value80;
#define R4Lib_Value80_TYPE 80u
/* R4STD.Bindings.Zig.grapheme.Stream; native size 32, alignment 8. */
typedef struct R4StdGraphemeStream { _Alignas(8) uint8_t opaque_bytes[32]; } R4StdGraphemeStream;
#define R4StdGraphemeStream_TYPE 81u
/* [4]u8; native size 4, alignment 1. */
typedef struct R4Lib_Value82 { _Alignas(1) uint8_t opaque_bytes[4]; } R4Lib_Value82;
#define R4Lib_Value82_TYPE 82u
/* R4STD.Bindings.Zig.console_text.Scalar; native size 16, alignment 8. */
typedef struct R4StdConsoleTextScalar { _Alignas(8) uint8_t opaque_bytes[16]; } R4StdConsoleTextScalar;
#define R4StdConsoleTextScalar_TYPE 83u
/* error{Incomplete,InvalidUtf8}!R4STD.Bindings.Zig.console_text.Scalar; native size 24, alignment 8. */
typedef struct R4Lib_Value84 { _Alignas(8) uint8_t opaque_bytes[24]; } R4Lib_Value84;
#define R4Lib_Value84_TYPE 84u
/* R4STD.Bindings.Zig.shortcut.ForeignEntry; native size 160, alignment 1. */
typedef struct R4StdShortcutForeignEntry { _Alignas(1) uint8_t opaque_bytes[160]; } R4StdShortcutForeignEntry;
#define R4StdShortcutForeignEntry_TYPE 85u
/* [32]u8; native size 32, alignment 1. */
typedef struct R4Lib_Value86 { _Alignas(1) uint8_t opaque_bytes[32]; } R4Lib_Value86;
#define R4Lib_Value86_TYPE 86u
/* [128]u8; native size 128, alignment 1. */
typedef struct R4Lib_Value87 { _Alignas(1) uint8_t opaque_bytes[128]; } R4Lib_Value87;
#define R4Lib_Value87_TYPE 87u
/* R4STD.Bindings.Zig.shortcut.TargetKind; native size 1, alignment 1. */
typedef struct R4StdShortcutTargetKind { _Alignas(1) uint8_t opaque_bytes[1]; } R4StdShortcutTargetKind;
#define R4StdShortcutTargetKind_TYPE 88u
/* R4STD.Bindings.Zig.shortcut.ResolvedTarget; native size 88, alignment 8. */
typedef struct R4StdShortcutResolvedTarget { _Alignas(8) uint8_t opaque_bytes[88]; } R4StdShortcutResolvedTarget;
#define R4StdShortcutResolvedTarget_TYPE 89u
/* R4STD.Bindings.Zig.shortcut.Shortcut; native size 4552, alignment 4. */
typedef struct R4StdShortcutShortcut { _Alignas(4) uint8_t opaque_bytes[4552]; } R4StdShortcutShortcut;
#define R4StdShortcutShortcut_TYPE 91u
/* [1024]u8; native size 1024, alignment 1. */
typedef struct R4Lib_Value92 { _Alignas(1) uint8_t opaque_bytes[1024]; } R4Lib_Value92;
#define R4Lib_Value92_TYPE 92u
/* [64]u8; native size 64, alignment 1. */
typedef struct R4Lib_Value93 { _Alignas(1) uint8_t opaque_bytes[64]; } R4Lib_Value93;
#define R4Lib_Value93_TYPE 93u
/* [8]R4STD.Bindings.Zig.shortcut.ForeignEntry; native size 1280, alignment 1. */
typedef struct R4Lib_Value94 { _Alignas(1) uint8_t opaque_bytes[1280]; } R4Lib_Value94;
#define R4Lib_Value94_TYPE 94u
/* error{ArgsTooLong,BufferTooSmall,DuplicateField,IconTooLong,InvalidPolicy,InvalidTarget,InvalidText,MissingFormat,MissingSchema,MissingTarget,TargetTooLong,TitleTooLong,UnknownField,UnsupportedFormat,WorkdirTooLong,WrongSchema}!R4STD.Bindings.Zig.shortcut.Shortcut; native size 4556, alignment 4. */
typedef struct R4Lib_Value95 { _Alignas(4) uint8_t opaque_bytes[4556]; } R4Lib_Value95;
#define R4Lib_Value95_TYPE 95u
/* ?abi.LaunchPolicy; native size 8, alignment 4. */
typedef struct R4Lib_Value96 { _Alignas(4) uint8_t opaque_bytes[8]; } R4Lib_Value96;
#define R4Lib_Value96_TYPE 96u
/* R4STD.Bindings.Zig.app_assoc.ForeignEntry; native size 208, alignment 1. */
typedef struct R4StdAssociationForeignEntry { _Alignas(1) uint8_t opaque_bytes[208]; } R4StdAssociationForeignEntry;
#define R4StdAssociationForeignEntry_TYPE 97u
/* [80]u8; native size 80, alignment 1. */
typedef struct R4Lib_Value98 { _Alignas(1) uint8_t opaque_bytes[80]; } R4Lib_Value98;
#define R4Lib_Value98_TYPE 98u
/* R4STD.Bindings.Zig.app_assoc.LaunchKind; native size 1, alignment 1. */
typedef struct R4StdAssociationLaunchKind { _Alignas(1) uint8_t opaque_bytes[1]; } R4StdAssociationLaunchKind;
#define R4StdAssociationLaunchKind_TYPE 99u
/* R4STD.Bindings.Zig.app_assoc.HandlerKind; native size 1, alignment 1. */
typedef struct R4StdAssociationHandlerKind { _Alignas(1) uint8_t opaque_bytes[1]; } R4StdAssociationHandlerKind;
#define R4StdAssociationHandlerKind_TYPE 100u
/* R4STD.Bindings.Zig.app_assoc.AppEntry; native size 1176, alignment 4. */
typedef struct R4StdAssociationAppEntry { _Alignas(4) uint8_t opaque_bytes[1176]; } R4StdAssociationAppEntry;
#define R4StdAssociationAppEntry_TYPE 101u
/* [16]u8; native size 16, alignment 1. */
typedef struct R4Lib_Value102 { _Alignas(1) uint8_t opaque_bytes[16]; } R4Lib_Value102;
#define R4Lib_Value102_TYPE 102u
/* [96]u8; native size 96, alignment 1. */
typedef struct R4Lib_Value103 { _Alignas(1) uint8_t opaque_bytes[96]; } R4Lib_Value103;
#define R4Lib_Value103_TYPE 103u
/* R4STD.Bindings.Zig.app_assoc.ExtEntry; native size 199, alignment 1. */
typedef struct R4StdAssociationExtEntry { _Alignas(1) uint8_t opaque_bytes[199]; } R4StdAssociationExtEntry;
#define R4StdAssociationExtEntry_TYPE 104u
/* [8]u8; native size 8, alignment 1. */
typedef struct R4Lib_Value105 { _Alignas(1) uint8_t opaque_bytes[8]; } R4Lib_Value105;
#define R4Lib_Value105_TYPE 105u
/* [24]u8; native size 24, alignment 1. */
typedef struct R4Lib_Value106 { _Alignas(1) uint8_t opaque_bytes[24]; } R4Lib_Value106;
#define R4Lib_Value106_TYPE 106u
/* [12]u8; native size 12, alignment 1. */
typedef struct R4Lib_Value107 { _Alignas(1) uint8_t opaque_bytes[12]; } R4Lib_Value107;
#define R4Lib_Value107_TYPE 107u
/* R4STD.Bindings.Zig.app_assoc.LaunchTarget; native size 120, alignment 8. */
typedef struct R4StdAssociationLaunchTarget { _Alignas(8) uint8_t opaque_bytes[120]; } R4StdAssociationLaunchTarget;
#define R4StdAssociationLaunchTarget_TYPE 108u
/* R4STD.Bindings.Zig.app_assoc.Config; native size 15944, alignment 8. */
typedef struct R4StdAssociationConfig { _Alignas(8) uint8_t opaque_bytes[15944]; } R4StdAssociationConfig;
#define R4StdAssociationConfig_TYPE 109u
/* [8]R4STD.Bindings.Zig.app_assoc.AppEntry; native size 9408, alignment 4. */
typedef struct R4Lib_Value110 { _Alignas(4) uint8_t opaque_bytes[9408]; } R4Lib_Value110;
#define R4Lib_Value110_TYPE 110u
/* [16]R4STD.Bindings.Zig.app_assoc.ExtEntry; native size 3184, alignment 1. */
typedef struct R4Lib_Value111 { _Alignas(1) uint8_t opaque_bytes[3184]; } R4Lib_Value111;
#define R4Lib_Value111_TYPE 111u
/* [16]R4STD.Bindings.Zig.app_assoc.ForeignEntry; native size 3328, alignment 1. */
typedef struct R4Lib_Value112 { _Alignas(1) uint8_t opaque_bytes[3328]; } R4Lib_Value112;
#define R4Lib_Value112_TYPE 112u
/* r4os.subsystem_catalog.Input; native size 48, alignment 8. */
typedef struct R4Lib_r4os_subsystem_catalog_Input { _Alignas(8) uint8_t opaque_bytes[48]; } R4Lib_r4os_subsystem_catalog_Input;
#define R4Lib_r4os_subsystem_catalog_Input_TYPE 113u
/* R4STD.Bindings.Zig.file_handler.TargetKind; native size 1, alignment 1. */
typedef struct R4StdFileHandlerTargetKind { _Alignas(1) uint8_t opaque_bytes[1]; } R4StdFileHandlerTargetKind;
#define R4StdFileHandlerTargetKind_TYPE 114u
/* R4STD.Bindings.Zig.file_handler.Target; native size 88, alignment 8. */
typedef struct R4StdFileHandlerTarget { _Alignas(8) uint8_t opaque_bytes[88]; } R4StdFileHandlerTarget;
#define R4StdFileHandlerTarget_TYPE 115u
/* R4STD.Bindings.Zig.file_handler.ResolutionState; native size 1, alignment 1. */
typedef struct R4StdFileHandlerResolutionState { _Alignas(1) uint8_t opaque_bytes[1]; } R4StdFileHandlerResolutionState;
#define R4StdFileHandlerResolutionState_TYPE 116u
/* R4STD.Bindings.Zig.file_handler.Resolution; native size 104, alignment 8. */
typedef struct R4StdFileHandlerResolution { _Alignas(8) uint8_t opaque_bytes[104]; } R4StdFileHandlerResolution;
#define R4StdFileHandlerResolution_TYPE 117u
/* ?R4STD.Bindings.Zig.file_handler.Target; native size 96, alignment 8. */
typedef struct R4Lib_Value118 { _Alignas(8) uint8_t opaque_bytes[96]; } R4Lib_Value118;
#define R4Lib_Value118_TYPE 118u
/* R4STD.Bindings.Zig.file_handler.ChoiceKind; native size 1, alignment 1. */
typedef struct R4StdFileHandlerChoiceKind { _Alignas(1) uint8_t opaque_bytes[1]; } R4StdFileHandlerChoiceKind;
#define R4StdFileHandlerChoiceKind_TYPE 119u
/* R4STD.Bindings.Zig.file_handler.Choice; native size 80, alignment 8. */
typedef struct R4StdFileHandlerChoice { _Alignas(8) uint8_t opaque_bytes[80]; } R4StdFileHandlerChoice;
#define R4StdFileHandlerChoice_TYPE 120u
/* ?*const R4STD.Bindings.Zig.app_assoc.AppEntry; native size 8, alignment 8. */
typedef struct R4Lib_Value121 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value121;
#define R4Lib_Value121_TYPE 121u
/* *const R4STD.Bindings.Zig.app_assoc.AppEntry; native size 8, alignment 8. */
typedef struct R4Lib_Value122 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value122;
#define R4Lib_Value122_TYPE 122u
/* R4STD.Bindings.Zig.file_handler.ChoiceList; native size 1928, alignment 8. */
typedef struct R4StdFileHandlerChoiceList { _Alignas(8) uint8_t opaque_bytes[1928]; } R4StdFileHandlerChoiceList;
#define R4StdFileHandlerChoiceList_TYPE 123u
/* [24]R4STD.Bindings.Zig.file_handler.Choice; native size 1920, alignment 8. */
typedef struct R4Lib_Value124 { _Alignas(8) uint8_t opaque_bytes[1920]; } R4Lib_Value124;
#define R4Lib_Value124_TYPE 124u
/* *const R4STD.Bindings.Zig.app_assoc.Config; native size 8, alignment 8. */
typedef struct R4Lib_Value125 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value125;
#define R4Lib_Value125_TYPE 125u
/* *const r4os.subsystem_catalog.Catalog; native size 8, alignment 8. */
typedef struct R4Lib_Value126 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value126;
#define R4Lib_Value126_TYPE 126u
/* r4os.subsystem_catalog.Catalog; native size 24592, alignment 8. */
typedef struct R4Lib_r4os_subsystem_catalog_Catalog { _Alignas(8) uint8_t opaque_bytes[24592]; } R4Lib_r4os_subsystem_catalog_Catalog;
#define R4Lib_r4os_subsystem_catalog_Catalog_TYPE 127u
/* *R4STD.Bindings.Zig.file_handler.Resolution; native size 8, alignment 8. */
typedef struct R4Lib_Value128 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value128;
#define R4Lib_Value128_TYPE 128u
/* error{BufferTooSmall,DuplicateGuest,InvalidAssociation,InvalidGuestPath,InvalidInput,InvalidKey,InvalidMagic,InvalidValue,MalformedRecord,MissingGuest,StaleAssociation,TooManyCandidates,TooManyChoices,TooManyOptions}!void; native size 2, alignment 2. */
typedef struct R4Lib_Value129 { _Alignas(2) uint8_t opaque_bytes[2]; } R4Lib_Value129;
#define R4Lib_Value129_TYPE 129u
/* *R4STD.Bindings.Zig.file_handler.ChoiceList; native size 8, alignment 8. */
typedef struct R4Lib_Value130 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value130;
#define R4Lib_Value130_TYPE 130u
/* error{BufferTooSmall,DuplicateGuest,InvalidAssociation,InvalidGuestPath,InvalidInput,InvalidKey,InvalidMagic,InvalidValue,MalformedRecord,MissingGuest,StaleAssociation,TooManyCandidates,TooManyChoices,TooManyOptions}!R4STD.Bindings.Zig.file_handler.Target; native size 96, alignment 8. */
typedef struct R4Lib_Value131 { _Alignas(8) uint8_t opaque_bytes[96]; } R4Lib_Value131;
#define R4Lib_Value131_TYPE 131u
/* R4STD.Bindings.Zig.subsystem_runtime.LoadStatus; native size 1, alignment 1. */
typedef struct R4StdSubsystemLoadStatus { _Alignas(1) uint8_t opaque_bytes[1]; } R4StdSubsystemLoadStatus;
#define R4StdSubsystemLoadStatus_TYPE 132u
/* R4STD.Bindings.Zig.subsystem_runtime.AccessStats; native size 16, alignment 8. */
typedef struct R4StdSubsystemAccessStats { _Alignas(8) uint8_t opaque_bytes[16]; } R4StdSubsystemAccessStats;
#define R4StdSubsystemAccessStats_TYPE 133u
/* R4STD.Bindings.Zig.subsystem_runtime.Inspection; native size 64, alignment 8. */
typedef struct R4StdSubsystemInspection { _Alignas(8) uint8_t opaque_bytes[64]; } R4StdSubsystemInspection;
#define R4StdSubsystemInspection_TYPE 134u
/* R4IMG.Bindings.Zig.r4img.Format; native size 1, alignment 1. */
typedef struct R4ImgHelpersFormat { _Alignas(1) uint8_t opaque_bytes[1]; } R4ImgHelpersFormat;
#define R4ImgHelpersFormat_TYPE 135u
/* R4IMG.Bindings.Zig.r4img.SvgGlyphProvider; native size 24, alignment 8. */
typedef struct R4ImgHelpersSvgGlyphProvider { _Alignas(8) uint8_t opaque_bytes[24]; } R4ImgHelpersSvgGlyphProvider;
#define R4ImgHelpersSvgGlyphProvider_TYPE 136u
/* ?*anyopaque; native size 8, alignment 8. */
typedef struct R4Lib_Value137 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value137;
#define R4Lib_Value137_TYPE 137u
/* ?*const fn (?*anyopaque, u32, u32) callconv(.c) u64; native size 8, alignment 8. */
typedef struct R4Lib_Value138 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value138;
#define R4Lib_Value138_TYPE 138u
/* R4IMG.Bindings.Zig.r4img.SvgLinkSink; native size 16, alignment 8. */
typedef struct R4ImgHelpersSvgLinkSink { _Alignas(8) uint8_t opaque_bytes[16]; } R4ImgHelpersSvgLinkSink;
#define R4ImgHelpersSvgLinkSink_TYPE 139u
/* ?*const fn (?*anyopaque, u16, i32, i32, i32, i32) callconv(.c) void; native size 8, alignment 8. */
typedef struct R4Lib_Value140 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value140;
#define R4Lib_Value140_TYPE 140u
/* R4IMG.Bindings.Zig.r4img.SvgRenderOptions; native size 64, alignment 8. */
typedef struct R4ImgHelpersSvgRenderOptions { _Alignas(8) uint8_t opaque_bytes[64]; } R4ImgHelpersSvgRenderOptions;
#define R4ImgHelpersSvgRenderOptions_TYPE 141u
/* ?R4IMG.Bindings.Zig.r4img.SvgGlyphProvider; native size 32, alignment 8. */
typedef struct R4Lib_Value142 { _Alignas(8) uint8_t opaque_bytes[32]; } R4Lib_Value142;
#define R4Lib_Value142_TYPE 142u
/* ?R4IMG.Bindings.Zig.r4img.SvgLinkSink; native size 24, alignment 8. */
typedef struct R4Lib_Value143 { _Alignas(8) uint8_t opaque_bytes[24]; } R4Lib_Value143;
#define R4Lib_Value143_TYPE 143u
/* R4IMG.Bindings.Zig.r4img.Info; native size 12, alignment 4. */
typedef struct R4ImgHelpersInfo { _Alignas(4) uint8_t opaque_bytes[12]; } R4ImgHelpersInfo;
#define R4ImgHelpersInfo_TYPE 144u
/* R4IMG.Bindings.Zig.r4img.Image; native size 32, alignment 8. */
typedef struct R4ImgHelpersImage { _Alignas(8) uint8_t opaque_bytes[32]; } R4ImgHelpersImage;
#define R4ImgHelpersImage_TYPE 145u
/* []u32; native size 16, alignment 8. */
typedef struct R4Lib_Value146 { _Alignas(8) uint8_t opaque_bytes[16]; } R4Lib_Value146;
#define R4Lib_Value146_TYPE 146u
/* R4IMG.Bindings.Zig.r4img_abi.R4ImgPngColor; native size 128, alignment 4. */
typedef struct R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor { _Alignas(4) uint8_t opaque_bytes[128]; } R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor;
#define R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_TYPE 147u
/* R4IMG.Bindings.Zig.r4img_abi.R4ImgRasterColor; native size 88, alignment 4. */
typedef struct R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor { _Alignas(4) uint8_t opaque_bytes[88]; } R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor;
#define R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor_TYPE 148u
/* R4IMG.Bindings.Zig.r4img.RasterContext; native size 8, alignment 8. */
typedef struct R4ImgHelpersRasterContext { _Alignas(8) uint8_t opaque_bytes[8]; } R4ImgHelpersRasterContext;
#define R4ImgHelpersRasterContext_TYPE 149u
/* R4IMG.Bindings.Zig.r4img_abi.RasterV1Client; native size 8, alignment 8. */
typedef struct R4Lib_R4IMG_Bindings_Zig_r4img_abi_RasterV1Client { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_R4IMG_Bindings_Zig_r4img_abi_RasterV1Client;
#define R4Lib_R4IMG_Bindings_Zig_r4img_abi_RasterV1Client_TYPE 150u
/* R4IMG.Bindings.Zig.r4img.Image16; native size 160, alignment 8. */
typedef struct R4ImgHelpersImage16 { _Alignas(8) uint8_t opaque_bytes[160]; } R4ImgHelpersImage16;
#define R4ImgHelpersImage16_TYPE 151u
/* []u16; native size 16, alignment 8. */
typedef struct R4Lib_Value152 { _Alignas(8) uint8_t opaque_bytes[16]; } R4Lib_Value152;
#define R4Lib_Value152_TYPE 152u
/* R4IMG.Bindings.Zig.r4img.DecoderDiagnostic; native size 16, alignment 8. */
typedef struct R4ImgHelpersDecoderDiagnostic { _Alignas(8) uint8_t opaque_bytes[16]; } R4ImgHelpersDecoderDiagnostic;
#define R4ImgHelpersDecoderDiagnostic_TYPE 153u
/* R4IMG.Bindings.Zig.r4img.Context; native size 8, alignment 8. */
typedef struct R4ImgHelpersContext { _Alignas(8) uint8_t opaque_bytes[8]; } R4ImgHelpersContext;
#define R4ImgHelpersContext_TYPE 154u
/* R4IMG.Bindings.Zig.r4img_abi.ApiV1Client; native size 8, alignment 8. */
typedef struct R4Lib_R4IMG_Bindings_Zig_r4img_abi_ApiV1Client { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_R4IMG_Bindings_Zig_r4img_abi_ApiV1Client;
#define R4Lib_R4IMG_Bindings_Zig_r4img_abi_ApiV1Client_TYPE 155u
/* R4IMG.Bindings.Zig.r4img.PngContext; native size 8, alignment 8. */
typedef struct R4ImgHelpersPngContext { _Alignas(8) uint8_t opaque_bytes[8]; } R4ImgHelpersPngContext;
#define R4ImgHelpersPngContext_TYPE 156u
/* R4IMG.Bindings.Zig.r4img_abi.PngV1Client; native size 8, alignment 8. */
typedef struct R4Lib_R4IMG_Bindings_Zig_r4img_abi_PngV1Client { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_R4IMG_Bindings_Zig_r4img_abi_PngV1Client;
#define R4Lib_R4IMG_Bindings_Zig_r4img_abi_PngV1Client_TYPE 157u
/* R4IMG.Bindings.Zig.color.Decoder(R4GFX.Bindings.Zig.r4gfx_abi).Policy; native size 20, alignment 4. */
typedef struct R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Policy { _Alignas(4) uint8_t opaque_bytes[20]; } R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Policy;
#define R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Policy_TYPE 158u
/* R4IMG.Bindings.Zig.color.Decoder(R4GFX.Bindings.Zig.r4gfx_abi).Characterization; native size 124, alignment 4. */
typedef struct R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Characterization { _Alignas(4) uint8_t opaque_bytes[124]; } R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Characterization;
#define R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Characterization_TYPE 159u
/* R4GFX.Bindings.Zig.r4gfx_abi.R4GfxColorDescription; native size 48, alignment 4. */
typedef struct R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription { _Alignas(4) uint8_t opaque_bytes[48]; } R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription;
#define R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription_TYPE 160u
/* ?R4GFX.Bindings.Zig.r4gfx_abi.R4GfxColorProfileDefinition; native size 68, alignment 4. */
typedef struct R4Lib_Value161 { _Alignas(4) uint8_t opaque_bytes[68]; } R4Lib_Value161;
#define R4Lib_Value161_TYPE 161u
/* R4GFX.Bindings.Zig.r4gfx_abi.R4GfxColorProfileDefinition; native size 64, alignment 4. */
typedef struct R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition { _Alignas(4) uint8_t opaque_bytes[64]; } R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition;
#define R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition_TYPE 162u
/* R4IMG.Bindings.Zig.color.Decoder(R4GFX.Bindings.Zig.r4gfx_abi).Result; native size 144, alignment 4. */
typedef struct R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Result { _Alignas(4) uint8_t opaque_bytes[144]; } R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Result;
#define R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Result_TYPE 163u
/* R4IMG.Bindings.Zig.color.Decoder(R4GFX.Bindings.Zig.r4gfx_abi).RasterResult; native size 104, alignment 4. */
typedef struct R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__RasterResult { _Alignas(4) uint8_t opaque_bytes[104]; } R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__RasterResult;
#define R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__RasterResult_TYPE 164u
/* error{ColorTransform,InvalidColor,ProfileLimit,UnsupportedColor}!R4IMG.Bindings.Zig.color.Decoder(R4GFX.Bindings.Zig.r4gfx_abi).Characterization; native size 128, alignment 4. */
typedef struct R4Lib_Value165 { _Alignas(4) uint8_t opaque_bytes[128]; } R4Lib_Value165;
#define R4Lib_Value165_TYPE 165u
/* mem.Allocator; native size 16, alignment 8. */
typedef struct R4LibraryAllocator { _Alignas(8) uint8_t opaque_bytes[16]; } R4LibraryAllocator;
#define R4LibraryAllocator_TYPE 166u
/* *const R4IMG.Bindings.Zig.r4img.Context; native size 8, alignment 8. */
typedef struct R4Lib_Value167 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value167;
#define R4Lib_Value167_TYPE 167u
/* *const R4IMG.Bindings.Zig.r4img.PngContext; native size 8, alignment 8. */
typedef struct R4Lib_Value168 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value168;
#define R4Lib_Value168_TYPE 168u
/* *const R4GFX.Bindings.Zig.r4gfx_abi.ColorV1Client; native size 8, alignment 8. */
typedef struct R4Lib_Value169 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value169;
#define R4Lib_Value169_TYPE 169u
/* R4GFX.Bindings.Zig.r4gfx_abi.ColorV1Client; native size 8, alignment 8. */
typedef struct R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_ColorV1Client { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_ColorV1Client;
#define R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_ColorV1Client_TYPE 170u
/* *const R4GFX.Bindings.Zig.r4gfx_abi.R4GfxColorImage; native size 8, alignment 8. */
typedef struct R4Lib_Value171 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value171;
#define R4Lib_Value171_TYPE 171u
/* R4GFX.Bindings.Zig.r4gfx_abi.R4GfxColorImage; native size 112, alignment 8. */
typedef struct R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorImage { _Alignas(8) uint8_t opaque_bytes[112]; } R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorImage;
#define R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorImage_TYPE 172u
/* R4GFX.Bindings.Zig.r4gfx_abi.R4GfxCpuImage; native size 40, alignment 8. */
typedef struct R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxCpuImage { _Alignas(8) uint8_t opaque_bytes[40]; } R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxCpuImage;
#define R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxCpuImage_TYPE 173u
/* R4GFX.Bindings.Zig.r4gfx_abi.R4GfxColorProfile; native size 16, alignment 8. */
typedef struct R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfile { _Alignas(8) uint8_t opaque_bytes[16]; } R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfile;
#define R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfile_TYPE 174u
/* *const R4GFX.Bindings.Zig.r4gfx_abi.R4GfxColorTransform; native size 8, alignment 8. */
typedef struct R4Lib_Value175 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value175;
#define R4Lib_Value175_TYPE 175u
/* R4GFX.Bindings.Zig.r4gfx_abi.R4GfxColorTransform; native size 64, alignment 8. */
typedef struct R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorTransform { _Alignas(8) uint8_t opaque_bytes[64]; } R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorTransform;
#define R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorTransform_TYPE 176u
/* R4GFX.Bindings.Zig.r4gfx_abi.R4GfxRect; native size 16, alignment 4. */
typedef struct R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxRect { _Alignas(4) uint8_t opaque_bytes[16]; } R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxRect;
#define R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxRect_TYPE 177u
/* @typeInfo(@typeInfo(@TypeOf(R4IMG.Bindings.Zig.color.Decoder(R4GFX.Bindings.Zig.r4gfx_abi).decode)).@"fn".return_type.?).error_union.error_set!R4IMG.Bindings.Zig.color.Decoder(R4GFX.Bindings.Zig.r4gfx_abi).Result; native size 148, alignment 4. */
typedef struct R4Lib_Value178 { _Alignas(4) uint8_t opaque_bytes[148]; } R4Lib_Value178;
#define R4Lib_Value178_TYPE 178u
/* *const R4IMG.Bindings.Zig.r4img.RasterContext; native size 8, alignment 8. */
typedef struct R4Lib_Value179 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value179;
#define R4Lib_Value179_TYPE 179u
/* @typeInfo(@typeInfo(@TypeOf(R4IMG.Bindings.Zig.color.Decoder(R4GFX.Bindings.Zig.r4gfx_abi).decodeRaster)).@"fn".return_type.?).error_union.error_set!R4IMG.Bindings.Zig.color.Decoder(R4GFX.Bindings.Zig.r4gfx_abi).RasterResult; native size 108, alignment 4. */
typedef struct R4Lib_Value180 { _Alignas(4) uint8_t opaque_bytes[108]; } R4Lib_Value180;
#define R4Lib_Value180_TYPE 180u
/* R4VIDEO.Bindings.Zig.r4video.VideoV1Client; native size 8, alignment 8. */
typedef struct R4Lib_R4VIDEO_Bindings_Zig_r4video_VideoV1Client { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_R4VIDEO_Bindings_Zig_r4video_VideoV1Client;
#define R4Lib_R4VIDEO_Bindings_Zig_r4video_VideoV1Client_TYPE 181u
/* *const R4VIDEO.Bindings.Zig.r4video.R4VideoRuntime; native size 8, alignment 8. */
typedef struct R4Lib_Value182 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value182;
#define R4Lib_Value182_TYPE 182u
/* R4VIDEO.Bindings.Zig.r4video.R4VideoRuntime; native size 16, alignment 8. */
typedef struct R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoRuntime { _Alignas(8) uint8_t opaque_bytes[16]; } R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoRuntime;
#define R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoRuntime_TYPE 183u
/* *R4VIDEO.Bindings.Zig.r4video.R4VideoCaps; native size 8, alignment 8. */
typedef struct R4Lib_Value184 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value184;
#define R4Lib_Value184_TYPE 184u
/* R4VIDEO.Bindings.Zig.r4video.R4VideoCaps; native size 104, alignment 8. */
typedef struct R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps { _Alignas(8) uint8_t opaque_bytes[104]; } R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps;
#define R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps_TYPE 185u
/* R4VIDEO.Bindings.Zig.r4video.R4VideoCapsQuery; native size 32, alignment 4. */
typedef struct R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCapsQuery { _Alignas(4) uint8_t opaque_bytes[32]; } R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCapsQuery;
#define R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCapsQuery_TYPE 186u
/* *R4IMG.Bindings.Zig.native_jpeg.Consumer(R4VIDEO.Bindings.Zig.r4video); native size 8, alignment 8. */
typedef struct R4Lib_Value187 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value187;
#define R4Lib_Value187_TYPE 187u
/* R4IMG.Bindings.Zig.native_jpeg.Consumer(R4VIDEO.Bindings.Zig.r4video); native size 88, alignment 8. */
typedef struct R4ImgNativeJpeg { _Alignas(8) uint8_t opaque_bytes[88]; } R4ImgNativeJpeg;
#define R4ImgNativeJpeg_TYPE 188u
/* R4VIDEO.Bindings.Zig.r4video.R4VideoDecoder; native size 16, alignment 8. */
typedef struct R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoDecoder { _Alignas(8) uint8_t opaque_bytes[16]; } R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoDecoder;
#define R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoDecoder_TYPE 189u
/* ?R4VIDEO.Bindings.Zig.r4video.R4VideoLease; native size 40, alignment 8. */
typedef struct R4Lib_Value190 { _Alignas(8) uint8_t opaque_bytes[40]; } R4Lib_Value190;
#define R4Lib_Value190_TYPE 190u
/* R4VIDEO.Bindings.Zig.r4video.R4VideoLease; native size 32, alignment 8. */
typedef struct R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoLease { _Alignas(8) uint8_t opaque_bytes[32]; } R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoLease;
#define R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoLease_TYPE 191u
/* *R4VIDEO.Bindings.Zig.r4video.R4VideoFrame; native size 8, alignment 8. */
typedef struct R4Lib_Value192 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value192;
#define R4Lib_Value192_TYPE 192u
/* R4VIDEO.Bindings.Zig.r4video.R4VideoFrame; native size 400, alignment 8. */
typedef struct R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame { _Alignas(8) uint8_t opaque_bytes[400]; } R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame;
#define R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_TYPE 193u
/* R4VIDEO.Bindings.Zig.r4video.R4VideoColor; native size 48, alignment 4. */
typedef struct R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor { _Alignas(4) uint8_t opaque_bytes[48]; } R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor;
#define R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor_TYPE 194u
/* R4VIDEO.Bindings.Zig.r4video.R4VideoPlane; native size 64, alignment 8. */
typedef struct R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoPlane { _Alignas(8) uint8_t opaque_bytes[64]; } R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoPlane;
#define R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoPlane_TYPE 195u
/* R4VIDEO.Bindings.Zig.r4video.R4VideoBuffer; native size 16, alignment 8. */
typedef struct R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoBuffer { _Alignas(8) uint8_t opaque_bytes[16]; } R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoBuffer;
#define R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoBuffer_TYPE 196u
/* R4VIDEO.Bindings.Zig.r4video.R4VideoFence; native size 40, alignment 8. */
typedef struct R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFence { _Alignas(8) uint8_t opaque_bytes[40]; } R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFence;
#define R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFence_TYPE 197u
/* *const R4VIDEO.Bindings.Zig.r4video.R4VideoReceipt; native size 8, alignment 8. */
typedef struct R4Lib_Value198 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value198;
#define R4Lib_Value198_TYPE 198u
/* R4VIDEO.Bindings.Zig.r4video.R4VideoReceipt; native size 56, alignment 8. */
typedef struct R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoReceipt { _Alignas(8) uint8_t opaque_bytes[56]; } R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoReceipt;
#define R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoReceipt_TYPE 199u
/* R4IMG.Bindings.Zig.native_jpeg.Dimensions; native size 8, alignment 4. */
typedef struct R4Lib_R4IMG_Bindings_Zig_native_jpeg_Dimensions { _Alignas(4) uint8_t opaque_bytes[8]; } R4Lib_R4IMG_Bindings_Zig_native_jpeg_Dimensions;
#define R4Lib_R4IMG_Bindings_Zig_native_jpeg_Dimensions_TYPE 200u
/* error{Unsupported}!R4IMG.Bindings.Zig.native_jpeg.Dimensions; native size 12, alignment 4. */
typedef struct R4Lib_Value201 { _Alignas(4) uint8_t opaque_bytes[12]; } R4Lib_Value201;
#define R4Lib_Value201_TYPE 201u
/* R4FONT.Bindings.Zig.r4font.Format; native size 4, alignment 4. */
typedef struct R4FontHelpersFormat { _Alignas(4) uint8_t opaque_bytes[4]; } R4FontHelpersFormat;
#define R4FontHelpersFormat_TYPE 202u
/* R4FONT.Bindings.Zig.r4font.Diagnostics; native size 56, alignment 8. */
typedef struct R4FontHelpersDiagnostics { _Alignas(8) uint8_t opaque_bytes[56]; } R4FontHelpersDiagnostics;
#define R4FontHelpersDiagnostics_TYPE 203u
/* R4FONT.Bindings.Zig.r4font.TestingFaultInjection; native size 32, alignment 8. */
typedef struct R4FontHelpersTestingFaultInjection { _Alignas(8) uint8_t opaque_bytes[32]; } R4FontHelpersTestingFaultInjection;
#define R4FontHelpersTestingFaultInjection_TYPE 204u
/* R4FONT.Bindings.Zig.r4font.FaceInfo; native size 72, alignment 8. */
typedef struct R4FontHelpersFaceInfo { _Alignas(8) uint8_t opaque_bytes[72]; } R4FontHelpersFaceInfo;
#define R4FontHelpersFaceInfo_TYPE 205u
/* R4FONT.Bindings.Zig.r4font.GlyphMetrics; native size 28, alignment 4. */
typedef struct R4FontHelpersGlyphMetrics { _Alignas(4) uint8_t opaque_bytes[28]; } R4FontHelpersGlyphMetrics;
#define R4FontHelpersGlyphMetrics_TYPE 206u
/* R4FONT.Bindings.Zig.r4font.Raster; native size 40, alignment 8. */
typedef struct R4FontHelpersRaster { _Alignas(8) uint8_t opaque_bytes[40]; } R4FontHelpersRaster;
#define R4FontHelpersRaster_TYPE 207u
/* R4FONT.Bindings.Zig.r4font.Context; native size 8, alignment 8. */
typedef struct R4FontHelpersContext { _Alignas(8) uint8_t opaque_bytes[8]; } R4FontHelpersContext;
#define R4FontHelpersContext_TYPE 208u
/* R4FONT.Bindings.Zig.r4font_abi.ApiV1Client; native size 8, alignment 8. */
typedef struct R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1Client { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1Client;
#define R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1Client_TYPE 209u
/* R4FONT.Bindings.Zig.r4font.Decoder; native size 24, alignment 8. */
typedef struct R4FontHelpersDecoder { _Alignas(8) uint8_t opaque_bytes[24]; } R4FontHelpersDecoder;
#define R4FontHelpersDecoder_TYPE 210u
/* *R4FONT.Bindings.Zig.r4font.AllocatorState; native size 8, alignment 8. */
typedef struct R4Lib_Value211 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value211;
#define R4Lib_Value211_TYPE 211u
/* R4FONT.Bindings.Zig.r4font.AllocatorState; native size 48, alignment 8. */
typedef struct R4FontHelpersAllocatorState { _Alignas(8) uint8_t opaque_bytes[48]; } R4FontHelpersAllocatorState;
#define R4FontHelpersAllocatorState_TYPE 212u
/* R4FONT.Bindings.Zig.r4font.Face; native size 16, alignment 8. */
typedef struct R4FontHelpersFace { _Alignas(8) uint8_t opaque_bytes[16]; } R4FontHelpersFace;
#define R4FontHelpersFace_TYPE 213u
/* R4FONT.Bindings.Zig.app_fonts.FaceHandle; native size 16, alignment 8. */
typedef struct R4FontStoreFaceHandle { _Alignas(8) uint8_t opaque_bytes[16]; } R4FontStoreFaceHandle;
#define R4FontStoreFaceHandle_TYPE 214u
/* R4FONT.Bindings.Zig.app_fonts.Options; native size 24, alignment 8. */
typedef struct R4FontStoreOptions { _Alignas(8) uint8_t opaque_bytes[24]; } R4FontStoreOptions;
#define R4FontStoreOptions_TYPE 215u
/* R4FONT.Bindings.Zig.app_fonts.FaceMetrics26_6; native size 16, alignment 4. */
typedef struct R4FontStoreFaceMetrics26_6 { _Alignas(4) uint8_t opaque_bytes[16]; } R4FontStoreFaceMetrics26_6;
#define R4FontStoreFaceMetrics26_6_TYPE 216u
/* R4FONT.Bindings.Zig.app_fonts.GlyphMetrics26_6; native size 24, alignment 4. */
typedef struct R4FontStoreGlyphMetrics26_6 { _Alignas(4) uint8_t opaque_bytes[24]; } R4FontStoreGlyphMetrics26_6;
#define R4FontStoreGlyphMetrics26_6_TYPE 217u
/* [2]i32; native size 8, alignment 4. */
typedef struct R4Lib_Value218 { _Alignas(4) uint8_t opaque_bytes[8]; } R4Lib_Value218;
#define R4Lib_Value218_TYPE 218u
/* R4FONT.Bindings.Zig.app_fonts.BorrowedRaster; native size 40, alignment 8. */
typedef struct R4FontStoreBorrowedRaster { _Alignas(8) uint8_t opaque_bytes[40]; } R4FontStoreBorrowedRaster;
#define R4FontStoreBorrowedRaster_TYPE 219u
/* R4FONT.Bindings.Zig.app_fonts.CacheStats; native size 48, alignment 8. */
typedef struct R4FontStoreCacheStats { _Alignas(8) uint8_t opaque_bytes[48]; } R4FontStoreCacheStats;
#define R4FontStoreCacheStats_TYPE 220u
/* R4FONT.Bindings.Zig.app_fonts.Diagnostics; native size 112, alignment 8. */
typedef struct R4FontStoreDiagnostics { _Alignas(8) uint8_t opaque_bytes[112]; } R4FontStoreDiagnostics;
#define R4FontStoreDiagnostics_TYPE 221u
/* R4FONT.Bindings.Zig.app_fonts.FaceStore; native size 192, alignment 8. */
typedef struct R4FontStoreFaceStore { _Alignas(8) uint8_t opaque_bytes[192]; } R4FontStoreFaceStore;
#define R4FontStoreFaceStore_TYPE 222u
/* array_list.Aligned(R4FONT.Bindings.Zig.app_fonts.Slot,null); native size 24, alignment 8. */
typedef struct R4Lib_array_list_Aligned_R4FONT_Bindings_Zig_app_fonts_Slot_null_ { _Alignas(8) uint8_t opaque_bytes[24]; } R4Lib_array_list_Aligned_R4FONT_Bindings_Zig_app_fonts_Slot_null_;
#define R4Lib_array_list_Aligned_R4FONT_Bindings_Zig_app_fonts_Slot_null__TYPE 223u
/* array_list.Aligned(R4FONT.Bindings.Zig.app_fonts.SourceSlot,null); native size 24, alignment 8. */
typedef struct R4Lib_array_list_Aligned_R4FONT_Bindings_Zig_app_fonts_SourceSlot_null_ { _Alignas(8) uint8_t opaque_bytes[24]; } R4Lib_array_list_Aligned_R4FONT_Bindings_Zig_app_fonts_SourceSlot_null_;
#define R4Lib_array_list_Aligned_R4FONT_Bindings_Zig_app_fonts_SourceSlot_null__TYPE 224u
/* array_list.Aligned(R4FONT.Bindings.Zig.app_fonts.CacheEntry,null); native size 24, alignment 8. */
typedef struct R4Lib_array_list_Aligned_R4FONT_Bindings_Zig_app_fonts_CacheEntry_null_ { _Alignas(8) uint8_t opaque_bytes[24]; } R4Lib_array_list_Aligned_R4FONT_Bindings_Zig_app_fonts_CacheEntry_null_;
#define R4Lib_array_list_Aligned_R4FONT_Bindings_Zig_app_fonts_CacheEntry_null__TYPE 225u
/* ?[]u8; native size 16, alignment 8. */
typedef struct R4Lib_Value226 { _Alignas(8) uint8_t opaque_bytes[16]; } R4Lib_Value226;
#define R4Lib_Value226_TYPE 226u
/* R4FONT.Bindings.Zig.font_import.FaceInfo; native size 64, alignment 8. */
typedef struct R4FontImportFaceInfo { _Alignas(8) uint8_t opaque_bytes[64]; } R4FontImportFaceInfo;
#define R4FontImportFaceInfo_TYPE 227u
/* R4FONT.Bindings.Zig.font_import.RasterGlyph; native size 32, alignment 8. */
typedef struct R4FontImportRasterGlyph { _Alignas(8) uint8_t opaque_bytes[32]; } R4FontImportRasterGlyph;
#define R4FontImportRasterGlyph_TYPE 228u
/* R4FONT.Bindings.Zig.font_import.Preview; native size 4, alignment 2. */
typedef struct R4FontImportPreview { _Alignas(2) uint8_t opaque_bytes[4]; } R4FontImportPreview;
#define R4FontImportPreview_TYPE 229u
/* @typeInfo(@typeInfo(@TypeOf(R4FONT.Bindings.Zig.font_import.inspect)).@"fn".return_type.?).error_union.error_set!R4FONT.Bindings.Zig.font_import.FaceInfo; native size 72, alignment 8. */
typedef struct R4Lib_Value230 { _Alignas(8) uint8_t opaque_bytes[72]; } R4Lib_Value230;
#define R4Lib_Value230_TYPE 230u
/* @typeInfo(@typeInfo(@TypeOf(R4FONT.Bindings.Zig.font_import.convert)).@"fn".return_type.?).error_union.error_set![]u8; native size 24, alignment 8. */
typedef struct R4Lib_Value231 { _Alignas(8) uint8_t opaque_bytes[24]; } R4Lib_Value231;
#define R4Lib_Value231_TYPE 231u
/* @typeInfo(@typeInfo(@TypeOf(R4FONT.Bindings.Zig.font_import.rasterizePreview)).@"fn".return_type.?).error_union.error_set!R4FONT.Bindings.Zig.font_import.Preview; native size 6, alignment 2. */
typedef struct R4Lib_Value232 { _Alignas(2) uint8_t opaque_bytes[6]; } R4Lib_Value232;
#define R4Lib_Value232_TYPE 232u
/* Shared.Language.support.Session; native size 64, alignment 8. */
typedef struct R4LibrarySession { _Alignas(8) uint8_t opaque_bytes[64]; } R4LibrarySession;
#define R4LibrarySession_TYPE 233u
/* *Shared.Language.support.Session; native size 8, alignment 8. */
typedef struct R4Lib_Value234 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value234;
#define R4Lib_Value234_TYPE 234u
/* *r4os.r4sys.Context; native size 8, alignment 8. */
typedef struct R4Lib_Value235 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value235;
#define R4Lib_Value235_TYPE 235u
/* r4os.r4sys.Context; native size 8, alignment 8. */
typedef struct R4Lib_r4os_r4sys_Context { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_r4os_r4sys_Context;
#define R4Lib_r4os_r4sys_Context_TYPE 236u
/* Shared.Language.support.Memory; native size 24, alignment 8. */
typedef struct R4LibraryMemory { _Alignas(8) uint8_t opaque_bytes[24]; } R4LibraryMemory;
#define R4LibraryMemory_TYPE 237u
/* @typeInfo(@typeInfo(@TypeOf(Shared.Language.support.colorClient)).@"fn".return_type.?).error_union.error_set!R4GFX.Bindings.Zig.r4gfx_abi.ColorV1Client; native size 16, alignment 8. */
typedef struct R4Lib_Value238 { _Alignas(8) uint8_t opaque_bytes[16]; } R4Lib_Value238;
#define R4Lib_Value238_TYPE 238u
/* @typeInfo(@typeInfo(@TypeOf(Shared.Language.support.videoClient)).@"fn".return_type.?).error_union.error_set!R4VIDEO.Bindings.Zig.r4video.VideoV1Client; native size 16, alignment 8. */
typedef struct R4Lib_Value239 { _Alignas(8) uint8_t opaque_bytes[16]; } R4Lib_Value239;
#define R4Lib_Value239_TYPE 239u
/* consumer_adapters.Saver; native size 16, alignment 8. */
typedef struct R4StdAdaptersSaver { _Alignas(8) uint8_t opaque_bytes[16]; } R4StdAdaptersSaver;
#define R4StdAdaptersSaver_TYPE 240u
/* [*:0]const u8; native size 8, alignment 8. */
typedef struct R4Lib_Value241 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value241;
#define R4Lib_Value241_TYPE 241u
/* *bool; native size 8, alignment 8. */
typedef struct R4Lib_Value242 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value242;
#define R4Lib_Value242_TYPE 242u
/* *u32; native size 8, alignment 8. */
typedef struct R4Lib_Value243 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value243;
#define R4Lib_Value243_TYPE 243u
/* *i32; native size 8, alignment 8. */
typedef struct R4Lib_Value244 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value244;
#define R4Lib_Value244_TYPE 244u
/* *R4STD.Bindings.Zig.settings.Writeback; native size 8, alignment 8. */
typedef struct R4Lib_Value245 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value245;
#define R4Lib_Value245_TYPE 245u
/* *r4os.gui.TextArea([]u8); native size 8, alignment 8. */
typedef struct R4Lib_Value246 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value246;
#define R4Lib_Value246_TYPE 246u
/* r4os.gui.TextArea([]u8); native size 128, alignment 8. */
typedef struct R4Lib_r4os_gui_TextArea___u8_ { _Alignas(8) uint8_t opaque_bytes[128]; } R4Lib_r4os_gui_TextArea___u8_;
#define R4Lib_r4os_gui_TextArea___u8__TYPE 247u
/* r4os.gui.TextAreaView; native size 24, alignment 8. */
typedef struct R4Lib_r4os_gui_TextAreaView { _Alignas(8) uint8_t opaque_bytes[24]; } R4Lib_r4os_gui_TextAreaView;
#define R4Lib_r4os_gui_TextAreaView_TYPE 248u
/* R4STD.Bindings.Zig.text_file.LoadResult; native size 12, alignment 4. */
typedef struct R4Lib_R4STD_Bindings_Zig_text_file_LoadResult { _Alignas(4) uint8_t opaque_bytes[12]; } R4Lib_R4STD_Bindings_Zig_text_file_LoadResult;
#define R4Lib_R4STD_Bindings_Zig_text_file_LoadResult_TYPE 249u
/* R4STD.Bindings.Zig.text_file.SaveResult; native size 8, alignment 4. */
typedef struct R4Lib_R4STD_Bindings_Zig_text_file_SaveResult { _Alignas(4) uint8_t opaque_bytes[8]; } R4Lib_R4STD_Bindings_Zig_text_file_SaveResult;
#define R4Lib_R4STD_Bindings_Zig_text_file_SaveResult_TYPE 250u
/* *R4STD.Bindings.Zig.subsystem_runtime.AccessStats; native size 8, alignment 8. */
typedef struct R4Lib_Value251 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value251;
#define R4Lib_Value251_TYPE 251u
/* error{BufferTooSmall,Directory,DuplicateGuest,InvalidAssociation,InvalidGuestPath,InvalidInput,InvalidKey,InvalidMagic,InvalidPath,InvalidValue,MalformedRecord,MissingFile,MissingGuest,ReadFailed,StaleAssociation,TooManyCandidates,TooManyChoices,TooManyOptions}!void; native size 2, alignment 2. */
typedef struct R4Lib_Value252 { _Alignas(2) uint8_t opaque_bytes[2]; } R4Lib_Value252;
#define R4Lib_Value252_TYPE 252u
/* error{Directory,InvalidPath,MissingFile,ReadFailed}!R4STD.Bindings.Zig.subsystem_runtime.Inspection; native size 72, alignment 8. */
typedef struct R4Lib_Value253 { _Alignas(8) uint8_t opaque_bytes[72]; } R4Lib_Value253;
#define R4Lib_Value253_TYPE 253u
/* error{Directory,InvalidPath,MissingFile,ReadFailed}!r4os.subsystem_catalog.Input; native size 56, alignment 8. */
typedef struct R4Lib_Value254 { _Alignas(8) uint8_t opaque_bytes[56]; } R4Lib_Value254;
#define R4Lib_Value254_TYPE 254u
/* *R4STD.Bindings.Zig.settings.EntryIterator; native size 8, alignment 8. */
typedef struct R4Lib_Value255 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value255;
#define R4Lib_Value255_TYPE 255u
/* *R4STD.Bindings.Zig.settings.Writer; native size 8, alignment 8. */
typedef struct R4Lib_Value256 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value256;
#define R4Lib_Value256_TYPE 256u
/* *const R4STD.Bindings.Zig.settings.Writer; native size 8, alignment 8. */
typedef struct R4Lib_Value257 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value257;
#define R4Lib_Value257_TYPE 257u
/* *const R4STD.Bindings.Zig.settings.Writeback; native size 8, alignment 8. */
typedef struct R4Lib_Value258 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value258;
#define R4Lib_Value258_TYPE 258u
/* *R4STD.Bindings.Zig.time.Config; native size 8, alignment 8. */
typedef struct R4Lib_Value259 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value259;
#define R4Lib_Value259_TYPE 259u
/* *R4STD.Bindings.Zig.codec.Stream; native size 8, alignment 8. */
typedef struct R4Lib_Value260 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value260;
#define R4Lib_Value260_TYPE 260u
/* *const R4STD.Bindings.Zig.codec.Stream; native size 8, alignment 8. */
typedef struct R4Lib_Value261 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value261;
#define R4Lib_Value261_TYPE 261u
/* error{BufferTooSmall,InvalidArgument,InvalidScalar,InvalidUtf8,RangesOverlap,RuntimeUnavailable,UndefinedByte,Unrepresentable}!bool; native size 4, alignment 2. */
typedef struct R4Lib_Value262 { _Alignas(2) uint8_t opaque_bytes[4]; } R4Lib_Value262;
#define R4Lib_Value262_TYPE 262u
/* *R4STD.Bindings.Zig.grapheme.State; native size 8, alignment 8. */
typedef struct R4Lib_Value263 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value263;
#define R4Lib_Value263_TYPE 263u
/* *R4STD.Bindings.Zig.grapheme.Iterator; native size 8, alignment 8. */
typedef struct R4Lib_Value264 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value264;
#define R4Lib_Value264_TYPE 264u
/* error{Incomplete,InvalidUtf8}!?R4STD.Bindings.Zig.grapheme.Range; native size 32, alignment 8. */
typedef struct R4Lib_Value265 { _Alignas(8) uint8_t opaque_bytes[32]; } R4Lib_Value265;
#define R4Lib_Value265_TYPE 265u
/* ?R4STD.Bindings.Zig.grapheme.Range; native size 24, alignment 8. */
typedef struct R4Lib_Value266 { _Alignas(8) uint8_t opaque_bytes[24]; } R4Lib_Value266;
#define R4Lib_Value266_TYPE 266u
/* *R4STD.Bindings.Zig.grapheme.Stream; native size 8, alignment 8. */
typedef struct R4Lib_Value267 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value267;
#define R4Lib_Value267_TYPE 267u
/* error{Incomplete,InvalidUtf8}!?R4STD.Bindings.Zig.grapheme.Stream.Event; native size 40, alignment 8. */
typedef struct R4Lib_Value268 { _Alignas(8) uint8_t opaque_bytes[40]; } R4Lib_Value268;
#define R4Lib_Value268_TYPE 268u
/* ?R4STD.Bindings.Zig.grapheme.Stream.Event; native size 32, alignment 8. */
typedef struct R4Lib_Value269 { _Alignas(8) uint8_t opaque_bytes[32]; } R4Lib_Value269;
#define R4Lib_Value269_TYPE 269u
/* R4STD.Bindings.Zig.grapheme.Stream.Event; native size 24, alignment 8. */
typedef struct R4StdGraphemeStream_Event { _Alignas(8) uint8_t opaque_bytes[24]; } R4StdGraphemeStream_Event;
#define R4StdGraphemeStream_Event_TYPE 270u
/* *const R4STD.Bindings.Zig.grapheme.Stream; native size 8, alignment 8. */
typedef struct R4Lib_Value271 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value271;
#define R4Lib_Value271_TYPE 271u
/* *R4STD.Bindings.Zig.shortcut.Shortcut; native size 8, alignment 8. */
typedef struct R4Lib_Value272 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value272;
#define R4Lib_Value272_TYPE 272u
/* error{ArgsTooLong,BufferTooSmall,DuplicateField,IconTooLong,InvalidPolicy,InvalidTarget,InvalidText,MissingFormat,MissingSchema,MissingTarget,TargetTooLong,TitleTooLong,UnknownField,UnsupportedFormat,WorkdirTooLong,WrongSchema}!void; native size 2, alignment 2. */
typedef struct R4Lib_Value273 { _Alignas(2) uint8_t opaque_bytes[2]; } R4Lib_Value273;
#define R4Lib_Value273_TYPE 273u
/* *const R4STD.Bindings.Zig.shortcut.Shortcut; native size 8, alignment 8. */
typedef struct R4Lib_Value274 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value274;
#define R4Lib_Value274_TYPE 274u
/* error{ArgsTooLong,BufferTooSmall,DuplicateField,IconTooLong,InvalidPolicy,InvalidTarget,InvalidText,MissingFormat,MissingSchema,MissingTarget,TargetTooLong,TitleTooLong,UnknownField,UnsupportedFormat,WorkdirTooLong,WrongSchema}![]const u8; native size 24, alignment 8. */
typedef struct R4Lib_Value275 { _Alignas(8) uint8_t opaque_bytes[24]; } R4Lib_Value275;
#define R4Lib_Value275_TYPE 275u
/* error{ArgsTooLong,BufferTooSmall,DuplicateField,IconTooLong,InvalidPolicy,InvalidTarget,InvalidText,MissingFormat,MissingSchema,MissingTarget,TargetTooLong,TitleTooLong,UnknownField,UnsupportedFormat,WorkdirTooLong,WrongSchema}!R4STD.Bindings.Zig.shortcut.ResolvedTarget; native size 96, alignment 8. */
typedef struct R4Lib_Value276 { _Alignas(8) uint8_t opaque_bytes[96]; } R4Lib_Value276;
#define R4Lib_Value276_TYPE 276u
/* *const R4STD.Bindings.Zig.app_assoc.ExtEntry; native size 8, alignment 8. */
typedef struct R4Lib_Value277 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value277;
#define R4Lib_Value277_TYPE 277u
/* *R4STD.Bindings.Zig.app_assoc.Config; native size 8, alignment 8. */
typedef struct R4Lib_Value278 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value278;
#define R4Lib_Value278_TYPE 278u
/* ?*const R4STD.Bindings.Zig.app_assoc.ExtEntry; native size 8, alignment 8. */
typedef struct R4Lib_Value279 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value279;
#define R4Lib_Value279_TYPE 279u
/* ?R4STD.Bindings.Zig.app_assoc.LaunchTarget; native size 128, alignment 8. */
typedef struct R4Lib_Value280 { _Alignas(8) uint8_t opaque_bytes[128]; } R4Lib_Value280;
#define R4Lib_Value280_TYPE 280u
/* *const R4STD.Bindings.Zig.file_handler.ChoiceList; native size 8, alignment 8. */
typedef struct R4Lib_Value281 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value281;
#define R4Lib_Value281_TYPE 281u
/* []const R4STD.Bindings.Zig.file_handler.Choice; native size 16, alignment 8. */
typedef struct R4Lib_Value282 { _Alignas(8) uint8_t opaque_bytes[16]; } R4Lib_Value282;
#define R4Lib_Value282_TYPE 282u
/* error{DecodeFailed,Empty,InvalidArgument,InvalidDimensions,InvalidImage,PixelBufferTooSmall,ScratchBufferTooSmall,TooLarge,UnsupportedFeature,UnsupportedFormat}!usize; native size 16, alignment 8. */
typedef struct R4Lib_Value283 { _Alignas(8) uint8_t opaque_bytes[16]; } R4Lib_Value283;
#define R4Lib_Value283_TYPE 283u
/* ?R4IMG.Bindings.Zig.r4img.RasterContext; native size 16, alignment 8. */
typedef struct R4Lib_Value284 { _Alignas(8) uint8_t opaque_bytes[16]; } R4Lib_Value284;
#define R4Lib_Value284_TYPE 284u
/* error{DecodeFailed,Empty,InvalidArgument,InvalidDimensions,InvalidImage,PixelBufferTooSmall,ScratchBufferTooSmall,TooLarge,UnsupportedFeature,UnsupportedFormat}!R4IMG.Bindings.Zig.r4img_abi.R4ImgRasterColor; native size 92, alignment 4. */
typedef struct R4Lib_Value285 { _Alignas(4) uint8_t opaque_bytes[92]; } R4Lib_Value285;
#define R4Lib_Value285_TYPE 285u
/* error{DecodeFailed,Empty,InvalidArgument,InvalidDimensions,InvalidImage,PixelBufferTooSmall,ScratchBufferTooSmall,TooLarge,UnsupportedFeature,UnsupportedFormat}![]u8; native size 24, alignment 8. */
typedef struct R4Lib_Value286 { _Alignas(8) uint8_t opaque_bytes[24]; } R4Lib_Value286;
#define R4Lib_Value286_TYPE 286u
/* ?R4IMG.Bindings.Zig.r4img.Context; native size 16, alignment 8. */
typedef struct R4Lib_Value287 { _Alignas(8) uint8_t opaque_bytes[16]; } R4Lib_Value287;
#define R4Lib_Value287_TYPE 287u
/* error{DecodeFailed,Empty,InvalidArgument,InvalidDimensions,InvalidImage,PixelBufferTooSmall,ScratchBufferTooSmall,TooLarge,UnsupportedFeature,UnsupportedFormat}!R4IMG.Bindings.Zig.r4img.Info; native size 16, alignment 4. */
typedef struct R4Lib_Value288 { _Alignas(4) uint8_t opaque_bytes[16]; } R4Lib_Value288;
#define R4Lib_Value288_TYPE 288u
/* error{DecodeFailed,Empty,InvalidArgument,InvalidDimensions,InvalidImage,PixelBufferTooSmall,ScratchBufferTooSmall,TooLarge,UnsupportedFeature,UnsupportedFormat}!R4IMG.Bindings.Zig.r4img.Image; native size 40, alignment 8. */
typedef struct R4Lib_Value289 { _Alignas(8) uint8_t opaque_bytes[40]; } R4Lib_Value289;
#define R4Lib_Value289_TYPE 289u
/* error{DecodeFailed,Empty,InvalidArgument,InvalidDimensions,InvalidImage,PixelBufferTooSmall,ScratchBufferTooSmall,TooLarge,UnsupportedFeature,UnsupportedFormat}![]u32; native size 24, alignment 8. */
typedef struct R4Lib_Value290 { _Alignas(8) uint8_t opaque_bytes[24]; } R4Lib_Value290;
#define R4Lib_Value290_TYPE 290u
/* error{DecodeFailed,Empty,InvalidArgument,InvalidDimensions,InvalidImage,PixelBufferTooSmall,ScratchBufferTooSmall,TooLarge,UnsupportedFeature,UnsupportedFormat}!R4IMG.Bindings.Zig.r4img.DecoderDiagnostic; native size 24, alignment 8. */
typedef struct R4Lib_Value291 { _Alignas(8) uint8_t opaque_bytes[24]; } R4Lib_Value291;
#define R4Lib_Value291_TYPE 291u
/* ?R4IMG.Bindings.Zig.r4img.PngContext; native size 16, alignment 8. */
typedef struct R4Lib_Value292 { _Alignas(8) uint8_t opaque_bytes[16]; } R4Lib_Value292;
#define R4Lib_Value292_TYPE 292u
/* error{DecodeFailed,Empty,InvalidArgument,InvalidDimensions,InvalidImage,PixelBufferTooSmall,ScratchBufferTooSmall,TooLarge,UnsupportedFeature,UnsupportedFormat}!R4IMG.Bindings.Zig.r4img_abi.R4ImgPngColor; native size 132, alignment 4. */
typedef struct R4Lib_Value293 { _Alignas(4) uint8_t opaque_bytes[132]; } R4Lib_Value293;
#define R4Lib_Value293_TYPE 293u
/* error{DecodeFailed,Empty,InvalidArgument,InvalidDimensions,InvalidImage,PixelBufferTooSmall,ScratchBufferTooSmall,TooLarge,UnsupportedFeature,UnsupportedFormat}!R4IMG.Bindings.Zig.r4img.Image16; native size 168, alignment 8. */
typedef struct R4Lib_Value294 { _Alignas(8) uint8_t opaque_bytes[168]; } R4Lib_Value294;
#define R4Lib_Value294_TYPE 294u
/* ?R4FONT.Bindings.Zig.r4font.Context; native size 16, alignment 8. */
typedef struct R4Lib_Value295 { _Alignas(8) uint8_t opaque_bytes[16]; } R4Lib_Value295;
#define R4Lib_Value295_TYPE 295u
/* *const R4FONT.Bindings.Zig.r4font_abi.ApiV1; native size 8, alignment 8. */
typedef struct R4Lib_Value296 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value296;
#define R4Lib_Value296_TYPE 296u
/* R4FONT.Bindings.Zig.r4font_abi.ApiV1; native size 120, alignment 8. */
typedef struct R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1 { _Alignas(8) uint8_t opaque_bytes[120]; } R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1;
#define R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1_TYPE 297u
/* r4os.runtime_r4l.InterfaceHeader; native size 32, alignment 8. */
typedef struct R4Lib_r4os_runtime_r4l_InterfaceHeader { _Alignas(8) uint8_t opaque_bytes[32]; } R4Lib_r4os_runtime_r4l_InterfaceHeader;
#define R4Lib_r4os_runtime_r4l_InterfaceHeader_TYPE 298u
/* *const r4os.runtime_r4l.InterfaceHeader; native size 8, alignment 8. */
typedef struct R4Lib_Value299 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value299;
#define R4Lib_Value299_TYPE 299u
/* *const R4FONT.Bindings.Zig.r4font.Context; native size 8, alignment 8. */
typedef struct R4Lib_Value300 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value300;
#define R4Lib_Value300_TYPE 300u
/* ?R4FONT.Bindings.Zig.r4font.Format; native size 8, alignment 4. */
typedef struct R4Lib_Value301 { _Alignas(4) uint8_t opaque_bytes[8]; } R4Lib_Value301;
#define R4Lib_Value301_TYPE 301u
/* error{BufferTooSmall,DecoderFailure,InvalidArgument,InvalidFaceIndex,InvalidFont,InvalidGlyph,OutOfMemory,TooLarge,UnsupportedFormat}!R4FONT.Bindings.Zig.r4font.Decoder; native size 32, alignment 8. */
typedef struct R4Lib_Value302 { _Alignas(8) uint8_t opaque_bytes[32]; } R4Lib_Value302;
#define R4Lib_Value302_TYPE 302u
/* *R4FONT.Bindings.Zig.r4font.Decoder; native size 8, alignment 8. */
typedef struct R4Lib_Value303 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value303;
#define R4Lib_Value303_TYPE 303u
/* *const R4FONT.Bindings.Zig.r4font.Decoder; native size 8, alignment 8. */
typedef struct R4Lib_Value304 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value304;
#define R4Lib_Value304_TYPE 304u
/* error{BufferTooSmall,DecoderFailure,InvalidArgument,InvalidFaceIndex,InvalidFont,InvalidGlyph,OutOfMemory,TooLarge,UnsupportedFormat}!R4FONT.Bindings.Zig.r4font.Face; native size 24, alignment 8. */
typedef struct R4Lib_Value305 { _Alignas(8) uint8_t opaque_bytes[24]; } R4Lib_Value305;
#define R4Lib_Value305_TYPE 305u
/* *R4FONT.Bindings.Zig.r4font.Face; native size 8, alignment 8. */
typedef struct R4Lib_Value306 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value306;
#define R4Lib_Value306_TYPE 306u
/* *const R4FONT.Bindings.Zig.r4font.Face; native size 8, alignment 8. */
typedef struct R4Lib_Value307 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value307;
#define R4Lib_Value307_TYPE 307u
/* error{BufferTooSmall,DecoderFailure,InvalidArgument,InvalidFaceIndex,InvalidFont,InvalidGlyph,OutOfMemory,TooLarge,UnsupportedFormat}!R4FONT.Bindings.Zig.r4font.FaceInfo; native size 80, alignment 8. */
typedef struct R4Lib_Value308 { _Alignas(8) uint8_t opaque_bytes[80]; } R4Lib_Value308;
#define R4Lib_Value308_TYPE 308u
/* error{BufferTooSmall,DecoderFailure,InvalidArgument,InvalidFaceIndex,InvalidFont,InvalidGlyph,OutOfMemory,TooLarge,UnsupportedFormat}!R4FONT.Bindings.Zig.r4font.GlyphMetrics; native size 32, alignment 4. */
typedef struct R4Lib_Value309 { _Alignas(4) uint8_t opaque_bytes[32]; } R4Lib_Value309;
#define R4Lib_Value309_TYPE 309u
/* error{BufferTooSmall,DecoderFailure,InvalidArgument,InvalidFaceIndex,InvalidFont,InvalidGlyph,OutOfMemory,TooLarge,UnsupportedFormat}![2]i32; native size 12, alignment 4. */
typedef struct R4Lib_Value310 { _Alignas(4) uint8_t opaque_bytes[12]; } R4Lib_Value310;
#define R4Lib_Value310_TYPE 310u
/* error{BufferTooSmall,DecoderFailure,InvalidArgument,InvalidFaceIndex,InvalidFont,InvalidGlyph,OutOfMemory,TooLarge,UnsupportedFormat}!R4FONT.Bindings.Zig.r4font.Raster; native size 48, alignment 8. */
typedef struct R4Lib_Value311 { _Alignas(8) uint8_t opaque_bytes[48]; } R4Lib_Value311;
#define R4Lib_Value311_TYPE 311u
/* error{BufferTooSmall,DecoderFailure,InvalidArgument,InvalidFaceIndex,InvalidFont,InvalidGlyph,InvalidHandle,OutOfMemory,TooLarge,UnsupportedFormat}!R4FONT.Bindings.Zig.app_fonts.FaceStore; native size 200, alignment 8. */
typedef struct R4Lib_Value312 { _Alignas(8) uint8_t opaque_bytes[200]; } R4Lib_Value312;
#define R4Lib_Value312_TYPE 312u
/* *R4FONT.Bindings.Zig.app_fonts.FaceStore; native size 8, alignment 8. */
typedef struct R4Lib_Value313 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value313;
#define R4Lib_Value313_TYPE 313u
/* error{BufferTooSmall,DecoderFailure,InvalidArgument,InvalidFaceIndex,InvalidFont,InvalidGlyph,InvalidHandle,OutOfMemory,TooLarge,UnsupportedFormat}!R4FONT.Bindings.Zig.app_fonts.FaceHandle; native size 24, alignment 8. */
typedef struct R4Lib_Value314 { _Alignas(8) uint8_t opaque_bytes[24]; } R4Lib_Value314;
#define R4Lib_Value314_TYPE 314u
/* *R4FONT.Bindings.Zig.app_fonts.FaceHandle; native size 8, alignment 8. */
typedef struct R4Lib_Value315 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value315;
#define R4Lib_Value315_TYPE 315u
/* error{BufferTooSmall,DecoderFailure,InvalidArgument,InvalidFaceIndex,InvalidFont,InvalidGlyph,InvalidHandle,OutOfMemory,TooLarge,UnsupportedFormat}!void; native size 2, alignment 2. */
typedef struct R4Lib_Value316 { _Alignas(2) uint8_t opaque_bytes[2]; } R4Lib_Value316;
#define R4Lib_Value316_TYPE 316u
/* error{BufferTooSmall,DecoderFailure,InvalidArgument,InvalidFaceIndex,InvalidFont,InvalidGlyph,InvalidHandle,OutOfMemory,TooLarge,UnsupportedFormat}!R4FONT.Bindings.Zig.r4font.FaceInfo; native size 80, alignment 8. */
typedef struct R4Lib_Value317 { _Alignas(8) uint8_t opaque_bytes[80]; } R4Lib_Value317;
#define R4Lib_Value317_TYPE 317u
/* error{BufferTooSmall,DecoderFailure,InvalidArgument,InvalidFaceIndex,InvalidFont,InvalidGlyph,InvalidHandle,OutOfMemory,TooLarge,UnsupportedFormat}!?u32; native size 12, alignment 4. */
typedef struct R4Lib_Value318 { _Alignas(4) uint8_t opaque_bytes[12]; } R4Lib_Value318;
#define R4Lib_Value318_TYPE 318u
/* error{BufferTooSmall,DecoderFailure,InvalidArgument,InvalidFaceIndex,InvalidFont,InvalidGlyph,InvalidHandle,OutOfMemory,TooLarge,UnsupportedFormat}!bool; native size 4, alignment 2. */
typedef struct R4Lib_Value319 { _Alignas(2) uint8_t opaque_bytes[4]; } R4Lib_Value319;
#define R4Lib_Value319_TYPE 319u
/* error{BufferTooSmall,DecoderFailure,InvalidArgument,InvalidFaceIndex,InvalidFont,InvalidGlyph,InvalidHandle,OutOfMemory,TooLarge,UnsupportedFormat}!R4FONT.Bindings.Zig.app_fonts.FaceMetrics26_6; native size 20, alignment 4. */
typedef struct R4Lib_Value320 { _Alignas(4) uint8_t opaque_bytes[20]; } R4Lib_Value320;
#define R4Lib_Value320_TYPE 320u
/* error{BufferTooSmall,DecoderFailure,InvalidArgument,InvalidFaceIndex,InvalidFont,InvalidGlyph,InvalidHandle,OutOfMemory,TooLarge,UnsupportedFormat}!R4FONT.Bindings.Zig.app_fonts.GlyphMetrics26_6; native size 28, alignment 4. */
typedef struct R4Lib_Value321 { _Alignas(4) uint8_t opaque_bytes[28]; } R4Lib_Value321;
#define R4Lib_Value321_TYPE 321u
/* error{BufferTooSmall,DecoderFailure,InvalidArgument,InvalidFaceIndex,InvalidFont,InvalidGlyph,InvalidHandle,OutOfMemory,TooLarge,UnsupportedFormat}![2]i32; native size 12, alignment 4. */
typedef struct R4Lib_Value322 { _Alignas(4) uint8_t opaque_bytes[12]; } R4Lib_Value322;
#define R4Lib_Value322_TYPE 322u
/* error{BufferTooSmall,DecoderFailure,InvalidArgument,InvalidFaceIndex,InvalidFont,InvalidGlyph,InvalidHandle,OutOfMemory,TooLarge,UnsupportedFormat}!R4FONT.Bindings.Zig.r4font.Raster; native size 48, alignment 8. */
typedef struct R4Lib_Value323 { _Alignas(8) uint8_t opaque_bytes[48]; } R4Lib_Value323;
#define R4Lib_Value323_TYPE 323u
/* error{BufferTooSmall,DecoderFailure,InvalidArgument,InvalidFaceIndex,InvalidFont,InvalidGlyph,InvalidHandle,OutOfMemory,TooLarge,UnsupportedFormat}!R4FONT.Bindings.Zig.app_fonts.BorrowedRaster; native size 48, alignment 8. */
typedef struct R4Lib_Value324 { _Alignas(8) uint8_t opaque_bytes[48]; } R4Lib_Value324;
#define R4Lib_Value324_TYPE 324u
/* *const R4FONT.Bindings.Zig.app_fonts.FaceStore; native size 8, alignment 8. */
typedef struct R4Lib_Value325 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value325;
#define R4Lib_Value325_TYPE 325u
/* *Shared.Language.support.Memory; native size 8, alignment 8. */
typedef struct R4Lib_Value326 { _Alignas(8) uint8_t opaque_bytes[8]; } R4Lib_Value326;
#define R4Lib_Value326_TYPE 326u
#define R4Libraries_ABI_FINGERPRINT UINT64_C(10906934532697860863)
int32_t R4LibrariesVerifyAbi(uint64_t);
#define R4StdSettings_current_format_version (1)
#define R4StdDate_seconds_per_day (86400)
#define R4StdTime_zone_count (38)
#define R4StdTime_zone_id_max (31)
#define R4StdTime_zone_label_max (39)
#define R4StdTime_utc_index (13)
#define R4StdTime_seconds_per_day (86400)
#define R4StdConfig_max_path_len (1023)
#define R4StdConfig_max_file_bytes (4096)
#define R4StdConfig_max_output_bytes (4096)
#define R4StdConfig_result_ok (0)
#define R4StdConfig_result_defaulted (1)
#define R4StdConfig_result_created (2)
#define R4StdConfig_result_recovered (3)
#define R4StdConfig_error_invalid_path (-1)
#define R4StdConfig_error_invalid_key (-2)
#define R4StdConfig_error_buffer_too_small (-3)
#define R4StdConfig_error_write_failed (-4)
#define R4StdConfig_error_rename_failed (-5)
#define R4StdConfig_error_invalid_value (-6)
#define R4StdConfig_error_verify_failed (-7)
#define R4StdConfig_error_recovery_failed (-8)
#define R4StdConfig_error_read_failed (-9)
#define R4StdGrapheme_uax29_revision (47)
#define R4StdPathText_component_utf16_units (255)
#define R4StdShortcut_title_max (63)
#define R4StdShortcut_path_max (1023)
#define R4StdShortcut_args_max (127)
#define R4StdShortcut_icon_max (1023)
#define R4StdShortcut_workdir_max (1023)
#define R4StdShortcut_foreign_max (8)
#define R4StdAssociation_max_apps (8)
#define R4StdAssociation_max_extensions (16)
#define R4StdAssociation_app_id_max (15)
#define R4StdAssociation_ext_max (7)
#define R4StdAssociation_title_max (31)
#define R4StdAssociation_path_max (1023)
#define R4StdAssociation_args_max (95)
#define R4StdAssociation_type_name_max (23)
#define R4StdAssociation_short_name_max (11)
#define R4StdAssociation_prefix_max (7)
#define R4StdAssociation_subsystem_id_max (63)
#define R4StdAssociation_format_id_max (63)
#define R4StdAssociation_foreign_max (16)
#define R4StdAssociation_foreign_key_max (79)
#define R4StdAssociation_foreign_value_max (127)
#define R4StdFileHandler_max_choices (24)
#define R4ImgHelpers_max_dimension (4096)
#define R4ImgHelpers_max_pixels (8847360)
#define R4ImgHelpers_max_scratch_bytes (234881024)
#define R4ImgHelpers_max_svg_source_bytes (262144)
#define R4FontHelpers_max_source_bytes (8388608)
#define R4FontHelpers_max_reconstructed_bytes (33554432)
#define R4FontHelpers_max_raster_dimension (512)
#define R4FontHelpers_default_allocation_limit (67108864)
#define R4FontStore_default_cached_glyphs (512)
#define R4FontStore_default_cached_bytes (8388608)
#define R4FontStore_min_pixel_height (4)
#define R4FontStore_max_pixel_height (256)
#define R4FontFormat_VERSION (1)
#define R4FontFormat_HEADER_SIZE (32)
#define R4FontFormat_TABLE_ENTRY_SIZE (16)
#define R4FontFormat_FLAG_HAS_BITMAP (1)
#define R4FontFormat_FLAG_HAS_OUTLINE (2)
#define R4FontFormat_FLAG_HAS_SFNT (4)
#define R4FontFormat_FLAG_HAS_KERNING (8)
#define R4FontFormat_FACE_RECORD_SIZE (64)
#define R4FontFormat_STRIKE_RECORD_SIZE (40)
#define R4FontFormat_GLYPH_MAP_RECORD_SIZE (16)
#define R4FontFormat_GLYPH_METRIC_RECORD_SIZE (24)
#define R4FontFormat_BITMAP_GLYPH_RECORD_SIZE (16)
#define R4FontFormat_KERN_PAIR_RECORD_SIZE (12)
#define R4FontFormat_OUTLINE_RECORD_SIZE (24)
#define R4FontFormat_SFNT_RECORD_SIZE (24)
#define R4FontFormat_TABLE_NAME (1162690894)
#define R4FontFormat_TABLE_FACE (1162035526)
#define R4FontFormat_TABLE_STRIKE (1263686739)
#define R4FontFormat_TABLE_GLYPH_MAP (1346456903)
#define R4FontFormat_TABLE_GLYPH_METRICS (1413827911)
#define R4FontFormat_TABLE_BITMAP_DATA (1413563458)
#define R4FontFormat_TABLE_KERNING (1314014539)
#define R4FontFormat_TABLE_OUTLINE (1280595279)
#define R4FontFormat_TABLE_SFNT (1414415955)
#define R4FontFormat_TABLE_META (1096041805)
#define R4FontFormat_FONT_KIND_BITMAP (1)
#define R4FontFormat_FONT_KIND_WINDOWS_VECTOR (2)
#define R4FontFormat_FONT_KIND_SFNT_TRUETYPE (3)
#define R4FontFormat_STYLE_MONOSPACE (1)
#define R4FontFormat_STYLE_ITALIC (2)
#define R4FontFormat_STYLE_BOLD (4)
#define R4FontFormat_STYLE_UNDERLINE (8)
#define R4FontFormat_STYLE_STRIKEOUT (16)
#define R4FontFormat_CHARSET_CP437 (437)
#define R4FontFormat_CHARSET_WINDOWS_1252 (1252)
#define R4FontFormat_CHARSET_UNICODE (65535)
#define R4FontFormat_CHARSET_FLAG_CP437 (1)
#define R4FontFormat_CHARSET_FLAG_WINDOWS_1252 (2)
#define R4FontFormat_CHARSET_FLAG_UNICODE (4)
#define R4FontFormat_BITMAP_FORMAT_MONO1_MSB (1)
#define R4FontFormat_OUTLINE_KIND_WINDOWS_VECTOR_FNT (1)
#define R4FontFormat_OUTLINE_KIND_TRUETYPE_GLYF (2)
#define R4FontFormat_SFNT_KIND_TRUETYPE (1)
#define R4FontFormat_REQUIRED_SFNT_CMAP (1)
#define R4FontFormat_REQUIRED_SFNT_NAME (2)
#define R4FontFormat_REQUIRED_SFNT_HEAD (4)
#define R4FontFormat_REQUIRED_SFNT_HHEA (8)
#define R4FontFormat_REQUIRED_SFNT_HMTX (16)
#define R4FontFormat_REQUIRED_SFNT_MAXP (32)
#define R4FontFormat_REQUIRED_SFNT_LOCA (64)
#define R4FontFormat_REQUIRED_SFNT_GLYF (128)
#define R4FontFormat_REQUIRED_SFNT_OS2 (256)
#define R4FontFormat_INVALID_GLYPH_ID (65535)
/* R4STD.Bindings.Zig.r4std.init -> bool */
static inline R4LibrariesSlot R4Std_init(uint32_t reserved, const R4XStartContext * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,0u,a,1u,0);
}
/* R4STD.Bindings.Zig.r4std.initialized -> bool */
static inline R4LibrariesSlot R4Std_initialized(uint32_t reserved) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,1u,a,0u,0);
}
/* R4STD.Bindings.Zig.text.textView -> abi_generated.R4TextView */
static inline R4LibrariesSlot R4StdText_textView(uint32_t reserved, const uint8_t * p0, uintptr_t n0, R4TextView *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,2u,a,1u,output);
}
/* R4STD.Bindings.Zig.text.validateUtf8 -> error{BufferTooSmall,EmbeddedNul,InvalidLineEnding,InvalidUiText8,InvalidUtf8,RuntimeUnavailable}!void */
static inline R4LibrariesSlot R4StdText_validateUtf8(uint32_t reserved, const uint8_t * p0, uintptr_t n0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,3u,a,1u,0);
}
/* R4STD.Bindings.Zig.text.validateUiText8 -> error{BufferTooSmall,EmbeddedNul,InvalidLineEnding,InvalidUiText8,InvalidUtf8,RuntimeUnavailable}!void */
static inline R4LibrariesSlot R4StdText_validateUiText8(uint32_t reserved, const uint8_t * p0, uintptr_t n0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,4u,a,1u,0);
}
/* R4STD.Bindings.Zig.settings.parseUtf8Text -> error{BufferTooSmall,EmbeddedNul,InvalidLineEnding,InvalidUiText8,InvalidUtf8,RuntimeUnavailable}!R4STD.Bindings.Zig.text.Utf8Text */
static inline R4LibrariesSlot R4StdSettings_parseUtf8Text(uint32_t reserved, const uint8_t * p0, uintptr_t n0, R4StdTextUtf8Text *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,5u,a,1u,output);
}
/* R4STD.Bindings.Zig.settings.parseSystemText -> error{BufferTooSmall,EmbeddedNul,InvalidLineEnding,InvalidUiText8,InvalidUtf8,RuntimeUnavailable}!R4STD.Bindings.Zig.text.SystemText */
static inline R4LibrariesSlot R4StdSettings_parseSystemText(uint32_t reserved, const uint8_t * p0, uintptr_t n0, R4StdTextSystemText *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,6u,a,1u,output);
}
/* R4STD.Bindings.Zig.settings.canonicalizeSystemText -> error{BufferTooSmall,EmbeddedNul,InvalidLineEnding,InvalidUiText8,InvalidUtf8,RuntimeUnavailable}![]const u8 */
static inline R4LibrariesSlot R4StdSettings_canonicalizeSystemText(uint32_t reserved, const uint8_t * p0, uintptr_t n0, uint8_t * p1, uintptr_t n1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,7u,a,2u,0);
}
/* R4STD.Bindings.Zig.settings.parseDocumentText -> error{BufferTooSmall,EmbeddedNul,InvalidLineEnding,InvalidUiText8,InvalidUtf8,RuntimeUnavailable}!R4STD.Bindings.Zig.text.DocumentText */
static inline R4LibrariesSlot R4StdSettings_parseDocumentText(uint32_t reserved, const uint8_t * p0, uintptr_t n0, R4StdTextDocumentText *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,8u,a,1u,output);
}
/* R4STD.Bindings.Zig.settings.parseUiText8 -> error{BufferTooSmall,EmbeddedNul,InvalidLineEnding,InvalidUiText8,InvalidUtf8,RuntimeUnavailable}!R4STD.Bindings.Zig.text.UiText8 */
static inline R4LibrariesSlot R4StdSettings_parseUiText8(uint32_t reserved, const uint8_t * p0, uintptr_t n0, R4StdTextUiText8 *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,9u,a,1u,output);
}
/* R4STD.Bindings.Zig.settings.ticksFromMilliseconds -> u64 */
static inline R4LibrariesSlot R4StdSettings_ticksFromMilliseconds(uint32_t reserved, uint32_t p0, uint32_t p1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,10u,a,2u,0);
}
/* R4STD.Bindings.Zig.settings.valueOf -> ?[]const u8 */
static inline R4LibrariesSlot R4StdSettings_valueOf(uint32_t reserved, const uint8_t * p0, uintptr_t n0, const uint8_t * p1, uintptr_t n1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,11u,a,2u,0);
}
/* R4STD.Bindings.Zig.settings.parseLine -> ?R4STD.Bindings.Zig.settings.Entry */
static inline R4LibrariesSlot R4StdSettings_parseLine(uint32_t reserved, const uint8_t * p0, uintptr_t n0, R4StdSettingsEntry *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,12u,a,1u,output);
}
/* R4STD.Bindings.Zig.settings.parseBool -> ?bool */
static inline R4LibrariesSlot R4StdSettings_parseBool(uint32_t reserved, const uint8_t * p0, uintptr_t n0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,13u,a,1u,0);
}
/* R4STD.Bindings.Zig.settings.parseU32 -> ?u32 */
static inline R4LibrariesSlot R4StdSettings_parseU32(uint32_t reserved, const uint8_t * p0, uintptr_t n0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,14u,a,1u,0);
}
/* R4STD.Bindings.Zig.settings.parseI32 -> ?i32 */
static inline R4LibrariesSlot R4StdSettings_parseI32(uint32_t reserved, const uint8_t * p0, uintptr_t n0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,15u,a,1u,0);
}
/* R4STD.Bindings.Zig.settings.parseRgb24 -> ?u32 */
static inline R4LibrariesSlot R4StdSettings_parseRgb24(uint32_t reserved, const uint8_t * p0, uintptr_t n0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,16u,a,1u,0);
}
/* R4STD.Bindings.Zig.settings.equalsKey -> bool */
static inline R4LibrariesSlot R4StdSettings_equalsKey(uint32_t reserved, const uint8_t * p0, uintptr_t n0, const uint8_t * p1, uintptr_t n1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,17u,a,2u,0);
}
/* R4STD.Bindings.Zig.settings.validKey -> bool */
static inline R4LibrariesSlot R4StdSettings_validKey(uint32_t reserved, const uint8_t * p0, uintptr_t n0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,18u,a,1u,0);
}
/* R4STD.Bindings.Zig.settings.trim -> []const u8 */
static inline R4LibrariesSlot R4StdSettings_trim(uint32_t reserved, const uint8_t * p0, uintptr_t n0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,19u,a,1u,0);
}
/* R4STD.Bindings.Zig.date.daysInMonth -> u8 */
static inline R4LibrariesSlot R4StdDate_daysInMonth(uint32_t reserved, uint16_t p0, uint8_t p1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,20u,a,2u,0);
}
/* R4STD.Bindings.Zig.date.validDateValue -> bool */
static inline R4LibrariesSlot R4StdDate_validDateValue(uint32_t reserved, uint16_t p0, uint8_t p1, uint8_t p2) {
 (void)reserved; R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,21u,a,3u,0);
}
/* R4STD.Bindings.Zig.date.validDate -> bool */
static inline R4LibrariesSlot R4StdDate_validDate(uint32_t reserved, const R4StdDateDate * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,22u,a,1u,0);
}
/* R4STD.Bindings.Zig.date.validDateTime -> bool */
static inline R4LibrariesSlot R4StdDate_validDateTime(uint32_t reserved, const R4StdDateDateTime * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,23u,a,1u,0);
}
/* R4STD.Bindings.Zig.date.compareDate -> i32 */
static inline R4LibrariesSlot R4StdDate_compareDate(uint32_t reserved, const R4StdDateDate * p0, const R4StdDateDate * p1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,24u,a,2u,0);
}
/* R4STD.Bindings.Zig.date.compareDateTime -> i32 */
static inline R4LibrariesSlot R4StdDate_compareDateTime(uint32_t reserved, const R4StdDateDateTime * p0, const R4StdDateDateTime * p1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,25u,a,2u,0);
}
/* R4STD.Bindings.Zig.date.weekday -> ?R4STD.Bindings.Zig.date.Weekday */
static inline R4LibrariesSlot R4StdDate_weekday(uint32_t reserved, const R4StdDateDate * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,26u,a,1u,0);
}
/* R4STD.Bindings.Zig.date.weekdayNumber -> u8 */
static inline R4LibrariesSlot R4StdDate_weekdayNumber(uint32_t reserved, uint16_t p0, uint8_t p1, uint8_t p2) {
 (void)reserved; R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,27u,a,3u,0);
}
/* R4STD.Bindings.Zig.date.shiftMinutes -> ?R4STD.Bindings.Zig.date.ShiftedDateTime */
static inline R4LibrariesSlot R4StdDate_shiftMinutes(uint32_t reserved, const R4StdDateDateTime * p0, int32_t p1, R4StdDateShiftedDateTime *output) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,28u,a,2u,output);
}
/* R4STD.Bindings.Zig.date.fromTimeState -> ?R4STD.Bindings.Zig.date.DateTime */
static inline R4LibrariesSlot R4StdDate_fromTimeState(uint32_t reserved, const R4TimeState * p0, R4StdDateDateTime *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,29u,a,1u,output);
}
/* R4STD.Bindings.Zig.date.toTimeState -> ?abi_generated.TimeState */
static inline R4LibrariesSlot R4StdDate_toTimeState(uint32_t reserved, const R4StdDateDateTime * p0, R4TimeState *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,30u,a,1u,output);
}
/* R4STD.Bindings.Zig.date.utcFromDateTime -> ?abi_generated.R4UtcTime */
static inline R4LibrariesSlot R4StdDate_utcFromDateTime(uint32_t reserved, const R4StdDateDateTime * p0, uint32_t p1, R4UtcTime *output) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,31u,a,2u,output);
}
/* R4STD.Bindings.Zig.date.dateTimeFromUtc -> ?R4STD.Bindings.Zig.date.DateTime */
static inline R4LibrariesSlot R4StdDate_dateTimeFromUtc(uint32_t reserved, const R4UtcTime * p0, R4StdDateDateTime *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,32u,a,1u,output);
}
/* R4STD.Bindings.Zig.date.formatDateIso -> []const u8 */
static inline R4LibrariesSlot R4StdDate_formatDateIso(uint32_t reserved, uint8_t * p0, uintptr_t n0, const R4StdDateDate * p1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,33u,a,2u,0);
}
/* R4STD.Bindings.Zig.date.formatDateTimeIso -> []const u8 */
static inline R4LibrariesSlot R4StdDate_formatDateTimeIso(uint32_t reserved, uint8_t * p0, uintptr_t n0, const R4StdDateDateTime * p1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,34u,a,2u,0);
}
/* R4STD.Bindings.Zig.date.formatDateTimeMinuteDisplay -> []const u8 */
static inline R4LibrariesSlot R4StdDate_formatDateTimeMinuteDisplay(uint32_t reserved, uint8_t * p0, uintptr_t n0, const R4StdDateDateTime * p1, uint32_t p2) {
 (void)reserved; R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,35u,a,3u,0);
}
/* R4STD.Bindings.Zig.date.parseDateIso -> ?R4STD.Bindings.Zig.date.Date */
static inline R4LibrariesSlot R4StdDate_parseDateIso(uint32_t reserved, const uint8_t * p0, uintptr_t n0, R4StdDateDate *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,36u,a,1u,output);
}
/* R4STD.Bindings.Zig.date.parseTime24 -> ?R4STD.Bindings.Zig.date.TimeOfDay */
static inline R4LibrariesSlot R4StdDate_parseTime24(uint32_t reserved, const uint8_t * p0, uintptr_t n0, R4StdDateTimeOfDay *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,37u,a,1u,output);
}
/* R4STD.Bindings.Zig.date.parseDateTimeIso -> ?R4STD.Bindings.Zig.date.DateTime */
static inline R4LibrariesSlot R4StdDate_parseDateTimeIso(uint32_t reserved, const uint8_t * p0, uintptr_t n0, R4StdDateDateTime *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,38u,a,1u,output);
}
/* R4STD.Bindings.Zig.date.decodeFatDate -> ?R4STD.Bindings.Zig.date.Date */
static inline R4LibrariesSlot R4StdDate_decodeFatDate(uint32_t reserved, uint16_t p0, R4StdDateDate *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,39u,a,1u,output);
}
/* R4STD.Bindings.Zig.date.decodeFatDateTime -> ?R4STD.Bindings.Zig.date.DateTime */
static inline R4LibrariesSlot R4StdDate_decodeFatDateTime(uint32_t reserved, uint16_t p0, uint16_t p1, R4StdDateDateTime *output) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,40u,a,2u,output);
}
/* R4STD.Bindings.Zig.date.toAbi -> R4STD.Bindings.Zig.r4std_abi.R4StdDateTime */
static inline R4LibrariesSlot R4StdDate_toAbi(uint32_t reserved, const R4StdDateDateTime * p0, R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdDateTime *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,41u,a,1u,output);
}
/* R4STD.Bindings.Zig.date.fromAbi -> R4STD.Bindings.Zig.date.DateTime */
static inline R4LibrariesSlot R4StdDate_fromAbi(uint32_t reserved, const R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdDateTime * p0, R4StdDateDateTime *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,42u,a,1u,output);
}
/* R4STD.Bindings.Zig.date.stateToAbi -> R4STD.Bindings.Zig.r4std_abi.R4StdTimeState */
static inline R4LibrariesSlot R4StdDate_stateToAbi(uint32_t reserved, const R4TimeState * p0, R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdTimeState *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,43u,a,1u,output);
}
/* R4STD.Bindings.Zig.date.stateFromAbi -> abi_generated.TimeState */
static inline R4LibrariesSlot R4StdDate_stateFromAbi(uint32_t reserved, const R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdTimeState * p0, R4TimeState *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,44u,a,1u,output);
}
/* R4STD.Bindings.Zig.time.zoneCount -> usize */
static inline R4LibrariesSlot R4StdTime_zoneCount(uint32_t reserved) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,45u,a,0u,0);
}
/* R4STD.Bindings.Zig.time.copyZoneId -> []const u8 */
static inline R4LibrariesSlot R4StdTime_copyZoneId(uint32_t reserved, uint8_t * p0, uintptr_t n0, uint64_t p1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,46u,a,2u,0);
}
/* R4STD.Bindings.Zig.time.copyZoneLabelForState -> []const u8 */
static inline R4LibrariesSlot R4StdTime_copyZoneLabelForState(uint32_t reserved, uint8_t * p0, uintptr_t n0, uint64_t p1, const R4TimeState * p2) {
 (void)reserved; R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,47u,a,3u,0);
}
/* R4STD.Bindings.Zig.time.indexForId -> ?usize */
static inline R4LibrariesSlot R4StdTime_indexForId(uint32_t reserved, const uint8_t * p0, uintptr_t n0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,48u,a,1u,0);
}
/* R4STD.Bindings.Zig.time.offsetAtState -> i16 */
static inline R4LibrariesSlot R4StdTime_offsetAtState(uint32_t reserved, uint64_t p0, const R4TimeState * p1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,49u,a,2u,0);
}
/* R4STD.Bindings.Zig.time.standardOffsetAt -> i16 */
static inline R4LibrariesSlot R4StdTime_standardOffsetAt(uint32_t reserved, uint64_t p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,50u,a,1u,0);
}
/* R4STD.Bindings.Zig.time.secondsInZone -> u32 */
static inline R4LibrariesSlot R4StdTime_secondsInZone(uint32_t reserved, uint32_t p0, int16_t p1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,51u,a,2u,0);
}
/* R4STD.Bindings.Zig.time.splitTime -> R4STD.Bindings.Zig.time.ClockTime */
static inline R4LibrariesSlot R4StdTime_splitTime(uint32_t reserved, uint32_t p0, R4StdTimeClockTime *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,52u,a,1u,output);
}
/* R4STD.Bindings.Zig.time.localDateTimeAtState -> ?R4STD.Bindings.Zig.date.DateTime */
static inline R4LibrariesSlot R4StdTime_localDateTimeAtState(uint32_t reserved, uint64_t p0, const R4TimeState * p1, R4StdDateDateTime *output) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,53u,a,2u,output);
}
/* R4STD.Bindings.Zig.time.localDateTimeForConfig -> ?R4STD.Bindings.Zig.date.DateTime */
static inline R4LibrariesSlot R4StdTime_localDateTimeForConfig(uint32_t reserved, const R4StdTimeHelpersConfig * p0, const R4TimeState * p1, R4StdDateDateTime *output) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,54u,a,2u,output);
}
/* R4STD.Bindings.Zig.time.formatDisplay -> []const u8 */
static inline R4LibrariesSlot R4StdTime_formatDisplay(uint32_t reserved, uint8_t * p0, uintptr_t n0, const R4StdTimeClockTime * p1, uint32_t p2) {
 (void)reserved; R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,55u,a,3u,0);
}
/* R4STD.Bindings.Zig.time.formatHmDisplay -> []const u8 */
static inline R4LibrariesSlot R4StdTime_formatHmDisplay(uint32_t reserved, uint8_t * p0, uintptr_t n0, const R4StdTimeClockTime * p1, uint32_t p2) {
 (void)reserved; R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,56u,a,3u,0);
}
/* R4STD.Bindings.Zig.time.formatHms -> []const u8 */
static inline R4LibrariesSlot R4StdTime_formatHms(uint32_t reserved, uint8_t * p0, uintptr_t n0, const R4StdTimeClockTime * p1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,57u,a,2u,0);
}
/* R4STD.Bindings.Zig.time.formatOffset -> []const u8 */
static inline R4LibrariesSlot R4StdTime_formatOffset(uint32_t reserved, uint8_t * p0, uintptr_t n0, int16_t p1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,58u,a,2u,0);
}
/* R4STD.Bindings.Zig.config.ok -> bool */
static inline R4LibrariesSlot R4StdConfig_ok(uint32_t reserved, int32_t p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,59u,a,1u,0);
}
/* R4STD.Bindings.Zig.config.parseFilePath -> error{ComponentTooLong,EmbeddedNul,Empty,ExpectedAbsolute,ExpectedRelative,InvalidCharacter,RootTraversal,TooLong}!r4os.path.FilePath */
static inline R4LibrariesSlot R4StdConfig_parseFilePath(uint32_t reserved, const uint8_t * p0, uintptr_t n0, R4Lib_r4os_path_FilePath *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,60u,a,1u,output);
}
/* R4STD.Bindings.Zig.config.parseAbsoluteFilePath -> error{ComponentTooLong,EmbeddedNul,Empty,ExpectedAbsolute,ExpectedRelative,InvalidCharacter,RootTraversal,TooLong}!r4os.path.AbsoluteFilePath */
static inline R4LibrariesSlot R4StdConfig_parseAbsoluteFilePath(uint32_t reserved, const uint8_t * p0, uintptr_t n0, R4Lib_r4os_path_AbsoluteFilePath *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,61u,a,1u,output);
}
/* R4STD.Bindings.Zig.config.parseRelativeFilePath -> error{ComponentTooLong,EmbeddedNul,Empty,ExpectedAbsolute,ExpectedRelative,InvalidCharacter,RootTraversal,TooLong}!r4os.path.RelativeFilePath */
static inline R4LibrariesSlot R4StdConfig_parseRelativeFilePath(uint32_t reserved, const uint8_t * p0, uintptr_t n0, R4Lib_r4os_path_RelativeFilePath *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,62u,a,1u,output);
}
/* R4STD.Bindings.Zig.config.parseRegistryPath -> error{ComponentTooLong,EmbeddedNul,Empty,ExpectedAbsolute,ExpectedRelative,InvalidCharacter,RootTraversal,TooLong}!r4os.path.RegistryPath */
static inline R4LibrariesSlot R4StdConfig_parseRegistryPath(uint32_t reserved, const uint8_t * p0, uintptr_t n0, R4Lib_r4os_path_RegistryPath *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,63u,a,1u,output);
}
/* R4STD.Bindings.Zig.config.pathsEqualIgnoreCase -> bool */
static inline R4LibrariesSlot R4StdConfig_pathsEqualIgnoreCase(uint32_t reserved, const uint8_t * p0, uintptr_t n0, const uint8_t * p1, uintptr_t n1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,64u,a,2u,0);
}
/* R4STD.Bindings.Zig.codec.legacyDecode -> error{BufferTooSmall,InvalidArgument,InvalidScalar,InvalidUtf8,RangesOverlap,RuntimeUnavailable,UndefinedByte,Unrepresentable}!u32 */
static inline R4LibrariesSlot R4StdCodec_legacyDecode(uint32_t reserved, uint32_t p0, uint32_t p1, uint8_t p2) {
 (void)reserved; R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,65u,a,3u,0);
}
/* R4STD.Bindings.Zig.codec.legacyEncode -> error{BufferTooSmall,InvalidArgument,InvalidScalar,InvalidUtf8,RangesOverlap,RuntimeUnavailable,UndefinedByte,Unrepresentable}!u8 */
static inline R4LibrariesSlot R4StdCodec_legacyEncode(uint32_t reserved, uint32_t p0, uint32_t p1, uint32_t p2) {
 (void)reserved; R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,66u,a,3u,0);
}
/* R4STD.Bindings.Zig.codec.decode -> error{BufferTooSmall,InvalidArgument,InvalidScalar,InvalidUtf8,RangesOverlap,RuntimeUnavailable,UndefinedByte,Unrepresentable}!R4STD.Bindings.Zig.codec.Decoded */
static inline R4LibrariesSlot R4StdCodec_decode(uint32_t reserved, const uint8_t * p0, uintptr_t n0, R4StdCodecDecoded *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,67u,a,1u,output);
}
/* R4STD.Bindings.Zig.codec.encode -> error{BufferTooSmall,InvalidArgument,InvalidScalar,InvalidUtf8,RangesOverlap,RuntimeUnavailable,UndefinedByte,Unrepresentable}![]const u8 */
static inline R4LibrariesSlot R4StdCodec_encode(uint32_t reserved, uint32_t p0, uint8_t * p1, uintptr_t n1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,68u,a,2u,0);
}
/* R4STD.Bindings.Zig.codec.legacyToUtf8 -> error{BufferTooSmall,InvalidArgument,InvalidScalar,InvalidUtf8,RangesOverlap,RuntimeUnavailable,UndefinedByte,Unrepresentable}![]const u8 */
static inline R4LibrariesSlot R4StdCodec_legacyToUtf8(uint32_t reserved, uint32_t p0, uint32_t p1, const uint8_t * p2, uintptr_t n2, uint8_t * p3, uintptr_t n3) {
 (void)reserved; R4LibrariesSlot a[4]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.length=n2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.ptr=(void *)p3,.length=n3,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,69u,a,4u,0);
}
/* R4STD.Bindings.Zig.codec.utf8ToLegacy -> error{BufferTooSmall,InvalidArgument,InvalidScalar,InvalidUtf8,RangesOverlap,RuntimeUnavailable,UndefinedByte,Unrepresentable}![]const u8 */
static inline R4LibrariesSlot R4StdCodec_utf8ToLegacy(uint32_t reserved, uint32_t p0, uint32_t p1, const uint8_t * p2, uintptr_t n2, uint8_t * p3, uintptr_t n3) {
 (void)reserved; R4LibrariesSlot a[4]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.length=n2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.ptr=(void *)p3,.length=n3,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,70u,a,4u,0);
}
/* R4STD.Bindings.Zig.codec.scalarCount -> error{BufferTooSmall,InvalidArgument,InvalidScalar,InvalidUtf8,RangesOverlap,RuntimeUnavailable,UndefinedByte,Unrepresentable}!usize */
static inline R4LibrariesSlot R4StdCodec_scalarCount(uint32_t reserved, const uint8_t * p0, uintptr_t n0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,71u,a,1u,0);
}
/* R4STD.Bindings.Zig.grapheme.valid -> bool */
static inline R4LibrariesSlot R4StdGrapheme_valid(uint32_t reserved, const uint8_t * p0, uintptr_t n0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,72u,a,1u,0);
}
/* R4STD.Bindings.Zig.grapheme.prefix -> error{Incomplete,InvalidUtf8}!usize */
static inline R4LibrariesSlot R4StdGrapheme_prefix(uint32_t reserved, const uint8_t * p0, uintptr_t n0, uint64_t p1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,73u,a,2u,0);
}
/* R4STD.Bindings.Zig.grapheme.floor -> error{Incomplete,InvalidUtf8}!usize */
static inline R4LibrariesSlot R4StdGrapheme_floor(uint32_t reserved, const uint8_t * p0, uintptr_t n0, uint64_t p1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,74u,a,2u,0);
}
/* R4STD.Bindings.Zig.grapheme.ceil -> error{Incomplete,InvalidUtf8}!usize */
static inline R4LibrariesSlot R4StdGrapheme_ceil(uint32_t reserved, const uint8_t * p0, uintptr_t n0, uint64_t p1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,75u,a,2u,0);
}
/* R4STD.Bindings.Zig.grapheme.previous -> error{Incomplete,InvalidUtf8}!usize */
static inline R4LibrariesSlot R4StdGrapheme_previous(uint32_t reserved, const uint8_t * p0, uintptr_t n0, uint64_t p1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,76u,a,2u,0);
}
/* R4STD.Bindings.Zig.grapheme.next -> error{Incomplete,InvalidUtf8}!usize */
static inline R4LibrariesSlot R4StdGrapheme_next(uint32_t reserved, const uint8_t * p0, uintptr_t n0, uint64_t p1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,77u,a,2u,0);
}
/* R4STD.Bindings.Zig.path_text.validText -> bool */
static inline R4LibrariesSlot R4StdPathText_validText(uint32_t reserved, const uint8_t * p0, uintptr_t n0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,78u,a,1u,0);
}
/* R4STD.Bindings.Zig.path_text.valid -> bool */
static inline R4LibrariesSlot R4StdPathText_valid(uint32_t reserved, const uint8_t * p0, uintptr_t n0, uint64_t p1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,79u,a,2u,0);
}
/* R4STD.Bindings.Zig.path_text.validComponent -> bool */
static inline R4LibrariesSlot R4StdPathText_validComponent(uint32_t reserved, const uint8_t * p0, uintptr_t n0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,80u,a,1u,0);
}
/* R4STD.Bindings.Zig.console_text.decode -> error{Incomplete,InvalidUtf8}!R4STD.Bindings.Zig.console_text.Scalar */
static inline R4LibrariesSlot R4StdConsoleText_decode(uint32_t reserved, const uint8_t * p0, uintptr_t n0, R4StdConsoleTextScalar *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,81u,a,1u,output);
}
/* R4STD.Bindings.Zig.console_text.completePrefix -> usize */
static inline R4LibrariesSlot R4StdConsoleText_completePrefix(uint32_t reserved, const uint8_t * p0, uintptr_t n0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,82u,a,1u,0);
}
/* R4STD.Bindings.Zig.console_text.printable -> bool */
static inline R4LibrariesSlot R4StdConsoleText_printable(uint32_t reserved, uint32_t p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,83u,a,1u,0);
}
/* R4STD.Bindings.Zig.console_text.cells -> usize */
static inline R4LibrariesSlot R4StdConsoleText_cells(uint32_t reserved, const uint8_t * p0, uintptr_t n0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,84u,a,1u,0);
}
/* R4STD.Bindings.Zig.shortcut.parse -> error{ArgsTooLong,BufferTooSmall,DuplicateField,IconTooLong,InvalidPolicy,InvalidTarget,InvalidText,MissingFormat,MissingSchema,MissingTarget,TargetTooLong,TitleTooLong,UnknownField,UnsupportedFormat,WorkdirTooLong,WrongSchema}!R4STD.Bindings.Zig.shortcut.Shortcut */
static inline R4LibrariesSlot R4StdShortcut_parse(uint32_t reserved, const uint8_t * p0, uintptr_t n0, R4StdShortcutShortcut *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,85u,a,1u,output);
}
/* R4STD.Bindings.Zig.shortcut.inferTargetKind -> R4STD.Bindings.Zig.shortcut.TargetKind */
static inline R4LibrariesSlot R4StdShortcut_inferTargetKind(uint32_t reserved, const uint8_t * p0, uintptr_t n0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,86u,a,1u,0);
}
/* R4STD.Bindings.Zig.shortcut.parsePolicy -> ?abi.LaunchPolicy */
static inline R4LibrariesSlot R4StdShortcut_parsePolicy(uint32_t reserved, const uint8_t * p0, uintptr_t n0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,87u,a,1u,0);
}
/* R4STD.Bindings.Zig.shortcut.policyText -> []const u8 */
static inline R4LibrariesSlot R4StdShortcut_policyText(uint32_t reserved, uint32_t p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,88u,a,1u,0);
}
/* R4STD.Bindings.Zig.app_assoc.expandArgs -> ?[]const u8 */
static inline R4LibrariesSlot R4StdAssociation_expandArgs(uint32_t reserved, const uint8_t * p0, uintptr_t n0, const uint8_t * p1, uintptr_t n1, uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.length=n2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,89u,a,3u,0);
}
/* R4STD.Bindings.Zig.app_assoc.extensionOfPath -> ?[]const u8 */
static inline R4LibrariesSlot R4StdAssociation_extensionOfPath(uint32_t reserved, const uint8_t * p0, uintptr_t n0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,90u,a,1u,0);
}
/* R4STD.Bindings.Zig.app_assoc.isR4XPath -> bool */
static inline R4LibrariesSlot R4StdAssociation_isR4XPath(uint32_t reserved, const uint8_t * p0, uintptr_t n0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,91u,a,1u,0);
}
/* R4STD.Bindings.Zig.file_handler.resolve -> error{BufferTooSmall,DuplicateGuest,InvalidAssociation,InvalidGuestPath,InvalidInput,InvalidKey,InvalidMagic,InvalidValue,MalformedRecord,MissingGuest,StaleAssociation,TooManyCandidates,TooManyChoices,TooManyOptions}!void */
static inline R4LibrariesSlot R4StdFileHandler_resolve(uint32_t reserved, const R4StdAssociationConfig * p0, const R4Lib_r4os_subsystem_catalog_Catalog * p1, const R4Lib_r4os_subsystem_catalog_Input * p2, uint8_t * p3, uintptr_t n3, R4StdFileHandlerResolution * p4) {
 (void)reserved; R4LibrariesSlot a[5]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.ptr=(void *)p3,.length=n3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.ptr=(void *)p4,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,92u,a,5u,0);
}
/* R4STD.Bindings.Zig.file_handler.collectChoices -> error{BufferTooSmall,DuplicateGuest,InvalidAssociation,InvalidGuestPath,InvalidInput,InvalidKey,InvalidMagic,InvalidValue,MalformedRecord,MissingGuest,StaleAssociation,TooManyCandidates,TooManyChoices,TooManyOptions}!void */
static inline R4LibrariesSlot R4StdFileHandler_collectChoices(uint32_t reserved, const R4StdAssociationConfig * p0, const R4Lib_r4os_subsystem_catalog_Catalog * p1, const R4Lib_r4os_subsystem_catalog_Input * p2, R4StdFileHandlerChoiceList * p3) {
 (void)reserved; R4LibrariesSlot a[4]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.ptr=(void *)p3,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,93u,a,4u,0);
}
/* R4STD.Bindings.Zig.file_handler.collectExtensionChoices -> error{BufferTooSmall,DuplicateGuest,InvalidAssociation,InvalidGuestPath,InvalidInput,InvalidKey,InvalidMagic,InvalidValue,MalformedRecord,MissingGuest,StaleAssociation,TooManyCandidates,TooManyChoices,TooManyOptions}!void */
static inline R4LibrariesSlot R4StdFileHandler_collectExtensionChoices(uint32_t reserved, const R4StdAssociationConfig * p0, const R4Lib_r4os_subsystem_catalog_Catalog * p1, const uint8_t * p2, uintptr_t n2, R4StdFileHandlerChoiceList * p3) {
 (void)reserved; R4LibrariesSlot a[4]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.length=n2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.ptr=(void *)p3,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,94u,a,4u,0);
}
/* R4STD.Bindings.Zig.file_handler.targetForChoice -> error{BufferTooSmall,DuplicateGuest,InvalidAssociation,InvalidGuestPath,InvalidInput,InvalidKey,InvalidMagic,InvalidValue,MalformedRecord,MissingGuest,StaleAssociation,TooManyCandidates,TooManyChoices,TooManyOptions}!R4STD.Bindings.Zig.file_handler.Target */
static inline R4LibrariesSlot R4StdFileHandler_targetForChoice(uint32_t reserved, const R4StdFileHandlerChoice * p0, const uint8_t * p1, uintptr_t n1, uint8_t * p2, uintptr_t n2, R4StdFileHandlerTarget *output) {
 (void)reserved; R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.length=n2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,95u,a,3u,output);
}
/* R4STD.Bindings.Zig.subsystem_runtime.status -> R4STD.Bindings.Zig.subsystem_runtime.LoadStatus */
static inline R4LibrariesSlot R4StdSubsystem_status(uint32_t reserved) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,96u,a,0u,0);
}
/* R4STD.Bindings.Zig.subsystem_runtime.catalog -> *const r4os.subsystem_catalog.Catalog */
static inline R4LibrariesSlot R4StdSubsystem_catalog(uint32_t reserved) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,97u,a,0u,0);
}
/* R4IMG.Bindings.Zig.color.Decoder(R4GFX.Bindings.Zig.r4gfx_abi).characterize -> error{ColorTransform,InvalidColor,ProfileLimit,UnsupportedColor}!R4IMG.Bindings.Zig.color.Decoder(R4GFX.Bindings.Zig.r4gfx_abi).Characterization */
static inline R4LibrariesSlot R4ImgColor_characterize(uint32_t reserved, const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor * p0, const R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Policy * p1, R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Characterization *output) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,98u,a,2u,output);
}
/* R4IMG.Bindings.Zig.color.Decoder(R4GFX.Bindings.Zig.r4gfx_abi).characterizeRaster -> error{ColorTransform,InvalidColor,ProfileLimit,UnsupportedColor}!R4IMG.Bindings.Zig.color.Decoder(R4GFX.Bindings.Zig.r4gfx_abi).Characterization */
static inline R4LibrariesSlot R4ImgColor_characterizeRaster(uint32_t reserved, const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor * p0, const R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Policy * p1, R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Characterization *output) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,99u,a,2u,output);
}
/* R4IMG.Bindings.Zig.color.Decoder(R4GFX.Bindings.Zig.r4gfx_abi).decode -> @typeInfo(@typeInfo(@TypeOf(R4IMG.Bindings.Zig.color.Decoder(R4GFX.Bindings.Zig.r4gfx_abi).decode)).@"fn".return_type.?).error_union.error_set!R4IMG.Bindings.Zig.color.Decoder(R4GFX.Bindings.Zig.r4gfx_abi).Result */
static inline R4LibrariesSlot R4ImgColor_decode(uint32_t reserved, const R4LibraryAllocator * p0, const R4ImgHelpersContext * p1, const R4ImgHelpersPngContext * p2, const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_ColorV1Client * p3, const uint8_t * p4, uintptr_t n4, const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorImage * p5, const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorTransform * p6, const R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Policy * p7, R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Result *output) {
 (void)reserved; R4LibrariesSlot a[8]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.ptr=(void *)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.ptr=(void *)p4,.length=n4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.ptr=(void *)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.ptr=(void *)p6,.flags=R4LIBRARIES_PRESENT};
 a[7] = (R4LibrariesSlot){.ptr=(void *)p7,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,100u,a,8u,output);
}
/* R4IMG.Bindings.Zig.color.Decoder(R4GFX.Bindings.Zig.r4gfx_abi).decodeRaster -> @typeInfo(@typeInfo(@TypeOf(R4IMG.Bindings.Zig.color.Decoder(R4GFX.Bindings.Zig.r4gfx_abi).decodeRaster)).@"fn".return_type.?).error_union.error_set!R4IMG.Bindings.Zig.color.Decoder(R4GFX.Bindings.Zig.r4gfx_abi).RasterResult */
static inline R4LibrariesSlot R4ImgColor_decodeRaster(uint32_t reserved, const R4LibraryAllocator * p0, const R4ImgHelpersContext * p1, const R4ImgHelpersRasterContext * p2, const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_ColorV1Client * p3, const uint8_t * p4, uintptr_t n4, const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorImage * p5, const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorTransform * p6, const R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Policy * p7, R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__RasterResult *output) {
 (void)reserved; R4LibrariesSlot a[8]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.ptr=(void *)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.ptr=(void *)p4,.length=n4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.ptr=(void *)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.ptr=(void *)p6,.flags=R4LIBRARIES_PRESENT};
 a[7] = (R4LibrariesSlot){.ptr=(void *)p7,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,101u,a,8u,output);
}
/* R4IMG.Bindings.Zig.native_jpeg.Consumer(R4VIDEO.Bindings.Zig.r4video).capabilities -> i32 */
static inline R4LibrariesSlot R4ImgNativeJpeg_capabilities(uint32_t reserved, const R4Lib_R4VIDEO_Bindings_Zig_r4video_VideoV1Client * p0, const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoRuntime * p1, uint32_t p2, const uint8_t * p3, uintptr_t n3, R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps * p4) {
 (void)reserved; R4LibrariesSlot a[5]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.ptr=(void *)p3,.length=n3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.ptr=(void *)p4,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,102u,a,5u,0);
}
/* R4IMG.Bindings.Zig.native_jpeg.Consumer(R4VIDEO.Bindings.Zig.r4video).start -> i32 */
static inline R4LibrariesSlot R4ImgNativeJpeg_start(uint32_t reserved, const R4Lib_R4VIDEO_Bindings_Zig_r4video_VideoV1Client * p0, const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoRuntime * p1, uint32_t p2, const uint8_t * p3, uintptr_t n3, uint64_t p4, R4ImgNativeJpeg * p5) {
 (void)reserved; R4LibrariesSlot a[6]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.ptr=(void *)p3,.length=n3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.ptr=(void *)p5,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,103u,a,6u,0);
}
/* R4IMG.Bindings.Zig.native_jpeg.Consumer(R4VIDEO.Bindings.Zig.r4video).advance -> i32 */
static inline R4LibrariesSlot R4ImgNativeJpeg_advance(uint32_t reserved, R4ImgNativeJpeg * p0, R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame * p1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,104u,a,2u,0);
}
/* R4IMG.Bindings.Zig.native_jpeg.Consumer(R4VIDEO.Bindings.Zig.r4video).release -> i32 */
static inline R4LibrariesSlot R4ImgNativeJpeg_release(uint32_t reserved, R4ImgNativeJpeg * p0, const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoReceipt * p1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,105u,a,2u,0);
}
/* R4IMG.Bindings.Zig.native_jpeg.Consumer(R4VIDEO.Bindings.Zig.r4video).close -> i32 */
static inline R4LibrariesSlot R4ImgNativeJpeg_close(uint32_t reserved, R4ImgNativeJpeg * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,106u,a,1u,0);
}
/* R4IMG.Bindings.Zig.native_jpeg.dimensions -> error{Unsupported}!R4IMG.Bindings.Zig.native_jpeg.Dimensions */
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_native_jpeg_dimensions(uint32_t reserved, const uint8_t * p0, uintptr_t n0, R4Lib_R4IMG_Bindings_Zig_native_jpeg_Dimensions *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,107u,a,1u,output);
}
/* R4FONT.Bindings.Zig.font_import.faceCount -> usize */
static inline R4LibrariesSlot R4FontImport_faceCount(uint32_t reserved, const uint8_t * p0, uintptr_t n0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,108u,a,1u,0);
}
/* R4FONT.Bindings.Zig.font_import.inspect -> @typeInfo(@typeInfo(@TypeOf(R4FONT.Bindings.Zig.font_import.inspect)).@"fn".return_type.?).error_union.error_set!R4FONT.Bindings.Zig.font_import.FaceInfo */
static inline R4LibrariesSlot R4FontImport_inspect(uint32_t reserved, const uint8_t * p0, uintptr_t n0, uint64_t p1, R4FontImportFaceInfo *output) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,109u,a,2u,output);
}
/* R4FONT.Bindings.Zig.font_import.convert -> @typeInfo(@typeInfo(@TypeOf(R4FONT.Bindings.Zig.font_import.convert)).@"fn".return_type.?).error_union.error_set![]u8 */
static inline R4LibrariesSlot R4FontImport_convert(uint32_t reserved, const R4LibraryAllocator * p0, const uint8_t * p1, uintptr_t n1, const uint8_t * p2, uintptr_t n2, uint64_t p3) {
 (void)reserved; R4LibrariesSlot a[4]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.length=n2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,110u,a,4u,0);
}
/* R4FONT.Bindings.Zig.font_import.rasterizePreview -> @typeInfo(@typeInfo(@TypeOf(R4FONT.Bindings.Zig.font_import.rasterizePreview)).@"fn".return_type.?).error_union.error_set!R4FONT.Bindings.Zig.font_import.Preview */
static inline R4LibrariesSlot R4FontImport_rasterizePreview(uint32_t reserved, const R4LibraryAllocator * p0, const uint8_t * p1, uintptr_t n1, uint64_t p2, const uint8_t * p3, uintptr_t n3, uint32_t * p4, uintptr_t n4, uint16_t p5, uint16_t p6, R4FontImportPreview *output) {
 (void)reserved; R4LibrariesSlot a[7]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.ptr=(void *)p3,.length=n3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.ptr=(void *)p4,.length=n4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,111u,a,7u,output);
}
/* R4FONT.Bindings.Zig.font_format.validScalar -> bool */
static inline R4LibrariesSlot R4FontFormat_validScalar(uint32_t reserved, uint32_t p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,112u,a,1u,0);
}
/* R4FONT.Bindings.Zig.font_format.readU16 -> u16 */
static inline R4LibrariesSlot R4FontFormat_readU16(uint32_t reserved, const uint8_t * p0, uintptr_t n0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,113u,a,1u,0);
}
/* R4FONT.Bindings.Zig.font_format.readI16 -> i16 */
static inline R4LibrariesSlot R4FontFormat_readI16(uint32_t reserved, const uint8_t * p0, uintptr_t n0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,114u,a,1u,0);
}
/* R4FONT.Bindings.Zig.font_format.readU32 -> u32 */
static inline R4LibrariesSlot R4FontFormat_readU32(uint32_t reserved, const uint8_t * p0, uintptr_t n0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,115u,a,1u,0);
}
/* R4FONT.Bindings.Zig.font_format.readTag -> u32 */
static inline R4LibrariesSlot R4FontFormat_readTag(uint32_t reserved, const uint8_t * p0, uintptr_t n0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,116u,a,1u,0);
}
/* Shared.Language.support.openSession -> bool */
static inline R4LibrariesSlot R4Library_openSession(uint32_t reserved, R4LibrarySession * p0, const R4XStartContext * p1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,117u,a,2u,0);
}
/* Shared.Language.support.system -> *r4os.r4sys.Context */
static inline R4LibrariesSlot R4Library_system(uint32_t reserved, R4LibrarySession * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,118u,a,1u,0);
}
/* Shared.Language.support.freeBytes -> void */
static inline R4LibrariesSlot R4Library_freeBytes(uint32_t reserved, const R4LibraryAllocator * p0, uint8_t * p1, uintptr_t n1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,119u,a,2u,0);
}
/* Shared.Language.support.colorClient -> @typeInfo(@typeInfo(@TypeOf(Shared.Language.support.colorClient)).@"fn".return_type.?).error_union.error_set!R4GFX.Bindings.Zig.r4gfx_abi.ColorV1Client */
static inline R4LibrariesSlot R4Library_colorClient(uint32_t reserved, const R4XStartContext * p0, R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_ColorV1Client *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,120u,a,1u,output);
}
/* Shared.Language.support.videoClient -> @typeInfo(@typeInfo(@TypeOf(Shared.Language.support.videoClient)).@"fn".return_type.?).error_union.error_set!R4VIDEO.Bindings.Zig.r4video.VideoV1Client */
static inline R4LibrariesSlot R4Library_videoClient(uint32_t reserved, const R4XStartContext * p0, R4Lib_R4VIDEO_Bindings_Zig_r4video_VideoV1Client *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,121u,a,1u,output);
}
/* consumer_adapters.Config.readString -> i32 */
static inline R4LibrariesSlot R4StdAdaptersConfig_readString(uint32_t reserved, R4Lib_r4os_r4sys_Context * p0, const uint8_t * p1, const uint8_t * p2, uintptr_t n2, const uint8_t * p3, uintptr_t n3, uint8_t * p4, uintptr_t n4) {
 (void)reserved; R4LibrariesSlot a[5]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.length=n2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.ptr=(void *)p3,.length=n3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.ptr=(void *)p4,.length=n4,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,122u,a,5u,0);
}
/* consumer_adapters.Config.readBool -> i32 */
static inline R4LibrariesSlot R4StdAdaptersConfig_readBool(uint32_t reserved, R4Lib_r4os_r4sys_Context * p0, const uint8_t * p1, const uint8_t * p2, uintptr_t n2, uint8_t p3, uint8_t * p4) {
 (void)reserved; R4LibrariesSlot a[5]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.length=n2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.ptr=(void *)p4,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,123u,a,5u,0);
}
/* consumer_adapters.Config.readU32 -> i32 */
static inline R4LibrariesSlot R4StdAdaptersConfig_readU32(uint32_t reserved, R4Lib_r4os_r4sys_Context * p0, const uint8_t * p1, const uint8_t * p2, uintptr_t n2, uint32_t p3, uint32_t * p4) {
 (void)reserved; R4LibrariesSlot a[5]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.length=n2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.ptr=(void *)p4,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,124u,a,5u,0);
}
/* consumer_adapters.Config.readI32 -> i32 */
static inline R4LibrariesSlot R4StdAdaptersConfig_readI32(uint32_t reserved, R4Lib_r4os_r4sys_Context * p0, const uint8_t * p1, const uint8_t * p2, uintptr_t n2, int32_t p3, int32_t * p4) {
 (void)reserved; R4LibrariesSlot a[5]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.length=n2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.ptr=(void *)p4,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,125u,a,5u,0);
}
/* consumer_adapters.Config.readRgb24 -> i32 */
static inline R4LibrariesSlot R4StdAdaptersConfig_readRgb24(uint32_t reserved, R4Lib_r4os_r4sys_Context * p0, const uint8_t * p1, const uint8_t * p2, uintptr_t n2, uint32_t p3, uint32_t * p4) {
 (void)reserved; R4LibrariesSlot a[5]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.length=n2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.ptr=(void *)p4,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,126u,a,5u,0);
}
/* consumer_adapters.Config.writeString -> i32 */
static inline R4LibrariesSlot R4StdAdaptersConfig_writeString(uint32_t reserved, R4Lib_r4os_r4sys_Context * p0, const uint8_t * p1, const uint8_t * p2, uintptr_t n2, const uint8_t * p3, uintptr_t n3) {
 (void)reserved; R4LibrariesSlot a[4]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.length=n2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.ptr=(void *)p3,.length=n3,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,127u,a,4u,0);
}
/* consumer_adapters.Config.writeBool -> i32 */
static inline R4LibrariesSlot R4StdAdaptersConfig_writeBool(uint32_t reserved, R4Lib_r4os_r4sys_Context * p0, const uint8_t * p1, const uint8_t * p2, uintptr_t n2, uint8_t p3) {
 (void)reserved; R4LibrariesSlot a[4]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.length=n2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,128u,a,4u,0);
}
/* consumer_adapters.Config.writeU32 -> i32 */
static inline R4LibrariesSlot R4StdAdaptersConfig_writeU32(uint32_t reserved, R4Lib_r4os_r4sys_Context * p0, const uint8_t * p1, const uint8_t * p2, uintptr_t n2, uint32_t p3) {
 (void)reserved; R4LibrariesSlot a[4]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.length=n2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,129u,a,4u,0);
}
/* consumer_adapters.Config.writeI32 -> i32 */
static inline R4LibrariesSlot R4StdAdaptersConfig_writeI32(uint32_t reserved, R4Lib_r4os_r4sys_Context * p0, const uint8_t * p1, const uint8_t * p2, uintptr_t n2, int32_t p3) {
 (void)reserved; R4LibrariesSlot a[4]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.length=n2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,130u,a,4u,0);
}
/* consumer_adapters.Config.writeRgb24 -> i32 */
static inline R4LibrariesSlot R4StdAdaptersConfig_writeRgb24(uint32_t reserved, R4Lib_r4os_r4sys_Context * p0, const uint8_t * p1, const uint8_t * p2, uintptr_t n2, uint32_t p3) {
 (void)reserved; R4LibrariesSlot a[4]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.length=n2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,131u,a,4u,0);
}
/* consumer_adapters.Config.saveDocument -> i32 */
static inline R4LibrariesSlot R4StdAdaptersConfig_saveDocument(uint32_t reserved, R4Lib_r4os_r4sys_Context * p0, const uint8_t * p1, const uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.length=n2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,132u,a,3u,0);
}
/* consumer_adapters.Config.recoverDocumentSave -> i32 */
static inline R4LibrariesSlot R4StdAdaptersConfig_recoverDocumentSave(uint32_t reserved, R4Lib_r4os_r4sys_Context * p0, const uint8_t * p1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,133u,a,2u,0);
}
/* consumer_adapters.Config.hasDocumentSaveLeftovers -> bool */
static inline R4LibrariesSlot R4StdAdaptersConfig_hasDocumentSaveLeftovers(uint32_t reserved, R4Lib_r4os_r4sys_Context * p0, const uint8_t * p1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,134u,a,2u,0);
}
/* consumer_adapters.Settings.ensureSystemDirs -> void */
static inline R4LibrariesSlot R4StdAdaptersSettings_ensureSystemDirs(uint32_t reserved, R4Lib_r4os_r4sys_Context * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,135u,a,1u,0);
}
/* consumer_adapters.Settings.ensureAppDirs -> void */
static inline R4LibrariesSlot R4StdAdaptersSettings_ensureAppDirs(uint32_t reserved, R4Lib_r4os_r4sys_Context * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,136u,a,1u,0);
}
/* consumer_adapters.Settings.ensureDesktopDirs -> void */
static inline R4LibrariesSlot R4StdAdaptersSettings_ensureDesktopDirs(uint32_t reserved, R4Lib_r4os_r4sys_Context * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,137u,a,1u,0);
}
/* consumer_adapters.Settings.flushIfDue -> R4STD.Bindings.Zig.settings.WritebackFlush */
static inline R4LibrariesSlot R4StdAdaptersSettings_flushIfDue(uint32_t reserved, R4StdSettingsWriteback * p0, uint64_t p1, const R4StdAdaptersSaver * p2, R4StdSettingsWritebackFlush *output) {
 (void)reserved; R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,138u,a,3u,output);
}
/* consumer_adapters.Settings.flushNow -> R4STD.Bindings.Zig.settings.WritebackFlush */
static inline R4LibrariesSlot R4StdAdaptersSettings_flushNow(uint32_t reserved, R4StdSettingsWriteback * p0, uint64_t p1, const R4StdAdaptersSaver * p2, R4StdSettingsWritebackFlush *output) {
 (void)reserved; R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,139u,a,3u,output);
}
/* consumer_adapters.TextFile.loadIntoTextArea -> R4STD.Bindings.Zig.text_file.LoadResult */
static inline R4LibrariesSlot R4StdAdaptersTextFile_loadIntoTextArea(uint32_t reserved, R4Lib_r4os_r4sys_Context * p0, const uint8_t * p1, R4Lib_r4os_gui_TextArea___u8_ * p2, const R4Lib_r4os_gui_TextAreaView * p3, R4Lib_R4STD_Bindings_Zig_text_file_LoadResult *output) {
 (void)reserved; R4LibrariesSlot a[4]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.ptr=(void *)p3,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,140u,a,4u,output);
}
/* consumer_adapters.TextFile.saveFromTextArea -> R4STD.Bindings.Zig.text_file.SaveResult */
static inline R4LibrariesSlot R4StdAdaptersTextFile_saveFromTextArea(uint32_t reserved, R4Lib_r4os_r4sys_Context * p0, const uint8_t * p1, R4Lib_r4os_gui_TextArea___u8_ * p2, R4Lib_R4STD_Bindings_Zig_text_file_SaveResult *output) {
 (void)reserved; R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,141u,a,3u,output);
}
/* consumer_adapters.FileHandler.resolvePath -> error{BufferTooSmall,Directory,DuplicateGuest,InvalidAssociation,InvalidGuestPath,InvalidInput,InvalidKey,InvalidMagic,InvalidPath,InvalidValue,MalformedRecord,MissingFile,MissingGuest,ReadFailed,StaleAssociation,TooManyCandidates,TooManyChoices,TooManyOptions}!void */
static inline R4LibrariesSlot R4StdAdaptersFileHandler_resolvePath(uint32_t reserved, R4Lib_r4os_r4sys_Context * p0, const R4StdAssociationConfig * p1, const R4Lib_r4os_subsystem_catalog_Catalog * p2, const uint8_t * p3, uintptr_t n3, uint8_t * p4, uintptr_t n4, R4StdFileHandlerResolution * p5, R4StdSubsystemAccessStats * p6) {
 (void)reserved; R4LibrariesSlot a[7]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.ptr=(void *)p3,.length=n3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.ptr=(void *)p4,.length=n4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.ptr=(void *)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.ptr=(void *)p6,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,142u,a,7u,0);
}
/* consumer_adapters.FileHandler.collectPathChoices -> error{BufferTooSmall,Directory,DuplicateGuest,InvalidAssociation,InvalidGuestPath,InvalidInput,InvalidKey,InvalidMagic,InvalidPath,InvalidValue,MalformedRecord,MissingFile,MissingGuest,ReadFailed,StaleAssociation,TooManyCandidates,TooManyChoices,TooManyOptions}!void */
static inline R4LibrariesSlot R4StdAdaptersFileHandler_collectPathChoices(uint32_t reserved, R4Lib_r4os_r4sys_Context * p0, const R4StdAssociationConfig * p1, const R4Lib_r4os_subsystem_catalog_Catalog * p2, const uint8_t * p3, uintptr_t n3, R4StdFileHandlerChoiceList * p4, R4StdSubsystemAccessStats * p5) {
 (void)reserved; R4LibrariesSlot a[6]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.ptr=(void *)p3,.length=n3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.ptr=(void *)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.ptr=(void *)p5,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,143u,a,6u,0);
}
/* consumer_adapters.Subsystem.load -> R4STD.Bindings.Zig.subsystem_runtime.LoadStatus */
static inline R4LibrariesSlot R4StdAdaptersSubsystem_load(uint32_t reserved, R4Lib_r4os_r4sys_Context * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,144u,a,1u,0);
}
/* consumer_adapters.Subsystem.inspect -> error{Directory,InvalidPath,MissingFile,ReadFailed}!R4STD.Bindings.Zig.subsystem_runtime.Inspection */
static inline R4LibrariesSlot R4StdAdaptersSubsystem_inspect(uint32_t reserved, R4Lib_r4os_r4sys_Context * p0, const uint8_t * p1, uintptr_t n1, R4StdSubsystemInspection *output) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,145u,a,2u,output);
}
/* consumer_adapters.Subsystem.completeProbe -> error{Directory,InvalidPath,MissingFile,ReadFailed}!r4os.subsystem_catalog.Input */
static inline R4LibrariesSlot R4StdAdaptersSubsystem_completeProbe(uint32_t reserved, R4Lib_r4os_r4sys_Context * p0, const R4Lib_r4os_subsystem_catalog_Input * p1, R4StdSubsystemAccessStats * p2, R4Lib_r4os_subsystem_catalog_Input *output) {
 (void)reserved; R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,146u,a,3u,output);
}
/* consumer_adapters.Subsystem.probe -> error{Directory,InvalidPath,MissingFile,ReadFailed}!r4os.subsystem_catalog.Input */
static inline R4LibrariesSlot R4StdAdaptersSubsystem_probe(uint32_t reserved, R4Lib_r4os_r4sys_Context * p0, const uint8_t * p1, uintptr_t n1, R4Lib_r4os_subsystem_catalog_Input *output) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,147u,a,2u,output);
}
/* consumer_adapters.Subsystem.hostPresent -> bool */
static inline R4LibrariesSlot R4StdAdaptersSubsystem_hostPresent(uint32_t reserved, R4Lib_r4os_r4sys_Context * p0, const uint8_t * p1, uintptr_t n1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,148u,a,2u,0);
}
/* R4STD.Bindings.Zig.text.Bytes.init -> R4STD.Bindings.Zig.text.Bytes */
static inline R4LibrariesSlot R4StdTextBytes_init(uint32_t reserved, const uint8_t * p0, uintptr_t n0, R4StdTextBytes *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,149u,a,1u,output);
}
/* R4STD.Bindings.Zig.text.Bytes.view -> abi_generated.R4TextView */
static inline R4LibrariesSlot R4StdTextBytes_view(uint32_t reserved, const R4StdTextBytes * p0, R4TextView *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,150u,a,1u,output);
}
/* R4STD.Bindings.Zig.text.Utf8Text.init -> error{BufferTooSmall,EmbeddedNul,InvalidLineEnding,InvalidUiText8,InvalidUtf8,RuntimeUnavailable}!R4STD.Bindings.Zig.text.Utf8Text */
static inline R4LibrariesSlot R4StdTextUtf8Text_init(uint32_t reserved, const uint8_t * p0, uintptr_t n0, R4StdTextUtf8Text *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,151u,a,1u,output);
}
/* R4STD.Bindings.Zig.text.Utf8Text.byteLen -> usize */
static inline R4LibrariesSlot R4StdTextUtf8Text_byteLen(uint32_t reserved, const R4StdTextUtf8Text * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,152u,a,1u,0);
}
/* R4STD.Bindings.Zig.text.Utf8Text.scalarCount -> usize */
static inline R4LibrariesSlot R4StdTextUtf8Text_scalarCount(uint32_t reserved, const R4StdTextUtf8Text * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,153u,a,1u,0);
}
/* R4STD.Bindings.Zig.text.Utf8Text.view -> abi_generated.R4TextView */
static inline R4LibrariesSlot R4StdTextUtf8Text_view(uint32_t reserved, const R4StdTextUtf8Text * p0, R4TextView *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,154u,a,1u,output);
}
/* R4STD.Bindings.Zig.text.UiText8.init -> error{BufferTooSmall,EmbeddedNul,InvalidLineEnding,InvalidUiText8,InvalidUtf8,RuntimeUnavailable}!R4STD.Bindings.Zig.text.UiText8 */
static inline R4LibrariesSlot R4StdTextUiText8_init(uint32_t reserved, const uint8_t * p0, uintptr_t n0, R4StdTextUiText8 *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,155u,a,1u,output);
}
/* R4STD.Bindings.Zig.text.UiText8.view -> abi_generated.R4TextView */
static inline R4LibrariesSlot R4StdTextUiText8_view(uint32_t reserved, const R4StdTextUiText8 * p0, R4TextView *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,156u,a,1u,output);
}
/* R4STD.Bindings.Zig.text.SystemText.parse -> error{BufferTooSmall,EmbeddedNul,InvalidLineEnding,InvalidUiText8,InvalidUtf8,RuntimeUnavailable}!R4STD.Bindings.Zig.text.SystemText */
static inline R4LibrariesSlot R4StdTextSystemText_parse(uint32_t reserved, const uint8_t * p0, uintptr_t n0, R4StdTextSystemText *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,157u,a,1u,output);
}
/* R4STD.Bindings.Zig.text.SystemText.canonicalSize -> usize */
static inline R4LibrariesSlot R4StdTextSystemText_canonicalSize(uint32_t reserved, const R4StdTextSystemText * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,158u,a,1u,0);
}
/* R4STD.Bindings.Zig.text.SystemText.writeCanonical -> error{BufferTooSmall,EmbeddedNul,InvalidLineEnding,InvalidUiText8,InvalidUtf8,RuntimeUnavailable}![]const u8 */
static inline R4LibrariesSlot R4StdTextSystemText_writeCanonical(uint32_t reserved, const R4StdTextSystemText * p0, uint8_t * p1, uintptr_t n1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,159u,a,2u,0);
}
/* R4STD.Bindings.Zig.text.DocumentText.init -> error{BufferTooSmall,EmbeddedNul,InvalidLineEnding,InvalidUiText8,InvalidUtf8,RuntimeUnavailable}!R4STD.Bindings.Zig.text.DocumentText */
static inline R4LibrariesSlot R4StdTextDocumentText_init(uint32_t reserved, const uint8_t * p0, uintptr_t n0, R4StdTextDocumentText *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,160u,a,1u,output);
}
/* R4STD.Bindings.Zig.text.DocumentText.writeExact -> error{BufferTooSmall,EmbeddedNul,InvalidLineEnding,InvalidUiText8,InvalidUtf8,RuntimeUnavailable}![]const u8 */
static inline R4LibrariesSlot R4StdTextDocumentText_writeExact(uint32_t reserved, const R4StdTextDocumentText * p0, uint8_t * p1, uintptr_t n1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,161u,a,2u,0);
}
/* R4STD.Bindings.Zig.settings.EntryIterator.init -> R4STD.Bindings.Zig.settings.EntryIterator */
static inline R4LibrariesSlot R4StdSettingsEntryIterator_init(uint32_t reserved, const uint8_t * p0, uintptr_t n0, R4StdSettingsEntryIterator *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,162u,a,1u,output);
}
/* R4STD.Bindings.Zig.settings.EntryIterator.next -> ?R4STD.Bindings.Zig.settings.Entry */
static inline R4LibrariesSlot R4StdSettingsEntryIterator_next(uint32_t reserved, R4StdSettingsEntryIterator * p0, R4StdSettingsEntry *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,163u,a,1u,output);
}
/* R4STD.Bindings.Zig.settings.Document.init -> R4STD.Bindings.Zig.settings.Document */
static inline R4LibrariesSlot R4StdSettingsDocument_init(uint32_t reserved, const uint8_t * p0, uintptr_t n0, R4StdSettingsDocument *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,164u,a,1u,output);
}
/* R4STD.Bindings.Zig.settings.Document.value -> ?[]const u8 */
static inline R4LibrariesSlot R4StdSettingsDocument_value(uint32_t reserved, const R4StdSettingsDocument * p0, const uint8_t * p1, uintptr_t n1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,165u,a,2u,0);
}
/* R4STD.Bindings.Zig.settings.Document.boolValue -> ?bool */
static inline R4LibrariesSlot R4StdSettingsDocument_boolValue(uint32_t reserved, const R4StdSettingsDocument * p0, const uint8_t * p1, uintptr_t n1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,166u,a,2u,0);
}
/* R4STD.Bindings.Zig.settings.Document.u32Value -> ?u32 */
static inline R4LibrariesSlot R4StdSettingsDocument_u32Value(uint32_t reserved, const R4StdSettingsDocument * p0, const uint8_t * p1, uintptr_t n1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,167u,a,2u,0);
}
/* R4STD.Bindings.Zig.settings.Document.i32Value -> ?i32 */
static inline R4LibrariesSlot R4StdSettingsDocument_i32Value(uint32_t reserved, const R4StdSettingsDocument * p0, const uint8_t * p1, uintptr_t n1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,168u,a,2u,0);
}
/* R4STD.Bindings.Zig.settings.Document.rgb24Value -> ?u32 */
static inline R4LibrariesSlot R4StdSettingsDocument_rgb24Value(uint32_t reserved, const R4StdSettingsDocument * p0, const uint8_t * p1, uintptr_t n1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,169u,a,2u,0);
}
/* R4STD.Bindings.Zig.settings.Document.formatVersion -> ?u32 */
static inline R4LibrariesSlot R4StdSettingsDocument_formatVersion(uint32_t reserved, const R4StdSettingsDocument * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,170u,a,1u,0);
}
/* R4STD.Bindings.Zig.settings.Document.schemaName -> ?[]const u8 */
static inline R4LibrariesSlot R4StdSettingsDocument_schemaName(uint32_t reserved, const R4StdSettingsDocument * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,171u,a,1u,0);
}
/* R4STD.Bindings.Zig.settings.Document.hasSupportedFormat -> bool */
static inline R4LibrariesSlot R4StdSettingsDocument_hasSupportedFormat(uint32_t reserved, const R4StdSettingsDocument * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,172u,a,1u,0);
}
/* R4STD.Bindings.Zig.settings.Writer.init -> R4STD.Bindings.Zig.settings.Writer */
static inline R4LibrariesSlot R4StdSettingsWriter_init(uint32_t reserved, uint8_t * p0, uintptr_t n0, R4StdSettingsWriter *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,173u,a,1u,output);
}
/* R4STD.Bindings.Zig.settings.Writer.writeHeader -> void */
static inline R4LibrariesSlot R4StdSettingsWriter_writeHeader(uint32_t reserved, R4StdSettingsWriter * p0, const uint8_t * p1, uintptr_t n1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,174u,a,2u,0);
}
/* R4STD.Bindings.Zig.settings.Writer.writeComment -> void */
static inline R4LibrariesSlot R4StdSettingsWriter_writeComment(uint32_t reserved, R4StdSettingsWriter * p0, const uint8_t * p1, uintptr_t n1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,175u,a,2u,0);
}
/* R4STD.Bindings.Zig.settings.Writer.writePair -> void */
static inline R4LibrariesSlot R4StdSettingsWriter_writePair(uint32_t reserved, R4StdSettingsWriter * p0, const uint8_t * p1, uintptr_t n1, const uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.length=n2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,176u,a,3u,0);
}
/* R4STD.Bindings.Zig.settings.Writer.writePairBool -> void */
static inline R4LibrariesSlot R4StdSettingsWriter_writePairBool(uint32_t reserved, R4StdSettingsWriter * p0, const uint8_t * p1, uintptr_t n1, uint8_t p2) {
 (void)reserved; R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,177u,a,3u,0);
}
/* R4STD.Bindings.Zig.settings.Writer.writePairU32 -> void */
static inline R4LibrariesSlot R4StdSettingsWriter_writePairU32(uint32_t reserved, R4StdSettingsWriter * p0, const uint8_t * p1, uintptr_t n1, uint32_t p2) {
 (void)reserved; R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,178u,a,3u,0);
}
/* R4STD.Bindings.Zig.settings.Writer.writePairI32 -> void */
static inline R4LibrariesSlot R4StdSettingsWriter_writePairI32(uint32_t reserved, R4StdSettingsWriter * p0, const uint8_t * p1, uintptr_t n1, int32_t p2) {
 (void)reserved; R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,179u,a,3u,0);
}
/* R4STD.Bindings.Zig.settings.Writer.writePairRgb24 -> void */
static inline R4LibrariesSlot R4StdSettingsWriter_writePairRgb24(uint32_t reserved, R4StdSettingsWriter * p0, const uint8_t * p1, uintptr_t n1, uint32_t p2) {
 (void)reserved; R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,180u,a,3u,0);
}
/* R4STD.Bindings.Zig.settings.Writer.bytes -> []const u8 */
static inline R4LibrariesSlot R4StdSettingsWriter_bytes(uint32_t reserved, const R4StdSettingsWriter * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,181u,a,1u,0);
}
/* R4STD.Bindings.Zig.settings.Writer.ok -> bool */
static inline R4LibrariesSlot R4StdSettingsWriter_ok(uint32_t reserved, const R4StdSettingsWriter * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,182u,a,1u,0);
}
/* R4STD.Bindings.Zig.settings.WritebackFlush.attempted -> bool */
static inline R4LibrariesSlot R4StdSettingsWritebackFlush_attempted(uint32_t reserved, const R4StdSettingsWritebackFlush * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,183u,a,1u,0);
}
/* R4STD.Bindings.Zig.settings.WritebackFlush.ok -> bool */
static inline R4LibrariesSlot R4StdSettingsWritebackFlush_ok(uint32_t reserved, const R4StdSettingsWritebackFlush * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,184u,a,1u,0);
}
/* R4STD.Bindings.Zig.settings.WritebackPolicy.forHz -> R4STD.Bindings.Zig.settings.WritebackPolicy */
static inline R4LibrariesSlot R4StdSettingsWritebackPolicy_forHz(uint32_t reserved, uint32_t p0, uint32_t p1, R4StdSettingsWritebackPolicy *output) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,185u,a,2u,output);
}
/* R4STD.Bindings.Zig.settings.WritebackPolicy.defaultSaveDelayMs -> u32 */
static inline R4LibrariesSlot R4StdSettingsWritebackPolicy_defaultSaveDelayMs(uint32_t reserved, uint32_t p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,186u,a,1u,0);
}
/* R4STD.Bindings.Zig.settings.WritebackPolicy.defaultRetryDelayMs -> u32 */
static inline R4LibrariesSlot R4StdSettingsWritebackPolicy_defaultRetryDelayMs(uint32_t reserved, uint32_t p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,187u,a,1u,0);
}
/* R4STD.Bindings.Zig.settings.Writeback.init -> R4STD.Bindings.Zig.settings.Writeback */
static inline R4LibrariesSlot R4StdSettingsWriteback_init(uint32_t reserved, const R4StdSettingsWritebackPolicy * p0, R4StdSettingsWriteback *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,188u,a,1u,output);
}
/* R4STD.Bindings.Zig.settings.Writeback.configure -> void */
static inline R4LibrariesSlot R4StdSettingsWriteback_configure(uint32_t reserved, R4StdSettingsWriteback * p0, const R4StdSettingsWritebackPolicy * p1, uint64_t p2) {
 (void)reserved; R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,189u,a,3u,0);
}
/* R4STD.Bindings.Zig.settings.Writeback.markDirty -> void */
static inline R4LibrariesSlot R4StdSettingsWriteback_markDirty(uint32_t reserved, R4StdSettingsWriteback * p0, uint64_t p1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,190u,a,2u,0);
}
/* R4STD.Bindings.Zig.settings.Writeback.isDirty -> bool */
static inline R4LibrariesSlot R4StdSettingsWriteback_isDirty(uint32_t reserved, const R4StdSettingsWriteback * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,191u,a,1u,0);
}
/* R4STD.Bindings.Zig.settings.Writeback.isDue -> bool */
static inline R4LibrariesSlot R4StdSettingsWriteback_isDue(uint32_t reserved, const R4StdSettingsWriteback * p0, uint64_t p1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,192u,a,2u,0);
}
/* R4STD.Bindings.Zig.settings.Writeback.complete -> R4STD.Bindings.Zig.settings.WritebackFlush */
static inline R4LibrariesSlot R4StdSettingsWriteback_complete(uint32_t reserved, R4StdSettingsWriteback * p0, uint64_t p1, int32_t p2, R4StdSettingsWritebackFlush *output) {
 (void)reserved; R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,193u,a,3u,output);
}
/* R4STD.Bindings.Zig.time.Config.selectedIndex -> usize */
static inline R4LibrariesSlot R4StdTimeHelpersConfig_selectedIndex(uint32_t reserved, const R4StdTimeHelpersConfig * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,194u,a,1u,0);
}
/* R4STD.Bindings.Zig.time.Config.zone -> R4STD.Bindings.Zig.time.Zone */
static inline R4LibrariesSlot R4StdTimeHelpersConfig_zone(uint32_t reserved, const R4StdTimeHelpersConfig * p0, R4StdTimeZone *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,195u,a,1u,output);
}
/* R4STD.Bindings.Zig.time.Config.selectedClockFormat -> u32 */
static inline R4LibrariesSlot R4StdTimeHelpersConfig_selectedClockFormat(uint32_t reserved, const R4StdTimeHelpersConfig * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,196u,a,1u,0);
}
/* R4STD.Bindings.Zig.time.Config.offsetMinutes -> i16 */
static inline R4LibrariesSlot R4StdTimeHelpersConfig_offsetMinutes(uint32_t reserved, const R4StdTimeHelpersConfig * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,197u,a,1u,0);
}
/* R4STD.Bindings.Zig.time.Config.offsetMinutesForState -> i16 */
static inline R4LibrariesSlot R4StdTimeHelpersConfig_offsetMinutesForState(uint32_t reserved, const R4StdTimeHelpersConfig * p0, const R4TimeState * p1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,198u,a,2u,0);
}
/* R4STD.Bindings.Zig.time.Config.loadFromBytes -> bool */
static inline R4LibrariesSlot R4StdTimeHelpersConfig_loadFromBytes(uint32_t reserved, R4StdTimeHelpersConfig * p0, const uint8_t * p1, uintptr_t n1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,199u,a,2u,0);
}
/* R4STD.Bindings.Zig.time.Config.setIndex -> void */
static inline R4LibrariesSlot R4StdTimeHelpersConfig_setIndex(uint32_t reserved, R4StdTimeHelpersConfig * p0, uint64_t p1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,200u,a,2u,0);
}
/* R4STD.Bindings.Zig.time.Config.setClockFormat -> void */
static inline R4LibrariesSlot R4StdTimeHelpersConfig_setClockFormat(uint32_t reserved, R4StdTimeHelpersConfig * p0, uint32_t p1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,201u,a,2u,0);
}
/* R4STD.Bindings.Zig.time.Config.writeTo -> []const u8 */
static inline R4LibrariesSlot R4StdTimeHelpersConfig_writeTo(uint32_t reserved, const R4StdTimeHelpersConfig * p0, uint8_t * p1, uintptr_t n1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,202u,a,2u,0);
}
/* R4STD.Bindings.Zig.time.Config.writeToForState -> []const u8 */
static inline R4LibrariesSlot R4StdTimeHelpersConfig_writeToForState(uint32_t reserved, const R4StdTimeHelpersConfig * p0, uint8_t * p1, uintptr_t n1, const R4TimeState * p2) {
 (void)reserved; R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,203u,a,3u,0);
}
/* R4STD.Bindings.Zig.codec.Stream.push -> error{BufferTooSmall,InvalidArgument,InvalidScalar,InvalidUtf8,RangesOverlap,RuntimeUnavailable,UndefinedByte,Unrepresentable}!R4STD.Bindings.Zig.codec.Decoded */
static inline R4LibrariesSlot R4StdCodecStream_push(uint32_t reserved, R4StdCodecStream * p0, uint8_t p1, R4StdCodecDecoded *output) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,204u,a,2u,output);
}
/* R4STD.Bindings.Zig.codec.Stream.finish -> error{BufferTooSmall,InvalidArgument,InvalidScalar,InvalidUtf8,RangesOverlap,RuntimeUnavailable,UndefinedByte,Unrepresentable}!bool */
static inline R4LibrariesSlot R4StdCodecStream_finish(uint32_t reserved, const R4StdCodecStream * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,205u,a,1u,0);
}
/* R4STD.Bindings.Zig.codec.Stream.reset -> void */
static inline R4LibrariesSlot R4StdCodecStream_reset(uint32_t reserved, R4StdCodecStream * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,206u,a,1u,0);
}
/* R4STD.Bindings.Zig.grapheme.State.push -> bool */
static inline R4LibrariesSlot R4StdGraphemeState_push(uint32_t reserved, R4StdGraphemeState * p0, uint32_t p1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,207u,a,2u,0);
}
/* R4STD.Bindings.Zig.grapheme.Iterator.next -> error{Incomplete,InvalidUtf8}!?R4STD.Bindings.Zig.grapheme.Range */
static inline R4LibrariesSlot R4StdGraphemeIterator_next(uint32_t reserved, R4StdGraphemeIterator * p0, R4StdGraphemeRange *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,208u,a,1u,output);
}
/* R4STD.Bindings.Zig.grapheme.Stream.push -> error{Incomplete,InvalidUtf8}!?R4STD.Bindings.Zig.grapheme.Stream.Event */
static inline R4LibrariesSlot R4StdGraphemeStream_push(uint32_t reserved, R4StdGraphemeStream * p0, uint8_t p1, R4StdGraphemeStream_Event *output) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,209u,a,2u,output);
}
/* R4STD.Bindings.Zig.grapheme.Stream.finish -> error{Incomplete,InvalidUtf8}!usize */
static inline R4LibrariesSlot R4StdGraphemeStream_finish(uint32_t reserved, const R4StdGraphemeStream * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,210u,a,1u,0);
}
/* R4STD.Bindings.Zig.shortcut.Shortcut.init -> error{ArgsTooLong,BufferTooSmall,DuplicateField,IconTooLong,InvalidPolicy,InvalidTarget,InvalidText,MissingFormat,MissingSchema,MissingTarget,TargetTooLong,TitleTooLong,UnknownField,UnsupportedFormat,WorkdirTooLong,WrongSchema}!R4STD.Bindings.Zig.shortcut.Shortcut */
static inline R4LibrariesSlot R4StdShortcutShortcut_init(uint32_t reserved, const uint8_t * p0, uintptr_t n0, R4StdShortcutShortcut *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,211u,a,1u,output);
}
/* R4STD.Bindings.Zig.shortcut.Shortcut.loadFromBytes -> error{ArgsTooLong,BufferTooSmall,DuplicateField,IconTooLong,InvalidPolicy,InvalidTarget,InvalidText,MissingFormat,MissingSchema,MissingTarget,TargetTooLong,TitleTooLong,UnknownField,UnsupportedFormat,WorkdirTooLong,WrongSchema}!void */
static inline R4LibrariesSlot R4StdShortcutShortcut_loadFromBytes(uint32_t reserved, R4StdShortcutShortcut * p0, const uint8_t * p1, uintptr_t n1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,212u,a,2u,0);
}
/* R4STD.Bindings.Zig.shortcut.Shortcut.writeTo -> error{ArgsTooLong,BufferTooSmall,DuplicateField,IconTooLong,InvalidPolicy,InvalidTarget,InvalidText,MissingFormat,MissingSchema,MissingTarget,TargetTooLong,TitleTooLong,UnknownField,UnsupportedFormat,WorkdirTooLong,WrongSchema}![]const u8 */
static inline R4LibrariesSlot R4StdShortcutShortcut_writeTo(uint32_t reserved, const R4StdShortcutShortcut * p0, uint8_t * p1, uintptr_t n1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,213u,a,2u,0);
}
/* R4STD.Bindings.Zig.shortcut.Shortcut.resolve -> error{ArgsTooLong,BufferTooSmall,DuplicateField,IconTooLong,InvalidPolicy,InvalidTarget,InvalidText,MissingFormat,MissingSchema,MissingTarget,TargetTooLong,TitleTooLong,UnknownField,UnsupportedFormat,WorkdirTooLong,WrongSchema}!R4STD.Bindings.Zig.shortcut.ResolvedTarget */
static inline R4LibrariesSlot R4StdShortcutShortcut_resolve(uint32_t reserved, const R4StdShortcutShortcut * p0, R4StdShortcutResolvedTarget *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,214u,a,1u,output);
}
/* R4STD.Bindings.Zig.shortcut.Shortcut.setTarget -> error{ArgsTooLong,BufferTooSmall,DuplicateField,IconTooLong,InvalidPolicy,InvalidTarget,InvalidText,MissingFormat,MissingSchema,MissingTarget,TargetTooLong,TitleTooLong,UnknownField,UnsupportedFormat,WorkdirTooLong,WrongSchema}!void */
static inline R4LibrariesSlot R4StdShortcutShortcut_setTarget(uint32_t reserved, R4StdShortcutShortcut * p0, const uint8_t * p1, uintptr_t n1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,215u,a,2u,0);
}
/* R4STD.Bindings.Zig.shortcut.Shortcut.setTitle -> error{ArgsTooLong,BufferTooSmall,DuplicateField,IconTooLong,InvalidPolicy,InvalidTarget,InvalidText,MissingFormat,MissingSchema,MissingTarget,TargetTooLong,TitleTooLong,UnknownField,UnsupportedFormat,WorkdirTooLong,WrongSchema}!void */
static inline R4LibrariesSlot R4StdShortcutShortcut_setTitle(uint32_t reserved, R4StdShortcutShortcut * p0, const uint8_t * p1, uintptr_t n1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,216u,a,2u,0);
}
/* R4STD.Bindings.Zig.shortcut.Shortcut.setArgs -> error{ArgsTooLong,BufferTooSmall,DuplicateField,IconTooLong,InvalidPolicy,InvalidTarget,InvalidText,MissingFormat,MissingSchema,MissingTarget,TargetTooLong,TitleTooLong,UnknownField,UnsupportedFormat,WorkdirTooLong,WrongSchema}!void */
static inline R4LibrariesSlot R4StdShortcutShortcut_setArgs(uint32_t reserved, R4StdShortcutShortcut * p0, const uint8_t * p1, uintptr_t n1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,217u,a,2u,0);
}
/* R4STD.Bindings.Zig.shortcut.Shortcut.setPolicy -> void */
static inline R4LibrariesSlot R4StdShortcutShortcut_setPolicy(uint32_t reserved, R4StdShortcutShortcut * p0, uint32_t p1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,218u,a,2u,0);
}
/* R4STD.Bindings.Zig.shortcut.Shortcut.setIcon -> error{ArgsTooLong,BufferTooSmall,DuplicateField,IconTooLong,InvalidPolicy,InvalidTarget,InvalidText,MissingFormat,MissingSchema,MissingTarget,TargetTooLong,TitleTooLong,UnknownField,UnsupportedFormat,WorkdirTooLong,WrongSchema}!void */
static inline R4LibrariesSlot R4StdShortcutShortcut_setIcon(uint32_t reserved, R4StdShortcutShortcut * p0, const uint8_t * p1, uintptr_t n1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,219u,a,2u,0);
}
/* R4STD.Bindings.Zig.shortcut.Shortcut.setWorkdir -> error{ArgsTooLong,BufferTooSmall,DuplicateField,IconTooLong,InvalidPolicy,InvalidTarget,InvalidText,MissingFormat,MissingSchema,MissingTarget,TargetTooLong,TitleTooLong,UnknownField,UnsupportedFormat,WorkdirTooLong,WrongSchema}!void */
static inline R4LibrariesSlot R4StdShortcutShortcut_setWorkdir(uint32_t reserved, R4StdShortcutShortcut * p0, const uint8_t * p1, uintptr_t n1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,220u,a,2u,0);
}
/* R4STD.Bindings.Zig.shortcut.Shortcut.targetText -> []const u8 */
static inline R4LibrariesSlot R4StdShortcutShortcut_targetText(uint32_t reserved, const R4StdShortcutShortcut * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,221u,a,1u,0);
}
/* R4STD.Bindings.Zig.shortcut.Shortcut.titleText -> []const u8 */
static inline R4LibrariesSlot R4StdShortcutShortcut_titleText(uint32_t reserved, const R4StdShortcutShortcut * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,222u,a,1u,0);
}
/* R4STD.Bindings.Zig.shortcut.Shortcut.argsText -> []const u8 */
static inline R4LibrariesSlot R4StdShortcutShortcut_argsText(uint32_t reserved, const R4StdShortcutShortcut * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,223u,a,1u,0);
}
/* R4STD.Bindings.Zig.shortcut.Shortcut.iconText -> []const u8 */
static inline R4LibrariesSlot R4StdShortcutShortcut_iconText(uint32_t reserved, const R4StdShortcutShortcut * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,224u,a,1u,0);
}
/* R4STD.Bindings.Zig.shortcut.Shortcut.workdirText -> []const u8 */
static inline R4LibrariesSlot R4StdShortcutShortcut_workdirText(uint32_t reserved, const R4StdShortcutShortcut * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,225u,a,1u,0);
}
/* R4STD.Bindings.Zig.app_assoc.AppEntry.idText -> []const u8 */
static inline R4LibrariesSlot R4StdAssociationAppEntry_idText(uint32_t reserved, const R4StdAssociationAppEntry * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,226u,a,1u,0);
}
/* R4STD.Bindings.Zig.app_assoc.AppEntry.titleText -> []const u8 */
static inline R4LibrariesSlot R4StdAssociationAppEntry_titleText(uint32_t reserved, const R4StdAssociationAppEntry * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,227u,a,1u,0);
}
/* R4STD.Bindings.Zig.app_assoc.AppEntry.pathText -> []const u8 */
static inline R4LibrariesSlot R4StdAssociationAppEntry_pathText(uint32_t reserved, const R4StdAssociationAppEntry * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,228u,a,1u,0);
}
/* R4STD.Bindings.Zig.app_assoc.AppEntry.argsText -> []const u8 */
static inline R4LibrariesSlot R4StdAssociationAppEntry_argsText(uint32_t reserved, const R4StdAssociationAppEntry * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,229u,a,1u,0);
}
/* R4STD.Bindings.Zig.app_assoc.ExtEntry.extText -> []const u8 */
static inline R4LibrariesSlot R4StdAssociationExtEntry_extText(uint32_t reserved, const R4StdAssociationExtEntry * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,230u,a,1u,0);
}
/* R4STD.Bindings.Zig.app_assoc.ExtEntry.appIdText -> []const u8 */
static inline R4LibrariesSlot R4StdAssociationExtEntry_appIdText(uint32_t reserved, const R4StdAssociationExtEntry * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,231u,a,1u,0);
}
/* R4STD.Bindings.Zig.app_assoc.ExtEntry.subsystemIdText -> []const u8 */
static inline R4LibrariesSlot R4StdAssociationExtEntry_subsystemIdText(uint32_t reserved, const R4StdAssociationExtEntry * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,232u,a,1u,0);
}
/* R4STD.Bindings.Zig.app_assoc.ExtEntry.formatIdText -> []const u8 */
static inline R4LibrariesSlot R4StdAssociationExtEntry_formatIdText(uint32_t reserved, const R4StdAssociationExtEntry * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,233u,a,1u,0);
}
/* R4STD.Bindings.Zig.app_assoc.ExtEntry.typeNameText -> []const u8 */
static inline R4LibrariesSlot R4StdAssociationExtEntry_typeNameText(uint32_t reserved, const R4StdAssociationExtEntry * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,234u,a,1u,0);
}
/* R4STD.Bindings.Zig.app_assoc.ExtEntry.shortNameText -> []const u8 */
static inline R4LibrariesSlot R4StdAssociationExtEntry_shortNameText(uint32_t reserved, const R4StdAssociationExtEntry * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,235u,a,1u,0);
}
/* R4STD.Bindings.Zig.app_assoc.ExtEntry.prefixText -> []const u8 */
static inline R4LibrariesSlot R4StdAssociationExtEntry_prefixText(uint32_t reserved, const R4StdAssociationExtEntry * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,236u,a,1u,0);
}
/* R4STD.Bindings.Zig.app_assoc.Config.initDefault -> R4STD.Bindings.Zig.app_assoc.Config */
static inline R4LibrariesSlot R4StdAssociationConfig_initDefault(uint32_t reserved, R4StdAssociationConfig *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,237u,a,0u,output);
}
/* R4STD.Bindings.Zig.app_assoc.Config.clear -> void */
static inline R4LibrariesSlot R4StdAssociationConfig_clear(uint32_t reserved, R4StdAssociationConfig * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,238u,a,1u,0);
}
/* R4STD.Bindings.Zig.app_assoc.Config.loadDefaults -> void */
static inline R4LibrariesSlot R4StdAssociationConfig_loadDefaults(uint32_t reserved, R4StdAssociationConfig * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,239u,a,1u,0);
}
/* R4STD.Bindings.Zig.app_assoc.Config.loadFromBytes -> bool */
static inline R4LibrariesSlot R4StdAssociationConfig_loadFromBytes(uint32_t reserved, R4StdAssociationConfig * p0, const uint8_t * p1, uintptr_t n1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,240u,a,2u,0);
}
/* R4STD.Bindings.Zig.app_assoc.Config.writeTo -> []const u8 */
static inline R4LibrariesSlot R4StdAssociationConfig_writeTo(uint32_t reserved, const R4StdAssociationConfig * p0, uint8_t * p1, uintptr_t n1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,241u,a,2u,0);
}
/* R4STD.Bindings.Zig.app_assoc.Config.appById -> ?*const R4STD.Bindings.Zig.app_assoc.AppEntry */
static inline R4LibrariesSlot R4StdAssociationConfig_appById(uint32_t reserved, const R4StdAssociationConfig * p0, const uint8_t * p1, uintptr_t n1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,242u,a,2u,0);
}
/* R4STD.Bindings.Zig.app_assoc.Config.extensionByName -> ?*const R4STD.Bindings.Zig.app_assoc.ExtEntry */
static inline R4LibrariesSlot R4StdAssociationConfig_extensionByName(uint32_t reserved, const R4StdAssociationConfig * p0, const uint8_t * p1, uintptr_t n1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,243u,a,2u,0);
}
/* R4STD.Bindings.Zig.app_assoc.Config.resolvePath -> ?R4STD.Bindings.Zig.app_assoc.LaunchTarget */
static inline R4LibrariesSlot R4StdAssociationConfig_resolvePath(uint32_t reserved, const R4StdAssociationConfig * p0, const uint8_t * p1, uintptr_t n1, uint8_t * p2, uintptr_t n2, R4StdAssociationLaunchTarget *output) {
 (void)reserved; R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.length=n2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,244u,a,3u,output);
}
/* R4STD.Bindings.Zig.app_assoc.Config.expandAppArgs -> ?[]const u8 */
static inline R4LibrariesSlot R4StdAssociationConfig_expandAppArgs(uint32_t reserved, const R4StdAssociationConfig * p0, const uint8_t * p1, uintptr_t n1, const uint8_t * p2, uintptr_t n2, uint8_t * p3, uintptr_t n3) {
 (void)reserved; R4LibrariesSlot a[4]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.length=n2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.ptr=(void *)p3,.length=n3,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,245u,a,4u,0);
}
/* R4STD.Bindings.Zig.app_assoc.Config.setExtensionApp -> bool */
static inline R4LibrariesSlot R4StdAssociationConfig_setExtensionApp(uint32_t reserved, R4StdAssociationConfig * p0, uint64_t p1, const uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.length=n2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,246u,a,3u,0);
}
/* R4STD.Bindings.Zig.app_assoc.Config.setExtensionSubsystem -> bool */
static inline R4LibrariesSlot R4StdAssociationConfig_setExtensionSubsystem(uint32_t reserved, R4StdAssociationConfig * p0, uint64_t p1, const uint8_t * p2, uintptr_t n2, const uint8_t * p3, uintptr_t n3) {
 (void)reserved; R4LibrariesSlot a[4]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.length=n2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.ptr=(void *)p3,.length=n3,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,247u,a,4u,0);
}
/* R4STD.Bindings.Zig.app_assoc.Config.setExtensionNone -> bool */
static inline R4LibrariesSlot R4StdAssociationConfig_setExtensionNone(uint32_t reserved, R4StdAssociationConfig * p0, uint64_t p1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,248u,a,2u,0);
}
/* R4STD.Bindings.Zig.file_handler.ChoiceList.slice -> []const R4STD.Bindings.Zig.file_handler.Choice */
static inline R4LibrariesSlot R4StdFileHandlerChoiceList_slice(uint32_t reserved, const R4StdFileHandlerChoiceList * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,249u,a,1u,0);
}
/* R4IMG.Bindings.Zig.r4img.Info.pixelCount -> error{DecodeFailed,Empty,InvalidArgument,InvalidDimensions,InvalidImage,PixelBufferTooSmall,ScratchBufferTooSmall,TooLarge,UnsupportedFeature,UnsupportedFormat}!usize */
static inline R4LibrariesSlot R4ImgHelpersInfo_pixelCount(uint32_t reserved, const R4ImgHelpersInfo * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,250u,a,1u,0);
}
/* R4IMG.Bindings.Zig.r4img.RasterContext.init -> ?R4IMG.Bindings.Zig.r4img.RasterContext */
static inline R4LibrariesSlot R4ImgHelpersRasterContext_init(uint32_t reserved, const R4XStartContext * p0, R4ImgHelpersRasterContext *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,251u,a,1u,output);
}
/* R4IMG.Bindings.Zig.r4img.RasterContext.color -> error{DecodeFailed,Empty,InvalidArgument,InvalidDimensions,InvalidImage,PixelBufferTooSmall,ScratchBufferTooSmall,TooLarge,UnsupportedFeature,UnsupportedFormat}!R4IMG.Bindings.Zig.r4img_abi.R4ImgRasterColor */
static inline R4LibrariesSlot R4ImgHelpersRasterContext_color(uint32_t reserved, const R4ImgHelpersRasterContext * p0, const uint8_t * p1, uintptr_t n1, R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor *output) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,252u,a,2u,output);
}
/* R4IMG.Bindings.Zig.r4img.RasterContext.iccProfile -> error{DecodeFailed,Empty,InvalidArgument,InvalidDimensions,InvalidImage,PixelBufferTooSmall,ScratchBufferTooSmall,TooLarge,UnsupportedFeature,UnsupportedFormat}![]u8 */
static inline R4LibrariesSlot R4ImgHelpersRasterContext_iccProfile(uint32_t reserved, const R4ImgHelpersRasterContext * p0, const uint8_t * p1, uintptr_t n1, uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.length=n2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,253u,a,3u,0);
}
/* R4IMG.Bindings.Zig.r4img.Context.init -> ?R4IMG.Bindings.Zig.r4img.Context */
static inline R4LibrariesSlot R4ImgHelpersContext_init(uint32_t reserved, const R4XStartContext * p0, R4ImgHelpersContext *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,254u,a,1u,output);
}
/* R4IMG.Bindings.Zig.r4img.Context.probe -> error{DecodeFailed,Empty,InvalidArgument,InvalidDimensions,InvalidImage,PixelBufferTooSmall,ScratchBufferTooSmall,TooLarge,UnsupportedFeature,UnsupportedFormat}!R4IMG.Bindings.Zig.r4img.Info */
static inline R4LibrariesSlot R4ImgHelpersContext_probe(uint32_t reserved, const R4ImgHelpersContext * p0, const uint8_t * p1, uintptr_t n1, const uint8_t * p2, uintptr_t n2, R4ImgHelpersInfo *output) {
 (void)reserved; R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.length=n2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,255u,a,3u,output);
}
/* R4IMG.Bindings.Zig.r4img.Context.scratchBytesFor -> error{DecodeFailed,Empty,InvalidArgument,InvalidDimensions,InvalidImage,PixelBufferTooSmall,ScratchBufferTooSmall,TooLarge,UnsupportedFeature,UnsupportedFormat}!usize */
static inline R4LibrariesSlot R4ImgHelpersContext_scratchBytesFor(uint32_t reserved, const R4ImgHelpersContext * p0, const R4ImgHelpersInfo * p1, uint64_t p2) {
 (void)reserved; R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,256u,a,3u,0);
}
/* R4IMG.Bindings.Zig.r4img.Context.decode -> error{DecodeFailed,Empty,InvalidArgument,InvalidDimensions,InvalidImage,PixelBufferTooSmall,ScratchBufferTooSmall,TooLarge,UnsupportedFeature,UnsupportedFormat}!R4IMG.Bindings.Zig.r4img.Image */
static inline R4LibrariesSlot R4ImgHelpersContext_decode(uint32_t reserved, const R4ImgHelpersContext * p0, const uint8_t * p1, uintptr_t n1, const uint8_t * p2, uintptr_t n2, uint32_t * p3, uintptr_t n3, uint8_t * p4, uintptr_t n4, R4ImgHelpersImage *output) {
 (void)reserved; R4LibrariesSlot a[5]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.length=n2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.ptr=(void *)p3,.length=n3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.ptr=(void *)p4,.length=n4,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,257u,a,5u,output);
}
/* R4IMG.Bindings.Zig.r4img.Context.decodeSvg -> error{DecodeFailed,Empty,InvalidArgument,InvalidDimensions,InvalidImage,PixelBufferTooSmall,ScratchBufferTooSmall,TooLarge,UnsupportedFeature,UnsupportedFormat}!R4IMG.Bindings.Zig.r4img.Image */
static inline R4LibrariesSlot R4ImgHelpersContext_decodeSvg(uint32_t reserved, const R4ImgHelpersContext * p0, const uint8_t * p1, uintptr_t n1, const uint8_t * p2, uintptr_t n2, uint32_t * p3, uintptr_t n3, uint8_t * p4, uintptr_t n4, const R4ImgHelpersSvgRenderOptions * p5, R4ImgHelpersImage *output) {
 (void)reserved; R4LibrariesSlot a[6]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.length=n2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.ptr=(void *)p3,.length=n3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.ptr=(void *)p4,.length=n4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.ptr=(void *)p5,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,258u,a,6u,output);
}
/* R4IMG.Bindings.Zig.r4img.Context.decodeSvgAt -> error{DecodeFailed,Empty,InvalidArgument,InvalidDimensions,InvalidImage,PixelBufferTooSmall,ScratchBufferTooSmall,TooLarge,UnsupportedFeature,UnsupportedFormat}!R4IMG.Bindings.Zig.r4img.Image */
static inline R4LibrariesSlot R4ImgHelpersContext_decodeSvgAt(uint32_t reserved, const R4ImgHelpersContext * p0, const uint8_t * p1, uintptr_t n1, const uint8_t * p2, uintptr_t n2, uint32_t * p3, uintptr_t n3, uint8_t * p4, uintptr_t n4, uint32_t p5, uint32_t p6, const R4ImgHelpersSvgRenderOptions * p7, R4ImgHelpersImage *output) {
 (void)reserved; R4LibrariesSlot a[8]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.length=n2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.ptr=(void *)p3,.length=n3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.ptr=(void *)p4,.length=n4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4LIBRARIES_PRESENT};
 a[7] = (R4LibrariesSlot){.ptr=(void *)p7,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,259u,a,8u,output);
}
/* R4IMG.Bindings.Zig.r4img.Context.scaleComposite -> error{DecodeFailed,Empty,InvalidArgument,InvalidDimensions,InvalidImage,PixelBufferTooSmall,ScratchBufferTooSmall,TooLarge,UnsupportedFeature,UnsupportedFormat}![]u32 */
static inline R4LibrariesSlot R4ImgHelpersContext_scaleComposite(uint32_t reserved, const R4ImgHelpersContext * p0, const R4ImgHelpersImage * p1, uint32_t * p2, uintptr_t n2, uint32_t p3, uint32_t p4, uint32_t p5) {
 (void)reserved; R4LibrariesSlot a[6]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.length=n2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,260u,a,6u,0);
}
/* R4IMG.Bindings.Zig.r4img.Context.decoderDiagnostic -> error{DecodeFailed,Empty,InvalidArgument,InvalidDimensions,InvalidImage,PixelBufferTooSmall,ScratchBufferTooSmall,TooLarge,UnsupportedFeature,UnsupportedFormat}!R4IMG.Bindings.Zig.r4img.DecoderDiagnostic */
static inline R4LibrariesSlot R4ImgHelpersContext_decoderDiagnostic(uint32_t reserved, const R4ImgHelpersContext * p0, R4ImgHelpersDecoderDiagnostic *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,261u,a,1u,output);
}
/* R4IMG.Bindings.Zig.r4img.PngContext.init -> ?R4IMG.Bindings.Zig.r4img.PngContext */
static inline R4LibrariesSlot R4ImgHelpersPngContext_init(uint32_t reserved, const R4XStartContext * p0, R4ImgHelpersPngContext *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,262u,a,1u,output);
}
/* R4IMG.Bindings.Zig.r4img.PngContext.pngColor -> error{DecodeFailed,Empty,InvalidArgument,InvalidDimensions,InvalidImage,PixelBufferTooSmall,ScratchBufferTooSmall,TooLarge,UnsupportedFeature,UnsupportedFormat}!R4IMG.Bindings.Zig.r4img_abi.R4ImgPngColor */
static inline R4LibrariesSlot R4ImgHelpersPngContext_pngColor(uint32_t reserved, const R4ImgHelpersPngContext * p0, const uint8_t * p1, uintptr_t n1, R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *output) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,263u,a,2u,output);
}
/* R4IMG.Bindings.Zig.r4img.PngContext.pngIccProfile -> error{DecodeFailed,Empty,InvalidArgument,InvalidDimensions,InvalidImage,PixelBufferTooSmall,ScratchBufferTooSmall,TooLarge,UnsupportedFeature,UnsupportedFormat}![]u8 */
static inline R4LibrariesSlot R4ImgHelpersPngContext_pngIccProfile(uint32_t reserved, const R4ImgHelpersPngContext * p0, const uint8_t * p1, uintptr_t n1, uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.length=n2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,264u,a,3u,0);
}
/* R4IMG.Bindings.Zig.r4img.PngContext.pngScratchBytes16 -> error{DecodeFailed,Empty,InvalidArgument,InvalidDimensions,InvalidImage,PixelBufferTooSmall,ScratchBufferTooSmall,TooLarge,UnsupportedFeature,UnsupportedFormat}!usize */
static inline R4LibrariesSlot R4ImgHelpersPngContext_pngScratchBytes16(uint32_t reserved, const R4ImgHelpersPngContext * p0, const R4ImgHelpersInfo * p1, uint64_t p2) {
 (void)reserved; R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,265u,a,3u,0);
}
/* R4IMG.Bindings.Zig.r4img.PngContext.pngDecode16 -> error{DecodeFailed,Empty,InvalidArgument,InvalidDimensions,InvalidImage,PixelBufferTooSmall,ScratchBufferTooSmall,TooLarge,UnsupportedFeature,UnsupportedFormat}!R4IMG.Bindings.Zig.r4img.Image16 */
static inline R4LibrariesSlot R4ImgHelpersPngContext_pngDecode16(uint32_t reserved, const R4ImgHelpersPngContext * p0, const uint8_t * p1, uintptr_t n1, uint16_t * p2, uintptr_t n2, uint8_t * p3, uintptr_t n3, R4ImgHelpersImage16 *output) {
 (void)reserved; R4LibrariesSlot a[4]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.length=n2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.ptr=(void *)p3,.length=n3,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,266u,a,4u,output);
}
/* R4FONT.Bindings.Zig.r4font.Context.init -> ?R4FONT.Bindings.Zig.r4font.Context */
static inline R4LibrariesSlot R4FontHelpersContext_init(uint32_t reserved, const R4XStartContext * p0, R4FontHelpersContext *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,267u,a,1u,output);
}
/* R4FONT.Bindings.Zig.r4font.Context.initTable -> ?R4FONT.Bindings.Zig.r4font.Context */
static inline R4LibrariesSlot R4FontHelpersContext_initTable(uint32_t reserved, const R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1 * p0, R4FontHelpersContext *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,268u,a,1u,output);
}
/* R4FONT.Bindings.Zig.r4font.Context.initHeader -> ?R4FONT.Bindings.Zig.r4font.Context */
static inline R4LibrariesSlot R4FontHelpersContext_initHeader(uint32_t reserved, const R4Lib_r4os_runtime_r4l_InterfaceHeader * p0, R4FontHelpersContext *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,269u,a,1u,output);
}
/* R4FONT.Bindings.Zig.r4font.Context.sniff -> ?R4FONT.Bindings.Zig.r4font.Format */
static inline R4LibrariesSlot R4FontHelpersContext_sniff(uint32_t reserved, const R4FontHelpersContext * p0, const uint8_t * p1, uintptr_t n1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,270u,a,2u,0);
}
/* R4FONT.Bindings.Zig.r4font.Context.createDecoder -> error{BufferTooSmall,DecoderFailure,InvalidArgument,InvalidFaceIndex,InvalidFont,InvalidGlyph,OutOfMemory,TooLarge,UnsupportedFormat}!R4FONT.Bindings.Zig.r4font.Decoder */
static inline R4LibrariesSlot R4FontHelpersContext_createDecoder(uint32_t reserved, const R4FontHelpersContext * p0, const R4LibraryAllocator * p1, uint64_t p2, R4FontHelpersDecoder *output) {
 (void)reserved; R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,271u,a,3u,output);
}
/* R4FONT.Bindings.Zig.r4font.Decoder.deinit -> void */
static inline R4LibrariesSlot R4FontHelpersDecoder_deinit(uint32_t reserved, R4FontHelpersDecoder * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,272u,a,1u,0);
}
/* R4FONT.Bindings.Zig.r4font.Decoder.diagnostics -> R4FONT.Bindings.Zig.r4font.Diagnostics */
static inline R4LibrariesSlot R4FontHelpersDecoder_diagnostics(uint32_t reserved, const R4FontHelpersDecoder * p0, R4FontHelpersDiagnostics *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,273u,a,1u,output);
}
/* R4FONT.Bindings.Zig.r4font.Decoder.openFace -> error{BufferTooSmall,DecoderFailure,InvalidArgument,InvalidFaceIndex,InvalidFont,InvalidGlyph,OutOfMemory,TooLarge,UnsupportedFormat}!R4FONT.Bindings.Zig.r4font.Face */
static inline R4LibrariesSlot R4FontHelpersDecoder_openFace(uint32_t reserved, R4FontHelpersDecoder * p0, const uint8_t * p1, uintptr_t n1, uint32_t p2, R4FontHelpersFace *output) {
 (void)reserved; R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,274u,a,3u,output);
}
/* R4FONT.Bindings.Zig.r4font.Face.deinit -> void */
static inline R4LibrariesSlot R4FontHelpersFace_deinit(uint32_t reserved, R4FontHelpersFace * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,275u,a,1u,0);
}
/* R4FONT.Bindings.Zig.r4font.Face.info -> error{BufferTooSmall,DecoderFailure,InvalidArgument,InvalidFaceIndex,InvalidFont,InvalidGlyph,OutOfMemory,TooLarge,UnsupportedFormat}!R4FONT.Bindings.Zig.r4font.FaceInfo */
static inline R4LibrariesSlot R4FontHelpersFace_info(uint32_t reserved, const R4FontHelpersFace * p0, R4FontHelpersFaceInfo *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,276u,a,1u,output);
}
/* R4FONT.Bindings.Zig.r4font.Face.glyphIndex -> u32 */
static inline R4LibrariesSlot R4FontHelpersFace_glyphIndex(uint32_t reserved, const R4FontHelpersFace * p0, uint32_t p1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,277u,a,2u,0);
}
/* R4FONT.Bindings.Zig.r4font.Face.glyphMetrics -> error{BufferTooSmall,DecoderFailure,InvalidArgument,InvalidFaceIndex,InvalidFont,InvalidGlyph,OutOfMemory,TooLarge,UnsupportedFormat}!R4FONT.Bindings.Zig.r4font.GlyphMetrics */
static inline R4LibrariesSlot R4FontHelpersFace_glyphMetrics(uint32_t reserved, const R4FontHelpersFace * p0, uint32_t p1, R4FontHelpersGlyphMetrics *output) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,278u,a,2u,output);
}
/* R4FONT.Bindings.Zig.r4font.Face.kerning -> error{BufferTooSmall,DecoderFailure,InvalidArgument,InvalidFaceIndex,InvalidFont,InvalidGlyph,OutOfMemory,TooLarge,UnsupportedFormat}![2]i32 */
static inline R4LibrariesSlot R4FontHelpersFace_kerning(uint32_t reserved, const R4FontHelpersFace * p0, uint32_t p1, uint32_t p2, R4Lib_Value218 *output) {
 (void)reserved; R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,279u,a,3u,output);
}
/* R4FONT.Bindings.Zig.r4font.Face.rasterize -> error{BufferTooSmall,DecoderFailure,InvalidArgument,InvalidFaceIndex,InvalidFont,InvalidGlyph,OutOfMemory,TooLarge,UnsupportedFormat}!R4FONT.Bindings.Zig.r4font.Raster */
static inline R4LibrariesSlot R4FontHelpersFace_rasterize(uint32_t reserved, const R4FontHelpersFace * p0, uint32_t p1, uint32_t p2, uint8_t * p3, uintptr_t n3, R4FontHelpersRaster *output) {
 (void)reserved; R4LibrariesSlot a[4]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.ptr=(void *)p3,.length=n3,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,280u,a,4u,output);
}
/* R4FONT.Bindings.Zig.app_fonts.FaceStore.init -> error{BufferTooSmall,DecoderFailure,InvalidArgument,InvalidFaceIndex,InvalidFont,InvalidGlyph,InvalidHandle,OutOfMemory,TooLarge,UnsupportedFormat}!R4FONT.Bindings.Zig.app_fonts.FaceStore */
static inline R4LibrariesSlot R4FontStoreFaceStore_init(uint32_t reserved, const R4FontHelpersContext * p0, const R4LibraryAllocator * p1, const R4FontStoreOptions * p2, R4FontStoreFaceStore *output) {
 (void)reserved; R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,281u,a,3u,output);
}
/* R4FONT.Bindings.Zig.app_fonts.FaceStore.deinit -> void */
static inline R4LibrariesSlot R4FontStoreFaceStore_deinit(uint32_t reserved, R4FontStoreFaceStore * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,282u,a,1u,0);
}
/* R4FONT.Bindings.Zig.app_fonts.FaceStore.openCopy -> error{BufferTooSmall,DecoderFailure,InvalidArgument,InvalidFaceIndex,InvalidFont,InvalidGlyph,InvalidHandle,OutOfMemory,TooLarge,UnsupportedFormat}!R4FONT.Bindings.Zig.app_fonts.FaceHandle */
static inline R4LibrariesSlot R4FontStoreFaceStore_openCopy(uint32_t reserved, R4FontStoreFaceStore * p0, const uint8_t * p1, uintptr_t n1, uint32_t p2, R4FontStoreFaceHandle *output) {
 (void)reserved; R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,283u,a,3u,output);
}
/* R4FONT.Bindings.Zig.app_fonts.FaceStore.release -> error{BufferTooSmall,DecoderFailure,InvalidArgument,InvalidFaceIndex,InvalidFont,InvalidGlyph,InvalidHandle,OutOfMemory,TooLarge,UnsupportedFormat}!void */
static inline R4LibrariesSlot R4FontStoreFaceStore_release(uint32_t reserved, R4FontStoreFaceStore * p0, R4FontStoreFaceHandle * p1) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,284u,a,2u,0);
}
/* R4FONT.Bindings.Zig.app_fonts.FaceStore.info -> error{BufferTooSmall,DecoderFailure,InvalidArgument,InvalidFaceIndex,InvalidFont,InvalidGlyph,InvalidHandle,OutOfMemory,TooLarge,UnsupportedFormat}!R4FONT.Bindings.Zig.r4font.FaceInfo */
static inline R4LibrariesSlot R4FontStoreFaceStore_info(uint32_t reserved, R4FontStoreFaceStore * p0, const R4FontStoreFaceHandle * p1, R4FontHelpersFaceInfo *output) {
 (void)reserved; R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,285u,a,2u,output);
}
/* R4FONT.Bindings.Zig.app_fonts.FaceStore.glyphIndex -> error{BufferTooSmall,DecoderFailure,InvalidArgument,InvalidFaceIndex,InvalidFont,InvalidGlyph,InvalidHandle,OutOfMemory,TooLarge,UnsupportedFormat}!?u32 */
static inline R4LibrariesSlot R4FontStoreFaceStore_glyphIndex(uint32_t reserved, R4FontStoreFaceStore * p0, const R4FontStoreFaceHandle * p1, uint32_t p2) {
 (void)reserved; R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,286u,a,3u,0);
}
/* R4FONT.Bindings.Zig.app_fonts.FaceStore.hasGlyph -> error{BufferTooSmall,DecoderFailure,InvalidArgument,InvalidFaceIndex,InvalidFont,InvalidGlyph,InvalidHandle,OutOfMemory,TooLarge,UnsupportedFormat}!bool */
static inline R4LibrariesSlot R4FontStoreFaceStore_hasGlyph(uint32_t reserved, R4FontStoreFaceStore * p0, const R4FontStoreFaceHandle * p1, uint32_t p2) {
 (void)reserved; R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,287u,a,3u,0);
}
/* R4FONT.Bindings.Zig.app_fonts.FaceStore.faceMetricsAt -> error{BufferTooSmall,DecoderFailure,InvalidArgument,InvalidFaceIndex,InvalidFont,InvalidGlyph,InvalidHandle,OutOfMemory,TooLarge,UnsupportedFormat}!R4FONT.Bindings.Zig.app_fonts.FaceMetrics26_6 */
static inline R4LibrariesSlot R4FontStoreFaceStore_faceMetricsAt(uint32_t reserved, R4FontStoreFaceStore * p0, const R4FontStoreFaceHandle * p1, uint32_t p2, R4FontStoreFaceMetrics26_6 *output) {
 (void)reserved; R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,288u,a,3u,output);
}
/* R4FONT.Bindings.Zig.app_fonts.FaceStore.glyphMetricsAt -> error{BufferTooSmall,DecoderFailure,InvalidArgument,InvalidFaceIndex,InvalidFont,InvalidGlyph,InvalidHandle,OutOfMemory,TooLarge,UnsupportedFormat}!R4FONT.Bindings.Zig.app_fonts.GlyphMetrics26_6 */
static inline R4LibrariesSlot R4FontStoreFaceStore_glyphMetricsAt(uint32_t reserved, R4FontStoreFaceStore * p0, const R4FontStoreFaceHandle * p1, uint32_t p2, uint32_t p3, R4FontStoreGlyphMetrics26_6 *output) {
 (void)reserved; R4LibrariesSlot a[4]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,289u,a,4u,output);
}
/* R4FONT.Bindings.Zig.app_fonts.FaceStore.kerningAt -> error{BufferTooSmall,DecoderFailure,InvalidArgument,InvalidFaceIndex,InvalidFont,InvalidGlyph,InvalidHandle,OutOfMemory,TooLarge,UnsupportedFormat}![2]i32 */
static inline R4LibrariesSlot R4FontStoreFaceStore_kerningAt(uint32_t reserved, R4FontStoreFaceStore * p0, const R4FontStoreFaceHandle * p1, uint32_t p2, uint32_t p3, uint32_t p4, R4Lib_Value218 *output) {
 (void)reserved; R4LibrariesSlot a[5]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,290u,a,5u,output);
}
/* R4FONT.Bindings.Zig.app_fonts.FaceStore.rasterize -> error{BufferTooSmall,DecoderFailure,InvalidArgument,InvalidFaceIndex,InvalidFont,InvalidGlyph,InvalidHandle,OutOfMemory,TooLarge,UnsupportedFormat}!R4FONT.Bindings.Zig.r4font.Raster */
static inline R4LibrariesSlot R4FontStoreFaceStore_rasterize(uint32_t reserved, R4FontStoreFaceStore * p0, const R4FontStoreFaceHandle * p1, uint32_t p2, uint32_t p3, uint8_t * p4, uintptr_t n4, R4FontHelpersRaster *output) {
 (void)reserved; R4LibrariesSlot a[5]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.ptr=(void *)p4,.length=n4,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,291u,a,5u,output);
}
/* R4FONT.Bindings.Zig.app_fonts.FaceStore.rasterizeCached -> error{BufferTooSmall,DecoderFailure,InvalidArgument,InvalidFaceIndex,InvalidFont,InvalidGlyph,InvalidHandle,OutOfMemory,TooLarge,UnsupportedFormat}!R4FONT.Bindings.Zig.app_fonts.BorrowedRaster */
static inline R4LibrariesSlot R4FontStoreFaceStore_rasterizeCached(uint32_t reserved, R4FontStoreFaceStore * p0, const R4FontStoreFaceHandle * p1, uint32_t p2, uint32_t p3, R4FontStoreBorrowedRaster *output) {
 (void)reserved; R4LibrariesSlot a[4]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,292u,a,4u,output);
}
/* R4FONT.Bindings.Zig.app_fonts.FaceStore.cacheStats -> R4FONT.Bindings.Zig.app_fonts.CacheStats */
static inline R4LibrariesSlot R4FontStoreFaceStore_cacheStats(uint32_t reserved, const R4FontStoreFaceStore * p0, R4FontStoreCacheStats *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,293u,a,1u,output);
}
/* R4FONT.Bindings.Zig.app_fonts.FaceStore.diagnostics -> R4FONT.Bindings.Zig.app_fonts.Diagnostics */
static inline R4LibrariesSlot R4FontStoreFaceStore_diagnostics(uint32_t reserved, const R4FontStoreFaceStore * p0, R4FontStoreDiagnostics *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,294u,a,1u,output);
}
/* R4FONT.Bindings.Zig.app_fonts.FaceStore.clearRasterCache -> void */
static inline R4LibrariesSlot R4FontStoreFaceStore_clearRasterCache(uint32_t reserved, R4FontStoreFaceStore * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,295u,a,1u,0);
}
/* Shared.Language.support.Memory.allocator -> mem.Allocator */
static inline R4LibrariesSlot R4LibraryMemory_allocator(uint32_t reserved, R4LibraryMemory * p0, R4LibraryAllocator *output) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,296u,a,1u,output);
}
/* consumer_adapters.Saver.save -> i32 */
static inline R4LibrariesSlot R4StdAdaptersSaver_save(uint32_t reserved, const R4StdAdaptersSaver * p0) {
 (void)reserved; R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesInvoke(R4Libraries_ABI_FINGERPRINT,297u,a,1u,0);
}
static inline R4LibrariesSlot R4Lib_Value0_create(R4Lib_Value0 *output, const R4XStartContext * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,0u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value0_inspect(const R4Lib_Value0 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,0u,(void *)self,0); }
static inline R4LibrariesSlot R4StdTextEncoding_create(R4StdTextEncoding *output, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,2u,a,1u,output); }
static inline R4LibrariesSlot R4StdTextEncoding_inspect(const R4StdTextEncoding *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,2u,(void *)self,0); }
static inline R4LibrariesSlot R4StdTextLineEnding_create(R4StdTextLineEnding *output, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,3u,a,1u,output); }
static inline R4LibrariesSlot R4StdTextLineEnding_inspect(const R4StdTextLineEnding *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,3u,(void *)self,0); }
static inline R4LibrariesSlot R4StdTextBytes_create(R4StdTextBytes *output, const uint8_t * p0, uintptr_t n0) {
 R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,4u,a,1u,output);
}
static inline R4LibrariesSlot R4StdTextBytes_from_fields(R4StdTextBytes *output, const uint8_t * p0, uintptr_t n0) {
 R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,4u,a,1u,output);
}
static inline R4LibrariesSlot R4StdTextBytes_get_bytes(const R4StdTextBytes *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,4u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdTextBytes_set_bytes(R4StdTextBytes *self, const uint8_t * p0, uintptr_t n0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,4u,0u,self,a,0); }
static inline R4LibrariesSlot R4StdTextBytes_inspect(const R4StdTextBytes *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,4u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value5_create(R4Lib_Value5 *output, const uint8_t * p0, uintptr_t n0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,5u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value5_inspect(const R4Lib_Value5 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,5u,(void *)self,0); }
static inline R4LibrariesSlot R4StdTextUtf8Text_create(R4StdTextUtf8Text *output, const uint8_t * p0, uintptr_t n0, uint64_t p1) {
 R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,6u,a,2u,output);
}
static inline R4LibrariesSlot R4StdTextUtf8Text_from_fields(R4StdTextUtf8Text *output, const uint8_t * p0, uintptr_t n0, uint64_t p1) {
 R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,6u,a,2u,output);
}
static inline R4LibrariesSlot R4StdTextUtf8Text_get_bytes(const R4StdTextUtf8Text *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,6u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdTextUtf8Text_set_bytes(R4StdTextUtf8Text *self, const uint8_t * p0, uintptr_t n0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,6u,0u,self,a,0); }
static inline R4LibrariesSlot R4StdTextUtf8Text_get_scalar_count(const R4StdTextUtf8Text *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,6u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdTextUtf8Text_set_scalar_count(R4StdTextUtf8Text *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,6u,1u,self,a,0); }
static inline R4LibrariesSlot R4StdTextUtf8Text_inspect(const R4StdTextUtf8Text *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,6u,(void *)self,0); }
static inline R4LibrariesSlot R4StdTextUiText8_create(R4StdTextUiText8 *output, const uint8_t * p0, uintptr_t n0) {
 R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,7u,a,1u,output);
}
static inline R4LibrariesSlot R4StdTextUiText8_from_fields(R4StdTextUiText8 *output, const uint8_t * p0, uintptr_t n0) {
 R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,7u,a,1u,output);
}
static inline R4LibrariesSlot R4StdTextUiText8_get_bytes(const R4StdTextUiText8 *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,7u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdTextUiText8_set_bytes(R4StdTextUiText8 *self, const uint8_t * p0, uintptr_t n0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,7u,0u,self,a,0); }
static inline R4LibrariesSlot R4StdTextUiText8_inspect(const R4StdTextUiText8 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,7u,(void *)self,0); }
static inline R4LibrariesSlot R4StdTextSystemText_create(R4StdTextSystemText *output, const uint8_t * p0, uintptr_t n0, const uint8_t * p1, uintptr_t n1, uint64_t p2) {
 R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,8u,a,3u,output);
}
static inline R4LibrariesSlot R4StdTextSystemText_from_fields(R4StdTextSystemText *output, const uint8_t * p0, uintptr_t n0, const uint8_t * p1, uintptr_t n1, uint64_t p2) {
 R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,8u,a,3u,output);
}
static inline R4LibrariesSlot R4StdTextSystemText_get_content(const R4StdTextSystemText *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,8u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdTextSystemText_set_content(R4StdTextSystemText *self, const uint8_t * p0, uintptr_t n0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,8u,0u,self,a,0); }
static inline R4LibrariesSlot R4StdTextSystemText_get_source(const R4StdTextSystemText *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,8u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdTextSystemText_set_source(R4StdTextSystemText *self, const uint8_t * p0, uintptr_t n0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,8u,1u,self,a,0); }
static inline R4LibrariesSlot R4StdTextSystemText_get_canonical_length(const R4StdTextSystemText *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,8u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdTextSystemText_set_canonical_length(R4StdTextSystemText *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,8u,2u,self,a,0); }
static inline R4LibrariesSlot R4StdTextSystemText_inspect(const R4StdTextSystemText *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,8u,(void *)self,0); }
static inline R4LibrariesSlot R4StdTextDocumentText_create(R4StdTextDocumentText *output, const uint8_t * p0, uintptr_t n0, uint32_t p1, uint32_t p2) {
 R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,9u,a,3u,output);
}
static inline R4LibrariesSlot R4StdTextDocumentText_from_fields(R4StdTextDocumentText *output, const uint8_t * p0, uintptr_t n0, uint32_t p1, uint32_t p2) {
 R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,9u,a,3u,output);
}
static inline R4LibrariesSlot R4StdTextDocumentText_get_bytes(const R4StdTextDocumentText *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,9u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdTextDocumentText_set_bytes(R4StdTextDocumentText *self, const uint8_t * p0, uintptr_t n0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,9u,0u,self,a,0); }
static inline R4LibrariesSlot R4StdTextDocumentText_get_encoding(const R4StdTextDocumentText *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,9u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdTextDocumentText_set_encoding(R4StdTextDocumentText *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,9u,1u,self,a,0); }
static inline R4LibrariesSlot R4StdTextDocumentText_get_line_ending(const R4StdTextDocumentText *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,9u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdTextDocumentText_set_line_ending(R4StdTextDocumentText *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,9u,2u,self,a,0); }
static inline R4LibrariesSlot R4StdTextDocumentText_inspect(const R4StdTextDocumentText *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,9u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value11_inspect(const R4Lib_Value11 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,11u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value12_inspect(const R4Lib_Value12 *self, R4StdTextUtf8Text *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,12u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value13_inspect(const R4Lib_Value13 *self, R4StdTextSystemText *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,13u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value14_create(R4Lib_Value14 *output, uint8_t * p0, uintptr_t n0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,14u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value14_inspect(const R4Lib_Value14 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,14u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value15_inspect(const R4Lib_Value15 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,15u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value16_inspect(const R4Lib_Value16 *self, R4StdTextDocumentText *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,16u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value17_inspect(const R4Lib_Value17 *self, R4StdTextUiText8 *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,17u,(void *)self,output); }
static inline R4LibrariesSlot R4StdSettingspaths_create(R4StdSettingspaths *output) {
 R4LibrariesSlot a[1]={0};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,18u,a,0u,output);
}
static inline R4LibrariesSlot R4StdSettingspaths_from_fields(R4StdSettingspaths *output) {
 R4LibrariesSlot a[1]={0};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,18u,a,0u,output);
}
static inline R4LibrariesSlot R4StdSettingspaths_inspect(const R4StdSettingspaths *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,18u,(void *)self,0); }
static inline R4LibrariesSlot R4StdSettingsEntry_create(R4StdSettingsEntry *output, const uint8_t * p0, uintptr_t n0, const uint8_t * p1, uintptr_t n1) {
 R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,19u,a,2u,output);
}
static inline R4LibrariesSlot R4StdSettingsEntry_from_fields(R4StdSettingsEntry *output, const uint8_t * p0, uintptr_t n0, const uint8_t * p1, uintptr_t n1) {
 R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,19u,a,2u,output);
}
static inline R4LibrariesSlot R4StdSettingsEntry_get_key(const R4StdSettingsEntry *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,19u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdSettingsEntry_set_key(R4StdSettingsEntry *self, const uint8_t * p0, uintptr_t n0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,19u,0u,self,a,0); }
static inline R4LibrariesSlot R4StdSettingsEntry_get_value(const R4StdSettingsEntry *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,19u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdSettingsEntry_set_value(R4StdSettingsEntry *self, const uint8_t * p0, uintptr_t n0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,19u,1u,self,a,0); }
static inline R4LibrariesSlot R4StdSettingsEntry_inspect(const R4StdSettingsEntry *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,19u,(void *)self,0); }
static inline R4LibrariesSlot R4StdSettingsEntryIterator_create(R4StdSettingsEntryIterator *output, const uint8_t * p0, uintptr_t n0) {
 R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 a[1].flags=R4LIBRARIES_DEFAULT;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,20u,a,2u,output);
}
static inline R4LibrariesSlot R4StdSettingsEntryIterator_from_fields(R4StdSettingsEntryIterator *output, const uint8_t * p0, uintptr_t n0, uint64_t p1) {
 R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,20u,a,2u,output);
}
static inline R4LibrariesSlot R4StdSettingsEntryIterator_get_bytes(const R4StdSettingsEntryIterator *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,20u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdSettingsEntryIterator_set_bytes(R4StdSettingsEntryIterator *self, const uint8_t * p0, uintptr_t n0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,20u,0u,self,a,0); }
static inline R4LibrariesSlot R4StdSettingsEntryIterator_get_cursor(const R4StdSettingsEntryIterator *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,20u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdSettingsEntryIterator_set_cursor(R4StdSettingsEntryIterator *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,20u,1u,self,a,0); }
static inline R4LibrariesSlot R4StdSettingsEntryIterator_inspect(const R4StdSettingsEntryIterator *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,20u,(void *)self,0); }
static inline R4LibrariesSlot R4StdSettingsDocument_create(R4StdSettingsDocument *output, const uint8_t * p0, uintptr_t n0) {
 R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,21u,a,1u,output);
}
static inline R4LibrariesSlot R4StdSettingsDocument_from_fields(R4StdSettingsDocument *output, const uint8_t * p0, uintptr_t n0) {
 R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,21u,a,1u,output);
}
static inline R4LibrariesSlot R4StdSettingsDocument_get_bytes(const R4StdSettingsDocument *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,21u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdSettingsDocument_set_bytes(R4StdSettingsDocument *self, const uint8_t * p0, uintptr_t n0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,21u,0u,self,a,0); }
static inline R4LibrariesSlot R4StdSettingsDocument_inspect(const R4StdSettingsDocument *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,21u,(void *)self,0); }
static inline R4LibrariesSlot R4StdSettingsWriter_create(R4StdSettingsWriter *output, uint8_t * p0, uintptr_t n0) {
 R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 a[1].flags=R4LIBRARIES_DEFAULT;
 a[2].flags=R4LIBRARIES_DEFAULT;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,22u,a,3u,output);
}
static inline R4LibrariesSlot R4StdSettingsWriter_from_fields(R4StdSettingsWriter *output, uint8_t * p0, uintptr_t n0, uint64_t p1, uint32_t p2) {
 R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,22u,a,3u,output);
}
static inline R4LibrariesSlot R4StdSettingsWriter_get_out(const R4StdSettingsWriter *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,22u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdSettingsWriter_set_out(R4StdSettingsWriter *self, uint8_t * p0, uintptr_t n0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,22u,0u,self,a,0); }
static inline R4LibrariesSlot R4StdSettingsWriter_get_len(const R4StdSettingsWriter *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,22u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdSettingsWriter_set_len(R4StdSettingsWriter *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,22u,1u,self,a,0); }
static inline R4LibrariesSlot R4StdSettingsWriter_get_truncated(const R4StdSettingsWriter *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,22u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdSettingsWriter_set_truncated(R4StdSettingsWriter *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,22u,2u,self,a,0); }
static inline R4LibrariesSlot R4StdSettingsWriter_inspect(const R4StdSettingsWriter *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,22u,(void *)self,0); }
static inline R4LibrariesSlot R4StdSettingsWritebackDurability_create(R4StdSettingsWritebackDurability *output, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,23u,a,1u,output); }
static inline R4LibrariesSlot R4StdSettingsWritebackDurability_inspect(const R4StdSettingsWritebackDurability *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,23u,(void *)self,0); }
static inline R4LibrariesSlot R4StdSettingsWritebackAction_create(R4StdSettingsWritebackAction *output, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,24u,a,1u,output); }
static inline R4LibrariesSlot R4StdSettingsWritebackAction_inspect(const R4StdSettingsWritebackAction *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,24u,(void *)self,0); }
static inline R4LibrariesSlot R4StdSettingsWritebackFlush_create(R4StdSettingsWritebackFlush *output) {
 R4LibrariesSlot a[4]={0};
 a[0].flags=R4LIBRARIES_DEFAULT;
 a[1].flags=R4LIBRARIES_DEFAULT;
 a[2].flags=R4LIBRARIES_DEFAULT;
 a[3].flags=R4LIBRARIES_DEFAULT;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,25u,a,4u,output);
}
static inline R4LibrariesSlot R4StdSettingsWritebackFlush_from_fields(R4StdSettingsWritebackFlush *output, uint32_t p0, int32_t p1, uint8_t p2, uint8_t p3) {
 R4LibrariesSlot a[4]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,25u,a,4u,output);
}
static inline R4LibrariesSlot R4StdSettingsWritebackFlush_get_action(const R4StdSettingsWritebackFlush *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,25u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdSettingsWritebackFlush_set_action(R4StdSettingsWritebackFlush *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,25u,0u,self,a,0); }
static inline R4LibrariesSlot R4StdSettingsWritebackFlush_get_result_code(const R4StdSettingsWritebackFlush *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,25u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdSettingsWritebackFlush_set_result_code(R4StdSettingsWritebackFlush *self, int32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,25u,1u,self,a,0); }
static inline R4LibrariesSlot R4StdSettingsWritebackFlush_get_first_failure(const R4StdSettingsWritebackFlush *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,25u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdSettingsWritebackFlush_set_first_failure(R4StdSettingsWritebackFlush *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,25u,2u,self,a,0); }
static inline R4LibrariesSlot R4StdSettingsWritebackFlush_get_recovered_after_failure(const R4StdSettingsWritebackFlush *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,25u,3u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdSettingsWritebackFlush_set_recovered_after_failure(R4StdSettingsWritebackFlush *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,25u,3u,self,a,0); }
static inline R4LibrariesSlot R4StdSettingsWritebackFlush_inspect(const R4StdSettingsWritebackFlush *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,25u,(void *)self,0); }
static inline R4LibrariesSlot R4StdSettingsWritebackPolicy_create(R4StdSettingsWritebackPolicy *output) {
 R4LibrariesSlot a[3]={0};
 a[0].flags=R4LIBRARIES_DEFAULT;
 a[1].flags=R4LIBRARIES_DEFAULT;
 a[2].flags=R4LIBRARIES_DEFAULT;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,26u,a,3u,output);
}
static inline R4LibrariesSlot R4StdSettingsWritebackPolicy_from_fields(R4StdSettingsWritebackPolicy *output, uint32_t p0, uint64_t p1, uint64_t p2) {
 R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,26u,a,3u,output);
}
static inline R4LibrariesSlot R4StdSettingsWritebackPolicy_get_durability(const R4StdSettingsWritebackPolicy *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,26u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdSettingsWritebackPolicy_set_durability(R4StdSettingsWritebackPolicy *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,26u,0u,self,a,0); }
static inline R4LibrariesSlot R4StdSettingsWritebackPolicy_get_save_delay_ticks(const R4StdSettingsWritebackPolicy *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,26u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdSettingsWritebackPolicy_set_save_delay_ticks(R4StdSettingsWritebackPolicy *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,26u,1u,self,a,0); }
static inline R4LibrariesSlot R4StdSettingsWritebackPolicy_get_retry_delay_ticks(const R4StdSettingsWritebackPolicy *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,26u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdSettingsWritebackPolicy_set_retry_delay_ticks(R4StdSettingsWritebackPolicy *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,26u,2u,self,a,0); }
static inline R4LibrariesSlot R4StdSettingsWritebackPolicy_inspect(const R4StdSettingsWritebackPolicy *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,26u,(void *)self,0); }
static inline R4LibrariesSlot R4StdSettingsWriteback_create(R4StdSettingsWriteback *output) {
 R4LibrariesSlot a[6]={0};
 a[0].flags=R4LIBRARIES_DEFAULT;
 a[1].flags=R4LIBRARIES_DEFAULT;
 a[2].flags=R4LIBRARIES_DEFAULT;
 a[3].flags=R4LIBRARIES_DEFAULT;
 a[4].flags=R4LIBRARIES_DEFAULT;
 a[5].flags=R4LIBRARIES_DEFAULT;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,27u,a,6u,output);
}
static inline R4LibrariesSlot R4StdSettingsWriteback_from_fields(R4StdSettingsWriteback *output, const R4StdSettingsWritebackPolicy * p0, uint8_t p1, uint64_t p2, uint32_t p3, int32_t p4, uint8_t p5) {
 R4LibrariesSlot a[6]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,27u,a,6u,output);
}
static inline R4LibrariesSlot R4StdSettingsWriteback_get_policy(const R4StdSettingsWriteback *self, R4StdSettingsWritebackPolicy *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,27u,0u,(void *)self,0,output); }
static inline R4LibrariesSlot R4StdSettingsWriteback_set_policy(R4StdSettingsWriteback *self, const R4StdSettingsWritebackPolicy * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,27u,0u,self,a,0); }
static inline R4LibrariesSlot R4StdSettingsWriteback_get_dirty(const R4StdSettingsWriteback *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,27u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdSettingsWriteback_set_dirty(R4StdSettingsWriteback *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,27u,1u,self,a,0); }
static inline R4LibrariesSlot R4StdSettingsWriteback_get_due_tick(const R4StdSettingsWriteback *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,27u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdSettingsWriteback_set_due_tick(R4StdSettingsWriteback *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,27u,2u,self,a,0); }
static inline R4LibrariesSlot R4StdSettingsWriteback_get_failures(const R4StdSettingsWriteback *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,27u,3u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdSettingsWriteback_set_failures(R4StdSettingsWriteback *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,27u,3u,self,a,0); }
static inline R4LibrariesSlot R4StdSettingsWriteback_get_last_result(const R4StdSettingsWriteback *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,27u,4u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdSettingsWriteback_set_last_result(R4StdSettingsWriteback *self, int32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,27u,4u,self,a,0); }
static inline R4LibrariesSlot R4StdSettingsWriteback_get_failure_reported(const R4StdSettingsWriteback *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,27u,5u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdSettingsWriteback_set_failure_reported(R4StdSettingsWriteback *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,27u,5u,self,a,0); }
static inline R4LibrariesSlot R4StdSettingsWriteback_inspect(const R4StdSettingsWriteback *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,27u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value28_create(R4Lib_Value28 *output, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,28u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value28_inspect(const R4Lib_Value28 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,28u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value29_create(R4Lib_Value29 *output, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,29u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value29_inspect(const R4Lib_Value29 *self, R4StdSettingsEntry *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,29u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value30_create(R4Lib_Value30 *output, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,30u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value30_inspect(const R4Lib_Value30 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,30u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value31_create(R4Lib_Value31 *output, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,31u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value31_inspect(const R4Lib_Value31 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,31u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value32_create(R4Lib_Value32 *output, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,32u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value32_inspect(const R4Lib_Value32 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,32u,(void *)self,0); }
static inline R4LibrariesSlot R4StdDateDate_create(R4StdDateDate *output) {
 R4LibrariesSlot a[3]={0};
 a[0].flags=R4LIBRARIES_DEFAULT;
 a[1].flags=R4LIBRARIES_DEFAULT;
 a[2].flags=R4LIBRARIES_DEFAULT;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,33u,a,3u,output);
}
static inline R4LibrariesSlot R4StdDateDate_from_fields(R4StdDateDate *output, uint16_t p0, uint8_t p1, uint8_t p2) {
 R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,33u,a,3u,output);
}
static inline R4LibrariesSlot R4StdDateDate_get_year(const R4StdDateDate *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,33u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdDateDate_set_year(R4StdDateDate *self, uint16_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,33u,0u,self,a,0); }
static inline R4LibrariesSlot R4StdDateDate_get_month(const R4StdDateDate *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,33u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdDateDate_set_month(R4StdDateDate *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,33u,1u,self,a,0); }
static inline R4LibrariesSlot R4StdDateDate_get_day(const R4StdDateDate *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,33u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdDateDate_set_day(R4StdDateDate *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,33u,2u,self,a,0); }
static inline R4LibrariesSlot R4StdDateDate_inspect(const R4StdDateDate *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,33u,(void *)self,0); }
static inline R4LibrariesSlot R4StdDateTimeOfDay_create(R4StdDateTimeOfDay *output) {
 R4LibrariesSlot a[3]={0};
 a[0].flags=R4LIBRARIES_DEFAULT;
 a[1].flags=R4LIBRARIES_DEFAULT;
 a[2].flags=R4LIBRARIES_DEFAULT;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,34u,a,3u,output);
}
static inline R4LibrariesSlot R4StdDateTimeOfDay_from_fields(R4StdDateTimeOfDay *output, uint8_t p0, uint8_t p1, uint8_t p2) {
 R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,34u,a,3u,output);
}
static inline R4LibrariesSlot R4StdDateTimeOfDay_get_hour(const R4StdDateTimeOfDay *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,34u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdDateTimeOfDay_set_hour(R4StdDateTimeOfDay *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,34u,0u,self,a,0); }
static inline R4LibrariesSlot R4StdDateTimeOfDay_get_minute(const R4StdDateTimeOfDay *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,34u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdDateTimeOfDay_set_minute(R4StdDateTimeOfDay *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,34u,1u,self,a,0); }
static inline R4LibrariesSlot R4StdDateTimeOfDay_get_second(const R4StdDateTimeOfDay *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,34u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdDateTimeOfDay_set_second(R4StdDateTimeOfDay *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,34u,2u,self,a,0); }
static inline R4LibrariesSlot R4StdDateTimeOfDay_inspect(const R4StdDateTimeOfDay *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,34u,(void *)self,0); }
static inline R4LibrariesSlot R4StdDateDateTime_create(R4StdDateDateTime *output) {
 R4LibrariesSlot a[2]={0};
 a[0].flags=R4LIBRARIES_DEFAULT;
 a[1].flags=R4LIBRARIES_DEFAULT;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,35u,a,2u,output);
}
static inline R4LibrariesSlot R4StdDateDateTime_from_fields(R4StdDateDateTime *output, const R4StdDateDate * p0, const R4StdDateTimeOfDay * p1) {
 R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,35u,a,2u,output);
}
static inline R4LibrariesSlot R4StdDateDateTime_get_date(const R4StdDateDateTime *self, R4StdDateDate *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,35u,0u,(void *)self,0,output); }
static inline R4LibrariesSlot R4StdDateDateTime_set_date(R4StdDateDateTime *self, const R4StdDateDate * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,35u,0u,self,a,0); }
static inline R4LibrariesSlot R4StdDateDateTime_get_time(const R4StdDateDateTime *self, R4StdDateTimeOfDay *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,35u,1u,(void *)self,0,output); }
static inline R4LibrariesSlot R4StdDateDateTime_set_time(R4StdDateDateTime *self, const R4StdDateTimeOfDay * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,35u,1u,self,a,0); }
static inline R4LibrariesSlot R4StdDateDateTime_inspect(const R4StdDateDateTime *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,35u,(void *)self,0); }
static inline R4LibrariesSlot R4StdDateWeekday_create(R4StdDateWeekday *output, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,36u,a,1u,output); }
static inline R4LibrariesSlot R4StdDateWeekday_inspect(const R4StdDateWeekday *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,36u,(void *)self,0); }
static inline R4LibrariesSlot R4StdDateShiftedDateTime_create(R4StdDateShiftedDateTime *output, const R4StdDateDateTime * p0, int32_t p1) {
 R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,37u,a,2u,output);
}
static inline R4LibrariesSlot R4StdDateShiftedDateTime_from_fields(R4StdDateShiftedDateTime *output, const R4StdDateDateTime * p0, int32_t p1) {
 R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,37u,a,2u,output);
}
static inline R4LibrariesSlot R4StdDateShiftedDateTime_get_value(const R4StdDateShiftedDateTime *self, R4StdDateDateTime *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,37u,0u,(void *)self,0,output); }
static inline R4LibrariesSlot R4StdDateShiftedDateTime_set_value(R4StdDateShiftedDateTime *self, const R4StdDateDateTime * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,37u,0u,self,a,0); }
static inline R4LibrariesSlot R4StdDateShiftedDateTime_get_day_delta(const R4StdDateShiftedDateTime *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,37u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdDateShiftedDateTime_set_day_delta(R4StdDateShiftedDateTime *self, int32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,37u,1u,self,a,0); }
static inline R4LibrariesSlot R4StdDateShiftedDateTime_inspect(const R4StdDateShiftedDateTime *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,37u,(void *)self,0); }
static inline R4LibrariesSlot R4StdDateFatDateTime_create(R4StdDateFatDateTime *output, uint16_t p0, uint16_t p1) {
 R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,38u,a,2u,output);
}
static inline R4LibrariesSlot R4StdDateFatDateTime_from_fields(R4StdDateFatDateTime *output, uint16_t p0, uint16_t p1) {
 R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,38u,a,2u,output);
}
static inline R4LibrariesSlot R4StdDateFatDateTime_get_date(const R4StdDateFatDateTime *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,38u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdDateFatDateTime_set_date(R4StdDateFatDateTime *self, uint16_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,38u,0u,self,a,0); }
static inline R4LibrariesSlot R4StdDateFatDateTime_get_time(const R4StdDateFatDateTime *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,38u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdDateFatDateTime_set_time(R4StdDateFatDateTime *self, uint16_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,38u,1u,self,a,0); }
static inline R4LibrariesSlot R4StdDateFatDateTime_inspect(const R4StdDateFatDateTime *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,38u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value39_create(R4Lib_Value39 *output, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,39u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value39_inspect(const R4Lib_Value39 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,39u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value40_create(R4Lib_Value40 *output, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,40u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value40_inspect(const R4Lib_Value40 *self, R4StdDateShiftedDateTime *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,40u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value42_create(R4Lib_Value42 *output, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,42u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value42_inspect(const R4Lib_Value42 *self, R4StdDateDateTime *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,42u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value43_create(R4Lib_Value43 *output, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,43u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value43_inspect(const R4Lib_Value43 *self, R4TimeState *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,43u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value44_create(R4Lib_Value44 *output, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,44u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value44_inspect(const R4Lib_Value44 *self, R4UtcTime *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,44u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value46_create(R4Lib_Value46 *output, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,46u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value46_inspect(const R4Lib_Value46 *self, R4StdDateDate *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,46u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value47_create(R4Lib_Value47 *output, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,47u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value47_inspect(const R4Lib_Value47 *self, R4StdDateTimeOfDay *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,47u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdDateTime_create(R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdDateTime *output, uint16_t p0, uint8_t p1, uint8_t p2, uint8_t p3, uint8_t p4, uint8_t p5, uint8_t p6) {
 R4LibrariesSlot a[7]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,48u,a,7u,output);
}
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdDateTime_from_fields(R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdDateTime *output, uint16_t p0, uint8_t p1, uint8_t p2, uint8_t p3, uint8_t p4, uint8_t p5, uint8_t p6) {
 R4LibrariesSlot a[7]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,48u,a,7u,output);
}
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdDateTime_get_year(const R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdDateTime *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,48u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdDateTime_set_year(R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdDateTime *self, uint16_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,48u,0u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdDateTime_get_month(const R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdDateTime *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,48u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdDateTime_set_month(R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdDateTime *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,48u,1u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdDateTime_get_day(const R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdDateTime *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,48u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdDateTime_set_day(R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdDateTime *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,48u,2u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdDateTime_get_hour(const R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdDateTime *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,48u,3u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdDateTime_set_hour(R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdDateTime *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,48u,3u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdDateTime_get_minute(const R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdDateTime *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,48u,4u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdDateTime_set_minute(R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdDateTime *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,48u,4u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdDateTime_get_second(const R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdDateTime *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,48u,5u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdDateTime_set_second(R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdDateTime *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,48u,5u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdDateTime_get_reserved(const R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdDateTime *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,48u,6u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdDateTime_set_reserved(R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdDateTime *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,48u,6u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdDateTime_inspect(const R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdDateTime *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,48u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdTimeState_create(R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdTimeState *output, uint16_t p0, uint8_t p1, uint8_t p2, uint8_t p3, uint8_t p4, uint8_t p5, uint8_t p6, uint32_t p7, uint32_t p8) {
 R4LibrariesSlot a[9]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4LIBRARIES_PRESENT};
 a[7] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p7,.flags=R4LIBRARIES_PRESENT};
 a[8] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p8,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,49u,a,9u,output);
}
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdTimeState_from_fields(R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdTimeState *output, uint16_t p0, uint8_t p1, uint8_t p2, uint8_t p3, uint8_t p4, uint8_t p5, uint8_t p6, uint32_t p7, uint32_t p8) {
 R4LibrariesSlot a[9]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4LIBRARIES_PRESENT};
 a[7] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p7,.flags=R4LIBRARIES_PRESENT};
 a[8] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p8,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,49u,a,9u,output);
}
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdTimeState_get_year(const R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdTimeState *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,49u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdTimeState_set_year(R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdTimeState *self, uint16_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,49u,0u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdTimeState_get_month(const R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdTimeState *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,49u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdTimeState_set_month(R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdTimeState *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,49u,1u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdTimeState_get_day(const R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdTimeState *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,49u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdTimeState_set_day(R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdTimeState *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,49u,2u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdTimeState_get_hour(const R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdTimeState *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,49u,3u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdTimeState_set_hour(R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdTimeState *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,49u,3u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdTimeState_get_minute(const R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdTimeState *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,49u,4u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdTimeState_set_minute(R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdTimeState *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,49u,4u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdTimeState_get_second(const R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdTimeState *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,49u,5u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdTimeState_set_second(R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdTimeState *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,49u,5u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdTimeState_get_weekday(const R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdTimeState *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,49u,6u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdTimeState_set_weekday(R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdTimeState *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,49u,6u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdTimeState_get_seconds_since_midnight(const R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdTimeState *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,49u,7u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdTimeState_set_seconds_since_midnight(R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdTimeState *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,49u,7u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdTimeState_get_valid(const R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdTimeState *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,49u,8u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdTimeState_set_valid(R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdTimeState *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,49u,8u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdTimeState_inspect(const R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdTimeState *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,49u,(void *)self,0); }
static inline R4LibrariesSlot R4StdTimeZone_create(R4StdTimeZone *output) {
 R4LibrariesSlot a[6]={0};
 a[0].flags=R4LIBRARIES_DEFAULT;
 a[1].flags=R4LIBRARIES_DEFAULT;
 a[2].flags=R4LIBRARIES_DEFAULT;
 a[3].flags=R4LIBRARIES_DEFAULT;
 a[4].flags=R4LIBRARIES_DEFAULT;
 a[5].flags=R4LIBRARIES_DEFAULT;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,50u,a,6u,output);
}
static inline R4LibrariesSlot R4StdTimeZone_from_fields(R4StdTimeZone *output, const uint8_t * p0, uintptr_t n0, const uint8_t * p1, uintptr_t n1, int16_t p2, int16_t p3, int16_t p4, uint8_t p5) {
 R4LibrariesSlot a[6]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,50u,a,6u,output);
}
static inline R4LibrariesSlot R4StdTimeZone_get_id(const R4StdTimeZone *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,50u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdTimeZone_set_id(R4StdTimeZone *self, const uint8_t * p0, uintptr_t n0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,50u,0u,self,a,0); }
static inline R4LibrariesSlot R4StdTimeZone_get_label(const R4StdTimeZone *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,50u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdTimeZone_set_label(R4StdTimeZone *self, const uint8_t * p0, uintptr_t n0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,50u,1u,self,a,0); }
static inline R4LibrariesSlot R4StdTimeZone_get_offset_minutes(const R4StdTimeZone *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,50u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdTimeZone_set_offset_minutes(R4StdTimeZone *self, int16_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,50u,2u,self,a,0); }
static inline R4LibrariesSlot R4StdTimeZone_get_standard_offset_minutes(const R4StdTimeZone *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,50u,3u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdTimeZone_set_standard_offset_minutes(R4StdTimeZone *self, int16_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,50u,3u,self,a,0); }
static inline R4LibrariesSlot R4StdTimeZone_get_daylight_offset_minutes(const R4StdTimeZone *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,50u,4u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdTimeZone_set_daylight_offset_minutes(R4StdTimeZone *self, int16_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,50u,4u,self,a,0); }
static inline R4LibrariesSlot R4StdTimeZone_get_uses_daylight_time(const R4StdTimeZone *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,50u,5u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdTimeZone_set_uses_daylight_time(R4StdTimeZone *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,50u,5u,self,a,0); }
static inline R4LibrariesSlot R4StdTimeZone_inspect(const R4StdTimeZone *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,50u,(void *)self,0); }
static inline R4LibrariesSlot R4StdTimeClockTime_create(R4StdTimeClockTime *output, uint8_t p0, uint8_t p1, uint8_t p2) {
 R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,51u,a,3u,output);
}
static inline R4LibrariesSlot R4StdTimeClockTime_from_fields(R4StdTimeClockTime *output, uint8_t p0, uint8_t p1, uint8_t p2) {
 R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,51u,a,3u,output);
}
static inline R4LibrariesSlot R4StdTimeClockTime_get_hours(const R4StdTimeClockTime *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,51u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdTimeClockTime_set_hours(R4StdTimeClockTime *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,51u,0u,self,a,0); }
static inline R4LibrariesSlot R4StdTimeClockTime_get_minutes(const R4StdTimeClockTime *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,51u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdTimeClockTime_set_minutes(R4StdTimeClockTime *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,51u,1u,self,a,0); }
static inline R4LibrariesSlot R4StdTimeClockTime_get_seconds(const R4StdTimeClockTime *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,51u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdTimeClockTime_set_seconds(R4StdTimeClockTime *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,51u,2u,self,a,0); }
static inline R4LibrariesSlot R4StdTimeClockTime_inspect(const R4StdTimeClockTime *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,51u,(void *)self,0); }
static inline R4LibrariesSlot R4StdTimeHelpersConfig_create(R4StdTimeHelpersConfig *output) {
 R4LibrariesSlot a[2]={0};
 a[0].flags=R4LIBRARIES_DEFAULT;
 a[1].flags=R4LIBRARIES_DEFAULT;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,52u,a,2u,output);
}
static inline R4LibrariesSlot R4StdTimeHelpersConfig_from_fields(R4StdTimeHelpersConfig *output, uint64_t p0, uint32_t p1) {
 R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,52u,a,2u,output);
}
static inline R4LibrariesSlot R4StdTimeHelpersConfig_get_timezone_index(const R4StdTimeHelpersConfig *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,52u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdTimeHelpersConfig_set_timezone_index(R4StdTimeHelpersConfig *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,52u,0u,self,a,0); }
static inline R4LibrariesSlot R4StdTimeHelpersConfig_get_clock_format(const R4StdTimeHelpersConfig *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,52u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdTimeHelpersConfig_set_clock_format(R4StdTimeHelpersConfig *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,52u,1u,self,a,0); }
static inline R4LibrariesSlot R4StdTimeHelpersConfig_inspect(const R4StdTimeHelpersConfig *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,52u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value53_create(R4Lib_Value53 *output, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,53u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value53_inspect(const R4Lib_Value53 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,53u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value54_inspect(const R4Lib_Value54 *self, R4Lib_r4os_path_FilePath *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,54u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value56_inspect(const R4Lib_Value56 *self, R4Lib_r4os_path_AbsoluteFilePath *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,56u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value58_inspect(const R4Lib_Value58 *self, R4Lib_r4os_path_RelativeFilePath *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,58u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value60_inspect(const R4Lib_Value60 *self, R4Lib_r4os_path_RegistryPath *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,60u,(void *)self,output); }
static inline R4LibrariesSlot R4StdCodecCodepage_create(R4StdCodecCodepage *output, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,62u,a,1u,output); }
static inline R4LibrariesSlot R4StdCodecCodepage_inspect(const R4StdCodecCodepage *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,62u,(void *)self,0); }
static inline R4LibrariesSlot R4StdCodecMode_create(R4StdCodecMode *output, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,63u,a,1u,output); }
static inline R4LibrariesSlot R4StdCodecMode_inspect(const R4StdCodecMode *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,63u,(void *)self,0); }
static inline R4LibrariesSlot R4StdCodecScalar_create(R4StdCodecScalar *output, uint32_t p0, uint64_t p1) {
 R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,64u,a,2u,output);
}
static inline R4LibrariesSlot R4StdCodecScalar_from_fields(R4StdCodecScalar *output, uint32_t p0, uint64_t p1) {
 R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,64u,a,2u,output);
}
static inline R4LibrariesSlot R4StdCodecScalar_get_value(const R4StdCodecScalar *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,64u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdCodecScalar_set_value(R4StdCodecScalar *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,64u,0u,self,a,0); }
static inline R4LibrariesSlot R4StdCodecScalar_get_byte_length(const R4StdCodecScalar *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,64u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdCodecScalar_set_byte_length(R4StdCodecScalar *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,64u,1u,self,a,0); }
static inline R4LibrariesSlot R4StdCodecScalar_inspect(const R4StdCodecScalar *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,64u,(void *)self,0); }
#define R4StdCodecDecoded_TAG_complete 0u
#define R4StdCodecDecoded_TAG_incomplete 1u
static inline R4LibrariesSlot R4StdCodecDecoded_get_complete(const R4StdCodecDecoded *self, R4StdCodecScalar *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,65u,0u,(void *)self,0,output); }
static inline R4LibrariesSlot R4StdCodecDecoded_set_complete(R4StdCodecDecoded *self, const R4StdCodecScalar * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,65u,0u,self,a,0); }
static inline R4LibrariesSlot R4StdCodecDecoded_get_incomplete(const R4StdCodecDecoded *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,65u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdCodecDecoded_set_incomplete(R4StdCodecDecoded *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,65u,1u,self,a,0); }
static inline R4LibrariesSlot R4StdCodecDecoded_inspect(const R4StdCodecDecoded *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,65u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib__typeInfo_R4STD_Bindings_Zig_codec_Decoded____union__tag_type___create(R4Lib__typeInfo_R4STD_Bindings_Zig_codec_Decoded____union__tag_type__ *output, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,66u,a,1u,output); }
static inline R4LibrariesSlot R4Lib__typeInfo_R4STD_Bindings_Zig_codec_Decoded____union__tag_type___inspect(const R4Lib__typeInfo_R4STD_Bindings_Zig_codec_Decoded____union__tag_type__ *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,66u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value67_inspect(const R4Lib_Value67 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,67u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value68_inspect(const R4Lib_Value68 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,68u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value69_inspect(const R4Lib_Value69 *self, R4StdCodecDecoded *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,69u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value70_inspect(const R4Lib_Value70 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,70u,(void *)self,0); }
static inline R4LibrariesSlot R4StdCodecStream_create(R4StdCodecStream *output) {
 R4LibrariesSlot a[1]={0};
 a[0].flags=R4LIBRARIES_DEFAULT;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,71u,a,1u,output);
}
static inline R4LibrariesSlot R4StdCodecStream_from_fields(R4StdCodecStream *output, const R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdUtf8State * p0) {
 R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,71u,a,1u,output);
}
static inline R4LibrariesSlot R4StdCodecStream_get_state(const R4StdCodecStream *self, R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdUtf8State *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,71u,0u,(void *)self,0,output); }
static inline R4LibrariesSlot R4StdCodecStream_set_state(R4StdCodecStream *self, const R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdUtf8State * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,71u,0u,self,a,0); }
static inline R4LibrariesSlot R4StdCodecStream_inspect(const R4StdCodecStream *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,71u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdUtf8State_create(R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdUtf8State *output, uint32_t p0, uint32_t p1, uint32_t p2, uint32_t p3) {
 R4LibrariesSlot a[4]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,72u,a,4u,output);
}
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdUtf8State_from_fields(R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdUtf8State *output, uint32_t p0, uint32_t p1, uint32_t p2, uint32_t p3) {
 R4LibrariesSlot a[4]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,72u,a,4u,output);
}
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdUtf8State_get_packed_bytes(const R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdUtf8State *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,72u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdUtf8State_set_packed_bytes(R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdUtf8State *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,72u,0u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdUtf8State_get_length(const R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdUtf8State *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,72u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdUtf8State_set_length(R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdUtf8State *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,72u,1u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdUtf8State_get_reserved0(const R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdUtf8State *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,72u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdUtf8State_set_reserved0(R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdUtf8State *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,72u,2u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdUtf8State_get_reserved1(const R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdUtf8State *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,72u,3u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdUtf8State_set_reserved1(R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdUtf8State *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,72u,3u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdUtf8State_inspect(const R4Lib_R4STD_Bindings_Zig_r4std_abi_R4StdUtf8State *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,72u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value73_inspect(const R4Lib_Value73 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,73u,(void *)self,0); }
static inline R4LibrariesSlot R4StdGraphemeState_create(R4StdGraphemeState *output) {
 R4LibrariesSlot a[5]={0};
 a[0].flags=R4LIBRARIES_DEFAULT;
 a[1].flags=R4LIBRARIES_DEFAULT;
 a[2].flags=R4LIBRARIES_DEFAULT;
 a[3].flags=R4LIBRARIES_DEFAULT;
 a[4].flags=R4LIBRARIES_DEFAULT;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,74u,a,5u,output);
}
static inline R4LibrariesSlot R4StdGraphemeState_from_fields(R4StdGraphemeState *output, R4LibrariesSlot p0, uint8_t p1, uint8_t p2, uint8_t p3, uint32_t p4) {
 R4LibrariesSlot a[5]={0};
 a[0] = p0;
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,74u,a,5u,output);
}
static inline R4LibrariesSlot R4StdGraphemeState_get_previous(const R4StdGraphemeState *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,74u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdGraphemeState_set_previous(R4StdGraphemeState *self, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,74u,0u,self,a,0); }
static inline R4LibrariesSlot R4StdGraphemeState_get_ri_odd(const R4StdGraphemeState *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,74u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdGraphemeState_set_ri_odd(R4StdGraphemeState *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,74u,1u,self,a,0); }
static inline R4LibrariesSlot R4StdGraphemeState_get_ep_extend(const R4StdGraphemeState *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,74u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdGraphemeState_set_ep_extend(R4StdGraphemeState *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,74u,2u,self,a,0); }
static inline R4LibrariesSlot R4StdGraphemeState_get_zwj_after_ep(const R4StdGraphemeState *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,74u,3u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdGraphemeState_set_zwj_after_ep(R4StdGraphemeState *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,74u,3u,self,a,0); }
static inline R4LibrariesSlot R4StdGraphemeState_get_indic(const R4StdGraphemeState *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,74u,4u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdGraphemeState_set_indic(R4StdGraphemeState *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,74u,4u,self,a,0); }
static inline R4LibrariesSlot R4StdGraphemeState_inspect(const R4StdGraphemeState *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,74u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value75_create(R4Lib_Value75 *output, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,75u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value75_inspect(const R4Lib_Value75 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,75u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_grapheme_properties_Gcb_create(R4Lib_R4STD_Bindings_Zig_grapheme_properties_Gcb *output, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,76u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_grapheme_properties_Gcb_inspect(const R4Lib_R4STD_Bindings_Zig_grapheme_properties_Gcb *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,76u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value77_create(R4Lib_Value77 *output, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,77u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value77_inspect(const R4Lib_Value77 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,77u,(void *)self,0); }
static inline R4LibrariesSlot R4StdGraphemeRange_create(R4StdGraphemeRange *output, uint64_t p0, uint64_t p1) {
 R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,78u,a,2u,output);
}
static inline R4LibrariesSlot R4StdGraphemeRange_from_fields(R4StdGraphemeRange *output, uint64_t p0, uint64_t p1) {
 R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,78u,a,2u,output);
}
static inline R4LibrariesSlot R4StdGraphemeRange_get_start(const R4StdGraphemeRange *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,78u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdGraphemeRange_set_start(R4StdGraphemeRange *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,78u,0u,self,a,0); }
static inline R4LibrariesSlot R4StdGraphemeRange_get_end(const R4StdGraphemeRange *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,78u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdGraphemeRange_set_end(R4StdGraphemeRange *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,78u,1u,self,a,0); }
static inline R4LibrariesSlot R4StdGraphemeRange_inspect(const R4StdGraphemeRange *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,78u,(void *)self,0); }
static inline R4LibrariesSlot R4StdGraphemeIterator_create(R4StdGraphemeIterator *output, const uint8_t * p0, uintptr_t n0) {
 R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 a[1].flags=R4LIBRARIES_DEFAULT;
 a[2].flags=R4LIBRARIES_DEFAULT;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,79u,a,3u,output);
}
static inline R4LibrariesSlot R4StdGraphemeIterator_from_fields(R4StdGraphemeIterator *output, const uint8_t * p0, uintptr_t n0, uint64_t p1, const R4StdGraphemeState * p2) {
 R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,79u,a,3u,output);
}
static inline R4LibrariesSlot R4StdGraphemeIterator_get_bytes(const R4StdGraphemeIterator *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,79u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdGraphemeIterator_set_bytes(R4StdGraphemeIterator *self, const uint8_t * p0, uintptr_t n0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,79u,0u,self,a,0); }
static inline R4LibrariesSlot R4StdGraphemeIterator_get_offset(const R4StdGraphemeIterator *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,79u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdGraphemeIterator_set_offset(R4StdGraphemeIterator *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,79u,1u,self,a,0); }
static inline R4LibrariesSlot R4StdGraphemeIterator_get_state(const R4StdGraphemeIterator *self, R4StdGraphemeState *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,79u,2u,(void *)self,0,output); }
static inline R4LibrariesSlot R4StdGraphemeIterator_set_state(R4StdGraphemeIterator *self, const R4StdGraphemeState * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,79u,2u,self,a,0); }
static inline R4LibrariesSlot R4StdGraphemeIterator_inspect(const R4StdGraphemeIterator *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,79u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value80_inspect(const R4Lib_Value80 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,80u,(void *)self,0); }
static inline R4LibrariesSlot R4StdGraphemeStream_create(R4StdGraphemeStream *output) {
 R4LibrariesSlot a[5]={0};
 a[0].flags=R4LIBRARIES_DEFAULT;
 a[1].flags=R4LIBRARIES_DEFAULT;
 a[2].flags=R4LIBRARIES_DEFAULT;
 a[3].flags=R4LIBRARIES_DEFAULT;
 a[4].flags=R4LIBRARIES_DEFAULT;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,81u,a,5u,output);
}
static inline R4LibrariesSlot R4StdGraphemeStream_from_fields(R4StdGraphemeStream *output, const R4StdGraphemeState * p0, const R4Lib_Value82 * p1, uint64_t p2, uint64_t p3, uint8_t p4) {
 R4LibrariesSlot a[5]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,81u,a,5u,output);
}
static inline R4LibrariesSlot R4StdGraphemeStream_get_state(const R4StdGraphemeStream *self, R4StdGraphemeState *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,81u,0u,(void *)self,0,output); }
static inline R4LibrariesSlot R4StdGraphemeStream_set_state(R4StdGraphemeStream *self, const R4StdGraphemeState * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,81u,0u,self,a,0); }
static inline R4LibrariesSlot R4StdGraphemeStream_get_pending(const R4StdGraphemeStream *self, R4Lib_Value82 *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,81u,1u,(void *)self,0,output); }
static inline R4LibrariesSlot R4StdGraphemeStream_set_pending(R4StdGraphemeStream *self, const R4Lib_Value82 * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,81u,1u,self,a,0); }
static inline R4LibrariesSlot R4StdGraphemeStream_get_len(const R4StdGraphemeStream *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,81u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdGraphemeStream_set_len(R4StdGraphemeStream *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,81u,2u,self,a,0); }
static inline R4LibrariesSlot R4StdGraphemeStream_get_offset(const R4StdGraphemeStream *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,81u,3u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdGraphemeStream_set_offset(R4StdGraphemeStream *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,81u,3u,self,a,0); }
static inline R4LibrariesSlot R4StdGraphemeStream_get_failed(const R4StdGraphemeStream *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,81u,4u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdGraphemeStream_set_failed(R4StdGraphemeStream *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,81u,4u,self,a,0); }
static inline R4LibrariesSlot R4StdGraphemeStream_inspect(const R4StdGraphemeStream *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,81u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value82_create(R4Lib_Value82 *output, const R4Lib_Value82 * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,82u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value82_inspect(const R4Lib_Value82 *self, R4Lib_Value82 *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,82u,(void *)self,output); }
static inline R4LibrariesSlot R4StdConsoleTextScalar_create(R4StdConsoleTextScalar *output, uint32_t p0, uint64_t p1) {
 R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,83u,a,2u,output);
}
static inline R4LibrariesSlot R4StdConsoleTextScalar_from_fields(R4StdConsoleTextScalar *output, uint32_t p0, uint64_t p1) {
 R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,83u,a,2u,output);
}
static inline R4LibrariesSlot R4StdConsoleTextScalar_get_value(const R4StdConsoleTextScalar *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,83u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdConsoleTextScalar_set_value(R4StdConsoleTextScalar *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,83u,0u,self,a,0); }
static inline R4LibrariesSlot R4StdConsoleTextScalar_get_len(const R4StdConsoleTextScalar *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,83u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdConsoleTextScalar_set_len(R4StdConsoleTextScalar *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,83u,1u,self,a,0); }
static inline R4LibrariesSlot R4StdConsoleTextScalar_inspect(const R4StdConsoleTextScalar *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,83u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value84_inspect(const R4Lib_Value84 *self, R4StdConsoleTextScalar *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,84u,(void *)self,output); }
static inline R4LibrariesSlot R4StdShortcutForeignEntry_create(R4StdShortcutForeignEntry *output) {
 R4LibrariesSlot a[2]={0};
 a[0].flags=R4LIBRARIES_DEFAULT;
 a[1].flags=R4LIBRARIES_DEFAULT;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,85u,a,2u,output);
}
static inline R4LibrariesSlot R4StdShortcutForeignEntry_from_fields(R4StdShortcutForeignEntry *output, const R4Lib_Value86 * p0, const R4Lib_Value87 * p1) {
 R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,85u,a,2u,output);
}
static inline R4LibrariesSlot R4StdShortcutForeignEntry_get_key(const R4StdShortcutForeignEntry *self, R4Lib_Value86 *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,85u,0u,(void *)self,0,output); }
static inline R4LibrariesSlot R4StdShortcutForeignEntry_set_key(R4StdShortcutForeignEntry *self, const R4Lib_Value86 * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,85u,0u,self,a,0); }
static inline R4LibrariesSlot R4StdShortcutForeignEntry_get_value(const R4StdShortcutForeignEntry *self, R4Lib_Value87 *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,85u,1u,(void *)self,0,output); }
static inline R4LibrariesSlot R4StdShortcutForeignEntry_set_value(R4StdShortcutForeignEntry *self, const R4Lib_Value87 * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,85u,1u,self,a,0); }
static inline R4LibrariesSlot R4StdShortcutForeignEntry_inspect(const R4StdShortcutForeignEntry *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,85u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value86_create(R4Lib_Value86 *output, const R4Lib_Value86 * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,86u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value86_inspect(const R4Lib_Value86 *self, R4Lib_Value86 *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,86u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value87_create(R4Lib_Value87 *output, const R4Lib_Value87 * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,87u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value87_inspect(const R4Lib_Value87 *self, R4Lib_Value87 *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,87u,(void *)self,output); }
static inline R4LibrariesSlot R4StdShortcutTargetKind_create(R4StdShortcutTargetKind *output, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,88u,a,1u,output); }
static inline R4LibrariesSlot R4StdShortcutTargetKind_inspect(const R4StdShortcutTargetKind *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,88u,(void *)self,0); }
static inline R4LibrariesSlot R4StdShortcutResolvedTarget_create(R4StdShortcutResolvedTarget *output, uint32_t p0, const uint8_t * p1, uintptr_t n1, const uint8_t * p2, uintptr_t n2, const uint8_t * p3, uintptr_t n3, uint32_t p4, const uint8_t * p5, uintptr_t n5, const uint8_t * p6, uintptr_t n6) {
 R4LibrariesSlot a[7]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.length=n2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.ptr=(void *)p3,.length=n3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.ptr=(void *)p5,.length=n5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.ptr=(void *)p6,.length=n6,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,89u,a,7u,output);
}
static inline R4LibrariesSlot R4StdShortcutResolvedTarget_from_fields(R4StdShortcutResolvedTarget *output, uint32_t p0, const uint8_t * p1, uintptr_t n1, const uint8_t * p2, uintptr_t n2, const uint8_t * p3, uintptr_t n3, uint32_t p4, const uint8_t * p5, uintptr_t n5, const uint8_t * p6, uintptr_t n6) {
 R4LibrariesSlot a[7]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.length=n2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.ptr=(void *)p3,.length=n3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.ptr=(void *)p5,.length=n5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.ptr=(void *)p6,.length=n6,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,89u,a,7u,output);
}
static inline R4LibrariesSlot R4StdShortcutResolvedTarget_get_kind(const R4StdShortcutResolvedTarget *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,89u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdShortcutResolvedTarget_set_kind(R4StdShortcutResolvedTarget *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,89u,0u,self,a,0); }
static inline R4LibrariesSlot R4StdShortcutResolvedTarget_get_target(const R4StdShortcutResolvedTarget *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,89u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdShortcutResolvedTarget_set_target(R4StdShortcutResolvedTarget *self, const uint8_t * p0, uintptr_t n0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,89u,1u,self,a,0); }
static inline R4LibrariesSlot R4StdShortcutResolvedTarget_get_title(const R4StdShortcutResolvedTarget *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,89u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdShortcutResolvedTarget_set_title(R4StdShortcutResolvedTarget *self, const uint8_t * p0, uintptr_t n0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,89u,2u,self,a,0); }
static inline R4LibrariesSlot R4StdShortcutResolvedTarget_get_args(const R4StdShortcutResolvedTarget *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,89u,3u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdShortcutResolvedTarget_set_args(R4StdShortcutResolvedTarget *self, const uint8_t * p0, uintptr_t n0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,89u,3u,self,a,0); }
static inline R4LibrariesSlot R4StdShortcutResolvedTarget_get_policy(const R4StdShortcutResolvedTarget *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,89u,4u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdShortcutResolvedTarget_set_policy(R4StdShortcutResolvedTarget *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,89u,4u,self,a,0); }
static inline R4LibrariesSlot R4StdShortcutResolvedTarget_get_icon(const R4StdShortcutResolvedTarget *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,89u,5u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdShortcutResolvedTarget_set_icon(R4StdShortcutResolvedTarget *self, const uint8_t * p0, uintptr_t n0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,89u,5u,self,a,0); }
static inline R4LibrariesSlot R4StdShortcutResolvedTarget_get_workdir(const R4StdShortcutResolvedTarget *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,89u,6u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdShortcutResolvedTarget_set_workdir(R4StdShortcutResolvedTarget *self, const uint8_t * p0, uintptr_t n0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,89u,6u,self,a,0); }
static inline R4LibrariesSlot R4StdShortcutResolvedTarget_inspect(const R4StdShortcutResolvedTarget *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,89u,(void *)self,0); }
static inline R4LibrariesSlot R4StdShortcutShortcut_create(R4StdShortcutShortcut *output) {
 R4LibrariesSlot a[8]={0};
 a[0].flags=R4LIBRARIES_DEFAULT;
 a[1].flags=R4LIBRARIES_DEFAULT;
 a[2].flags=R4LIBRARIES_DEFAULT;
 a[3].flags=R4LIBRARIES_DEFAULT;
 a[4].flags=R4LIBRARIES_DEFAULT;
 a[5].flags=R4LIBRARIES_DEFAULT;
 a[6].flags=R4LIBRARIES_DEFAULT;
 a[7].flags=R4LIBRARIES_DEFAULT;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,91u,a,8u,output);
}
static inline R4LibrariesSlot R4StdShortcutShortcut_from_fields(R4StdShortcutShortcut *output, const R4Lib_Value92 * p0, const R4Lib_Value93 * p1, const R4Lib_Value87 * p2, uint32_t p3, const R4Lib_Value92 * p4, const R4Lib_Value92 * p5, const R4Lib_Value94 * p6, uint8_t p7) {
 R4LibrariesSlot a[8]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.ptr=(void *)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.ptr=(void *)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.ptr=(void *)p6,.flags=R4LIBRARIES_PRESENT};
 a[7] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p7,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,91u,a,8u,output);
}
static inline R4LibrariesSlot R4StdShortcutShortcut_get_target(const R4StdShortcutShortcut *self, R4Lib_Value92 *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,91u,0u,(void *)self,0,output); }
static inline R4LibrariesSlot R4StdShortcutShortcut_set_target(R4StdShortcutShortcut *self, const R4Lib_Value92 * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,91u,0u,self,a,0); }
static inline R4LibrariesSlot R4StdShortcutShortcut_get_title(const R4StdShortcutShortcut *self, R4Lib_Value93 *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,91u,1u,(void *)self,0,output); }
static inline R4LibrariesSlot R4StdShortcutShortcut_set_title(R4StdShortcutShortcut *self, const R4Lib_Value93 * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,91u,1u,self,a,0); }
static inline R4LibrariesSlot R4StdShortcutShortcut_get_args(const R4StdShortcutShortcut *self, R4Lib_Value87 *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,91u,2u,(void *)self,0,output); }
static inline R4LibrariesSlot R4StdShortcutShortcut_set_args(R4StdShortcutShortcut *self, const R4Lib_Value87 * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,91u,2u,self,a,0); }
static inline R4LibrariesSlot R4StdShortcutShortcut_get_policy(const R4StdShortcutShortcut *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,91u,3u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdShortcutShortcut_set_policy(R4StdShortcutShortcut *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,91u,3u,self,a,0); }
static inline R4LibrariesSlot R4StdShortcutShortcut_get_icon(const R4StdShortcutShortcut *self, R4Lib_Value92 *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,91u,4u,(void *)self,0,output); }
static inline R4LibrariesSlot R4StdShortcutShortcut_set_icon(R4StdShortcutShortcut *self, const R4Lib_Value92 * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,91u,4u,self,a,0); }
static inline R4LibrariesSlot R4StdShortcutShortcut_get_workdir(const R4StdShortcutShortcut *self, R4Lib_Value92 *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,91u,5u,(void *)self,0,output); }
static inline R4LibrariesSlot R4StdShortcutShortcut_set_workdir(R4StdShortcutShortcut *self, const R4Lib_Value92 * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,91u,5u,self,a,0); }
static inline R4LibrariesSlot R4StdShortcutShortcut_get_foreign(const R4StdShortcutShortcut *self, R4Lib_Value94 *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,91u,6u,(void *)self,0,output); }
static inline R4LibrariesSlot R4StdShortcutShortcut_set_foreign(R4StdShortcutShortcut *self, const R4Lib_Value94 * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,91u,6u,self,a,0); }
static inline R4LibrariesSlot R4StdShortcutShortcut_get_foreign_count(const R4StdShortcutShortcut *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,91u,7u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdShortcutShortcut_set_foreign_count(R4StdShortcutShortcut *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,91u,7u,self,a,0); }
static inline R4LibrariesSlot R4StdShortcutShortcut_inspect(const R4StdShortcutShortcut *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,91u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value92_create(R4Lib_Value92 *output, const R4Lib_Value92 * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,92u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value92_inspect(const R4Lib_Value92 *self, R4Lib_Value92 *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,92u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value93_create(R4Lib_Value93 *output, const R4Lib_Value93 * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,93u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value93_inspect(const R4Lib_Value93 *self, R4Lib_Value93 *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,93u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value94_create(R4Lib_Value94 *output, const R4Lib_Value94 * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,94u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value94_inspect(const R4Lib_Value94 *self, R4Lib_Value94 *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,94u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value95_inspect(const R4Lib_Value95 *self, R4StdShortcutShortcut *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,95u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value96_create(R4Lib_Value96 *output, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,96u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value96_inspect(const R4Lib_Value96 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,96u,(void *)self,0); }
static inline R4LibrariesSlot R4StdAssociationForeignEntry_create(R4StdAssociationForeignEntry *output) {
 R4LibrariesSlot a[2]={0};
 a[0].flags=R4LIBRARIES_DEFAULT;
 a[1].flags=R4LIBRARIES_DEFAULT;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,97u,a,2u,output);
}
static inline R4LibrariesSlot R4StdAssociationForeignEntry_from_fields(R4StdAssociationForeignEntry *output, const R4Lib_Value98 * p0, const R4Lib_Value87 * p1) {
 R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,97u,a,2u,output);
}
static inline R4LibrariesSlot R4StdAssociationForeignEntry_get_key(const R4StdAssociationForeignEntry *self, R4Lib_Value98 *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,97u,0u,(void *)self,0,output); }
static inline R4LibrariesSlot R4StdAssociationForeignEntry_set_key(R4StdAssociationForeignEntry *self, const R4Lib_Value98 * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,97u,0u,self,a,0); }
static inline R4LibrariesSlot R4StdAssociationForeignEntry_get_value(const R4StdAssociationForeignEntry *self, R4Lib_Value87 *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,97u,1u,(void *)self,0,output); }
static inline R4LibrariesSlot R4StdAssociationForeignEntry_set_value(R4StdAssociationForeignEntry *self, const R4Lib_Value87 * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,97u,1u,self,a,0); }
static inline R4LibrariesSlot R4StdAssociationForeignEntry_inspect(const R4StdAssociationForeignEntry *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,97u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value98_create(R4Lib_Value98 *output, const R4Lib_Value98 * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,98u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value98_inspect(const R4Lib_Value98 *self, R4Lib_Value98 *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,98u,(void *)self,output); }
static inline R4LibrariesSlot R4StdAssociationLaunchKind_create(R4StdAssociationLaunchKind *output, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,99u,a,1u,output); }
static inline R4LibrariesSlot R4StdAssociationLaunchKind_inspect(const R4StdAssociationLaunchKind *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,99u,(void *)self,0); }
static inline R4LibrariesSlot R4StdAssociationHandlerKind_create(R4StdAssociationHandlerKind *output, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,100u,a,1u,output); }
static inline R4LibrariesSlot R4StdAssociationHandlerKind_inspect(const R4StdAssociationHandlerKind *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,100u,(void *)self,0); }
static inline R4LibrariesSlot R4StdAssociationAppEntry_create(R4StdAssociationAppEntry *output) {
 R4LibrariesSlot a[6]={0};
 a[0].flags=R4LIBRARIES_DEFAULT;
 a[1].flags=R4LIBRARIES_DEFAULT;
 a[2].flags=R4LIBRARIES_DEFAULT;
 a[3].flags=R4LIBRARIES_DEFAULT;
 a[4].flags=R4LIBRARIES_DEFAULT;
 a[5].flags=R4LIBRARIES_DEFAULT;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,101u,a,6u,output);
}
static inline R4LibrariesSlot R4StdAssociationAppEntry_from_fields(R4StdAssociationAppEntry *output, uint8_t p0, const R4Lib_Value102 * p1, const R4Lib_Value86 * p2, const R4Lib_Value92 * p3, uint32_t p4, const R4Lib_Value103 * p5) {
 R4LibrariesSlot a[6]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.ptr=(void *)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.ptr=(void *)p5,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,101u,a,6u,output);
}
static inline R4LibrariesSlot R4StdAssociationAppEntry_get_valid(const R4StdAssociationAppEntry *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,101u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdAssociationAppEntry_set_valid(R4StdAssociationAppEntry *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,101u,0u,self,a,0); }
static inline R4LibrariesSlot R4StdAssociationAppEntry_get_id(const R4StdAssociationAppEntry *self, R4Lib_Value102 *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,101u,1u,(void *)self,0,output); }
static inline R4LibrariesSlot R4StdAssociationAppEntry_set_id(R4StdAssociationAppEntry *self, const R4Lib_Value102 * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,101u,1u,self,a,0); }
static inline R4LibrariesSlot R4StdAssociationAppEntry_get_title(const R4StdAssociationAppEntry *self, R4Lib_Value86 *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,101u,2u,(void *)self,0,output); }
static inline R4LibrariesSlot R4StdAssociationAppEntry_set_title(R4StdAssociationAppEntry *self, const R4Lib_Value86 * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,101u,2u,self,a,0); }
static inline R4LibrariesSlot R4StdAssociationAppEntry_get_path(const R4StdAssociationAppEntry *self, R4Lib_Value92 *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,101u,3u,(void *)self,0,output); }
static inline R4LibrariesSlot R4StdAssociationAppEntry_set_path(R4StdAssociationAppEntry *self, const R4Lib_Value92 * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,101u,3u,self,a,0); }
static inline R4LibrariesSlot R4StdAssociationAppEntry_get_policy(const R4StdAssociationAppEntry *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,101u,4u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdAssociationAppEntry_set_policy(R4StdAssociationAppEntry *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,101u,4u,self,a,0); }
static inline R4LibrariesSlot R4StdAssociationAppEntry_get_args(const R4StdAssociationAppEntry *self, R4Lib_Value103 *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,101u,5u,(void *)self,0,output); }
static inline R4LibrariesSlot R4StdAssociationAppEntry_set_args(R4StdAssociationAppEntry *self, const R4Lib_Value103 * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,101u,5u,self,a,0); }
static inline R4LibrariesSlot R4StdAssociationAppEntry_inspect(const R4StdAssociationAppEntry *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,101u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value102_create(R4Lib_Value102 *output, const R4Lib_Value102 * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,102u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value102_inspect(const R4Lib_Value102 *self, R4Lib_Value102 *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,102u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value103_create(R4Lib_Value103 *output, const R4Lib_Value103 * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,103u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value103_inspect(const R4Lib_Value103 *self, R4Lib_Value103 *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,103u,(void *)self,output); }
static inline R4LibrariesSlot R4StdAssociationExtEntry_create(R4StdAssociationExtEntry *output) {
 R4LibrariesSlot a[10]={0};
 a[0].flags=R4LIBRARIES_DEFAULT;
 a[1].flags=R4LIBRARIES_DEFAULT;
 a[2].flags=R4LIBRARIES_DEFAULT;
 a[3].flags=R4LIBRARIES_DEFAULT;
 a[4].flags=R4LIBRARIES_DEFAULT;
 a[5].flags=R4LIBRARIES_DEFAULT;
 a[6].flags=R4LIBRARIES_DEFAULT;
 a[7].flags=R4LIBRARIES_DEFAULT;
 a[8].flags=R4LIBRARIES_DEFAULT;
 a[9].flags=R4LIBRARIES_DEFAULT;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,104u,a,10u,output);
}
static inline R4LibrariesSlot R4StdAssociationExtEntry_from_fields(R4StdAssociationExtEntry *output, uint8_t p0, const R4Lib_Value105 * p1, uint32_t p2, const R4Lib_Value102 * p3, const R4Lib_Value93 * p4, const R4Lib_Value93 * p5, const R4Lib_Value106 * p6, const R4Lib_Value107 * p7, const R4Lib_Value105 * p8, uint8_t p9) {
 R4LibrariesSlot a[10]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.ptr=(void *)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.ptr=(void *)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.ptr=(void *)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.ptr=(void *)p6,.flags=R4LIBRARIES_PRESENT};
 a[7] = (R4LibrariesSlot){.ptr=(void *)p7,.flags=R4LIBRARIES_PRESENT};
 a[8] = (R4LibrariesSlot){.ptr=(void *)p8,.flags=R4LIBRARIES_PRESENT};
 a[9] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p9,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,104u,a,10u,output);
}
static inline R4LibrariesSlot R4StdAssociationExtEntry_get_valid(const R4StdAssociationExtEntry *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,104u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdAssociationExtEntry_set_valid(R4StdAssociationExtEntry *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,104u,0u,self,a,0); }
static inline R4LibrariesSlot R4StdAssociationExtEntry_get_ext(const R4StdAssociationExtEntry *self, R4Lib_Value105 *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,104u,1u,(void *)self,0,output); }
static inline R4LibrariesSlot R4StdAssociationExtEntry_set_ext(R4StdAssociationExtEntry *self, const R4Lib_Value105 * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,104u,1u,self,a,0); }
static inline R4LibrariesSlot R4StdAssociationExtEntry_get_handler_kind(const R4StdAssociationExtEntry *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,104u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdAssociationExtEntry_set_handler_kind(R4StdAssociationExtEntry *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,104u,2u,self,a,0); }
static inline R4LibrariesSlot R4StdAssociationExtEntry_get_app_id(const R4StdAssociationExtEntry *self, R4Lib_Value102 *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,104u,3u,(void *)self,0,output); }
static inline R4LibrariesSlot R4StdAssociationExtEntry_set_app_id(R4StdAssociationExtEntry *self, const R4Lib_Value102 * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,104u,3u,self,a,0); }
static inline R4LibrariesSlot R4StdAssociationExtEntry_get_subsystem_id(const R4StdAssociationExtEntry *self, R4Lib_Value93 *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,104u,4u,(void *)self,0,output); }
static inline R4LibrariesSlot R4StdAssociationExtEntry_set_subsystem_id(R4StdAssociationExtEntry *self, const R4Lib_Value93 * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,104u,4u,self,a,0); }
static inline R4LibrariesSlot R4StdAssociationExtEntry_get_format_id(const R4StdAssociationExtEntry *self, R4Lib_Value93 *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,104u,5u,(void *)self,0,output); }
static inline R4LibrariesSlot R4StdAssociationExtEntry_set_format_id(R4StdAssociationExtEntry *self, const R4Lib_Value93 * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,104u,5u,self,a,0); }
static inline R4LibrariesSlot R4StdAssociationExtEntry_get_type_name(const R4StdAssociationExtEntry *self, R4Lib_Value106 *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,104u,6u,(void *)self,0,output); }
static inline R4LibrariesSlot R4StdAssociationExtEntry_set_type_name(R4StdAssociationExtEntry *self, const R4Lib_Value106 * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,104u,6u,self,a,0); }
static inline R4LibrariesSlot R4StdAssociationExtEntry_get_short_name(const R4StdAssociationExtEntry *self, R4Lib_Value107 *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,104u,7u,(void *)self,0,output); }
static inline R4LibrariesSlot R4StdAssociationExtEntry_set_short_name(R4StdAssociationExtEntry *self, const R4Lib_Value107 * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,104u,7u,self,a,0); }
static inline R4LibrariesSlot R4StdAssociationExtEntry_get_prefix(const R4StdAssociationExtEntry *self, R4Lib_Value105 *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,104u,8u,(void *)self,0,output); }
static inline R4LibrariesSlot R4StdAssociationExtEntry_set_prefix(R4StdAssociationExtEntry *self, const R4Lib_Value105 * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,104u,8u,self,a,0); }
static inline R4LibrariesSlot R4StdAssociationExtEntry_get_rank(const R4StdAssociationExtEntry *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,104u,9u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdAssociationExtEntry_set_rank(R4StdAssociationExtEntry *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,104u,9u,self,a,0); }
static inline R4LibrariesSlot R4StdAssociationExtEntry_inspect(const R4StdAssociationExtEntry *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,104u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value105_create(R4Lib_Value105 *output, const R4Lib_Value105 * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,105u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value105_inspect(const R4Lib_Value105 *self, R4Lib_Value105 *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,105u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value106_create(R4Lib_Value106 *output, const R4Lib_Value106 * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,106u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value106_inspect(const R4Lib_Value106 *self, R4Lib_Value106 *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,106u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value107_create(R4Lib_Value107 *output, const R4Lib_Value107 * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,107u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value107_inspect(const R4Lib_Value107 *self, R4Lib_Value107 *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,107u,(void *)self,output); }
static inline R4LibrariesSlot R4StdAssociationLaunchTarget_create(R4StdAssociationLaunchTarget *output, uint32_t p0, const uint8_t * p1, uintptr_t n1, const uint8_t * p2, uintptr_t n2, const uint8_t * p3, uintptr_t n3, const uint8_t * p4, uintptr_t n4, uint32_t p5, const uint8_t * p6, uintptr_t n6, const uint8_t * p7, uintptr_t n7, const uint8_t * p8, uintptr_t n8, uint8_t p9) {
 R4LibrariesSlot a[10]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.length=n2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.ptr=(void *)p3,.length=n3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.ptr=(void *)p4,.length=n4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.ptr=(void *)p6,.length=n6,.flags=R4LIBRARIES_PRESENT};
 a[7] = (R4LibrariesSlot){.ptr=(void *)p7,.length=n7,.flags=R4LIBRARIES_PRESENT};
 a[8] = (R4LibrariesSlot){.ptr=(void *)p8,.length=n8,.flags=R4LIBRARIES_PRESENT};
 a[9] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p9,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,108u,a,10u,output);
}
static inline R4LibrariesSlot R4StdAssociationLaunchTarget_from_fields(R4StdAssociationLaunchTarget *output, uint32_t p0, const uint8_t * p1, uintptr_t n1, const uint8_t * p2, uintptr_t n2, const uint8_t * p3, uintptr_t n3, const uint8_t * p4, uintptr_t n4, uint32_t p5, const uint8_t * p6, uintptr_t n6, const uint8_t * p7, uintptr_t n7, const uint8_t * p8, uintptr_t n8, uint8_t p9) {
 R4LibrariesSlot a[10]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.length=n2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.ptr=(void *)p3,.length=n3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.ptr=(void *)p4,.length=n4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.ptr=(void *)p6,.length=n6,.flags=R4LIBRARIES_PRESENT};
 a[7] = (R4LibrariesSlot){.ptr=(void *)p7,.length=n7,.flags=R4LIBRARIES_PRESENT};
 a[8] = (R4LibrariesSlot){.ptr=(void *)p8,.length=n8,.flags=R4LIBRARIES_PRESENT};
 a[9] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p9,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,108u,a,10u,output);
}
static inline R4LibrariesSlot R4StdAssociationLaunchTarget_get_kind(const R4StdAssociationLaunchTarget *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,108u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdAssociationLaunchTarget_set_kind(R4StdAssociationLaunchTarget *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,108u,0u,self,a,0); }
static inline R4LibrariesSlot R4StdAssociationLaunchTarget_get_app_id(const R4StdAssociationLaunchTarget *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,108u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdAssociationLaunchTarget_set_app_id(R4StdAssociationLaunchTarget *self, const uint8_t * p0, uintptr_t n0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,108u,1u,self,a,0); }
static inline R4LibrariesSlot R4StdAssociationLaunchTarget_get_title(const R4StdAssociationLaunchTarget *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,108u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdAssociationLaunchTarget_set_title(R4StdAssociationLaunchTarget *self, const uint8_t * p0, uintptr_t n0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,108u,2u,self,a,0); }
static inline R4LibrariesSlot R4StdAssociationLaunchTarget_get_app_path(const R4StdAssociationLaunchTarget *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,108u,3u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdAssociationLaunchTarget_set_app_path(R4StdAssociationLaunchTarget *self, const uint8_t * p0, uintptr_t n0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,108u,3u,self,a,0); }
static inline R4LibrariesSlot R4StdAssociationLaunchTarget_get_args(const R4StdAssociationLaunchTarget *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,108u,4u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdAssociationLaunchTarget_set_args(R4StdAssociationLaunchTarget *self, const uint8_t * p0, uintptr_t n0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,108u,4u,self,a,0); }
static inline R4LibrariesSlot R4StdAssociationLaunchTarget_get_policy(const R4StdAssociationLaunchTarget *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,108u,5u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdAssociationLaunchTarget_set_policy(R4StdAssociationLaunchTarget *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,108u,5u,self,a,0); }
static inline R4LibrariesSlot R4StdAssociationLaunchTarget_get_type_name(const R4StdAssociationLaunchTarget *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,108u,6u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdAssociationLaunchTarget_set_type_name(R4StdAssociationLaunchTarget *self, const uint8_t * p0, uintptr_t n0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,108u,6u,self,a,0); }
static inline R4LibrariesSlot R4StdAssociationLaunchTarget_get_short_name(const R4StdAssociationLaunchTarget *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,108u,7u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdAssociationLaunchTarget_set_short_name(R4StdAssociationLaunchTarget *self, const uint8_t * p0, uintptr_t n0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,108u,7u,self,a,0); }
static inline R4LibrariesSlot R4StdAssociationLaunchTarget_get_prefix(const R4StdAssociationLaunchTarget *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,108u,8u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdAssociationLaunchTarget_set_prefix(R4StdAssociationLaunchTarget *self, const uint8_t * p0, uintptr_t n0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,108u,8u,self,a,0); }
static inline R4LibrariesSlot R4StdAssociationLaunchTarget_get_rank(const R4StdAssociationLaunchTarget *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,108u,9u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdAssociationLaunchTarget_set_rank(R4StdAssociationLaunchTarget *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,108u,9u,self,a,0); }
static inline R4LibrariesSlot R4StdAssociationLaunchTarget_inspect(const R4StdAssociationLaunchTarget *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,108u,(void *)self,0); }
static inline R4LibrariesSlot R4StdAssociationConfig_create(R4StdAssociationConfig *output) {
 R4LibrariesSlot a[6]={0};
 a[0].flags=R4LIBRARIES_DEFAULT;
 a[1].flags=R4LIBRARIES_DEFAULT;
 a[2].flags=R4LIBRARIES_DEFAULT;
 a[3].flags=R4LIBRARIES_DEFAULT;
 a[4].flags=R4LIBRARIES_DEFAULT;
 a[5].flags=R4LIBRARIES_DEFAULT;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,109u,a,6u,output);
}
static inline R4LibrariesSlot R4StdAssociationConfig_from_fields(R4StdAssociationConfig *output, const R4Lib_Value110 * p0, uint64_t p1, const R4Lib_Value111 * p2, uint64_t p3, const R4Lib_Value112 * p4, uint64_t p5) {
 R4LibrariesSlot a[6]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.ptr=(void *)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,109u,a,6u,output);
}
static inline R4LibrariesSlot R4StdAssociationConfig_get_apps(const R4StdAssociationConfig *self, R4Lib_Value110 *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,109u,0u,(void *)self,0,output); }
static inline R4LibrariesSlot R4StdAssociationConfig_set_apps(R4StdAssociationConfig *self, const R4Lib_Value110 * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,109u,0u,self,a,0); }
static inline R4LibrariesSlot R4StdAssociationConfig_get_app_count(const R4StdAssociationConfig *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,109u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdAssociationConfig_set_app_count(R4StdAssociationConfig *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,109u,1u,self,a,0); }
static inline R4LibrariesSlot R4StdAssociationConfig_get_extensions(const R4StdAssociationConfig *self, R4Lib_Value111 *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,109u,2u,(void *)self,0,output); }
static inline R4LibrariesSlot R4StdAssociationConfig_set_extensions(R4StdAssociationConfig *self, const R4Lib_Value111 * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,109u,2u,self,a,0); }
static inline R4LibrariesSlot R4StdAssociationConfig_get_extension_count(const R4StdAssociationConfig *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,109u,3u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdAssociationConfig_set_extension_count(R4StdAssociationConfig *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,109u,3u,self,a,0); }
static inline R4LibrariesSlot R4StdAssociationConfig_get_foreign(const R4StdAssociationConfig *self, R4Lib_Value112 *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,109u,4u,(void *)self,0,output); }
static inline R4LibrariesSlot R4StdAssociationConfig_set_foreign(R4StdAssociationConfig *self, const R4Lib_Value112 * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,109u,4u,self,a,0); }
static inline R4LibrariesSlot R4StdAssociationConfig_get_foreign_count(const R4StdAssociationConfig *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,109u,5u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdAssociationConfig_set_foreign_count(R4StdAssociationConfig *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,109u,5u,self,a,0); }
static inline R4LibrariesSlot R4StdAssociationConfig_inspect(const R4StdAssociationConfig *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,109u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value110_create(R4Lib_Value110 *output, const R4Lib_Value110 * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,110u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value110_inspect(const R4Lib_Value110 *self, R4Lib_Value110 *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,110u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value111_create(R4Lib_Value111 *output, const R4Lib_Value111 * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,111u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value111_inspect(const R4Lib_Value111 *self, R4Lib_Value111 *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,111u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value112_create(R4Lib_Value112 *output, const R4Lib_Value112 * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,112u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value112_inspect(const R4Lib_Value112 *self, R4Lib_Value112 *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,112u,(void *)self,output); }
static inline R4LibrariesSlot R4StdFileHandlerTargetKind_create(R4StdFileHandlerTargetKind *output, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,114u,a,1u,output); }
static inline R4LibrariesSlot R4StdFileHandlerTargetKind_inspect(const R4StdFileHandlerTargetKind *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,114u,(void *)self,0); }
static inline R4LibrariesSlot R4StdFileHandlerTarget_create(R4StdFileHandlerTarget *output, uint32_t p0, const uint8_t * p1, uintptr_t n1, const uint8_t * p3, uintptr_t n3, const uint8_t * p4, uintptr_t n4, const uint8_t * p5, uintptr_t n5, uint32_t p6) {
 R4LibrariesSlot a[7]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 a[2].flags=R4LIBRARIES_DEFAULT;
 a[3] = (R4LibrariesSlot){.ptr=(void *)p3,.length=n3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.ptr=(void *)p4,.length=n4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.ptr=(void *)p5,.length=n5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,115u,a,7u,output);
}
static inline R4LibrariesSlot R4StdFileHandlerTarget_from_fields(R4StdFileHandlerTarget *output, uint32_t p0, const uint8_t * p1, uintptr_t n1, const uint8_t * p2, uintptr_t n2, const uint8_t * p3, uintptr_t n3, const uint8_t * p4, uintptr_t n4, const uint8_t * p5, uintptr_t n5, uint32_t p6) {
 R4LibrariesSlot a[7]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.length=n2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.ptr=(void *)p3,.length=n3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.ptr=(void *)p4,.length=n4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.ptr=(void *)p5,.length=n5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,115u,a,7u,output);
}
static inline R4LibrariesSlot R4StdFileHandlerTarget_get_kind(const R4StdFileHandlerTarget *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,115u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdFileHandlerTarget_set_kind(R4StdFileHandlerTarget *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,115u,0u,self,a,0); }
static inline R4LibrariesSlot R4StdFileHandlerTarget_get_handler_id(const R4StdFileHandlerTarget *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,115u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdFileHandlerTarget_set_handler_id(R4StdFileHandlerTarget *self, const uint8_t * p0, uintptr_t n0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,115u,1u,self,a,0); }
static inline R4LibrariesSlot R4StdFileHandlerTarget_get_format_id(const R4StdFileHandlerTarget *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,115u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdFileHandlerTarget_set_format_id(R4StdFileHandlerTarget *self, const uint8_t * p0, uintptr_t n0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,115u,2u,self,a,0); }
static inline R4LibrariesSlot R4StdFileHandlerTarget_get_title(const R4StdFileHandlerTarget *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,115u,3u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdFileHandlerTarget_set_title(R4StdFileHandlerTarget *self, const uint8_t * p0, uintptr_t n0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,115u,3u,self,a,0); }
static inline R4LibrariesSlot R4StdFileHandlerTarget_get_app_path(const R4StdFileHandlerTarget *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,115u,4u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdFileHandlerTarget_set_app_path(R4StdFileHandlerTarget *self, const uint8_t * p0, uintptr_t n0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,115u,4u,self,a,0); }
static inline R4LibrariesSlot R4StdFileHandlerTarget_get_args(const R4StdFileHandlerTarget *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,115u,5u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdFileHandlerTarget_set_args(R4StdFileHandlerTarget *self, const uint8_t * p0, uintptr_t n0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,115u,5u,self,a,0); }
static inline R4LibrariesSlot R4StdFileHandlerTarget_get_policy(const R4StdFileHandlerTarget *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,115u,6u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdFileHandlerTarget_set_policy(R4StdFileHandlerTarget *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,115u,6u,self,a,0); }
static inline R4LibrariesSlot R4StdFileHandlerTarget_inspect(const R4StdFileHandlerTarget *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,115u,(void *)self,0); }
static inline R4LibrariesSlot R4StdFileHandlerResolutionState_create(R4StdFileHandlerResolutionState *output, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,116u,a,1u,output); }
static inline R4LibrariesSlot R4StdFileHandlerResolutionState_inspect(const R4StdFileHandlerResolutionState *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,116u,(void *)self,0); }
static inline R4LibrariesSlot R4StdFileHandlerResolution_create(R4StdFileHandlerResolution *output) {
 R4LibrariesSlot a[2]={0};
 a[0].flags=R4LIBRARIES_DEFAULT;
 a[1].flags=R4LIBRARIES_DEFAULT;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,117u,a,2u,output);
}
static inline R4LibrariesSlot R4StdFileHandlerResolution_from_fields(R4StdFileHandlerResolution *output, uint32_t p0, R4LibrariesSlot p1) {
 R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = p1;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,117u,a,2u,output);
}
static inline R4LibrariesSlot R4StdFileHandlerResolution_get_state(const R4StdFileHandlerResolution *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,117u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdFileHandlerResolution_set_state(R4StdFileHandlerResolution *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,117u,0u,self,a,0); }
static inline R4LibrariesSlot R4StdFileHandlerResolution_get_target(const R4StdFileHandlerResolution *self, R4StdFileHandlerTarget *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,117u,1u,(void *)self,0,output); }
static inline R4LibrariesSlot R4StdFileHandlerResolution_set_target(R4StdFileHandlerResolution *self, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,117u,1u,self,a,0); }
static inline R4LibrariesSlot R4StdFileHandlerResolution_inspect(const R4StdFileHandlerResolution *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,117u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value118_create(R4Lib_Value118 *output, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,118u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value118_inspect(const R4Lib_Value118 *self, R4StdFileHandlerTarget *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,118u,(void *)self,output); }
static inline R4LibrariesSlot R4StdFileHandlerChoiceKind_create(R4StdFileHandlerChoiceKind *output, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,119u,a,1u,output); }
static inline R4LibrariesSlot R4StdFileHandlerChoiceKind_inspect(const R4StdFileHandlerChoiceKind *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,119u,(void *)self,0); }
static inline R4LibrariesSlot R4StdFileHandlerChoice_create(R4StdFileHandlerChoice *output, uint32_t p0, const uint8_t * p1, uintptr_t n1, const uint8_t * p3, uintptr_t n3, const uint8_t * p4, uintptr_t n4) {
 R4LibrariesSlot a[7]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 a[2].flags=R4LIBRARIES_DEFAULT;
 a[3] = (R4LibrariesSlot){.ptr=(void *)p3,.length=n3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.ptr=(void *)p4,.length=n4,.flags=R4LIBRARIES_PRESENT};
 a[5].flags=R4LIBRARIES_DEFAULT;
 a[6].flags=R4LIBRARIES_DEFAULT;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,120u,a,7u,output);
}
static inline R4LibrariesSlot R4StdFileHandlerChoice_from_fields(R4StdFileHandlerChoice *output, uint32_t p0, const uint8_t * p1, uintptr_t n1, const uint8_t * p2, uintptr_t n2, const uint8_t * p3, uintptr_t n3, const uint8_t * p4, uintptr_t n4, uint32_t p5, R4LibrariesSlot p6) {
 R4LibrariesSlot a[7]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.length=n2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.ptr=(void *)p3,.length=n3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.ptr=(void *)p4,.length=n4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = p6;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,120u,a,7u,output);
}
static inline R4LibrariesSlot R4StdFileHandlerChoice_get_kind(const R4StdFileHandlerChoice *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,120u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdFileHandlerChoice_set_kind(R4StdFileHandlerChoice *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,120u,0u,self,a,0); }
static inline R4LibrariesSlot R4StdFileHandlerChoice_get_handler_id(const R4StdFileHandlerChoice *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,120u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdFileHandlerChoice_set_handler_id(R4StdFileHandlerChoice *self, const uint8_t * p0, uintptr_t n0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,120u,1u,self,a,0); }
static inline R4LibrariesSlot R4StdFileHandlerChoice_get_format_id(const R4StdFileHandlerChoice *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,120u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdFileHandlerChoice_set_format_id(R4StdFileHandlerChoice *self, const uint8_t * p0, uintptr_t n0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,120u,2u,self,a,0); }
static inline R4LibrariesSlot R4StdFileHandlerChoice_get_title(const R4StdFileHandlerChoice *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,120u,3u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdFileHandlerChoice_set_title(R4StdFileHandlerChoice *self, const uint8_t * p0, uintptr_t n0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,120u,3u,self,a,0); }
static inline R4LibrariesSlot R4StdFileHandlerChoice_get_app_path(const R4StdFileHandlerChoice *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,120u,4u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdFileHandlerChoice_set_app_path(R4StdFileHandlerChoice *self, const uint8_t * p0, uintptr_t n0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,120u,4u,self,a,0); }
static inline R4LibrariesSlot R4StdFileHandlerChoice_get_policy(const R4StdFileHandlerChoice *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,120u,5u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdFileHandlerChoice_set_policy(R4StdFileHandlerChoice *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,120u,5u,self,a,0); }
static inline R4LibrariesSlot R4StdFileHandlerChoice_get_app(const R4StdFileHandlerChoice *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,120u,6u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdFileHandlerChoice_set_app(R4StdFileHandlerChoice *self, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,120u,6u,self,a,0); }
static inline R4LibrariesSlot R4StdFileHandlerChoice_inspect(const R4StdFileHandlerChoice *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,120u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value121_create(R4Lib_Value121 *output, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,121u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value121_inspect(const R4Lib_Value121 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,121u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value122_create(R4Lib_Value122 *output, const R4StdAssociationAppEntry * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,122u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value122_inspect(const R4Lib_Value122 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,122u,(void *)self,0); }
static inline R4LibrariesSlot R4StdFileHandlerChoiceList_create(R4StdFileHandlerChoiceList *output) {
 R4LibrariesSlot a[2]={0};
 a[0].flags=R4LIBRARIES_DEFAULT;
 a[1].flags=R4LIBRARIES_DEFAULT;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,123u,a,2u,output);
}
static inline R4LibrariesSlot R4StdFileHandlerChoiceList_from_fields(R4StdFileHandlerChoiceList *output, const R4Lib_Value124 * p0, uint64_t p1) {
 R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,123u,a,2u,output);
}
static inline R4LibrariesSlot R4StdFileHandlerChoiceList_get_items(const R4StdFileHandlerChoiceList *self, R4Lib_Value124 *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,123u,0u,(void *)self,0,output); }
static inline R4LibrariesSlot R4StdFileHandlerChoiceList_set_items(R4StdFileHandlerChoiceList *self, const R4Lib_Value124 * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,123u,0u,self,a,0); }
static inline R4LibrariesSlot R4StdFileHandlerChoiceList_get_count(const R4StdFileHandlerChoiceList *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,123u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdFileHandlerChoiceList_set_count(R4StdFileHandlerChoiceList *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,123u,1u,self,a,0); }
static inline R4LibrariesSlot R4StdFileHandlerChoiceList_inspect(const R4StdFileHandlerChoiceList *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,123u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value124_create(R4Lib_Value124 *output, const R4Lib_Value124 * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,124u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value124_inspect(const R4Lib_Value124 *self, R4Lib_Value124 *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,124u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value125_create(R4Lib_Value125 *output, const R4StdAssociationConfig * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,125u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value125_inspect(const R4Lib_Value125 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,125u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value126_create(R4Lib_Value126 *output, const R4Lib_r4os_subsystem_catalog_Catalog * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,126u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value126_inspect(const R4Lib_Value126 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,126u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value128_create(R4Lib_Value128 *output, R4StdFileHandlerResolution * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,128u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value128_inspect(const R4Lib_Value128 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,128u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value129_inspect(const R4Lib_Value129 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,129u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value130_create(R4Lib_Value130 *output, R4StdFileHandlerChoiceList * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,130u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value130_inspect(const R4Lib_Value130 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,130u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value131_inspect(const R4Lib_Value131 *self, R4StdFileHandlerTarget *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,131u,(void *)self,output); }
static inline R4LibrariesSlot R4StdSubsystemLoadStatus_create(R4StdSubsystemLoadStatus *output, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,132u,a,1u,output); }
static inline R4LibrariesSlot R4StdSubsystemLoadStatus_inspect(const R4StdSubsystemLoadStatus *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,132u,(void *)self,0); }
static inline R4LibrariesSlot R4StdSubsystemAccessStats_create(R4StdSubsystemAccessStats *output) {
 R4LibrariesSlot a[3]={0};
 a[0].flags=R4LIBRARIES_DEFAULT;
 a[1].flags=R4LIBRARIES_DEFAULT;
 a[2].flags=R4LIBRARIES_DEFAULT;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,133u,a,3u,output);
}
static inline R4LibrariesSlot R4StdSubsystemAccessStats_from_fields(R4StdSubsystemAccessStats *output, uint32_t p0, uint32_t p1, uint64_t p2) {
 R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,133u,a,3u,output);
}
static inline R4LibrariesSlot R4StdSubsystemAccessStats_get_info_calls(const R4StdSubsystemAccessStats *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,133u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdSubsystemAccessStats_set_info_calls(R4StdSubsystemAccessStats *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,133u,0u,self,a,0); }
static inline R4LibrariesSlot R4StdSubsystemAccessStats_get_read_calls(const R4StdSubsystemAccessStats *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,133u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdSubsystemAccessStats_set_read_calls(R4StdSubsystemAccessStats *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,133u,1u,self,a,0); }
static inline R4LibrariesSlot R4StdSubsystemAccessStats_get_read_bytes(const R4StdSubsystemAccessStats *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,133u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdSubsystemAccessStats_set_read_bytes(R4StdSubsystemAccessStats *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,133u,2u,self,a,0); }
static inline R4LibrariesSlot R4StdSubsystemAccessStats_inspect(const R4StdSubsystemAccessStats *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,133u,(void *)self,0); }
static inline R4LibrariesSlot R4StdSubsystemInspection_create(R4StdSubsystemInspection *output, const R4Lib_r4os_subsystem_catalog_Input * p0, const R4StdSubsystemAccessStats * p1) {
 R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,134u,a,2u,output);
}
static inline R4LibrariesSlot R4StdSubsystemInspection_from_fields(R4StdSubsystemInspection *output, const R4Lib_r4os_subsystem_catalog_Input * p0, const R4StdSubsystemAccessStats * p1) {
 R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,134u,a,2u,output);
}
static inline R4LibrariesSlot R4StdSubsystemInspection_get_input(const R4StdSubsystemInspection *self, R4Lib_r4os_subsystem_catalog_Input *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,134u,0u,(void *)self,0,output); }
static inline R4LibrariesSlot R4StdSubsystemInspection_set_input(R4StdSubsystemInspection *self, const R4Lib_r4os_subsystem_catalog_Input * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,134u,0u,self,a,0); }
static inline R4LibrariesSlot R4StdSubsystemInspection_get_access(const R4StdSubsystemInspection *self, R4StdSubsystemAccessStats *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,134u,1u,(void *)self,0,output); }
static inline R4LibrariesSlot R4StdSubsystemInspection_set_access(R4StdSubsystemInspection *self, const R4StdSubsystemAccessStats * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,134u,1u,self,a,0); }
static inline R4LibrariesSlot R4StdSubsystemInspection_inspect(const R4StdSubsystemInspection *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,134u,(void *)self,0); }
static inline R4LibrariesSlot R4ImgHelpersFormat_create(R4ImgHelpersFormat *output, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,135u,a,1u,output); }
static inline R4LibrariesSlot R4ImgHelpersFormat_inspect(const R4ImgHelpersFormat *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,135u,(void *)self,0); }
static inline R4LibrariesSlot R4ImgHelpersSvgGlyphProvider_create(R4ImgHelpersSvgGlyphProvider *output) {
 R4LibrariesSlot a[6]={0};
 a[0].flags=R4LIBRARIES_DEFAULT;
 a[1].flags=R4LIBRARIES_DEFAULT;
 a[2].flags=R4LIBRARIES_DEFAULT;
 a[3].flags=R4LIBRARIES_DEFAULT;
 a[4].flags=R4LIBRARIES_DEFAULT;
 a[5].flags=R4LIBRARIES_DEFAULT;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,136u,a,6u,output);
}
static inline R4LibrariesSlot R4ImgHelpersSvgGlyphProvider_from_fields(R4ImgHelpersSvgGlyphProvider *output, R4LibrariesSlot p0, uint16_t p1, uint16_t p2, uint16_t p3, int16_t p4, R4LibrariesSlot p5) {
 R4LibrariesSlot a[6]={0};
 a[0] = p0;
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = p5;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,136u,a,6u,output);
}
static inline R4LibrariesSlot R4ImgHelpersSvgGlyphProvider_get_context(const R4ImgHelpersSvgGlyphProvider *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,136u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4ImgHelpersSvgGlyphProvider_set_context(R4ImgHelpersSvgGlyphProvider *self, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,136u,0u,self,a,0); }
static inline R4LibrariesSlot R4ImgHelpersSvgGlyphProvider_get_width(const R4ImgHelpersSvgGlyphProvider *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,136u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4ImgHelpersSvgGlyphProvider_set_width(R4ImgHelpersSvgGlyphProvider *self, uint16_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,136u,1u,self,a,0); }
static inline R4LibrariesSlot R4ImgHelpersSvgGlyphProvider_get_height(const R4ImgHelpersSvgGlyphProvider *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,136u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4ImgHelpersSvgGlyphProvider_set_height(R4ImgHelpersSvgGlyphProvider *self, uint16_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,136u,2u,self,a,0); }
static inline R4LibrariesSlot R4ImgHelpersSvgGlyphProvider_get_advance(const R4ImgHelpersSvgGlyphProvider *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,136u,3u,(void *)self,0,0); }
static inline R4LibrariesSlot R4ImgHelpersSvgGlyphProvider_set_advance(R4ImgHelpersSvgGlyphProvider *self, uint16_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,136u,3u,self,a,0); }
static inline R4LibrariesSlot R4ImgHelpersSvgGlyphProvider_get_baseline(const R4ImgHelpersSvgGlyphProvider *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,136u,4u,(void *)self,0,0); }
static inline R4LibrariesSlot R4ImgHelpersSvgGlyphProvider_set_baseline(R4ImgHelpersSvgGlyphProvider *self, int16_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,136u,4u,self,a,0); }
static inline R4LibrariesSlot R4ImgHelpersSvgGlyphProvider_get_row(const R4ImgHelpersSvgGlyphProvider *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,136u,5u,(void *)self,0,0); }
static inline R4LibrariesSlot R4ImgHelpersSvgGlyphProvider_set_row(R4ImgHelpersSvgGlyphProvider *self, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,136u,5u,self,a,0); }
static inline R4LibrariesSlot R4ImgHelpersSvgGlyphProvider_inspect(const R4ImgHelpersSvgGlyphProvider *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,136u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value137_create(R4Lib_Value137 *output, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,137u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value137_inspect(const R4Lib_Value137 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,137u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value138_create(R4Lib_Value138 *output, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,138u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value138_inspect(const R4Lib_Value138 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,138u,(void *)self,0); }
static inline R4LibrariesSlot R4ImgHelpersSvgLinkSink_create(R4ImgHelpersSvgLinkSink *output) {
 R4LibrariesSlot a[2]={0};
 a[0].flags=R4LIBRARIES_DEFAULT;
 a[1].flags=R4LIBRARIES_DEFAULT;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,139u,a,2u,output);
}
static inline R4LibrariesSlot R4ImgHelpersSvgLinkSink_from_fields(R4ImgHelpersSvgLinkSink *output, R4LibrariesSlot p0, R4LibrariesSlot p1) {
 R4LibrariesSlot a[2]={0};
 a[0] = p0;
 a[1] = p1;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,139u,a,2u,output);
}
static inline R4LibrariesSlot R4ImgHelpersSvgLinkSink_get_context(const R4ImgHelpersSvgLinkSink *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,139u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4ImgHelpersSvgLinkSink_set_context(R4ImgHelpersSvgLinkSink *self, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,139u,0u,self,a,0); }
static inline R4LibrariesSlot R4ImgHelpersSvgLinkSink_get_record(const R4ImgHelpersSvgLinkSink *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,139u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4ImgHelpersSvgLinkSink_set_record(R4ImgHelpersSvgLinkSink *self, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,139u,1u,self,a,0); }
static inline R4LibrariesSlot R4ImgHelpersSvgLinkSink_inspect(const R4ImgHelpersSvgLinkSink *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,139u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value140_create(R4Lib_Value140 *output, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,140u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value140_inspect(const R4Lib_Value140 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,140u,(void *)self,0); }
static inline R4LibrariesSlot R4ImgHelpersSvgRenderOptions_create(R4ImgHelpersSvgRenderOptions *output) {
 R4LibrariesSlot a[3]={0};
 a[0].flags=R4LIBRARIES_DEFAULT;
 a[1].flags=R4LIBRARIES_DEFAULT;
 a[2].flags=R4LIBRARIES_DEFAULT;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,141u,a,3u,output);
}
static inline R4LibrariesSlot R4ImgHelpersSvgRenderOptions_from_fields(R4ImgHelpersSvgRenderOptions *output, R4LibrariesSlot p0, R4LibrariesSlot p1, R4LibrariesSlot p2) {
 R4LibrariesSlot a[3]={0};
 a[0] = p0;
 a[1] = p1;
 a[2] = p2;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,141u,a,3u,output);
}
static inline R4LibrariesSlot R4ImgHelpersSvgRenderOptions_get_glyphs(const R4ImgHelpersSvgRenderOptions *self, R4ImgHelpersSvgGlyphProvider *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,141u,0u,(void *)self,0,output); }
static inline R4LibrariesSlot R4ImgHelpersSvgRenderOptions_set_glyphs(R4ImgHelpersSvgRenderOptions *self, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,141u,0u,self,a,0); }
static inline R4LibrariesSlot R4ImgHelpersSvgRenderOptions_get_links(const R4ImgHelpersSvgRenderOptions *self, R4ImgHelpersSvgLinkSink *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,141u,1u,(void *)self,0,output); }
static inline R4LibrariesSlot R4ImgHelpersSvgRenderOptions_set_links(R4ImgHelpersSvgRenderOptions *self, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,141u,1u,self,a,0); }
static inline R4LibrariesSlot R4ImgHelpersSvgRenderOptions_get_background(const R4ImgHelpersSvgRenderOptions *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,141u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4ImgHelpersSvgRenderOptions_set_background(R4ImgHelpersSvgRenderOptions *self, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,141u,2u,self,a,0); }
static inline R4LibrariesSlot R4ImgHelpersSvgRenderOptions_inspect(const R4ImgHelpersSvgRenderOptions *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,141u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value142_create(R4Lib_Value142 *output, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,142u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value142_inspect(const R4Lib_Value142 *self, R4ImgHelpersSvgGlyphProvider *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,142u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value143_create(R4Lib_Value143 *output, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,143u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value143_inspect(const R4Lib_Value143 *self, R4ImgHelpersSvgLinkSink *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,143u,(void *)self,output); }
static inline R4LibrariesSlot R4ImgHelpersInfo_create(R4ImgHelpersInfo *output, uint32_t p0, uint32_t p1, uint32_t p2, uint8_t p3) {
 R4LibrariesSlot a[4]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,144u,a,4u,output);
}
static inline R4LibrariesSlot R4ImgHelpersInfo_from_fields(R4ImgHelpersInfo *output, uint32_t p0, uint32_t p1, uint32_t p2, uint8_t p3) {
 R4LibrariesSlot a[4]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,144u,a,4u,output);
}
static inline R4LibrariesSlot R4ImgHelpersInfo_get_format(const R4ImgHelpersInfo *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,144u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4ImgHelpersInfo_set_format(R4ImgHelpersInfo *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,144u,0u,self,a,0); }
static inline R4LibrariesSlot R4ImgHelpersInfo_get_width(const R4ImgHelpersInfo *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,144u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4ImgHelpersInfo_set_width(R4ImgHelpersInfo *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,144u,1u,self,a,0); }
static inline R4LibrariesSlot R4ImgHelpersInfo_get_height(const R4ImgHelpersInfo *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,144u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4ImgHelpersInfo_set_height(R4ImgHelpersInfo *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,144u,2u,self,a,0); }
static inline R4LibrariesSlot R4ImgHelpersInfo_get_channels(const R4ImgHelpersInfo *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,144u,3u,(void *)self,0,0); }
static inline R4LibrariesSlot R4ImgHelpersInfo_set_channels(R4ImgHelpersInfo *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,144u,3u,self,a,0); }
static inline R4LibrariesSlot R4ImgHelpersInfo_inspect(const R4ImgHelpersInfo *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,144u,(void *)self,0); }
static inline R4LibrariesSlot R4ImgHelpersImage_create(R4ImgHelpersImage *output, const R4ImgHelpersInfo * p0, uint32_t * p1, uintptr_t n1) {
 R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,145u,a,2u,output);
}
static inline R4LibrariesSlot R4ImgHelpersImage_from_fields(R4ImgHelpersImage *output, const R4ImgHelpersInfo * p0, uint32_t * p1, uintptr_t n1) {
 R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,145u,a,2u,output);
}
static inline R4LibrariesSlot R4ImgHelpersImage_get_info(const R4ImgHelpersImage *self, R4ImgHelpersInfo *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,145u,0u,(void *)self,0,output); }
static inline R4LibrariesSlot R4ImgHelpersImage_set_info(R4ImgHelpersImage *self, const R4ImgHelpersInfo * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,145u,0u,self,a,0); }
static inline R4LibrariesSlot R4ImgHelpersImage_get_pixels(const R4ImgHelpersImage *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,145u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4ImgHelpersImage_set_pixels(R4ImgHelpersImage *self, uint32_t * p0, uintptr_t n0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,145u,1u,self,a,0); }
static inline R4LibrariesSlot R4ImgHelpersImage_inspect(const R4ImgHelpersImage *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,145u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value146_create(R4Lib_Value146 *output, uint32_t * p0, uintptr_t n0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,146u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value146_inspect(const R4Lib_Value146 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,146u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_create(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *output, uint32_t p0, uint32_t p1, uint32_t p2, uint32_t p3, uint32_t p4, uint32_t p5, uint32_t p6, uint32_t p7, uint32_t p8, uint32_t p9, uint32_t p10, uint32_t p11, uint32_t p12, uint32_t p13, uint32_t p14, uint32_t p15, uint32_t p16, uint32_t p17, uint32_t p18, uint32_t p19, uint32_t p20, uint32_t p21, uint32_t p22, uint32_t p23, uint32_t p24, uint32_t p25, uint32_t p26, uint32_t p27, uint32_t p28, uint32_t p29, uint32_t p30, uint32_t p31) {
 R4LibrariesSlot a[32]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4LIBRARIES_PRESENT};
 a[7] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p7,.flags=R4LIBRARIES_PRESENT};
 a[8] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p8,.flags=R4LIBRARIES_PRESENT};
 a[9] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p9,.flags=R4LIBRARIES_PRESENT};
 a[10] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p10,.flags=R4LIBRARIES_PRESENT};
 a[11] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p11,.flags=R4LIBRARIES_PRESENT};
 a[12] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p12,.flags=R4LIBRARIES_PRESENT};
 a[13] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p13,.flags=R4LIBRARIES_PRESENT};
 a[14] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p14,.flags=R4LIBRARIES_PRESENT};
 a[15] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p15,.flags=R4LIBRARIES_PRESENT};
 a[16] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p16,.flags=R4LIBRARIES_PRESENT};
 a[17] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p17,.flags=R4LIBRARIES_PRESENT};
 a[18] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p18,.flags=R4LIBRARIES_PRESENT};
 a[19] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p19,.flags=R4LIBRARIES_PRESENT};
 a[20] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p20,.flags=R4LIBRARIES_PRESENT};
 a[21] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p21,.flags=R4LIBRARIES_PRESENT};
 a[22] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p22,.flags=R4LIBRARIES_PRESENT};
 a[23] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p23,.flags=R4LIBRARIES_PRESENT};
 a[24] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p24,.flags=R4LIBRARIES_PRESENT};
 a[25] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p25,.flags=R4LIBRARIES_PRESENT};
 a[26] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p26,.flags=R4LIBRARIES_PRESENT};
 a[27] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p27,.flags=R4LIBRARIES_PRESENT};
 a[28] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p28,.flags=R4LIBRARIES_PRESENT};
 a[29] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p29,.flags=R4LIBRARIES_PRESENT};
 a[30] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p30,.flags=R4LIBRARIES_PRESENT};
 a[31] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p31,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,147u,a,32u,output);
}
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_from_fields(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *output, uint32_t p0, uint32_t p1, uint32_t p2, uint32_t p3, uint32_t p4, uint32_t p5, uint32_t p6, uint32_t p7, uint32_t p8, uint32_t p9, uint32_t p10, uint32_t p11, uint32_t p12, uint32_t p13, uint32_t p14, uint32_t p15, uint32_t p16, uint32_t p17, uint32_t p18, uint32_t p19, uint32_t p20, uint32_t p21, uint32_t p22, uint32_t p23, uint32_t p24, uint32_t p25, uint32_t p26, uint32_t p27, uint32_t p28, uint32_t p29, uint32_t p30, uint32_t p31) {
 R4LibrariesSlot a[32]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4LIBRARIES_PRESENT};
 a[7] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p7,.flags=R4LIBRARIES_PRESENT};
 a[8] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p8,.flags=R4LIBRARIES_PRESENT};
 a[9] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p9,.flags=R4LIBRARIES_PRESENT};
 a[10] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p10,.flags=R4LIBRARIES_PRESENT};
 a[11] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p11,.flags=R4LIBRARIES_PRESENT};
 a[12] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p12,.flags=R4LIBRARIES_PRESENT};
 a[13] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p13,.flags=R4LIBRARIES_PRESENT};
 a[14] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p14,.flags=R4LIBRARIES_PRESENT};
 a[15] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p15,.flags=R4LIBRARIES_PRESENT};
 a[16] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p16,.flags=R4LIBRARIES_PRESENT};
 a[17] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p17,.flags=R4LIBRARIES_PRESENT};
 a[18] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p18,.flags=R4LIBRARIES_PRESENT};
 a[19] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p19,.flags=R4LIBRARIES_PRESENT};
 a[20] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p20,.flags=R4LIBRARIES_PRESENT};
 a[21] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p21,.flags=R4LIBRARIES_PRESENT};
 a[22] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p22,.flags=R4LIBRARIES_PRESENT};
 a[23] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p23,.flags=R4LIBRARIES_PRESENT};
 a[24] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p24,.flags=R4LIBRARIES_PRESENT};
 a[25] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p25,.flags=R4LIBRARIES_PRESENT};
 a[26] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p26,.flags=R4LIBRARIES_PRESENT};
 a[27] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p27,.flags=R4LIBRARIES_PRESENT};
 a[28] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p28,.flags=R4LIBRARIES_PRESENT};
 a[29] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p29,.flags=R4LIBRARIES_PRESENT};
 a[30] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p30,.flags=R4LIBRARIES_PRESENT};
 a[31] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p31,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,147u,a,32u,output);
}
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_get_version(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_set_version(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,0u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_get_size(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_set_size(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,1u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_get_kind(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_set_kind(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,2u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_get_flags(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,3u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_set_flags(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,3u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_get_bit_depth(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,4u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_set_bit_depth(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,4u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_get_color_type(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,5u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_set_color_type(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,5u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_get_cicp_primaries(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,6u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_set_cicp_primaries(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,6u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_get_cicp_transfer(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,7u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_set_cicp_transfer(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,7u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_get_cicp_matrix(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,8u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_set_cicp_matrix(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,8u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_get_cicp_full_range(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,9u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_set_cicp_full_range(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,9u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_get_intent(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,10u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_set_intent(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,10u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_get_gamma(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,11u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_set_gamma(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,11u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_get_white_x(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,12u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_set_white_x(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,12u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_get_white_y(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,13u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_set_white_y(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,13u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_get_red_x(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,14u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_set_red_x(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,14u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_get_red_y(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,15u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_set_red_y(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,15u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_get_green_x(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,16u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_set_green_x(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,16u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_get_green_y(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,17u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_set_green_y(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,17u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_get_blue_x(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,18u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_set_blue_x(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,18u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_get_blue_y(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,19u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_set_blue_y(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,19u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_get_mastering_red_x(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,20u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_set_mastering_red_x(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,20u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_get_mastering_red_y(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,21u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_set_mastering_red_y(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,21u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_get_mastering_green_x(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,22u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_set_mastering_green_x(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,22u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_get_mastering_green_y(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,23u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_set_mastering_green_y(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,23u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_get_mastering_blue_x(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,24u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_set_mastering_blue_x(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,24u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_get_mastering_blue_y(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,25u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_set_mastering_blue_y(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,25u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_get_mastering_white_x(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,26u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_set_mastering_white_x(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,26u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_get_mastering_white_y(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,27u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_set_mastering_white_y(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,27u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_get_mastering_maximum(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,28u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_set_mastering_maximum(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,28u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_get_mastering_minimum(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,29u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_set_mastering_minimum(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,29u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_get_content_maximum(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,30u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_set_content_maximum(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,30u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_get_content_average(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,31u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_set_content_average(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,147u,31u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor_inspect(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,147u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor_create(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor *output, uint32_t p0, uint32_t p1, uint32_t p2, uint32_t p3, uint32_t p4, uint32_t p5, uint32_t p6, uint32_t p7, int32_t p8, int32_t p9, int32_t p10, int32_t p11, int32_t p12, int32_t p13, int32_t p14, int32_t p15, int32_t p16, uint32_t p17, uint32_t p18, uint32_t p19, uint32_t p20, uint32_t p21) {
 R4LibrariesSlot a[22]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4LIBRARIES_PRESENT};
 a[7] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p7,.flags=R4LIBRARIES_PRESENT};
 a[8] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p8,.flags=R4LIBRARIES_PRESENT};
 a[9] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p9,.flags=R4LIBRARIES_PRESENT};
 a[10] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p10,.flags=R4LIBRARIES_PRESENT};
 a[11] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p11,.flags=R4LIBRARIES_PRESENT};
 a[12] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p12,.flags=R4LIBRARIES_PRESENT};
 a[13] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p13,.flags=R4LIBRARIES_PRESENT};
 a[14] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p14,.flags=R4LIBRARIES_PRESENT};
 a[15] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p15,.flags=R4LIBRARIES_PRESENT};
 a[16] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p16,.flags=R4LIBRARIES_PRESENT};
 a[17] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p17,.flags=R4LIBRARIES_PRESENT};
 a[18] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p18,.flags=R4LIBRARIES_PRESENT};
 a[19] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p19,.flags=R4LIBRARIES_PRESENT};
 a[20] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p20,.flags=R4LIBRARIES_PRESENT};
 a[21] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p21,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,148u,a,22u,output);
}
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor_from_fields(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor *output, uint32_t p0, uint32_t p1, uint32_t p2, uint32_t p3, uint32_t p4, uint32_t p5, uint32_t p6, uint32_t p7, int32_t p8, int32_t p9, int32_t p10, int32_t p11, int32_t p12, int32_t p13, int32_t p14, int32_t p15, int32_t p16, uint32_t p17, uint32_t p18, uint32_t p19, uint32_t p20, uint32_t p21) {
 R4LibrariesSlot a[22]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4LIBRARIES_PRESENT};
 a[7] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p7,.flags=R4LIBRARIES_PRESENT};
 a[8] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p8,.flags=R4LIBRARIES_PRESENT};
 a[9] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p9,.flags=R4LIBRARIES_PRESENT};
 a[10] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p10,.flags=R4LIBRARIES_PRESENT};
 a[11] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p11,.flags=R4LIBRARIES_PRESENT};
 a[12] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p12,.flags=R4LIBRARIES_PRESENT};
 a[13] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p13,.flags=R4LIBRARIES_PRESENT};
 a[14] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p14,.flags=R4LIBRARIES_PRESENT};
 a[15] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p15,.flags=R4LIBRARIES_PRESENT};
 a[16] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p16,.flags=R4LIBRARIES_PRESENT};
 a[17] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p17,.flags=R4LIBRARIES_PRESENT};
 a[18] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p18,.flags=R4LIBRARIES_PRESENT};
 a[19] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p19,.flags=R4LIBRARIES_PRESENT};
 a[20] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p20,.flags=R4LIBRARIES_PRESENT};
 a[21] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p21,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,148u,a,22u,output);
}
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor_get_version(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,148u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor_set_version(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,148u,0u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor_get_size(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,148u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor_set_size(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,148u,1u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor_get_format(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,148u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor_set_format(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,148u,2u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor_get_kind(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,148u,3u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor_set_kind(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,148u,3u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor_get_color_model(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,148u,4u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor_set_color_model(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,148u,4u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor_get_flags(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,148u,5u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor_set_flags(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,148u,5u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor_get_intent(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,148u,6u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor_set_intent(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,148u,6u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor_get_reserved(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,148u,7u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor_set_reserved(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,148u,7u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor_get_red_x(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,148u,8u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor_set_red_x(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor *self, int32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,148u,8u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor_get_red_y(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,148u,9u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor_set_red_y(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor *self, int32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,148u,9u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor_get_red_z(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,148u,10u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor_set_red_z(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor *self, int32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,148u,10u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor_get_green_x(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,148u,11u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor_set_green_x(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor *self, int32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,148u,11u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor_get_green_y(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,148u,12u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor_set_green_y(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor *self, int32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,148u,12u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor_get_green_z(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,148u,13u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor_set_green_z(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor *self, int32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,148u,13u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor_get_blue_x(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,148u,14u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor_set_blue_x(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor *self, int32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,148u,14u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor_get_blue_y(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,148u,15u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor_set_blue_y(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor *self, int32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,148u,15u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor_get_blue_z(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,148u,16u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor_set_blue_z(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor *self, int32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,148u,16u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor_get_gamma_red(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,148u,17u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor_set_gamma_red(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,148u,17u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor_get_gamma_green(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,148u,18u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor_set_gamma_green(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,148u,18u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor_get_gamma_blue(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,148u,19u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor_set_gamma_blue(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,148u,19u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor_get_profile_bytes(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,148u,20u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor_set_profile_bytes(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,148u,20u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor_get_reserved1(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,148u,21u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor_set_reserved1(R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,148u,21u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor_inspect(const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,148u,(void *)self,0); }
static inline R4LibrariesSlot R4ImgHelpersRasterContext_create(R4ImgHelpersRasterContext *output, const R4Lib_R4IMG_Bindings_Zig_r4img_abi_RasterV1Client * p0) {
 R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,149u,a,1u,output);
}
static inline R4LibrariesSlot R4ImgHelpersRasterContext_from_fields(R4ImgHelpersRasterContext *output, const R4Lib_R4IMG_Bindings_Zig_r4img_abi_RasterV1Client * p0) {
 R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,149u,a,1u,output);
}
static inline R4LibrariesSlot R4ImgHelpersRasterContext_get_client(const R4ImgHelpersRasterContext *self, R4Lib_R4IMG_Bindings_Zig_r4img_abi_RasterV1Client *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,149u,0u,(void *)self,0,output); }
static inline R4LibrariesSlot R4ImgHelpersRasterContext_set_client(R4ImgHelpersRasterContext *self, const R4Lib_R4IMG_Bindings_Zig_r4img_abi_RasterV1Client * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,149u,0u,self,a,0); }
static inline R4LibrariesSlot R4ImgHelpersRasterContext_inspect(const R4ImgHelpersRasterContext *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,149u,(void *)self,0); }
static inline R4LibrariesSlot R4ImgHelpersImage16_create(R4ImgHelpersImage16 *output, const R4ImgHelpersInfo * p0, const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor * p1, uint16_t * p2, uintptr_t n2) {
 R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.length=n2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,151u,a,3u,output);
}
static inline R4LibrariesSlot R4ImgHelpersImage16_from_fields(R4ImgHelpersImage16 *output, const R4ImgHelpersInfo * p0, const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor * p1, uint16_t * p2, uintptr_t n2) {
 R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.length=n2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,151u,a,3u,output);
}
static inline R4LibrariesSlot R4ImgHelpersImage16_get_info(const R4ImgHelpersImage16 *self, R4ImgHelpersInfo *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,151u,0u,(void *)self,0,output); }
static inline R4LibrariesSlot R4ImgHelpersImage16_set_info(R4ImgHelpersImage16 *self, const R4ImgHelpersInfo * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,151u,0u,self,a,0); }
static inline R4LibrariesSlot R4ImgHelpersImage16_get_color(const R4ImgHelpersImage16 *self, R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,151u,1u,(void *)self,0,output); }
static inline R4LibrariesSlot R4ImgHelpersImage16_set_color(R4ImgHelpersImage16 *self, const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,151u,1u,self,a,0); }
static inline R4LibrariesSlot R4ImgHelpersImage16_get_rgba(const R4ImgHelpersImage16 *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,151u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4ImgHelpersImage16_set_rgba(R4ImgHelpersImage16 *self, uint16_t * p0, uintptr_t n0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,151u,2u,self,a,0); }
static inline R4LibrariesSlot R4ImgHelpersImage16_inspect(const R4ImgHelpersImage16 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,151u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value152_create(R4Lib_Value152 *output, uint16_t * p0, uintptr_t n0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,152u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value152_inspect(const R4Lib_Value152 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,152u,(void *)self,0); }
static inline R4LibrariesSlot R4ImgHelpersDecoderDiagnostic_create(R4ImgHelpersDecoderDiagnostic *output, uint64_t p0, uint8_t p1) {
 R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,153u,a,2u,output);
}
static inline R4LibrariesSlot R4ImgHelpersDecoderDiagnostic_from_fields(R4ImgHelpersDecoderDiagnostic *output, uint64_t p0, uint8_t p1) {
 R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,153u,a,2u,output);
}
static inline R4LibrariesSlot R4ImgHelpersDecoderDiagnostic_get_scratch_peak(const R4ImgHelpersDecoderDiagnostic *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,153u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4ImgHelpersDecoderDiagnostic_set_scratch_peak(R4ImgHelpersDecoderDiagnostic *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,153u,0u,self,a,0); }
static inline R4LibrariesSlot R4ImgHelpersDecoderDiagnostic_get_allocation_failed(const R4ImgHelpersDecoderDiagnostic *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,153u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4ImgHelpersDecoderDiagnostic_set_allocation_failed(R4ImgHelpersDecoderDiagnostic *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,153u,1u,self,a,0); }
static inline R4LibrariesSlot R4ImgHelpersDecoderDiagnostic_inspect(const R4ImgHelpersDecoderDiagnostic *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,153u,(void *)self,0); }
static inline R4LibrariesSlot R4ImgHelpersContext_create(R4ImgHelpersContext *output, const R4Lib_R4IMG_Bindings_Zig_r4img_abi_ApiV1Client * p0) {
 R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,154u,a,1u,output);
}
static inline R4LibrariesSlot R4ImgHelpersContext_from_fields(R4ImgHelpersContext *output, const R4Lib_R4IMG_Bindings_Zig_r4img_abi_ApiV1Client * p0) {
 R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,154u,a,1u,output);
}
static inline R4LibrariesSlot R4ImgHelpersContext_get_client(const R4ImgHelpersContext *self, R4Lib_R4IMG_Bindings_Zig_r4img_abi_ApiV1Client *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,154u,0u,(void *)self,0,output); }
static inline R4LibrariesSlot R4ImgHelpersContext_set_client(R4ImgHelpersContext *self, const R4Lib_R4IMG_Bindings_Zig_r4img_abi_ApiV1Client * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,154u,0u,self,a,0); }
static inline R4LibrariesSlot R4ImgHelpersContext_inspect(const R4ImgHelpersContext *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,154u,(void *)self,0); }
static inline R4LibrariesSlot R4ImgHelpersPngContext_create(R4ImgHelpersPngContext *output, const R4Lib_R4IMG_Bindings_Zig_r4img_abi_PngV1Client * p0) {
 R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,156u,a,1u,output);
}
static inline R4LibrariesSlot R4ImgHelpersPngContext_from_fields(R4ImgHelpersPngContext *output, const R4Lib_R4IMG_Bindings_Zig_r4img_abi_PngV1Client * p0) {
 R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,156u,a,1u,output);
}
static inline R4LibrariesSlot R4ImgHelpersPngContext_get_client(const R4ImgHelpersPngContext *self, R4Lib_R4IMG_Bindings_Zig_r4img_abi_PngV1Client *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,156u,0u,(void *)self,0,output); }
static inline R4LibrariesSlot R4ImgHelpersPngContext_set_client(R4ImgHelpersPngContext *self, const R4Lib_R4IMG_Bindings_Zig_r4img_abi_PngV1Client * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,156u,0u,self,a,0); }
static inline R4LibrariesSlot R4ImgHelpersPngContext_inspect(const R4ImgHelpersPngContext *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,156u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Policy_create(R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Policy *output) {
 R4LibrariesSlot a[7]={0};
 a[0].flags=R4LIBRARIES_DEFAULT;
 a[1].flags=R4LIBRARIES_DEFAULT;
 a[2].flags=R4LIBRARIES_DEFAULT;
 a[3].flags=R4LIBRARIES_DEFAULT;
 a[4].flags=R4LIBRARIES_DEFAULT;
 a[5].flags=R4LIBRARIES_DEFAULT;
 a[6].flags=R4LIBRARIES_DEFAULT;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,158u,a,7u,output);
}
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Policy_from_fields(R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Policy *output, uint8_t p0, uint8_t p1, uint8_t p2, uint32_t p3, uint32_t p4, uint32_t p5, uint32_t p6) {
 R4LibrariesSlot a[7]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,158u,a,7u,output);
}
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Policy_get_untagged_srgb(const R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Policy *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,158u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Policy_set_untagged_srgb(R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Policy *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,158u,0u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Policy_get_missing_chromaticities_srgb(const R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Policy *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,158u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Policy_set_missing_chromaticities_srgb(R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Policy *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,158u,1u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Policy_get_missing_gamma_srgb(const R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Policy *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,158u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Policy_set_missing_gamma_srgb(R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Policy *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,158u,2u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Policy_get_sdr_white(const R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Policy *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,158u,3u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Policy_set_sdr_white(R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Policy *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,158u,3u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Policy_get_hdr_white(const R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Policy *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,158u,4u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Policy_set_hdr_white(R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Policy *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,158u,4u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Policy_get_pq_peak(const R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Policy *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,158u,5u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Policy_set_pq_peak(R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Policy *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,158u,5u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Policy_get_hlg_peak(const R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Policy *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,158u,6u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Policy_set_hlg_peak(R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Policy *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,158u,6u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Policy_inspect(const R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Policy *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,158u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Characterization_create(R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Characterization *output, const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription * p0) {
 R4LibrariesSlot a[5]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1].flags=R4LIBRARIES_DEFAULT;
 a[2].flags=R4LIBRARIES_DEFAULT;
 a[3].flags=R4LIBRARIES_DEFAULT;
 a[4].flags=R4LIBRARIES_DEFAULT;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,159u,a,5u,output);
}
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Characterization_from_fields(R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Characterization *output, const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription * p0, R4LibrariesSlot p1, uint8_t p2, uint8_t p3, uint32_t p4) {
 R4LibrariesSlot a[5]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = p1;
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,159u,a,5u,output);
}
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Characterization_get_description(const R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Characterization *self, R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,159u,0u,(void *)self,0,output); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Characterization_set_description(R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Characterization *self, const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,159u,0u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Characterization_get_definition(const R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Characterization *self, R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,159u,1u,(void *)self,0,output); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Characterization_set_definition(R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Characterization *self, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,159u,1u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Characterization_get_embedded_profile(const R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Characterization *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,159u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Characterization_set_embedded_profile(R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Characterization *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,159u,2u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Characterization_get_assumed(const R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Characterization *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,159u,3u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Characterization_set_assumed(R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Characterization *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,159u,3u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Characterization_get_intent(const R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Characterization *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,159u,4u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Characterization_set_intent(R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Characterization *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,159u,4u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Characterization_inspect(const R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Characterization *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,159u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription_create(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription *output, uint32_t p0, uint32_t p1, uint32_t p2, uint32_t p3, uint32_t p4, uint32_t p5, uint32_t p6, uint32_t p7, uint32_t p8, uint32_t p9, uint32_t p10, uint32_t p11) {
 R4LibrariesSlot a[12]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4LIBRARIES_PRESENT};
 a[7] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p7,.flags=R4LIBRARIES_PRESENT};
 a[8] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p8,.flags=R4LIBRARIES_PRESENT};
 a[9] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p9,.flags=R4LIBRARIES_PRESENT};
 a[10] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p10,.flags=R4LIBRARIES_PRESENT};
 a[11] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p11,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,160u,a,12u,output);
}
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription_from_fields(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription *output, uint32_t p0, uint32_t p1, uint32_t p2, uint32_t p3, uint32_t p4, uint32_t p5, uint32_t p6, uint32_t p7, uint32_t p8, uint32_t p9, uint32_t p10, uint32_t p11) {
 R4LibrariesSlot a[12]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4LIBRARIES_PRESENT};
 a[7] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p7,.flags=R4LIBRARIES_PRESENT};
 a[8] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p8,.flags=R4LIBRARIES_PRESENT};
 a[9] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p9,.flags=R4LIBRARIES_PRESENT};
 a[10] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p10,.flags=R4LIBRARIES_PRESENT};
 a[11] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p11,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,160u,a,12u,output);
}
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription_get_version(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,160u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription_set_version(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,160u,0u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription_get_size(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,160u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription_set_size(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,160u,1u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription_get_primaries(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,160u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription_set_primaries(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,160u,2u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription_get_transfer(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,160u,3u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription_set_transfer(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,160u,3u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription_get_range(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,160u,4u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription_set_range(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,160u,4u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription_get_alpha(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,160u,5u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription_set_alpha(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,160u,5u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription_get_precision(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,160u,6u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription_set_precision(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,160u,6u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription_get_flags(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,160u,7u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription_set_flags(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,160u,7u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription_get_reference_white(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,160u,8u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription_set_reference_white(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,160u,8u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription_get_peak(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,160u,9u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription_set_peak(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,160u,9u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription_get_black(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,160u,10u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription_set_black(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,160u,10u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription_get_reserved(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,160u,11u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription_set_reserved(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,160u,11u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription_inspect(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,160u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value161_create(R4Lib_Value161 *output, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,161u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value161_inspect(const R4Lib_Value161 *self, R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,161u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition_create(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition *output, uint32_t p0, uint32_t p1, uint32_t p2, uint32_t p3, uint32_t p4, uint32_t p5, uint32_t p6, uint32_t p7, uint32_t p8, uint32_t p9, uint32_t p10, uint32_t p11, uint32_t p12, uint32_t p13, uint32_t p14, uint32_t p15) {
 R4LibrariesSlot a[16]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4LIBRARIES_PRESENT};
 a[7] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p7,.flags=R4LIBRARIES_PRESENT};
 a[8] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p8,.flags=R4LIBRARIES_PRESENT};
 a[9] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p9,.flags=R4LIBRARIES_PRESENT};
 a[10] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p10,.flags=R4LIBRARIES_PRESENT};
 a[11] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p11,.flags=R4LIBRARIES_PRESENT};
 a[12] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p12,.flags=R4LIBRARIES_PRESENT};
 a[13] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p13,.flags=R4LIBRARIES_PRESENT};
 a[14] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p14,.flags=R4LIBRARIES_PRESENT};
 a[15] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p15,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,162u,a,16u,output);
}
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition_from_fields(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition *output, uint32_t p0, uint32_t p1, uint32_t p2, uint32_t p3, uint32_t p4, uint32_t p5, uint32_t p6, uint32_t p7, uint32_t p8, uint32_t p9, uint32_t p10, uint32_t p11, uint32_t p12, uint32_t p13, uint32_t p14, uint32_t p15) {
 R4LibrariesSlot a[16]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4LIBRARIES_PRESENT};
 a[7] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p7,.flags=R4LIBRARIES_PRESENT};
 a[8] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p8,.flags=R4LIBRARIES_PRESENT};
 a[9] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p9,.flags=R4LIBRARIES_PRESENT};
 a[10] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p10,.flags=R4LIBRARIES_PRESENT};
 a[11] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p11,.flags=R4LIBRARIES_PRESENT};
 a[12] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p12,.flags=R4LIBRARIES_PRESENT};
 a[13] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p13,.flags=R4LIBRARIES_PRESENT};
 a[14] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p14,.flags=R4LIBRARIES_PRESENT};
 a[15] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p15,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,162u,a,16u,output);
}
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition_get_version(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,162u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition_set_version(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,162u,0u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition_get_size(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,162u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition_set_size(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,162u,1u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition_get_color_model(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,162u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition_set_color_model(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,162u,2u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition_get_curve(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,162u,3u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition_set_curve(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,162u,3u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition_get_white_x(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,162u,4u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition_set_white_x(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,162u,4u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition_get_white_y(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,162u,5u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition_set_white_y(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,162u,5u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition_get_red_x(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,162u,6u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition_set_red_x(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,162u,6u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition_get_red_y(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,162u,7u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition_set_red_y(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,162u,7u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition_get_green_x(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,162u,8u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition_set_green_x(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,162u,8u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition_get_green_y(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,162u,9u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition_set_green_y(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,162u,9u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition_get_blue_x(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,162u,10u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition_set_blue_x(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,162u,10u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition_get_blue_y(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,162u,11u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition_set_blue_y(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,162u,11u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition_get_gamma_red(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,162u,12u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition_set_gamma_red(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,162u,12u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition_get_gamma_green(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,162u,13u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition_set_gamma_green(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,162u,13u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition_get_gamma_blue(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,162u,14u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition_set_gamma_blue(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,162u,14u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition_get_reserved(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,162u,15u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition_set_reserved(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,162u,15u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition_inspect(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfileDefinition *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,162u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Result_create(R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Result *output, const R4ImgHelpersInfo * p0, const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor * p1, uint8_t p2) {
 R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,163u,a,3u,output);
}
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Result_from_fields(R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Result *output, const R4ImgHelpersInfo * p0, const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor * p1, uint8_t p2) {
 R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,163u,a,3u,output);
}
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Result_get_info(const R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Result *self, R4ImgHelpersInfo *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,163u,0u,(void *)self,0,output); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Result_set_info(R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Result *self, const R4ImgHelpersInfo * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,163u,0u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Result_get_metadata(const R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Result *self, R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,163u,1u,(void *)self,0,output); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Result_set_metadata(R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Result *self, const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,163u,1u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Result_get_assumed(const R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Result *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,163u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Result_set_assumed(R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Result *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,163u,2u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Result_inspect(const R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Result *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,163u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__RasterResult_create(R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__RasterResult *output, const R4ImgHelpersInfo * p0, const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor * p1, uint8_t p2) {
 R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,164u,a,3u,output);
}
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__RasterResult_from_fields(R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__RasterResult *output, const R4ImgHelpersInfo * p0, const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor * p1, uint8_t p2) {
 R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,164u,a,3u,output);
}
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__RasterResult_get_info(const R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__RasterResult *self, R4ImgHelpersInfo *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,164u,0u,(void *)self,0,output); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__RasterResult_set_info(R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__RasterResult *self, const R4ImgHelpersInfo * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,164u,0u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__RasterResult_get_metadata(const R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__RasterResult *self, R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,164u,1u,(void *)self,0,output); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__RasterResult_set_metadata(R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__RasterResult *self, const R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,164u,1u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__RasterResult_get_assumed(const R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__RasterResult *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,164u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__RasterResult_set_assumed(R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__RasterResult *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,164u,2u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__RasterResult_inspect(const R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__RasterResult *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,164u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value165_inspect(const R4Lib_Value165 *self, R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Characterization *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,165u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value167_create(R4Lib_Value167 *output, const R4ImgHelpersContext * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,167u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value167_inspect(const R4Lib_Value167 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,167u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value168_create(R4Lib_Value168 *output, const R4ImgHelpersPngContext * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,168u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value168_inspect(const R4Lib_Value168 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,168u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value169_create(R4Lib_Value169 *output, const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_ColorV1Client * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,169u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value169_inspect(const R4Lib_Value169 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,169u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value171_create(R4Lib_Value171 *output, const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorImage * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,171u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value171_inspect(const R4Lib_Value171 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,171u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorImage_create(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorImage *output, uint32_t p0, uint32_t p1, const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxCpuImage * p2, const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription * p3, const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfile * p4) {
 R4LibrariesSlot a[5]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.ptr=(void *)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.ptr=(void *)p4,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,172u,a,5u,output);
}
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorImage_from_fields(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorImage *output, uint32_t p0, uint32_t p1, const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxCpuImage * p2, const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription * p3, const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfile * p4) {
 R4LibrariesSlot a[5]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.ptr=(void *)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.ptr=(void *)p4,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,172u,a,5u,output);
}
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorImage_get_version(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorImage *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,172u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorImage_set_version(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorImage *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,172u,0u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorImage_get_size(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorImage *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,172u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorImage_set_size(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorImage *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,172u,1u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorImage_get_image(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorImage *self, R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxCpuImage *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,172u,2u,(void *)self,0,output); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorImage_set_image(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorImage *self, const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxCpuImage * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,172u,2u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorImage_get_description(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorImage *self, R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,172u,3u,(void *)self,0,output); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorImage_set_description(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorImage *self, const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorDescription * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,172u,3u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorImage_get_profile(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorImage *self, R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfile *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,172u,4u,(void *)self,0,output); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorImage_set_profile(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorImage *self, const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfile * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,172u,4u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorImage_inspect(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorImage *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,172u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxCpuImage_create(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxCpuImage *output, uint64_t p0, uint64_t p1, uint64_t p2, uint32_t p3, uint32_t p4, uint32_t p5, uint32_t p6) {
 R4LibrariesSlot a[7]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,173u,a,7u,output);
}
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxCpuImage_from_fields(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxCpuImage *output, uint64_t p0, uint64_t p1, uint64_t p2, uint32_t p3, uint32_t p4, uint32_t p5, uint32_t p6) {
 R4LibrariesSlot a[7]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,173u,a,7u,output);
}
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxCpuImage_get_cpu_address(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxCpuImage *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,173u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxCpuImage_set_cpu_address(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxCpuImage *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,173u,0u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxCpuImage_get_byte_length(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxCpuImage *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,173u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxCpuImage_set_byte_length(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxCpuImage *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,173u,1u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxCpuImage_get_pitch(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxCpuImage *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,173u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxCpuImage_set_pitch(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxCpuImage *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,173u,2u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxCpuImage_get_width(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxCpuImage *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,173u,3u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxCpuImage_set_width(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxCpuImage *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,173u,3u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxCpuImage_get_height(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxCpuImage *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,173u,4u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxCpuImage_set_height(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxCpuImage *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,173u,4u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxCpuImage_get_format(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxCpuImage *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,173u,5u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxCpuImage_set_format(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxCpuImage *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,173u,5u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxCpuImage_get_reserved(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxCpuImage *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,173u,6u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxCpuImage_set_reserved(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxCpuImage *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,173u,6u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxCpuImage_inspect(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxCpuImage *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,173u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfile_create(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfile *output, uint64_t p0, uint64_t p1) {
 R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,174u,a,2u,output);
}
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfile_from_fields(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfile *output, uint64_t p0, uint64_t p1) {
 R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,174u,a,2u,output);
}
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfile_get_address(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfile *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,174u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfile_set_address(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfile *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,174u,0u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfile_get_generation(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfile *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,174u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfile_set_generation(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfile *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,174u,1u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfile_inspect(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorProfile *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,174u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value175_create(R4Lib_Value175 *output, const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorTransform * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,175u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value175_inspect(const R4Lib_Value175 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,175u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorTransform_create(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorTransform *output, uint32_t p0, uint32_t p1, const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxRect * p2, const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxRect * p3, uint32_t p4, uint32_t p5, uint32_t p6, uint32_t p7, uint64_t p8) {
 R4LibrariesSlot a[9]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.ptr=(void *)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4LIBRARIES_PRESENT};
 a[7] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p7,.flags=R4LIBRARIES_PRESENT};
 a[8] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p8,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,176u,a,9u,output);
}
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorTransform_from_fields(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorTransform *output, uint32_t p0, uint32_t p1, const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxRect * p2, const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxRect * p3, uint32_t p4, uint32_t p5, uint32_t p6, uint32_t p7, uint64_t p8) {
 R4LibrariesSlot a[9]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.ptr=(void *)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4LIBRARIES_PRESENT};
 a[7] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p7,.flags=R4LIBRARIES_PRESENT};
 a[8] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p8,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,176u,a,9u,output);
}
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorTransform_get_version(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorTransform *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,176u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorTransform_set_version(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorTransform *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,176u,0u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorTransform_get_size(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorTransform *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,176u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorTransform_set_size(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorTransform *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,176u,1u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorTransform_get_source_rect(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorTransform *self, R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxRect *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,176u,2u,(void *)self,0,output); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorTransform_set_source_rect(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorTransform *self, const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxRect * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,176u,2u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorTransform_get_target_rect(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorTransform *self, R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxRect *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,176u,3u,(void *)self,0,output); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorTransform_set_target_rect(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorTransform *self, const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxRect * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,176u,3u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorTransform_get_sampler(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorTransform *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,176u,4u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorTransform_set_sampler(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorTransform *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,176u,4u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorTransform_get_operation(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorTransform *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,176u,5u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorTransform_set_operation(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorTransform *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,176u,5u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorTransform_get_opacity(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorTransform *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,176u,6u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorTransform_set_opacity(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorTransform *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,176u,6u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorTransform_get_flags(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorTransform *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,176u,7u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorTransform_set_flags(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorTransform *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,176u,7u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorTransform_get_pixel_budget(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorTransform *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,176u,8u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorTransform_set_pixel_budget(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorTransform *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,176u,8u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorTransform_inspect(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxColorTransform *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,176u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxRect_create(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxRect *output, uint32_t p0, uint32_t p1, uint32_t p2, uint32_t p3) {
 R4LibrariesSlot a[4]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,177u,a,4u,output);
}
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxRect_from_fields(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxRect *output, uint32_t p0, uint32_t p1, uint32_t p2, uint32_t p3) {
 R4LibrariesSlot a[4]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,177u,a,4u,output);
}
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxRect_get_x(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxRect *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,177u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxRect_set_x(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxRect *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,177u,0u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxRect_get_y(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxRect *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,177u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxRect_set_y(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxRect *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,177u,1u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxRect_get_width(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxRect *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,177u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxRect_set_width(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxRect *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,177u,2u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxRect_get_height(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxRect *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,177u,3u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxRect_set_height(R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxRect *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,177u,3u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxRect_inspect(const R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_R4GfxRect *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,177u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value178_inspect(const R4Lib_Value178 *self, R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__Result *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,178u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value179_create(R4Lib_Value179 *output, const R4ImgHelpersRasterContext * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,179u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value179_inspect(const R4Lib_Value179 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,179u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value180_inspect(const R4Lib_Value180 *self, R4Lib_R4IMG_Bindings_Zig_color_Decoder_R4GFX_Bindings_Zig_r4gfx_abi__RasterResult *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,180u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value182_create(R4Lib_Value182 *output, const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoRuntime * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,182u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value182_inspect(const R4Lib_Value182 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,182u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoRuntime_create(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoRuntime *output, uint64_t p0, uint64_t p1) {
 R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,183u,a,2u,output);
}
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoRuntime_from_fields(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoRuntime *output, uint64_t p0, uint64_t p1) {
 R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,183u,a,2u,output);
}
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoRuntime_get_address(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoRuntime *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,183u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoRuntime_set_address(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoRuntime *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,183u,0u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoRuntime_get_generation(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoRuntime *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,183u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoRuntime_set_generation(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoRuntime *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,183u,1u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoRuntime_inspect(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoRuntime *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,183u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value184_create(R4Lib_Value184 *output, R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,184u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value184_inspect(const R4Lib_Value184 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,184u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps_create(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps *output, uint32_t p0, uint32_t p1, const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCapsQuery * p2, uint32_t p3, uint32_t p4, uint32_t p5, uint32_t p6, uint32_t p7, uint32_t p8, uint64_t p9, uint32_t p10, uint32_t p11, uint64_t p12, uint64_t p13, uint32_t p14, uint32_t p15) {
 R4LibrariesSlot a[16]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4LIBRARIES_PRESENT};
 a[7] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p7,.flags=R4LIBRARIES_PRESENT};
 a[8] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p8,.flags=R4LIBRARIES_PRESENT};
 a[9] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p9,.flags=R4LIBRARIES_PRESENT};
 a[10] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p10,.flags=R4LIBRARIES_PRESENT};
 a[11] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p11,.flags=R4LIBRARIES_PRESENT};
 a[12] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p12,.flags=R4LIBRARIES_PRESENT};
 a[13] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p13,.flags=R4LIBRARIES_PRESENT};
 a[14] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p14,.flags=R4LIBRARIES_PRESENT};
 a[15] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p15,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,185u,a,16u,output);
}
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps_from_fields(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps *output, uint32_t p0, uint32_t p1, const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCapsQuery * p2, uint32_t p3, uint32_t p4, uint32_t p5, uint32_t p6, uint32_t p7, uint32_t p8, uint64_t p9, uint32_t p10, uint32_t p11, uint64_t p12, uint64_t p13, uint32_t p14, uint32_t p15) {
 R4LibrariesSlot a[16]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4LIBRARIES_PRESENT};
 a[7] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p7,.flags=R4LIBRARIES_PRESENT};
 a[8] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p8,.flags=R4LIBRARIES_PRESENT};
 a[9] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p9,.flags=R4LIBRARIES_PRESENT};
 a[10] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p10,.flags=R4LIBRARIES_PRESENT};
 a[11] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p11,.flags=R4LIBRARIES_PRESENT};
 a[12] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p12,.flags=R4LIBRARIES_PRESENT};
 a[13] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p13,.flags=R4LIBRARIES_PRESENT};
 a[14] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p14,.flags=R4LIBRARIES_PRESENT};
 a[15] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p15,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,185u,a,16u,output);
}
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps_get_version(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,185u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps_set_version(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,185u,0u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps_get_size(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,185u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps_set_size(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,185u,1u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps_get_query(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps *self, R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCapsQuery *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,185u,2u,(void *)self,0,output); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps_set_query(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps *self, const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCapsQuery * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,185u,2u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps_get_min_width(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,185u,3u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps_set_min_width(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,185u,3u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps_get_min_height(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,185u,4u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps_set_min_height(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,185u,4u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps_get_max_width(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,185u,5u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps_set_max_width(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,185u,5u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps_get_max_height(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,185u,6u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps_set_max_height(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,185u,6u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps_get_max_level(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,185u,7u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps_set_max_level(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,185u,7u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps_get_output_formats(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,185u,8u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps_set_output_formats(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,185u,8u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps_get_max_packet_bytes(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,185u,9u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps_set_max_packet_bytes(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,185u,9u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps_get_max_pending_packets(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,185u,10u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps_set_max_pending_packets(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,185u,10u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps_get_max_frame_leases(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,185u,11u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps_set_max_frame_leases(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,185u,11u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps_get_device_generation(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,185u,12u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps_set_device_generation(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,185u,12u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps_get_reset_generation(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,185u,13u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps_set_reset_generation(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,185u,13u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps_get_flags(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,185u,14u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps_set_flags(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,185u,14u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps_get_reserved(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,185u,15u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps_set_reserved(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,185u,15u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps_inspect(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCaps *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,185u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCapsQuery_create(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCapsQuery *output, uint32_t p0, uint32_t p1, uint32_t p2, uint32_t p3, uint32_t p4, uint32_t p5, uint32_t p6, uint32_t p7) {
 R4LibrariesSlot a[8]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4LIBRARIES_PRESENT};
 a[7] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p7,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,186u,a,8u,output);
}
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCapsQuery_from_fields(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCapsQuery *output, uint32_t p0, uint32_t p1, uint32_t p2, uint32_t p3, uint32_t p4, uint32_t p5, uint32_t p6, uint32_t p7) {
 R4LibrariesSlot a[8]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4LIBRARIES_PRESENT};
 a[7] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p7,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,186u,a,8u,output);
}
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCapsQuery_get_version(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCapsQuery *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,186u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCapsQuery_set_version(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCapsQuery *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,186u,0u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCapsQuery_get_size(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCapsQuery *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,186u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCapsQuery_set_size(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCapsQuery *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,186u,1u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCapsQuery_get_backend(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCapsQuery *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,186u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCapsQuery_set_backend(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCapsQuery *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,186u,2u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCapsQuery_get_adapter_id(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCapsQuery *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,186u,3u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCapsQuery_set_adapter_id(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCapsQuery *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,186u,3u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCapsQuery_get_codec(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCapsQuery *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,186u,4u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCapsQuery_set_codec(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCapsQuery *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,186u,4u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCapsQuery_get_profile(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCapsQuery *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,186u,5u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCapsQuery_set_profile(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCapsQuery *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,186u,5u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCapsQuery_get_bit_depth(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCapsQuery *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,186u,6u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCapsQuery_set_bit_depth(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCapsQuery *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,186u,6u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCapsQuery_get_chroma(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCapsQuery *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,186u,7u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCapsQuery_set_chroma(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCapsQuery *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,186u,7u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCapsQuery_inspect(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoCapsQuery *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,186u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value187_create(R4Lib_Value187 *output, R4ImgNativeJpeg * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,187u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value187_inspect(const R4Lib_Value187 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,187u,(void *)self,0); }
static inline R4LibrariesSlot R4ImgNativeJpeg_create(R4ImgNativeJpeg *output, const R4Lib_R4VIDEO_Bindings_Zig_r4video_VideoV1Client * p0, const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoDecoder * p1, const uint8_t * p2, uintptr_t n2) {
 R4LibrariesSlot a[9]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.length=n2,.flags=R4LIBRARIES_PRESENT};
 a[3].flags=R4LIBRARIES_DEFAULT;
 a[4].flags=R4LIBRARIES_DEFAULT;
 a[5].flags=R4LIBRARIES_DEFAULT;
 a[6].flags=R4LIBRARIES_DEFAULT;
 a[7].flags=R4LIBRARIES_DEFAULT;
 a[8].flags=R4LIBRARIES_DEFAULT;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,188u,a,9u,output);
}
static inline R4LibrariesSlot R4ImgNativeJpeg_from_fields(R4ImgNativeJpeg *output, const R4Lib_R4VIDEO_Bindings_Zig_r4video_VideoV1Client * p0, const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoDecoder * p1, const uint8_t * p2, uintptr_t n2, uint8_t p3, uint8_t p4, uint8_t p5, uint8_t p6, uint8_t p7, R4LibrariesSlot p8) {
 R4LibrariesSlot a[9]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.length=n2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4LIBRARIES_PRESENT};
 a[7] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p7,.flags=R4LIBRARIES_PRESENT};
 a[8] = p8;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,188u,a,9u,output);
}
static inline R4LibrariesSlot R4ImgNativeJpeg_get_api(const R4ImgNativeJpeg *self, R4Lib_R4VIDEO_Bindings_Zig_r4video_VideoV1Client *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,188u,0u,(void *)self,0,output); }
static inline R4LibrariesSlot R4ImgNativeJpeg_set_api(R4ImgNativeJpeg *self, const R4Lib_R4VIDEO_Bindings_Zig_r4video_VideoV1Client * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,188u,0u,self,a,0); }
static inline R4LibrariesSlot R4ImgNativeJpeg_get_decoder(const R4ImgNativeJpeg *self, R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoDecoder *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,188u,1u,(void *)self,0,output); }
static inline R4LibrariesSlot R4ImgNativeJpeg_set_decoder(R4ImgNativeJpeg *self, const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoDecoder * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,188u,1u,self,a,0); }
static inline R4LibrariesSlot R4ImgNativeJpeg_get_source(const R4ImgNativeJpeg *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,188u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4ImgNativeJpeg_set_source(R4ImgNativeJpeg *self, const uint8_t * p0, uintptr_t n0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,188u,2u,self,a,0); }
static inline R4LibrariesSlot R4ImgNativeJpeg_get_sent(const R4ImgNativeJpeg *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,188u,3u,(void *)self,0,0); }
static inline R4LibrariesSlot R4ImgNativeJpeg_set_sent(R4ImgNativeJpeg *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,188u,3u,self,a,0); }
static inline R4LibrariesSlot R4ImgNativeJpeg_get_draining(const R4ImgNativeJpeg *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,188u,4u,(void *)self,0,0); }
static inline R4LibrariesSlot R4ImgNativeJpeg_set_draining(R4ImgNativeJpeg *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,188u,4u,self,a,0); }
static inline R4LibrariesSlot R4ImgNativeJpeg_get_received(const R4ImgNativeJpeg *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,188u,5u,(void *)self,0,0); }
static inline R4LibrariesSlot R4ImgNativeJpeg_set_received(R4ImgNativeJpeg *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,188u,5u,self,a,0); }
static inline R4LibrariesSlot R4ImgNativeJpeg_get_closing(const R4ImgNativeJpeg *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,188u,6u,(void *)self,0,0); }
static inline R4LibrariesSlot R4ImgNativeJpeg_set_closing(R4ImgNativeJpeg *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,188u,6u,self,a,0); }
static inline R4LibrariesSlot R4ImgNativeJpeg_get_closed(const R4ImgNativeJpeg *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,188u,7u,(void *)self,0,0); }
static inline R4LibrariesSlot R4ImgNativeJpeg_set_closed(R4ImgNativeJpeg *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,188u,7u,self,a,0); }
static inline R4LibrariesSlot R4ImgNativeJpeg_get_held(const R4ImgNativeJpeg *self, R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoLease *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,188u,8u,(void *)self,0,output); }
static inline R4LibrariesSlot R4ImgNativeJpeg_set_held(R4ImgNativeJpeg *self, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,188u,8u,self,a,0); }
static inline R4LibrariesSlot R4ImgNativeJpeg_inspect(const R4ImgNativeJpeg *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,188u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoDecoder_create(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoDecoder *output, uint64_t p0, uint64_t p1) {
 R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,189u,a,2u,output);
}
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoDecoder_from_fields(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoDecoder *output, uint64_t p0, uint64_t p1) {
 R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,189u,a,2u,output);
}
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoDecoder_get_address(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoDecoder *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,189u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoDecoder_set_address(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoDecoder *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,189u,0u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoDecoder_get_generation(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoDecoder *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,189u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoDecoder_set_generation(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoDecoder *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,189u,1u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoDecoder_inspect(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoDecoder *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,189u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value190_create(R4Lib_Value190 *output, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,190u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value190_inspect(const R4Lib_Value190 *self, R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoLease *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,190u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoLease_create(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoLease *output, const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoDecoder * p0, uint64_t p1, uint64_t p2) {
 R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,191u,a,3u,output);
}
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoLease_from_fields(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoLease *output, const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoDecoder * p0, uint64_t p1, uint64_t p2) {
 R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,191u,a,3u,output);
}
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoLease_get_decoder(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoLease *self, R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoDecoder *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,191u,0u,(void *)self,0,output); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoLease_set_decoder(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoLease *self, const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoDecoder * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,191u,0u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoLease_get_token(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoLease *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,191u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoLease_set_token(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoLease *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,191u,1u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoLease_get_stream_generation(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoLease *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,191u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoLease_set_stream_generation(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoLease *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,191u,2u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoLease_inspect(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoLease *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,191u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value192_create(R4Lib_Value192 *output, R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,192u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value192_inspect(const R4Lib_Value192 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,192u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_create(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame *output, uint32_t p0, uint32_t p1, const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoLease * p2, uint64_t p3, int64_t p4, int64_t p5, uint64_t p6, uint32_t p7, uint32_t p8, uint32_t p9, uint32_t p10, uint32_t p11, uint32_t p12, uint32_t p13, uint32_t p14, uint32_t p15, uint32_t p16, const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor * p17, const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoPlane * p18, const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoPlane * p19, const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoPlane * p20, const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFence * p21, uint32_t p22, uint32_t p23) {
 R4LibrariesSlot a[24]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4LIBRARIES_PRESENT};
 a[7] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p7,.flags=R4LIBRARIES_PRESENT};
 a[8] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p8,.flags=R4LIBRARIES_PRESENT};
 a[9] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p9,.flags=R4LIBRARIES_PRESENT};
 a[10] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p10,.flags=R4LIBRARIES_PRESENT};
 a[11] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p11,.flags=R4LIBRARIES_PRESENT};
 a[12] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p12,.flags=R4LIBRARIES_PRESENT};
 a[13] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p13,.flags=R4LIBRARIES_PRESENT};
 a[14] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p14,.flags=R4LIBRARIES_PRESENT};
 a[15] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p15,.flags=R4LIBRARIES_PRESENT};
 a[16] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p16,.flags=R4LIBRARIES_PRESENT};
 a[17] = (R4LibrariesSlot){.ptr=(void *)p17,.flags=R4LIBRARIES_PRESENT};
 a[18] = (R4LibrariesSlot){.ptr=(void *)p18,.flags=R4LIBRARIES_PRESENT};
 a[19] = (R4LibrariesSlot){.ptr=(void *)p19,.flags=R4LIBRARIES_PRESENT};
 a[20] = (R4LibrariesSlot){.ptr=(void *)p20,.flags=R4LIBRARIES_PRESENT};
 a[21] = (R4LibrariesSlot){.ptr=(void *)p21,.flags=R4LIBRARIES_PRESENT};
 a[22] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p22,.flags=R4LIBRARIES_PRESENT};
 a[23] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p23,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,193u,a,24u,output);
}
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_from_fields(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame *output, uint32_t p0, uint32_t p1, const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoLease * p2, uint64_t p3, int64_t p4, int64_t p5, uint64_t p6, uint32_t p7, uint32_t p8, uint32_t p9, uint32_t p10, uint32_t p11, uint32_t p12, uint32_t p13, uint32_t p14, uint32_t p15, uint32_t p16, const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor * p17, const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoPlane * p18, const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoPlane * p19, const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoPlane * p20, const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFence * p21, uint32_t p22, uint32_t p23) {
 R4LibrariesSlot a[24]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4LIBRARIES_PRESENT};
 a[7] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p7,.flags=R4LIBRARIES_PRESENT};
 a[8] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p8,.flags=R4LIBRARIES_PRESENT};
 a[9] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p9,.flags=R4LIBRARIES_PRESENT};
 a[10] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p10,.flags=R4LIBRARIES_PRESENT};
 a[11] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p11,.flags=R4LIBRARIES_PRESENT};
 a[12] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p12,.flags=R4LIBRARIES_PRESENT};
 a[13] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p13,.flags=R4LIBRARIES_PRESENT};
 a[14] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p14,.flags=R4LIBRARIES_PRESENT};
 a[15] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p15,.flags=R4LIBRARIES_PRESENT};
 a[16] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p16,.flags=R4LIBRARIES_PRESENT};
 a[17] = (R4LibrariesSlot){.ptr=(void *)p17,.flags=R4LIBRARIES_PRESENT};
 a[18] = (R4LibrariesSlot){.ptr=(void *)p18,.flags=R4LIBRARIES_PRESENT};
 a[19] = (R4LibrariesSlot){.ptr=(void *)p19,.flags=R4LIBRARIES_PRESENT};
 a[20] = (R4LibrariesSlot){.ptr=(void *)p20,.flags=R4LIBRARIES_PRESENT};
 a[21] = (R4LibrariesSlot){.ptr=(void *)p21,.flags=R4LIBRARIES_PRESENT};
 a[22] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p22,.flags=R4LIBRARIES_PRESENT};
 a[23] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p23,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,193u,a,24u,output);
}
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_get_version(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,193u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_set_version(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,193u,0u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_get_size(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,193u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_set_size(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,193u,1u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_get_lease(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame *self, R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoLease *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,193u,2u,(void *)self,0,output); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_set_lease(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame *self, const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoLease * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,193u,2u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_get_tag(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,193u,3u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_set_tag(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,193u,3u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_get_pts_ns(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,193u,4u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_set_pts_ns(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame *self, int64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,193u,4u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_get_dts_ns(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,193u,5u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_set_dts_ns(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame *self, int64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,193u,5u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_get_duration_ns(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,193u,6u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_set_duration_ns(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,193u,6u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_get_coded_width(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,193u,7u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_set_coded_width(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,193u,7u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_get_coded_height(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,193u,8u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_set_coded_height(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,193u,8u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_get_crop_x(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,193u,9u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_set_crop_x(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,193u,9u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_get_crop_y(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,193u,10u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_set_crop_y(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,193u,10u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_get_crop_width(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,193u,11u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_set_crop_width(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,193u,11u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_get_crop_height(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,193u,12u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_set_crop_height(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,193u,12u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_get_sar_num(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,193u,13u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_set_sar_num(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,193u,13u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_get_sar_den(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,193u,14u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_set_sar_den(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,193u,14u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_get_format(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,193u,15u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_set_format(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,193u,15u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_get_plane_count(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,193u,16u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_set_plane_count(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,193u,16u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_get_color(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame *self, R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,193u,17u,(void *)self,0,output); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_set_color(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame *self, const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,193u,17u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_get_plane0(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame *self, R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoPlane *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,193u,18u,(void *)self,0,output); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_set_plane0(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame *self, const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoPlane * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,193u,18u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_get_plane1(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame *self, R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoPlane *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,193u,19u,(void *)self,0,output); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_set_plane1(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame *self, const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoPlane * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,193u,19u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_get_plane2(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame *self, R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoPlane *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,193u,20u,(void *)self,0,output); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_set_plane2(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame *self, const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoPlane * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,193u,20u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_get_ready(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame *self, R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFence *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,193u,21u,(void *)self,0,output); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_set_ready(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame *self, const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFence * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,193u,21u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_get_flags(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,193u,22u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_set_flags(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,193u,22u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_get_reserved(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,193u,23u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_set_reserved(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,193u,23u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame_inspect(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFrame *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,193u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor_create(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor *output, uint32_t p0, uint32_t p1, uint32_t p2, uint32_t p3, uint32_t p4, uint32_t p5, uint32_t p6, uint32_t p7, uint32_t p8, uint32_t p9, uint32_t p10, uint32_t p11) {
 R4LibrariesSlot a[12]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4LIBRARIES_PRESENT};
 a[7] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p7,.flags=R4LIBRARIES_PRESENT};
 a[8] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p8,.flags=R4LIBRARIES_PRESENT};
 a[9] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p9,.flags=R4LIBRARIES_PRESENT};
 a[10] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p10,.flags=R4LIBRARIES_PRESENT};
 a[11] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p11,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,194u,a,12u,output);
}
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor_from_fields(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor *output, uint32_t p0, uint32_t p1, uint32_t p2, uint32_t p3, uint32_t p4, uint32_t p5, uint32_t p6, uint32_t p7, uint32_t p8, uint32_t p9, uint32_t p10, uint32_t p11) {
 R4LibrariesSlot a[12]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4LIBRARIES_PRESENT};
 a[7] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p7,.flags=R4LIBRARIES_PRESENT};
 a[8] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p8,.flags=R4LIBRARIES_PRESENT};
 a[9] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p9,.flags=R4LIBRARIES_PRESENT};
 a[10] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p10,.flags=R4LIBRARIES_PRESENT};
 a[11] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p11,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,194u,a,12u,output);
}
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor_get_version(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,194u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor_set_version(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,194u,0u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor_get_size(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,194u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor_set_size(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,194u,1u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor_get_primaries(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,194u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor_set_primaries(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,194u,2u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor_get_transfer(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,194u,3u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor_set_transfer(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,194u,3u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor_get_range(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,194u,4u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor_set_range(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,194u,4u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor_get_matrix(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,194u,5u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor_set_matrix(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,194u,5u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor_get_chroma_location(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,194u,6u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor_set_chroma_location(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,194u,6u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor_get_bit_depth(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,194u,7u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor_set_bit_depth(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,194u,7u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor_get_reference_white(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,194u,8u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor_set_reference_white(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,194u,8u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor_get_peak(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,194u,9u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor_set_peak(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,194u,9u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor_get_black(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,194u,10u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor_set_black(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,194u,10u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor_get_flags(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,194u,11u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor_set_flags(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,194u,11u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor_inspect(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoColor *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,194u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoPlane_create(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoPlane *output, const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoBuffer * p0, const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoBuffer * p1, uint64_t p2, uint64_t p3, uint64_t p4, uint32_t p5, uint32_t p6) {
 R4LibrariesSlot a[7]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,195u,a,7u,output);
}
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoPlane_from_fields(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoPlane *output, const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoBuffer * p0, const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoBuffer * p1, uint64_t p2, uint64_t p3, uint64_t p4, uint32_t p5, uint32_t p6) {
 R4LibrariesSlot a[7]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,195u,a,7u,output);
}
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoPlane_get_buffer(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoPlane *self, R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoBuffer *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,195u,0u,(void *)self,0,output); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoPlane_set_buffer(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoPlane *self, const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoBuffer * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,195u,0u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoPlane_get_reference(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoPlane *self, R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoBuffer *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,195u,1u,(void *)self,0,output); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoPlane_set_reference(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoPlane *self, const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoBuffer * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,195u,1u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoPlane_get_offset(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoPlane *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,195u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoPlane_set_offset(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoPlane *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,195u,2u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoPlane_get_pitch(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoPlane *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,195u,3u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoPlane_set_pitch(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoPlane *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,195u,3u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoPlane_get_row_bytes(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoPlane *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,195u,4u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoPlane_set_row_bytes(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoPlane *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,195u,4u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoPlane_get_rows(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoPlane *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,195u,5u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoPlane_set_rows(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoPlane *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,195u,5u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoPlane_get_reserved(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoPlane *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,195u,6u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoPlane_set_reserved(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoPlane *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,195u,6u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoPlane_inspect(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoPlane *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,195u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoBuffer_create(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoBuffer *output, uint32_t p0, uint32_t p1, uint64_t p2) {
 R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,196u,a,3u,output);
}
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoBuffer_from_fields(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoBuffer *output, uint32_t p0, uint32_t p1, uint64_t p2) {
 R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,196u,a,3u,output);
}
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoBuffer_get_id(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoBuffer *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,196u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoBuffer_set_id(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoBuffer *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,196u,0u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoBuffer_get_reserved0(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoBuffer *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,196u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoBuffer_set_reserved0(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoBuffer *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,196u,1u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoBuffer_get_generation(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoBuffer *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,196u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoBuffer_set_generation(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoBuffer *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,196u,2u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoBuffer_inspect(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoBuffer *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,196u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFence_create(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFence *output, uint32_t p0, uint32_t p1, uint64_t p2, uint64_t p3, uint64_t p4, uint64_t p5) {
 R4LibrariesSlot a[6]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,197u,a,6u,output);
}
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFence_from_fields(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFence *output, uint32_t p0, uint32_t p1, uint64_t p2, uint64_t p3, uint64_t p4, uint64_t p5) {
 R4LibrariesSlot a[6]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,197u,a,6u,output);
}
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFence_get_slot(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFence *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,197u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFence_set_slot(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFence *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,197u,0u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFence_get_adapter_id(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFence *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,197u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFence_set_adapter_id(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFence *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,197u,1u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFence_get_timeline(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFence *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,197u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFence_set_timeline(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFence *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,197u,2u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFence_get_point(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFence *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,197u,3u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFence_set_point(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFence *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,197u,3u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFence_get_device_generation(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFence *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,197u,4u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFence_set_device_generation(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFence *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,197u,4u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFence_get_reset_generation(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFence *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,197u,5u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFence_set_reset_generation(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFence *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,197u,5u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFence_inspect(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFence *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,197u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value198_create(R4Lib_Value198 *output, const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoReceipt * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,198u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value198_inspect(const R4Lib_Value198 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,198u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoReceipt_create(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoReceipt *output, uint32_t p0, uint32_t p1, const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFence * p2, int32_t p3, uint32_t p4) {
 R4LibrariesSlot a[5]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,199u,a,5u,output);
}
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoReceipt_from_fields(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoReceipt *output, uint32_t p0, uint32_t p1, const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFence * p2, int32_t p3, uint32_t p4) {
 R4LibrariesSlot a[5]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,199u,a,5u,output);
}
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoReceipt_get_version(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoReceipt *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,199u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoReceipt_set_version(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoReceipt *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,199u,0u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoReceipt_get_size(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoReceipt *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,199u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoReceipt_set_size(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoReceipt *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,199u,1u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoReceipt_get_fence(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoReceipt *self, R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFence *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,199u,2u,(void *)self,0,output); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoReceipt_set_fence(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoReceipt *self, const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoFence * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,199u,2u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoReceipt_get_result(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoReceipt *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,199u,3u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoReceipt_set_result(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoReceipt *self, int32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,199u,3u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoReceipt_get_reserved(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoReceipt *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,199u,4u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoReceipt_set_reserved(R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoReceipt *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,199u,4u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoReceipt_inspect(const R4Lib_R4VIDEO_Bindings_Zig_r4video_R4VideoReceipt *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,199u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_native_jpeg_Dimensions_create(R4Lib_R4IMG_Bindings_Zig_native_jpeg_Dimensions *output, uint32_t p0, uint32_t p1) {
 R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,200u,a,2u,output);
}
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_native_jpeg_Dimensions_from_fields(R4Lib_R4IMG_Bindings_Zig_native_jpeg_Dimensions *output, uint32_t p0, uint32_t p1) {
 R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,200u,a,2u,output);
}
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_native_jpeg_Dimensions_get_width(const R4Lib_R4IMG_Bindings_Zig_native_jpeg_Dimensions *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,200u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_native_jpeg_Dimensions_set_width(R4Lib_R4IMG_Bindings_Zig_native_jpeg_Dimensions *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,200u,0u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_native_jpeg_Dimensions_get_height(const R4Lib_R4IMG_Bindings_Zig_native_jpeg_Dimensions *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,200u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_native_jpeg_Dimensions_set_height(R4Lib_R4IMG_Bindings_Zig_native_jpeg_Dimensions *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,200u,1u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4IMG_Bindings_Zig_native_jpeg_Dimensions_inspect(const R4Lib_R4IMG_Bindings_Zig_native_jpeg_Dimensions *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,200u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value201_inspect(const R4Lib_Value201 *self, R4Lib_R4IMG_Bindings_Zig_native_jpeg_Dimensions *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,201u,(void *)self,output); }
static inline R4LibrariesSlot R4FontHelpersFormat_create(R4FontHelpersFormat *output, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,202u,a,1u,output); }
static inline R4LibrariesSlot R4FontHelpersFormat_inspect(const R4FontHelpersFormat *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,202u,(void *)self,0); }
static inline R4LibrariesSlot R4FontHelpersDiagnostics_create(R4FontHelpersDiagnostics *output, uint64_t p0, uint64_t p1, uint64_t p2, uint64_t p3, uint64_t p4, uint64_t p5, uint8_t p6) {
 R4LibrariesSlot a[7]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,203u,a,7u,output);
}
static inline R4LibrariesSlot R4FontHelpersDiagnostics_from_fields(R4FontHelpersDiagnostics *output, uint64_t p0, uint64_t p1, uint64_t p2, uint64_t p3, uint64_t p4, uint64_t p5, uint8_t p6) {
 R4LibrariesSlot a[7]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,203u,a,7u,output);
}
static inline R4LibrariesSlot R4FontHelpersDiagnostics_get_current_bytes(const R4FontHelpersDiagnostics *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,203u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontHelpersDiagnostics_set_current_bytes(R4FontHelpersDiagnostics *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,203u,0u,self,a,0); }
static inline R4LibrariesSlot R4FontHelpersDiagnostics_get_peak_bytes(const R4FontHelpersDiagnostics *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,203u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontHelpersDiagnostics_set_peak_bytes(R4FontHelpersDiagnostics *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,203u,1u,self,a,0); }
static inline R4LibrariesSlot R4FontHelpersDiagnostics_get_allocation_count(const R4FontHelpersDiagnostics *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,203u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontHelpersDiagnostics_set_allocation_count(R4FontHelpersDiagnostics *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,203u,2u,self,a,0); }
static inline R4LibrariesSlot R4FontHelpersDiagnostics_get_reallocation_count(const R4FontHelpersDiagnostics *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,203u,3u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontHelpersDiagnostics_set_reallocation_count(R4FontHelpersDiagnostics *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,203u,3u,self,a,0); }
static inline R4LibrariesSlot R4FontHelpersDiagnostics_get_reallocation_failure_count(const R4FontHelpersDiagnostics *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,203u,4u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontHelpersDiagnostics_set_reallocation_failure_count(R4FontHelpersDiagnostics *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,203u,4u,self,a,0); }
static inline R4LibrariesSlot R4FontHelpersDiagnostics_get_allocation_limit(const R4FontHelpersDiagnostics *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,203u,5u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontHelpersDiagnostics_set_allocation_limit(R4FontHelpersDiagnostics *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,203u,5u,self,a,0); }
static inline R4LibrariesSlot R4FontHelpersDiagnostics_get_allocation_failed(const R4FontHelpersDiagnostics *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,203u,6u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontHelpersDiagnostics_set_allocation_failed(R4FontHelpersDiagnostics *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,203u,6u,self,a,0); }
static inline R4LibrariesSlot R4FontHelpersDiagnostics_inspect(const R4FontHelpersDiagnostics *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,203u,(void *)self,0); }
static inline R4LibrariesSlot R4FontHelpersTestingFaultInjection_create(R4FontHelpersTestingFaultInjection *output) {
 R4LibrariesSlot a[2]={0};
 a[0].flags=R4LIBRARIES_DEFAULT;
 a[1].flags=R4LIBRARIES_DEFAULT;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,204u,a,2u,output);
}
static inline R4LibrariesSlot R4FontHelpersTestingFaultInjection_from_fields(R4FontHelpersTestingFaultInjection *output, R4LibrariesSlot p0, R4LibrariesSlot p1) {
 R4LibrariesSlot a[2]={0};
 a[0] = p0;
 a[1] = p1;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,204u,a,2u,output);
}
static inline R4LibrariesSlot R4FontHelpersTestingFaultInjection_get_allocation_after(const R4FontHelpersTestingFaultInjection *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,204u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontHelpersTestingFaultInjection_set_allocation_after(R4FontHelpersTestingFaultInjection *self, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,204u,0u,self,a,0); }
static inline R4LibrariesSlot R4FontHelpersTestingFaultInjection_get_reallocation_after(const R4FontHelpersTestingFaultInjection *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,204u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontHelpersTestingFaultInjection_set_reallocation_after(R4FontHelpersTestingFaultInjection *self, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,204u,1u,self,a,0); }
static inline R4LibrariesSlot R4FontHelpersTestingFaultInjection_inspect(const R4FontHelpersTestingFaultInjection *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,204u,(void *)self,0); }
static inline R4LibrariesSlot R4FontHelpersFaceInfo_create(R4FontHelpersFaceInfo *output, uint32_t p0, uint32_t p1, uint32_t p2, uint32_t p3, int32_t p4, int32_t p5, int32_t p6, int32_t p7, uint8_t p8, uint8_t p9, const uint8_t * p10, uintptr_t n10, const uint8_t * p11, uintptr_t n11) {
 R4LibrariesSlot a[12]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4LIBRARIES_PRESENT};
 a[7] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p7,.flags=R4LIBRARIES_PRESENT};
 a[8] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p8,.flags=R4LIBRARIES_PRESENT};
 a[9] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p9,.flags=R4LIBRARIES_PRESENT};
 a[10] = (R4LibrariesSlot){.ptr=(void *)p10,.length=n10,.flags=R4LIBRARIES_PRESENT};
 a[11] = (R4LibrariesSlot){.ptr=(void *)p11,.length=n11,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,205u,a,12u,output);
}
static inline R4LibrariesSlot R4FontHelpersFaceInfo_from_fields(R4FontHelpersFaceInfo *output, uint32_t p0, uint32_t p1, uint32_t p2, uint32_t p3, int32_t p4, int32_t p5, int32_t p6, int32_t p7, uint8_t p8, uint8_t p9, const uint8_t * p10, uintptr_t n10, const uint8_t * p11, uintptr_t n11) {
 R4LibrariesSlot a[12]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4LIBRARIES_PRESENT};
 a[7] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p7,.flags=R4LIBRARIES_PRESENT};
 a[8] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p8,.flags=R4LIBRARIES_PRESENT};
 a[9] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p9,.flags=R4LIBRARIES_PRESENT};
 a[10] = (R4LibrariesSlot){.ptr=(void *)p10,.length=n10,.flags=R4LIBRARIES_PRESENT};
 a[11] = (R4LibrariesSlot){.ptr=(void *)p11,.length=n11,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,205u,a,12u,output);
}
static inline R4LibrariesSlot R4FontHelpersFaceInfo_get_face_count(const R4FontHelpersFaceInfo *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,205u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontHelpersFaceInfo_set_face_count(R4FontHelpersFaceInfo *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,205u,0u,self,a,0); }
static inline R4LibrariesSlot R4FontHelpersFaceInfo_get_face_index(const R4FontHelpersFaceInfo *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,205u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontHelpersFaceInfo_set_face_index(R4FontHelpersFaceInfo *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,205u,1u,self,a,0); }
static inline R4LibrariesSlot R4FontHelpersFaceInfo_get_glyph_count(const R4FontHelpersFaceInfo *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,205u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontHelpersFaceInfo_set_glyph_count(R4FontHelpersFaceInfo *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,205u,2u,self,a,0); }
static inline R4LibrariesSlot R4FontHelpersFaceInfo_get_units_per_em(const R4FontHelpersFaceInfo *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,205u,3u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontHelpersFaceInfo_set_units_per_em(R4FontHelpersFaceInfo *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,205u,3u,self,a,0); }
static inline R4LibrariesSlot R4FontHelpersFaceInfo_get_ascender(const R4FontHelpersFaceInfo *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,205u,4u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontHelpersFaceInfo_set_ascender(R4FontHelpersFaceInfo *self, int32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,205u,4u,self,a,0); }
static inline R4LibrariesSlot R4FontHelpersFaceInfo_get_descender(const R4FontHelpersFaceInfo *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,205u,5u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontHelpersFaceInfo_set_descender(R4FontHelpersFaceInfo *self, int32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,205u,5u,self,a,0); }
static inline R4LibrariesSlot R4FontHelpersFaceInfo_get_line_height(const R4FontHelpersFaceInfo *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,205u,6u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontHelpersFaceInfo_set_line_height(R4FontHelpersFaceInfo *self, int32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,205u,6u,self,a,0); }
static inline R4LibrariesSlot R4FontHelpersFaceInfo_get_max_advance(const R4FontHelpersFaceInfo *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,205u,7u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontHelpersFaceInfo_set_max_advance(R4FontHelpersFaceInfo *self, int32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,205u,7u,self,a,0); }
static inline R4LibrariesSlot R4FontHelpersFaceInfo_get_bold(const R4FontHelpersFaceInfo *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,205u,8u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontHelpersFaceInfo_set_bold(R4FontHelpersFaceInfo *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,205u,8u,self,a,0); }
static inline R4LibrariesSlot R4FontHelpersFaceInfo_get_italic(const R4FontHelpersFaceInfo *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,205u,9u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontHelpersFaceInfo_set_italic(R4FontHelpersFaceInfo *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,205u,9u,self,a,0); }
static inline R4LibrariesSlot R4FontHelpersFaceInfo_get_family(const R4FontHelpersFaceInfo *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,205u,10u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontHelpersFaceInfo_set_family(R4FontHelpersFaceInfo *self, const uint8_t * p0, uintptr_t n0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,205u,10u,self,a,0); }
static inline R4LibrariesSlot R4FontHelpersFaceInfo_get_style(const R4FontHelpersFaceInfo *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,205u,11u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontHelpersFaceInfo_set_style(R4FontHelpersFaceInfo *self, const uint8_t * p0, uintptr_t n0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,205u,11u,self,a,0); }
static inline R4LibrariesSlot R4FontHelpersFaceInfo_inspect(const R4FontHelpersFaceInfo *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,205u,(void *)self,0); }
static inline R4LibrariesSlot R4FontHelpersGlyphMetrics_create(R4FontHelpersGlyphMetrics *output, uint32_t p0, int32_t p1, int32_t p2, int32_t p3, int32_t p4, int32_t p5, int32_t p6) {
 R4LibrariesSlot a[7]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,206u,a,7u,output);
}
static inline R4LibrariesSlot R4FontHelpersGlyphMetrics_from_fields(R4FontHelpersGlyphMetrics *output, uint32_t p0, int32_t p1, int32_t p2, int32_t p3, int32_t p4, int32_t p5, int32_t p6) {
 R4LibrariesSlot a[7]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,206u,a,7u,output);
}
static inline R4LibrariesSlot R4FontHelpersGlyphMetrics_get_glyph_index(const R4FontHelpersGlyphMetrics *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,206u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontHelpersGlyphMetrics_set_glyph_index(R4FontHelpersGlyphMetrics *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,206u,0u,self,a,0); }
static inline R4LibrariesSlot R4FontHelpersGlyphMetrics_get_advance_x(const R4FontHelpersGlyphMetrics *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,206u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontHelpersGlyphMetrics_set_advance_x(R4FontHelpersGlyphMetrics *self, int32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,206u,1u,self,a,0); }
static inline R4LibrariesSlot R4FontHelpersGlyphMetrics_get_advance_y(const R4FontHelpersGlyphMetrics *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,206u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontHelpersGlyphMetrics_set_advance_y(R4FontHelpersGlyphMetrics *self, int32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,206u,2u,self,a,0); }
static inline R4LibrariesSlot R4FontHelpersGlyphMetrics_get_bearing_x(const R4FontHelpersGlyphMetrics *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,206u,3u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontHelpersGlyphMetrics_set_bearing_x(R4FontHelpersGlyphMetrics *self, int32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,206u,3u,self,a,0); }
static inline R4LibrariesSlot R4FontHelpersGlyphMetrics_get_bearing_y(const R4FontHelpersGlyphMetrics *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,206u,4u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontHelpersGlyphMetrics_set_bearing_y(R4FontHelpersGlyphMetrics *self, int32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,206u,4u,self,a,0); }
static inline R4LibrariesSlot R4FontHelpersGlyphMetrics_get_width(const R4FontHelpersGlyphMetrics *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,206u,5u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontHelpersGlyphMetrics_set_width(R4FontHelpersGlyphMetrics *self, int32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,206u,5u,self,a,0); }
static inline R4LibrariesSlot R4FontHelpersGlyphMetrics_get_height(const R4FontHelpersGlyphMetrics *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,206u,6u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontHelpersGlyphMetrics_set_height(R4FontHelpersGlyphMetrics *self, int32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,206u,6u,self,a,0); }
static inline R4LibrariesSlot R4FontHelpersGlyphMetrics_inspect(const R4FontHelpersGlyphMetrics *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,206u,(void *)self,0); }
static inline R4LibrariesSlot R4FontHelpersRaster_create(R4FontHelpersRaster *output, uint32_t p0, uint32_t p1, uint32_t p2, int32_t p3, int32_t p4, int32_t p5, uint8_t * p6, uintptr_t n6) {
 R4LibrariesSlot a[7]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.ptr=(void *)p6,.length=n6,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,207u,a,7u,output);
}
static inline R4LibrariesSlot R4FontHelpersRaster_from_fields(R4FontHelpersRaster *output, uint32_t p0, uint32_t p1, uint32_t p2, int32_t p3, int32_t p4, int32_t p5, uint8_t * p6, uintptr_t n6) {
 R4LibrariesSlot a[7]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.ptr=(void *)p6,.length=n6,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,207u,a,7u,output);
}
static inline R4LibrariesSlot R4FontHelpersRaster_get_glyph_index(const R4FontHelpersRaster *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,207u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontHelpersRaster_set_glyph_index(R4FontHelpersRaster *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,207u,0u,self,a,0); }
static inline R4LibrariesSlot R4FontHelpersRaster_get_width(const R4FontHelpersRaster *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,207u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontHelpersRaster_set_width(R4FontHelpersRaster *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,207u,1u,self,a,0); }
static inline R4LibrariesSlot R4FontHelpersRaster_get_height(const R4FontHelpersRaster *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,207u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontHelpersRaster_set_height(R4FontHelpersRaster *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,207u,2u,self,a,0); }
static inline R4LibrariesSlot R4FontHelpersRaster_get_left(const R4FontHelpersRaster *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,207u,3u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontHelpersRaster_set_left(R4FontHelpersRaster *self, int32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,207u,3u,self,a,0); }
static inline R4LibrariesSlot R4FontHelpersRaster_get_top(const R4FontHelpersRaster *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,207u,4u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontHelpersRaster_set_top(R4FontHelpersRaster *self, int32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,207u,4u,self,a,0); }
static inline R4LibrariesSlot R4FontHelpersRaster_get_advance_x_26_6(const R4FontHelpersRaster *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,207u,5u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontHelpersRaster_set_advance_x_26_6(R4FontHelpersRaster *self, int32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,207u,5u,self,a,0); }
static inline R4LibrariesSlot R4FontHelpersRaster_get_alpha(const R4FontHelpersRaster *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,207u,6u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontHelpersRaster_set_alpha(R4FontHelpersRaster *self, uint8_t * p0, uintptr_t n0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,207u,6u,self,a,0); }
static inline R4LibrariesSlot R4FontHelpersRaster_inspect(const R4FontHelpersRaster *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,207u,(void *)self,0); }
static inline R4LibrariesSlot R4FontHelpersContext_create(R4FontHelpersContext *output, const R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1Client * p0) {
 R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,208u,a,1u,output);
}
static inline R4LibrariesSlot R4FontHelpersContext_from_fields(R4FontHelpersContext *output, const R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1Client * p0) {
 R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,208u,a,1u,output);
}
static inline R4LibrariesSlot R4FontHelpersContext_get_client(const R4FontHelpersContext *self, R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1Client *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,208u,0u,(void *)self,0,output); }
static inline R4LibrariesSlot R4FontHelpersContext_set_client(R4FontHelpersContext *self, const R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1Client * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,208u,0u,self,a,0); }
static inline R4LibrariesSlot R4FontHelpersContext_inspect(const R4FontHelpersContext *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,208u,(void *)self,0); }
static inline R4LibrariesSlot R4FontHelpersDecoder_create(R4FontHelpersDecoder *output, const R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1Client * p0, uint64_t p1, R4FontHelpersAllocatorState * p2) {
 R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,210u,a,3u,output);
}
static inline R4LibrariesSlot R4FontHelpersDecoder_from_fields(R4FontHelpersDecoder *output, const R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1Client * p0, uint64_t p1, R4FontHelpersAllocatorState * p2) {
 R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,210u,a,3u,output);
}
static inline R4LibrariesSlot R4FontHelpersDecoder_get_client(const R4FontHelpersDecoder *self, R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1Client *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,210u,0u,(void *)self,0,output); }
static inline R4LibrariesSlot R4FontHelpersDecoder_set_client(R4FontHelpersDecoder *self, const R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1Client * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,210u,0u,self,a,0); }
static inline R4LibrariesSlot R4FontHelpersDecoder_get_raw(const R4FontHelpersDecoder *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,210u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontHelpersDecoder_set_raw(R4FontHelpersDecoder *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,210u,1u,self,a,0); }
static inline R4LibrariesSlot R4FontHelpersDecoder_get_state(const R4FontHelpersDecoder *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,210u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontHelpersDecoder_set_state(R4FontHelpersDecoder *self, R4FontHelpersAllocatorState * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,210u,2u,self,a,0); }
static inline R4LibrariesSlot R4FontHelpersDecoder_inspect(const R4FontHelpersDecoder *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,210u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value211_create(R4Lib_Value211 *output, R4FontHelpersAllocatorState * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,211u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value211_inspect(const R4Lib_Value211 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,211u,(void *)self,0); }
static inline R4LibrariesSlot R4FontHelpersAllocatorState_create(R4FontHelpersAllocatorState *output, const R4LibraryAllocator * p0) {
 R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1].flags=R4LIBRARIES_DEFAULT;
 a[2].flags=R4LIBRARIES_DEFAULT;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,212u,a,3u,output);
}
static inline R4LibrariesSlot R4FontHelpersAllocatorState_from_fields(R4FontHelpersAllocatorState *output, const R4LibraryAllocator * p0, R4LibrariesSlot p1, R4LibrariesSlot p2) {
 R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = p1;
 a[2] = p2;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,212u,a,3u,output);
}
static inline R4LibrariesSlot R4FontHelpersAllocatorState_get_allocator(const R4FontHelpersAllocatorState *self, R4LibraryAllocator *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,212u,0u,(void *)self,0,output); }
static inline R4LibrariesSlot R4FontHelpersAllocatorState_set_allocator(R4FontHelpersAllocatorState *self, const R4LibraryAllocator * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,212u,0u,self,a,0); }
static inline R4LibrariesSlot R4FontHelpersAllocatorState_get_fail_allocation_after(const R4FontHelpersAllocatorState *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,212u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontHelpersAllocatorState_set_fail_allocation_after(R4FontHelpersAllocatorState *self, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,212u,1u,self,a,0); }
static inline R4LibrariesSlot R4FontHelpersAllocatorState_get_fail_reallocation_after(const R4FontHelpersAllocatorState *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,212u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontHelpersAllocatorState_set_fail_reallocation_after(R4FontHelpersAllocatorState *self, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,212u,2u,self,a,0); }
static inline R4LibrariesSlot R4FontHelpersAllocatorState_inspect(const R4FontHelpersAllocatorState *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,212u,(void *)self,0); }
static inline R4LibrariesSlot R4FontHelpersFace_create(R4FontHelpersFace *output, const R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1Client * p0, uint64_t p1) {
 R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,213u,a,2u,output);
}
static inline R4LibrariesSlot R4FontHelpersFace_from_fields(R4FontHelpersFace *output, const R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1Client * p0, uint64_t p1) {
 R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,213u,a,2u,output);
}
static inline R4LibrariesSlot R4FontHelpersFace_get_client(const R4FontHelpersFace *self, R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1Client *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,213u,0u,(void *)self,0,output); }
static inline R4LibrariesSlot R4FontHelpersFace_set_client(R4FontHelpersFace *self, const R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1Client * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,213u,0u,self,a,0); }
static inline R4LibrariesSlot R4FontHelpersFace_get_raw(const R4FontHelpersFace *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,213u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontHelpersFace_set_raw(R4FontHelpersFace *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,213u,1u,self,a,0); }
static inline R4LibrariesSlot R4FontHelpersFace_inspect(const R4FontHelpersFace *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,213u,(void *)self,0); }
static inline R4LibrariesSlot R4FontStoreFaceHandle_create(R4FontStoreFaceHandle *output) {
 R4LibrariesSlot a[3]={0};
 a[0].flags=R4LIBRARIES_DEFAULT;
 a[1].flags=R4LIBRARIES_DEFAULT;
 a[2].flags=R4LIBRARIES_DEFAULT;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,214u,a,3u,output);
}
static inline R4LibrariesSlot R4FontStoreFaceHandle_from_fields(R4FontStoreFaceHandle *output, uint64_t p0, uint32_t p1, uint32_t p2) {
 R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,214u,a,3u,output);
}
static inline R4LibrariesSlot R4FontStoreFaceHandle_get_owner(const R4FontStoreFaceHandle *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,214u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontStoreFaceHandle_set_owner(R4FontStoreFaceHandle *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,214u,0u,self,a,0); }
static inline R4LibrariesSlot R4FontStoreFaceHandle_get_slot(const R4FontStoreFaceHandle *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,214u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontStoreFaceHandle_set_slot(R4FontStoreFaceHandle *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,214u,1u,self,a,0); }
static inline R4LibrariesSlot R4FontStoreFaceHandle_get_generation(const R4FontStoreFaceHandle *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,214u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontStoreFaceHandle_set_generation(R4FontStoreFaceHandle *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,214u,2u,self,a,0); }
static inline R4LibrariesSlot R4FontStoreFaceHandle_inspect(const R4FontStoreFaceHandle *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,214u,(void *)self,0); }
static inline R4LibrariesSlot R4FontStoreOptions_create(R4FontStoreOptions *output) {
 R4LibrariesSlot a[3]={0};
 a[0].flags=R4LIBRARIES_DEFAULT;
 a[1].flags=R4LIBRARIES_DEFAULT;
 a[2].flags=R4LIBRARIES_DEFAULT;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,215u,a,3u,output);
}
static inline R4LibrariesSlot R4FontStoreOptions_from_fields(R4FontStoreOptions *output, uint64_t p0, uint64_t p1, uint64_t p2) {
 R4LibrariesSlot a[3]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,215u,a,3u,output);
}
static inline R4LibrariesSlot R4FontStoreOptions_get_decoder_allocation_limit(const R4FontStoreOptions *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,215u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontStoreOptions_set_decoder_allocation_limit(R4FontStoreOptions *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,215u,0u,self,a,0); }
static inline R4LibrariesSlot R4FontStoreOptions_get_max_cached_glyphs(const R4FontStoreOptions *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,215u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontStoreOptions_set_max_cached_glyphs(R4FontStoreOptions *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,215u,1u,self,a,0); }
static inline R4LibrariesSlot R4FontStoreOptions_get_max_cached_bytes(const R4FontStoreOptions *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,215u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontStoreOptions_set_max_cached_bytes(R4FontStoreOptions *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,215u,2u,self,a,0); }
static inline R4LibrariesSlot R4FontStoreOptions_inspect(const R4FontStoreOptions *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,215u,(void *)self,0); }
static inline R4LibrariesSlot R4FontStoreFaceMetrics26_6_create(R4FontStoreFaceMetrics26_6 *output, int32_t p0, int32_t p1, int32_t p2, int32_t p3) {
 R4LibrariesSlot a[4]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,216u,a,4u,output);
}
static inline R4LibrariesSlot R4FontStoreFaceMetrics26_6_from_fields(R4FontStoreFaceMetrics26_6 *output, int32_t p0, int32_t p1, int32_t p2, int32_t p3) {
 R4LibrariesSlot a[4]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,216u,a,4u,output);
}
static inline R4LibrariesSlot R4FontStoreFaceMetrics26_6_get_height(const R4FontStoreFaceMetrics26_6 *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,216u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontStoreFaceMetrics26_6_set_height(R4FontStoreFaceMetrics26_6 *self, int32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,216u,0u,self,a,0); }
static inline R4LibrariesSlot R4FontStoreFaceMetrics26_6_get_line_height(const R4FontStoreFaceMetrics26_6 *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,216u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontStoreFaceMetrics26_6_set_line_height(R4FontStoreFaceMetrics26_6 *self, int32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,216u,1u,self,a,0); }
static inline R4LibrariesSlot R4FontStoreFaceMetrics26_6_get_baseline(const R4FontStoreFaceMetrics26_6 *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,216u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontStoreFaceMetrics26_6_set_baseline(R4FontStoreFaceMetrics26_6 *self, int32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,216u,2u,self,a,0); }
static inline R4LibrariesSlot R4FontStoreFaceMetrics26_6_get_max_advance(const R4FontStoreFaceMetrics26_6 *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,216u,3u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontStoreFaceMetrics26_6_set_max_advance(R4FontStoreFaceMetrics26_6 *self, int32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,216u,3u,self,a,0); }
static inline R4LibrariesSlot R4FontStoreFaceMetrics26_6_inspect(const R4FontStoreFaceMetrics26_6 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,216u,(void *)self,0); }
static inline R4LibrariesSlot R4FontStoreGlyphMetrics26_6_create(R4FontStoreGlyphMetrics26_6 *output, int32_t p0, int32_t p1, int32_t p2, int32_t p3, int32_t p4, int32_t p5) {
 R4LibrariesSlot a[6]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,217u,a,6u,output);
}
static inline R4LibrariesSlot R4FontStoreGlyphMetrics26_6_from_fields(R4FontStoreGlyphMetrics26_6 *output, int32_t p0, int32_t p1, int32_t p2, int32_t p3, int32_t p4, int32_t p5) {
 R4LibrariesSlot a[6]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,217u,a,6u,output);
}
static inline R4LibrariesSlot R4FontStoreGlyphMetrics26_6_get_advance_x(const R4FontStoreGlyphMetrics26_6 *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,217u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontStoreGlyphMetrics26_6_set_advance_x(R4FontStoreGlyphMetrics26_6 *self, int32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,217u,0u,self,a,0); }
static inline R4LibrariesSlot R4FontStoreGlyphMetrics26_6_get_advance_y(const R4FontStoreGlyphMetrics26_6 *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,217u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontStoreGlyphMetrics26_6_set_advance_y(R4FontStoreGlyphMetrics26_6 *self, int32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,217u,1u,self,a,0); }
static inline R4LibrariesSlot R4FontStoreGlyphMetrics26_6_get_bearing_x(const R4FontStoreGlyphMetrics26_6 *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,217u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontStoreGlyphMetrics26_6_set_bearing_x(R4FontStoreGlyphMetrics26_6 *self, int32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,217u,2u,self,a,0); }
static inline R4LibrariesSlot R4FontStoreGlyphMetrics26_6_get_bearing_y(const R4FontStoreGlyphMetrics26_6 *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,217u,3u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontStoreGlyphMetrics26_6_set_bearing_y(R4FontStoreGlyphMetrics26_6 *self, int32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,217u,3u,self,a,0); }
static inline R4LibrariesSlot R4FontStoreGlyphMetrics26_6_get_width(const R4FontStoreGlyphMetrics26_6 *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,217u,4u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontStoreGlyphMetrics26_6_set_width(R4FontStoreGlyphMetrics26_6 *self, int32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,217u,4u,self,a,0); }
static inline R4LibrariesSlot R4FontStoreGlyphMetrics26_6_get_height(const R4FontStoreGlyphMetrics26_6 *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,217u,5u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontStoreGlyphMetrics26_6_set_height(R4FontStoreGlyphMetrics26_6 *self, int32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,217u,5u,self,a,0); }
static inline R4LibrariesSlot R4FontStoreGlyphMetrics26_6_inspect(const R4FontStoreGlyphMetrics26_6 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,217u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value218_create(R4Lib_Value218 *output, const R4Lib_Value218 * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,218u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value218_inspect(const R4Lib_Value218 *self, R4Lib_Value218 *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,218u,(void *)self,output); }
static inline R4LibrariesSlot R4FontStoreBorrowedRaster_create(R4FontStoreBorrowedRaster *output, uint32_t p0, uint32_t p1, uint32_t p2, int32_t p3, int32_t p4, int32_t p5, const uint8_t * p6, uintptr_t n6) {
 R4LibrariesSlot a[7]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.ptr=(void *)p6,.length=n6,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,219u,a,7u,output);
}
static inline R4LibrariesSlot R4FontStoreBorrowedRaster_from_fields(R4FontStoreBorrowedRaster *output, uint32_t p0, uint32_t p1, uint32_t p2, int32_t p3, int32_t p4, int32_t p5, const uint8_t * p6, uintptr_t n6) {
 R4LibrariesSlot a[7]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.ptr=(void *)p6,.length=n6,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,219u,a,7u,output);
}
static inline R4LibrariesSlot R4FontStoreBorrowedRaster_get_glyph_index(const R4FontStoreBorrowedRaster *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,219u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontStoreBorrowedRaster_set_glyph_index(R4FontStoreBorrowedRaster *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,219u,0u,self,a,0); }
static inline R4LibrariesSlot R4FontStoreBorrowedRaster_get_width(const R4FontStoreBorrowedRaster *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,219u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontStoreBorrowedRaster_set_width(R4FontStoreBorrowedRaster *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,219u,1u,self,a,0); }
static inline R4LibrariesSlot R4FontStoreBorrowedRaster_get_height(const R4FontStoreBorrowedRaster *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,219u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontStoreBorrowedRaster_set_height(R4FontStoreBorrowedRaster *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,219u,2u,self,a,0); }
static inline R4LibrariesSlot R4FontStoreBorrowedRaster_get_left(const R4FontStoreBorrowedRaster *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,219u,3u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontStoreBorrowedRaster_set_left(R4FontStoreBorrowedRaster *self, int32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,219u,3u,self,a,0); }
static inline R4LibrariesSlot R4FontStoreBorrowedRaster_get_top(const R4FontStoreBorrowedRaster *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,219u,4u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontStoreBorrowedRaster_set_top(R4FontStoreBorrowedRaster *self, int32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,219u,4u,self,a,0); }
static inline R4LibrariesSlot R4FontStoreBorrowedRaster_get_advance_x_26_6(const R4FontStoreBorrowedRaster *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,219u,5u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontStoreBorrowedRaster_set_advance_x_26_6(R4FontStoreBorrowedRaster *self, int32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,219u,5u,self,a,0); }
static inline R4LibrariesSlot R4FontStoreBorrowedRaster_get_alpha(const R4FontStoreBorrowedRaster *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,219u,6u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontStoreBorrowedRaster_set_alpha(R4FontStoreBorrowedRaster *self, const uint8_t * p0, uintptr_t n0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,219u,6u,self,a,0); }
static inline R4LibrariesSlot R4FontStoreBorrowedRaster_inspect(const R4FontStoreBorrowedRaster *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,219u,(void *)self,0); }
static inline R4LibrariesSlot R4FontStoreCacheStats_create(R4FontStoreCacheStats *output, uint64_t p0, uint64_t p1, uint64_t p2, uint64_t p3, uint64_t p4, uint64_t p5) {
 R4LibrariesSlot a[6]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,220u,a,6u,output);
}
static inline R4LibrariesSlot R4FontStoreCacheStats_from_fields(R4FontStoreCacheStats *output, uint64_t p0, uint64_t p1, uint64_t p2, uint64_t p3, uint64_t p4, uint64_t p5) {
 R4LibrariesSlot a[6]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,220u,a,6u,output);
}
static inline R4LibrariesSlot R4FontStoreCacheStats_get_entries(const R4FontStoreCacheStats *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,220u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontStoreCacheStats_set_entries(R4FontStoreCacheStats *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,220u,0u,self,a,0); }
static inline R4LibrariesSlot R4FontStoreCacheStats_get_bytes(const R4FontStoreCacheStats *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,220u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontStoreCacheStats_set_bytes(R4FontStoreCacheStats *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,220u,1u,self,a,0); }
static inline R4LibrariesSlot R4FontStoreCacheStats_get_max_entries(const R4FontStoreCacheStats *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,220u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontStoreCacheStats_set_max_entries(R4FontStoreCacheStats *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,220u,2u,self,a,0); }
static inline R4LibrariesSlot R4FontStoreCacheStats_get_max_bytes(const R4FontStoreCacheStats *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,220u,3u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontStoreCacheStats_set_max_bytes(R4FontStoreCacheStats *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,220u,3u,self,a,0); }
static inline R4LibrariesSlot R4FontStoreCacheStats_get_hits(const R4FontStoreCacheStats *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,220u,4u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontStoreCacheStats_set_hits(R4FontStoreCacheStats *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,220u,4u,self,a,0); }
static inline R4LibrariesSlot R4FontStoreCacheStats_get_misses(const R4FontStoreCacheStats *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,220u,5u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontStoreCacheStats_set_misses(R4FontStoreCacheStats *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,220u,5u,self,a,0); }
static inline R4LibrariesSlot R4FontStoreCacheStats_inspect(const R4FontStoreCacheStats *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,220u,(void *)self,0); }
static inline R4LibrariesSlot R4FontStoreDiagnostics_create(R4FontStoreDiagnostics *output, uint64_t p0, uint64_t p1, uint64_t p2, uint64_t p3, uint64_t p4, uint64_t p5, uint64_t p6, const R4FontHelpersDiagnostics * p7) {
 R4LibrariesSlot a[8]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4LIBRARIES_PRESENT};
 a[7] = (R4LibrariesSlot){.ptr=(void *)p7,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,221u,a,8u,output);
}
static inline R4LibrariesSlot R4FontStoreDiagnostics_from_fields(R4FontStoreDiagnostics *output, uint64_t p0, uint64_t p1, uint64_t p2, uint64_t p3, uint64_t p4, uint64_t p5, uint64_t p6, const R4FontHelpersDiagnostics * p7) {
 R4LibrariesSlot a[8]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4LIBRARIES_PRESENT};
 a[7] = (R4LibrariesSlot){.ptr=(void *)p7,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,221u,a,8u,output);
}
static inline R4LibrariesSlot R4FontStoreDiagnostics_get_active_faces(const R4FontStoreDiagnostics *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,221u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontStoreDiagnostics_set_active_faces(R4FontStoreDiagnostics *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,221u,0u,self,a,0); }
static inline R4LibrariesSlot R4FontStoreDiagnostics_get_source_objects(const R4FontStoreDiagnostics *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,221u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontStoreDiagnostics_set_source_objects(R4FontStoreDiagnostics *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,221u,1u,self,a,0); }
static inline R4LibrariesSlot R4FontStoreDiagnostics_get_source_bytes(const R4FontStoreDiagnostics *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,221u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontStoreDiagnostics_set_source_bytes(R4FontStoreDiagnostics *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,221u,2u,self,a,0); }
static inline R4LibrariesSlot R4FontStoreDiagnostics_get_raster_entries(const R4FontStoreDiagnostics *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,221u,3u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontStoreDiagnostics_set_raster_entries(R4FontStoreDiagnostics *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,221u,3u,self,a,0); }
static inline R4LibrariesSlot R4FontStoreDiagnostics_get_raster_bytes(const R4FontStoreDiagnostics *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,221u,4u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontStoreDiagnostics_set_raster_bytes(R4FontStoreDiagnostics *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,221u,4u,self,a,0); }
static inline R4LibrariesSlot R4FontStoreDiagnostics_get_cache_hits(const R4FontStoreDiagnostics *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,221u,5u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontStoreDiagnostics_set_cache_hits(R4FontStoreDiagnostics *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,221u,5u,self,a,0); }
static inline R4LibrariesSlot R4FontStoreDiagnostics_get_cache_misses(const R4FontStoreDiagnostics *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,221u,6u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontStoreDiagnostics_set_cache_misses(R4FontStoreDiagnostics *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,221u,6u,self,a,0); }
static inline R4LibrariesSlot R4FontStoreDiagnostics_get_decoder(const R4FontStoreDiagnostics *self, R4FontHelpersDiagnostics *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,221u,7u,(void *)self,0,output); }
static inline R4LibrariesSlot R4FontStoreDiagnostics_set_decoder(R4FontStoreDiagnostics *self, const R4FontHelpersDiagnostics * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,221u,7u,self,a,0); }
static inline R4LibrariesSlot R4FontStoreDiagnostics_inspect(const R4FontStoreDiagnostics *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,221u,(void *)self,0); }
static inline R4LibrariesSlot R4FontStoreFaceStore_create(R4FontStoreFaceStore *output, const R4LibraryAllocator * p0, const R4FontHelpersDecoder * p1, uint64_t p2, const R4FontStoreOptions * p3) {
 R4LibrariesSlot a[12]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.ptr=(void *)p3,.flags=R4LIBRARIES_PRESENT};
 a[4].flags=R4LIBRARIES_DEFAULT;
 a[5].flags=R4LIBRARIES_DEFAULT;
 a[6].flags=R4LIBRARIES_DEFAULT;
 a[7].flags=R4LIBRARIES_DEFAULT;
 a[8].flags=R4LIBRARIES_DEFAULT;
 a[9].flags=R4LIBRARIES_DEFAULT;
 a[10].flags=R4LIBRARIES_DEFAULT;
 a[11].flags=R4LIBRARIES_DEFAULT;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,222u,a,12u,output);
}
static inline R4LibrariesSlot R4FontStoreFaceStore_from_fields(R4FontStoreFaceStore *output, const R4LibraryAllocator * p0, const R4FontHelpersDecoder * p1, uint64_t p2, const R4FontStoreOptions * p3, const R4Lib_array_list_Aligned_R4FONT_Bindings_Zig_app_fonts_Slot_null_ * p4, const R4Lib_array_list_Aligned_R4FONT_Bindings_Zig_app_fonts_SourceSlot_null_ * p5, const R4Lib_array_list_Aligned_R4FONT_Bindings_Zig_app_fonts_CacheEntry_null_ * p6, uint64_t p7, uint64_t p8, uint64_t p9, uint64_t p10, R4LibrariesSlot p11) {
 R4LibrariesSlot a[12]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.ptr=(void *)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.ptr=(void *)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.ptr=(void *)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.ptr=(void *)p6,.flags=R4LIBRARIES_PRESENT};
 a[7] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p7,.flags=R4LIBRARIES_PRESENT};
 a[8] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p8,.flags=R4LIBRARIES_PRESENT};
 a[9] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p9,.flags=R4LIBRARIES_PRESENT};
 a[10] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p10,.flags=R4LIBRARIES_PRESENT};
 a[11] = p11;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,222u,a,12u,output);
}
static inline R4LibrariesSlot R4FontStoreFaceStore_get_allocator(const R4FontStoreFaceStore *self, R4LibraryAllocator *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,222u,0u,(void *)self,0,output); }
static inline R4LibrariesSlot R4FontStoreFaceStore_set_allocator(R4FontStoreFaceStore *self, const R4LibraryAllocator * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,222u,0u,self,a,0); }
static inline R4LibrariesSlot R4FontStoreFaceStore_get_decoder(const R4FontStoreFaceStore *self, R4FontHelpersDecoder *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,222u,1u,(void *)self,0,output); }
static inline R4LibrariesSlot R4FontStoreFaceStore_set_decoder(R4FontStoreFaceStore *self, const R4FontHelpersDecoder * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,222u,1u,self,a,0); }
static inline R4LibrariesSlot R4FontStoreFaceStore_get_owner(const R4FontStoreFaceStore *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,222u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontStoreFaceStore_set_owner(R4FontStoreFaceStore *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,222u,2u,self,a,0); }
static inline R4LibrariesSlot R4FontStoreFaceStore_get_options(const R4FontStoreFaceStore *self, R4FontStoreOptions *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,222u,3u,(void *)self,0,output); }
static inline R4LibrariesSlot R4FontStoreFaceStore_set_options(R4FontStoreFaceStore *self, const R4FontStoreOptions * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,222u,3u,self,a,0); }
static inline R4LibrariesSlot R4FontStoreFaceStore_get_slots(const R4FontStoreFaceStore *self, R4Lib_array_list_Aligned_R4FONT_Bindings_Zig_app_fonts_Slot_null_ *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,222u,4u,(void *)self,0,output); }
static inline R4LibrariesSlot R4FontStoreFaceStore_set_slots(R4FontStoreFaceStore *self, const R4Lib_array_list_Aligned_R4FONT_Bindings_Zig_app_fonts_Slot_null_ * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,222u,4u,self,a,0); }
static inline R4LibrariesSlot R4FontStoreFaceStore_get_sources(const R4FontStoreFaceStore *self, R4Lib_array_list_Aligned_R4FONT_Bindings_Zig_app_fonts_SourceSlot_null_ *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,222u,5u,(void *)self,0,output); }
static inline R4LibrariesSlot R4FontStoreFaceStore_set_sources(R4FontStoreFaceStore *self, const R4Lib_array_list_Aligned_R4FONT_Bindings_Zig_app_fonts_SourceSlot_null_ * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,222u,5u,self,a,0); }
static inline R4LibrariesSlot R4FontStoreFaceStore_get_cache(const R4FontStoreFaceStore *self, R4Lib_array_list_Aligned_R4FONT_Bindings_Zig_app_fonts_CacheEntry_null_ *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,222u,6u,(void *)self,0,output); }
static inline R4LibrariesSlot R4FontStoreFaceStore_set_cache(R4FontStoreFaceStore *self, const R4Lib_array_list_Aligned_R4FONT_Bindings_Zig_app_fonts_CacheEntry_null_ * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,222u,6u,self,a,0); }
static inline R4LibrariesSlot R4FontStoreFaceStore_get_cache_bytes(const R4FontStoreFaceStore *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,222u,7u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontStoreFaceStore_set_cache_bytes(R4FontStoreFaceStore *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,222u,7u,self,a,0); }
static inline R4LibrariesSlot R4FontStoreFaceStore_get_cache_clock(const R4FontStoreFaceStore *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,222u,8u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontStoreFaceStore_set_cache_clock(R4FontStoreFaceStore *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,222u,8u,self,a,0); }
static inline R4LibrariesSlot R4FontStoreFaceStore_get_cache_hits(const R4FontStoreFaceStore *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,222u,9u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontStoreFaceStore_set_cache_hits(R4FontStoreFaceStore *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,222u,9u,self,a,0); }
static inline R4LibrariesSlot R4FontStoreFaceStore_get_cache_misses(const R4FontStoreFaceStore *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,222u,10u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontStoreFaceStore_set_cache_misses(R4FontStoreFaceStore *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,222u,10u,self,a,0); }
static inline R4LibrariesSlot R4FontStoreFaceStore_get_scratch(const R4FontStoreFaceStore *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,222u,11u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontStoreFaceStore_set_scratch(R4FontStoreFaceStore *self, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,222u,11u,self,a,0); }
static inline R4LibrariesSlot R4FontStoreFaceStore_inspect(const R4FontStoreFaceStore *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,222u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value226_create(R4Lib_Value226 *output, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,226u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value226_inspect(const R4Lib_Value226 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,226u,(void *)self,0); }
static inline R4LibrariesSlot R4FontImportFaceInfo_create(R4FontImportFaceInfo *output, const uint8_t * p0, uintptr_t n0, const uint8_t * p1, uintptr_t n1, uint64_t p2, uint64_t p3, uint16_t p4, uint16_t p5, uint16_t p6, uint16_t p7, uint8_t p8) {
 R4LibrariesSlot a[9]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4LIBRARIES_PRESENT};
 a[7] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p7,.flags=R4LIBRARIES_PRESENT};
 a[8] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p8,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,227u,a,9u,output);
}
static inline R4LibrariesSlot R4FontImportFaceInfo_from_fields(R4FontImportFaceInfo *output, const uint8_t * p0, uintptr_t n0, const uint8_t * p1, uintptr_t n1, uint64_t p2, uint64_t p3, uint16_t p4, uint16_t p5, uint16_t p6, uint16_t p7, uint8_t p8) {
 R4LibrariesSlot a[9]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)p1,.length=n1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4LIBRARIES_PRESENT};
 a[7] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p7,.flags=R4LIBRARIES_PRESENT};
 a[8] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p8,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,227u,a,9u,output);
}
static inline R4LibrariesSlot R4FontImportFaceInfo_get_family(const R4FontImportFaceInfo *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,227u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontImportFaceInfo_set_family(R4FontImportFaceInfo *self, const uint8_t * p0, uintptr_t n0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,227u,0u,self,a,0); }
static inline R4LibrariesSlot R4FontImportFaceInfo_get_style(const R4FontImportFaceInfo *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,227u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontImportFaceInfo_set_style(R4FontImportFaceInfo *self, const uint8_t * p0, uintptr_t n0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,227u,1u,self,a,0); }
static inline R4LibrariesSlot R4FontImportFaceInfo_get_face_index(const R4FontImportFaceInfo *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,227u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontImportFaceInfo_set_face_index(R4FontImportFaceInfo *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,227u,2u,self,a,0); }
static inline R4LibrariesSlot R4FontImportFaceInfo_get_face_count(const R4FontImportFaceInfo *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,227u,3u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontImportFaceInfo_set_face_count(R4FontImportFaceInfo *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,227u,3u,self,a,0); }
static inline R4LibrariesSlot R4FontImportFaceInfo_get_pixel_width(const R4FontImportFaceInfo *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,227u,4u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontImportFaceInfo_set_pixel_width(R4FontImportFaceInfo *self, uint16_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,227u,4u,self,a,0); }
static inline R4LibrariesSlot R4FontImportFaceInfo_get_pixel_height(const R4FontImportFaceInfo *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,227u,5u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontImportFaceInfo_set_pixel_height(R4FontImportFaceInfo *self, uint16_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,227u,5u,self,a,0); }
static inline R4LibrariesSlot R4FontImportFaceInfo_get_max_width(const R4FontImportFaceInfo *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,227u,6u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontImportFaceInfo_set_max_width(R4FontImportFaceInfo *self, uint16_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,227u,6u,self,a,0); }
static inline R4LibrariesSlot R4FontImportFaceInfo_get_glyph_count(const R4FontImportFaceInfo *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,227u,7u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontImportFaceInfo_set_glyph_count(R4FontImportFaceInfo *self, uint16_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,227u,7u,self,a,0); }
static inline R4LibrariesSlot R4FontImportFaceInfo_get_vector(const R4FontImportFaceInfo *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,227u,8u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontImportFaceInfo_set_vector(R4FontImportFaceInfo *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,227u,8u,self,a,0); }
static inline R4LibrariesSlot R4FontImportFaceInfo_inspect(const R4FontImportFaceInfo *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,227u,(void *)self,0); }
static inline R4LibrariesSlot R4FontImportRasterGlyph_create(R4FontImportRasterGlyph *output, uint32_t p0, uint16_t p1, uint16_t p2, int16_t p3, const uint8_t * p4, uintptr_t n4) {
 R4LibrariesSlot a[5]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.ptr=(void *)p4,.length=n4,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,228u,a,5u,output);
}
static inline R4LibrariesSlot R4FontImportRasterGlyph_from_fields(R4FontImportRasterGlyph *output, uint32_t p0, uint16_t p1, uint16_t p2, int16_t p3, const uint8_t * p4, uintptr_t n4) {
 R4LibrariesSlot a[5]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.ptr=(void *)p4,.length=n4,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,228u,a,5u,output);
}
static inline R4LibrariesSlot R4FontImportRasterGlyph_get_codepoint(const R4FontImportRasterGlyph *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,228u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontImportRasterGlyph_set_codepoint(R4FontImportRasterGlyph *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,228u,0u,self,a,0); }
static inline R4LibrariesSlot R4FontImportRasterGlyph_get_width(const R4FontImportRasterGlyph *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,228u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontImportRasterGlyph_set_width(R4FontImportRasterGlyph *self, uint16_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,228u,1u,self,a,0); }
static inline R4LibrariesSlot R4FontImportRasterGlyph_get_height(const R4FontImportRasterGlyph *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,228u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontImportRasterGlyph_set_height(R4FontImportRasterGlyph *self, uint16_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,228u,2u,self,a,0); }
static inline R4LibrariesSlot R4FontImportRasterGlyph_get_advance(const R4FontImportRasterGlyph *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,228u,3u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontImportRasterGlyph_set_advance(R4FontImportRasterGlyph *self, int16_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,228u,3u,self,a,0); }
static inline R4LibrariesSlot R4FontImportRasterGlyph_get_data(const R4FontImportRasterGlyph *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,228u,4u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontImportRasterGlyph_set_data(R4FontImportRasterGlyph *self, const uint8_t * p0, uintptr_t n0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,228u,4u,self,a,0); }
static inline R4LibrariesSlot R4FontImportRasterGlyph_inspect(const R4FontImportRasterGlyph *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,228u,(void *)self,0); }
static inline R4LibrariesSlot R4FontImportPreview_create(R4FontImportPreview *output, uint16_t p0, uint16_t p1) {
 R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,229u,a,2u,output);
}
static inline R4LibrariesSlot R4FontImportPreview_from_fields(R4FontImportPreview *output, uint16_t p0, uint16_t p1) {
 R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,229u,a,2u,output);
}
static inline R4LibrariesSlot R4FontImportPreview_get_width(const R4FontImportPreview *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,229u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontImportPreview_set_width(R4FontImportPreview *self, uint16_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,229u,0u,self,a,0); }
static inline R4LibrariesSlot R4FontImportPreview_get_height(const R4FontImportPreview *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,229u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4FontImportPreview_set_height(R4FontImportPreview *self, uint16_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,229u,1u,self,a,0); }
static inline R4LibrariesSlot R4FontImportPreview_inspect(const R4FontImportPreview *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,229u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value230_inspect(const R4Lib_Value230 *self, R4FontImportFaceInfo *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,230u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value231_inspect(const R4Lib_Value231 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,231u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value232_inspect(const R4Lib_Value232 *self, R4FontImportPreview *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,232u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value234_create(R4Lib_Value234 *output, R4LibrarySession * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,234u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value234_inspect(const R4Lib_Value234 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,234u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value235_create(R4Lib_Value235 *output, R4Lib_r4os_r4sys_Context * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,235u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value235_inspect(const R4Lib_Value235 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,235u,(void *)self,0); }
static inline R4LibrariesSlot R4LibraryMemory_create(R4LibraryMemory *output, uintptr_t p1, uintptr_t p2) {
 R4LibrariesSlot a[3]={0};
 a[0].flags=R4LIBRARIES_DEFAULT;
 a[1] = (R4LibrariesSlot){.ptr=(void *)(uintptr_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)(uintptr_t)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,237u,a,3u,output);
}
static inline R4LibrariesSlot R4LibraryMemory_from_fields(R4LibraryMemory *output, R4LibrariesSlot p0, uintptr_t p1, uintptr_t p2) {
 R4LibrariesSlot a[3]={0};
 a[0] = p0;
 a[1] = (R4LibrariesSlot){.ptr=(void *)(uintptr_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)(uintptr_t)p2,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,237u,a,3u,output);
}
static inline R4LibrariesSlot R4LibraryMemory_get_user(const R4LibraryMemory *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,237u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4LibraryMemory_set_user(R4LibraryMemory *self, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,237u,0u,self,a,0); }
static inline R4LibrariesSlot R4LibraryMemory_get_allocate(const R4LibraryMemory *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,237u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4LibraryMemory_set_allocate(R4LibraryMemory *self, uintptr_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)(uintptr_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,237u,1u,self,a,0); }
static inline R4LibrariesSlot R4LibraryMemory_get_release(const R4LibraryMemory *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,237u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4LibraryMemory_set_release(R4LibraryMemory *self, uintptr_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)(uintptr_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,237u,2u,self,a,0); }
static inline R4LibrariesSlot R4LibraryMemory_inspect(const R4LibraryMemory *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,237u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value238_inspect(const R4Lib_Value238 *self, R4Lib_R4GFX_Bindings_Zig_r4gfx_abi_ColorV1Client *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,238u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value239_inspect(const R4Lib_Value239 *self, R4Lib_R4VIDEO_Bindings_Zig_r4video_VideoV1Client *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,239u,(void *)self,output); }
static inline R4LibrariesSlot R4StdAdaptersSaver_create(R4StdAdaptersSaver *output, uintptr_t p1) {
 R4LibrariesSlot a[2]={0};
 a[0].flags=R4LIBRARIES_DEFAULT;
 a[1] = (R4LibrariesSlot){.ptr=(void *)(uintptr_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,240u,a,2u,output);
}
static inline R4LibrariesSlot R4StdAdaptersSaver_from_fields(R4StdAdaptersSaver *output, R4LibrariesSlot p0, uintptr_t p1) {
 R4LibrariesSlot a[2]={0};
 a[0] = p0;
 a[1] = (R4LibrariesSlot){.ptr=(void *)(uintptr_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,240u,a,2u,output);
}
static inline R4LibrariesSlot R4StdAdaptersSaver_get_user(const R4StdAdaptersSaver *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,240u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdAdaptersSaver_set_user(R4StdAdaptersSaver *self, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,240u,0u,self,a,0); }
static inline R4LibrariesSlot R4StdAdaptersSaver_get_callback(const R4StdAdaptersSaver *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,240u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdAdaptersSaver_set_callback(R4StdAdaptersSaver *self, uintptr_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)(uintptr_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,240u,1u,self,a,0); }
static inline R4LibrariesSlot R4StdAdaptersSaver_inspect(const R4StdAdaptersSaver *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,240u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value241_create(R4Lib_Value241 *output, const uint8_t * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,241u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value241_inspect(const R4Lib_Value241 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,241u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value242_create(R4Lib_Value242 *output, uint8_t * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,242u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value242_inspect(const R4Lib_Value242 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,242u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value243_create(R4Lib_Value243 *output, uint32_t * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,243u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value243_inspect(const R4Lib_Value243 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,243u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value244_create(R4Lib_Value244 *output, int32_t * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,244u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value244_inspect(const R4Lib_Value244 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,244u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value245_create(R4Lib_Value245 *output, R4StdSettingsWriteback * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,245u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value245_inspect(const R4Lib_Value245 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,245u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value246_create(R4Lib_Value246 *output, R4Lib_r4os_gui_TextArea___u8_ * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,246u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value246_inspect(const R4Lib_Value246 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,246u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_text_file_LoadResult_create(R4Lib_R4STD_Bindings_Zig_text_file_LoadResult *output) {
 R4LibrariesSlot a[4]={0};
 a[0].flags=R4LIBRARIES_DEFAULT;
 a[1].flags=R4LIBRARIES_DEFAULT;
 a[2].flags=R4LIBRARIES_DEFAULT;
 a[3].flags=R4LIBRARIES_DEFAULT;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,249u,a,4u,output);
}
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_text_file_LoadResult_from_fields(R4Lib_R4STD_Bindings_Zig_text_file_LoadResult *output, uint8_t p0, uint8_t p1, uint32_t p2, int32_t p3) {
 R4LibrariesSlot a[4]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,249u,a,4u,output);
}
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_text_file_LoadResult_get_ok(const R4Lib_R4STD_Bindings_Zig_text_file_LoadResult *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,249u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_text_file_LoadResult_set_ok(R4Lib_R4STD_Bindings_Zig_text_file_LoadResult *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,249u,0u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_text_file_LoadResult_get_truncated(const R4Lib_R4STD_Bindings_Zig_text_file_LoadResult *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,249u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_text_file_LoadResult_set_truncated(R4Lib_R4STD_Bindings_Zig_text_file_LoadResult *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,249u,1u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_text_file_LoadResult_get_bytes_read(const R4Lib_R4STD_Bindings_Zig_text_file_LoadResult *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,249u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_text_file_LoadResult_set_bytes_read(R4Lib_R4STD_Bindings_Zig_text_file_LoadResult *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,249u,2u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_text_file_LoadResult_get_error_code(const R4Lib_R4STD_Bindings_Zig_text_file_LoadResult *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,249u,3u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_text_file_LoadResult_set_error_code(R4Lib_R4STD_Bindings_Zig_text_file_LoadResult *self, int32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,249u,3u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_text_file_LoadResult_inspect(const R4Lib_R4STD_Bindings_Zig_text_file_LoadResult *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,249u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_text_file_SaveResult_create(R4Lib_R4STD_Bindings_Zig_text_file_SaveResult *output) {
 R4LibrariesSlot a[2]={0};
 a[0].flags=R4LIBRARIES_DEFAULT;
 a[1].flags=R4LIBRARIES_DEFAULT;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,250u,a,2u,output);
}
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_text_file_SaveResult_from_fields(R4Lib_R4STD_Bindings_Zig_text_file_SaveResult *output, uint8_t p0, int32_t p1) {
 R4LibrariesSlot a[2]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,250u,a,2u,output);
}
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_text_file_SaveResult_get_ok(const R4Lib_R4STD_Bindings_Zig_text_file_SaveResult *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,250u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_text_file_SaveResult_set_ok(R4Lib_R4STD_Bindings_Zig_text_file_SaveResult *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,250u,0u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_text_file_SaveResult_get_bytes_written(const R4Lib_R4STD_Bindings_Zig_text_file_SaveResult *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,250u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_text_file_SaveResult_set_bytes_written(R4Lib_R4STD_Bindings_Zig_text_file_SaveResult *self, int32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,250u,1u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4STD_Bindings_Zig_text_file_SaveResult_inspect(const R4Lib_R4STD_Bindings_Zig_text_file_SaveResult *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,250u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value251_create(R4Lib_Value251 *output, R4StdSubsystemAccessStats * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,251u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value251_inspect(const R4Lib_Value251 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,251u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value252_inspect(const R4Lib_Value252 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,252u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value253_inspect(const R4Lib_Value253 *self, R4StdSubsystemInspection *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,253u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value254_inspect(const R4Lib_Value254 *self, R4Lib_r4os_subsystem_catalog_Input *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,254u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value255_create(R4Lib_Value255 *output, R4StdSettingsEntryIterator * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,255u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value255_inspect(const R4Lib_Value255 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,255u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value256_create(R4Lib_Value256 *output, R4StdSettingsWriter * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,256u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value256_inspect(const R4Lib_Value256 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,256u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value257_create(R4Lib_Value257 *output, const R4StdSettingsWriter * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,257u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value257_inspect(const R4Lib_Value257 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,257u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value258_create(R4Lib_Value258 *output, const R4StdSettingsWriteback * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,258u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value258_inspect(const R4Lib_Value258 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,258u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value259_create(R4Lib_Value259 *output, R4StdTimeHelpersConfig * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,259u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value259_inspect(const R4Lib_Value259 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,259u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value260_create(R4Lib_Value260 *output, R4StdCodecStream * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,260u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value260_inspect(const R4Lib_Value260 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,260u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value261_create(R4Lib_Value261 *output, const R4StdCodecStream * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,261u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value261_inspect(const R4Lib_Value261 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,261u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value262_inspect(const R4Lib_Value262 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,262u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value263_create(R4Lib_Value263 *output, R4StdGraphemeState * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,263u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value263_inspect(const R4Lib_Value263 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,263u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value264_create(R4Lib_Value264 *output, R4StdGraphemeIterator * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,264u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value264_inspect(const R4Lib_Value264 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,264u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value265_inspect(const R4Lib_Value265 *self, R4StdGraphemeRange *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,265u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value266_create(R4Lib_Value266 *output, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,266u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value266_inspect(const R4Lib_Value266 *self, R4StdGraphemeRange *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,266u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value267_create(R4Lib_Value267 *output, R4StdGraphemeStream * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,267u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value267_inspect(const R4Lib_Value267 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,267u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value268_inspect(const R4Lib_Value268 *self, R4StdGraphemeStream_Event *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,268u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value269_create(R4Lib_Value269 *output, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,269u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value269_inspect(const R4Lib_Value269 *self, R4StdGraphemeStream_Event *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,269u,(void *)self,output); }
static inline R4LibrariesSlot R4StdGraphemeStream_Event_create(R4StdGraphemeStream_Event *output, uint64_t p0, uint32_t p1, uint64_t p2, uint8_t p3) {
 R4LibrariesSlot a[4]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,270u,a,4u,output);
}
static inline R4LibrariesSlot R4StdGraphemeStream_Event_from_fields(R4StdGraphemeStream_Event *output, uint64_t p0, uint32_t p1, uint64_t p2, uint8_t p3) {
 R4LibrariesSlot a[4]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,270u,a,4u,output);
}
static inline R4LibrariesSlot R4StdGraphemeStream_Event_get_offset(const R4StdGraphemeStream_Event *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,270u,0u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdGraphemeStream_Event_set_offset(R4StdGraphemeStream_Event *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,270u,0u,self,a,0); }
static inline R4LibrariesSlot R4StdGraphemeStream_Event_get_scalar(const R4StdGraphemeStream_Event *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,270u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdGraphemeStream_Event_set_scalar(R4StdGraphemeStream_Event *self, uint32_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,270u,1u,self,a,0); }
static inline R4LibrariesSlot R4StdGraphemeStream_Event_get_byte_length(const R4StdGraphemeStream_Event *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,270u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdGraphemeStream_Event_set_byte_length(R4StdGraphemeStream_Event *self, uint64_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,270u,2u,self,a,0); }
static inline R4LibrariesSlot R4StdGraphemeStream_Event_get_break_before(const R4StdGraphemeStream_Event *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,270u,3u,(void *)self,0,0); }
static inline R4LibrariesSlot R4StdGraphemeStream_Event_set_break_before(R4StdGraphemeStream_Event *self, uint8_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,270u,3u,self,a,0); }
static inline R4LibrariesSlot R4StdGraphemeStream_Event_inspect(const R4StdGraphemeStream_Event *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,270u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value271_create(R4Lib_Value271 *output, const R4StdGraphemeStream * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,271u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value271_inspect(const R4Lib_Value271 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,271u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value272_create(R4Lib_Value272 *output, R4StdShortcutShortcut * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,272u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value272_inspect(const R4Lib_Value272 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,272u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value273_inspect(const R4Lib_Value273 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,273u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value274_create(R4Lib_Value274 *output, const R4StdShortcutShortcut * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,274u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value274_inspect(const R4Lib_Value274 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,274u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value275_inspect(const R4Lib_Value275 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,275u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value276_inspect(const R4Lib_Value276 *self, R4StdShortcutResolvedTarget *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,276u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value277_create(R4Lib_Value277 *output, const R4StdAssociationExtEntry * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,277u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value277_inspect(const R4Lib_Value277 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,277u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value278_create(R4Lib_Value278 *output, R4StdAssociationConfig * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,278u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value278_inspect(const R4Lib_Value278 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,278u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value279_create(R4Lib_Value279 *output, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,279u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value279_inspect(const R4Lib_Value279 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,279u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value280_create(R4Lib_Value280 *output, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,280u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value280_inspect(const R4Lib_Value280 *self, R4StdAssociationLaunchTarget *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,280u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value281_create(R4Lib_Value281 *output, const R4StdFileHandlerChoiceList * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,281u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value281_inspect(const R4Lib_Value281 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,281u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value282_create(R4Lib_Value282 *output, const R4StdFileHandlerChoice * p0, uintptr_t n0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.length=n0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,282u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value282_inspect(const R4Lib_Value282 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,282u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value283_inspect(const R4Lib_Value283 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,283u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value284_create(R4Lib_Value284 *output, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,284u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value284_inspect(const R4Lib_Value284 *self, R4ImgHelpersRasterContext *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,284u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value285_inspect(const R4Lib_Value285 *self, R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgRasterColor *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,285u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value286_inspect(const R4Lib_Value286 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,286u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value287_create(R4Lib_Value287 *output, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,287u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value287_inspect(const R4Lib_Value287 *self, R4ImgHelpersContext *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,287u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value288_inspect(const R4Lib_Value288 *self, R4ImgHelpersInfo *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,288u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value289_inspect(const R4Lib_Value289 *self, R4ImgHelpersImage *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,289u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value290_inspect(const R4Lib_Value290 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,290u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value291_inspect(const R4Lib_Value291 *self, R4ImgHelpersDecoderDiagnostic *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,291u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value292_create(R4Lib_Value292 *output, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,292u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value292_inspect(const R4Lib_Value292 *self, R4ImgHelpersPngContext *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,292u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value293_inspect(const R4Lib_Value293 *self, R4Lib_R4IMG_Bindings_Zig_r4img_abi_R4ImgPngColor *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,293u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value294_inspect(const R4Lib_Value294 *self, R4ImgHelpersImage16 *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,294u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value295_create(R4Lib_Value295 *output, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,295u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value295_inspect(const R4Lib_Value295 *self, R4FontHelpersContext *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,295u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value296_create(R4Lib_Value296 *output, const R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1 * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,296u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value296_inspect(const R4Lib_Value296 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,296u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1_create(R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1 *output, const R4Lib_r4os_runtime_r4l_InterfaceHeader * p0, uintptr_t p1, uintptr_t p2, uintptr_t p3, uintptr_t p4, uintptr_t p5, uintptr_t p6, uintptr_t p7, uintptr_t p8, uintptr_t p9, uintptr_t p10, uintptr_t p11) {
 R4LibrariesSlot a[12]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)(uintptr_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)(uintptr_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.ptr=(void *)(uintptr_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.ptr=(void *)(uintptr_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.ptr=(void *)(uintptr_t)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.ptr=(void *)(uintptr_t)p6,.flags=R4LIBRARIES_PRESENT};
 a[7] = (R4LibrariesSlot){.ptr=(void *)(uintptr_t)p7,.flags=R4LIBRARIES_PRESENT};
 a[8] = (R4LibrariesSlot){.ptr=(void *)(uintptr_t)p8,.flags=R4LIBRARIES_PRESENT};
 a[9] = (R4LibrariesSlot){.ptr=(void *)(uintptr_t)p9,.flags=R4LIBRARIES_PRESENT};
 a[10] = (R4LibrariesSlot){.ptr=(void *)(uintptr_t)p10,.flags=R4LIBRARIES_PRESENT};
 a[11] = (R4LibrariesSlot){.ptr=(void *)(uintptr_t)p11,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,297u,a,12u,output);
}
static inline R4LibrariesSlot R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1_from_fields(R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1 *output, const R4Lib_r4os_runtime_r4l_InterfaceHeader * p0, uintptr_t p1, uintptr_t p2, uintptr_t p3, uintptr_t p4, uintptr_t p5, uintptr_t p6, uintptr_t p7, uintptr_t p8, uintptr_t p9, uintptr_t p10, uintptr_t p11) {
 R4LibrariesSlot a[12]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 a[1] = (R4LibrariesSlot){.ptr=(void *)(uintptr_t)p1,.flags=R4LIBRARIES_PRESENT};
 a[2] = (R4LibrariesSlot){.ptr=(void *)(uintptr_t)p2,.flags=R4LIBRARIES_PRESENT};
 a[3] = (R4LibrariesSlot){.ptr=(void *)(uintptr_t)p3,.flags=R4LIBRARIES_PRESENT};
 a[4] = (R4LibrariesSlot){.ptr=(void *)(uintptr_t)p4,.flags=R4LIBRARIES_PRESENT};
 a[5] = (R4LibrariesSlot){.ptr=(void *)(uintptr_t)p5,.flags=R4LIBRARIES_PRESENT};
 a[6] = (R4LibrariesSlot){.ptr=(void *)(uintptr_t)p6,.flags=R4LIBRARIES_PRESENT};
 a[7] = (R4LibrariesSlot){.ptr=(void *)(uintptr_t)p7,.flags=R4LIBRARIES_PRESENT};
 a[8] = (R4LibrariesSlot){.ptr=(void *)(uintptr_t)p8,.flags=R4LIBRARIES_PRESENT};
 a[9] = (R4LibrariesSlot){.ptr=(void *)(uintptr_t)p9,.flags=R4LIBRARIES_PRESENT};
 a[10] = (R4LibrariesSlot){.ptr=(void *)(uintptr_t)p10,.flags=R4LIBRARIES_PRESENT};
 a[11] = (R4LibrariesSlot){.ptr=(void *)(uintptr_t)p11,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,297u,a,12u,output);
}
static inline R4LibrariesSlot R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1_get_header(const R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1 *self, R4Lib_r4os_runtime_r4l_InterfaceHeader *output) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,297u,0u,(void *)self,0,output); }
static inline R4LibrariesSlot R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1_set_header(R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1 *self, const R4Lib_r4os_runtime_r4l_InterfaceHeader * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,297u,0u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1_get_sniff(const R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1 *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,297u,1u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1_set_sniff(R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1 *self, uintptr_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)(uintptr_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,297u,1u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1_get_decoder_create(const R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1 *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,297u,2u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1_set_decoder_create(R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1 *self, uintptr_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)(uintptr_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,297u,2u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1_get_decoder_destroy(const R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1 *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,297u,3u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1_set_decoder_destroy(R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1 *self, uintptr_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)(uintptr_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,297u,3u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1_get_decoder_diagnostics(const R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1 *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,297u,4u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1_set_decoder_diagnostics(R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1 *self, uintptr_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)(uintptr_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,297u,4u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1_get_decoder_open_face(const R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1 *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,297u,5u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1_set_decoder_open_face(R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1 *self, uintptr_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)(uintptr_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,297u,5u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1_get_face_close(const R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1 *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,297u,6u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1_set_face_close(R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1 *self, uintptr_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)(uintptr_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,297u,6u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1_get_face_info(const R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1 *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,297u,7u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1_set_face_info(R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1 *self, uintptr_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)(uintptr_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,297u,7u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1_get_glyph_index(const R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1 *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,297u,8u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1_set_glyph_index(R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1 *self, uintptr_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)(uintptr_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,297u,8u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1_get_glyph_metrics(const R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1 *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,297u,9u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1_set_glyph_metrics(R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1 *self, uintptr_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)(uintptr_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,297u,9u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1_get_kerning(const R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1 *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,297u,10u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1_set_kerning(R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1 *self, uintptr_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)(uintptr_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,297u,10u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1_get_rasterize(const R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1 *self) { return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,297u,11u,(void *)self,0,0); }
static inline R4LibrariesSlot R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1_set_rasterize(R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1 *self, uintptr_t p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)(uintptr_t)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesField(R4Libraries_ABI_FINGERPRINT,297u,11u,self,a,0); }
static inline R4LibrariesSlot R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1_inspect(const R4Lib_R4FONT_Bindings_Zig_r4font_abi_ApiV1 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,297u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value299_create(R4Lib_Value299 *output, const R4Lib_r4os_runtime_r4l_InterfaceHeader * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,299u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value299_inspect(const R4Lib_Value299 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,299u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value300_create(R4Lib_Value300 *output, const R4FontHelpersContext * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,300u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value300_inspect(const R4Lib_Value300 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,300u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value301_create(R4Lib_Value301 *output, R4LibrariesSlot p0) { R4LibrariesSlot a[1]={0};
 a[0] = p0;
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,301u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value301_inspect(const R4Lib_Value301 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,301u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value302_inspect(const R4Lib_Value302 *self, R4FontHelpersDecoder *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,302u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value303_create(R4Lib_Value303 *output, R4FontHelpersDecoder * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,303u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value303_inspect(const R4Lib_Value303 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,303u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value304_create(R4Lib_Value304 *output, const R4FontHelpersDecoder * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,304u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value304_inspect(const R4Lib_Value304 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,304u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value305_inspect(const R4Lib_Value305 *self, R4FontHelpersFace *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,305u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value306_create(R4Lib_Value306 *output, R4FontHelpersFace * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,306u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value306_inspect(const R4Lib_Value306 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,306u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value307_create(R4Lib_Value307 *output, const R4FontHelpersFace * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,307u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value307_inspect(const R4Lib_Value307 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,307u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value308_inspect(const R4Lib_Value308 *self, R4FontHelpersFaceInfo *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,308u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value309_inspect(const R4Lib_Value309 *self, R4FontHelpersGlyphMetrics *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,309u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value310_inspect(const R4Lib_Value310 *self, R4Lib_Value218 *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,310u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value311_inspect(const R4Lib_Value311 *self, R4FontHelpersRaster *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,311u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value312_inspect(const R4Lib_Value312 *self, R4FontStoreFaceStore *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,312u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value313_create(R4Lib_Value313 *output, R4FontStoreFaceStore * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,313u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value313_inspect(const R4Lib_Value313 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,313u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value314_inspect(const R4Lib_Value314 *self, R4FontStoreFaceHandle *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,314u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value315_create(R4Lib_Value315 *output, R4FontStoreFaceHandle * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,315u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value315_inspect(const R4Lib_Value315 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,315u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value316_inspect(const R4Lib_Value316 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,316u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value317_inspect(const R4Lib_Value317 *self, R4FontHelpersFaceInfo *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,317u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value318_inspect(const R4Lib_Value318 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,318u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value319_inspect(const R4Lib_Value319 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,319u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value320_inspect(const R4Lib_Value320 *self, R4FontStoreFaceMetrics26_6 *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,320u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value321_inspect(const R4Lib_Value321 *self, R4FontStoreGlyphMetrics26_6 *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,321u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value322_inspect(const R4Lib_Value322 *self, R4Lib_Value218 *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,322u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value323_inspect(const R4Lib_Value323 *self, R4FontHelpersRaster *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,323u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value324_inspect(const R4Lib_Value324 *self, R4FontStoreBorrowedRaster *output) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,324u,(void *)self,output); }
static inline R4LibrariesSlot R4Lib_Value325_create(R4Lib_Value325 *output, const R4FontStoreFaceStore * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,325u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value325_inspect(const R4Lib_Value325 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,325u,(void *)self,0); }
static inline R4LibrariesSlot R4Lib_Value326_create(R4Lib_Value326 *output, R4LibraryMemory * p0) { R4LibrariesSlot a[1]={0};
 a[0] = (R4LibrariesSlot){.ptr=(void *)p0,.flags=R4LIBRARIES_PRESENT};
 return R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT,326u,a,1u,output); }
static inline R4LibrariesSlot R4Lib_Value326_inspect(const R4Lib_Value326 *self) { return R4LibrariesInspect(R4Libraries_ABI_FINGERPRINT,326u,(void *)self,0); }
#endif
