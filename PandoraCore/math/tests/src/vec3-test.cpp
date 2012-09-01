#include "test-helpers.h"

#include <vector3.h>
#include <gtest/gtest.h>

#include <cmath>

const Math::Vec3d create_random_vector3 ();

TEST (Vector3Test, empty_constructor_gives_zero_vector)
{
  const Math::Vec3d vector;
  EXPECT_EQ (0.0, vector.x);
  EXPECT_EQ (0.0, vector.y);
  EXPECT_EQ (0.0, vector.z);
}

TEST (Vector3Test, constructing_a_vector_with_three_arguments_populates_the_vector_with_those_arguments)
{
  const Math::Vec3d vector (0.1, 2.3, 3.7);
  EXPECT_EQ (0.1, vector.x);
  EXPECT_EQ (2.3, vector.y);
  EXPECT_EQ (3.7, vector.z);
}

TEST (Vector3Test, constructing_a_vector_with_an_array_of_three_elements_populates_vector_with_the_array)
{
  BEGIN_MULTITEST

  auto tmp = create_double_array_of_size (3);
  const Math::Vec3d vector (tmp);

  EXPECT_EQ (tmp[0], vector.x);
  EXPECT_EQ (tmp[1], vector.y);
  EXPECT_EQ (tmp[2], vector.z);

  delete[] tmp;
  END_MULTITEST
}

TEST (Vector3Test, assigning_a_vector_to_an_array_populates_vector_with_given_array)
{
  BEGIN_MULTITEST

  auto tmp = create_double_array_of_size (3);
  const Math::Vec3d vector = tmp;

  EXPECT_EQ (tmp[0], vector.x);
  EXPECT_EQ (tmp[1], vector.y);
  EXPECT_EQ (tmp[2], vector.z);

  delete[] tmp;
  END_MULTITEST
}

TEST (Vector3Test, assigning_a_vector_to_another_vector_populates_the_vector)
{
  BEGIN_MULTITEST

  auto vector = create_random_vector3 ();
  auto copy = vector;

  EXPECT_EQ (vector.x, copy.x);
  EXPECT_EQ (vector.y, copy.y);
  EXPECT_EQ (vector.z, copy.z);

  END_MULTITEST
}

TEST (Vector3Test, copy_constructor_makes_hard_copy)
{
  BEGIN_MULTITEST

  const auto vector = create_random_vector3 ();
  auto copy (vector);

  EXPECT_EQ (vector.x, copy.x);
  EXPECT_EQ (vector.y, copy.y);
  EXPECT_EQ (vector.z, copy.z);
  ++copy.x;
  EXPECT_NE (vector.x, copy.x);

  END_MULTITEST
}

TEST (Vector3Test, index_operator_maps_to_x_y_and_z)
{
  BEGIN_MULTITEST

  auto vector = create_random_vector3 ();

  EXPECT_EQ (vector.x, vector[0]);
  EXPECT_EQ (vector.y, vector[1]);
  EXPECT_EQ (vector.z, vector[2]);

  vector[1] += 10;
  EXPECT_EQ (vector.y, vector[1]);

  END_MULTITEST
}

TEST (Vector3Test, index_operator_maps_for_const_vectors)
{
  BEGIN_MULTITEST

  const auto vector = create_random_vector3 ();
  EXPECT_EQ (vector.x, vector[0]);
  EXPECT_EQ (vector.y, vector[1]);
  EXPECT_EQ (vector.z, vector[2]);

  END_MULTITEST
}

TEST (Vector3Test, index_operator_throws_index_operator_out_of_range_exception)
{
  const Math::Vec3d vector;

  EXPECT_THROW (vector[3], Math::Vec3d::index_operator_out_of_range_exception);
}

TEST (Vector3Test, length_of_zero_vector_is_zero)
{
  const Math::Vec3d vector;
  EXPECT_EQ (0.0, vector.length ());
  EXPECT_EQ (0.0, vector.lengthSquared ());
}

TEST (Vector3Test, length_of_vector_follows_mathematical_rules)
{
  BEGIN_MULTITEST

  const auto vector = create_random_vector3 ();
  EXPECT_EQ (std::sqrt (vector.x*vector.x + vector.y*vector.y + vector.z*vector.z), vector.length ());
  EXPECT_EQ ((vector.x*vector.x + vector.y*vector.y + vector.z*vector.z), vector.lengthSquared ());

  END_MULTITEST
}

TEST (Vector3Test, normalize_vector_gives_length_of_1)
{
  BEGIN_MULTITEST

  auto vector = create_random_vector3 ();
  vector.normalize ();
  EXPECT_FLOAT_EQ (1.0, vector.length ());

  END_MULTITEST
}

TEST (Vector3Test, normalize_zero_vector_throws_normalizing_zero_vector_exception)
{
  Math::Vec3d vector;
  EXPECT_THROW (vector.normalize (), Math::Vec3d::normalizing_zero_vector_exception);
}

TEST (Vector3Test, negating_a_vector_returns_the_negation_of_each_element)
{
  BEGIN_MULTITEST

  const auto vector = create_random_vector3 ();
  auto result = -vector;

  EXPECT_EQ (-vector.x, result.x);
  EXPECT_EQ (-vector.y, result.y);
  EXPECT_EQ (-vector.z, result.z);

  END_MULTITEST
}

TEST (Vector3Test, adding_two_vectors_adds_the_vectors_by_elements)
{
  BEGIN_MULTITEST

  const auto vec_1 = create_random_vector3 ();
  const auto vec_2 = create_random_vector3 ();
  auto res = vec_1 + vec_2;

  EXPECT_EQ (vec_1.x + vec_2.x, res.x);
  EXPECT_EQ (vec_1.y + vec_2.y, res.y);
  EXPECT_EQ (vec_1.z + vec_2.z, res.z);

  END_MULTITEST
}

TEST (Vector3Test, subtracting_two_vectors_subtracts_the_vectors_by_elements)
{
  BEGIN_MULTITEST

  const auto vec_1 = create_random_vector3 ();
  const auto vec_2 = create_random_vector3 ();
  auto res = vec_1 - vec_2;

  EXPECT_EQ (vec_1.x - vec_2.x, res.x);
  EXPECT_EQ (vec_1.y - vec_2.y, res.y);
  EXPECT_EQ (vec_1.z - vec_2.z, res.z);

  END_MULTITEST
}

TEST (Vector3Test, adding_a_vector_to_a_vector_adds_element_wise)
{
  BEGIN_MULTITEST

  const auto vec_1 = create_random_vector3 ();
  const auto vec_2 = create_random_vector3 ();
  auto res = vec_1;

  res += vec_2;

  EXPECT_EQ (vec_1.x + vec_2.x, res.x);
  EXPECT_EQ (vec_1.y + vec_2.y, res.y);
  EXPECT_EQ (vec_1.z + vec_2.z, res.z);

  END_MULTITEST
}

TEST (Vector3Test, subtracting_a_vector_from_a_vector_subtracts_element_wise)
{
  BEGIN_MULTITEST

  const auto vec_1 = create_random_vector3 ();
  const auto vec_2 = create_random_vector3 ();
  auto res = vec_1;

  res -= vec_2;

  EXPECT_EQ (vec_1.x - vec_2.x, res.x);
  EXPECT_EQ (vec_1.y - vec_2.y, res.y);
  EXPECT_EQ (vec_1.z - vec_2.z, res.z);

  END_MULTITEST
}

TEST (Vector3Test, multiplying_vector_with_scalar_from_right_multiplies_each_element_by_the_scalar)
{
  BEGIN_MULTITEST

  const auto vector = create_random_vector3 ();
  auto scalar = rand () / 100.0;
  auto res = vector * scalar;

  EXPECT_EQ (vector.x * scalar, res.x);
  EXPECT_EQ (vector.y * scalar, res.y);
  EXPECT_EQ (vector.z * scalar, res.z);

  END_MULTITEST
}

TEST (Vector3Test, multiplying_vector_with_scalar_from_left_multiplies_each_element_by_the_scalar)
{
  BEGIN_MULTITEST

  const auto vector = create_random_vector3 ();
  auto scalar = rand () / 100.0;
  auto res = scalar * vector;

  EXPECT_EQ (vector.x * scalar, res.x);
  EXPECT_EQ (vector.y * scalar, res.y);
  EXPECT_EQ (vector.z * scalar, res.z);

  END_MULTITEST
}

TEST (Vector3Test, dividing_vector_with_scalar_from_right_divides_each_element_by_the_scalar)
{
  BEGIN_MULTITEST

  const auto vector = create_random_vector3 ();
  auto scalar = rand () / 100.0;
  auto res = vector / scalar;

  EXPECT_EQ (vector.x / scalar, res.x);
  EXPECT_EQ (vector.y / scalar, res.y);
  EXPECT_EQ (vector.z / scalar, res.z);

  END_MULTITEST
}

TEST (Vector3Test, multiplying_two_vectors_multiplies_component_wise)
{
  BEGIN_MULTITEST

  const auto left = create_random_vector3 ();
  const auto right = create_random_vector3 ();
  auto res = left * right;

  EXPECT_EQ (left.x * right.x, res.x);
  EXPECT_EQ (left.y * right.y, res.y);
  EXPECT_EQ (left.z * right.z, res.z);

  END_MULTITEST
}

TEST (Vector3Test, dividing_a_vector_with_zero_throws_division_by_zero_exception)
{
  const auto vector = create_random_vector3 ();
  EXPECT_THROW (vector / 0.0, Math::Vec3d::division_by_zero_exception);
}

TEST (Vector3Test, cross_product_of_two_vector_follows_mathematical_rules)
{
  BEGIN_MULTITEST

  const auto vector_1 = create_random_vector3 ();
  const auto vector_2 = create_random_vector3 ();
  auto res = vector_1.cross (vector_2);

  EXPECT_EQ (vector_1.y * vector_2.z - vector_1.z * vector_2.y, res.x);
  EXPECT_EQ (vector_1.z * vector_2.x - vector_1.x * vector_2.z, res.y);
  EXPECT_EQ (vector_1.x * vector_2.y - vector_1.y * vector_2.x, res.z);

  END_MULTITEST
}

TEST (Vector3Test, dot_product_with_zero_vector_is_zero)
{
  BEGIN_MULTITEST

  const auto vector = create_random_vector3 ();
  const Math::Vec3d zero;
  EXPECT_EQ (0.0, vector.dot (zero));

  END_MULTITEST
}

TEST (Vector3Test, dot_product_of_two_vectors_add_the_product_of_each_component)
{
  BEGIN_MULTITEST

  const auto vector_1 = create_random_vector3 ();
  const auto vector_2 = create_random_vector3 ();

  auto dotprod = vector_1.dot (vector_2);
  auto vec_prod = vector_1 * vector_2;
  EXPECT_EQ (vec_prod.x + vec_prod.y + vec_prod.z, dotprod);

  END_MULTITEST
}

TEST (Vector3Test, multiplying_scalar_to_a_vector_multiplies_each_component_with_the_scalar)
{
  BEGIN_MULTITEST

  const auto vector = create_random_vector3 ();
  auto scalar = rand () / 100.0;
  auto res = vector;

  res *= scalar;

  EXPECT_EQ (vector.x * scalar, res.x);
  EXPECT_EQ (vector.y * scalar, res.y);
  EXPECT_EQ (vector.z * scalar, res.z);

  END_MULTITEST
}

TEST (Vector3Test, dividing_vector_with_a_scalar_divides_each_components_with_the_scalar)
{
  BEGIN_MULTITEST

  const auto vector = create_random_vector3 ();
  auto scalar = rand () / 100.0;
  auto res = vector;

  res /= scalar;

  EXPECT_EQ (vector.x / scalar, res.x);
  EXPECT_EQ (vector.y / scalar, res.y);
  EXPECT_EQ (vector.z / scalar, res.z);

  END_MULTITEST
}

TEST (Vector3Test, multiplying_vector_with_a_vector_multiplies_component_wise)
{
  BEGIN_MULTITEST

  const auto vector = create_random_vector3 ();
  const auto other = create_random_vector3 ();
  auto res = vector;

  res *= other;

  EXPECT_EQ (vector.x * other.x, res.x);
  EXPECT_EQ (vector.y * other.y, res.y);
  EXPECT_EQ (vector.z * other.z, res.z);

  END_MULTITEST
}

TEST (Vector3Test, dividing_vector_with_zero_throws_division_by_zero_exception)
{
  auto vector = create_random_vector3 ();
  EXPECT_THROW (vector /= 0.0, Math::Vec3d::division_by_zero_exception);
}

TEST (Vector3Test, equality_operator_returns_true_for_the_same_object)
{
  BEGIN_MULTITEST

  const auto vector = create_random_vector3 ();
  EXPECT_EQ (vector, vector);

  END_MULTITEST
}

TEST (Vector3Test, equality_operator_returns_true_for_copy)
{
  BEGIN_MULTITEST

  const auto vector = create_random_vector3 ();
  auto copy = vector;

  EXPECT_EQ (vector, copy);

  END_MULTITEST
}

TEST (Vector3Test, equality_operator_returns_true_for_objects_with_equal_elements)
{
  BEGIN_MULTITEST

  auto array = create_double_array_of_size (3);
  const Math::Vec3d vector (array);
  const Math::Vec3d other (array);

  EXPECT_EQ (vector, other);

  delete[] array;
  END_MULTITEST
}

TEST (Vector3Test, equality_operator_returns_false_for_object_with_different_x)
{
  const Math::Vec3d vector (3.2, 5.4, 1.2);
  const Math::Vec3d other (5.6, 5.4, 1.2);
  EXPECT_FALSE (vector == other);
}

TEST (Vector3Test, equality_operator_returns_false_for_object_with_different_y)
{
  const Math::Vec3d vector (3.2, 5.4, 1.2);
  const Math::Vec3d other (3.2, 1.4, 1.2);
  EXPECT_FALSE (vector == other);
}

TEST (Vector3Test, equality_operator_returns_false_for_object_with_different_z)
{
  const Math::Vec3d vector (3.2, 5.4, 1.2);
  const Math::Vec3d other (3.2, 5.4, 3.7);
  EXPECT_FALSE (vector == other);
}

TEST (Vector3Test, inequality_operator_returns_false_for_the_same_object)
{
  BEGIN_MULTITEST

  const auto vector = create_random_vector3 ();
  EXPECT_FALSE (vector != vector);

  END_MULTITEST
}

TEST (Vector3Test, inequality_operator_returns_false_for_copy)
{
  BEGIN_MULTITEST

  const auto vector = create_random_vector3 ();
  auto copy = vector;
  EXPECT_FALSE (vector != copy);

  END_MULTITEST
}

TEST (Vector3Test, inequality_operator_returns_false)
{
  const Math::Vec3d vector (3.2, 5.4, 1.2);
  const Math::Vec3d other (3.2, 5.4, 1.2);
  EXPECT_FALSE (vector != other);
}

TEST (Vector3Test, inequality_operator_returns_true_for_object_with_different_x)
{
  const Math::Vec3d vector (3.2, 5.4, 1.2);
  const Math::Vec3d other (5.6, 5.4, 1.2);
  EXPECT_NE (vector, other);
}

TEST (Vector3Test, inequality_operator_returns_true_for_object_with_different_y)
{
  const Math::Vec3d vector (3.2, 5.4, 1.2);
  const Math::Vec3d other (3.2, 1.4, 1.2);
  EXPECT_NE (vector, other);
}

TEST (Vector3Test, inequality_operator_returns_true_for_object_with_different_z)
{
  const Math::Vec3d vector (3.2, 5.4, 1.2);
  const Math::Vec3d other (3.2, 5.4, 3.7);
  EXPECT_NE (vector, other);
}

TEST (Vector3Test, vector_can_be_casted_c_style)
{
  const Math::Vec3d vector;
  auto pointer = (const double *) vector;
  EXPECT_EQ (pointer[0], vector.x);
  EXPECT_EQ (pointer[1], vector.y);
  EXPECT_EQ (pointer[2], vector.z);
}

TEST (Vector3Test, vector_can_be_statically_casted)
{
  const Math::Vec3d vector;
  auto pointer = static_cast<const double*> (vector);
  EXPECT_EQ (pointer[0], vector.x);
  EXPECT_EQ (pointer[1], vector.y);
  EXPECT_EQ (pointer[2], vector.z);
}

TEST (Vector3Test, casted_vector_manipulates_the_object)
{
  Math::Vec3d vector;
  auto pointer = static_cast<double*> (vector);
  ++pointer[0];
  EXPECT_EQ (vector.x, pointer[0]);
  EXPECT_EQ (vector.y, pointer[1]);
  EXPECT_EQ (vector.z, pointer[2]);
}

TEST (Vector3Test, othonormal_basis_with_zero_vector_throws_can_not_make_orthonormal_basis_with_zero_vector_exception)
{
  Math::Vec3d vec1 (3.0, 5.0, 7.0);
  Math::Vec3d vec2 (7.0, 9.0, 17.0);
  Math::Vec3d zero (0.0, 0.0, 0.0);

  EXPECT_THROW (Math::Vec3d::generateOrthonormalBasis (zero, vec2, vec1), Math::Vec3d::can_not_make_orthonormal_basis_with_zero_vector_exception);
  EXPECT_THROW (Math::Vec3d::generateOrthonormalBasis (vec1, zero, vec2), Math::Vec3d::can_not_make_orthonormal_basis_with_zero_vector_exception);
  EXPECT_THROW (Math::Vec3d::generateOrthonormalBasis (vec1, vec2, zero), Math::Vec3d::can_not_make_orthonormal_basis_with_zero_vector_exception);
}

TEST (Vector3Test, orthonormal_basis_with_equal_vectors_throws_can_not_make_orthonormal_basis_with_equal_vectors_exception)
{
  Math::Vec3d vec1 (3.0, 5.0, 7.0);
  Math::Vec3d vec2 (7.0, 9.0, 17.0);
  EXPECT_THROW (Math::Vec3d::generateOrthonormalBasis (vec1, vec2, vec1), Math::Vec3d::can_not_make_orthonormal_basis_with_equal_vectors_exception);
  EXPECT_THROW (Math::Vec3d::generateOrthonormalBasis (vec1, vec2, vec2), Math::Vec3d::can_not_make_orthonormal_basis_with_equal_vectors_exception);
  EXPECT_THROW (Math::Vec3d::generateOrthonormalBasis (vec1, vec1, vec2), Math::Vec3d::can_not_make_orthonormal_basis_with_equal_vectors_exception);
}

TEST (Vector3Test, orthonormal_basis_gives_vectors_of_length_1)
{
  BEGIN_MULTITEST

  auto vec1 = create_random_vector3 ();
  auto vec2 = create_random_vector3 ();
  auto vec3 = create_random_vector3 ();

  Math::Vec3d::generateOrthonormalBasis (vec1, vec2, vec3);

  EXPECT_FLOAT_EQ (1, vec1.length ());
  EXPECT_FLOAT_EQ (1, vec2.length ());
  EXPECT_FLOAT_EQ (1, vec3.length ());

  END_MULTITEST
}

TEST (Vector3Test, orthonormal_basis_gives_dot_products_of_zero)
{
  BEGIN_MULTITEST

  auto vec1 = create_random_vector3 ();
  auto vec2 = create_random_vector3 ();
  auto vec3 = create_random_vector3 ();

  Math::Vec3d::generateOrthonormalBasis (vec1, vec2, vec3);

  EXPECT_NEAR (0, vec1.dot (vec2), PRECISION);
  EXPECT_NEAR (0, vec1.dot (vec3), PRECISION);
  EXPECT_NEAR (0, vec2.dot (vec3), PRECISION);

  END_MULTITEST
}

const Math::Vec3d create_random_vector3 ()
{
  auto array = create_double_array_of_size (3);
  Math::Vec3d vector (array);

  delete [] array;
  return vector;
}
