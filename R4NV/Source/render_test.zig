const std = @import("std");
const t = std.testing;
const render = @import("render.zig");
const hw = @import("Generated/Render/c797.zig");
fn word(data: []const u8, offset: usize) u32 { return std.mem.readInt(u32, data[offset..][0..4], .little); }
fn state(program: *const render.Program, method: u32) !u32 {
    var at: usize = 0;
    var found: ?u32 = null;
    while (at < program.count) {
        const header = program.data[at];
        try t.expectEqual(@as(u32,0x20000000), header & 0xe0000000);
        const count = (header >> 16) & 0x1fff;
        try t.expect(count > 0 and at + count < program.count);
        const start = (header & 0x1fff) * 4;
        for (0..count) |index| if (start + index * 4 == method) { found = program.data[at+1+index]; };
        at += count + 1;
    }
    return found orelse error.MissingState;
}
pub fn check() !void {
    try render.reference_model.check();
    var binding: render.Binding = .{
        .draw = .{
            .target = .{ .address = 0x100000, .bytes = 65536, .width = 128, .height = 128, .pitch = 512, .format = .argb8888, .layout = .linear },
            .source = .{ .address = 0x200000, .bytes = 16384, .width = 64, .height = 64, .pitch = 256, .format = .argb8888, .layout = .linear },
            .destination = .{ .x = -16, .y = 0, .width = 128, .height = 64 },
            .source_rect = .{ .x = 0, .y = 0, .width = 64, .height = 64 },
            .scissor = .{ .x = 0, .y = 8, .width = 64, .height = 64 }, .blend = .over, .opacity = 128,
        },
        .programs = .{ .address = 0x300000, .bytes = render.shader_bytes },
        .packet = .{ .address = 0x400000, .bytes = render.packet_bytes },
    };
    var packet: [render.packet_bytes]u8 = undefined;
    var program: render.Program = .{};
    var shader_data: [render.shader_bytes]u8 = undefined;
    try render.shaderUpload(&shader_data);
    try t.expectEqual(@as(u32,0x02020481), word(&shader_data,0));
    try t.expectEqual(@as(u32,0x00025482), word(&shader_data,render.shaderOffset(1)));
    try render.packetUpload(binding.draw, &packet);
    const top_left: render.Vertex = @bitCast(packet[768..808].*);
    const bottom_right: render.Vertex = @bitCast(packet[888..928].*);
    try t.expectEqualSlices(f32, &.{-1.25,-1,0,1}, &top_left.position);
    try t.expectEqualSlices(f32, &.{0.75,0,0,1}, &bottom_right.position);
    try t.expectEqualSlices(f32, &.{0,0}, &top_left.uv);
    try t.expectEqualSlices(f32, &.{1,1}, &bottom_right.uv);
    try t.expectApproxEqAbs(@as(f32,128.0/255.0), top_left.tint[3], 0.000001);
    try t.expectEqualSlices(u8, &(@as([160]u8,@splat(0))), packet[352..512]);
    try render.encode(binding,&program);
    try t.expect(program.count < render.max_words - 11);
    try t.expectEqual(@as(u32,1), try state(&program,hw.SET_SCISSOR_ENABLE));
    try t.expectEqual(@as(u32,64<<16), try state(&program,hw.SET_SCISSOR_ENABLE+4));
    try t.expectEqual(@as(u32,8|(64<<16)), try state(&program,hw.SET_SCISSOR_ENABLE+8));
    try t.expectEqual(@as(u32,4), try state(&program,hw.DRAW_VERTEX_ARRAY_BEGIN_END_A+4));
    try t.expectEqual(@as(u32,1), try state(&program,hw.SET_BLEND));
    try t.expectEqual(@as(u32,0x4303), try state(&program,hw.SET_BLEND_PER_TARGET_SEPARATE_FOR_ALPHA+12));
    try t.expectEqual(@as(u32,160), try state(&program,hw.SET_VERTEX_STREAM_SIZE_A+4));
    try t.expectEqual(@as(u32,0x11), try state(&program,hw.BIND_GROUP_CONSTANT_BUFFER+128));
    try t.expectEqual(@as(u32,4), try state(&program,hw.SET_PIPELINE_BINDING+5*64));
    // Maximal sampled lists fit the existing 4 KB ring. Geometry and alpha
    // have separate packets; immutable shader/target state is encoded once.
    var draws: [render.batch_capacity]render.Draw = @splat(binding.draw);
    for (&draws, 0..) |*draw, index| { draw.opacity = @intCast(index + 1); draw.scissor.x = @intCast(index); }
    var packets: [render.packet_capacity_bytes]u8 = undefined;
    var batch = binding; batch.draw = draws[0]; batch.additional = draws[1..]; batch.packet.bytes = packets.len;
    try render.packetUploadList(&draws, &packets);
    try render.encode(batch, &program);
    try t.expect(program.count + 11 <= 1024);
    try t.expectEqual(@as(u32,@intCast(binding.packet.address + 15 * render.packet_bytes + 768)), try state(&program, hw.SET_VERTEX_STREAM_A_FORMAT + 8));
    for (draws, 0..) |draw, index| {
        const vertex: render.Vertex = @bitCast(packets[index * render.packet_bytes + 768..][0..40].*);
        try t.expectApproxEqAbs(@as(f32,@floatFromInt(draw.opacity)) / 255.0, vertex.tint[3], 0.000001);
    }
    const unchanged = packets;
    draws[15].target.address += 65536;
    try t.expectError(error.Unsupported, render.packetUploadList(&draws, &packets));
    try t.expectEqualSlices(u8, &unchanged, &packets);
    std.debug.print("render list: 16 sampled draws; {d} words including one release; 16384 upload bytes\n", .{program.count + 11});
    // Every fixed fragment profile binds its own immutable header/code pair.
    for ([_]render.Transfer{.identity,.decode_srgb,.encode_srgb}) |transfer| {
        binding.draw.transfer = transfer;
        try render.encode(binding,&program);
        try t.expectEqual(@as(u32,@intCast(binding.programs.address+render.shaderOffset(binding.draw.profile()-1))), try state(&program,hw.SET_PIPELINE_PROGRAM_ADDRESS_A+5*64+4));
    }
    binding.draw.transfer = .identity;
    binding.draw.source = null;
    binding.draw.color = 0x80402010;
    try render.packetUpload(binding.draw,&packet);
    const solid: render.Vertex = @bitCast(packet[768..808].*);
    try t.expectApproxEqAbs(@as(f32,64.0/255.0*128.0/255.0), solid.tint[0], 0.000001);
    try render.encode(binding,&program);
    try t.expectEqual(@as(u32,0x10), try state(&program,hw.BIND_GROUP_CONSTANT_BUFFER+128));
    try t.expectEqual(@as(u32,@intCast(binding.programs.address+render.shaderOffset(5))), try state(&program,hw.SET_PIPELINE_PROGRAM_ADDRESS_A+64+4));
    try t.expectEqual(@as(u32,0xf0f),word(&shader_data,render.shaderOffset(5)+24));
    binding.draw.color = 0x40ff0000;
    try t.expectError(error.Bounds,render.packetUpload(binding.draw,&packet));
    binding.draw.color = 0x80402010;
    binding.draw.scissor.x = 200;
    try t.expectError(error.Empty,render.encode(binding,&program));
    binding.draw.scissor.x = 0;
    binding.programs.address += 4;
    try t.expectError(error.Bounds,render.encode(binding,&program));
    binding.programs.address -= 4;
    binding.packet.address = binding.draw.target.address;
    try t.expectError(error.Unsupported,render.encode(binding,&program));
    binding.packet.address = 0x400000;
    binding.draw.source = binding.draw.target;
    try t.expectError(error.Unsupported,render.encode(binding,&program));
    binding.draw.source = null;
    binding.draw.target.address = 1<<40;
    _ = try render.image.texture(binding.draw.target);
    try t.expectError(error.Unsupported,render.encode(binding,&program));
}
