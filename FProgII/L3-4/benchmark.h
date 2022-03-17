// We will only need the next headers if compiling for benchmark
// rand() & derivates (srand...)
#include <stdlib.h>

// Needed for UINT32_MAX's val.
#include <stdint.h>

// For time(struct...)
#include <time.h>

// printf()...
#include <stdio.h>

// Configurable benchmark number, default to 10M (1M offers good insight too)
#define N_VEGADES 1000000

#ifndef EXTERNAL_TIME
void timed_benchmark();
#endif
