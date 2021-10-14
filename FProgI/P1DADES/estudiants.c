/*
	Compile using: gcc estudiants.c -Wall -Wextra

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

int32_t main()
{
	printf("En aquest programa calcularem el percentatge de nois i noies en una aula\n");

	printf("A continuació, introdueixi el nombre de nois: ");

	unsigned int  m_nois = 0;

	scanf("%u", &m_nois);

	printf("Ara, el nombre de noies: ");

	unsigned int m_noies = 0;

	scanf("%u", &m_noies);

	unsigned int m_total = 0;

	m_total = m_nois + m_noies;

	float m_percent_nois = (((float) m_nois * 100) / (float)m_total);

	float m_percent_noies = (((float)m_noies * 100) / (float)m_total);

	printf("Nombre total de nois: %u, (%f%%); Nombre total de noies: %u (%f%%); Total d'alumnes: %u\n", m_nois, m_percent_nois, m_noies, m_percent_noies, m_total);
}
