/*
	Compile using: gcc turismerural.c -Wall -Wextra (Use -DREPTE=1 if you want to use the extended version that checks if m_nits > 12)
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
	Linux CS3003NS 5.14.6-051406-generic #202109181232 SMP Sat Sep 18 12:35:35 UTC 2021 x86_64 x86_64 x86_64 GNU/Linux
*/

#include <stdint.h>
#include <stdio.h>

#define OK 0
#define FAIL 1

#define PREU_NITS 150

int main()
{
	unsigned int m_persones;
	unsigned int m_nits;

	printf("Càlcul de pressupost - Casa Rural Can Marball\n");
	printf("A continuació introdueixi un nombre de persones a allotjar (Màxim 12): ");

	scanf("%u", &m_persones);

	// First check if we're not exceeding the place's maximum capacity
	if (m_persones <= 12)
	{
		printf("Ara introdueixi el nombre de nits a allotjar-se: ");

		scanf("%u", &m_nits);

		// REPTE Part
		// If there's more than 12 nights, don't proceed
		if (m_nits > 12)
		{
			printf("El nombre de nits excedeix les 12 máximes permeses!\n");
		} else {
			printf("Calculant pressupost per a %u persones amb una estància de %u nits...\n", m_persones, m_nits);
			printf("Preu sense IVA: %u €, IVA (21%%): %.2f €, Preu Total (IVA Inclòs): %.2f €\n", (m_nits * PREU_NITS), ((float)(m_nits * PREU_NITS) * 0.21), (((float)(m_nits * PREU_NITS) * 0.21) + (m_nits * PREU_NITS)));	
		}
		
	} else {
		printf("Ha introduit %u persones, el máxim són 12!\n", m_persones);
	}
	

	return OK;
}
