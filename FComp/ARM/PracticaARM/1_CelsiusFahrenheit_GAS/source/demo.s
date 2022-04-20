@;-----------------------------------------------------------------------
@;   Description: a program to check the temperature-scale conversion
@;				functions implemented in "CelsiusFahrenheit.c".
@;	IMPORTANT NOTE: there is a much confident testing set implemented in
@;				"tests/test_CelsiusFahrenheit.c"; the aim of "demo.s" is
@;				to show how would it be a usual main() code invoking the
@;				mentioned functions.
@;-----------------------------------------------------------------------
@;	Author: Santiago Romani (DEIM, URV)
@;	Date:   March/2022 
@;-----------------------------------------------------------------------
@;	Programmer 1: xxx.xxx@estudiants.urv.cat
@;	Programmer 2: yyy.yyy@estudiants.urv.cat
@;-----------------------------------------------------------------------*/

# Section .data contains pre-initialized variables
.data
		.align 2
		temp1C:	.word 0x0002335C		@; temp1C = 35.21 �C
		temp2F:	.word 0xFFFE8400		@; temp2F = -23.75 �F

# Section .bss contains un-initialized variables
.bss
		.align 2
		temp1F:	.space 4				@; expected conversion:  95.379638671875 �F
		temp2C:	.space 4				@; expected conversion: -30.978271484375 �C

# Section .text contains the actual code
.text
		.align 2
		.arm
		.global main
main:
		# Push Link Register's Content to Stack
		push {lr}

		# r1 = &temp1C
		ldr r1, =temp1C

		# r2 = &temp1F
		ldr r2, =temp1F

		# r3 = &temp2F
		ldr r3, =temp2F

		# r4 = &temp2C
		ldr r4, =temp2C

		# r0 = (*r1)
		ldr r0, [r1]

		# Subroutine call:
		# Celsius2Fahrenheit(input: r0)
		bl Celsius2Fahrenheit

		# Store the result of the above function @ temp1F's mem. addr.
		str r0, [r2]

		# r0 = (*r3)
		ldr r0, [r3]

		# Subroutine call:
		# Fahrenheit2Celsius(input: r0)
		bl Fahrenheit2Celsius

		# Store the result of the above function @ temp2C's mem. addr.
		str r0, [r4]

		# Check results
		# (gdb) p /x (int) temp1F		-> 0x0005F613
		# (gdb) p /x (int) temp2C		-> 0xFFFE1059

		# Set r0 (retval) to 0
		mov r0, #0
		
		# Jump back to main caller
		pop {pc}
.end
