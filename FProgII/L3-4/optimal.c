#include <optimal.h>

// Based-off the make flags, change the function's return type
#ifdef BENCHMARK
unsigned int es_triangular_op(unsigned int m_number)
#else
bool es_triangular_op(unsigned int m_number)
#endif
{
#ifndef BENCHMARK
	bool m_triangular = false;
#else
	unsigned int m_triangular = 0;
	float m_nearest;
#endif

	/*
		Use a float, less memory footprint than using a double
		
		Formula:
			[sqrt(8x+1)] - 1
		n = ----------------
				   2
	*/
	float m_result = (((sqrtf((8 * m_number) + 1)) - 1) / 2);

	/*
		This is an interesting trick:

		If the ceil'd version of n and the floor'd version of n are the same,
		it's safe to assume n is a natural number without fractional part.
	*/
	if (ceil(m_result) == floor(m_result))
	{
#ifdef BENCHMARK
		m_triangular = (unsigned int) m_result;
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
		*/
    	m_nearest = ceil(((sqrtf(1 + 8 * m_number)) - 1) / 2);
    	m_nearest = ((m_nearest * (m_nearest + 1)) / 2);
	}
#endif

	/*
		This only adds an additional instruction (Moves the result to %rax)
		following x86_64 SysV ABI, at the end 1 instruction shouldn't be noticed at all
	*/
	return m_triangular;
}
