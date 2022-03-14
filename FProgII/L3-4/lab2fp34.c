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
#include <stdlib.h>
#include <time.h>

#define N_VEGADES 10000000
#define M_MAX_NUM 50000

int main()
{
	unsigned int m_number = 0;

#ifndef BENCHMARK
	bool m_triangular = false;
	bool m_cond = true;
#endif

#ifdef TABLE
	unsigned int m_table[P] = {0};
#endif

#ifdef BENCHMARK
	srand(time(0));
	m_number = rand() % ((M_MAX_NUM + 1) - 1) + 1;
#else
	while (m_cond)
	{
		printf("Introdueixi un nombre [0, 50000]: ");
		scanf("%d", &m_number);
	
		if (m_number < 0)
		{
			printf("El nombre ha de ser més gran que 0\n");
		}
		else
		if (m_number > 50000)
		{
			printf("El nombre ha de ser més petit que 50000 (Inclós)!\n");
		}
		else
		{
			m_cond = false;
		}
	}
#endif

#ifdef BENCHMARK
	if (m_number > 0 && m_number < 50000)
	{
#endif
#ifdef BRUTEFORCE
#ifndef BENCHMARK
		m_triangular = es_triangular_fb(m_number);
#else
		for (int i = 0; i < N_VEGADES; i++)
		{
			srand(time(0));
			m_number = rand() % ((M_MAX_NUM + 1) - 1) + 1;
			es_triangular_fb(m_number);
		}
#endif
#endif

#ifdef OPTIMAL
#ifndef BENCHMARK
		m_triangular = es_triangular_op(m_number);
#else
		for (int i = 0; i < N_VEGADES; i++)
		{
			srand(time(0));
			m_number = rand() % ((M_MAX_NUM + 1) - 1) + 1;
			es_triangular_op(m_number);	
		}
#endif
#endif

#ifdef TABLE
#ifndef BENCHMARK
		calcula_triangulars(m_table);
		m_triangular = es_triangular_tau(m_table, m_number);
#else
		calcula_triangulars(m_table);

		for (int i = 0; i < N_VEGADES; i++)
		{
			srand(time(0));
			m_number = rand() % ((M_MAX_NUM + 1) - 1) + 1;
			
			if (m_number <= 0x4A81DE28)
			{
				es_triangular_tau(m_table, m_number);	
			}
		}
#endif
#endif

#ifdef BENCHMARK
	}
#endif

#ifndef BENCHMARK
	if (m_triangular)
	{
		printf("El nombre %d es triangular!\n", m_number);
	}
	else
	{
		printf("El nombre %d no es triangular!\n", m_number);
	}
#endif

	return 0;
}
