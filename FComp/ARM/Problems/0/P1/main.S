.arm

.code 32

.section .data

.align 2
fib0:
	.int 0

fib1:
	.int 1

.section .bss
.align 2
fib2:
	.space 4

i:
	.space 4

.section .text

.global main

.align 2

main:
	ldr r3, =fib0
	ldr r4, =fib1
	ldr r5, =fib2

	# r0-2 contains fib0-3
	ldr r0, [r3]
	ldr r1, [r4]
	ldr r2, [r5]

	ldr r4, =i

	# r3 contains i
	ldr r3, [r4]

	# Loop construction
	# (i = 1)
	mov r3, #1

.loop:
	add r2, r1, r0
	mov r0, r1
	mov r1, r2
	add r3, #1
	cmp r3, #49
	blo .loop

	mov pc, lr
	
.end
