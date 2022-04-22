@;----------------------------------------------------------------
@;  CelsiusFahrenheit.s: rutines de conversi� de temperatura en 
@;						 format Q12 (Coma Fixa 1:19:12). 
@;----------------------------------------------------------------
@;	santiago.romani@urv.cat
@;	pere.millan@urv.cat
@;	(Mar� 2021, Mar� 2022)
@;----------------------------------------------------------------
@;	Programador/a 1: xxx.xxx@estudiants.urv.cat
@;	Programador/a 2: yyy.yyy@estudiants.urv.cat
@;----------------------------------------------------------------*/

.include "Q12.i"

.bss
.align 2
output:
		.space 4

.align 2
prod64:
		.space 8

.text
		.align 2
		.arm


@; Celsius2Fahrenheit(): converteix una temperatura en graus Celsius a la
@;						temperatura equivalent en graus Fahrenheit, utilitzant
@;						valors codificats en Coma Fixa 1:19:12.
@;	Entrada:
@;		input 	-> R0
@;	Sortida:
@;		R0 		-> output = (input * 9/5) + 32.0;
@;		R3		-> 3_LibQ12
.global Celsius2Fahrenheit
Celsius2Fahrenheit:
		# We will clobber original r1 to r4 values
		# push them to the stack to preserve them
		# Push Link Register too to return to main()
		push {r1 - r3, lr}

		# r1 = MAKE_Q12(9.0/5.0)
		ldr r3, =MAKE_Q12_9_div_5

		# 32*32-bit multiplication (64-bit result)
		# Takes 2 32-bit registers (32 bit low-high pair respectively)
		# multiplies them and sets the low and high values accordingly
		# Example:
		# r0 (32) * r1 (32) = [r1 (32) : r2 (32)] (64)
		smull r1, r2, r0, r3

		# Grab the integer part of the value
		mov r1, r1, lsr #12

		# Load the Mask Value
		ldr r3, =MASK_FRAC

		# Get the fractional part from hi register
		# and AND-it with [r3's] mask
		and r3, r2, r3

		# Logical shift to the left the value
		mov r3, r3, lsl #20

		# Join r3 and r1 into r0, this is the result
		orr r0, r3, r1

		# Add MAKE_Q12(32.0)'s value to the result
		add r0, #MAKE_Q12_32

		# Restore to the previous control block
		pop {r1 - r3, pc}

@; Fahrenheit2Celsius(): converteix una temperatura en graus Fahrenheit a la
@;						temperatura equivalent en graus Celsius, utilitzant
@;						valors codificats en Coma Fixa 1:19:12.
@;	Entrada:r0
@;	Sortida:
@;		R0 		-> output = (input - 32.0) * 5/9;
@;		R3		-> 3_LibQ12
.global Fahrenheit2Celsius
Fahrenheit2Celsius:
		# We will clobber original r1 to r4 values
		# push them to the stack to preserve them
		# Push Link Register too to return to main()
		push {r1 - r3, lr}

		# r1 = MAKE_Q12(32.0)
		ldr r1, =MAKE_Q12_32

		# Substract MAKE_Q12(32.0)'s value from input (r0) 
		sub r0, r0, r1

		# r5 = &prod64
		ldr r3, =prod64

		# r1 = lo 32 bits of prod64
		ldr r1, [r3]

		# r2 = hi 32 bits of prod64 (Base + 4 offset)
		ldr r2, [r3, #4]

		# r3 = MAKE_Q12(5.0/9.0)
		ldr r3, =MAKE_Q12_5_div_9
		
		# 32*32-bit multiplication (64-bit result)
		# Takes 2 32-bit registers (32 bit low-high pair respectively)
		# multiplies them and sets the low and high values accordingly
		# Example:
		# r0 (32) * r1 (32) = [r2 (32) : r3 (32)] (64)
		smull r1, r2, r0, r3

		# Grab the integer part of the value
		mov r0, r1, lsr #12

		# Load the mask val. to the register
		ldr r3, =MASK_FRAC
		
		# Mask the fractional part
		# pseudo:
		# high_32bits = (64bit_val & 0xFFFF00000)
		# r4 = high_32bits & MASK_FRAC (0x00000FFF)
		and r3, r2, r3

		# This gets us the fractional part
		mov r3, r3, lsl #20

		# Join the registers
		orr r2, r3, r0

		# Last bitshift, accomodate in r3
		mov r3, r3, asr #12

		# Result value is expected to be in r0
		mov r0, r2
		
		# Restore to the previous control block
		pop {r1 - r3, pc}
