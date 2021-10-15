/*
	Compile using: gcc prac0.c -Wall -Wextra (Use -DDEBUG switch if you want to enable debugging)
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
	
	$ uname -a
	Linux Desktop 5.10.60.1-microsoft-standard-WSL2 #1 SMP Wed Aug 25 23:20:18 UTC 2021 x86_64 x86_64 x86_64 GNU/Linux

	# NOTE!
	# I build the binary using WSL2, Microsoft's in-house Linux emulation layer that uses Hyper-V technology to work
	# Results should be the same as on a real Ubuntu install, but bare in mind that there could be some differences.
*/

// stdint for standard integer types
#include <stdint.h>
// stdio for printf and scanf decl.
#include <stdio.h>
// stdbool for booleans
#include <stdbool.h>

// OK = 0
#define OK 0
// FAIL = 1
#define FAIL 1

typedef struct m_budget
{
	// Using uint8_t to ensure less memory footprint
	// It gets limited to hold only 2 digit long number (Max 99) because the practise paper
	// values checking the project length, so anything over 99 is overkill because the comparison
	// is 6 < months > 48
	uint8_t months;

	// Using uint16_t to ensure less memory footprint
	// It gets limited to hold only 4 digit long number (Max 9999) which I think is reasonable
	// considering the project size.
	uint16_t nbworkers;

	// Using uint16_t to ensure less memory footprint
	// It gets limited to hold only 4 digit long number (Max 9999) which I think is reasonable
	// considering the project size.
	uint16_t bworkers;

	// Using uint32_t to ensure less memory footprint
	// It gets limited to hold only 6 digit long number (Max 999999) which I think is reasonable
	// considering the project size.
	uint32_t materials;

	// Using uint32_t to ensure less memory footprint
	// It gets limited to hold only 6 digit long number (Max 999999) which I think is reasonable
	// considering the project size.
	uint32_t travels;

	// Using uint32_t to ensure less memory footprint
	// It gets limited to hold only 6 digit long number (Max 999999) which I think is reasonable
	// considering the project size.
	uint32_t rentalandservices;

	// Using uint32_t to ensure less memory footprint
	// It gets limited to hold only 6 digit long number (Max 999999) which I think is reasonable
	// considering the project size.
	uint32_t fungiblematerials;
} budget;

// Allocate a new budget structure to keep things simpler instead of minting new variables everytime.
// I also opted for using structs because editing it is very straightforward and I can prompt the user
// to edit it at the end if he wants to.
budget newbudget;

/*
	main() function [NOTE: I personally use (u)int[8,16,32,64]_t types to ensure cross-platform compatibility]
*/
int32_t main()
{
	printf("Calculador de Pressupost\n");

	printf("Per començar, introdueixi la duració total del projecte (en mesos): ");

	/*
		I specify scanf the %hhu modifier

		%hhu ensures that scanf reads the integer the user inputs as an unsigned char 
	*/
	scanf("%hhu", &newbudget.months);

#ifdef DEBUG
	printf("newbudget.months: %u\n", (uint32_t)(newbudget.months));
#endif

	// Check against stdin var size overrun, as it will auto-fill the other next variables because scanf() will read stdin automatically
	// due to a larger input.
	// Only check if larger than 99, cheching if less than 0 (-1, -2...) is pointless because unsigned types only have positive values.
	// If it overflows, it'll go back counting from 0 or the inverse
	if (newbudget.months > 99)
	{
		printf("Els mesos totals han de ser inferior a 100, torni a executar el programa!\n");
		return FAIL;
	}

	// Compare wether newbudget.months is larger than 48 or smaller than 6, in that case, exit the program
	if (newbudget.months < 6 || newbudget.months > 48)
	{
		printf("Durada del projecte invàlida, torni a executar el programa!\n");
		return FAIL;
	}

	printf("Ara introdueixi el nombre de persones no becades (2500€ al mes) contractades: ");

	/*
		I specify scanf the %hu modifier

		%hu ensures that scanf reads the integer the user inputs as an unsigned short 
	*/
	scanf("%hu", &newbudget.nbworkers);

#ifdef DEBUG
	printf("newbudget.nbworkers: %u\n", (uint32_t)(newbudget.nbworkers));
#endif

	// Check against stdin var size overrun, as it will auto-fill the other next variables because scanf() will read stdin automatically
	// due to a larger input.
	// Only check if larger than 9999, cheching if less than 0 (-1, -2...) is pointless because unsigned types only have positive values.
	// If it overflows, it'll go back counting from 0 or the inverse
	if (newbudget.nbworkers > 9999)
	{
		printf("El nombre de treballadors no becats ha de ser inferior 10000, torni a executar el programa!\n");
		return FAIL;
	}

	printf("Ara introdueixi el nombre de persones becades (1200€ al mes) contractades: ");

	/*
		I specify scanf the %hu modifier

		%hu ensures that scanf reads the integer the user inputs as an unsigned short 
	*/
	scanf("%hu", &newbudget.bworkers);

#ifdef DEBUG
	printf("newbudget.bworkers: %u\n", (uint32_t)(newbudget.bworkers));
#endif

	// Check against stdin var size overrun, as it will auto-fill the other next variables because scanf() will read stdin automatically
	// due to a larger input.
	// Only check if larger than 9999, cheching if less than 0 (-1, -2...) is pointless because unsigned types only have positive values.
	// If it overflows, it'll go back counting from 0 or the inverse
	if (newbudget.bworkers > 9999)
	{
		printf("El nombre de treballadors becats ha de ser inferior 10000, torni a executar el programa!\n");
		return FAIL;
	}

	printf("Introdueixi la despesa total en material inventariable (€): ");

	/*
		I specify scanf the %u modifier

		%u ensures that scanf reads the integer the user inputs as an unsigned int 
	*/
	scanf("%u", &newbudget.materials);

#ifdef DEBUG
	printf("newbudget.materials: %u\n", newbudget.materials);
#endif

	// Check against stdin var size overrun, as it will auto-fill the other next variables because scanf() will read stdin automatically
	// due to a larger input.
	// Only check if larger than 999999, cheching if less than 0 (-1, -2...) is pointless because unsigned types only have positive values.
	// If it overflows, it'll go back counting from 0 or the inverse
	if (newbudget.materials > 999999)
	{
		printf("El pressupost de material ha de ser inferior a 1000000, torni a executar el programa!\n");
		return FAIL;
	}

	printf("Introdueixi la despesa total en viatges (€): ");

	/*
		I specify scanf the %u modifier

		%u ensures that scanf reads the integer the user inputs as an unsigned int 
	*/
	scanf("%u", &newbudget.travels);

#ifdef DEBUG
	printf("newbudget.travels: %u\n", newbudget.travels);
#endif

	// Check against stdin var size overrun, as it will auto-fill the other next variables because scanf() will read stdin automatically
	// due to a larger input.
	// Only check if larger than 999999, cheching if less than 0 (-1, -2...) is pointless because unsigned types only have positive values.
	// If it overflows, it'll go back counting from 0 or the inverse
	if (newbudget.travels > 999999)
	{
		printf("El pressupost per a viatges ha de ser inferior a 1000000, torni a executar el programa!\n");
		return FAIL;
	}

	printf("Introdueixi la despesa total en alquilers i serveis (€): ");

	/*
		I specify scanf the %u modifier

		%u ensures that scanf reads the integer the user inputs as an unsigned int 
	*/
	scanf("%u", &newbudget.rentalandservices);

#ifdef DEBUG
	printf("newbudget.rentalandservices: %u\n", newbudget.rentalandservices);
#endif

	// Check against stdin var size overrun, as it will auto-fill the other next variables because scanf() will read stdin automatically
	// due to a larger input.
	// Only check if larger than 999999, cheching if less than 0 (-1, -2...) is pointless because unsigned types only have positive values.
	// If it overflows, it'll go back counting from 0 or the inverse
	if (newbudget.rentalandservices > 999999)
	{
		printf("El pressupost per alquilers i serveis ha de ser inferior a 1000000, torni a executar el programa!\n");
		return FAIL;
	}

	printf("Introdueixi la despesa total en materials fungibles (€): ");

	/*
		I specify scanf the %u modifier

		%u ensures that scanf reads the integer the user inputs as an unsigned int 
	*/
	scanf("%u", &newbudget.fungiblematerials);

#ifdef DEBUG
	printf("newbudget.fungiblematerials: %u\n", newbudget.fungiblematerials);
#endif

	// Check against stdin var size overrun, as it will auto-fill the other next variables because scanf() will read stdin automatically
	// due to a larger input.
	// Only check if larger than 999999, cheching if less than 0 (-1, -2...) is pointless because unsigned types only have positive values.
	// If it overflows, it'll go back counting from 0 or the inverse
	if (newbudget.fungiblematerials > 999999)
	{
		printf("El pressupost per a viatges ha de ser inferior a 1000000, torni a executar el programa!\n");
		return FAIL;
	}

	uint32_t total = (((newbudget.nbworkers) * 2500) + ((newbudget.bworkers) * 1200) + (newbudget.materials)
		+ (newbudget.travels) + (newbudget.rentalandservices) + (newbudget.fungiblematerials));

	if (newbudget.months >= 6 && newbudget.months <= 12)
	{
		printf("S'aplica un overhead del 10%% al pressupost!\n");
		float pct10 = (float) total * 0.1;
		total = total + pct10;
	} else {
		printf("S'aplica un overhead del 20%% al pressupost!\n");
		float pct20 = (float) total * 0.2;
		total = total + pct20;
	}

	printf("El pressupost total per al projecte (Amb una durada de %u mesos) es: %f (€)\n", (uint32_t) newbudget.months, (float) total);

	return OK;
}