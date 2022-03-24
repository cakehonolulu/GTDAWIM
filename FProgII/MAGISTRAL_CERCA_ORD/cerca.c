#include <stdbool.h>
#include <stdio.h>

// Retorna cert si algun dels nombres és igual a un valor
bool hi_ha_valor(float dades[], int n_elems, int v)
{
	bool m_cond = false;

	unsigned int i;

	while (i < n_elems && !m_cond)
	{
		if (dades[i] == v)
		{
			m_cond = true;
		}
		else
		{
			i++;
		}
	}

	return m_cond;
}

int main(int argc, char **argv)
{
	float m_table[5] = {1.3, 3, 5, 6, 5};

	bool m_found = hi_ha_valor(m_table, sizeof(m_table), 6);
	if (m_found)
		printf("Valor trobat!\n");
	else
		printf("Valor no trobat!\n");

	return 0;
}
