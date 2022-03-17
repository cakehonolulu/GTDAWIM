#include <stdio.h>
#include <stdint.h>

int main()
{
	unsigned int m_num = 0, m_triang = 0, i;

	printf("Escriu la posició del triangular a obtenir: ");
	scanf("%d", &m_num);

	for (i = 0; i <= m_num; i++)
	{
		m_triang = (m_triang + i);
	}

	printf("El triangular a la posició %d és: %d\n", m_num, m_triang);

	if (m_triang <= UINT32_MAX)
	{
		printf("Vàlid, més petit que 0x%06X (UINT32_MAX)\nValor constant per al programa: 0x%06X\n", UINT32_MAX, m_triang);
	}
	else
	{
		printf("No vàlid! Provi un nombre més petit...\n");
	}

	return 0;
}
