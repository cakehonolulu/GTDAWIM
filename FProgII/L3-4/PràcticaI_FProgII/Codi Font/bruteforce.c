#include <bruteforce.h>

unsigned int es_triangular_fb(unsigned int m_number)
{
	unsigned int i, m_summation = 0, m_triangular = 0;

	// Do this while the summatory is <= number provided
	for (i = 0; m_summation <= m_number; i++)
	{
		// m_triangular_num = m_prev_triang_summation + i
		m_summation = (m_summation + i);

		// Check if summation equals provided number
		if (m_summation == m_number)
		{
			// Set the return value accordingly
			m_triangular = m_summation;
		}
	}

	/*
		On benchmark, the next triangular number that is higher
		than provided number is a valid return
	*/
	if (m_summation > m_number)
	{
		m_triangular = m_summation;
	}

	/*
		This only adds an additional instruction (Moves the result to %rax)
		following x86_64 SysV ABI, at the end 1 instruction shouldn't be noticed at all
	*/
	return m_triangular;
}
