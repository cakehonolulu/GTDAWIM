/*
	Compile using: gcc turismerural.c -Wall -Wextra
	GCC Version (LLVM's Clang untested):
	$ gcc --version
	gcc (Ubuntu 11.2.0-7ubuntu2) 11.2.0
	Ubuntu Version:
	$ lsb_release -a

	Linux Kernel Version:
	Linux CS3003NS 5.14.6-051406-generic #202109181232 SMP Sat Sep 18 12:35:35 UTC 2021 x86_64 x86_64 x86_64 GNU/Linux
*/

#include <stdint.h>
#include <stdio.h>

int main()
{
	unsigned int m_persones = 0;

	printf("Càlcul de pressupost - Casa Rural Can Marball\n");
	printf("A continuació introdueixi un nombre de persones a allotjar (Màxim 12): ");

	scanf("%u", &m_persones);

	if (m_persones <= 12)
	{
		if (m_persones >= 1)
		{
			printf("Ara introdueixi el nombre de nits a allotjar-se: ");

			unsigned int m_nits = 0;

			scanf("%u", &m_nits);

			if (m_nits > 0)
			{
				printf("Calculant pressupost per a %u persones amb una estància de %u nits...\n", m_persones, m_nits);	
			} else {
				printf("El nombre de nits es incorrecte!\n");
				return 1;
			}		
		} else {
			printf("Ha introduit %u persones, el mínim es 1 i el máxim 12!\n", m_persones);
			return 1;
		}
		
	} else {
		printf("Ha introduit %u persones, el mínim es 1 i el máxim 12!\n", m_persones);
		return 1;
	}
}
