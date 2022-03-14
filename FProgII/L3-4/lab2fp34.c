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

#define N_VEGADES 10000

int main()
{
	unsigned int m_number = 0;

#ifndef BENCHMARK
	bool m_triangular = false;
#endif

#ifdef TABLE
	unsigned int m_table[P] = {0};
#endif

#ifdef BENCHMARK
	srand(time(0));
	m_number = rand() % ((N_VEGADES + 1) - 1) + 1;
#else
	printf("Introdueixi un nombre: ");
	scanf("%d", &m_number);
#endif

	if (m_number != 0)
	{
#ifdef BRUTEFORCE
#ifndef BENCHMARK
		m_triangular = es_triangular_fb(m_number);
#else
		for (int i = 0; i < N_VEGADES; i++)
		{
			srand(time(0));
			m_number = rand() % ((N_VEGADES + 1) - 1) + 1;
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
			m_number = rand() % ((N_VEGADES + 1) - 1) + 1;
			es_triangular_op(m_number);	
		}
#endif
#endif

#ifdef TABLE
#ifndef BENCHMARK
		calcula_triangulars(m_table);
		m_triangular = es_triangular_tau(m_table, m_number);
#else
		for (int i = 0; i < N_VEGADES; i++)
		{
			srand(time(0));
			m_number = rand() % ((N_VEGADES + 1) - 1) + 1;
			calcula_triangulars(m_table);
			es_triangular_tau(m_table, m_number);		
		}
#endif
#endif
	}

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
