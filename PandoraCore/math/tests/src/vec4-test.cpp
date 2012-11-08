#include "test-helpers.h"

#include <vector4.h>
#include <vector3.h>

#include <gtest/gtest.h>

#include <cmath>

const Math::Vec3d create_random_vector3();
const Math::Vec4d create_random_vector4();

class Vector4Test : public ::testing::Test
{
  protected:
    void SetUp();
    void TearDown();

    double * array;

    double scalar;
    Math::Vec4d empty_vector;
    Math::Vec4d argument_made_vector;
    Math::Vec4d array_assigned_vector;
    Math::Vec4d random_vector;
    Math::Vec4d random_vector2;
    Math::Vec4d random_vector4;
    Math::Vec4d random_vector_copy;
};

void Vector4Test::SetUp()
{
  scalar = rand() / 100.0;
  array = create_double_array_of_size(4);
  argument_made_vector = Math::Vec4d(array[0], array[1], array[2], array[3]);
  random_vector = Math::Vec4d(array);
  array_assigned_vector = array;

  auto tmp = create_double_array_of_size(4);
  random_vector2 = Math::Vec4d(tmp);
  delete[] tmp;

  tmp = create_double_array_of_size(4);
  random_vector4 = Math::Vec4d(tmp);
  delete[] tmp;

  random_vector_copy = random_vector;
}

void Vector4Test::TearDown()
{
  delete[] array;
}

TEST_F(Vector4Test, empty_constructor_creates_zero_vector)
{
  EXPECT_EQ(0.0, empty_vector[0]);
  EXPECT_EQ(0.0, empty_vector[1]);
  EXPECT_EQ(0.0, empty_vector[2]);
  EXPECT_EQ(0.0, empty_vector[3]);
}

TEST_F(Vector4Test, construction_with_arguments_populates_the_vector_with_those_arguments)
{
  const Math::Vec4d vector(0.1, 7.8, 4.3, 2.3);
  EXPECT_EQ(0.1, vector[0]);
  EXPECT_EQ(7.8, vector[1]);
  EXPECT_EQ(4.3, vector[2]);
  EXPECT_EQ(2.3, vector[3]);
}

TEST_F(Vector4Test, construction_from_array_populates_vector_with_array)
{
  EXPECT_EQ(array[0], random_vector[0]);
  EXPECT_EQ(array[1], random_vector[1]);
  EXPECT_EQ(array[2], random_vector[2]);
  EXPECT_EQ(array[3], random_vector[3]);
}

TEST_F(Vector4Test, copy_constructor_copies_each_element)
{
  EXPECT_EQ(random_vector[0], random_vector_copy[0]);
  EXPECT_EQ(random_vector[1], random_vector_copy[1]);
  EXPECT_EQ(random_vector[2], random_vector_copy[2]);
  EXPECT_EQ(random_vector[3], random_vector_copy[3]);
}

TEST_F(Vector4Test, copy_constructor_makes_hard_copy)
{
  ++random_vector[0];
  EXPECT_NE(random_vector[0], random_vector_copy[0]);
}

TEST_F(Vector4Test, assignment_from_vector_makes_copy)
{
  EXPECT_EQ(random_vector[0], random_vector_copy[0]);
  EXPECT_EQ(random_vector[1], random_vector_copy[1]);
  EXPECT_EQ(random_vector[2], random_vector_copy[2]);
  EXPECT_EQ(random_vector[3], random_vector_copy[3]);
}

TEST_F(Vector4Test, copy_from_Vec3d_gives_a_Vec3d_with_1_as_the_w_component)
{
  const auto vector3 = create_random_vector3();
  const Math::Vec4d copy(vector3);

  EXPECT_EQ(vector3[0], copy[0]);
  EXPECT_EQ(vector3[1], copy[1]);
  EXPECT_EQ(vector3[2], copy[2]);
  EXPECT_EQ(1.0, copy[3]);
}

TEST_F(Vector4Test, assigning_from_Vec3d_gives_a_Vec3d_with_1_as_the_w_component)
{
  const auto vector3 = create_random_vector3();
  Math::Vec4d copy;
  copy = vector3;

  EXPECT_EQ(vector3[0], copy[0]);
  EXPECT_EQ(vector3[1], copy[1]);
  EXPECT_EQ(vector3[2], copy[2]);
  EXPECT_EQ(1.0,        copy[3]);
}

TEST_F(Vector4Test, index_operator_maps_to_x_y_z_w)
{
  EXPECT_EQ(random_vector[0], random_vector[0]);
  EXPECT_EQ(random_vector[1], random_vector[1]);
  EXPECT_EQ(random_vector[2], random_vector[2]);
  EXPECT_EQ(random_vector[3], random_vector[3]);
}

TEST_F(Vector4Test, index_operator_manipulates_data)
{
  random_vector[2] = 5.3;

  EXPECT_EQ(5.3, random_vector[2]);
}

TEST_F(Vector4Test, length_of_zero_vector_is_zero)
{
  EXPECT_EQ(0.0, Math::Vec4d::ZERO.length());
  EXPECT_EQ(0.0, Math::Vec4d::ZERO.lengthSquared());
}

TEST_F(Vector4Test, lengthSquared_of_vector_is_the_sum_of_the_squared_components)
{
  EXPECT_EQ(random_vector[0] * random_vector[0] +
             random_vector[1] * random_vector[1] +
             random_vector[2] * random_vector[2] +
             random_vector[3] * random_vector[3], random_vector.lengthSquared());
}

TEST_F(Vector4Test, length_of_vector_is_the_square_root_of_the_squared_length)
{
  EXPECT_EQ(std::sqrt(random_vector.lengthSquared()), random_vector.length());
}

TEST_F(Vector4Test, normalization_of_vector_gives_length_of_1)
{
  random_vector.normalize();

  EXPECT_FLOAT_EQ(1.0, random_vector.length());
}

TEST_F(Vector4Test, negation_of_vector_negates_each_component)
{
  auto res = -random_vector;

  EXPECT_EQ(-random_vector[0], res[0]);
  EXPECT_EQ(-random_vector[1], res[1]);
  EXPECT_EQ(-random_vector[2], res[2]);
  EXPECT_EQ(-random_vector[3], res[3]);
}

TEST_F(Vector4Test, adding_two_vectors_adds_each_component)
{
  auto res = random_vector + random_vector2;

  EXPECT_EQ(random_vector[0] + random_vector2[0], res[0]);
  EXPECT_EQ(random_vector[1] + random_vector2[1], res[1]);
  EXPECT_EQ(random_vector[2] + random_vector2[2], res[2]);
  EXPECT_EQ(random_vector[3] + random_vector2[3], res[3]);
}

TEST_F(Vector4Test, subtracting_two_vectors_subtracts_each_component)
{
  auto res = random_vector - random_vector2;

  EXPECT_EQ(random_vector[0] - random_vector2[0], res[0]);
  EXPECT_EQ(random_vector[1] - random_vector2[1], res[1]);
  EXPECT_EQ(random_vector[2] - random_vector2[2], res[2]);
  EXPECT_EQ(random_vector[3] - random_vector2[3], res[3]);
}

TEST_F(Vector4Test, adding_vector_to_vector_adds_each_component)
{
  auto res = random_vector;
  res += random_vector2;

  EXPECT_EQ(random_vector[0] + random_vector2[0], res[0]);
  EXPECT_EQ(random_vector[1] + random_vector2[1], res[1]);
  EXPECT_EQ(random_vector[2] + random_vector2[2], res[2]);
  EXPECT_EQ(random_vector[3] + random_vector2[3], res[3]);
}

TEST_F(Vector4Test, subtracting_vector_from_vector_subtracts_each_component)
{
  auto res = random_vector;
  res -= random_vector2;

  EXPECT_EQ(random_vector[0] - random_vector2[0], res[0]);
  EXPECT_EQ(random_vector[1] - random_vector2[1], res[1]);
  EXPECT_EQ(random_vector[2] - random_vector2[2], res[2]);
  EXPECT_EQ(random_vector[3] - random_vector2[3], res[3]);
}

TEST_F(Vector4Test, multiplying_vector_with_scalar_from_right_multiplies_each_component_with_scalar)
{
  auto res = random_vector * scalar;

  EXPECT_EQ(random_vector[0] * scalar, res[0]);
  EXPECT_EQ(random_vector[1] * scalar, res[1]);
  EXPECT_EQ(random_vector[2] * scalar, res[2]);
  EXPECT_EQ(random_vector[3] * scalar, res[3]);
}

TEST_F(Vector4Test, multiplying_vector_with_scalar_from_left_multiplies_each_component_with_scalar)
{
  auto res = scalar * random_vector;

  EXPECT_EQ(random_vector[0] * scalar, res[0]);
  EXPECT_EQ(random_vector[1] * scalar, res[1]);
  EXPECT_EQ(random_vector[2] * scalar, res[2]);
  EXPECT_EQ(random_vector[3] * scalar, res[3]);
}

TEST_F(Vector4Test, dividing_vector_with_scalar_from_right_divides_each_component_with_scalar)
{
  auto res = random_vector / scalar;

  EXPECT_EQ(random_vector[0] / scalar, res[0]);
  EXPECT_EQ(random_vector[1] / scalar, res[1]);
  EXPECT_EQ(random_vector[2] / scalar, res[2]);
  EXPECT_EQ(random_vector[3] / scalar, res[3]);
}

TEST_F(Vector4Test, multiplying_vector_with_scalar_multiplies_each_component_with_scalar)
{
  auto res = random_vector;
  res *= scalar;

  EXPECT_EQ(random_vector[0] * scalar, res[0]);
  EXPECT_EQ(random_vector[1] * scalar, res[1]);
  EXPECT_EQ(random_vector[2] * scalar, res[2]);
  EXPECT_EQ(random_vector[3] * scalar, res[3]);
}

TEST_F(Vector4Test, dividing_vector_with_scalar_divides_each_component_with_scalar)
{
  auto res = random_vector;
  res /= scalar;

  EXPECT_EQ(random_vector[0] / scalar, res[0]);
  EXPECT_EQ(random_vector[1] / scalar, res[1]);
  EXPECT_EQ(random_vector[2] / scalar, res[2]);
  EXPECT_EQ(random_vector[3] / scalar, res[3]);
}

TEST_F(Vector4Test, multiplying_vector_to_vector_multiplies_each_component)
{
  auto res = random_vector;
  res *= random_vector2;

  EXPECT_EQ(random_vector[0] * random_vector2[0], res[0]);
  EXPECT_EQ(random_vector[1] * random_vector2[1], res[1]);
  EXPECT_EQ(random_vector[2] * random_vector2[2], res[2]);
  EXPECT_EQ(random_vector[3] * random_vector2[3], res[3]);
}

TEST_F(Vector4Test, dot_product_of_two_vectors_add_the_product_of_the_vectors)
{
  auto dotprod = random_vector.dot(random_vector2);
  auto multvec = random_vector * random_vector2;

  EXPECT_EQ(multvec[0] + multvec[1] + multvec[2] + multvec[3], dotprod);
}

TEST_F(Vector4Test, equality_operator_on_same_object_returns_true)
{
  EXPECT_EQ(random_vector, random_vector);
}

TEST_F(Vector4Test, equality_operator_on_copy_returns_true)
{
  EXPECT_EQ(random_vector, random_vector_copy);
}

TEST_F(Vector4Test, equality_operator_on_different_x_returns_false)
{
  const Math::Vec4d vector(3.2, 4.5, 3.1, 6.7);
  const Math::Vec4d different(2.3, 4.5, 3.1, 6.7);

  EXPECT_FALSE(vector == different);
}

TEST_F(Vector4Test, equality_operator_on_different_y_returns_false)
{
  const Math::Vec4d vector(3.2, 4.5, 3.1, 6.7);
  const Math::Vec4d different(3.2, 4.0, 3.1, 6.7);

  EXPECT_FALSE(vector == different);
}

TEST_F(Vector4Test, equality_operator_on_different_z_returns_false)
{
  const Math::Vec4d vector(3.2, 4.5, 3.1, 6.7);
  const Math::Vec4d different(3.2, 4.5, .1, 6.7);

  EXPECT_FALSE(vector == different);
}

TEST_F(Vector4Test, equality_operator_on_different_w_returns_false)
{
  const Math::Vec4d vector(3.2, 4.5, 3.1, 6.7);
  const Math::Vec4d different(3.2, 4.5, 3.1, 7.8);

  EXPECT_FALSE(vector == different);
}

TEST_F(Vector4Test, inequality_operator_on_different_x_returns_true)
{
  const Math::Vec4d vector(3.2, 4.5, 3.1, 6.7);
  const Math::Vec4d different(2.3, 4.5, 3.1, 6.7);

  EXPECT_NE(vector, different);
}

TEST_F(Vector4Test, inequality_operator_on_different_y_returns_true)
{
  const Math::Vec4d vector(3.2, 4.5, 3.1, 6.7);
  const Math::Vec4d different(3.2, 4.0, 3.1, 6.7);

  EXPECT_NE(vector, different);
}

TEST_F(Vector4Test, inequality_operator_on_different_z_returns_true)
{
  const Math::Vec4d vector(3.2, 4.5, 3.1, 6.7);
  const Math::Vec4d different(3.2, 4.5, .1, 6.7);

  EXPECT_NE(vector, different);
}

TEST_F(Vector4Test, inequality_operator_on_different_w_returns_true)
{
  const Math::Vec4d vector(3.2, 4.5, 3.1, 6.7);
  const Math::Vec4d different(3.2, 4.5, 3.1, 7.8);

  EXPECT_NE(vector, different);
}

TEST_F(Vector4Test, inequality_operator_on_same_object_returns_false)
{
  EXPECT_FALSE(random_vector != random_vector);
}

TEST_F(Vector4Test, inequality_operator_on_copy_returns_false)
{
  EXPECT_FALSE(random_vector != random_vector_copy);
}

TEST_F(Vector4Test, inequality_operator_on_similar_vectors_return_false)
{
  auto array = create_double_array_of_size(4);
  const Math::Vec4d vector(array);
  const Math::Vec4d similar(array);

  EXPECT_FALSE(vector != similar);

  delete[] array;
}

TEST_F(Vector4Test, vector_can_be_casted_c_style)
{
  auto pointer =(const double *) random_vector;

  EXPECT_EQ(pointer[0], random_vector[0]);
  EXPECT_EQ(pointer[1], random_vector[1]);
  EXPECT_EQ(pointer[2], random_vector[2]);
  EXPECT_EQ(pointer[3], random_vector[3]);
}

TEST_F(Vector4Test, vector_can_be_statically_casted)
{
  auto pointer = static_cast<const double *>(random_vector);

  EXPECT_EQ(pointer[0], random_vector[0]);
  EXPECT_EQ(pointer[1], random_vector[1]);
  EXPECT_EQ(pointer[2], random_vector[2]);
  EXPECT_EQ(pointer[3], random_vector[3]);
}

TEST_F(Vector4Test, changing_the_casted_pointers_changes_the_vector)
{
  auto pointer =(double *) random_vector;
  auto static_ptr = static_cast<double *>(random_vector);

  ++pointer[2];
  EXPECT_EQ(pointer[2], random_vector[2]);
  EXPECT_EQ(static_ptr[2], random_vector[2]);
}

const Math::Vec4d create_random_vector4()
{
  auto array = create_double_array_of_size(4);
  Math::Vec4d vector(array);

  delete [] array;
  return vector;
}
