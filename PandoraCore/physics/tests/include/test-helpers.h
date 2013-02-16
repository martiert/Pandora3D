#ifndef TEST_HELPERS_H
#define TEST_HERLPERS_H

#include <config.h>
#include <cstdlib>
#include <ctime>

#define PRECISION 1.0e-8

double * create_double_array_of_size(const size_t & size);
Physics::Vector3 create_random_vector3();
double create_random_scalar();

#endif
