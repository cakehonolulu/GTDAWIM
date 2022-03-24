.arm

.code 32

.section .rodata

.align 2
a:
	.int 3

b:
	.int 4

.section .data

.align 2
mul:
	.int 0

.section .bss
.align 2
i:
	.space 4

.section .text

.global main

.align 2

main:
	ldr r4, =a
	ldr r5, =b
	ldr r6, =i
	ldr r7, =mul

	ldr r0, [r4]
	ldr r1, [r5]
	ldr r2, [r6]
	ldr r3, [r7]

	# (i = 0)
	mov r2, #0

.loop:
	add r3, r0
	add r2, #1
	cmp r2, r1
	blo .loop

	mov pc, lr
	
.end
