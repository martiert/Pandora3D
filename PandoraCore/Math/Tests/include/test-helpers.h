#ifndef TEST_HELPERS_H
#define TEST_HERLPERS_H

#include <vector2.h>
#include <vector3.h>
#include <vector4.h>
#include <matrix2.h>
#include <matrix3.h>
#include <matrix4.h>

#include <gtest/gtest.h>

#define BEGIN_MULTITEST for (size_t many_counter = 0; many_counter < 10000; ++many_counter) {
#define END_MULTITEST }
#define PRECISION 1.0e-10

double* create_double_array_of_size (const size_t& size);

const Math::Vec2d create_random_vector2d ();
const Math::Vec3d create_random_vector3d ();
const Math::Vec4d create_random_vector4d ();

const Math::Matrix2d create_random_matrix2d ();
const Math::Matrix3d create_random_matrix3d ();
const Math::Matrix4d create_random_matrix4d ();

#endif
