/*
	Compile using: gcc parquets.c -Wall -Wextra -lm

	GCC Version (LLVM's Clang untested):
	$ gcc --version
	gcc (Ubuntu 11.2.0-7ubuntu2) 11.2.0

	Ubuntu Version:
	$ lsb_release -a
	No LSB modules are available.
	Distributor ID: Ubuntu
	Description:    Ubuntu 21.10
	Release:        21.10
	Codename:       impish

	Linux Kernel Version:
	$ uname -a
	Linux Desktop 5.10.16.3-microsoft-standard-WSL2 #1 SMP Fri Apr 2 22:23:49 UTC 2021 x86_64 x86_64 x86_64 GNU/Linux

	# NOTE!
	# I build the binary using WSL2, Microsoft's in-house Linux emulation layer that uses Hyper-V technology to work
	# Results should be the same as on a real Ubuntu install, but bare in mind that there could be some differences.
*/

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

/* Defines */

// I'll use them to distinguish between a good return and a bad one.
#define OK 0
#define FAIL 1

/* Variables */

/*
	I declare the next two variables as constants, because we won't be modifying them.
	We need to use decimals, so we'll have to use floating point units (floats).
*/

const float m_parquet = 2.5;	// Square meters
const float m_socol = 2.2;		// Meters

/* Functions */

/*
	I use an int32_t type for main, this lets me return ints whenever program finishes it's course.
	I stick to int32_t instead of int, because it ensures backward compatibility with non x86_64 processor.
	If compiling for an older bit-ness, change compiler flags accordingly.

	You can check which flags you need using ´´man gcc´´ on a Linux machine.
*/

int32_t main()
{
	printf("En aquest programa calcularem el nombre de paquets de parquet i socols necesaris per");
	printf("emplenar una habitació rectangular amb mides proveides per l'usuari\n");

	printf("A continuació, introdueixi la llargada: ");

	// Declare a float where scanf() will read the user input to
	// Decimal input must be separated using a point, not a comma
	float m_llargada = 0;

	scanf("%f", &m_llargada);

	printf("Ara, la amplada: ");

	// Declare a float where scanf() will read the user input to
	// Decimal input must be separated using a point, not a comma
	float m_amplada = 0;

	scanf("%f", &m_amplada);

	printf("Llargada: %f (metres), Amplada: %f (metres)\n", m_llargada, m_amplada);

	// We will now calculate the area we need to cover
	float m_area = m_llargada * m_amplada;

	printf("Per cobrir %f metres cuadrats d'habitacio, necesitarem %f unitats de parquet\n", m_area, round(m_area / m_parquet));

	printf("Per cobrir amb sócols, necesitarem %f peçes de sócols\n", round(((m_amplada * 2) + (m_amplada * 2) / m_socol)));

	return OK;
}