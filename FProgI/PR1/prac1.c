#include "prac1.h"

int main()
{
	char m_filename[20] = {0};
	int m_speed;
	int m_yodification;
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

	printf("A continuació, introdueixi la velocitat del mestre Yoda: ");

	scanf("%1d", &m_speed);

	if (m_speed != 0 && m_speed != 1 && m_speed != 2)
	{
		printf("Paràmetre de velocitat no acceptat (0-3)!\nSortint...\n");
		return 1;
	}

	printf("Ara, el coficient de yodificació: ");

	scanf("%1d", &m_yodification);

	if (m_yodification != 0 && m_yodification != 1 && m_yodification != 2)
	{
		printf("Paràmetre de velocitat no acceptat (0-3)!\nSortint...\n");
		return 1;
	}

	yodify(m_file, m_speed, m_yodification);

	fclose(m_file);

	return 0;
}

int yodify(FILE *m_file, char m_speed, char m_yodification)
{
	char m_sentence[(15 * 15) + 1];
	char m_lines;

	fscanf(m_file, "%[^\n]", m_sentence);
    printf("Primera frase:\n%s\n", m_sentence);

	return 0;
}
