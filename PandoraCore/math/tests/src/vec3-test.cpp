#include "test-helpers.h"

#include <vector3.h>
#include <gtest/gtest.h>

#include <cmath>

class Vector3Test : public ::testing::Test
{
  protected:
    void SetUp ();
    void TearDown ();

    double * array;

    double scalar;
    Math::Vec3d empty_vector;
    Math::Vec3d argument_made_vector;
    Math::Vec3d array_assigned_vector;
    Math::Vec3d random_vector;
    Math::Vec3d random_vector2;
    Math::Vec3d random_vector3;
    Math::Vec3d random_vector_copy;
};

void Vector3Test::SetUp ()
{
  scalar = rand () / 100.0;
  array = create_double_array_of_size (3);
  argument_made_vector = Math::Vec3d (array[0], array[1], array[2]);
  random_vector = Math::Vec3d (array);
  array_assigned_vector = array;

  auto tmp = create_double_array_of_size (3);
  random_vector2 = Math::Vec3d (tmp);
  delete[] tmp;

  tmp = create_double_array_of_size (3);
  random_vector3 = Math::Vec3d (tmp);
  delete[] tmp;

  random_vector_copy = random_vector;
}

void Vector3Test::TearDown ()
{
  delete[] array;
}

const Math::Vec3d create_random_vector3 ();

TEST_F (Vector3Test, empty_constructor_gives_zero_vector)
{
  EXPECT_EQ (0.0, empty_vector.x);
  EXPECT_EQ (0.0, empty_vector.y);
  EXPECT_EQ (0.0, empty_vector.z);
}

TEST_F (Vector3Test, constructing_a_vector_with_three_arguments_populates_the_vector_with_those_arguments)
{
  const Math::Vec3d vector (0.1, 2.3, 3.7);
  EXPECT_EQ (0.1, vector.x);
  EXPECT_EQ (2.3, vector.y);
  EXPECT_EQ (3.7, vector.z);
}

TEST_F (Vector3Test, constructing_a_vector_with_an_array_of_three_elements_populates_vector_with_the_array)
{
  EXPECT_EQ (array[0], random_vector.x);
  EXPECT_EQ (array[1], random_vector.y);
  EXPECT_EQ (array[2], random_vector.z);
}

TEST_F (Vector3Test, assigning_a_vector_to_an_array_populates_vector_with_given_array)
{
  EXPECT_EQ (array[0], array_assigned_vector.x);
  EXPECT_EQ (array[1], array_assigned_vector.y);
  EXPECT_EQ (array[2], array_assigned_vector.z);
}

TEST_F (Vector3Test, assigning_a_vector_to_another_vector_populates_the_vector)
{
  EXPECT_EQ (random_vector.x, random_vector_copy.x);
  EXPECT_EQ (random_vector.y, random_vector_copy.y);
  EXPECT_EQ (random_vector.z, random_vector_copy.z);
}

TEST_F (Vector3Test, copy_constructor_makes_hard_copy)
{
  auto copy (random_vector);

  EXPECT_EQ (random_vector.x, copy.x);
  EXPECT_EQ (random_vector.y, copy.y);
  EXPECT_EQ (random_vector.z, copy.z);
  ++copy.x;
  EXPECT_NE (random_vector.x, copy.x);
}

TEST_F (Vector3Test, index_operator_maps_to_x_y_and_z)
{
  EXPECT_EQ (random_vector.x, random_vector[0]);
  EXPECT_EQ (random_vector.y, random_vector[1]);
  EXPECT_EQ (random_vector.z, random_vector[2]);

  random_vector[1] += 10;
  EXPECT_EQ (random_vector.y, random_vector[1]);
}

TEST_F (Vector3Test, index_operator_maps_for_const_vectors)
{
  EXPECT_EQ (random_vector.x, random_vector[0]);
  EXPECT_EQ (random_vector.y, random_vector[1]);
  EXPECT_EQ (random_vector.z, random_vector[2]);
}

TEST_F (Vector3Test, length_of_zero_vector_is_zero)
{
  EXPECT_EQ (0.0, Math::Vec3d::ZERO.length ());
  EXPECT_EQ (0.0, Math::Vec3d::ZERO.lengthSquared ());
}

TEST_F (Vector3Test, length_of_vector_follows_mathematical_rules)
{
  EXPECT_EQ (std::sqrt (random_vector.x*random_vector.x + random_vector.y*random_vector.y + random_vector.z*random_vector.z), random_vector.length ());
  EXPECT_EQ ((random_vector.x*random_vector.x + random_vector.y*random_vector.y + random_vector.z*random_vector.z), random_vector.lengthSquared ());
}

TEST_F (Vector3Test, normalize_vector_gives_length_of_1)
{
  random_vector.normalize ();
  EXPECT_FLOAT_EQ (1.0, random_vector.length ());
}

TEST_F (Vector3Test, negating_a_vector_returns_the_negation_of_each_element)
{
  auto negated = -random_vector;

  EXPECT_EQ (-random_vector.x, negated.x);
  EXPECT_EQ (-random_vector.y, negated.y);
  EXPECT_EQ (-random_vector.z, negated.z);
}

TEST_F (Vector3Test, adding_two_vectors_adds_the_vectors_by_elements)
{
  auto res = random_vector + random_vector2;

  EXPECT_EQ (random_vector.x + random_vector2.x, res.x);
  EXPECT_EQ (random_vector.y + random_vector2.y, res.y);
  EXPECT_EQ (random_vector.z + random_vector2.z, res.z);
}

TEST_F (Vector3Test, subtracting_two_vectors_subtracts_the_vectors_by_elements)
{
  auto res = random_vector - random_vector2;

  EXPECT_EQ (random_vector.x - random_vector2.x, res.x);
  EXPECT_EQ (random_vector.y - random_vector2.y, res.y);
  EXPECT_EQ (random_vector.z - random_vector2.z, res.z);
}

TEST_F (Vector3Test, adding_a_vector_to_a_vector_adds_element_wise)
{
  random_vector_copy += random_vector2;

  EXPECT_EQ (random_vector.x + random_vector2.x, random_vector_copy.x);
  EXPECT_EQ (random_vector.y + random_vector2.y, random_vector_copy.y);
  EXPECT_EQ (random_vector.z + random_vector2.z, random_vector_copy.z);
}

TEST_F (Vector3Test, subtracting_a_vector_from_a_vector_subtracts_element_wise)
{
  random_vector_copy -= random_vector2;

  EXPECT_EQ (random_vector.x - random_vector2.x, random_vector_copy.x);
  EXPECT_EQ (random_vector.y - random_vector2.y, random_vector_copy.y);
  EXPECT_EQ (random_vector.z - random_vector2.z, random_vector_copy.z);
}

TEST_F (Vector3Test, multiplying_vector_with_scalar_from_right_multiplies_each_element_by_the_scalar)
{
  auto res = random_vector * scalar;

  EXPECT_EQ (random_vector.x * scalar, res.x);
  EXPECT_EQ (random_vector.y * scalar, res.y);
  EXPECT_EQ (random_vector.z * scalar, res.z);
}

TEST_F (Vector3Test, multiplying_vector_with_scalar_from_left_multiplies_each_element_by_the_scalar)
{
  auto res = scalar * random_vector;

  EXPECT_EQ (random_vector.x * scalar, res.x);
  EXPECT_EQ (random_vector.y * scalar, res.y);
  EXPECT_EQ (random_vector.z * scalar, res.z);
}

TEST_F (Vector3Test, dividing_vector_with_scalar_from_right_divides_each_element_by_the_scalar)
{
  auto res = random_vector / scalar;

  EXPECT_EQ (random_vector.x / scalar, res.x);
  EXPECT_EQ (random_vector.y / scalar, res.y);
  EXPECT_EQ (random_vector.z / scalar, res.z);
}

TEST_F (Vector3Test, multiplying_two_vectors_multiplies_component_wise)
{
  auto res = random_vector * random_vector2;

  EXPECT_EQ (random_vector.x * random_vector2.x, res.x);
  EXPECT_EQ (random_vector.y * random_vector2.y, res.y);
  EXPECT_EQ (random_vector.z * random_vector2.z, res.z);
}

TEST_F (Vector3Test, cross_product_of_two_vector_follows_mathematical_rules)
{
  auto res = random_vector.cross (random_vector2);

  EXPECT_EQ (random_vector.y * random_vector2.z - random_vector.z * random_vector2.y, res.x);
  EXPECT_EQ (random_vector.z * random_vector2.x - random_vector.x * random_vector2.z, res.y);
  EXPECT_EQ (random_vector.x * random_vector2.y - random_vector.y * random_vector2.x, res.z);
}

TEST_F (Vector3Test, dot_product_with_zero_vector_is_zero)
{
  EXPECT_EQ (0.0, random_vector.dot (Math::Vec3d::ZERO));
}

TEST_F (Vector3Test, dot_product_of_two_vectors_add_the_product_of_each_component)
{
  auto dotprod = random_vector.dot (random_vector2);
  auto vec_prod = random_vector * random_vector2;
  EXPECT_EQ (vec_prod.x + vec_prod.y + vec_prod.z, dotprod);
}

TEST_F (Vector3Test, multiplying_scalar_to_a_vector_multiplies_each_component_with_the_scalar)
{
  random_vector_copy *= scalar;

  EXPECT_EQ (random_vector.x * scalar, random_vector_copy.x);
  EXPECT_EQ (random_vector.y * scalar, random_vector_copy.y);
  EXPECT_EQ (random_vector.z * scalar, random_vector_copy.z);
}

TEST_F (Vector3Test, dividing_vector_with_a_scalar_divides_each_components_with_the_scalar)
{
  random_vector_copy /= scalar;

  EXPECT_EQ (random_vector.x / scalar, random_vector_copy.x);
  EXPECT_EQ (random_vector.y / scalar, random_vector_copy.y);
  EXPECT_EQ (random_vector.z / scalar, random_vector_copy.z);
}

TEST_F (Vector3Test, multiplying_vector_with_a_vector_multiplies_component_wise)
{
  random_vector_copy *= random_vector2;

  EXPECT_EQ (random_vector.x * random_vector2.x, random_vector_copy.x);
  EXPECT_EQ (random_vector.y * random_vector2.y, random_vector_copy.y);
  EXPECT_EQ (random_vector.z * random_vector2.z, random_vector_copy.z);
}

TEST_F (Vector3Test, equality_operator_returns_true_for_the_same_object)
{
  EXPECT_EQ (random_vector, random_vector);
}

TEST_F (Vector3Test, equality_operator_returns_true_for_copy)
{
  auto copy = random_vector;

  EXPECT_EQ (random_vector, copy);
}

TEST_F (Vector3Test, equality_operator_returns_true_for_objects_with_equal_elements)
{
  const Math::Vec3d other (array);

  EXPECT_EQ (random_vector, other);
}

TEST_F (Vector3Test, equality_operator_returns_false_for_object_with_different_x)
{
  const Math::Vec3d vector (3.2, 5.4, 1.2);
  const Math::Vec3d other (5.6, 5.4, 1.2);
  EXPECT_FALSE (vector == other);
}

TEST_F (Vector3Test, equality_operator_returns_false_for_object_with_different_y)
{
  const Math::Vec3d vector (3.2, 5.4, 1.2);
  const Math::Vec3d other (3.2, 1.4, 1.2);
  EXPECT_FALSE (vector == other);
}

TEST_F (Vector3Test, equality_operator_returns_false_for_object_with_different_z)
{
  const Math::Vec3d vector (3.2, 5.4, 1.2);
  const Math::Vec3d other (3.2, 5.4, 3.7);
  EXPECT_FALSE (vector == other);
}

TEST_F (Vector3Test, inequality_operator_returns_false_for_the_same_object)
{
  EXPECT_FALSE (random_vector != random_vector);
}

TEST_F (Vector3Test, inequality_operator_returns_false_for_copy)
{
  EXPECT_FALSE (random_vector != random_vector_copy);
}

TEST_F (Vector3Test, inequality_operator_returns_false)
{
  const Math::Vec3d vector (3.2, 5.4, 1.2);
  const Math::Vec3d other (3.2, 5.4, 1.2);
  EXPECT_FALSE (vector != other);
}

TEST_F (Vector3Test, inequality_operator_returns_true_for_object_with_different_x)
{
  const Math::Vec3d vector (3.2, 5.4, 1.2);
  const Math::Vec3d other (5.6, 5.4, 1.2);
  EXPECT_NE (vector, other);
}

TEST_F (Vector3Test, inequality_operator_returns_true_for_object_with_different_y)
{
  const Math::Vec3d vector (3.2, 5.4, 1.2);
  const Math::Vec3d other (3.2, 1.4, 1.2);
  EXPECT_NE (vector, other);
}

TEST_F (Vector3Test, inequality_operator_returns_true_for_object_with_different_z)
{
  const Math::Vec3d vector (3.2, 5.4, 1.2);
  const Math::Vec3d other (3.2, 5.4, 3.7);
  EXPECT_NE (vector, other);
}

TEST_F (Vector3Test, vector_can_be_casted_c_style)
{
  auto pointer = (const double *) random_vector;
  EXPECT_EQ (pointer[0], random_vector.x);
  EXPECT_EQ (pointer[1], random_vector.y);
  EXPECT_EQ (pointer[2], random_vector.z);
}

TEST_F (Vector3Test, vector_can_be_statically_casted)
{
  auto pointer = static_cast<const double*> (random_vector);
  EXPECT_EQ (pointer[0], random_vector.x);
  EXPECT_EQ (pointer[1], random_vector.y);
  EXPECT_EQ (pointer[2], random_vector.z);
}

TEST_F (Vector3Test, casted_vector_manipulates_the_object)
{
  auto pointer = static_cast<double*> (random_vector);
  ++pointer[0];
  EXPECT_EQ (random_vector.x, pointer[0]);
  EXPECT_EQ (random_vector.y, pointer[1]);
  EXPECT_EQ (random_vector.z, pointer[2]);
}

TEST_F (Vector3Test, orthonormal_basis_gives_vectors_of_length_1)
{
  Math::Vec3d::generateOrthonormalBasis (random_vector, random_vector2, random_vector3);

  EXPECT_FLOAT_EQ (1, random_vector.length ());
  EXPECT_FLOAT_EQ (1, random_vector2.length ());
  EXPECT_FLOAT_EQ (1, random_vector3.length ());
}

TEST_F (Vector3Test, orthonormal_basis_gives_dot_products_of_zero)
{
  Math::Vec3d::generateOrthonormalBasis (random_vector, random_vector2, random_vector3);

  EXPECT_NEAR (0, random_vector.dot (random_vector2), PRECISION);
  EXPECT_NEAR (0, random_vector.dot (random_vector3), PRECISION);
  EXPECT_NEAR (0, random_vector2.dot (random_vector3), PRECISION);
}

const Math::Vec3d create_random_vector3 ()
{
  auto array = create_double_array_of_size (3);
  Math::Vec3d vector (array);

  delete [] array;
  return vector;
}
