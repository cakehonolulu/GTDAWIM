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

void maxmin(int taula[], int nv, int *max, int *min)
{
	int i = 0;

	*min = taula[i];
	*max = taula[i];

	while (i < nv)
	{
		if (taula[i] > *min && taula[i] > *max)
		{
			*max = taula[i];
		}
		else
		if (taula[i] < *min)
		{
			*min = taula[i];
		}
		
		i++;
	}
}
