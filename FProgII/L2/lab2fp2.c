#include <calculs.h>
#include <dades.h>
#include <stdio.h>
#include <stdbool.h>

int main()
{
	int m_vec[50] = {0};
	int m_num = 0, m_max = 0, m_min = 0;
	bool m_cond = true;

	while (m_cond)
	{
		printf("Quants enters vol introduir (Mínim 1, Máxim 50)? ");
		scanf("%d", &m_num);

		if (m_num < 1)
		{
			printf("El nombre %d es massa petit!\n", m_num);
		}
		else
		if (m_num > 50)
		{
			printf("El nombre %d es massa gran!\n", m_num);
		}
		else
		{
			m_cond = false;
		}
	}

	obtenir_dades(m_vec, m_num, 10, 90);

	mostrar_dades(m_vec, m_num);

	printf("La mitjana dels nombres del vector es: %0.2f\n", mitjana(m_vec, m_num));

	maxmin(m_vec, m_num, &m_max, &m_min);

	printf("El nombre més alt es: %d; el més baix: %d\n", m_max, m_min);

	return 0;
}
