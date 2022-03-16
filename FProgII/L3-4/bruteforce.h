#ifndef BENCHMARK
#include <stdbool.h>
#endif

/* Function definitions */
#ifdef BENCHMARK
unsigned int es_triangular_fb(unsigned int m_number);
#else
bool es_triangular_fb(unsigned int m_number);
#endif
