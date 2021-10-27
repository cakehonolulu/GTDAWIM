#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define M_MAX_TRIES 5

int main()
{
	// Define variables at the start of the program
	int m_edat, m_bid, m_tries;
	bool m_end;

	/*
		Use: "man srand" to gather more info on srand() usage
		srand() requires a seed to start it's RNG function.
		We'll nested-call time() with a NULL argument
		(Normally expects a time_t structure)
		to get the seed from there which will work good enough
	*/
	srand(time(NULL));

	/*
		More info: http://pi.math.cornell.edu/~morris/135/mod.pdf
		Using modulo 41 (m_maxrangen + 1 ) - 10) we ensure the number
		ends up being 40 at max. If we want to cover up to 50, add 10;
		that way if modulo of rand() yields 0 due to a non-residue division,
		we'll get the minimum number (Which is 10)
	*/
	m_edat = (rand() % 41) + 10;

	// Initialize all variables before entering the while() loop
	m_tries = 1;
	m_end = false;

	while (!m_end)
	{
		printf("Quina edat creus que tinc? ");
		scanf("%d", &m_bid);

		if ((m_bid > m_edat) || (m_bid < m_edat))
		{
			printf("Fred fred!\n");
			if (m_bid > m_edat)
			{
				printf("Prova un nombre més baix!\n");
			} else if (m_bid < m_edat) {
				printf("Prova un nombre més gran!\n");
			}
		}

		if (m_bid == m_edat)
		{
			printf("Ha encertat la meva edat! Ha guanyat!\n");
			m_end = true;
		}

		if (m_tries == M_MAX_TRIES)
		{
			printf("Oh... No ha aconseguit esdevinar la meva edat... Ha perdut!\n");
			m_end = true;
		}

		m_tries++;
	}

	return 0;

}