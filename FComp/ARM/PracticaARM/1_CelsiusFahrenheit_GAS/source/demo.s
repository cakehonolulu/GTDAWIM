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

.data
		.align 2
	temp1C:	.word 0x0002335C		@; temp1C = 35.21 ºC
	temp2F:	.word 0xFFFE8400		@; temp2F = -23.75 ºF

.bss
		.align 2
	temp1F:	.space 4				@; expected conversion:  95.379638671875 ºF
	temp2C:	.space 4				@; expected conversion: -30.978271484375 ºC


.text
		.align 2
		.arm
		.global main
main:
		push {lr}
		
			@; temp1F = Celsius2Fahrenheit(temp1C);
		
			@; temp2C = Fahrenheit2Celsius(temp2F);

@; TESTING POINT: check the results
@;	(gdb) p /x temp1F		-> 0x0005F613
@;	(gdb) p /x temp2C		-> 0xFFFE1059
@; BREAKPOINT
		mov r0, #0					@; return(0)
		
		pop {pc}

.end

