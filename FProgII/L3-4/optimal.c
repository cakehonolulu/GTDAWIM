#include <optimal.h>

#ifdef BENCHMARK
unsigned int es_triangular_op(unsigned int m_number)
#else
bool es_triangular_op(unsigned int m_number)
#endif
{
#ifdef BENCHMARK
	unsigned int m_next_num, m_pow, m_triangular;
#else
	bool m_triangular = false;
#endif

	float n = (((sqrtf((8 * m_number) + 1)) - 1) / 2);

	if (n == (unsigned int) n)
	{
#ifdef BENCHMARK
		m_triangular = (unsigned int) n;
#else
		m_triangular = true;
#endif
	}
#ifdef BENCHMARK
	else
	{
		/*
			If it's not a triangular number, find the next one.
			Reconstruct the original formula to get the original number.

				1	   1
			x = - n² + - n
				2	   2
		*/
		m_next_num = ceil(n);
		m_pow = (m_next_num * m_next_num);
		m_triangular = (unsigned int) (((1 / 2) * m_pow) + ((1 / 2) * m_next_num));
	}
#endif

	return m_triangular;
}
