#include <bruteforce.h>
#include <stdio.h>
#include <stdbool.h>

int main()
{
	int m_number = 0;
	bool m_triangular = false;

	printf("Introdueixi un nombre: ");
	scanf("%d", &m_number);

#ifdef BRUTEFORCE
	m_triangular = bruteforce_triangular(m_number);
#endif

	if (m_triangular)
	{
		printf("El nombre %d es triangular!\n", m_number);
	}
	else
	{
		printf("El nombre %d no es triangular!\n", m_number);
	}

	return 0;
}
