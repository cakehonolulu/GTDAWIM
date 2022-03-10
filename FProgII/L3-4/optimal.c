#include <optimal.h>

bool optimal_triangular(unsigned int m_number)
{
	bool m_triangular = false;

	double n = (((sqrt((8 * m_number) + 1)) - 1) / 2);

	if (n == (unsigned int) n)
	{
		m_triangular = true;
	}

	return m_triangular;
}
