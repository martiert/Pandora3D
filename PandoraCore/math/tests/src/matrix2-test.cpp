#include "test-helpers.h"

#include <matrix2.h>
#include <vector2.h>
#include <gtest/gtest.h>

const Math::Matrix2<double> create_random_matrix2();
const Math::Vec2d create_random_vector2();

class Matrix2Test : public ::testing::Test
{
  protected:
    void SetUp();

    Math::Matrix2d random_matrix;
    Math::Matrix2d random_matrix2;
    Math::Vec2d random_vector;
    double scalar;
};

void Matrix2Test::SetUp()
{
  random_matrix = create_random_matrix2();
  random_matrix2 = create_random_matrix2();
  random_vector = create_random_vector2();
  scalar = rand() / 100.0;
}

TEST_F(Matrix2Test, empty_constructor_makes_identity_matrix)
{
  const Math::Matrix2<double> mat1;
  EXPECT_EQ(1.0, mat1(0,0));
  EXPECT_EQ(0.0, mat1(0,1));
  EXPECT_EQ(0.0, mat1(1,0));
  EXPECT_EQ(1.0, mat1(1,1));
}

TEST_F(Matrix2Test, matrix_copies_array)
{
  auto array = create_double_array_of_size(4);
  std::array<double, 4> tmp {{array[0], array[1], array[2], array[3]}};
  const Math::Matrix2<double> mat1(tmp);

  EXPECT_EQ(tmp[0], mat1(0,0));
  EXPECT_EQ(tmp[1], mat1(0,1));
  EXPECT_EQ(tmp[2], mat1(1,0));
  EXPECT_EQ(tmp[3], mat1(1,1));

  tmp[0] = 4.5;
  EXPECT_NE(tmp[0], mat1(0,0));

  delete array;
}

TEST_F(Matrix2Test, matrix_can_be_specified)
{
  auto tmp = create_double_array_of_size(4);
  const Math::Matrix2<double> mat1(tmp[0], tmp[1], tmp[2], tmp[3]);

  EXPECT_EQ(tmp[0], mat1(0,0));
  EXPECT_EQ(tmp[1], mat1(0,1));
  EXPECT_EQ(tmp[2], mat1(1,0));
  EXPECT_EQ(tmp[3], mat1(1,1));

  delete[] tmp;
}

TEST_F(Matrix2Test, matrix_copies_matrix)
{
  Math::Matrix2<double> mat2(random_matrix);

  EXPECT_EQ(random_matrix(0,0), mat2(0,0));
  EXPECT_EQ(random_matrix(0,1), mat2(0,1));
  EXPECT_EQ(random_matrix(1,0), mat2(1,0));
  EXPECT_EQ(random_matrix(1,1), mat2(1,1));

  mat2(0,1) = 4.0;
  EXPECT_NE(random_matrix(0,1), mat2(0,1));
}

TEST_F(Matrix2Test, matrix_multiplication_with_scalar_from_right_multiplies_each_component_with_scalar)
{
  auto res = random_matrix * scalar;

  EXPECT_EQ(random_matrix(0,0) * scalar, res(0,0));
  EXPECT_EQ(random_matrix(0,1) * scalar, res(0,1));
  EXPECT_EQ(random_matrix(1,0) * scalar, res(1,0));
  EXPECT_EQ(random_matrix(1,1) * scalar, res(1,1));
}

TEST_F(Matrix2Test, matrix_multiplication_with_scalar_from_left_multiplies_each_component_with_scalar)
{
  auto res = scalar * random_matrix;

  EXPECT_EQ(random_matrix(0,0) * scalar, res(0,0));
  EXPECT_EQ(random_matrix(0,1) * scalar, res(0,1));
  EXPECT_EQ(random_matrix(1,0) * scalar, res(1,0));
  EXPECT_EQ(random_matrix(1,1) * scalar, res(1,1));
}

TEST_F(Matrix2Test, multiplying_scalar_to_matrix_multiplies_each_component_with_scalar)
{
  auto res = random_matrix;
  res *= scalar;

  EXPECT_EQ(random_matrix(0,0) * scalar, res(0,0));
  EXPECT_EQ(random_matrix(0,1) * scalar, res(0,1));
  EXPECT_EQ(random_matrix(1,0) * scalar, res(1,0));
  EXPECT_EQ(random_matrix(1,1) * scalar, res(1,1));
}

TEST_F(Matrix2Test, adding_two_matrices_adds_component_wise)
{
  auto res = random_matrix + random_matrix2;

  EXPECT_EQ(random_matrix(0,0) + random_matrix2(0,0), res(0,0));
  EXPECT_EQ(random_matrix(0,1) + random_matrix2(0,1), res(0,1));
  EXPECT_EQ(random_matrix(1,0) + random_matrix2(1,0), res(1,0));
  EXPECT_EQ(random_matrix(1,1) + random_matrix2(1,1), res(1,1));
}

TEST_F(Matrix2Test, adding_matrix_to_matrix_adds_component_wise)
{
  auto res(random_matrix);
  res += random_matrix2;

  EXPECT_EQ(random_matrix(0,0) + random_matrix2(0,0), res(0,0));
  EXPECT_EQ(random_matrix(0,1) + random_matrix2(0,1), res(0,1));
  EXPECT_EQ(random_matrix(1,0) + random_matrix2(1,0), res(1,0));
  EXPECT_EQ(random_matrix(1,1) + random_matrix2(1,1), res(1,1));
}

TEST_F(Matrix2Test, subtracting_two_matrices_subtracts_component_wise)
{
  auto res = random_matrix - random_matrix2;

  EXPECT_EQ(random_matrix(0,0) - random_matrix2(0,0), res(0,0));
  EXPECT_EQ(random_matrix(0,1) - random_matrix2(0,1), res(0,1));
  EXPECT_EQ(random_matrix(1,0) - random_matrix2(1,0), res(1,0));
  EXPECT_EQ(random_matrix(1,1) - random_matrix2(1,1), res(1,1));
}

TEST_F(Matrix2Test, subtracting_matrix_from_matrix_subtracts_component_wise)
{
  auto res(random_matrix);
  res -= random_matrix2;

  EXPECT_EQ(random_matrix(0,0) - random_matrix2(0,0), res(0,0));
  EXPECT_EQ(random_matrix(0,1) - random_matrix2(0,1), res(0,1));
  EXPECT_EQ(random_matrix(1,0) - random_matrix2(1,0), res(1,0));
  EXPECT_EQ(random_matrix(1,1) - random_matrix2(1,1), res(1,1));
}

TEST_F(Matrix2Test, determinant_of_identity_matrix_is_one)
{
  EXPECT_EQ(1.0, Math::Matrix2<double>::IDENTITY.determinant());
}

TEST_F(Matrix2Test, determinant_of_zero_matrix_is_zero)
{
  EXPECT_EQ(0.0, Math::Matrix2<double>::ZERO.determinant());
}

TEST_F(Matrix2Test, determinant_of_matrix_follows_mathematical_rules)
{
  EXPECT_EQ(random_matrix[0] * random_matrix[3] - random_matrix[1] * random_matrix[2], random_matrix.determinant());
}

TEST_F(Matrix2Test, multiplying_matrix_with_identity_from_right_returns_same_matrix)
{
  auto result = random_matrix * Math::Matrix2d::IDENTITY;

  EXPECT_EQ(random_matrix(0,0), result(0,0));
  EXPECT_EQ(random_matrix(0,1), result(0,1));
  EXPECT_EQ(random_matrix(1,0), result(1,0));
  EXPECT_EQ(random_matrix(1,1), result(1,1));
}

TEST_F(Matrix2Test, multiplying_matrix_with_identity_from_left_returns_same_matrix)
{
  auto result = Math::Matrix2d::IDENTITY * random_matrix;

  EXPECT_EQ(random_matrix(0,0), result(0,0));
  EXPECT_EQ(random_matrix(0,1), result(0,1));
  EXPECT_EQ(random_matrix(1,0), result(1,0));
  EXPECT_EQ(random_matrix(1,1), result(1,1));
}

TEST_F(Matrix2Test, multiply_matrix_with_zero_matrix_from_right_gives_zero_matrix)
{
  auto result = random_matrix * Math::Matrix2d::ZERO;

  EXPECT_EQ(0, result(0,0));
  EXPECT_EQ(0, result(0,1));
  EXPECT_EQ(0, result(1,0));
  EXPECT_EQ(0, result(1,1));
}

TEST_F(Matrix2Test, multiply_matrix_with_zero_matrix_from_left_gives_zero_matrix)
{
  auto result = Math::Matrix2d::ZERO * random_matrix;

  EXPECT_EQ(0, result(0,0));
  EXPECT_EQ(0, result(0,1));
  EXPECT_EQ(0, result(1,0));
  EXPECT_EQ(0, result(1,1));
}

TEST_F(Matrix2Test, matrix_multiplication_follows_mathematical_rules)
{
  auto result = random_matrix * random_matrix2;

  EXPECT_EQ(random_matrix(0,0) * random_matrix2(0,0) + random_matrix(0,1) * random_matrix2(1,0), result(0,0));
  EXPECT_EQ(random_matrix(0,0) * random_matrix2(0,1) + random_matrix(0,1) * random_matrix2(1,1), result(0,1));
  EXPECT_EQ(random_matrix(1,0) * random_matrix2(0,0) + random_matrix(1,1) * random_matrix2(1,0), result(1,0));
  EXPECT_EQ(random_matrix(1,0) * random_matrix2(0,1) + random_matrix(1,1) * random_matrix2(1,1), result(1,1));
}

TEST_F(Matrix2Test, dividing_matrix_and_scalar_divides_each_component)
{
  auto result = random_matrix / scalar;

  EXPECT_EQ(random_matrix(0,0) / scalar, result(0,0));
  EXPECT_EQ(random_matrix(0,1) / scalar, result(0,1));
  EXPECT_EQ(random_matrix(1,0) / scalar, result(1,0));
  EXPECT_EQ(random_matrix(1,1) / scalar, result(1,1));
}

TEST_F(Matrix2Test, dividing_matrix_with_scalar_divides_each_component)
{
  auto result = random_matrix;
  result /= scalar;

  EXPECT_EQ(random_matrix(0,0) / scalar, result(0,0));
  EXPECT_EQ(random_matrix(0,1) / scalar, result(0,1));
  EXPECT_EQ(random_matrix(1,0) / scalar, result(1,0));
  EXPECT_EQ(random_matrix(1,1) / scalar, result(1,1));
}

TEST_F(Matrix2Test, multiplication_with_inverse_from_right_returns_identity)
{
  auto inverse = random_matrix.inverse();
  auto result = random_matrix * inverse;

  EXPECT_NEAR(1, result(0,0), PRECISION);
  EXPECT_NEAR(0, result(0,1), PRECISION);
  EXPECT_NEAR(0, result(1,0), PRECISION);
  EXPECT_NEAR(1, result(1,1), PRECISION);
}

TEST_F(Matrix2Test, multiplication_with_inverse_from_left_returns_identity)
{
  auto inverse = random_matrix.inverse();
  auto result = inverse * random_matrix;

  EXPECT_NEAR(1, result(0,0), PRECISION);
  EXPECT_NEAR(0, result(0,1), PRECISION);
  EXPECT_NEAR(0, result(1,0), PRECISION);
  EXPECT_NEAR(1, result(1,1), PRECISION);
}

TEST_F(Matrix2Test, multiplying_identity_with_vector_returns_vector)
{
  const auto res = Math::Matrix2<double>::IDENTITY * random_vector;

  EXPECT_EQ(random_vector.x, res.x);
  EXPECT_EQ(random_vector.y, res.y);
}

TEST_F(Matrix2Test, multiplying_matrix_with_vector_is_mathematically_correct)
{
  const auto res = random_matrix * random_vector;

  EXPECT_EQ(random_matrix[0] * random_vector.x + random_matrix[1] * random_vector.y, res.x);
  EXPECT_EQ(random_matrix[2] * random_vector.x + random_matrix[3] * random_vector.y, res.y);
}

TEST_F(Matrix2Test, multiplying_vector_with_identity_returns_vector)
{
  const auto res = random_vector * Math::Matrix2<double>::IDENTITY;

  EXPECT_EQ(random_vector.x, res.x);
  EXPECT_EQ(random_vector.y, res.y);
}

TEST_F(Matrix2Test, multiplying_vector_with_matrix_is_mathematically_correct)
{
  const auto res = random_vector * random_matrix;

  EXPECT_EQ(random_matrix[0] * random_vector.x + random_matrix[2] * random_vector.y, res.x);
  EXPECT_EQ(random_matrix[1] * random_vector.x + random_matrix[3] * random_vector.y, res.y);
}

TEST_F(Matrix2Test, transpose_of_identity_is_identity)
{
  auto transpose = Math::Matrix2d::IDENTITY.transpose();

  EXPECT_EQ(1, transpose(0,0));
  EXPECT_EQ(0, transpose(0,1));
  EXPECT_EQ(0, transpose(1,0));
  EXPECT_EQ(1, transpose(1,1));
}

TEST_F(Matrix2Test, transpose_of_matrix_switches_rows_and_columns)
{
  auto transpose = random_matrix.transpose();

  EXPECT_EQ(random_matrix(0,0), transpose(0,0));
  EXPECT_EQ(random_matrix(1,0), transpose(0,1));
  EXPECT_EQ(random_matrix(0,1), transpose(1,0));
  EXPECT_EQ(random_matrix(1,1), transpose(1,1));
}

TEST_F(Matrix2Test, equal_operator_of_same_matrix_returns_true)
{
  EXPECT_EQ(random_matrix, random_matrix);
}

TEST_F(Matrix2Test, equal_operator_of_copies_returns_true)
{
  const Math::Matrix2<double> copy(random_matrix);

  EXPECT_EQ(random_matrix, copy);
}

TEST_F(Matrix2Test, equal_operator_of_similar_matrices_returns_true)
{
  auto array = create_double_array_of_size(4);
  std::array<double, 4> tmp {{array[0], array[1], array[2], array[3]}};
  const Math::Matrix2<double> matrix1(tmp);
  const Math::Matrix2<double> matrix2(tmp);

  EXPECT_EQ(matrix1, matrix2);

  delete[] array;
}

TEST_F(Matrix2Test, equal_operator_of_different_first_components_returns_false)
{
  const Math::Matrix2<double> matrix1(3.4, 5.1, 2.1, 7.8);
  const Math::Matrix2<double> matrix2(3, 5.1, 2.1, 7.8);

  EXPECT_FALSE(matrix1 == matrix2);
}

TEST_F(Matrix2Test, equal_operator_of_different_second_components_returns_false)
{
  const Math::Matrix2<double> matrix1(3.4, 5.1, 2.1, 7.8);
  const Math::Matrix2<double> matrix2(3.4, .1, 2.1, 7.8);

  EXPECT_FALSE(matrix1 == matrix2);
}

TEST_F(Matrix2Test, equal_operator_of_different_third_components_returns_false)
{
  const Math::Matrix2<double> matrix1(3.4, 5.1, 2.1, 7.8);
  const Math::Matrix2<double> matrix2(3.4, 5.1, 6.1, 7.8);

  EXPECT_FALSE(matrix1 == matrix2);
}

TEST_F(Matrix2Test, equal_operator_of_different_forth_components_returns_false)
{
  const Math::Matrix2<double> matrix1(3.4, 5.1, 2.1, 7.8);
  const Math::Matrix2<double> matrix2(3.4, 5.1, 2.1, 8.8);

  EXPECT_FALSE(matrix1 == matrix2);
}

TEST_F(Matrix2Test, unequal_operator_of_same_matrix_returns_false)
{
  const auto matrix = create_random_matrix2();

  EXPECT_FALSE(matrix != matrix);
}

TEST_F(Matrix2Test, unequal_operator_of_copies_returns_false)
{
  const auto matrix = create_random_matrix2();
  const Math::Matrix2<double> copy(matrix);

  EXPECT_FALSE(matrix != copy);
}

TEST_F(Matrix2Test, unequal_operator_of_similar_matrices_returns_false)
{
  auto array = create_double_array_of_size(4);
  std::array<double, 4> tmp {{array[0], array[1], array[2], array[3]}};
  const Math::Matrix2<double> matrix1(tmp);
  const Math::Matrix2<double> matrix2(tmp);

  EXPECT_FALSE(matrix1 != matrix2);

  delete[] array;
}

TEST_F(Matrix2Test, equal_operator_of_different_first_components_returns_true)
{
  const Math::Matrix2<double> matrix1(3.4, 5.1, 2.1, 7.8);
  const Math::Matrix2<double> matrix2(3, 5.1, 2.1, 7.8);
  EXPECT_NE(matrix1, matrix2);
}

TEST_F(Matrix2Test, equal_operator_of_different_second_components_returns_true)
{
  const Math::Matrix2<double> matrix1(3.4, 5.1, 2.1, 7.8);
  const Math::Matrix2<double> matrix2(3.4, .1, 2.1, 7.8);
  EXPECT_NE(matrix1, matrix2);
}

TEST_F(Matrix2Test, equal_operator_of_different_third_components_returns_true)
{
  const Math::Matrix2<double> matrix1(3.4, 5.1, 2.1, 7.8);
  const Math::Matrix2<double> matrix2(3.4, 5.1, 6.1, 7.8);
  EXPECT_NE(matrix1, matrix2);
}

TEST_F(Matrix2Test, equal_operator_of_different_forth_components_returns_true)
{
  const Math::Matrix2<double> matrix1(3.4, 5.1, 2.1, 7.8);
  const Math::Matrix2<double> matrix2(3.4, 5.1, 2.1, 8.8);
  EXPECT_NE(matrix1, matrix2);
}

// Helper functions

const Math::Matrix2<double> create_random_matrix2()
{
  auto tmp = create_double_array_of_size(4);
  std::array<double, 4> array {{tmp[0], tmp[1], tmp[2], tmp[3]}};
  Math::Matrix2<double> matrix(array);

  delete [] tmp;
  return matrix;
}
