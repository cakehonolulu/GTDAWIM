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
	mov r0, #1
	# (s = 0)
	mov r1, #0
loop:
	# s += i
	add r1, r0
	add r0, #1
	cmp r0, #9
	bne loop

	nop
.end