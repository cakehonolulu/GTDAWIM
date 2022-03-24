#include <stdbool.h>
#include <stdio.h>

// Retorna cert si algun dels nombres és igual a un valor
int hi_ha_valor(float dades[], int n_elems, int v)
{
	bool m_cond = false;

	unsigned int i = 0, m_pos = -1;

	while (i < n_elems && !m_cond)
	{
		if (dades[i] == v)
		{
			m_cond = true;
			m_pos = i;
		}
		else
		{
			i++;
		}
	}

	return m_pos;
}

int main(int argc, char **argv)
{
	float m_table[5] = {1.3, 3, 5, 6, 5};

	int m_pos = hi_ha_valor(m_table, 5, atoi(argv[1]));

	if (m_pos != -1)
	{
		printf("Valor trobat a la posició %d!\n", m_pos);
	}
	else
	{
		printf("Valor no trobat!\n");
	}

	return 0;
}
