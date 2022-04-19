.section .text

.global _start

.extern main

.arm
.code 32
.align 2
_start:
	nop
	bl main
.halt:
	b .halt

.end
