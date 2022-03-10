#include <table.h>
#include <stdio.h>

void calcula_triangulars(unsigned int m_table[])
{
	unsigned int m_summation = 0, i = 0;

	while (i < P)
	{
		m_summation = (m_summation + i);
		m_table[i] = m_summation;
		i++;
	}
}

bool es_triangular_tau(unsigned int m_table[], unsigned int m_number)
{
	bool m_triangular = false;

	int i = 0;

	while (m_table[i] <= m_number)
	{
		if (m_table[i] == m_number)
		{
			m_triangular = true;
		}

		i++;
	}

	return m_triangular;
}
