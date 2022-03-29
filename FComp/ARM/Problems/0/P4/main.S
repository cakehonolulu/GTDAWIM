.arm

.code 32

.section .rodata

.align 2
a:
	.int 3

b:
	.int 40

.section .data

.align 2
div:
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
	ldr r5, =div
	ldr r6, =i

	ldr r0, [r4]
	ldr r1, [r5]
	ldr r2, [r6]

	# (i = 0)
	mov r2, #40

	cmp r0, r2
	bl .while

.end:
	b .end

.while:
	cmp r2, #0
	bhi .loop
	mov pc, lr

.loop:
	sub r2, r2, r0  
	add r1, #1
	b .while

.end
