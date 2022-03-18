#include <optimal.h>

unsigned int es_triangular_op(unsigned int m_number)
{
	unsigned int m_triangular = 0;

	/*
		Use a float, less memory footprint than using a double
		
		Formula:
			[sqrt(8x+1)] - 1
		n = ----------------
				   2
	*/
	float m_nearest, m_result;

	m_result = (((sqrtf((8 * m_number) + 1)) - 1) / 2);

	/*
		This is an interesting trick:

		If the ceil'd version of n and the floor'd version of n are the same,
		it's safe to assume n is a natural number without fractional part.
	*/
	if (ceil(m_result) == floor(m_result))
	{
		m_triangular = (unsigned int) m_result;
	}
	else
	{
		/*
			Formula:
					  [sqrt(8x+1)] - 1
			ceil(n) = ----------------
				   			 2

						  (n * (n + 1))
			next_triang = -------------
							    2
		*/
		m_nearest = ceil(m_result);
    	m_nearest = ((m_nearest * (m_nearest + 1)) / 2);
	}

	/*
		This only adds an additional instruction (Moves the result to %rax)
		following x86_64 SysV ABI, at the end 1 instruction shouldn't be noticed at all
	*/
	return m_triangular;
}
