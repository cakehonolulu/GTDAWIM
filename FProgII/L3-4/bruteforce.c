#include <bruteforce.h>

bool es_triangular_fb(unsigned int m_number)
{
	bool m_triangular = false, m_cond = true;
	unsigned int i = 0, m_summation = 0;

	while (m_cond)
	{
		m_summation = (m_summation + (i++));

		if (m_number == m_summation)
		{
			m_triangular = true;
			m_cond = false;
		}
		else
		if (m_number < m_summation)
		{
			m_cond = false;
		}
	}

	return m_triangular;
}
