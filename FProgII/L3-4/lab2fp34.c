/*
	Use ifdefs to reduce binary size (Only compiles one method,
	configurable via Make arguments, -D switches if compiling manually or define's)
*/
#ifdef BENCHMARK

#include <benchmark.h>

#else

#ifdef RETAIL
/*
I tend to use the latest standard available so the compiler warns be about
stdbool.h being deprecated (warning: "the <stdbool.h> header is deprecated in C2x" [-W#warnings])
but this is probably going to be compiled on an older (And non-clang) compiler so I'll leave it as-is.
*/
#include <stdbool.h>
#endif

#endif

#ifdef BRUTEFORCE
#include <bruteforce.h>
#endif

#ifdef OPTIMAL
#include <optimal.h>
#endif

#ifdef TABLE
#include <table.h>
#endif

#include <stdio.h>

int main()
{
#ifdef BENCHMARK
#ifdef EXTERNAL_TIME
#ifdef TABLE
	unsigned int m_table[P] = {0};
#endif
#endif
#else
#ifdef TABLE
	unsigned int m_table[P] = {0};
#endif

	bool m_cond = true;
	unsigned int m_number = 0;
	bool m_triangular = false;

	// Simple while, keep checking until good input found
	while (m_cond)
	{
		printf("Introdueixi un nombre positiu superior o igual a 0: ");
		scanf("%d", &m_number);
	
		if (m_number <= 0)
		{
			printf("El nombre ha de ser més gran o igual que 0\n");
		}
		else
		{
			m_cond = false;
		}
	}
#endif

	/*
		The main idea backing the use of if(n)defs is that I want the program
		to be benchmarkable and at the same time, be useful for end users who'd
		like to compile the program as-is with user input support and without
		the benchmarking complement.
	*/
#ifdef BENCHMARK
#ifndef EXTERNAL_TIME
	timed_benchmark();
#else

#ifdef BRUTEFORCE
	for (int i = 0; i < N_VEGADES; i++)
	{
		srand(time(0));
		es_triangular_fb(rand() % ((UINT32_MAX + 1) - 1) + 1);
	}
#endif

#ifdef OPTIMAL
	for (int i = 0; i < N_VEGADES; i++)
	{
		srand(time(0));
		es_triangular_op(rand() % ((UINT32_MAX + 1) - 1) + 1);
	}
#endif

#ifdef TABLE
	calcula_triangulars(m_table);

	for (int i = 0; i < N_VEGADES; i++)
	{
		srand(time(0));
		es_triangular_tau(m_table, rand() % ((UINT32_MAX + 1) - 1) + 1);
	}
#endif

#endif
#else
#ifdef BRUTEFORCE
	m_triangular = es_triangular_fb(m_number);
#endif

#ifdef OPTIMAL
	m_triangular = es_triangular_op(m_number);
#endif

#ifdef TABLE
	calcula_triangulars(m_table);
	m_triangular = es_triangular_tau(m_table, m_number);
#endif
#endif

#ifndef BENCHMARK
	// If not in benchmark number, tell the user if it's triangular or not
	if (m_triangular)
	{
		printf("El nombre %d es triangular!\n", m_number);
	}
	else
	{
		printf("El nombre %d no es triangular!\n", m_number);
	}
#endif

	return 0;
}
