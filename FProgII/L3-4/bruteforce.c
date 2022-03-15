#include <bruteforce.h>

// Based-off the make flags, change the function's return type
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

	// Do this while m_cond = 1 (true)
	while (m_cond)
	{
		// m_triangular_num = m_prev_triang_summation + current_index++
		m_summation = (m_summation + (i++));

		// Check if summation equals provided number
		if (m_summation == m_number)
		{

#ifdef BENCHMARK
			// Set the return value accordingly
			m_triangular = m_summation;
#else
			m_triangular = true;
#endif

			m_cond = false;
		}
		else
		/*
			On benchmark, the next triangular number that is higher
			than provided number is a valid return
		*/
		if (m_summation > m_number)
		{
#ifdef BENCHMARK
			m_triangular = m_summation;
#endif
			m_cond = false;
		}
	}

	/*
		This only adds an additional instruction (Moves the result to %rax)
		following x86_64 SysV ABI, at the end 1 instruction shouldn't be noticed at all
	*/
	return m_triangular;
}
