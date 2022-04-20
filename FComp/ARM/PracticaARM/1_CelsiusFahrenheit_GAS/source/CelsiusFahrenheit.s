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
.global Celsius2Fahrenheit
Celsius2Fahrenheit:
		# We will clobber original r1 to r4 values
		# push them to the stack to preserve them
		# Push Link Register too to return to main()
		push {r1 - r4, lr}

		# r1 = MAKE_Q12(9.0/5.0)
		ldr r1, =MAKE_Q12_9_div_5

		# 32*32-bit multiplication (64-bit result)
		# Takes 2 32-bit registers (32 bit low-high pair respectively)
		# multiplies them and sets the low and high values accordingly
		# Example:
		# r0 (32) * r1 (32) = [r2 (32) : r3 (32)] (64)
		smull r2, r3, r0, r1

		# Grab the integer part of the value
		mov r2, r2, lsr #12
		
		# Load the mask val. to the register
		ldr r5, =MASK_FRAC
		
		# Mask the fractional part
		# pseudo:
		# high_32bits = (64bit_val & 0xFFFF00000)
		# r4 = high_32bits & MASK_FRAC (0x00000FFF)
		and r4, r3, r5

		mov r4, r4, lsl #20
		orr r0, r4, r2
		mov r3, r3, asr #12

		# Add MAKE_Q12(32.0)'s value to the result
		add r2, r2, #MAKE_Q12_32

		# Result value is expected to be in r0
		mov r0, r2

		# Restore to the previous control block
		pop {r1 - r4, pc}

@; Fahrenheit2Celsius(): converteix una temperatura en graus Fahrenheit a la
@;						temperatura equivalent en graus Celsius, utilitzant
@;						valors codificats en Coma Fixa 1:19:12.
@;	Entrada:r0
.global Fahrenheit2Celsius
Fahrenheit2Celsius:
		# We will clobber original r1 to r4 values
		# push them to the stack to preserve them
		# Push Link Register too to return to main()
		push {r1 - r4, lr}

		# r4 = MAKE_Q12(5.0/9.0)
		ldr r4, =MAKE_Q12_5_div_9
		
		# r5 = &prod64
		ldr r5, =prod64

		# r6 = &output
		ldr r6, =output

		# r7 = MAKE_Q12(32.0)
		ldr r7, =MAKE_Q12_32

		# Substract MAKE_Q12(32.0)'s value from input (r0) 
		sub r0, r0, r7

		# r1 = lo 32 bits of prod64
		ldr r1, [r5]

		# r2 = hi 32 bits of prod64 (Base + 4 offset)
		ldr r2, [r5, #4]

		# r6 = output
		ldr r3, [r6]

		# 32*32-bit multiplication (64-bit result)
		# Takes 2 32-bit registers (32 bit low-high pair respectively)
		# multiplies them and sets the low and high values accordingly
		# Example:
		# r0 (32) * r1 (32) = [r2 (32) : r3 (32)] (64)
		smull r1, r2, r0, r4

		# Grab the integer part of the value
		mov r0, r1, lsr #12

		# Load the mask val. to the register
		ldr r5, =MASK_FRAC
		
		# Mask the fractional part
		# pseudo:
		# high_32bits = (64bit_val & 0xFFFF00000)
		# r4 = high_32bits & MASK_FRAC (0x00000FFF)
		and r5, r2, r5

		mov r5, r5, lsl #20
		orr r2, r5, r0
		mov r3, r3, asr #12

		# Result value is expected to be in r0
		mov r0, r2
		
		# Restore to the previous control block
		pop {r1 - r4, pc}
