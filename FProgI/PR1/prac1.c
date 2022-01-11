#include <stdio.h>
#include <stdlib.h>

int main()
{
	char m_filename[20] = {0};
	FILE *m_file = NULL;

	printf("Yodizer - Del català al dialecte yoda!\n");
	printf("Introdueixi el nom del fitxer a llegir: ");

	/*
		scanf: Read until newline found, this prevents
		scanf()'s quirky stdin buffer overruns'
	*/
	scanf("%19s", m_filename);

	m_file = fopen(m_filename, "r");

	if (!m_file)
	{
		printf("No s'ha pogut obrir l'arxiu!\nSortint...\n");
		exit(EXIT_FAILURE);
	}

	fclose(m_file);

}
