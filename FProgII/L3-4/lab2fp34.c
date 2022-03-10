#ifdef BRUTEFORCE
#include <bruteforce.h>
#endif

#ifdef OPTIMAL
#include <optimal.h>
#endif

#ifdef TABLE
#include <table.h>
#endif

#include <stdio.h>
#include <stdbool.h>

int main()
{
	int m_number = 0;
	bool m_triangular = false;

#ifdef TABLE
	unsigned int m_table[P] = {0};
#endif

	printf("Introdueixi un nombre: ");
	scanf("%d", &m_number);

	if (m_number != 0)
	{
#ifdef BRUTEFORCE
		m_triangular = es_triangular_fb(m_number);
#endif

#ifdef OPTIMAL
		m_triangular = es_triangular_op(m_number);
#endif

#ifdef TABLE
		calcula_triangulars(m_table);
		m_triangular = es_triangular_tau(m_table, m_number);
#endif
	}

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
