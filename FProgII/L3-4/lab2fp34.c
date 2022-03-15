/*
	Use ifdefs to reduce binary size (Only compiles one method,
	configurable via Make arguments or -D switches if compiling manually)
*/
#ifdef BRUTEFORCE
#include <bruteforce.h>
#endif

#ifdef OPTIMAL
#include <optimal.h>
#endif

#ifdef TABLE
#include <table.h>
#endif

#ifndef BENCHMARK
// Only needed for "Release"-type builds
#include <stdio.h>
/*
I tend to use the latest standard available so the compiler warns be about
stdbool.h being deprecated (warning: "the <stdbool.h> header is deprecated in C2x" [-W#warnings])
but this is probably going to be compiled on an older (And non-clang) compiler so I'll leave it as-is.
*/
#include <stdbool.h>
#else

// We will only need the next headers if compiling for benchmark
// rand() & derivates (srand...)
#include <stdlib.h>

// Needed for UINT32_MAX's val.
#include <stdint.h>

// For time(struct...)
#include <time.h>
#endif

// Configurable benchmark number, default to 10M (1M offers good insight too)
#define N_VEGADES 10000000

int main()
{
	unsigned int m_number = 0;

#ifndef BENCHMARK
	bool m_triangular = false;
	bool m_cond = true;
#endif

#ifdef TABLE
	// Table with positive integers for the table method
	unsigned int m_table[P] = {0};
#endif

#ifndef BENCHMARK
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
#ifdef BRUTEFORCE
#ifndef BENCHMARK
	m_triangular = es_triangular_fb(m_number);
#else
	// Do this for N_VEGADES
	for (int i = 0; i < N_VEGADES; i++)
	{
		// Each time we RNG a number, we *should* provide a fresh seed
		srand(time(0));

		// Generate a a number ranging from 0 to UINT32_MAX (0xFFFFFFFF)
		// Formula discussed in FProg 1
		// https://github.com/cakehonolulu/GTDAWIM/blob/main/FProgI/L5AGE/jocedat.c#L32
		m_number = rand() % ((UINT32_MAX + 1) - 1) + 1;

		/*
			Call the function, could assign the return value to a variable
			but it'd be pointless and cause a non-used-variable-related
			compiler warning.
		*/
		es_triangular_fb(m_number);
	}
#endif
#endif

#ifdef OPTIMAL
#ifndef BENCHMARK
	m_triangular = es_triangular_op(m_number);
#else
	// Pretty much the same as Bruteforce...
	for (int i = 0; i < N_VEGADES; i++)
	{
		srand(time(0));
		m_number = rand() % ((UINT32_MAX + 1) - 1) + 1;
		es_triangular_op(m_number);	
	}
#endif
#endif

#ifdef TABLE
#ifndef BENCHMARK
	calcula_triangulars(m_table);
	m_triangular = es_triangular_tau(m_table, m_number);
#else
	/*
		We only populate the table once, else it'd be expensive exec-time
	 	Function works with pointers to avoid passing by value (Pass by ref. instead)
	*/
	calcula_triangulars(m_table);

	for (int i = 0; i < N_VEGADES; i++)
	{
		srand(time(0));
		m_number = rand() % ((UINT32_MAX + 1) - 1) + 1;
		
		/*
			This hardcoded number comes from an utility I designed to check
			the 'nth triangular number (Provided by the user)

			File: m_triang.c

			Tested with P = 50000 "limitation"
		*/
		if (m_number <= 0x4A81DE28)
		{
			es_triangular_tau(m_table, m_number);	
		}
	}
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
