// stdint for standard integer types
#include <stdint.h>
// stdio for printf and scanf decl.
#include <stdio.h>
// stdbool for booleans
#include <stdbool.h>

// OK = 0
#define OK 0
// FAIL = 1
#define FAIL 1

typedef struct budget
{
	// Using uint8_t to ensure less memory footprint
	// It gets limited to hold only 2 digit long number (Max 99) because the practise paper
	// values checking the project length, so anything over 99 is overkill because the comparison
	// is 6 < months > 48
	uint8_t months;

	// Using uint16_t to ensure less memory footprint
	// It gets limited to hold only 4 digit long number (Max 9999) which I think is reasonable
	// considering the project size.
	uint16_t nbworkers;

	// Using uint16_t to ensure less memory footprint
	// It gets limited to hold only 4 digit long number (Max 9999) which I think is reasonable
	// considering the project size.
	uint16_t bworkers;

	// Using uint32_t to ensure less memory footprint
	// It gets limited to hold only 6 digit long number (Max 999999) which I think is reasonable
	// considering the project size.
	uint32_t materials;

	// Using uint32_t to ensure less memory footprint
	// It gets limited to hold only 6 digit long number (Max 999999) which I think is reasonable
	// considering the project size.
	uint32_t travels;

	// Using uint32_t to ensure less memory footprint
	// It gets limited to hold only 6 digit long number (Max 999999) which I think is reasonable
	// considering the project size.
	uint32_t rentalandservices;

	// Using uint32_t to ensure less memory footprint
	// It gets limited to hold only 6 digit long number (Max 999999) which I think is reasonable
	// considering the project size.
	uint32_t fungiblematerials;
} m_budget;
