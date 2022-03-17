#include <optimal.h>

unsigned int es_triangular_op(unsigned int m_number)
{
	unsigned int m_triangular = 0;
	unsigned int i;

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

		If the ceil'd version of n and the floor'd version of n are the same,
		it's safe to assume n is a natural number without fractional part.
	*/
	if (ceil(n) == floor(n))
	{
		m_triangular = (unsigned int) n;
	}
	else
	{
		/*
			If it's not a triangular number, find the next one.
			Reconstruct the original formula to get the original number.
			Keep feeding values until the next closer triangular is found (Not the previous!)
		*/
		for (i = 0; n <= m_number; i++)
		{
			n = (((floor(sqrtf(2 * (m_number + i))))) * (((floor(sqrtf(2 * (m_number + i))))) + 1) / 2);

			if (ceil(n) == floor(n) && (n >= m_number))
			{
				m_triangular = (unsigned int) n;
			}
		}
	}

	/*
		This only adds an additional instruction (Moves the result to %rax)
		following x86_64 SysV ABI, at the end 1 instruction shouldn't be noticed at all
	*/
	return m_triangular;
}
