#include <stdbool.h>

/* Definitions */
#define P 50000

/* Function definitions */
void calcula_triangulars(unsigned int *m_table);

#ifdef BENCHMARK
unsigned int es_triangular_tau(unsigned int *m_table, unsigned int m_number);
#else
bool es_triangular_tau(unsigned int *m_table, unsigned int m_number);
#endif
