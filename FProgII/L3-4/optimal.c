#include <optimal.h>

bool es_triangular_op(unsigned int m_number)
{
	bool m_triangular = false;

	float n = (((sqrtf((8 * m_number) + 1)) - 1) / 2);

	if (n == (unsigned int) n)
	{
		m_triangular = true;
	}

	return m_triangular;
}
