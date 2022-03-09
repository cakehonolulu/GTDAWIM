#include <calculs.h>

float mitjana(int taula[], int nv)
{
	int i;
	float m_result = 0;
	
	for (i = 0; i < nv; i++)
	{
		m_result += taula[i];
	}

	return (m_result / nv); 
}
