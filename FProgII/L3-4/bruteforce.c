#include <bruteforce.h>

#ifdef BENCHMARK
unsigned int es_triangular_fb(unsigned int m_number)
#else
bool es_triangular_fb(unsigned int m_number)
#endif
{
#ifdef BENCHMARK
	unsigned int m_triangular = 0;
#else
	bool m_triangular = false;
#endif

	bool m_cond = true;
	unsigned int i = 0, m_summation = 0;

	while (m_cond)
	{
		m_summation = (m_summation + (i++));

		if (m_summation == m_number)
		{

#ifdef BENCHMARK
			m_triangular = m_summation;
#else
			m_triangular = true;
#endif

			m_cond = false;
		}
		else
#ifdef BENCHMARK
		if (m_summation > m_number)
		{
			m_triangular = m_summation;
			m_cond = false;
		}
#else
		if (m_summation > m_number)
		{
			m_cond = false;
		}
#endif
	}

	return m_triangular;
}
