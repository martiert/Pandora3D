#include <matrix3.h>
#include <gtest/gtest.h>

#include "test-helpers.h"

const Math::Matrix3d create_random_matrix3();

class Matrix3Test : public ::testing::Test
{
  protected:
    void SetUp();
    void TearDown();

    double * array;
    Math::Matrix3d random_matrix;
    Math::Matrix3d random_matrix2;
    double scalar;
};

void Matrix3Test::SetUp()
{
  array = create_double_array_of_size(9);
  random_matrix = create_random_matrix3();
  random_matrix2 = create_random_matrix3();
  scalar = rand() / 100.0;
}

void Matrix3Test::TearDown()
{
  delete[] array;
}

TEST_F(Matrix3Test, empty_constructor_makes_identity_matrix)
{
  const Math::Matrix3d matrix;

  EXPECT_EQ(1.0, matrix(0,0));
  EXPECT_EQ(0.0, matrix(0,1));
  EXPECT_EQ(0.0, matrix(0,2));
  EXPECT_EQ(0.0, matrix(1,0));
  EXPECT_EQ(1.0, matrix(1,1));
  EXPECT_EQ(0.0, matrix(1,2));
  EXPECT_EQ(0.0, matrix(2,0));
  EXPECT_EQ(0.0, matrix(2,1));
  EXPECT_EQ(1.0, matrix(2,2));
}

TEST_F(Matrix3Test, matrix_can_be_constructed_from_array)
{
  const Math::Matrix3d tmp(array);
  for (auto i = 0; i < 9; ++i)
    EXPECT_EQ(array[i], tmp[i]);
}

TEST_F(Matrix3Test, matrix_can_be_specified)
{
  const Math::Matrix3d tmp({array[0], array[1], array[2],
    array[3], array[4], array[5],
    array[6], array[7], array[8]});

  for (auto i = 0; i < 9; ++i)
    EXPECT_EQ(array[i], tmp[i]);
}

TEST_F(Matrix3Test, matrix_can_be_copied)
{
  const Math::Matrix3d copy(random_matrix);

  for (auto i = 0; i < 9; ++i)
    EXPECT_EQ(random_matrix[i], copy[i]);
}

TEST_F(Matrix3Test, matrix_can_be_assigned)
{
  const Math::Matrix3d copy = random_matrix;

  for (auto i = 0; i < 9; ++i)
    EXPECT_EQ(random_matrix[i], copy[i]);
}

TEST_F(Matrix3Test, determinant_of_zero_matrix_is_zero)
{
  Math::Matrix3d zero{{0,0,0,0,0,0,0,0,0}};
  EXPECT_EQ(0, matrix_determinant(zero));
}

TEST_F(Matrix3Test, transpose_of_zero_matrix_is_zero)
{
  Math::Matrix3d zero{{0,0,0,0,0,0,0,0,0}};
  auto transpose = matrix_transpose(zero);

  for (size_t i = 0; i < 9; ++i)
    EXPECT_EQ(0, transpose[i]);
}

TEST_F(Matrix3Test, trace_of_zero_matrix_is_zero)
{
  Math::Matrix3d zero{{0,0,0,0,0,0,0,0,0}};
  EXPECT_EQ(0, matrix_trace(zero));
}

TEST_F(Matrix3Test, inverse_of_identity_is_identity)
{
  Math::Matrix3d identity;
  auto inverse = matrix_inverse(identity);

  for (auto i = 0; i < 9; ++i)
    EXPECT_EQ(identity[i], inverse[i]);
}

TEST_F(Matrix3Test, adding_matrix_to_matrix_adds_each_element)
{
  Math::Matrix3d result(random_matrix);
  result += random_matrix2;

  for (auto i = 0; i < 9; ++i)
    EXPECT_EQ(random_matrix[i] + random_matrix2[i], result[i]);
}

TEST_F(Matrix3Test, subtracting_matrix_from_matrix_subtracts_each_element)
{
  Math::Matrix3d result(random_matrix);
  result -= random_matrix2;

  for (auto i = 0; i < 9; ++i)
    EXPECT_EQ(random_matrix[i] - random_matrix2[i], result[i]);
}

TEST_F(Matrix3Test, multiply_scalar_to_matrix_multiplies_each_component_of_the_matrix)
{
  auto result(random_matrix);
  result *= scalar;

  for (auto i = 0; i < 9; ++i)
    EXPECT_EQ(random_matrix[i] * scalar, result[i]);
}

TEST_F(Matrix3Test, dividing_matrix_with_scalar_divides_each_component)
{
  auto result(random_matrix);
  result /= scalar;

  for (auto i = 0; i < 9; ++i)
    EXPECT_FLOAT_EQ(random_matrix[i] / scalar, result[i]);
}

TEST_F(Matrix3Test, multipling_matrix_with_scalar_from_right_multiplies_each_component)
{
  auto result = random_matrix * scalar;

  for (auto i = 0; i < 9; ++i)
    EXPECT_EQ(random_matrix[i] * scalar, result[i]);
}

TEST_F(Matrix3Test, multipling_matrix_with_scalar_from_left_multiplies_each_component)
{
  auto result = scalar * random_matrix;

  for (auto i = 0; i < 9; ++i)
    EXPECT_EQ(random_matrix[i] * scalar, result[i]);
}

TEST_F(Matrix3Test, dividing_matrix_and_scalar_divides_each_component)
{
  auto result = random_matrix / scalar;

  for (auto i = 0; i < 9; ++i)
    EXPECT_FLOAT_EQ(random_matrix[i] / scalar, result[i]);
}

TEST_F(Matrix3Test, adding_two_matrices_adds_each_element)
{
  auto result = random_matrix + random_matrix2;

  for (auto i = 0; i < 9; ++i)
    EXPECT_EQ(random_matrix[i] + random_matrix2[i], result[i]);
}

TEST_F(Matrix3Test, subtracting_two_matrices_subtracts_each_element)
{
  auto result = random_matrix - random_matrix2;

  for (auto i = 0; i < 9; ++i)
    EXPECT_EQ(random_matrix[i] - random_matrix2[i], result[i]);
}

TEST_F(Matrix3Test, equality_of_same_matrix_returns_true)
{
  EXPECT_EQ(random_matrix, random_matrix);
}

TEST_F(Matrix3Test, inequality_of_same_matrix_returns_false)
{
  const auto matrix = create_random_matrix3();

  EXPECT_FALSE(matrix != matrix);
}

TEST_F(Matrix3Test, determinant_of_identity_matrix_is_one)
{
  Math::Matrix3d identity;
  EXPECT_EQ(1, matrix_determinant(identity));
}

// TEST_F(Matrix3Test, matrix_determinant_follows_mathematical_rules)
// {
//   auto det = random_matrix(0,0) *(random_matrix(1,1) * random_matrix(2,2) -
//     random_matrix(1,2) * random_matrix(2,1)) -
//   random_matrix(0,1) *(random_matrix(1,0) * random_matrix(2,2) -
//       random_matrix(2,0) * random_matrix(1,2)) +
//   random_matrix(0,2) *(random_matrix(1,0) * random_matrix(2,1) -
//       random_matrix(2,0) * random_matrix(1,1));
// 
//   EXPECT_EQ(det, random_matrix.determinant());
// }

TEST_F(Matrix3Test, matrix_multipliplied_with_zero_matrix_from_right_is_zero_matrix)
{
  Math::Matrix3d zero({0, 0, 0, 0, 0, 0, 0, 0, 0});
  auto result = random_matrix * zero;

  for (size_t i = 0; i < 9; ++i)
    EXPECT_EQ(0, result[i]);
}

TEST_F(Matrix3Test, matrix_multipliplied_with_zero_matrix_from_left_is_zero_matrix)
{
  Math::Matrix3d zero({0, 0, 0, 0, 0, 0, 0, 0, 0});
  auto result = zero * random_matrix;

  for (size_t i = 0; i < 9; ++i)
    EXPECT_EQ(0, result[i]);
}

TEST_F(Matrix3Test, matrix_multipliplied_with_identity_from_right_is_the_same_matrix_again)
{
  Math::Matrix3d identity;
  auto result = random_matrix * identity;

  for (size_t i = 0; i < 9; ++i)
    EXPECT_EQ(random_matrix[i], result[i]);
}

TEST_F(Matrix3Test, matrix_multipliplied_with_identity_from_left_is_the_same_matrix_again)
{
  Math::Matrix3d identity;
  auto result = identity * random_matrix;

  for (size_t i = 0; i < 9; ++i)
    EXPECT_EQ(random_matrix[i], result[i]);
}

TEST_F(Matrix3Test, matrix_matrix_multiplication_follows_normal_mathematical_rules)
{
  auto result = random_matrix * random_matrix2;

  for (auto i = 0; i < 3; ++i) {
    for (auto j = 0; j < 3; ++j) {
      auto res = 0.0;
      for (auto k = 0; k < 3; ++k)
        res += random_matrix(i,k) * random_matrix2(k,j);
      EXPECT_EQ(res, result(i,j));
    }
  }
}

TEST_F(Matrix3Test, trace_of_identity_matrix_is_three)
{
  Math::Matrix3d identity;
  EXPECT_EQ(3, matrix_trace(identity));
}

TEST_F(Matrix3Test, trace_of_random_matrix_is_sum_of_diagonal)
{
  auto trace = random_matrix(0,0) + random_matrix(1,1) + random_matrix(2,2);

  EXPECT_EQ(trace, matrix_trace(random_matrix));
}

TEST_F(Matrix3Test, transpose_of_identity_is_identity)
{
  Math::Matrix3d identity;
  auto transpose = matrix_transpose(identity);

  for (size_t i = 0; i < 9; ++i)
    EXPECT_EQ(identity[i], transpose[i]);
}

TEST_F(Matrix3Test, adjacent_of_identity_is_identity)
{
  Math::Matrix3d identity;
  auto adjacent = matrix_transpose(identity);

  for (size_t i = 0; i < 9; ++i)
    EXPECT_EQ(identity[i], adjacent[i]);
}

TEST_F(Matrix3Test, transpose_of_matrix_swaps_rows_with_columns)
{
  auto transpose = matrix_transpose(random_matrix);

  for (size_t i = 0; i < 3; ++i)
    for (size_t j = 0; j < 3; ++j)
      EXPECT_EQ(random_matrix(i,j), transpose(j,i));
}

// TEST_F(Matrix3Test, matrix_multiplied_with_its_inverse_from_right_is_identity)
// {
//   auto inverse = random_matrix.inverse();
//   auto result = random_matrix * inverse;
// 
//   EXPECT_NEAR(1, result(0,0), PRECISION);
//   EXPECT_NEAR(0, result(0,1), PRECISION);
//   EXPECT_NEAR(0, result(0,2), PRECISION);
// 
//   EXPECT_NEAR(0, result(1,0), PRECISION);
//   EXPECT_NEAR(1, result(1,1), PRECISION);
//   EXPECT_NEAR(0, result(1,2), PRECISION);
// 
//   EXPECT_NEAR(0, result(2,0), PRECISION);
//   EXPECT_NEAR(0, result(2,1), PRECISION);
//   EXPECT_NEAR(1, result(2,2), PRECISION);
// }

TEST_F(Matrix3Test, equality_of_copied_matrix_returns_true)
{
  auto copy = random_matrix;

  EXPECT_EQ(random_matrix, copy);
}

TEST_F(Matrix3Test, equality_of_equal_matrix_returns_true)
{
  const auto array = create_double_array_of_size(9);
  const Math::Matrix3d matrix(array);
  const Math::Matrix3d equal(array);

  EXPECT_EQ(matrix, equal);

  delete[] array;
}

TEST_F(Matrix3Test, equality_of_matrix_with_one_different_element_returns_false)
{
  const auto matrix = create_random_matrix3();

  for (int i = 0; i < 9; ++i) {
    auto other = matrix;
    other[i] += 4;

    EXPECT_FALSE(matrix == other);
  }
}

TEST_F(Matrix3Test, inequality_of_copied_matrix_returns_false)
{
  const auto matrix = create_random_matrix3();
  auto copy = matrix;

  EXPECT_FALSE(matrix != copy);
}

TEST_F(Matrix3Test, inequality_of_equal_matrix_returns_false)
{
  const auto array = create_double_array_of_size(9);
  const Math::Matrix3d matrix(array);
  const Math::Matrix3d equal(array);

  EXPECT_FALSE(matrix != equal);

  delete[] array;
}

TEST_F(Matrix3Test, inequality_of_matrix_with_one_different_element_returns_true)
{
  const auto matrix = create_random_matrix3();

  for (int i = 0; i < 9; ++i) {
    auto other = matrix;
    other[i] += 4;

    EXPECT_NE(matrix, other);
  }
}

const Math::Matrix3d create_random_matrix3()
{
  const auto array = create_double_array_of_size(9);
  Math::Matrix3d matrix(array);
  delete [] array;
  return matrix;
}
