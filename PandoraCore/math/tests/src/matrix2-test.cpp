#include "test-helpers.h"

#include <matrix2.h>
#include <vector2.h>
#include <gtest/gtest.h>

const Math::Matrix2<double> create_random_matrix2 ();
const Math::Vec2d create_random_vector2 ();

TEST (Matrix2Test, empty_constructor_makes_identity_matrix)
{
  const Math::Matrix2<double> mat1;
  EXPECT_EQ (1.0, mat1 (0,0));
  EXPECT_EQ (0.0, mat1 (0,1));
  EXPECT_EQ (0.0, mat1 (1,0));
  EXPECT_EQ (1.0, mat1 (1,1));
}

TEST (Matrix2Test, matrix_copies_array)
{
  auto array = create_double_array_of_size (4);
  std::array<double, 4> tmp {{array[0], array[1], array[2], array[3]}};
  const Math::Matrix2<double> mat1 (tmp);

  EXPECT_EQ (tmp[0], mat1 (0,0));
  EXPECT_EQ (tmp[1], mat1 (0,1));
  EXPECT_EQ (tmp[2], mat1 (1,0));
  EXPECT_EQ (tmp[3], mat1 (1,1));

  tmp[0] = 4.5;
  EXPECT_NE (tmp[0], mat1 (0,0));

  delete array;
}

TEST (Matrix2Test, matrix_can_be_specified)
{
  auto tmp = create_double_array_of_size (4);
  const Math::Matrix2<double> mat1 (tmp[0], tmp[1], tmp[2], tmp[3]);

  EXPECT_EQ (tmp[0], mat1 (0,0));
  EXPECT_EQ (tmp[1], mat1 (0,1));
  EXPECT_EQ (tmp[2], mat1 (1,0));
  EXPECT_EQ (tmp[3], mat1 (1,1));

  delete[] tmp;}

TEST (Matrix2Test, matrix_copies_matrix)
{
  const auto mat1 = create_random_matrix2 ();
  Math::Matrix2<double> mat2 (mat1);

  EXPECT_EQ (mat1 (0,0), mat2 (0,0));
  EXPECT_EQ (mat1 (0,1), mat2 (0,1));
  EXPECT_EQ (mat1 (1,0), mat2 (1,0));
  EXPECT_EQ (mat1 (1,1), mat2 (1,1));

  mat2(0,1) = 4.0;
  EXPECT_NE (mat1 (0,1), mat2 (0,1));
}

TEST (Matrix2Test, matrix_multiplication_with_scalar_from_right_multiplies_each_component_with_scalar)
{
  const auto matrix = create_random_matrix2 ();
  auto scalar = rand () / 100.0;
  auto res = matrix * scalar;

  EXPECT_EQ (matrix (0,0) * scalar, res (0,0));
  EXPECT_EQ (matrix (0,1) * scalar, res (0,1));
  EXPECT_EQ (matrix (1,0) * scalar, res (1,0));
  EXPECT_EQ (matrix (1,1) * scalar, res (1,1));
}

TEST (Matrix2Test, matrix_multiplication_with_scalar_from_left_multiplies_each_component_with_scalar)
{
  const auto matrix = create_random_matrix2 ();
  auto scalar = rand () / 100.0;
  auto res = scalar * matrix;

  EXPECT_EQ (matrix (0,0) * scalar, res (0,0));
  EXPECT_EQ (matrix (0,1) * scalar, res (0,1));
  EXPECT_EQ (matrix (1,0) * scalar, res (1,0));
  EXPECT_EQ (matrix (1,1) * scalar, res (1,1));
}

TEST (Matrix2Test, multiplying_scalar_to_matrix_multiplies_each_component_with_scalar)
{
  const auto matrix = create_random_matrix2 ();
  auto scalar = rand () / 100.0;
  auto res = matrix;
  res *= scalar;

  EXPECT_EQ (matrix (0,0) * scalar, res (0,0));
  EXPECT_EQ (matrix (0,1) * scalar, res (0,1));
  EXPECT_EQ (matrix (1,0) * scalar, res (1,0));
  EXPECT_EQ (matrix (1,1) * scalar, res (1,1));
}

TEST (Matrix2Test, adding_two_matrices_adds_component_wise)
{
  const auto matrix1 = create_random_matrix2 ();
  const auto matrix2 = create_random_matrix2 ();
  auto res = matrix1 + matrix2;

  EXPECT_EQ (matrix1 (0,0) + matrix2 (0,0), res (0,0));
  EXPECT_EQ (matrix1 (0,1) + matrix2 (0,1), res (0,1));
  EXPECT_EQ (matrix1 (1,0) + matrix2 (1,0), res (1,0));
  EXPECT_EQ (matrix1 (1,1) + matrix2 (1,1), res (1,1));
}

TEST (Matrix2Test, adding_matrix_to_matrix_adds_component_wise)
{
  const auto matrix1 = create_random_matrix2 ();
  const auto matrix2 = create_random_matrix2 ();
  auto res (matrix1);
  res += matrix2;

  EXPECT_EQ (matrix1 (0,0) + matrix2 (0,0), res (0,0));
  EXPECT_EQ (matrix1 (0,1) + matrix2 (0,1), res (0,1));
  EXPECT_EQ (matrix1 (1,0) + matrix2 (1,0), res (1,0));
  EXPECT_EQ (matrix1 (1,1) + matrix2 (1,1), res (1,1));
}

TEST (Matrix2Test, subtracting_two_matrices_subtracts_component_wise)
{
  const auto matrix1 = create_random_matrix2 ();
  const auto matrix2 = create_random_matrix2 ();
  auto res = matrix1 - matrix2;

  EXPECT_EQ (matrix1 (0,0) - matrix2 (0,0), res (0,0));
  EXPECT_EQ (matrix1 (0,1) - matrix2 (0,1), res (0,1));
  EXPECT_EQ (matrix1 (1,0) - matrix2 (1,0), res (1,0));
  EXPECT_EQ (matrix1 (1,1) - matrix2 (1,1), res (1,1));
}

TEST (Matrix2Test, subtracting_matrix_from_matrix_subtracts_component_wise)
{
  const auto matrix1 = create_random_matrix2 ();
  const auto matrix2 = create_random_matrix2 ();
  auto res (matrix1);
  res -= matrix2;

  EXPECT_EQ (matrix1 (0,0) - matrix2 (0,0), res (0,0));
  EXPECT_EQ (matrix1 (0,1) - matrix2 (0,1), res (0,1));
  EXPECT_EQ (matrix1 (1,0) - matrix2 (1,0), res (1,0));
  EXPECT_EQ (matrix1 (1,1) - matrix2 (1,1), res (1,1));
}

TEST (Matrix2Test, determinant_of_identity_matrix_is_one)
{
  EXPECT_EQ (1.0, Math::Matrix2<double>::IDENTITY.determinant ());
}

TEST (Matrix2Test, determinant_of_zero_matrix_is_zero)
{
  EXPECT_EQ (0.0, Math::Matrix2<double>::ZERO.determinant ());
}

TEST (Matrix2Test, determinant_of_matrix_follows_mathematical_rules)
{
  const auto matrix = create_random_matrix2 ();

  EXPECT_EQ (matrix[0] * matrix[3] - matrix[1] * matrix[2], matrix.determinant ());
}

TEST (Matrix2Test, multiplying_matrix_with_identity_from_right_returns_same_matrix)
{
  const auto matrix = create_random_matrix2 ();
  auto result = matrix * Math::Matrix2<double>::IDENTITY;

  EXPECT_EQ (matrix (0,0), result (0,0));
  EXPECT_EQ (matrix (0,1), result (0,1));
  EXPECT_EQ (matrix (1,0), result (1,0));
  EXPECT_EQ (matrix (1,1), result (1,1));
}

TEST (Matrix2Test, multiplying_matrix_with_identity_from_left_returns_same_matrix)
{
  const auto matrix = create_random_matrix2 ();
  auto result = Math::Matrix2<double>::IDENTITY * matrix;

  EXPECT_EQ (matrix (0,0), result (0,0));
  EXPECT_EQ (matrix (0,1), result (0,1));
  EXPECT_EQ (matrix (1,0), result (1,0));
  EXPECT_EQ (matrix (1,1), result (1,1));
}

TEST (Matrix2Test, multiply_matrix_with_zero_matrix_from_right_gives_zero_matrix)
{
  const auto matrix = create_random_matrix2 ();
  auto result = matrix * Math::Matrix2<double>::ZERO;

  EXPECT_EQ (0, result (0,0));
  EXPECT_EQ (0, result (0,1));
  EXPECT_EQ (0, result (1,0));
  EXPECT_EQ (0, result (1,1));
}

TEST (Matrix2Test, multiply_matrix_with_zero_matrix_from_left_gives_zero_matrix)
{
  const auto matrix = create_random_matrix2 ();
  auto result = Math::Matrix2<double>::ZERO * matrix;

  EXPECT_EQ (0, result (0,0));
  EXPECT_EQ (0, result (0,1));
  EXPECT_EQ (0, result (1,0));
  EXPECT_EQ (0, result (1,1));
}

TEST (Matrix2Test, matrix_multiplication_follows_mathematical_rules)
{
  const auto mat1 = create_random_matrix2 ();
  const auto mat2 = create_random_matrix2 ();
  auto result = mat1 * mat2;

  EXPECT_EQ (mat1 (0,0) * mat2 (0,0) + mat1 (0,1) * mat2 (1,0), result (0,0));
  EXPECT_EQ (mat1 (0,0) * mat2 (0,1) + mat1 (0,1) * mat2 (1,1), result (0,1));
  EXPECT_EQ (mat1 (1,0) * mat2 (0,0) + mat1 (1,1) * mat2 (1,0), result (1,0));
  EXPECT_EQ (mat1 (1,0) * mat2 (0,1) + mat1 (1,1) * mat2 (1,1), result (1,1));
}

TEST (Matrix2Test, dividing_matrix_and_scalar_divides_each_component)
{
  const auto matrix = create_random_matrix2 ();
  auto scalar = rand () / 100.0;
  auto result = matrix / scalar;

  EXPECT_EQ (matrix (0,0) / scalar, result (0,0));
  EXPECT_EQ (matrix (0,1) / scalar, result (0,1));
  EXPECT_EQ (matrix (1,0) / scalar, result (1,0));
  EXPECT_EQ (matrix (1,1) / scalar, result (1,1));
}

TEST (Matrix2Test, dividing_matrix_with_scalar_divides_each_component)
{
  const auto matrix = create_random_matrix2 ();
  auto scalar = rand () / 100.0;
  auto result = matrix;
  result /= scalar;

  EXPECT_EQ (matrix (0,0) / scalar, result (0,0));
  EXPECT_EQ (matrix (0,1) / scalar, result (0,1));
  EXPECT_EQ (matrix (1,0) / scalar, result (1,0));
  EXPECT_EQ (matrix (1,1) / scalar, result (1,1));
}

TEST (Matrix2Test, multiplication_with_inverse_from_right_returns_identity)
{
  const auto matrix = create_random_matrix2 ();
  auto inverse = matrix.inverse ();
  auto result = matrix * inverse;

  EXPECT_NEAR (1, result (0,0), PRECISION);
  EXPECT_NEAR (0, result (0,1), PRECISION);
  EXPECT_NEAR (0, result (1,0), PRECISION);
  EXPECT_NEAR (1, result (1,1), PRECISION);
}

TEST (Matrix2Test, multiplication_with_inverse_from_left_returns_identity)
{
  const auto matrix = create_random_matrix2 ();
  auto inverse = matrix.inverse ();
  auto result = inverse * matrix;

  EXPECT_NEAR (1, result (0,0), PRECISION);
  EXPECT_NEAR (0, result (0,1), PRECISION);
  EXPECT_NEAR (0, result (1,0), PRECISION);
  EXPECT_NEAR (1, result (1,1), PRECISION);
}

TEST (Matrix2Test, multiplying_identity_with_vector_returns_vector)
{
  const auto vector = create_random_vector2 ();
  const auto res = Math::Matrix2<double>::IDENTITY * vector;

  EXPECT_EQ (vector.x, res.x);
  EXPECT_EQ (vector.y, res.y);
}

TEST (Matrix2Test, multiplying_matrix_with_vector_is_mathematically_correct)
{
  const auto matrix = create_random_matrix2 ();
  const auto vector = create_random_vector2 ();
  const auto res = matrix * vector;

  EXPECT_EQ (matrix[0] * vector.x + matrix[1] * vector.y, res.x);
  EXPECT_EQ (matrix[2] * vector.x + matrix[3] * vector.y, res.y);
}

TEST (Matrix2Test, multiplying_vector_with_identity_returns_vector)
{
  const auto vector = create_random_vector2 ();
  const auto res = vector * Math::Matrix2<double>::IDENTITY;

  EXPECT_EQ (vector.x, res.x);
  EXPECT_EQ (vector.y, res.y);
}

TEST (Matrix2Test, multiplying_vector_with_matrix_is_mathematically_correct)
{
  const auto matrix = create_random_matrix2 ();
  const auto vector = create_random_vector2 ();
  const auto res = vector * matrix;

  EXPECT_EQ (matrix[0] * vector.x + matrix[2] * vector.y, res.x);
  EXPECT_EQ (matrix[1] * vector.x + matrix[3] * vector.y, res.y);
}

TEST (Matrix2Test, transpose_of_identity_is_identity)
{
  auto transpose = Math::Matrix2<double>::IDENTITY.transpose ();

  EXPECT_EQ (1, transpose (0,0));
  EXPECT_EQ (0, transpose (0,1));
  EXPECT_EQ (0, transpose (1,0));
  EXPECT_EQ (1, transpose (1,1));
}

TEST (Matrix2Test, transpose_of_matrix_switches_rows_and_columns)
{
  const auto matrix = create_random_matrix2 ();
  auto transpose = matrix.transpose ();

  EXPECT_EQ (matrix (0,0), transpose (0,0));
  EXPECT_EQ (matrix (1,0), transpose (0,1));
  EXPECT_EQ (matrix (0,1), transpose (1,0));
  EXPECT_EQ (matrix (1,1), transpose (1,1));
}

TEST (Matrix2Test, equal_operator_of_same_matrix_returns_true)
{
  const auto matrix = create_random_matrix2 ();

  EXPECT_EQ (matrix, matrix);
}

TEST (Matrix2Test, equal_operator_of_copies_returns_true)
{
  const auto matrix = create_random_matrix2 ();
  const Math::Matrix2<double> copy (matrix);

  EXPECT_EQ (matrix, copy);
}

TEST (Matrix2Test, equal_operator_of_similar_matrices_returns_true)
{
  auto array = create_double_array_of_size (4);
  std::array<double, 4> tmp {{array[0], array[1], array[2], array[3]}};
  const Math::Matrix2<double> matrix1 (tmp);
  const Math::Matrix2<double> matrix2 (tmp);

  EXPECT_EQ (matrix1, matrix2);

  delete[] array;
}

TEST (Matrix2Test, equal_operator_of_different_first_components_returns_false)
{
  const Math::Matrix2<double> matrix1 (3.4, 5.1, 2.1, 7.8);
  const Math::Matrix2<double> matrix2 (3, 5.1, 2.1, 7.8);

  EXPECT_FALSE (matrix1 == matrix2);
}

TEST (Matrix2Test, equal_operator_of_different_second_components_returns_false)
{
  const Math::Matrix2<double> matrix1 (3.4, 5.1, 2.1, 7.8);
  const Math::Matrix2<double> matrix2 (3.4, .1, 2.1, 7.8);

  EXPECT_FALSE (matrix1 == matrix2);
}

TEST (Matrix2Test, equal_operator_of_different_third_components_returns_false)
{
  const Math::Matrix2<double> matrix1 (3.4, 5.1, 2.1, 7.8);
  const Math::Matrix2<double> matrix2 (3.4, 5.1, 6.1, 7.8);

  EXPECT_FALSE (matrix1 == matrix2);
}

TEST (Matrix2Test, equal_operator_of_different_forth_components_returns_false)
{
  const Math::Matrix2<double> matrix1 (3.4, 5.1, 2.1, 7.8);
  const Math::Matrix2<double> matrix2 (3.4, 5.1, 2.1, 8.8);

  EXPECT_FALSE (matrix1 == matrix2);
}

TEST (Matrix2Test, unequal_operator_of_same_matrix_returns_false)
{
  const auto matrix = create_random_matrix2 ();

  EXPECT_FALSE (matrix != matrix);
}

TEST (Matrix2Test, unequal_operator_of_copies_returns_false)
{
  const auto matrix = create_random_matrix2 ();
  const Math::Matrix2<double> copy (matrix);

  EXPECT_FALSE (matrix != copy);
}

TEST (Matrix2Test, unequal_operator_of_similar_matrices_returns_false)
{
  auto array = create_double_array_of_size (4);
  std::array<double, 4> tmp {{array[0], array[1], array[2], array[3]}};
  const Math::Matrix2<double> matrix1 (tmp);
  const Math::Matrix2<double> matrix2 (tmp);

  EXPECT_FALSE (matrix1 != matrix2);

  delete[] array;
}

TEST (Matrix2Test, equal_operator_of_different_first_components_returns_true)
{
  const Math::Matrix2<double> matrix1 (3.4, 5.1, 2.1, 7.8);
  const Math::Matrix2<double> matrix2 (3, 5.1, 2.1, 7.8);
  EXPECT_NE (matrix1, matrix2);
}

TEST (Matrix2Test, equal_operator_of_different_second_components_returns_true)
{
  const Math::Matrix2<double> matrix1 (3.4, 5.1, 2.1, 7.8);
  const Math::Matrix2<double> matrix2 (3.4, .1, 2.1, 7.8);
  EXPECT_NE (matrix1, matrix2);
}

TEST (Matrix2Test, equal_operator_of_different_third_components_returns_true)
{
  const Math::Matrix2<double> matrix1 (3.4, 5.1, 2.1, 7.8);
  const Math::Matrix2<double> matrix2 (3.4, 5.1, 6.1, 7.8);
  EXPECT_NE (matrix1, matrix2);
}

TEST (Matrix2Test, equal_operator_of_different_forth_components_returns_true)
{
  const Math::Matrix2<double> matrix1 (3.4, 5.1, 2.1, 7.8);
  const Math::Matrix2<double> matrix2 (3.4, 5.1, 2.1, 8.8);
  EXPECT_NE (matrix1, matrix2);
}

// Helper functions

const Math::Matrix2<double> create_random_matrix2 ()
{
  auto tmp = create_double_array_of_size (4);
  std::array<double, 4> array {{tmp[0], tmp[1], tmp[2], tmp[3]}};
  Math::Matrix2<double> matrix (array);

  delete [] tmp;
  return matrix;
}
