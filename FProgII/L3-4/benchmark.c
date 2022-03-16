#include <bruteforce.h>
#include <optimal.h>
#include <table.h>

#include <benchmark.h>

void timed_benchmark()
{
	unsigned int m_table[P] = {0};
	time_t m_end = time(NULL);
	time_t m_start = time(NULL);

	for (int i = 0; i < N_VEGADES; i++)
	{
		srand(time(0));
		es_triangular_fb(rand() % ((UINT32_MAX + 1) - 1) + 1);
	}

	m_end = time(NULL);

	printf("El métode Força Bruta ha trigat %ld segons\n", (m_end - m_start));

	m_start = time(NULL);

	for (int i = 0; i < N_VEGADES; i++)
	{
		srand(time(0));
		es_triangular_op(rand() % ((UINT32_MAX + 1) - 1) + 1);
	}

	m_end = time(NULL);

	printf("El métode Óptim ha trigat %ld segons\n", (m_end - m_start));

	m_start = time(NULL);

	calcula_triangulars(m_table);

	for (int i = 0; i < N_VEGADES; i++)
	{
		srand(time(0));
		es_triangular_tau(m_table, rand() % ((UINT32_MAX + 1) - 1) + 1);
	}

	m_end = time(NULL);
	
	printf("El métode Taula ha trigat %ld segons\n", (m_end - m_start));
}
