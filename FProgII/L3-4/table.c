#include <table.h>
#include <stdio.h>

bool table_triangular(unsigned int m_number)
{
	bool m_triangular = false;

	unsigned int m_table[P] = {0}, m_summation = 0, i = 0;

	while (i < P)
	{
		m_summation = (m_summation + i);
		m_table[i] = m_summation;
		i++;
	}

	i = 0;

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
