;
;  CPU-A
;
;  (c) 2024-2025 TDolphin
;

; benchmark version 0.1

    xdef    _Benchmark01asm

    section code,code

; ============ Benchmark  ============
_Benchmark01asm:
        movem.l d2-d7/a2-a6,-(a7)  ; save all non-scratch registers
        cmp.l   #0,d0           ; check if loop count is zero
        beq     .exit_early     ; if zero, exit immediately
        move.l  d0,d7           ; use d7 as main loop counter (preserved)
.loop_benchmarks:
        move.l   #10000,d0
        jsr _BenchmarkAdd
        move.l   #10000,d0
        jsr _BenchmarkMuls
        move.l   #10000,d0
        jsr _BenchmarkMove
        move.l   #10000,d0
        jsr _BenchmarkOr
        move.l   #10000,d0
        jsr _BenchmarkEor
        move.l   #10000,d0
        jsr _BenchmarkCmp
        move.l   #100,d0
        jsr _BenchmarkMemCopy
        move.l   #10000,d0
        jsr _BenchmarkComplex
        subq.l  #1,d7
        bne     .loop_benchmarks
.exit_early:
        movem.l (a7)+,d2-d7/a2-a6  ; restore all non-scratch registers
        rts

; ============ ADD.L Benchmark ============
_BenchmarkAdd:
        move.l  d0,d1          ; d1 loop counter
        moveq   #0,d2
.loop_add:
        add.l   d1,d2
        subq.l  #1,d1
        bne     .loop_add
        rts

; ============ MULS Benchmark ============
_BenchmarkMuls:
        move.l  d0,d1           ; d1 loop counter
        moveq   #1,d2
        moveq   #1,d3           ; initialize d3
.loop_muls:
        muls    d2,d3
        subq.l  #1,d1
        bne     .loop_muls
        rts

; ============ MOVE.L Benchmark ============
_BenchmarkMove:
        move.l  d0,d2           ; d2 loop counter
        moveq   #0,d0
        moveq   #0,d1
.loop_move:
        move.l  d0,d1
        subq.l  #1,d2
        bne     .loop_move
        rts

; ============ OR.L Benchmark ============
_BenchmarkOr:
        move.l  d0,d2           ; d2 loop counter
        moveq   #0,d0
        moveq   #1,d1
.loop_or:
        or.l    d1,d0
        subq.l  #1,d2
        bne     .loop_or
        rts

; ============ EOR.L Benchmark ============
_BenchmarkEor:
        move.l  d0,d2           ; d2 loop counter
        moveq   #0,d0
        moveq   #1,d1
.loop_eor:
        eor.l   d1,d0
        subq.l  #1,d2
        bne     .loop_eor
        rts

; ============ CMP/BEQ Benchmark ============
_BenchmarkCmp:
        move.l  d0,d2           ; d2 loop counter
        moveq   #0,d0
        moveq   #1,d1
.loop_cmp:
        cmp.l   d1,d0
        beq     .skip
.skip:
        subq.l  #1,d2
        bne     .loop_cmp
        rts

; ============ mix/complex Benchmark ============
_BenchmarkComplex:
        move.l  d0,d2           ; d2 loop counter
        moveq   #0,d0
        moveq   #1,d1
        moveq   #0,d5
        moveq   #0,d6
.loop_cmp:
        movem.l d2-d7/a2-a6,-(a7)
        jsr     .sub_opt
        movem.l (a7)+,d2-d7/a2-a6
        cmp.l   d1,d0
        beq     .skip
.skip:
        subq.l  #1,d2
        bne     .loop_cmp
        rts
.sub_opt:
        movem.l d2-d7/a2-a6,-(a7)
        add.l   #$50505050,d5
        nop
        sub.l   #$f0f0f0f0,d6
        nop
        add.w   #$F0F0,d6
        nop
        sub.w   #$7070,d5
        movem.l (a7)+,d2-d7/a2-a6
        rts

_BenchmarkMemCopy:
.loop_outer:
        lea     SourceBuffer,a0     ; source
        lea     DestBuffer,a1       ; destination
        move.l  #256-1,d1         ; 256 longwords = 1024 bytes
.loop_inner:
        move.l  (a0)+,(a1)+
        dbra    d1,.loop_inner
        subq.l  #1,d0
        bne     .loop_outer
        rts

    section bss,bss
SourceBuffer:  ds.l 256
DestBuffer:    ds.l 256