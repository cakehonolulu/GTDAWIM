.arm

.code 32

.section .rodata

.align 2
a:
	.int 3

.section .data

.align 2
pot2:
	.int 1

.section .bss
.align 2
i:
	.space 4

.section .text

.global main

.align 2

main:
	ldr r4, =a
	ldr r5, =pot2
	ldr r6, =i

	ldr r0, [r4]
	ldr r1, [r5]
	ldr r2, [r6]

	# (i = 0)
	mov r2, #0

.loop:
	add r1, r1, r1
	add r2, #1
	cmp r2, r0
	blo .loop

	mov pc, lr
	
.end
