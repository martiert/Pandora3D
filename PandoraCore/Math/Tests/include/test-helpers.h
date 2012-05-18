#ifndef TEST_HELPERS_H
#define TEST_HERLPERS_H

#include <cstdlib>
#include <ctime>

#define BEGIN_MULTITEST for (size_t many_counter = 0; many_counter < 10000; ++many_counter) {
#define END_MULTITEST }
#define PRECISION 1.0e-8

double* create_double_array_of_size (const size_t& size);

#endif
