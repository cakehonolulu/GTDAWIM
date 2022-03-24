#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Retorna cert si algun dels nombres és igual a un valor
int hi_ha_valor(float *dades, int n_elems, int v, int *m_tab)
{
	unsigned int i = 0, m_pos = -1, j = 0;

	while (i < n_elems)
	{
		if (dades[i] == v)
		{
			m_pos = i;
			m_tab[j] = i;
			i++;
			j++;
		}
		else
		{
			i++;
		}
	}

	return j;
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("S'ha d'especificar el nombre a cercar!\n");
	}
	else
	{
		float m_table[] = {2, 1, 2, 3, 2};

		int m_tab[5] = {-1, -1, -1, -1, -1};

		int m_check = hi_ha_valor(m_table, 5, atoi(argv[1]), m_tab);

		if (m_check != 0)
		{
			printf("Trobats a la posició: ");

			for (int i = 0; i < 5; i++)
			{
				if (m_tab[i] != -1)
					printf("%d ", (m_tab[i] + 1));
			}

			printf("\n");
		}
		else
		{
			printf("No s'ha trobat!\n");
		}
	}
	
	return 0;
}
