.section .bss
i:
	.space 4

.section .data
s:
	.int 0

.section .text

.arm

.code 32

.global main

.align 2

main:
	# Loop construction
	# (i = 1)
	ldr r0, =i
	mov r1, #1
	str r1, [r0]

	# (s = 0)
	ldr r1, =s
	mov r2, #0
	str r2, [r1]

	# r2 = i
	# r3 = s
	ldr r2, [r0]
	ldr r3, [r1]

loop:
	# s += i
	add r3, r2
	add r2, #1
	cmp r2, #9
	bne loop

	# Store the result in [r1] (*s)
	str r3, [r1]
.end
