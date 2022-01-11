#include "prac1.h"

int main()
{
	char m_filename[20] = {0};
	int m_speed, m_yodification;
	FILE *m_file = NULL;

	printf("Yodizer - Del català al dialecte yoda!\n");
	//printf("Introdueixi el nom del fitxer a llegir: ");

	/*
		scanf: Read until newline found, this prevents
		scanf()'s quirky stdin buffer overruns'
	*/
	//scanf("%19s", m_filename);
	strcpy(m_filename, "yodatest.txt");

	m_file = fopen(m_filename, "r");

	if (!m_file)
	{
		//printf("No s'ha pogut obrir l'arxiu!\nSortint...\n");
		exit(EXIT_FAILURE);
	}

	//printf("A continuació, introdueixi la velocitat del mestre Yoda: ");

	//scanf("%1d", &m_speed);
	m_speed = 1;

	if (m_speed != 0 && m_speed != 1 && m_speed != 2)
	{
		//printf("Paràmetre de velocitat no acceptat (0-3)!\nSortint...\n");
		return 1;
	}

	//printf("Ara, el coficient de yodificació: ");

	//scanf("%1d", &m_yodification);
	m_yodification = 1;

	if (m_yodification != 0 && m_yodification != 1 && m_yodification != 2)
	{
		//printf("Paràmetre de velocitat no acceptat (0-3)!\nSortint...\n");
		return 1;
	}

	yodify(m_file, m_speed, m_yodification);

	fclose(m_file);

	return 0;
}

int yodify(FILE *m_file, int m_speed, int m_yodification)
{
	/*
		Total line count (Excluding empty newlines); how many characters
		a determined line has and the current character index for fgetc()
	*/
	int m_lines = 0, m_line_chars = 0;
	char m_char;

	// While loop that runs until fgetc() gets to End-Of-File (stdlib.h)
	while ((m_char = fgetc(m_file)) != EOF)
	{
		// Check if m_char index points to an ASCII newline '\n' char
	    if (m_char == '\n')
	    {
	    	// Set the line character count back to 0 as we just newlined
	        m_line_chars = 0;

	    	// Increment the line count
	        m_lines++;
	    }
	    else
	    {
	    	// If no newline is found, increment current line character count
	        m_line_chars++;
	    }
	}

	/*
		After processing the entire file, check if we have remaining characters
		on the line character count variable; that means that there's another
		sentence on the file that hasn't been counted due to it not having
		a line break at the end of it.
	*/
	if (m_line_chars > 0)
	{
		// Increment the line count by 1
	    m_lines++;
	}

	printf("Linees totals al arxiu: %d\n\n", m_lines);

	// Rewind up until the start of the file after dealing with fgetc()
	rewind(m_file);

	char m_sentences[m_lines][15 * 15];

	int i;
	for (i = 0; i < m_lines; i++)
	{
		fgets(m_sentences[i], (15 * 15), m_file);

		int m_length = strlen(m_sentences[i]);

		if (m_length > 0 && m_sentences[i][m_length - 1] == '\n')
		{
			m_sentences[i][--m_length] = '\0';
		}

		printf("%s\n", m_sentences[i]);
	}
	
	// Rewind up until the start of the file after dealing with fgetc()
	rewind(m_file);

	char m_sentence[15 * 15];

	char *m_index;

	for (i = 0; i < m_lines; i++)
	{
		printf("\n\x1B[34mFrase Número %d\x1B[0m\n", i + 1);

		m_index = strtok(m_sentences[i]," ,.-");

		while (m_index != NULL)
		{
			printf("%s\n", m_index);
			m_index = strtok(NULL," ,.-");
		}

	}

	return 0;
}
