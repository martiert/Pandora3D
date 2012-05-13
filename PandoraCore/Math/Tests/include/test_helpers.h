#ifndef TEST_HELPERS_H
#define TEST_HERLPERS_H

#include <vector2.h>
#include <vector3.h>
#include <vector4.h>
#include <matrix2.h>
#include <matrix3.h>
#include <matrix4.h>

#define START_MANY for (size_t many_counter = 0; many_counter < 1000; ++many_counter) {
#define END_MANY }

double* create_double_array_of_size (const size_t& size);
Math::Matrix4d create_random_4d_matrix ();
Math::Matrix3d create_random_3d_matrix ();


#endif
