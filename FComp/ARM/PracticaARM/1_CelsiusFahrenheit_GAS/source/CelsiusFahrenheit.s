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

.data
.align 2
Q12:
	.int 0x00001CCD

.align 2
inv_a_Q12:
	.int 0x00020000

.align 2
inv_Q12:
	.int 0x000008E4

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
		push {r3, r5, lr}
	inv_Q12
		ldr r5, =prod64
		ldr r6, =output

		ldr r7, =Q12

		ldr r8, =inv_a_Q12

		ldr r9, [r8]

		# R2 = lo 32-bits
		ldr r1, [r5]

		# R3 = hi 32-bits
		ldr r2, [r5, #4]

		# R5 = output
		ldr r3, [r6]

		# R7 = MAKE_Q12(9.0/5.0)
		ldr r4, [r7]

		umull r1, r2, r0, r4

		mov r0, r1, lsr #12

		add r0, r9
		
		pop {r3, r5, pc}

@; Fahrenheit2Celsius(): converteix una temperatura en graus Fahrenheit a la
@;						temperatura equivalent en graus Celsius, utilitzant
@;						valors codificats en Coma Fixa 1:19:12.
@;	Entrada:
@;		input 	-> R0
@;	Sortida:
@;		R0 		-> output = (input - 32.0) * 5/9;
	.global Fahrenheit2Celsius
Fahrenheit2Celsius:
		push {r3, r5, lr}
	
		ldr r5, =prod64
		ldr r6, =output


		ldr r7, =inv_Q12
		
		ldr r8, =inv_a_Q12

		ldr r9, [r8]

		sub r0, r0, r9

		# R2 = lo 32-bits
		ldr r1, [r5]

		# R3 = hi 32-bits
		ldr r2, [r5, #4]

		# R5 = output
		ldr r3, [r6]

		# R7 = MAKE_Q12(9.0/5.0)
		ldr r4, [r7]

		umull r1, r2, r0, r4

		mov r0, r1, lsr #12
		
		pop {r3, r5, pc}
