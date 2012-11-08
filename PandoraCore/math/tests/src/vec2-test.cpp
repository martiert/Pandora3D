#include "test-helpers.h"

#include <vector2.h>
#include <gtest/gtest.h>

#include <cmath>

class Vector2Test : public ::testing::Test
{
  protected:
    void SetUp();
    void TearDown();

    double * array;

    Math::Vec2d empty_vector;
    Math::Vec2d argument_made_vector;
    Math::Vec2d array_assigned_vector;
    Math::Vec2d random_vector;
};

void Vector2Test::SetUp()
{
  array = create_double_array_of_size(2);
  argument_made_vector = Math::Vec2d(array[0], array[1]);
  random_vector = Math::Vec2d(array);
  array_assigned_vector = array;
}

void Vector2Test::TearDown()
{
  delete[] array;
}

const Math::Vec2d create_random_vector2();

TEST_F(Vector2Test, empty_constructor_gives_zero_vector)
{
  EXPECT_EQ(0.0, empty_vector[0]);
  EXPECT_EQ(0.0, empty_vector[1]);
}

TEST_F(Vector2Test, constructing_a_vector_with_two_arguments_populates_the_vector_with_those_arguments)
{
  EXPECT_EQ(array[0], argument_made_vector[0]);
  EXPECT_EQ(array[1], argument_made_vector[1]);
}

TEST_F(Vector2Test, constructing_a_vector_with_a_array_of_two_elements_populates_vector_with_the_array)
{
  EXPECT_EQ(array[0], random_vector[0]);
  EXPECT_EQ(array[1], random_vector[1]);
}

TEST_F(Vector2Test, assigning_a_vector_to_an_array_populates_vector_with_given_array)
{
  EXPECT_EQ(array[0], array_assigned_vector[0]);
  EXPECT_EQ(array[1], array_assigned_vector[1]);
}

TEST_F(Vector2Test, assigning_a_vector_to_another_vector_populates_the_vector)
{
  auto copy = random_vector;

  EXPECT_EQ(random_vector[0], copy[0]);
  EXPECT_EQ(random_vector[1], copy[1]);
}

TEST_F(Vector2Test, copy_constructor_makes_a_hard_copy)
{
  auto copy(random_vector);

  EXPECT_EQ(random_vector[0], copy[0]);
  EXPECT_EQ(random_vector[1], copy[1]);
  ++copy[0];
  EXPECT_NE(random_vector[0], copy[0]);
}

TEST_F(Vector2Test, index_operator_maps_to_x_and_y)
{
  EXPECT_EQ(random_vector[0], random_vector[0]);
  EXPECT_EQ(random_vector[1], random_vector[1]);

  random_vector[0] += 4.2;
  EXPECT_EQ(random_vector[0], random_vector[0]);
}

TEST_F(Vector2Test, zero_vector_gives_zero_length)
{
  EXPECT_EQ(0.0, length(empty_vector));
  EXPECT_EQ(0.0, lengthSquared(empty_vector));
}

TEST_F(Vector2Test, length_of_vector_follows_mathematical_rules)
{
  auto squaredLength = random_vector[0] * random_vector[0] + random_vector[1] * random_vector[1];
  EXPECT_EQ(squaredLength, lengthSquared(random_vector));
  EXPECT_EQ(std::sqrt(squaredLength), length(random_vector));
}

TEST_F(Vector2Test, accessing_element_outside_vector_kills_program)
{
  EXPECT_DEATH(random_vector[2], "Index operator out of range");
}

TEST_F(Vector2Test, accessing_element_outside_const_vector_kills_program)
{
  const Math::Vec2d vector;
  EXPECT_DEATH(vector[2], "Index operator out of range");
}

TEST_F(Vector2Test, trying_to_normalize_zero_vector_kills_program)
{
  EXPECT_DEATH(normalize(empty_vector), "Can not normalize zero vector");
}

TEST_F(Vector2Test, normalize_non_zero_vector_gives_new_length_of_1)
{
  normalize(random_vector);
  EXPECT_FLOAT_EQ(1.0, length(random_vector));
}

TEST_F(Vector2Test, vector_negation_negates_each_component)
{
  auto neg = -random_vector;

  EXPECT_EQ(-random_vector[0], neg[0]);
  EXPECT_EQ(-random_vector[1], neg[1]);
}

TEST_F(Vector2Test, adding_two_vectors_adds_each_component)
{
  const auto vector_1 = create_random_vector2();
  const auto vector_2 = create_random_vector2();
  auto res = vector_1 + vector_2;

  EXPECT_EQ(vector_1[0] + vector_2[0], res[0]);
  EXPECT_EQ(vector_1[1] + vector_2[1], res[1]);
}

TEST_F(Vector2Test, subtracting_two_vectors_subtracts_each_component)
{
  const auto vector_1 = create_random_vector2();
  const auto vector_2 = create_random_vector2();
  auto res = vector_1 - vector_2;

  EXPECT_EQ(vector_1[0] - vector_2[0], res[0]);
  EXPECT_EQ(vector_1[1] - vector_2[1], res[1]);
}

TEST_F(Vector2Test, multiplying_vector_with_scalar_from_right_multiplies_each_component)
{
  const auto vector = create_random_vector2();
  auto res = vector * 2.3;

  EXPECT_EQ(vector[0] * 2.3, res[0]);
  EXPECT_EQ(vector[1] * 2.3, res[1]);
}

TEST_F(Vector2Test, dividing_vector_with_scalar_divides_each_component)
{
  const auto vector = create_random_vector2();
  double scalar = rand() / 100.0;
  auto res = vector / scalar;

  EXPECT_EQ(vector[0] / scalar, res[0]);
  EXPECT_EQ(vector[1] / scalar, res[1]);
}

TEST_F(Vector2Test, multiplying_vector_with_scalar_from_left_multiplies_each_component)
{
  const auto vector = create_random_vector2();
  auto scalar = rand() / 100.0;
  auto res = scalar * vector;

  EXPECT_EQ(vector[0] * scalar, res[0]);
  EXPECT_EQ(vector[1] * scalar, res[1]);
}

TEST_F(Vector2Test, multiplying_two_vectors_multiplies_component_wise)
{
  const auto vec1 = create_random_vector2();
  const auto vec2 = create_random_vector2();
  auto res = vec1 * vec2;

  EXPECT_EQ(vec1[0] * vec2[0], res[0]);
  EXPECT_EQ(vec1[1] * vec2[1], res[1]);
}

TEST_F(Vector2Test, dot_product_of_two_vectors_gives_the_sum_of_the_vectors_multiplied)
{
  const auto vec1 = create_random_vector2();
  const auto vec2 = create_random_vector2();

  auto dotProd = dot(vec1, vec2);
  auto mult = vec1 * vec2;
  EXPECT_EQ(mult[0] + mult[1], dotProd);
}

TEST_F(Vector2Test, perp_vector_is_zero_vector_for_zero_vector)
{
  const Math::Vec2d vector;
  auto perp_vec = perp(vector);

  EXPECT_EQ(0.0, perp_vec[0]);
  EXPECT_EQ(0.0, perp_vec[1]);
}

TEST_F(Vector2Test, perpendicular_vector_of_non_zero_vector_is_non_zero)
{
  const auto vector = create_random_vector2();
  auto perp_vec = perp(vector);

  EXPECT_TRUE(perp_vec[0] != 0.0 || perp_vec[1] != 0.0);
}

TEST_F(Vector2Test, dot_product_with_perp_vector_is_zero)
{
  const auto vector = create_random_vector2();
  auto perp_vec = perp(vector);

  EXPECT_EQ(0.0, dot(vector, perp_vec));
  EXPECT_EQ(0.0, dot(perp_vec, vector));
}

TEST_F(Vector2Test, addition_to_vector_gives_same_as_the_vectors_added)
{
  const auto vec1 = create_random_vector2();
  auto vec2 = create_random_vector2();

  auto vec3 = vec1 + vec2;
  vec2 += vec1;

  EXPECT_EQ(vec3[0], vec2[0]);
  EXPECT_EQ(vec3[1], vec2[1]);
}

TEST_F(Vector2Test, subtraction_from_vector_gives_same_as_vectors_subtracted)
{
  const auto vec1 = create_random_vector2();
  auto vec2 = create_random_vector2();

  auto vec3 = vec2 - vec1;
  vec2 -= vec1;

  EXPECT_EQ(vec3[0], vec2[0]);
  EXPECT_EQ(vec3[1], vec2[1]);
}

TEST_F(Vector2Test, multiplication_inplace_with_scalar_gives_same_as_vector_times_scalar)
{
  auto vec1 = create_random_vector2();
  auto scalar = rand() / 100.0;

  auto vec2 = vec1 * scalar;
  vec1 *= scalar;

  EXPECT_EQ(vec1[0], vec2[0]);
  EXPECT_EQ(vec1[1], vec2[1]);
}

TEST_F(Vector2Test, multiplication_inplace_with_vector_gives_same_as_vector_times_vector)
{
  const auto vec1 = create_random_vector2();
  auto vec2 = create_random_vector2();

  auto vec3 = vec1 * vec2;
  vec2 *= vec1;

  EXPECT_EQ(vec3[0], vec2[0]);
  EXPECT_EQ(vec3[1], vec2[1]);
}

TEST_F(Vector2Test, division_with_zero_kills_program)
{
  EXPECT_DEATH(random_vector /= 0.0, "Can not divide vector by zero");
}

TEST_F(Vector2Test, division_inplace_with_with_scalar_gives_same_as_vector_divided_by_scalar)
{
  auto vec1 = create_random_vector2();
  auto scalar = rand() / 100.0;

  auto vec2 = vec1 / scalar;
  vec1 /= scalar;

  EXPECT_EQ(vec1[0], vec2[0]);
  EXPECT_EQ(vec1[1], vec2[1]);
}

TEST_F(Vector2Test, inplace_arithmetic_returns_ref_to_self)
{
  auto vec1 = create_random_vector2();
  auto vec2 = create_random_vector2();
  auto tmp = rand() / 100.0;

  Math::Vec2d *res;

  res = &(vec1 += vec2);
  EXPECT_EQ(&vec1, res);

  res = &(vec2 -= vec1);
  EXPECT_EQ(&vec2, res);

  res = &(vec1 *= vec2);
  EXPECT_EQ(&vec1, res);

  res = &(vec2 *= tmp);
  EXPECT_EQ(&vec2, res);

  res = &(vec1 /= tmp);
  EXPECT_EQ(&vec1, res);
}

TEST_F(Vector2Test, equality_operator_gives_true_for_same_vector)
{
  const auto vector = create_random_vector2();
  EXPECT_EQ(vector, vector);
}

TEST_F(Vector2Test, equality_operator_gives_true_for_copied_vector)
{
  const auto vector = create_random_vector2();
  auto copy = vector;

  EXPECT_EQ(copy, vector);
}

TEST_F(Vector2Test, equality_operator_gives_true_for_vectors_with_equal_components)
{
  auto array = create_double_array_of_size(2);
  const Math::Vec2d vector(array);
  const Math::Vec2d same(array);

  EXPECT_EQ(vector, same);

  delete[] array;
}

TEST_F(Vector2Test, equality_operator_gives_false_for_unequal_x)
{
  const Math::Vec2d vector(3.2, 1.8);
  const Math::Vec2d different(3.0, 1.8);
  EXPECT_FALSE(vector == different);
}

TEST_F(Vector2Test, equality_operator_gives_false_for_unequal_y)
{
  const Math::Vec2d vector(3.2, 1.8);
  const Math::Vec2d different(3.2, 2.8);
  EXPECT_FALSE(vector == different);
}

TEST_F(Vector2Test, non_equal_operator_gives_true_for_unequal_x)
{
  const Math::Vec2d vector(3.2, 1.8);
  const Math::Vec2d different(3.0, 1.8);
  EXPECT_NE(vector, different);
}

TEST_F(Vector2Test, non_equal_operator_gives_true_for_unequal_y)
{
  const Math::Vec2d vector(3.2, 1.8);
  const Math::Vec2d different(3.2, 2.8);
  EXPECT_NE(vector, different);
}

TEST_F(Vector2Test, non_equal_operator_gives_false_for_same_vector)
{
  const auto vector = create_random_vector2();
  EXPECT_FALSE(vector != vector);
}

TEST_F(Vector2Test, non_equal_operator_gives_false_for_copy)
{
  const auto vector = create_random_vector2();
  auto copy = vector;
  EXPECT_FALSE(copy != vector);
}

TEST_F(Vector2Test, non_equal_operator_gives_false_for_vectors_with_equal_components)
{
  auto array = create_double_array_of_size(2);
  const Math::Vec2d vector(array);
  const Math::Vec2d same(array);
  EXPECT_FALSE(vector != same);

  delete[] array;
}

TEST_F(Vector2Test, creating_orthonormal_basis_with_zero_vector_kills_program)
{
  EXPECT_DEATH(generateOrthonormalBasis(random_vector, empty_vector),
               "Can not make orthonormal basis from a zero vector");
  EXPECT_DEATH(generateOrthonormalBasis(empty_vector, random_vector),
               "Can not make orthonormal basis from a zero vector");
}

TEST_F(Vector2Test, creating_orthonormal_basis_with_same_vector_kills_program)
{
  EXPECT_DEATH(generateOrthonormalBasis(random_vector, random_vector),
               "Can not make orthonormal basis from equal vectors");
}

TEST_F(Vector2Test, orthonormal_basis_creates_perpendicular_vectors_of_length_1)
{
  auto vec1 = create_random_vector2();
  auto vec2 = create_random_vector2();

  if (vec1 != vec2) {
    generateOrthonormalBasis(vec1, vec2);
    EXPECT_NEAR(0.0, dot(vec1, vec2), PRECISION);
    EXPECT_NEAR(1.0, length(vec1), PRECISION);
    EXPECT_NEAR(1.0, length(vec2), PRECISION);
  }
}

const Math::Vec2d create_random_vector2()
{
  auto array = create_double_array_of_size(2);
  Math::Vec2d vector(array);

  delete [] array;
  return vector;
}
