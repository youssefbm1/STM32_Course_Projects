    .syntax unified
    .global _start
    .thumb

_start:
    ldr sp, = 0x10008000 
    @bl init_bbs
    bl main
_exit:
    b _exit
