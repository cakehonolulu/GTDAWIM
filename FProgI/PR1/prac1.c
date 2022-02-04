#include "prac1.h"

// main() function
int main()
{
	// Filename array that can read file names up to 20 characters
	char m_filename[21] = {0}, m_sentences[MAX_LINES][15 * 15], *m_word_matrix[MAX_LINES][15][15], m_sentence_words[MAX_LINES];;

	// Speed of text and yodification modifier
	int m_speed, m_yodification, m_length;

	// FILE object type variable that will hold the text file handle 
	FILE *m_file = NULL;

	printf("Yodizer - Del català al dialecte yoda!\n");

#ifdef DEBUG
	strcpy(m_filename, "yodatest.txt");
#endif

#ifndef DEBUG
	printf("Introdueixi el nom del fitxer a llegir: ");

	/*
		Read the filename from stdin buffer
		Use the %19 modifier to allow only up to 19 characters
	*/
	scanf("%20s", m_filename);
#endif

	// Use fopen() with the scanf()-modified filename and the "read" modifier
	m_file = fopen(m_filename, "r");

	// Check if file was succesfully opened
	if (!m_file)
	{
		printf("No s'ha pogut obrir l'arxiu!\nSortint...\n");
		/*
			Else, completely exit the program.
			This is done to avoid possible segmentation faults
			if we're handling with it due to it being a pointer.
		*/
		return 1;
	}

#ifdef DEBUG
	m_speed = 1;
#endif

#ifndef DEBUG
	printf("A continuació, introdueixi la velocitat del mestre Yoda: ");

	/*
		Read the speed from stdin buffer
		Use the %1 modifier to allow only one character to be read (0,1,2)
	*/
	scanf("%1d", &m_speed);

	// Check if m_speed falls within the [0,2] range
	if (m_speed != 0 && m_speed != 1 && m_speed != 2)
	{
		printf("Paràmetre de velocitat no acceptat (0-3)!\nSortint...\n");
		return 1;
	}
#endif

#ifdef DEBUG
	m_yodification = 1;
#endif

#ifndef DEBUG
	printf("Ara, el coficient de yodificació: ");

	/*
		Read the yodification modifier from stdin buffer
		Use the %1 modifier to allow only one character to be read (0,1,2)
	*/
	scanf("%1d", &m_yodification);

	// Check if m_yodification falls within the [0,2] range
	if (m_yodification != 0 && m_yodification != 1 && m_yodification != 2)
	{
		printf("Paràmetre de velocitat no acceptat (0-3)!\nSortint...\n");
		return 1;
	}
#endif

	/*
		m_yodify()

		Parameters (3):
		FILE descriptor pointer, speed modifier and yoda coeff. modifier

		Brief explanation:
		1.- Reads the file and starts cointing the total lines on it,
			also checks for lines that don't have \n at the end.
		
		2.- Builds a string array of N lines (Obtained previously)
			with each sentence found on the file. If it finds a
			newline character at the end of a sentence, it carefully
			replaces it with a \0 byte.

		3.- *CAREFULLY* craft a 3 dimensional character pointer matrix
			that for each line, holds each word on it.
			It's 3 dimensional so that it can hold N lines of maximum
			15 words 15 characters each; a detailed drawing can be found
			further down the source file.

			Because we're dealing with pointers, it's important
			to not blow ourselves up, so the algorithm is carefully
			crafted in order to avoid *possible* segmentation faults.

			Each word gets the same treatment, no spaces, commas or dots.

		4.- After crafting the matrix, for each line, we create an integer
			array that ranges from 0 to the words on that line and fills
			it with number from 0 to, again, the number of that line.
			
			Example:
			Line 1 has 6 words.
			int m_array[6] = {0, 1, 2, 3, 4, 5};

			When the array is created, what we want to accomplish is
			shuffling each part of it so that we can have a randomized
			array.

			Example:
			int m_array[6] = {0, 1, 2, 3, 4, 5};
			exchange(m_array)
			m_array[6] = {4, 2, 3, 1, 5, 0};
			Which we can feed to the matrix[line][m_array[i]] and get
			a never-repeated randomized string from the sentence.

			This clever trick can be archived using rand() and careful
			pointer assignments that swap integer array members between
			themselves granting a non-repeating random sequence of numbers.

		5.- Finally, after doing all that, the only thing left is actually
			checking the speed and yodification coeff. to properly print
			the altered array of strings.

			Once that gets sorted out, yoda appears on the screen and the
			randomized sentence under.

		6.-	When it finishes, it closes the file handle and leaves a last message.
	*/
	
	m_length = m_read_sentences(m_file, m_sentences, m_word_matrix, m_sentence_words);

	m_yodify(m_length, m_word_matrix, m_sentence_words, m_yodification, m_speed);

	printf("De processar... ha acabat, el fitxer\n");

	return 0;
}

void alenteix_frase(char frase[], char frase_lenta[], int velocitat)
{
	(void) frase;
	(void) frase_lenta;
	(void) velocitat;

	printf("... ");
}

int m_read_sentences(FILE *m_file, char m_s[MAX_LINES][15 * 15], char *m_w_m[MAX_LINES][15][15], char *m_sentence_words)
{
	char m_char;
	int i, m_lines = 0, m_line_chars = 0, m_length;

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

	// Rewind up until the start of the file after dealing with fgetc()
	rewind(m_file);

	for (i = 0; i < m_lines; i++)
	{
		fgets(m_s[i], (15 * 15), m_file);

		// Get it's length
		m_length = strlen(m_s[i]);

		// If the sentence exists, check if the last byte on the sentece is a LF (\n)
		if (m_length > 0 && m_s[i][m_length - 1] == '\n')
		{
			// If that's the case, access it using m_length - 1 and set it to \0
			m_s[i][m_length - 1] = '\0';
		}

		m_sentence_words[i] = frase_a_taula(m_s[i], m_w_m[i]);
	}

	fclose(m_file);

	return m_lines;
}

int frase_a_taula(char *frase, char *paraules[15][15])
{
	int m_word_index = 0;
	char *m_index;

	/*
		Point the index to the result of strtok.
		It searches for delimitation tokens (Whitespaces, dots or commas)
		in the sentence arrays and returns a pointer to them, else, a NULL one
		if there's no tokens found.
	*/
	m_index = strtok(frase, " .,");

	// While there's still tokens on the sentence
	while (m_index != NULL)
	{
		/*
			We can't assign values to this matrix by going the traditional way,
			so we need to use strcpy() which expects a pointer to the destination
			and a pointer to the char array
		*/
		strcpy((char *) paraules[m_word_index], m_index);

		// Increment the current word index
		m_word_index++;

		/*
			We specify NULL to strtok() to get it to keep tokenizing the previously
			pointed sentence.
		*/
		m_index = strtok(NULL, " .,");
	}

#ifdef DEBUG
	for (i = 0; i < m_word_index; i++)
	{
		printf("%s ", (char *) paraules[i]);
	}
	
	printf("\n");
#endif

	return m_word_index;
}

void m_yodify(int m_total_lines, char *m_word_matrix[MAX_LINES][15][15], char *m_sentence_words, int m_yodification, int m_speed)
{
	FILE *m_result = fopen("result.txt", "w");
	char m_slowed_sentence[300] = {0};
	int i, j, k;

	// Do this for every line
	for (i = 0; i < m_total_lines; i++)
	{
		// Check if the sentence has 4 or more words
		if (m_sentence_words[i] >= 4)
		{
			// Draw yoda
			dibuixa_yoda();

			/*
				Start printing the sentences
				Do this for all the words in the sentence
			*/

			for (j = 0; j < m_sentence_words[i]; j++)
			{
				if (m_yodification)
				{
					/*
						If they do, create an array sized the total word-length of a sentence.
						So if the sentence has 6 words, array will contain 6 numbers.
					*/
					int m_array[m_sentence_words[i]];
		
					// Populate the newly created array with numbers starting from 0
					for (k = 0; k < m_sentence_words[i]; k++)
					{
						m_array[k] = k;
					}
	
					// Shuffle the array (Change the order of the numerical serie)
					m_array_shuffle(m_array, m_sentence_words[i], m_yodification);

					strcat(m_slowed_sentence, (char *) m_word_matrix[i][m_array[j]]);
					printf("%s", (char *) m_word_matrix[i][m_array[j]]);
				}
				else
				{
					strcat(m_slowed_sentence, (char *) m_word_matrix[i][j]);
					printf("%s", (char *) m_word_matrix[i][j]);
				}

				if (m_speed == 1)
				{
					if ((j) && (j % 2 == 1))
					{
						alenteix_frase((char *) m_word_matrix[i][j], m_slowed_sentence, m_speed);
						strcat(m_slowed_sentence, "... ");
					}
					else
					{
						printf(" ");
						strcat(m_slowed_sentence, " ");
					}
				}
				// Or, if speed = 2, print 3 dots and space after each word
				else if (m_speed == 2)
				{
					alenteix_frase((char *) m_word_matrix[i][j], m_slowed_sentence, m_speed);
					strcat(m_slowed_sentence, "... ");
				}
				else
				{
					// If speed = 0
					strcat(m_slowed_sentence, " ");
					printf(" ");
				}

				strcat(m_slowed_sentence, "\0");
			}

			fputs((char *) m_slowed_sentence, m_result);
			memset(m_slowed_sentence, 0, sizeof(m_slowed_sentence));
		}
		else
		{
			// If the sentence has less-than-4 words, print it as-is without modifications
			printf("\n\n[!] La frase número %d es inferior a 4 paraules, no es yodatitzarà...\n", i + 1);

			// Untouched (Less-than-4-words sentence)
			for (int j = 0; j < m_sentence_words[i]; j++)
			{
				// Print it
				printf("%s ", (char *) m_word_matrix[i][j]);
				strcat(m_slowed_sentence, (char *) m_word_matrix[i][j]);
			}

			fputs((char *) m_slowed_sentence, m_result);
			memset(m_slowed_sentence, 0, sizeof(m_slowed_sentence));
		}

		printf("\n");
		fputs("\n", m_result);
	}
}

// Prof. provided
void dibuixa_yoda()
{
	char yoda[4][19] =	{{92, 96, 45, 45, 46, 95, 39, 46, 58, 58, 46, 96, 46, 95, 46, 45, 45, 39, 47},
						{32, 92, 32, 32, 32, 96, 32, 95, 95, 58, 58, 95, 95, 32, 39, 32, 32, 32, 47},
						{32, 32, 32, 45, 45, 58, 46, 96, 39, 46, 46, 96, 39, 46, 58, 45, 45, 32, 32},
						{32, 32, 32, 32, 32, 32, 92, 32, 96, 45, 45, 39, 32, 47, 32, 32, 32, 32, 32}};
	int i, j = 0;

	printf("\n\n\n");

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 19; j++)
		{
			printf ("%c", yoda[i][j]);
		}
		printf("\n");
	}
}

/*
	This function exchanges two integers by creating a temporal
	variable holding one of them; then, by using pointer addressing
	we can modify the value of the first one to be the value of the
	second; and then, setting the second to the first one (Which was
	saved previously on the temporal variable).
*/
void m_exchange(int *m_first, int *m_second)
{
	// Setup a temporal variable that holds the first value at *position
	// This is all done thanks to pointer dereferencing mechanics
    int m_temp = *m_first;

    // Set the *first value to the *second
    *m_first = *m_second;

    // Set the *second value to the temporal variable (Which holds the old *first val.)
    *m_second = m_temp;
}

/*
	This function is all possible thanks to PRNG.
	It gets a seed for PRNG workings by feeding srand() with a null TIME struct.

	It iterates through each index of the array and exchanges it with another value
	from the same array by calling m_exchange
*/
void m_array_shuffle(int m_array[], int m_array_size, int m_yodification)
{
	// Seed obtaination for rand()
    srand(time(NULL));

    int i, j;

    // Do this for the entire array size
    for (i = m_array_size - 1; i > 0; i--)
    {
    	// Based on the yodification coeff, apply more or less randomness
    	if (m_yodification == 1)
    	{
			j = rand() % (i);
    	}
		else if (m_yodification == 2)
		{
			j = rand() % (i + 1);
		}

		// Call the exchange func.
        m_exchange(&m_array[i], &m_array[j]);
    }
}
