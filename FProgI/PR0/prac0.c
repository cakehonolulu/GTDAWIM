/*
	Compile using: gcc prac0.c -Wall -Wextra (Use -DDEBUG switch if you want to enable debugging if compiling w/o make,
	else specify DEBUG=1 alongside make (If building from the Github repo project locally)).

	GCC Version (LLVM's Clang untested):
	
	$ gcc --version
	gcc (Ubuntu 11.2.0-7ubuntu2) 11.2.0

	$ lsb_release -a
	No LSB modules are available.
	Distributor ID:	Ubuntu
	Description:	Ubuntu Jammy Jellyfish (development branch)
	Release:		22.04
	Codename:		jammy
	
	$ uname -a
	Linux CS3003NS 5.14.15-051415-generic #202110270548 SMP Wed Oct 27 11:48:56 UTC 2021 x86_64 x86_64 x86_64 GNU/Linux
*/

#include <stdio.h>

/*
	main() function
*/
int main()
{
	// Using unsigned char to ensure less memory footprint
	unsigned char months;

	// Using unsigned short to ensure less memory footprint
	unsigned short nbworkers;

	// Using unsigned short to ensure less memory footprint
	unsigned short bworkers;

	/*
		NOTE: Code::Blocks's compiler is not good-enough,
		so it's better to avoid	using scanf() modifiers whilst compiling there.
		If you're using a decent & up-to-date compiler there should be
		no problems, else, remove "h" scanf() modifiers.

		Also, accent marks get displayed inproperly there.
		I suspect it's due to an UTF-8 incompatibility issue that maybe
		a compiler flag fixes (But I can't assume there's a solution because
		the compiler version that ships with Code::Blocks is arcaic), on
		Linux, if using the compiler listed at the top of this source code, there's
		no need for specifying anything as it works OOTB (Out-of-the-box).
	*/
	float materials;

	float travels;

	float rentalandservices;

	float fungiblematerials;

	// Use a float to display up-to-cents accuracy on the price
	float total;

	printf("Calculador de Pressupost\n");

	printf("Per començar, introdueixi la duració total del projecte (en mesos): ");

	/*
		I specify scanf the %hhu modifier

		%hhu ensures that scanf reads the integer the user inputs as an unsigned char 
	*/
	scanf("%hhu", &months);

	// Compare wether months is larger than 48 or smaller than 6, in that case, exit the program
	if (months < 6 || months > 48)
	{
		printf("Durada del projecte invàlida, torni a executar el programa!\n");
	} else {
		printf("Ara introdueixi el nombre de persones no becades (2500€ al mes) contractades: ");

		/*
			I specify scanf the %hu modifier

			%hu ensures that scanf reads the integer the user inputs as an unsigned short 
		*/
		scanf("%hu", &nbworkers);

		printf("Ara introdueixi el nombre de persones becades (1200€ al mes) contractades: ");

		/*
			I specify scanf the %hu modifier

			%hu ensures that scanf reads the integer the user inputs as an unsigned short 
		*/
		scanf("%hu", &bworkers);

		printf("Introdueixi la despesa total en material inventariable (€): ");

		/*
			I specify scanf the %f modifier

			%f ensures that scanf reads the integer the user inputs as a floar
		*/
		scanf("%f", &materials);

		printf("Introdueixi la despesa total en viatges (€): ");

		/*
			I specify scanf the %f modifier

			%f ensures that scanf reads the integer the user inputs as a floar
		*/
		scanf("%f", &travels);

		printf("Introdueixi la despesa total en alquilers i serveis (€): ");

		/*
			I specify scanf the %f modifier

			%f ensures that scanf reads the integer the user inputs as a floar 
		*/
		scanf("%f", &rentalandservices);

		printf("Introdueixi la despesa total en materials fungibles (€): ");

		/*
			I specify scanf the % modifier

			%f ensures that scanf reads the integer the user inputs as a floar 
		*/
		scanf("%f", &fungiblematerials);

		total = ((((float) nbworkers) * 2500) + (((float) bworkers) * 1200) + (materials)
			+ (travels) + (rentalandservices) + (fungiblematerials));

		if (months >= 6 && months <= 12)
		{
			printf("S'aplica un overhead del 10%% al pressupost!\n");
			total += (total * 0.1);
		} else {
			printf("S'aplica un overhead del 20%% al pressupost!\n");
			total += (total * 0.2);
		}

		// Cast the unsigned char
		printf("El pressupost total per al projecte (Amb una durada de %u mesos) es: %0.2f (€)\n", (unsigned int) months, total);
	}

	return 0;
}