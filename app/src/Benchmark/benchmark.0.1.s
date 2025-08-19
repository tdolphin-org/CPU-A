|
|  CPU-A
|
|  (c) 2024-2025 TDolphin
|

| benchmark version 0.1

    .globl    _Benchmark01asm

    .text

    .bss
    .align 4
BenchRepeatCount:  .long 0

    .data
    .align 4

SourceBuffer:  .space 256*4
DestBuffer:    .space 256*4

| ============ Benchmark  ============
| parameters:
| d0 - main loop counter
| d1 - bench repeat count

_Benchmark01asm:
        link.w %a5,#0
        move.l 8(%a5),%d0        | first parameter (loops)
        move.l 12(%a5),%d1       | second parameter (repeat)
        movem.l %d2-%d7/%a2-%a6,-(%a7)  | save all non-scratch registers
        cmp.l   #0,%d0           | check if loop count is zero
        beq     .exit_early     | if zero, exit immediately
        cmp.l   #0,%d1           | check if bench repeat count is zero
        beq     .exit_early     | if zero, exit immediately
        move.l  %d0,%d7           | use d7 as main loop counter
        move.l  %d0,BenchRepeatCount  | store to variable directly like Benchmark02asm
.loop_benchmarks:
        jsr _BenchmarkAdd
        jsr _BenchmarkMuls
        jsr _BenchmarkMove
        jsr _BenchmarkOr
        jsr _BenchmarkEor
        jsr _BenchmarkCmp
        jsr _BenchmarkMemCopy
        jsr _BenchmarkComplex
        subq.l  #1,%d7
        bne     .loop_benchmarks
.exit_early:
        move.l BenchRepeatCount,%d0  | load from variable directly like Benchmark02asm
        movem.l (%a7)+,%d2-%d7/%a2-%a6  | restore all non-scratch registers
        unlk %a5
        rts

| ============ ADD.L Benchmark ============
_BenchmarkAdd:
        move.l  BenchRepeatCount,%d1  | d1 loop counter - direct access
        moveq   #0,%d2
.loop_add:
        add.l   %d1,%d2
        subq.l  #1,%d1
        bne     .loop_add
        rts

| ============ MULS Benchmark ============
_BenchmarkMuls:
        move.l  BenchRepeatCount,%d1  | d1 loop counter - direct access
        moveq   #1,%d2
        moveq   #1,%d3               | initialize d3
.loop_muls:
        muls    %d2,%d3
        subq.l  #1,%d1
        bne     .loop_muls
        rts

| ============ MOVE.L Benchmark ============
_BenchmarkMove:
        move.l  BenchRepeatCount,%d2  | d2 loop counter - direct access
        moveq   #0,%d0
        moveq   #0,%d1
.loop_move:
        move.l  %d0,%d1
        subq.l  #1,%d2
        bne     .loop_move
        rts

| ============ OR.L Benchmark ============
_BenchmarkOr:
        move.l  BenchRepeatCount,%d2  | d2 loop counter - direct access
        moveq   #0,%d0
        moveq   #1,%d1
.loop_or:
        or.l    %d1,%d0
        subq.l  #1,%d2
        bne     .loop_or
        rts

| ============ EOR.L Benchmark ============
_BenchmarkEor:
        move.l  BenchRepeatCount,%d2  | d2 loop counter - direct access
        moveq   #0,%d0
        moveq   #1,%d1
.loop_eor:
        eor.l   %d1,%d0
        subq.l  #1,%d2
        bne     .loop_eor
        rts

| ============ CMP/BEQ Benchmark ============
_BenchmarkCmp:
        move.l  BenchRepeatCount,%d2  | d2 loop counter - direct access
        moveq   #0,%d0
        moveq   #1,%d1
.loop_cmp:
        cmp.l   %d1,%d0
        beq     .skip
.skip:
        subq.l  #1,%d2
        bne     .loop_cmp
        rts

| ============ Memory Copy Benchmark ============
_BenchmarkMemCopy:
        move.l  BenchRepeatCount,%d2  | d2 loop counter - direct access
        lea     SourceBuffer,%a0      | source buffer address
        lea     DestBuffer,%a1        | destination buffer address
.loop_memcopy:
        moveq   #63,%d1               | copy 64 longs (256 bytes)
.inner_loop:
        move.l  (%a0)+,(%a1)+        | copy long from source to dest
        dbf     %d1,.inner_loop       | decrement and branch
        lea     SourceBuffer,%a0      | reset source pointer
        lea     DestBuffer,%a1        | reset dest pointer
        subq.l  #1,%d2
        bne     .loop_memcopy
        rts

| ============ mix/complex Benchmark ============
_BenchmarkComplex:
        move.l  BenchRepeatCount,%d2  | d2 loop counter - direct access
        moveq   #0,%d0
        moveq   #1,%d1
        moveq   #0,%d5
        moveq   #0,%d6
.loop_complex:
        jsr     .sub_opt
        cmp.l   %d1,%d0
        beq     .skip_complex
.skip_complex:
        subq.l  #1,%d2
        bne     .loop_complex
        rts
.sub_opt:
        movem.l %d0-%d7/%a0-%a6,-(%a7)
        add.l   #0x50505050,%d5
        nop
        sub.l   #0xf0f0f0f0,%d6
        nop
        add.w   #0xF0F0,%d6
        nop
        sub.w   #0x7070,%d5
        movem.l (%a7)+,%d0-%d7/%a0-%a6
        rts
