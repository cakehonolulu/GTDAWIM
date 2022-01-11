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

	m_read_and_convert(m_file, m_speed, m_yodification);

	printf("De processar... ha acabat, el fitxer\n");
	fclose(m_file);

	return 0;
}

int m_read_and_convert(FILE *m_file, int m_speed, int m_yodification)
{
	/*
		Total line count (Excluding empty newlines); how many characters
		a determined line has and the current character index for fgetc()
	*/
	char m_char, *m_index;
	int i, j, k, m_len, m_letter_index = 0, m_word_index = 0, m_lines = 0, m_line_chars = 0;

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

	/*				    Letters
					    0 1 2 3 4 5 6 ...

			Words	0   M a y
					1   t h e
					2   f o r c e
					3   b e
					4   w i t h
					5   y o u
					...
	*/
	char m_matrix[m_lines][15][15];

	memset( m_matrix, '0', sizeof(m_matrix));


	for (i = 0; i < m_lines; i++)
	{
		printf("\n\x1B[34mFrase Número %d\x1B[0m\n", (i + 1));

		m_index = strtok(m_sentences[i], " .,");

		while (m_index != NULL)
		{
			m_len = strlen(m_index);

			// This writes **INTO** the matrix
			for (j = 0; j < m_len; j++)
			{
				m_matrix[i][m_word_index][m_letter_index] = m_index[j];
				m_letter_index++;
			}


			// This reads **OFF** the matrix
			for (j = 0; j < m_len; j++)
			{
#ifdef DEBUG
				printf("[%c] -> %d %d %d ", m_matrix[i][m_word_index][j], i, m_word_index, j);
#endif
				printf("%c", m_matrix[i][m_word_index][j]);
			}
			
			printf("\n");
			m_index = strtok(NULL, " .,");

			m_word_index++;
			m_letter_index = 0;
		}

		m_word_index = 0;
	
	}

	printf("\n");
	
	k = 0;

	// Now it gets interesting, apply speed and yodification coef.
	for (i = 0; i < m_lines; i++)
	{
		switch (m_yodification)
		{
			case 0:
				break;
			case 1:
				// Low yodification
				// Check each word
				for (j = 0; j < 15; j++)
				{

					if (m_matrix[i][j][0] == '0')
					{
						break;
					}

					k++;
				}
				printf("line %d has %d words\n", (i + 1), k);
				k = 0;
				break;
			case 2:
				// High yodification
				break;
			default:
				break;
		}
		
		//dibuixa_yoda();
	}

	return 0;
}

void dibuixa_yoda()
{
 char yoda[4][19] = {{92, 96, 45, 45, 46, 95, 39, 46, 58, 58, 46, 96, 46, 95, 46, 45, 45, 39, 47},
 {32, 92, 32, 32, 32, 96, 32, 95, 95, 58, 58, 95, 95, 32, 39, 32, 32, 32, 47},
{32, 32, 32, 45, 45, 58, 46, 96, 39, 46, 46, 96, 39, 46, 58, 45, 45, 32, 32},
{32, 32, 32, 32, 32, 32, 92, 32, 96, 45, 45, 39, 32, 47, 32, 32, 32, 32, 32}};
 int i, j;

 printf("\n\n\n");
 for (i = 0; i < 4; i++)
 {
 for (j = 0; j < 19; j++)
 {
 printf ("\x1B[32m%c\x1B[0m", yoda[i][j]);
 }
 printf("\n");
 }
}

//strncpy(string, array, 20);