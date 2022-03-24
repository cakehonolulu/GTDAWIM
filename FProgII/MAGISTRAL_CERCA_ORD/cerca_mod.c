#include <stdbool.h>
#include <stdio.h>

// Retorna cert si algun dels nombres és igual a un valor
void hi_ha_valor(float *dades, int n_elems, int v)
{
	unsigned int i = 0;

	while (n_elems && dades[i] != v)
	{
		if (dades[i] == v)
		{
			printf("Trobat!\n");
		}
		else
		{
			i++;
		}
	}
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("S'ha d'especificar un argument amb el nombre!\n");
	}
	else
	{
		float m_table[5] = {1.3, 3, 5, 6, 5};
		hi_ha_valor(m_table, 5, atoi(argv[1]));
	}

	return 0;
}
