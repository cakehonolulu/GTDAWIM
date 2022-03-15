#ifndef BENCHMARK
#include <stdbool.h>
#endif

#include <math.h>

/* Function definitions */
#ifdef BENCHMARK
unsigned int es_triangular_op(unsigned int m_number);
#else
bool es_triangular_op(unsigned int m_number);
#endif
