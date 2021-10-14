/*
	Compile using: gcc numtodig.c -Wall -Wextra
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
#include <stdint.h>

void digitalize(unsigned int m_number)
{
	if (m_number == 0)
	{	//  Procedure ended
		return;
	}

	unsigned int m_residue;

	/*
		Modulo
		We divide by 10 to get the residue of the operation
		until we get residue 0, which finishes the while loop
	*/

	m_residue = m_number % 10;

	/*
		In a recursively manner, call the function again until m_residue
		holds the entire inputted number and the input has become 0
	*/

	digitalize(m_number / 10);

	printf("%d ", m_residue);
}

int32_t main()
{
	printf("Aquest programa separa els dígits de la cadena de nombres que introdueixi l'usuari\n");
	printf("A continuació introdueixi el número: ");

	unsigned int m_nombre = 0;

	scanf("%10u", &m_nombre);

	digitalize(m_nombre);

	printf("\n");

	return 0;
}
