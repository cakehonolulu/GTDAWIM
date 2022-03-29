.arm

.code 32

.section .data

.align 2
a:
	.int 30

b:
	.int 40

.section .text

.global main

.align 2

main:
	ldr r4, =a
	ldr r5, =b

	ldr r0, [r4]
	ldr r1, [r5]
	cmp r0, #0
	bhi .finish

	cmp r1, #0
	bhi .if

.if:
	cmp r0, r1
	bhi .assign
	


.finish:
	mov r0, r5
	// a = b
	str r0, [r4]
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
