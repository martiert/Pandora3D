#include "test-helpers.h"

#include <vector2.h>
#include <gtest/gtest.h>

#include <cmath>

class Vector2Test : public ::testing::Test
{
  protected:
    void SetUp ();
    void TearDown ();

    double * array;

    Math::Vec2d empty_vector;
    Math::Vec2d argument_made_vector;
    Math::Vec2d array_assigned_vector;
    Math::Vec2d random_vector;
};

void Vector2Test::SetUp ()
{
  array = create_double_array_of_size (2);
  argument_made_vector = Math::Vec2d (array[0], array[1]);
  random_vector = Math::Vec2d (array);
  array_assigned_vector = array;
}

void Vector2Test::TearDown ()
{
  delete[] array;
}

const Math::Vec2d create_random_vector2 ();

TEST_F (Vector2Test, empty_constructor_gives_zero_vector)
{
  EXPECT_EQ (0.0, empty_vector.x);
  EXPECT_EQ (0.0, empty_vector.y);
}

TEST_F (Vector2Test, constructing_a_vector_with_two_arguments_populates_the_vector_with_those_arguments)
{
  EXPECT_EQ (array[0], argument_made_vector.x);
  EXPECT_EQ (array[1], argument_made_vector.y);
}

TEST_F (Vector2Test, constructing_a_vector_with_a_array_of_two_elements_populates_vector_with_the_array)
{
  EXPECT_EQ (array[0], random_vector.x);
  EXPECT_EQ (array[1], random_vector.y);
}

TEST_F (Vector2Test, assigning_a_vector_to_an_array_populates_vector_with_given_array)
{
  EXPECT_EQ (array[0], array_assigned_vector.x);
  EXPECT_EQ (array[1], array_assigned_vector.y);
}

TEST_F (Vector2Test, assigning_a_vector_to_another_vector_populates_the_vector)
{
  auto copy = random_vector;

  EXPECT_EQ (random_vector.x, copy.x);
  EXPECT_EQ (random_vector.y, copy.y);
}

TEST_F (Vector2Test, copy_constructor_makes_a_hard_copy)
{
  auto copy (random_vector);

  EXPECT_EQ (random_vector.x, copy.x);
  EXPECT_EQ (random_vector.y, copy.y);
  ++copy.x;
  EXPECT_NE (random_vector.x, copy.x);
}

TEST_F (Vector2Test, index_operator_maps_to_x_and_y)
{
  EXPECT_EQ (random_vector.x, random_vector[0]);
  EXPECT_EQ (random_vector.y, random_vector[1]);

  random_vector[0] += 4.2;
  EXPECT_EQ (random_vector.x, random_vector[0]);
}

TEST_F (Vector2Test, index_operator_throws_index_out_of_range_exception_when_out_of_range)
{
  const Math::Vec2d vector;
  EXPECT_THROW (vector[2], Math::Vec2d::index_operator_out_of_range_exception);
}

TEST_F (Vector2Test, vector_can_be_casted_to_array_c_style)
{
  auto pointer = (double *) random_vector;

  EXPECT_EQ (pointer[0], random_vector.x);
  EXPECT_EQ (pointer[1], random_vector.y);
}

TEST_F (Vector2Test, vector_can_be_static_casted_to_array)
{
  auto pointer = static_cast<double*> (random_vector);

  EXPECT_EQ (pointer[0], random_vector.x);
  EXPECT_EQ (pointer[1], random_vector.y);
}

TEST_F (Vector2Test, changing_the_array_we_cast_to_changes_the_vector)
{
  auto pointer = static_cast<double*> (random_vector);
  auto tmp = pointer[0];

  ++pointer[0];
  EXPECT_EQ (pointer[0], tmp + 1);
  EXPECT_EQ (random_vector.x, pointer[0]);
}

TEST_F (Vector2Test, const_vector_can_be_cast_to_const_ptr)
{
  const auto vector = create_random_vector2 ();
  auto const_ptr = (const double*) vector;

  EXPECT_EQ (const_ptr[0], vector.x);
  EXPECT_EQ (const_ptr[1], vector.y);
}

TEST_F (Vector2Test, zero_vector_gives_zero_length)
{
  EXPECT_EQ (0.0, empty_vector.length ());
  EXPECT_EQ (0.0, empty_vector.lengthSquared ());
}

TEST_F (Vector2Test, length_of_vector_follows_mathematical_rules)
{
  auto lengthSquared = random_vector.x * random_vector.x + random_vector.y * random_vector.y;
  EXPECT_EQ (lengthSquared, random_vector.lengthSquared ());
  EXPECT_EQ (std::sqrt (lengthSquared), random_vector.length ());
}

TEST_F (Vector2Test, normalize_non_zero_vector_gives_new_length_of_1)
{
  random_vector.normalize ();
  EXPECT_FLOAT_EQ (1.0, random_vector.length ());
}

TEST_F (Vector2Test, normalize_throws_can_not_normalize_zero_exception_when_normalizing_zero_vector)
{
  EXPECT_THROW (empty_vector.normalize (), Math::Vec2d::can_not_normalize_zero_vector_exception);
}

TEST_F (Vector2Test, vector_negation_negates_each_component)
{
  auto neg = -random_vector;

  EXPECT_EQ (-random_vector.x, neg.x);
  EXPECT_EQ (-random_vector.y, neg.y);
}

TEST_F (Vector2Test, adding_two_vectors_adds_each_component)
{
  const auto vector_1 = create_random_vector2 ();
  const auto vector_2 = create_random_vector2 ();
  auto res = vector_1 + vector_2;

  EXPECT_EQ (vector_1.x + vector_2.x, res.x);
  EXPECT_EQ (vector_1.y + vector_2.y, res.y);
}

TEST_F (Vector2Test, subtracting_two_vectors_subtracts_each_component)
{
  const auto vector_1 = create_random_vector2 ();
  const auto vector_2 = create_random_vector2 ();
  auto res = vector_1 - vector_2;

  EXPECT_EQ (vector_1.x - vector_2.x, res.x);
  EXPECT_EQ (vector_1.y - vector_2.y, res.y);
}

TEST_F (Vector2Test, multiplying_vector_with_scalar_from_right_multiplies_each_component)
{
  const auto vector = create_random_vector2 ();
  auto res = vector * 2.3;

  EXPECT_EQ (vector.x * 2.3, res.x);
  EXPECT_EQ (vector.y * 2.3, res.y);
}

TEST_F (Vector2Test, dividing_vector_with_scalar_divides_each_component)
{
  const auto vector = create_random_vector2 ();
  double scalar = rand () / 100.0;
  auto res = vector / scalar;

  EXPECT_EQ (vector.x / scalar, res.x);
  EXPECT_EQ (vector.y / scalar, res.y);
}

TEST_F (Vector2Test, multiplying_vector_with_scalar_from_left_multiplies_each_component)
{
  const auto vector = create_random_vector2 ();
  auto scalar = rand () / 100.0;
  auto res = scalar * vector;

  EXPECT_EQ (vector.x * scalar, res.x);
  EXPECT_EQ (vector.y * scalar, res.y);
}

TEST_F (Vector2Test, dividing_vector_with_zero_throws_division_by_zero_exception)
{
  const auto vector = create_random_vector2 ();
  EXPECT_THROW (vector / 0.0, Math::Vec2d::division_by_zero_exception);
}

TEST_F (Vector2Test, multiplying_two_vectors_multiplies_component_wise)
{
  const auto vec1 = create_random_vector2 ();
  const auto vec2 = create_random_vector2 ();
  auto res = vec1 * vec2;

  EXPECT_EQ (vec1.x * vec2.x, res.x);
  EXPECT_EQ (vec1.y * vec2.y, res.y);
}

TEST_F (Vector2Test, dot_product_of_two_vectors_gives_the_sum_of_the_vectors_multiplied)
{
  const auto vec1 = create_random_vector2 ();
  const auto vec2 = create_random_vector2 ();

  auto dot = vec1.dot (vec2);
  auto mult = vec1 * vec2;
  EXPECT_EQ (mult.x + mult.y, dot);
}

TEST_F (Vector2Test, perp_vector_is_zero_vector_for_zero_vector)
{
  const Math::Vec2d vector;
  auto perp = vector.perp ();

  EXPECT_EQ (0.0, perp.x);
  EXPECT_EQ (0.0, perp.y);
}

TEST_F (Vector2Test, perpendicular_vector_of_non_zero_vector_is_non_zero)
{
  const auto vector = create_random_vector2 ();
  auto perp = vector.perp ();

  EXPECT_TRUE (perp.x != 0.0 || perp.y != 0.0);
}

TEST_F (Vector2Test, dot_product_with_perp_vector_is_zero)
{
  const auto vector = create_random_vector2 ();
  auto perp = vector.perp ();

  EXPECT_EQ (0.0, vector.dot (perp));
  EXPECT_EQ (0.0, perp.dot (vector));
}

TEST_F (Vector2Test, addition_to_vector_gives_same_as_the_vectors_added)
{
  const auto vec1 = create_random_vector2 ();
  auto vec2 = create_random_vector2 ();

  auto vec3 = vec1 + vec2;
  vec2 += vec1;

  EXPECT_EQ (vec3.x, vec2.x);
  EXPECT_EQ (vec3.y, vec2.y);
}

TEST_F (Vector2Test, subtraction_from_vector_gives_same_as_vectors_subtracted)
{
  const auto vec1 = create_random_vector2 ();
  auto vec2 = create_random_vector2 ();

  auto vec3 = vec2 - vec1;
  vec2 -= vec1;

  EXPECT_EQ (vec3.x, vec2.x);
  EXPECT_EQ (vec3.y, vec2.y);
}

TEST_F (Vector2Test, multiplication_inplace_with_scalar_gives_same_as_vector_times_scalar)
{
  auto vec1 = create_random_vector2 ();
  auto scalar = rand () / 100.0;

  auto vec2 = vec1 * scalar;
  vec1 *= scalar;

  EXPECT_EQ (vec1.x, vec2.x);
  EXPECT_EQ (vec1.y, vec2.y);
}

TEST_F (Vector2Test, multiplication_inplace_with_vector_gives_same_as_vector_times_vector)
{
  const auto vec1 = create_random_vector2 ();
  auto vec2 = create_random_vector2 ();

  auto vec3 = vec1 * vec2;
  vec2 *= vec1;

  EXPECT_EQ (vec3.x, vec2.x);
  EXPECT_EQ (vec3.y, vec2.y);
}

TEST_F (Vector2Test, division_inplace_with_with_scalar_gives_same_as_vector_divided_by_scalar)
{
  auto vec1 = create_random_vector2 ();
  auto scalar = rand () / 100.0;

  auto vec2 = vec1 / scalar;
  vec1 /= scalar;

  EXPECT_EQ (vec1.x, vec2.x);
  EXPECT_EQ (vec1.y, vec2.y);
}

TEST_F (Vector2Test, inplace_division_by_zero_throws_division_by_zero_exception)
{
  auto vec = create_random_vector2 ();

  EXPECT_THROW (vec /= 0.0, Math::Vec2d::division_by_zero_exception);
}

TEST_F (Vector2Test, inplace_arithmetic_returns_ref_to_self)
{
  auto vec1 = create_random_vector2 ();
  auto vec2 = create_random_vector2 ();
  auto tmp = rand () / 100.0;

  Math::Vec2d *res;

  res = &(vec1 += vec2);
  EXPECT_EQ (&vec1, res);

  res = &(vec2 -= vec1);
  EXPECT_EQ (&vec2, res);

  res = &(vec1 *= vec2);
  EXPECT_EQ (&vec1, res);

  res = &(vec2 *= tmp);
  EXPECT_EQ (&vec2, res);

  res = &(vec1 /= tmp);
  EXPECT_EQ (&vec1, res);
}

TEST_F (Vector2Test, equality_operator_gives_true_for_same_vector)
{
  const auto vector = create_random_vector2 ();
  EXPECT_EQ (vector, vector);
}

TEST_F (Vector2Test, equality_operator_gives_true_for_copied_vector)
{
  const auto vector = create_random_vector2 ();
  auto copy = vector;

  EXPECT_EQ (copy, vector);
}

TEST_F (Vector2Test, equality_operator_gives_true_for_vectors_with_equal_components)
{
  auto array = create_double_array_of_size (2);
  const Math::Vec2d vector (array);
  const Math::Vec2d same (array);

  EXPECT_EQ (vector, same);

  delete[] array;
}

TEST_F (Vector2Test, equality_operator_gives_false_for_unequal_x)
{
  const Math::Vec2d vector (3.2, 1.8);
  const Math::Vec2d different (3.0, 1.8);
  EXPECT_FALSE (vector == different);
}

TEST_F (Vector2Test, equality_operator_gives_false_for_unequal_y)
{
  const Math::Vec2d vector (3.2, 1.8);
  const Math::Vec2d different (3.2, 2.8);
  EXPECT_FALSE (vector == different);
}

TEST_F (Vector2Test, non_equal_operator_gives_true_for_unequal_x)
{
  const Math::Vec2d vector (3.2, 1.8);
  const Math::Vec2d different (3.0, 1.8);
  EXPECT_NE (vector, different);
}

TEST_F (Vector2Test, non_equal_operator_gives_true_for_unequal_y)
{
  const Math::Vec2d vector (3.2, 1.8);
  const Math::Vec2d different (3.2, 2.8);
  EXPECT_NE (vector, different);
}

TEST_F (Vector2Test, non_equal_operator_gives_false_for_same_vector)
{
  const auto vector = create_random_vector2 ();
  EXPECT_FALSE (vector != vector);
}

TEST_F (Vector2Test, non_equal_operator_gives_false_for_copy)
{
  const auto vector = create_random_vector2 ();
  auto copy = vector;
  EXPECT_FALSE (copy != vector);
}

TEST_F (Vector2Test, non_equal_operator_gives_false_for_vectors_with_equal_components)
{
  auto array = create_double_array_of_size (2);
  const Math::Vec2d vector (array);
  const Math::Vec2d same (array);
  EXPECT_FALSE (vector != same);

  delete[] array;
}

TEST_F (Vector2Test, orhtonormal_basis_with_zero_vector_throws_can_not_make_orthonormal_basis_with_zero_vector_exception)
{
  Math::Vec2d zero;
  Math::Vec2d vector (4.0, 7.0);
  EXPECT_THROW (Math::Vec2d::generateOrthonormalBasis (zero, vector), Math::Vec2d::can_not_make_orthonormal_basis_with_zero_vector_exception);
  EXPECT_THROW (Math::Vec2d::generateOrthonormalBasis (vector, zero), Math::Vec2d::can_not_make_orthonormal_basis_with_zero_vector_exception);
}

TEST_F (Vector2Test, orthonormal_basis_with_equal_vectors_throws_can_not_make_orthonormal_basis_from_equal_vectors_exception)
{
  Math::Vec2d vector (4.0, 7.0);
  auto copy = vector;
  EXPECT_THROW (Math::Vec2d::generateOrthonormalBasis (vector, copy), Math::Vec2d::can_not_make_orthonormal_basis_from_equal_vectors_exception);
}

TEST_F (Vector2Test, orthonormal_basis_creates_perpendicular_vectors_of_length_1)
{
  auto vec1 = create_random_vector2 ();
  auto vec2 = create_random_vector2 ();

  if (vec1 != vec2) {
    Math::Vec2d::generateOrthonormalBasis (vec1, vec2);
    EXPECT_NEAR (0.0, vec1.dot (vec2), PRECISION);
    EXPECT_NEAR (1.0, vec1.length (), PRECISION);
    EXPECT_NEAR (1.0, vec2.length (), PRECISION);
  }
}

const Math::Vec2d create_random_vector2 ()
{
  auto array = create_double_array_of_size (2);
  Math::Vec2d vector (array);

  delete [] array;
  return vector;
}
