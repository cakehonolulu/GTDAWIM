#include <optimal.h>

// Based-off the make flags, change the function's return type
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

	/*
		Use a float, less memory footprint than using a double
		
		Formula:
			[sqrt(8x+1)] - 1
		n = ----------------
				   2
	*/
	float n = (((sqrtf((8 * m_number) + 1)) - 1) / 2);

	/*
		This is an interesting trick:

		We can modulus by 1 to check if it'll return 0 (0._0_; 0 should
		be the remainder thus being 'integer'), it should be good enough
		for our pruposes.
	*/
	if (n % 1 = 0)
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

		// Round up the number (As we need to find the *next* triangular number closest to our num)
		m_next_num = ceil(n);

		// Calculate power of 2 (Multiply by itself 1 time)
		m_pow = (m_next_num * m_next_num);

		// Apply the formula described before
		m_triangular = (unsigned int) (((1 / 2) * m_pow) + ((1 / 2) * m_next_num));
	}
#endif

	/*
		This only adds an additional instruction (Moves the result to %rax)
		following x86_64 SysV ABI, at the end 1 instruction shouldn't be noticed at all
	*/
	return m_triangular;
}
