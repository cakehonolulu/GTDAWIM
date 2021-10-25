/*
	Compile using: gcc estudiants.c -Wall -Wextra
	GCC Version (LLVM's Clang untested):
	$ gcc --version
	gcc (Ubuntu 11.2.0-7ubuntu2) 11.2.0
	Ubuntu Version:
	$ lsb_release -a

	Linux Kernel Version:
	Linux CS3003NS 5.14.6-051406-generic #202109181232 SMP Sat Sep 18 12:35:35 UTC 2021 x86_64 x86_64 x86_64 GNU/Linux
*/

#include <stdio.h>

// [A-Z] = [65-90]
// [a-z] = [97-122]
// [0-9] = [48-57]

// 32

int main()
{
	printf("Programa per convertir entre majúscules i minúscules\n");
	printf("A continuació introdueixi la lletra que vulgui (Autodetecta majúscules): ");

	char m_letter;

	scanf("%c", &m_letter);

	printf("L'usuari ha escrit %c\n", m_letter);

	if (m_letter <= 90)
	{
		if (m_letter >= 65)
		{
			printf("Lletra majúscula detectada: %c ", m_letter);
			m_letter += 32;
			printf("convertida a: %c\n", m_letter);
		}
	} else if (m_letter <= 122)
	{
		if (m_letter >= 97)
		{
			printf("Lletra minúscula detectada: %c ", m_letter);
			m_letter -= 32;
			printf("convertida a: %c\n", m_letter);
		}
	}

}

