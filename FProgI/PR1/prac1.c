#include "prac1.h"

// main() function
int main()
{
	// Filename array that can read file names up to 20 characters
	char m_filename[21] = {0};

	// Speed of text and yodification modifier
	int m_speed, m_yodification;

	// FILE object type variable that will hold the text file handle 
	FILE *m_file = NULL;

	printf("Yodizer - Del català al dialecte yoda!\n");
	printf("Introdueixi el nom del fitxer a llegir: ");

	/*
		Read the filename from stdin buffer
		Use the %19 modifier to allow only up to 19 characters
	*/
	scanf("%20s", m_filename);

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
	m_yodify(m_file, m_speed, m_yodification);

	printf("\n\nDe processar... ha acabat, el fitxer\n");
	fclose(m_file);

	return 0;
}

int m_yodify(FILE *m_file, int m_speed, int m_yodification)
{
	/*
		Total line count (Excluding empty newlines); how many characters
		a determined line has, the current character index for fgetc()
		and the current already-read characters (To aid in line detection)
	*/
	char m_char, *m_index;
	int m_lines = 0, m_line_chars = 0;

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

	// Max of 15 strings of maximum 15 characters
	// Split into sentences
	char m_sentences[m_lines][15 * 15];

	// Do this for all lines
	for (int i = 0; i < m_lines; i++)
	{
		// Read the entire sentence off the file
		fgets(m_sentences[i], (15 * 15), m_file);

		// Get it's length
		int m_length = strlen(m_sentences[i]);

		// If the sentence exists, check if the last byte on the sentece is a LF (\n)
		if (m_length > 0 && m_sentences[i][m_length - 1] == '\n')
		{
			// If that's the case, access it using m_length - 1 and set it to \0
			m_sentences[i][m_length - 1] = '\0';
		}
	}

	/*
		matrix[sentence][word][char_list]

		Sentence	0   may the force be with you    Word	0 may		Letters		0 m
					1   may the force be with you...		1 the					1 a
					2   ...									2 force					2 y
					...										3 ...
	*/
	char *m_matrix[m_lines][15][15];

	// Craft an array of words per line (Ex: m_sentence_words[line1] = 6)
	char m_sentence_words[m_lines];
	
	/*
		Because C expects m_lines to be defined at compile-time, we need to
		populate the array afterwards so that it can be used without segfaulting.

		Not doing so leaves the compiler no size information and it can't allocate
		the space for it correctly.

		It's done this way because malloc()'s aren't permitted as of right now
	*/
	memset(m_matrix, '0', m_lines * 15 * 15 * sizeof(char *));

	// Current word index
	int m_word_index = 0;

	// Do this for every line
	for (int i = 0; i < m_lines; i++)
	{
		/*
			Point the index to the result of strtok.
			It searches for delimitation tokens (Whitespaces, dots or commas)
			in the sentence arrays and returns a pointer to them, else, a NULL one
			if there's no tokens found.

		*/
		m_index = strtok(m_sentences[i], " .,");

		// While there's still tokens on the sentence
		while (m_index != NULL)
		{
			/*
				We can't assign values to this matrix by going the traditional way,
				so we need to use strcpy() which expects a pointer to the destination
				and a pointer to the char array
			*/
			strcpy((char *) m_matrix[i][m_word_index], m_index);

			// Increment the current word index
			m_word_index++;

			/*
				We specify NULL to strtok() to get it to keep tokenizing the previously
				pointed sentence.
			*/
			m_index = strtok(NULL, " .,");
		}	

		// After each loop ending, add the sentence word count to the array of line word numbers
		m_sentence_words[i] = m_word_index;

		// And set the index back to 0
		m_word_index = 0;
	}

#ifdef DEBUG
	/*
		This doesn't get compiled in "release" builds, but it iterates through all sentences
		and prints them if-and-only-if their word-count is 4 or higher.

		I left this algo here because it shows how I planned to do the words >= 4 check afterwards.
	*/
	int m_checked_sentences = 0;

	for (int i = 0; i < m_lines; i++)
	{
		if (m_sentence_words[i] >= 4)
		{
			m_checked_sentences++;

			printf("Frase %d (Paraules %d): ", m_checked_sentences, m_sentence_words[i]);

			for (int x = 0; x < m_sentence_words[i]; x++)
			{
				printf("%s ", (char *) m_matrix[i][x]);
			}

			printf("\n");
		}		
	}
#endif

	// Do this for every line
	for (int i = 0; i < m_lines; i++)
	{
		// Check if the sentence has 4 or more words
		if (m_sentence_words[i] >= 4)
		{
			/*
				If they do, create an array sized the total word-length of a sentence.
				So if the sentence has 6 words, array will contain 6 numbers.
			*/
			int m_array[m_sentence_words[i]];

			// Same reasoning for this can be found up in the source code.
			memset(m_array, '0', m_sentence_words[i] * sizeof(int));

			// Populate the newly created array with numbers starting from 0
			for (int l = 0; l < m_sentence_words[i]; l++)
			{
				m_array[l] = l;
			}

			// Shuffle the array (Change the order of the numerical serie)
			m_array_shuffle(m_array, m_sentence_words[i], m_yodification);

			// Draw yoda
			dibuixa_yoda();

			/*
				Start printing the sentences
				Do this for all the words in the sentence
			*/
			for (int j = 0; j < m_sentence_words[i]; j++)
			{
				// Print the word by accessing the matrix
				printf("%s", (char *) m_matrix[i][m_array[j]]);

				// Check if speed = 1 and if we've already printed 2 words
				// If we have not, print a whitespace
				if (m_speed == 1 && j % 2 == 1)
				{
					printf(" ");
				}
				// If we have and speed = 1, print 3 dots and a space
				else if (m_speed == 1 && j % 2 == 0)
				{
					printf("... ");
				}
				// Or, if speed = 2, print 3 dots and space after each word
				else if (m_speed == 2)
				{
					printf("... ");
				}
			}
		}
		else
		{
			// If the sentence has less-than-4 words, print it as-is without modifications
			printf("\n\n[!] La frase número %d es inferior a 4 paraules, no es yodatitzarà...\n", i + 1);

			// Untouched (Less-than-4-words sentence)
			for (int j = 0; j < m_sentence_words[i]; j++)
			{
				// Print it
				printf("%s ", (char *) m_matrix[i][j]);
			}
		}

		printf("\n");
	}

	return 0;
}

// Prof. provided
void dibuixa_yoda()
{
	char yoda[4][19] =	{{92, 96, 45, 45, 46, 95, 39, 46, 58, 58, 46, 96, 46, 95, 46, 45, 45, 39, 47},
						{32, 92, 32, 32, 32, 96, 32, 95, 95, 58, 58, 95, 95, 32, 39, 32, 32, 32, 47},
						{32, 32, 32, 45, 45, 58, 46, 96, 39, 46, 46, 96, 39, 46, 58, 45, 45, 32, 32},
						{32, 32, 32, 32, 32, 32, 92, 32, 96, 45, 45, 39, 32, 47, 32, 32, 32, 32, 32}};
	int i, j;

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

void m_exchange(int *m_first, int *m_second)
{
    int m_temp = *m_first;
    *m_first = *m_second;
    *m_second = m_temp;
}

void m_array_shuffle(int m_array[], int m_array_size, int m_yodification)
{
    srand(time(NULL));

    int i, j;

    for (i = m_array_size - 1; i > 0; i--)
    {
    	if (m_yodification == 1)
    	{
			j = rand() % (i);
    	}
		else
		{
			j = rand() % (i + 1);
		}

        m_exchange(&m_array[i], &m_array[j]);
    }
}
