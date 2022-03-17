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

unsigned int es_triangular_tau(unsigned int *m_table, unsigned int m_number)
{
	unsigned int m_triangular = 0;

	unsigned int i;

	// 0x4A81DE28 in decimal is the P'th triangular number value
	if (m_number <= 0x4A81DE28)
	{
		// Do while condition lasts
		for (i = 0; m_table[i] <= m_number; i++)
		{
			// Compare each table's index value against the provide number
			if (m_table[i] == m_number)
			{
				// Return the value
				m_triangular = m_table[i];
			}
		}

		// If bigger, assign it
		if (m_table[i] > m_number)
		{
			// Only on benchmark mode, assign the value (first_triang >= n)
			m_triangular = m_table[i];
		}
	}

	/*
		This only adds an additional instruction (Moves the result to %rax)
		following x86_64 SysV ABI, at the end 1 instruction shouldn't be noticed at all
	*/
	return m_triangular;
}
