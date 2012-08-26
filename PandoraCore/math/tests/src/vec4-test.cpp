#include "test-helpers.h"

#include <vector4.h>
#include <vector3.h>

#include <gtest/gtest.h>

#include <cmath>

const Math::Vector3 create_random_vector3 ();
const Math::Vector4 create_random_vector4 ();

TEST (Vector4Test, empty_constructor_creates_zero_vector)
{
  const Math::Vector4 vector;
  EXPECT_EQ (0.0, vector.x);
  EXPECT_EQ (0.0, vector.y);
  EXPECT_EQ (0.0, vector.z);
  EXPECT_EQ (0.0, vector.w);
}

TEST (Vector4Test, construction_with_arguments_populates_the_vector_with_those_arguments)
{
  const Math::Vector4 vector (0.1, 7.8, 4.3, 2.3);
  EXPECT_EQ (0.1, vector.x);
  EXPECT_EQ (7.8, vector.y);
  EXPECT_EQ (4.3, vector.z);
  EXPECT_EQ (2.3, vector.w);
}

TEST (Vector4Test, construction_from_array_populates_vector_with_array)
{
  BEGIN_MULTITEST

  auto array = create_double_array_of_size (4);
  const Math::Vector4 vector (array);

  EXPECT_EQ (array[0], vector.x);
  EXPECT_EQ (array[1], vector.y);
  EXPECT_EQ (array[2], vector.z);
  EXPECT_EQ (array[3], vector.w);

  delete[] array;
  END_MULTITEST
}

TEST (Vector4Test, copy_constructor_copies_each_element)
{
  BEGIN_MULTITEST

  const auto vector = create_random_vector4 ();
  const Math::Vector4 copy (vector);

  EXPECT_EQ (vector.x, copy.x);
  EXPECT_EQ (vector.y, copy.y);
  EXPECT_EQ (vector.z, copy.z);
  EXPECT_EQ (vector.w, copy.w);

  END_MULTITEST
}

TEST (Vector4Test, copy_constructor_makes_hard_copy)
{
  BEGIN_MULTITEST

  auto vector = create_random_vector4 ();
  const Math::Vector4 copy (vector);
  ++vector.x;
  EXPECT_NE (vector.x, copy.x);

  END_MULTITEST
}

TEST (Vector4Test, assignment_from_vector_makes_copy)
{
  BEGIN_MULTITEST

  const auto vector = create_random_vector4 ();
  Math::Vector4 copy;
  copy = vector;

  EXPECT_EQ (vector.x, copy.x);
  EXPECT_EQ (vector.y, copy.y);
  EXPECT_EQ (vector.z, copy.z);
  EXPECT_EQ (vector.w, copy.w);

  END_MULTITEST
}

TEST (Vector4Test, assignment_from_array_assigns_each_element_to_vector)
{
  BEGIN_MULTITEST

  auto array = create_double_array_of_size (4);
  Math::Vector4 vector;
  vector = array;

  EXPECT_EQ (array[0], vector.x);
  EXPECT_EQ (array[1], vector.y);
  EXPECT_EQ (array[2], vector.z);
  EXPECT_EQ (array[3], vector.w);

  delete[] array;
  END_MULTITEST
}

TEST (Vector4Test, copy_from_Vector3_gives_a_Vector3_with_1_as_the_w_component)
{
  BEGIN_MULTITEST

  const auto vector3 = create_random_vector3 ();
  const Math::Vector4 copy (vector3);

  EXPECT_EQ (vector3.x, copy.x);
  EXPECT_EQ (vector3.y, copy.y);
  EXPECT_EQ (vector3.z, copy.z);
  EXPECT_EQ (1.0, copy.w);

  END_MULTITEST
}

TEST (Vector4Test, assigning_from_Vector3_gives_a_Vector3_with_1_as_the_w_component)
{
  BEGIN_MULTITEST

  const auto vector3 = create_random_vector3 ();
  Math::Vector4 copy;
  copy = vector3;

  EXPECT_EQ (vector3.x, copy.x);
  EXPECT_EQ (vector3.y, copy.y);
  EXPECT_EQ (vector3.z, copy.z);
  EXPECT_EQ (1.0, copy.w);

  END_MULTITEST
}

TEST (Vector4Test, index_operator_maps_to_x_y_z_w)
{
  BEGIN_MULTITEST

  const auto vector = create_random_vector4 ();

  EXPECT_EQ (vector.x, vector[0]);
  EXPECT_EQ (vector.y, vector[1]);
  EXPECT_EQ (vector.z, vector[2]);
  EXPECT_EQ (vector.w, vector[3]);

  END_MULTITEST
}

TEST (Vector4Test, index_operator_manipulates_data)
{
  auto vector = create_random_vector4 ();
  vector[2] = 5.3;

  EXPECT_EQ (5.3, vector.z);
}

TEST (Vector4Test, index_operator_throws_index_operator_out_of_range_exception_when_out_of_range)
{
  const auto vector = create_random_vector4 ();

  EXPECT_THROW (vector[4], Math::Vector4::index_operator_out_of_range_exception);
}

TEST (Vector4Test, length_of_zero_vector_is_zero)
{
  const Math::Vector4 zero;

  EXPECT_EQ (0.0, zero.length ());
  EXPECT_EQ (0.0, zero.lengthSquared ());
}

TEST (Vector4Test, lengthSquared_of_vector_is_the_sum_of_the_squared_components)
{
  BEGIN_MULTITEST

  const auto vector = create_random_vector4 ();

  EXPECT_EQ (vector.x * vector.x +
             vector.y * vector.y +
             vector.z * vector.z +
             vector.w * vector.w, vector.lengthSquared ());

  END_MULTITEST
}

TEST (Vector4Test, length_of_vector_is_the_square_root_of_the_squared_length)
{
  BEGIN_MULTITEST

  const auto vector = create_random_vector4 ();

  EXPECT_EQ (std::sqrt (vector.lengthSquared ()), vector.length ());

  END_MULTITEST
}

TEST (Vector4Test, normalization_of_vector_gives_length_of_1)
{
  BEGIN_MULTITEST

  auto vector = create_random_vector4 ();
  vector.normalize ();

  EXPECT_FLOAT_EQ (1.0, vector.length ());

  END_MULTITEST
}

TEST (Vector4Test, normalization_of_zero_vector_throws_normalizing_zero_vector_exception)
{
  Math::Vector4 zero;
  EXPECT_THROW (zero.normalize (), Math::Vector4::normalizing_zero_vector_exception);
}

TEST (Vector4Test, negation_of_vector_negates_each_component)
{
  BEGIN_MULTITEST

  const auto vector = create_random_vector4 ();
  auto res = -vector;

  EXPECT_EQ (-vector.x, res.x);
  EXPECT_EQ (-vector.y, res.y);
  EXPECT_EQ (-vector.z, res.z);
  EXPECT_EQ (-vector.w, res.w);

  END_MULTITEST
}

TEST (Vector4Test, adding_two_vectors_adds_each_component)
{
  BEGIN_MULTITEST

  const auto vec_1 = create_random_vector4 ();
  const auto vec_2 = create_random_vector4 ();
  auto res = vec_1 + vec_2;

  EXPECT_EQ (vec_1.x + vec_2.x, res.x);
  EXPECT_EQ (vec_1.y + vec_2.y, res.y);
  EXPECT_EQ (vec_1.z + vec_2.z, res.z);
  EXPECT_EQ (vec_1.w + vec_2.w, res.w);

  END_MULTITEST
}

TEST (Vector4Test, subtracting_two_vectors_subtracts_each_component)
{
  BEGIN_MULTITEST

  const auto vec_1 = create_random_vector4 ();
  const auto vec_2 = create_random_vector4 ();
  auto res = vec_1 - vec_2;

  EXPECT_EQ (vec_1.x - vec_2.x, res.x);
  EXPECT_EQ (vec_1.y - vec_2.y, res.y);
  EXPECT_EQ (vec_1.z - vec_2.z, res.z);
  EXPECT_EQ (vec_1.w - vec_2.w, res.w);

  END_MULTITEST
}

TEST (Vector4Test, adding_vector_to_vector_adds_each_component)
{
  BEGIN_MULTITEST

  const auto vec_1 = create_random_vector4 ();
  const auto vec_2 = create_random_vector4 ();
  auto res = vec_1;
  res += vec_2;

  EXPECT_EQ (vec_1.x + vec_2.x, res.x);
  EXPECT_EQ (vec_1.y + vec_2.y, res.y);
  EXPECT_EQ (vec_1.z + vec_2.z, res.z);
  EXPECT_EQ (vec_1.w + vec_2.w, res.w);

  END_MULTITEST
}

TEST (Vector4Test, subtracting_vector_from_vector_subtracts_each_component)
{
  BEGIN_MULTITEST

  const auto vec_1 = create_random_vector4 ();
  const auto vec_2 = create_random_vector4 ();
  auto res = vec_1;
  res -= vec_2;

  EXPECT_EQ (vec_1.x - vec_2.x, res.x);
  EXPECT_EQ (vec_1.y - vec_2.y, res.y);
  EXPECT_EQ (vec_1.z - vec_2.z, res.z);
  EXPECT_EQ (vec_1.w - vec_2.w, res.w);

  END_MULTITEST
}

TEST (Vector4Test, multiplying_vector_with_scalar_from_right_multiplies_each_component_with_scalar)
{
  BEGIN_MULTITEST

  const auto vector = create_random_vector4 ();
  auto scalar = rand () / 100.0;
  auto res = vector * scalar;

  EXPECT_EQ (vector.x * scalar, res.x);
  EXPECT_EQ (vector.y * scalar, res.y);
  EXPECT_EQ (vector.z * scalar, res.z);
  EXPECT_EQ (vector.w * scalar, res.w);

  END_MULTITEST
}

TEST (Vector4Test, multiplying_vector_with_scalar_from_left_multiplies_each_component_with_scalar)
{
  BEGIN_MULTITEST

  const auto vector = create_random_vector4 ();
  auto scalar = rand () / 100.0;
  auto res = scalar * vector;

  EXPECT_EQ (vector.x * scalar, res.x);
  EXPECT_EQ (vector.y * scalar, res.y);
  EXPECT_EQ (vector.z * scalar, res.z);
  EXPECT_EQ (vector.w * scalar, res.w);

  END_MULTITEST
}

TEST (Vector4Test, dividing_vector_with_scalar_from_right_divides_each_component_with_scalar)
{
  BEGIN_MULTITEST

  const auto vector = create_random_vector4 ();
  auto scalar = rand () / 100.0;
  auto res = vector / scalar;

  EXPECT_EQ (vector.x / scalar, res.x);
  EXPECT_EQ (vector.y / scalar, res.y);
  EXPECT_EQ (vector.z / scalar, res.z);
  EXPECT_EQ (vector.w / scalar, res.w);

  END_MULTITEST
}

TEST (Vector4Test, dividing_vector_and_zero_throws_division_by_zero_exception)
{
  const auto vector = create_random_vector4 ();
  EXPECT_THROW (vector / 0.0, Math::Vector4::division_by_zero_exception);
}

TEST (Vector4Test, multiplying_vector_with_scalar_multiplies_each_component_with_scalar)
{
  BEGIN_MULTITEST

  const auto vector = create_random_vector4 ();
  auto scalar = create_random_scalar ();
  auto res = vector;
  res *= scalar;

  EXPECT_EQ (vector.x * scalar, res.x);
  EXPECT_EQ (vector.y * scalar, res.y);
  EXPECT_EQ (vector.z * scalar, res.z);
  EXPECT_EQ (vector.w * scalar, res.w);

  END_MULTITEST
}

TEST (Vector4Test, dividing_vector_with_scalar_divides_each_component_with_scalar)
{
  BEGIN_MULTITEST

  const auto vector = create_random_vector4 ();
  auto scalar = rand () / 100.0;
  auto res = vector;
  res /= scalar;

  EXPECT_EQ (vector.x / scalar, res.x);
  EXPECT_EQ (vector.y / scalar, res.y);
  EXPECT_EQ (vector.z / scalar, res.z);
  EXPECT_EQ (vector.w / scalar, res.w);

  END_MULTITEST
}

TEST (Vector4Test, multiplying_vector_to_vector_multiplies_each_component)
{
  BEGIN_MULTITEST

  const auto vector = create_random_vector4 ();
  const auto other = create_random_vector4 ();
  auto res = vector;
  res *= other;

  EXPECT_EQ (vector.x * other.x, res.x);
  EXPECT_EQ (vector.y * other.y, res.y);
  EXPECT_EQ (vector.z * other.z, res.z);
  EXPECT_EQ (vector.w * other.w, res.w);

  END_MULTITEST
}

TEST (Vector4Test, dividing_vector_with_zero_throws_division_by_zero_exception)
{
  auto vector = create_random_vector4 ();
  EXPECT_THROW (vector /= 0.0, Math::Vector4::division_by_zero_exception);
}

TEST (Vector4Test, dot_product_of_two_vectors_add_the_product_of_the_vectors)
{
  BEGIN_MULTITEST

  const auto vector = create_random_vector4 ();
  const auto other = create_random_vector4 ();
  auto dotprod = vector.dot (other);
  auto multvec = vector * other;

  EXPECT_EQ (multvec.x + multvec.y + multvec.z + multvec.w, dotprod);

  END_MULTITEST
}

TEST (Vector4Test, equality_operator_on_same_object_returns_true)
{
  BEGIN_MULTITEST

  const auto vector = create_random_vector4 ();

  EXPECT_EQ (vector, vector);

  END_MULTITEST
}

TEST (Vector4Test, equality_operator_on_copy_returns_true)
{
  BEGIN_MULTITEST

  const auto vector = create_random_vector4 ();
  auto copy (vector);

  EXPECT_EQ (vector, copy);

  END_MULTITEST
}

TEST (Vector4Test, equality_operator_on_similar_vectors_return_true)
{
  BEGIN_MULTITEST

  auto array = create_double_array_of_size (4);
  const Math::Vector4 vector (array);
  const Math::Vector4 similar (array);

  EXPECT_EQ (vector, similar);

  delete[] array;
  END_MULTITEST
}

TEST (Vector4Test, equality_operator_on_different_x_returns_false)
{
  const Math::Vector4 vector (3.2, 4.5, 3.1, 6.7);
  const Math::Vector4 different (2.3, 4.5, 3.1, 6.7);

  EXPECT_FALSE (vector == different);
}

TEST (Vector4Test, equality_operator_on_different_y_returns_false)
{
  const Math::Vector4 vector (3.2, 4.5, 3.1, 6.7);
  const Math::Vector4 different (3.2, 4.0, 3.1, 6.7);

  EXPECT_FALSE (vector == different);
}

TEST (Vector4Test, equality_operator_on_different_z_returns_false)
{
  const Math::Vector4 vector (3.2, 4.5, 3.1, 6.7);
  const Math::Vector4 different (3.2, 4.5, .1, 6.7);

  EXPECT_FALSE (vector == different);
}

TEST (Vector4Test, equality_operator_on_different_w_returns_false)
{
  const Math::Vector4 vector (3.2, 4.5, 3.1, 6.7);
  const Math::Vector4 different (3.2, 4.5, 3.1, 7.8);

  EXPECT_FALSE (vector == different);
}

TEST (Vector4Test, inequality_operator_on_different_x_returns_true)
{
  const Math::Vector4 vector (3.2, 4.5, 3.1, 6.7);
  const Math::Vector4 different (2.3, 4.5, 3.1, 6.7);

  EXPECT_NE (vector, different);
}

TEST (Vector4Test, inequality_operator_on_different_y_returns_true)
{
  const Math::Vector4 vector (3.2, 4.5, 3.1, 6.7);
  const Math::Vector4 different (3.2, 4.0, 3.1, 6.7);

  EXPECT_NE (vector, different);
}

TEST (Vector4Test, inequality_operator_on_different_z_returns_true)
{
  const Math::Vector4 vector (3.2, 4.5, 3.1, 6.7);
  const Math::Vector4 different (3.2, 4.5, .1, 6.7);

  EXPECT_NE (vector, different);
}

TEST (Vector4Test, inequality_operator_on_different_w_returns_true)
{
  const Math::Vector4 vector (3.2, 4.5, 3.1, 6.7);
  const Math::Vector4 different (3.2, 4.5, 3.1, 7.8);

  EXPECT_NE (vector, different);
}

TEST (Vector4Test, inequality_operator_on_same_object_returns_false)
{
  BEGIN_MULTITEST

  const auto vector = create_random_vector4 ();

  EXPECT_FALSE (vector != vector);

  END_MULTITEST
}

TEST (Vector4Test, inequality_operator_on_copy_returns_false)
{
  BEGIN_MULTITEST

  const auto vector = create_random_vector4 ();
  auto copy (vector);

  EXPECT_FALSE (vector != copy);

  END_MULTITEST
}

TEST (Vector4Test, inequality_operator_on_similar_vectors_return_false)
{
  BEGIN_MULTITEST

  auto array = create_double_array_of_size (4);
  const Math::Vector4 vector (array);
  const Math::Vector4 similar (array);

  EXPECT_FALSE (vector != similar);

  delete[] array;
  END_MULTITEST
}

TEST (Vector4Test, vector_can_be_casted_c_style)
{
  const auto vector = create_random_vector4 ();
  auto pointer = (const double *) vector;

  EXPECT_EQ (pointer[0], vector.x);
  EXPECT_EQ (pointer[1], vector.y);
  EXPECT_EQ (pointer[2], vector.z);
  EXPECT_EQ (pointer[3], vector.w);
}

TEST (Vector4Test, vector_can_be_statically_casted)
{
  const auto vector = create_random_vector4 ();
  auto pointer = static_cast<const double *> (vector);

  EXPECT_EQ (pointer[0], vector.x);
  EXPECT_EQ (pointer[1], vector.y);
  EXPECT_EQ (pointer[2], vector.z);
  EXPECT_EQ (pointer[3], vector.w);
}

TEST (Vector4Test, changing_the_casted_pointers_changes_the_vector)
{
  auto vector = create_random_vector4 ();
  auto pointer = (double *) vector;
  auto static_ptr = static_cast<double *> (vector);

  ++pointer[2];
  EXPECT_EQ (pointer[2], vector.z);
  EXPECT_EQ (static_ptr[2], vector.z);
}

const Math::Vector4 create_random_vector4 ()
{
  auto array = create_double_array_of_size (4);
  Math::Vector4 vector (array);

  delete [] array;
  return vector;
}
