#include <calculs.h>
#include <stdio.h>
#include <stdbool.h>

int main()
{
	int m_vec[50] = {0};
	int m_num = 0;
	bool m_cond = true;

	printf("Quants enters vol introduir (Mínim 1, Máxim 50)? ");

	while (m_cond)
	{
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

	return 0;
}
