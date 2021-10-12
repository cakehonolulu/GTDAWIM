/*
	Compile using: gcc pladedades.c -Wall -Wextra

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

// kB = 1000b
// 1MB = 1024kB

// 1 MB 1024kB
// x MB m_data

#define M_WORK_DAYS 5
#define MEGABYTE 1
#define MBtokB 1024

char *m_labour_days[] = {
	"Dilluns",
	"Dimarts",
	"Dimecres",
	"Dijous",
	"Divendres"
};

float m_data = 0;

int32_t main()
{
	printf("En aquest programa calcularem la mitjana de dades utilitzades al llarg de la setmana\n");

	printf("A continuació, anirem introduint dia a dia el consum de dades en kiloBits\n");

	float m_buffer = 0;

	for (size_t i = 0; i < M_WORK_DAYS; i++)
	{
		printf("%s (kB utilitzats): ", m_labour_days[i]);
		scanf("%f", &m_buffer);
		m_data += m_buffer;
		m_buffer = 0;
	}

	printf("Total de dades utilitzades: %f (kB), Mitjana setmanal: %f (MB)\n", m_data, (((m_data / M_WORK_DAYS) * MEGABYTE) / MBtokB));
}