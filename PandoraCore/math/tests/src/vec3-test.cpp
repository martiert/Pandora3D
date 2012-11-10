#include "test-helpers.h"

#include <vector3.h>
#include <gtest/gtest.h>

#include <cmath>

class Vector3Test : public ::testing::Test
{
  protected:
    void SetUp();
    void TearDown();

    double * array;

    double scalar;
    Math::Vec3d zero_vector;
    Math::Vec3d random_vector;
    Math::Vec3d random_vector2;
    Math::Vec3d random_vector3;
};

void Vector3Test::SetUp()
{
  scalar = rand() / 100.0;
  array = create_double_array_of_size(3);
  random_vector = Math::Vec3d(array);

  auto tmp = create_double_array_of_size(3);
  random_vector2 = Math::Vec3d(tmp);
  delete[] tmp;

  tmp = create_double_array_of_size(3);
  random_vector3 = Math::Vec3d(tmp);
  delete[] tmp;
}

void Vector3Test::TearDown()
{
  delete[] array;
}

TEST_F(Vector3Test, empty_constructor_gives_zero_vector)
{
  Math::Vec3d zero_vector;
  EXPECT_EQ(0.0, zero_vector[0]);
  EXPECT_EQ(0.0, zero_vector[1]);
  EXPECT_EQ(0.0, zero_vector[2]);
}

TEST_F(Vector3Test, constructing_a_vector_with_three_arguments_populates_the_vector_with_those_arguments)
{
  const Math::Vec3d vector({0.1, 2.3, 3.7});
  EXPECT_EQ(0.1, vector[0]);
  EXPECT_EQ(2.3, vector[1]);
  EXPECT_EQ(3.7, vector[2]);
}

TEST_F(Vector3Test, constructing_a_vector_with_an_array_of_three_elements_populates_vector_with_the_array)
{
  EXPECT_EQ(array[0], random_vector[0]);
  EXPECT_EQ(array[1], random_vector[1]);
  EXPECT_EQ(array[2], random_vector[2]);
}

TEST_F(Vector3Test, assigning_a_vector_to_an_array_populates_vector_with_given_array)
{
  Math::Vec3d array_assigned_vector(array);

  EXPECT_EQ(array[0], array_assigned_vector[0]);
  EXPECT_EQ(array[1], array_assigned_vector[1]);
  EXPECT_EQ(array[2], array_assigned_vector[2]);
}

TEST_F(Vector3Test, assigning_a_vector_to_another_vector_populates_the_vector)
{
  auto random_vector_copy = random_vector;

  EXPECT_EQ(random_vector[0], random_vector_copy[0]);
  EXPECT_EQ(random_vector[1], random_vector_copy[1]);
  EXPECT_EQ(random_vector[2], random_vector_copy[2]);
}

TEST_F(Vector3Test, copy_constructor_makes_hard_copy)
{
  auto copy(random_vector);

  EXPECT_EQ(random_vector[0], copy[0]);
  EXPECT_EQ(random_vector[1], copy[1]);
  EXPECT_EQ(random_vector[2], copy[2]);
  ++copy[0];
  EXPECT_NE(random_vector[0], copy[0]);
}

TEST_F(Vector3Test, length_of_zero_vector_is_zero)
{
  EXPECT_EQ(0.0, vector_length(zero_vector));
  EXPECT_EQ(0.0, vector_length_squared(zero_vector));
}

TEST_F(Vector3Test, normalize_vector_gives_length_of_1)
{
  normalize_vector(random_vector);
  EXPECT_FLOAT_EQ(1.0, vector_length(random_vector));
}

TEST_F(Vector3Test, negating_a_vector_returns_the_negation_of_each_element)
{
  auto negated = -random_vector;

  EXPECT_EQ(-random_vector[0], negated[0]);
  EXPECT_EQ(-random_vector[1], negated[1]);
  EXPECT_EQ(-random_vector[2], negated[2]);
}

TEST_F(Vector3Test, adding_two_vectors_adds_the_vectors_by_elements)
{
  auto res = random_vector + random_vector2;

  EXPECT_EQ(random_vector[0] + random_vector2[0], res[0]);
  EXPECT_EQ(random_vector[1] + random_vector2[1], res[1]);
  EXPECT_EQ(random_vector[2] + random_vector2[2], res[2]);
}

TEST_F(Vector3Test, subtracting_two_vectors_subtracts_the_vectors_by_elements)
{
  auto res = random_vector - random_vector2;

  EXPECT_EQ(random_vector[0] - random_vector2[0], res[0]);
  EXPECT_EQ(random_vector[1] - random_vector2[1], res[1]);
  EXPECT_EQ(random_vector[2] - random_vector2[2], res[2]);
}

TEST_F(Vector3Test, multiplying_two_vectors_multiplies_component_wise)
{
  auto res = random_vector * random_vector2;

  EXPECT_EQ(random_vector[0] * random_vector2[0], res[0]);
  EXPECT_EQ(random_vector[1] * random_vector2[1], res[1]);
  EXPECT_EQ(random_vector[2] * random_vector2[2], res[2]);
}

TEST_F(Vector3Test, multiplying_vector_with_scalar_from_right_multiplies_each_element_by_the_scalar)
{
  auto res = random_vector * scalar;

  EXPECT_EQ(random_vector[0] * scalar, res[0]);
  EXPECT_EQ(random_vector[1] * scalar, res[1]);
  EXPECT_EQ(random_vector[2] * scalar, res[2]);
}

TEST_F(Vector3Test, multiplying_vector_with_scalar_from_left_multiplies_each_element_by_the_scalar)
{
  auto res = scalar * random_vector;

  EXPECT_EQ(random_vector[0] * scalar, res[0]);
  EXPECT_EQ(random_vector[1] * scalar, res[1]);
  EXPECT_EQ(random_vector[2] * scalar, res[2]);
}

TEST_F(Vector3Test, dividing_vector_with_scalar_divides_each_element_by_the_scalar)
{
  auto res = random_vector / scalar;

  EXPECT_EQ(random_vector[0] / scalar, res[0]);
  EXPECT_EQ(random_vector[1] / scalar, res[1]);
  EXPECT_EQ(random_vector[2] / scalar, res[2]);
}

TEST_F(Vector3Test, adding_a_vector_to_a_vector_adds_element_wise)
{
  auto random_vector_copy = random_vector;
  random_vector_copy += random_vector2;

  EXPECT_EQ(random_vector[0] + random_vector2[0], random_vector_copy[0]);
  EXPECT_EQ(random_vector[1] + random_vector2[1], random_vector_copy[1]);
  EXPECT_EQ(random_vector[2] + random_vector2[2], random_vector_copy[2]);
}

TEST_F(Vector3Test, subtracting_a_vector_from_a_vector_subtracts_element_wise)
{
  auto random_vector_copy = random_vector;
  random_vector_copy -= random_vector2;

  EXPECT_EQ(random_vector[0] - random_vector2[0], random_vector_copy[0]);
  EXPECT_EQ(random_vector[1] - random_vector2[1], random_vector_copy[1]);
  EXPECT_EQ(random_vector[2] - random_vector2[2], random_vector_copy[2]);
}

TEST_F(Vector3Test, multiplying_scalar_to_a_vector_multiplies_each_component_with_the_scalar)
{
  auto random_vector_copy = random_vector;
  random_vector_copy *= scalar;

  EXPECT_EQ(random_vector[0] * scalar, random_vector_copy[0]);
  EXPECT_EQ(random_vector[1] * scalar, random_vector_copy[1]);
  EXPECT_EQ(random_vector[2] * scalar, random_vector_copy[2]);
}

TEST_F(Vector3Test, dividing_vector_with_a_scalar_divides_each_components_with_the_scalar)
{
  auto random_vector_copy = random_vector;
  random_vector_copy /= scalar;

  EXPECT_EQ(random_vector[0] / scalar, random_vector_copy[0]);
  EXPECT_EQ(random_vector[1] / scalar, random_vector_copy[1]);
  EXPECT_EQ(random_vector[2] / scalar, random_vector_copy[2]);
}

TEST_F(Vector3Test, multiplying_vector_with_a_vector_multiplies_component_wise)
{
  auto random_vector_copy = random_vector;
  random_vector_copy *= random_vector2;

  EXPECT_EQ(random_vector[0] * random_vector2[0], random_vector_copy[0]);
  EXPECT_EQ(random_vector[1] * random_vector2[1], random_vector_copy[1]);
  EXPECT_EQ(random_vector[2] * random_vector2[2], random_vector_copy[2]);
}

TEST_F(Vector3Test, dot_product_with_zero_vector_is_zero)
{
  Math::Vec3d zero_vector;
  EXPECT_EQ(0.0, dot_product(random_vector, zero_vector));
}

TEST_F(Vector3Test, running_through_the_vector_as_a_initializer_list_gives_the_vector_elements)
{
  size_t i = 0;
  const Math::Vec3d vector({4.2, 3.2, 5.6});
  for (auto elem : vector)
    EXPECT_EQ(vector[i++], elem);

  EXPECT_EQ((size_t) 3, i);
}

TEST_F(Vector3Test, using_a_range_based_for_loop_to_change_the_elements)
{
  size_t i = 0;
  const Math::Vec3d vector({4.2, 5.6, 7.8});
  for (auto& elem : random_vector)
    elem = vector[i++];
  EXPECT_EQ(vector, random_vector);
}

TEST_F(Vector3Test, cross_product_of_two_vector_follows_mathematical_rules)
{
  auto res = cross_product(random_vector, random_vector2);

  EXPECT_EQ(random_vector[1] * random_vector2[2] - random_vector[2] * random_vector2[1], res[0]);
  EXPECT_EQ(random_vector[2] * random_vector2[0] - random_vector[0] * random_vector2[2], res[1]);
  EXPECT_EQ(random_vector[0] * random_vector2[1] - random_vector[1] * random_vector2[0], res[2]);
}

TEST_F(Vector3Test, cross_product_creates_vector_which_is_normal_to_the_two_others)
{
  auto res = cross_product(random_vector, random_vector2);
  EXPECT_NEAR(0, dot_product(res, random_vector), PRECISION);
  EXPECT_NEAR(0, dot_product(res, random_vector2), PRECISION);
  EXPECT_NEAR(0, dot_product(random_vector, res), PRECISION);
  EXPECT_NEAR(0, dot_product(random_vector2, res), PRECISION);
}

TEST_F(Vector3Test, equality_operator_returns_true_for_the_same_object)
{
  EXPECT_EQ(random_vector, random_vector);
}

TEST_F(Vector3Test, inequality_operator_returns_false_for_the_same_object)
{
  EXPECT_FALSE(random_vector != random_vector);
}

TEST_F(Vector3Test, orthonormal_basis_gives_vectors_of_length_1)
{
  generate_orthonormal_basis(random_vector, random_vector2, random_vector3);

  EXPECT_FLOAT_EQ(1, vector_length(random_vector));
  EXPECT_FLOAT_EQ(1, vector_length(random_vector2));
  EXPECT_FLOAT_EQ(1, vector_length(random_vector3));
}

TEST_F(Vector3Test, orthonormal_basis_gives_dot_products_of_zero)
{
  generate_orthonormal_basis(random_vector, random_vector2, random_vector3);

  EXPECT_NEAR(0, dot_product(random_vector, random_vector2), PRECISION);
  EXPECT_NEAR(0, dot_product(random_vector, random_vector3), PRECISION);
  EXPECT_NEAR(0, dot_product(random_vector2, random_vector3), PRECISION);
}

TEST_F(Vector3Test, dot_product_of_two_vectors_add_the_product_of_each_component)
{
  auto dotprod = dot_product(random_vector, random_vector2);
  auto vec_prod = random_vector * random_vector2;
  EXPECT_EQ(vec_prod[0] + vec_prod[1] + vec_prod[2], dotprod);
}

TEST_F(Vector3Test, using_an_out_of_range_index_asserts)
{
  EXPECT_DEATH(random_vector[4], "Index operator out of range");
}

TEST_F(Vector3Test, using_an_out_of_range_index_on_const_vector_asserts)
{
  const Math::Vec3d const_vector;
  EXPECT_DEATH(const_vector[4], "Index operator out of range");
}

TEST_F(Vector3Test, length_of_vector_follows_mathematical_rules)
{
  auto len_squared = (random_vector[0]*random_vector[0] + random_vector[1]*random_vector[1] + random_vector[2]*random_vector[2]);
  EXPECT_EQ(std::sqrt(len_squared), vector_length(random_vector));
  EXPECT_EQ(len_squared, vector_length_squared(random_vector));
}

TEST_F(Vector3Test, normalizing_a_zero_vector_asserts)
{
  EXPECT_DEATH(normalize_vector(zero_vector), "Can not normalize zero vector");
}

TEST_F(Vector3Test, dividing_vector_with_0_asserts)
{
  EXPECT_DEATH(random_vector /= (double) 0, "Can not divide vector by zero");
}

TEST_F(Vector3Test, equality_operator_returns_true_for_copy)
{
  auto copy = random_vector;

  EXPECT_EQ(random_vector, copy);
}

TEST_F(Vector3Test, equality_operator_returns_true_for_objects_with_equal_elements)
{
  const Math::Vec3d other(array);

  EXPECT_EQ(random_vector, other);
}

TEST_F(Vector3Test, equality_operator_returns_false_for_object_with_different_x)
{
  const Math::Vec3d vector({3.2, 5.4, 1.2});
  const Math::Vec3d other({5.6, 5.4, 1.2});
  EXPECT_FALSE(vector == other);
}

TEST_F(Vector3Test, equality_operator_returns_false_for_object_with_different_y)
{
  const Math::Vec3d vector({3.2, 5.4, 1.2});
  const Math::Vec3d other({3.2, 1.4, 1.2});
  EXPECT_FALSE(vector == other);
}

TEST_F(Vector3Test, equality_operator_returns_false_for_object_with_different_z)
{
  const Math::Vec3d vector({3.2, 5.4, 1.2});
  const Math::Vec3d other({3.2, 5.4, 3.7});
  EXPECT_FALSE(vector == other);
}

TEST_F(Vector3Test, inequality_operator_returns_false_for_copy)
{
  auto random_vector_copy = random_vector;
  EXPECT_FALSE(random_vector != random_vector_copy);
}

TEST_F(Vector3Test, inequality_operator_returns_false)
{
  const Math::Vec3d vector({3.2, 5.4, 1.2});
  const Math::Vec3d other({3.2, 5.4, 1.2});
  EXPECT_FALSE(vector != other);
}

TEST_F(Vector3Test, inequality_operator_returns_true_for_object_with_different_x)
{
  const Math::Vec3d vector({3.2, 5.4, 1.2});
  const Math::Vec3d other({5.6, 5.4, 1.2});
  EXPECT_NE(vector, other);
}

TEST_F(Vector3Test, inequality_operator_returns_true_for_object_with_different_y)
{
  const Math::Vec3d vector({3.2, 5.4, 1.2});
  const Math::Vec3d other({3.2, 1.4, 1.2});
  EXPECT_NE(vector, other);
}

TEST_F(Vector3Test, inequality_operator_returns_true_for_object_with_different_z)
{
  const Math::Vec3d vector({3.2, 5.4, 1.2});
  const Math::Vec3d other({3.2, 5.4, 3.7});
  EXPECT_NE(vector, other);
}

TEST_F(Vector3Test, orthonormalizing_with_zero_vector_asserts)
{
  EXPECT_DEATH(generate_orthonormal_basis(zero_vector, random_vector, random_vector2),
               "Can not make orthonormal basis with zero vector");
  EXPECT_DEATH(generate_orthonormal_basis(random_vector, zero_vector, random_vector2),
               "Can not make orthonormal basis with zero vector");
  EXPECT_DEATH(generate_orthonormal_basis(random_vector, random_vector2, zero_vector),
               "Can not make orthonormal basis with zero vector");
}

TEST_F(Vector3Test, ortonormalizing_with_equal_vectors_asserts)
{
  EXPECT_DEATH(generate_orthonormal_basis(random_vector, random_vector, random_vector),
               "Can not make orthonormal basis with equal vectors");
  EXPECT_DEATH(generate_orthonormal_basis(random_vector2, random_vector, random_vector),
               "Can not make orthonormal basis with equal vectors");
  EXPECT_DEATH(generate_orthonormal_basis(random_vector, random_vector2, random_vector),
               "Can not make orthonormal basis with equal vectors");
  EXPECT_DEATH(generate_orthonormal_basis(random_vector, random_vector, random_vector2),
               "Can not make orthonormal basis with equal vectors");
}
