#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINES 50

int m_read_sentences(FILE *m_file, char m_s[MAX_LINES][15 * 15], char *m_w_m[MAX_LINES][15][15], char *m_sentence_words);
void m_yodify(int m_total_lines, char *m_word_matrix[MAX_LINES][15][15], char *m_sentence_words, int m_yodification, int m_speed);
int frase_a_taula(char *frase, char *paraules[15][15]);
void dibuixa_yoda();
void m_exchange(int *m_first, int *m_second);
void m_array_shuffle(int m_array[], int m_array_size, int m_yodification);
