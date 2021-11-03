#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define M_MAX_TRIES 5

int main()
{
	// Define variables at the start of the program
	int m_edat, m_bid, m_tries;
	[[maybe_unused]] bool m_failedguess;
	[[maybe_unused]] bool m_guessedright;
	bool m_fi;

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
	m_fi = false;
	
	m_failedguess = false;
	m_guessedright = false;

	// Only enter the while loop if (And only if) both bools are false
	while (!m_fi)
	{
		// Print a brief program explanation and get user input
		printf("Quina edat creus que tinc? ");
		scanf("%d", &m_bid);

		// Check if the user guessed correctly the number
		if (m_bid == m_edat)
		{
			// Set the condition to true
			m_guessedright = true;
			m_fi = true;
		}

		// Check if we're exceeding the max number of tries
		if (m_tries == M_MAX_TRIES)
		{
			// Set the condition to true
			m_failedguess = true;
			m_fi = true;
		}

		// Check if user input is higher or lower than the one generated
		if (((m_bid > m_edat) || (m_bid < m_edat)) && m_fi != true)
		{
			// Tell the user's guess is far from the number
			printf("Fred fred!\n");
			// Check if guess is higher than generated number
			if (m_bid > m_edat)
			{
				// Tell the user to input a lower number
				printf("Prova un nombre més baix!\n");
			// Check if the guess is lower than generated number
			} else if (m_bid < m_edat) {
				// Tel the user to input a higher number
				printf("Prova un nombre més gran!\n");
			}
		}

		// Increment the current number of tries by 1
		m_tries++;
	}

	// Out of the while() loop

	// If the user guessed the bid correctly, prompt it to him
	if (m_bid == m_edat)
	{
		printf("Ha encertat la meva edat! Ha guanyat!\n");
	}

	// If the user has exceeded the max number of tries, prompt him
	if (m_tries > M_MAX_TRIES && m_bid != m_edat)
	{
		printf("Oh... No ha aconseguit esdevinar la meva edat... Ha perdut!\n");
	}

	return 0;

}