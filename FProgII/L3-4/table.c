#include <table.h>

void calcula_triangulars(unsigned int *m_table)
{
	/*
		This function works the same as bruteforce, but whatever it computes
		goes into an integer array[P]
	*/
	unsigned int m_summation = 0, i;

	for (i = 0; i < P; i++)
	{
		m_summation = (m_summation + i);
		m_table[i] = m_summation;
	}
}

#ifdef BENCHMARK
unsigned int es_triangular_tau(unsigned int *m_table, unsigned int m_number)
#else
bool es_triangular_tau(unsigned int *m_table, unsigned int m_number)
#endif
{
#ifdef BENCHMARK
	unsigned int m_triangular = 0;
#else
	bool m_triangular = false;
#endif
	bool m_cond = true;
	int i = 0;

	// Do while condition lasts
	while (m_cond)
	{
		// Compare each table's index value against the provide number
		if (m_table[i] == m_number)
		{
#ifdef BENCHMARK
			// Return the value
			m_triangular = m_table[i];
#else
			m_triangular = true;
#endif
			m_cond = false;
		}
		else
		// If bigger, stop
		if (m_table[i] > m_number)
		{
#ifdef BENCHMARK
			// But if on benchmark mode, assign the value (first_triang >= n)
			m_triangular = m_table[i];
#endif
			m_cond = false;
		}

		i++;
	}
	
	/*
		This only adds an additional instruction (Moves the result to %rax)
		following x86_64 SysV ABI, at the end 1 instruction shouldn't be noticed at all
	*/
	return m_triangular;
}
