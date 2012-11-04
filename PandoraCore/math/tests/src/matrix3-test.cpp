#include <matrix3.h>
#include <gtest/gtest.h>

#include "test-helpers.h"

const Math::Matrix3d create_random_matrix3();

class Matrix3Test : public ::testing::Test
{
  protected:
    void SetUp();

    Math::Matrix3d random_matrix;
    Math::Matrix3d random_matrix2;
    double scalar;
};

void Matrix3Test::SetUp()
{
  random_matrix = create_random_matrix3();
  random_matrix2 = create_random_matrix3();
  scalar = rand() / 100.0;
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
  const auto c_array = create_double_array_of_size(9);
  const std::array<double, 9> array {{c_array[0], c_array[1], c_array[2],
                                      c_array[3], c_array[4], c_array[5],
                                      c_array[6], c_array[7], c_array[8]}};
  const Math::Matrix3d tmp(array);

  for (auto i = 0; i < 9; ++i)
    EXPECT_EQ(array[i], tmp[i]);

  delete[] c_array;
}

TEST_F(Matrix3Test, matrix_can_be_specified)
{
  const auto array = create_double_array_of_size(9);
  const Math::Matrix3d tmp(array[0], array[1], array[2],
    array[3], array[4], array[5],
    array[6], array[7], array[8]);

  for (auto i = 0; i < 9; ++i)
    EXPECT_EQ(array[i], tmp[i]);

  delete[] array;
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

TEST_F(Matrix3Test, multiply_scalar_to_matrix_multiplies_each_component_of_the_matrix)
{
  auto result(random_matrix);
  result *= scalar;

  for (auto i = 0; i < 9; ++i)
    EXPECT_EQ(random_matrix[i] * scalar, result[i]);
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

TEST_F(Matrix3Test, dividing_scalar_to_matrix_divides_each_component)
{
  auto result(random_matrix);
  result /= scalar;

  for (auto i = 0; i < 9; ++i)
    EXPECT_EQ(random_matrix[i] / scalar, result[i]);
}

TEST_F(Matrix3Test, dividing_matrix_and_scalar_divides_each_component)
{
  auto result = random_matrix / scalar;

  for (auto i = 0; i < 9; ++i)
    EXPECT_EQ(random_matrix[i] / scalar, result[i]);
}

TEST_F(Matrix3Test, adding_matrix_with_matrix_adds_each_element)
{
  Math::Matrix3d result(random_matrix);
  result += random_matrix2;

  for (auto i = 0; i < 9; ++i)
    EXPECT_EQ(random_matrix[i] + random_matrix2[i], result[i]);
}

TEST_F(Matrix3Test, adding_two_matrices_adds_each_element)
{
  auto result = random_matrix + random_matrix2;

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

TEST_F(Matrix3Test, subtracting_two_matrices_subtracts_each_element)
{
  auto result = random_matrix - random_matrix2;

  for (auto i = 0; i < 9; ++i)
    EXPECT_EQ(random_matrix[i] - random_matrix2[i], result[i]);
}

TEST_F(Matrix3Test, determinant_of_zero_matrix_is_zero)
{
  EXPECT_EQ(0, Math::Matrix3d::ZERO.determinant());
}

TEST_F(Matrix3Test, determinant_of_identity_matrix_is_one)
{
  EXPECT_EQ(1, Math::Matrix3d::IDENTITY.determinant());
}

TEST_F(Matrix3Test, matrix_determinant_follows_mathematical_rules)
{
  auto det = random_matrix(0,0) *(random_matrix(1,1) * random_matrix(2,2) -
    random_matrix(1,2) * random_matrix(2,1)) -
  random_matrix(0,1) *(random_matrix(1,0) * random_matrix(2,2) -
      random_matrix(2,0) * random_matrix(1,2)) +
  random_matrix(0,2) *(random_matrix(1,0) * random_matrix(2,1) -
      random_matrix(2,0) * random_matrix(1,1));

  EXPECT_EQ(det, random_matrix.determinant());
}

TEST_F(Matrix3Test, matrix_multipliplied_with_zero_matrix_from_right_is_zero_matrix)
{
  auto result = random_matrix * Math::Matrix3d::ZERO;

  for (size_t i = 0; i < 9; ++i)
    EXPECT_EQ(0, result[i]);
}

TEST_F(Matrix3Test, matrix_multipliplied_with_zero_matrix_from_left_is_zero_matrix)
{
  auto result = Math::Matrix3d::ZERO * random_matrix;

  for (size_t i = 0; i < 9; ++i)
    EXPECT_EQ(0, result[i]);
}

TEST_F(Matrix3Test, matrix_multipliplied_with_identity_from_right_is_the_same_matrix_again)
{
  auto result = random_matrix * Math::Matrix3d::IDENTITY;

  for (size_t i = 0; i < 9; ++i)
    EXPECT_EQ(random_matrix[i], result[i]);
}

TEST_F(Matrix3Test, matrix_multipliplied_with_identity_from_left_is_the_same_matrix_again)
{
  auto result = Math::Matrix3d::IDENTITY * random_matrix;

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

TEST_F(Matrix3Test, trace_of_zero_matrix_is_zero)
{
  EXPECT_EQ(0, Math::Matrix3d::ZERO.trace());
}

TEST_F(Matrix3Test, trace_of_identity_matrix_is_three)
{
  EXPECT_EQ(3, Math::Matrix3d::IDENTITY.trace());
}

TEST_F(Matrix3Test, trace_of_random_matrix_is_sum_of_diagonal)
{
  auto trace = random_matrix(0,0) + random_matrix(1,1) + random_matrix(2,2);

  EXPECT_EQ(trace, random_matrix.trace());
}

TEST_F(Matrix3Test, transpose_of_zero_matrix_is_zero)
{
  auto transpose = Math::Matrix3d::ZERO.transpose();

  for (size_t i = 0; i < 9; ++i)
    EXPECT_EQ(0, transpose[i]);
}

TEST_F(Matrix3Test, transpose_of_identity_is_identity)
{
  auto transpose = Math::Matrix3d::IDENTITY.transpose();

  for (size_t i = 0; i < 9; ++i)
    EXPECT_EQ(Math::Matrix3d::IDENTITY[i], transpose[i]);
}

TEST_F(Matrix3Test, transpose_of_matrix_swaps_rows_with_columns)
{
  auto transpose = random_matrix.transpose();

  for (size_t i = 0; i < 3; ++i)
    for (size_t j = 0; j < 3; ++j)
      EXPECT_EQ(random_matrix(i,j), transpose(j,i));
}

TEST_F(Matrix3Test, inverse_of_identity_is_identity)
{
  auto inverse = Math::Matrix3d::IDENTITY.inverse();

  for (auto i = 0; i < 9; ++i)
    EXPECT_EQ(Math::Matrix3d::IDENTITY[i], inverse[i]);
}

TEST_F(Matrix3Test, matrix_multiplied_with_its_inverse_from_right_is_identity)
{
  auto inverse = random_matrix.inverse();
  auto result = random_matrix * inverse;

  EXPECT_NEAR(1, result(0,0), PRECISION);
  EXPECT_NEAR(0, result(0,1), PRECISION);
  EXPECT_NEAR(0, result(0,2), PRECISION);

  EXPECT_NEAR(0, result(1,0), PRECISION);
  EXPECT_NEAR(1, result(1,1), PRECISION);
  EXPECT_NEAR(0, result(1,2), PRECISION);

  EXPECT_NEAR(0, result(2,0), PRECISION);
  EXPECT_NEAR(0, result(2,1), PRECISION);
  EXPECT_NEAR(1, result(2,2), PRECISION);
}

TEST_F(Matrix3Test, equality_of_same_matrix_returns_true)
{
  EXPECT_EQ(random_matrix, random_matrix);
}

TEST_F(Matrix3Test, equality_of_copied_matrix_returns_true)
{
  auto copy = random_matrix;

  EXPECT_EQ(random_matrix, copy);
}

TEST_F(Matrix3Test, equality_of_equal_matrix_returns_true)
{
  const auto c_array = create_double_array_of_size(9);
  const std::array<double, 9> array {{c_array[0], c_array[1], c_array[2],
                                      c_array[3], c_array[4], c_array[5],
                                      c_array[6], c_array[7], c_array[8]}};
  const Math::Matrix3d matrix(array);
  const Math::Matrix3d equal(array);

  EXPECT_EQ(matrix, equal);

  delete[] c_array;
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

TEST_F(Matrix3Test, inequality_of_same_matrix_returns_false)
{
  const auto matrix = create_random_matrix3();

  EXPECT_FALSE(matrix != matrix);
}

TEST_F(Matrix3Test, inequality_of_copied_matrix_returns_false)
{
  const auto matrix = create_random_matrix3();
  auto copy = matrix;

  EXPECT_FALSE(matrix != copy);
}

TEST_F(Matrix3Test, inequality_of_equal_matrix_returns_false)
{
  const auto c_array = create_double_array_of_size(9);
  const std::array<double, 9> array {{c_array[0], c_array[1], c_array[2],
                                      c_array[3], c_array[4], c_array[5],
                                      c_array[6], c_array[7], c_array[8]}};
  const Math::Matrix3d matrix(array);
  const Math::Matrix3d equal(array);

  EXPECT_FALSE(matrix != equal);

  delete[] c_array;
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
  const auto c_array = create_double_array_of_size(9);
  const std::array<double, 9> array {{c_array[0], c_array[1], c_array[2],
                                      c_array[3], c_array[4], c_array[5],
                                      c_array[6], c_array[7], c_array[8]}};
  Math::Matrix3d matrix(array);

  delete [] c_array;
  return matrix;
}
