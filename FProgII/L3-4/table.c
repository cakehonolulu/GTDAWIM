#include <table.h>
#include <stdio.h>

void calcula_triangulars(unsigned int *m_table)
{
	unsigned int m_summation = 0, i;

	for (i = 0; i < P; i++)
	{
		m_summation = (m_summation + i);
		m_table[i] = m_summation;
	}
}

#ifdef BENCHMARK
unsigned int es_triangular_tau(unsigned int *m_table, unsigned int m_number)
#else
bool es_triangular_tau(unsigned int *m_table, unsigned int m_number)
#endif
{
#ifdef BENCHMARK
	unsigned int m_triangular = 0;
#else
	bool m_triangular = false;
#endif
	bool m_cond = true;
	int i = 0;

	while (m_cond)
	{
		if (m_table[i] == m_number)
		{
#ifdef BENCHMARK
			m_triangular = m_table[i];
#else
			m_triangular = true;
#endif
			m_cond = false;
		}
		else
		if (m_table[i] > m_number)
		{
#ifdef BENCHMARK
			m_triangular = m_table[i];
#endif
			m_cond = false;
		}

		i++;
	}

	return m_triangular;
}
