#include <matrix3.h>
#include <gtest/gtest.h>

#include "test-helpers.h"

const Math::Matrix3<double> create_random_matrix3 ();

TEST (Matrix3Test, empty_constructor_makes_identity_matrix)
{
  const Math::Matrix3<double> matrix;

  EXPECT_EQ (1.0, matrix (0,0));
  EXPECT_EQ (0.0, matrix (0,1));
  EXPECT_EQ (0.0, matrix (0,2));
  EXPECT_EQ (0.0, matrix (1,0));
  EXPECT_EQ (1.0, matrix (1,1));
  EXPECT_EQ (0.0, matrix (1,2));
  EXPECT_EQ (0.0, matrix (2,0));
  EXPECT_EQ (0.0, matrix (2,1));
  EXPECT_EQ (1.0, matrix (2,2));
}

TEST (Matrix3Test, matrix_can_be_constructed_from_array)
{
  const auto c_array = create_double_array_of_size (9);
  const std::array<double, 9> array {{c_array[0], c_array[1], c_array[2],
                                      c_array[3], c_array[4], c_array[5],
                                      c_array[6], c_array[7], c_array[8]}};
  const Math::Matrix3<double> tmp (array);

  EXPECT_EQ (array[0], tmp (0,0));
  EXPECT_EQ (array[1], tmp (0,1));
  EXPECT_EQ (array[2], tmp (0,2));

  EXPECT_EQ (array[3], tmp (1,0));
  EXPECT_EQ (array[4], tmp (1,1));
  EXPECT_EQ (array[5], tmp (1,2));

  EXPECT_EQ (array[6], tmp (2,0));
  EXPECT_EQ (array[7], tmp (2,1));
  EXPECT_EQ (array[8], tmp (2,2));

  delete[] c_array;
}

TEST (Matrix3Test, matrix_can_be_specified)
{
  const auto array = create_double_array_of_size (9);
  const Math::Matrix3<double> tmp (array[0], array[1], array[2],
    array[3], array[4], array[5],
    array[6], array[7], array[8]);

  EXPECT_EQ (array[0], tmp (0,0));
  EXPECT_EQ (array[1], tmp (0,1));
  EXPECT_EQ (array[2], tmp (0,2));
  EXPECT_EQ (array[3], tmp (1,0));
  EXPECT_EQ (array[4], tmp (1,1));
  EXPECT_EQ (array[5], tmp (1,2));
  EXPECT_EQ (array[6], tmp (2,0));
  EXPECT_EQ (array[7], tmp (2,1));
  EXPECT_EQ (array[8], tmp (2,2));

  delete[] array;
}

TEST (Matrix3Test, matrix_can_be_copied)
{
  const auto matrix1 = create_random_matrix3 ();
  const Math::Matrix3<double> copy (matrix1);

  EXPECT_EQ (matrix1 (0,0), copy (0,0));
  EXPECT_EQ (matrix1 (0,1), copy (0,1));
  EXPECT_EQ (matrix1 (0,2), copy (0,2));

  EXPECT_EQ (matrix1 (1,0), copy (1,0));
  EXPECT_EQ (matrix1 (1,1), copy (1,1));
  EXPECT_EQ (matrix1 (1,2), copy (1,2));

  EXPECT_EQ (matrix1 (2,0), copy (2,0));
  EXPECT_EQ (matrix1 (2,1), copy (2,1));
  EXPECT_EQ (matrix1 (2,2), copy (2,2));
}

TEST (Matrix3Test, matrix_can_be_assigned)
{
  const auto matrix1 = create_random_matrix3 ();
  const Math::Matrix3<double> copy = matrix1;

  EXPECT_EQ (matrix1 (0,0), copy (0,0));
  EXPECT_EQ (matrix1 (0,1), copy (0,1));
  EXPECT_EQ (matrix1 (0,2), copy (0,2));

  EXPECT_EQ (matrix1 (1,0), copy (1,0));
  EXPECT_EQ (matrix1 (1,1), copy (1,1));
  EXPECT_EQ (matrix1 (1,2), copy (1,2));

  EXPECT_EQ (matrix1 (2,0), copy (2,0));
  EXPECT_EQ (matrix1 (2,1), copy (2,1));
  EXPECT_EQ (matrix1 (2,2), copy (2,2));
}

TEST (Matrix3Test, multiply_scalar_to_matrix_multiplies_each_component_of_the_matrix)
{
  const auto matrix = create_random_matrix3 ();
  auto scalar = rand () / 100.0;
  auto result (matrix);
  result *= scalar;

  EXPECT_EQ (matrix (0,0) * scalar, result (0,0));
  EXPECT_EQ (matrix (0,1) * scalar, result (0,1));
  EXPECT_EQ (matrix (0,2) * scalar, result (0,2));
  EXPECT_EQ (matrix (1,0) * scalar, result (1,0));
  EXPECT_EQ (matrix (1,1) * scalar, result (1,1));
  EXPECT_EQ (matrix (1,2) * scalar, result (1,2));
  EXPECT_EQ (matrix (2,0) * scalar, result (2,0));
  EXPECT_EQ (matrix (2,1) * scalar, result (2,1));
  EXPECT_EQ (matrix (2,2) * scalar, result (2,2));
}

TEST (Matrix3Test, multipling_matrix_with_scalar_from_right_multiplies_each_component)
{
  const auto matrix = create_random_matrix3 ();
  auto scalar = rand () / 100.0;
  auto result = matrix * scalar;

  EXPECT_EQ (matrix (0,0) * scalar, result (0,0));
  EXPECT_EQ (matrix (0,1) * scalar, result (0,1));
  EXPECT_EQ (matrix (0,2) * scalar, result (0,2));
  EXPECT_EQ (matrix (1,0) * scalar, result (1,0));
  EXPECT_EQ (matrix (1,1) * scalar, result (1,1));
  EXPECT_EQ (matrix (1,2) * scalar, result (1,2));
  EXPECT_EQ (matrix (2,0) * scalar, result (2,0));
  EXPECT_EQ (matrix (2,1) * scalar, result (2,1));
  EXPECT_EQ (matrix (2,2) * scalar, result (2,2));
}

TEST (Matrix3Test, multipling_matrix_with_scalar_from_left_multiplies_each_component)
{
  const auto matrix = create_random_matrix3 ();
  auto scalar = rand () / 100.0;
  auto result = scalar * matrix;

  EXPECT_EQ (matrix (0,0) * scalar, result (0,0));
  EXPECT_EQ (matrix (0,1) * scalar, result (0,1));
  EXPECT_EQ (matrix (0,2) * scalar, result (0,2));
  EXPECT_EQ (matrix (1,0) * scalar, result (1,0));
  EXPECT_EQ (matrix (1,1) * scalar, result (1,1));
  EXPECT_EQ (matrix (1,2) * scalar, result (1,2));
  EXPECT_EQ (matrix (2,0) * scalar, result (2,0));
  EXPECT_EQ (matrix (2,1) * scalar, result (2,1));
  EXPECT_EQ (matrix (2,2) * scalar, result (2,2));
}

TEST (Matrix3Test, dividing_scalar_to_matrix_divides_each_component)
{
  const auto matrix = create_random_matrix3 ();
  auto scalar = rand () / 100.0;
  auto result (matrix);
  result /= scalar;

  EXPECT_EQ (matrix (0,0) / scalar, result (0,0));
  EXPECT_EQ (matrix (0,1) / scalar, result (0,1));
  EXPECT_EQ (matrix (0,2) / scalar, result (0,2));
  EXPECT_EQ (matrix (1,0) / scalar, result (1,0));
  EXPECT_EQ (matrix (1,1) / scalar, result (1,1));
  EXPECT_EQ (matrix (1,2) / scalar, result (1,2));
  EXPECT_EQ (matrix (2,0) / scalar, result (2,0));
  EXPECT_EQ (matrix (2,1) / scalar, result (2,1));
  EXPECT_EQ (matrix (2,2) / scalar, result (2,2));
}

TEST (Matrix3Test, dividing_matrix_and_scalar_divides_each_component)
{
  const auto matrix = create_random_matrix3 ();
  auto scalar = rand () / 100.0;
  auto result = matrix / scalar;

  EXPECT_EQ (matrix (0,0) / scalar, result (0,0));
  EXPECT_EQ (matrix (0,1) / scalar, result (0,1));
  EXPECT_EQ (matrix (0,2) / scalar, result (0,2));
  EXPECT_EQ (matrix (1,0) / scalar, result (1,0));
  EXPECT_EQ (matrix (1,1) / scalar, result (1,1));
  EXPECT_EQ (matrix (1,2) / scalar, result (1,2));
  EXPECT_EQ (matrix (2,0) / scalar, result (2,0));
  EXPECT_EQ (matrix (2,1) / scalar, result (2,1));
  EXPECT_EQ (matrix (2,2) / scalar, result (2,2));
}

TEST (Matrix3Test, adding_matrix_with_matrix_adds_each_element)
{
  const auto matrix1 = create_random_matrix3 ();
  const auto matrix2 = create_random_matrix3 ();
  Math::Matrix3<double> result (matrix1);
  result += matrix2;

  EXPECT_EQ (matrix1 (0,0) + matrix2 (0,0), result (0,0));
  EXPECT_EQ (matrix1 (0,1) + matrix2 (0,1), result (0,1));
  EXPECT_EQ (matrix1 (0,2) + matrix2 (0,2), result (0,2));
  EXPECT_EQ (matrix1 (1,0) + matrix2 (1,0), result (1,0));
  EXPECT_EQ (matrix1 (1,1) + matrix2 (1,1), result (1,1));
  EXPECT_EQ (matrix1 (1,2) + matrix2 (1,2), result (1,2));
  EXPECT_EQ (matrix1 (2,0) + matrix2 (2,0), result (2,0));
  EXPECT_EQ (matrix1 (2,1) + matrix2 (2,1), result (2,1));
  EXPECT_EQ (matrix1 (2,2) + matrix2 (2,2), result (2,2));
}

TEST (Matrix2Test, adding_two_matrices_adds_each_element)
{
  const auto matrix1 = create_random_matrix3 ();
  const auto matrix2 = create_random_matrix3 ();
  auto result = matrix1 + matrix2;

  EXPECT_EQ (matrix1 (0,0) + matrix2 (0,0), result (0,0));
  EXPECT_EQ (matrix1 (0,1) + matrix2 (0,1), result (0,1));
  EXPECT_EQ (matrix1 (0,2) + matrix2 (0,2), result (0,2));
  EXPECT_EQ (matrix1 (1,0) + matrix2 (1,0), result (1,0));
  EXPECT_EQ (matrix1 (1,1) + matrix2 (1,1), result (1,1));
  EXPECT_EQ (matrix1 (1,2) + matrix2 (1,2), result (1,2));
  EXPECT_EQ (matrix1 (2,0) + matrix2 (2,0), result (2,0));
  EXPECT_EQ (matrix1 (2,1) + matrix2 (2,1), result (2,1));
  EXPECT_EQ (matrix1 (2,2) + matrix2 (2,2), result (2,2));
}

TEST (Matrix3Test, subtracting_matrix_from_matrix_subtracts_each_element)
{
  const auto matrix1 = create_random_matrix3 ();
  const auto matrix2 = create_random_matrix3 ();
  Math::Matrix3<double> result (matrix1);
  result -= matrix2;

  EXPECT_EQ (matrix1 (0,0) - matrix2 (0,0), result (0,0));
  EXPECT_EQ (matrix1 (0,1) - matrix2 (0,1), result (0,1));
  EXPECT_EQ (matrix1 (0,2) - matrix2 (0,2), result (0,2));
  EXPECT_EQ (matrix1 (1,0) - matrix2 (1,0), result (1,0));
  EXPECT_EQ (matrix1 (1,1) - matrix2 (1,1), result (1,1));
  EXPECT_EQ (matrix1 (1,2) - matrix2 (1,2), result (1,2));
  EXPECT_EQ (matrix1 (2,0) - matrix2 (2,0), result (2,0));
  EXPECT_EQ (matrix1 (2,1) - matrix2 (2,1), result (2,1));
  EXPECT_EQ (matrix1 (2,2) - matrix2 (2,2), result (2,2));
}

TEST (Matrix3Test, subtracting_two_matrices_subtracts_each_element)
{
  const auto matrix1 = create_random_matrix3 ();
  const auto matrix2 = create_random_matrix3 ();
  auto result = matrix1 - matrix2;

  EXPECT_EQ (matrix1 (0,0) - matrix2 (0,0), result (0,0));
  EXPECT_EQ (matrix1 (0,1) - matrix2 (0,1), result (0,1));
  EXPECT_EQ (matrix1 (0,2) - matrix2 (0,2), result (0,2));
  EXPECT_EQ (matrix1 (1,0) - matrix2 (1,0), result (1,0));
  EXPECT_EQ (matrix1 (1,1) - matrix2 (1,1), result (1,1));
  EXPECT_EQ (matrix1 (1,2) - matrix2 (1,2), result (1,2));
  EXPECT_EQ (matrix1 (2,0) - matrix2 (2,0), result (2,0));
  EXPECT_EQ (matrix1 (2,1) - matrix2 (2,1), result (2,1));
  EXPECT_EQ (matrix1 (2,2) - matrix2 (2,2), result (2,2));
}

TEST (Matrix3Test, determinant_of_zero_matrix_is_zero)
{
  EXPECT_EQ (0, Math::Matrix3<double>::ZERO.determinant ());
}

TEST (Matrix3Test, determinant_of_identity_matrix_is_one)
{
  EXPECT_EQ (1, Math::Matrix3<double>::IDENTITY.determinant ());
}

TEST (Matrix3Test, matrix_determinant_follows_mathematical_rules)
{
  const auto matrix = create_random_matrix3 ();

  auto det = matrix (0,0) * (matrix (1,1) * matrix (2,2) -
    matrix (1,2) * matrix (2,1)) -
  matrix (0,1) * (matrix (1,0) * matrix (2,2) -
      matrix (2,0) * matrix (1,2)) +
  matrix (0,2) * (matrix (1,0) * matrix (2,1) -
      matrix (2,0) * matrix (1,1));

  EXPECT_EQ (det, matrix.determinant ());
}

TEST (Matrix3Test, matrix_multipliplied_with_zero_matrix_from_right_is_zero_matrix)
{
  const auto matrix = create_random_matrix3 ();
  auto result = matrix * Math::Matrix3<double>::ZERO;

  for (size_t i = 0; i < 9; ++i)
    EXPECT_EQ (0, result[i]);
}

TEST (Matrix3Test, matrix_multipliplied_with_zero_matrix_from_left_is_zero_matrix)
{
  const auto matrix = create_random_matrix3 ();
  auto result = Math::Matrix3<double>::ZERO * matrix;

  for (size_t i = 0; i < 9; ++i)
    EXPECT_EQ (0, result[i]);
}

TEST (Matrix3Test, matrix_multipliplied_with_identity_from_right_is_the_same_matrix_again)
{
  const auto matrix = create_random_matrix3 ();
  auto result = matrix * Math::Matrix3<double>::IDENTITY;

  for (size_t i = 0; i < 9; ++i)
    EXPECT_EQ (matrix[i], result[i]);
}

TEST (Matrix3Test, matrix_multipliplied_with_identity_from_left_is_the_same_matrix_again)
{
  const auto matrix = create_random_matrix3 ();
  auto result = Math::Matrix3<double>::IDENTITY * matrix;

  for (size_t i = 0; i < 9; ++i)
    EXPECT_EQ (matrix[i], result[i]);
}

TEST (Matrix3Test, matrix_matrix_multiplication_follows_normal_mathematical_rules)
{
  const auto mat1 = create_random_matrix3 ();
  const auto mat2 = create_random_matrix3 ();
  auto result = mat1 * mat2;

  for (auto i = 0; i < 3; ++i) {
    for (auto j = 0; j < 3; ++j) {
      auto res = 0.0;
      for (auto k = 0; k < 3; ++k)
        res += mat1 (i,k) * mat2 (k,j);
      EXPECT_EQ (res, result (i,j));
    }
  }
}

TEST (Matrix3Test, trace_of_zero_matrix_is_zero)
{
  EXPECT_EQ (0, Math::Matrix3<double>::ZERO.trace ());
}

TEST (Matrix3Test, trace_of_identity_matrix_is_three)
{
  EXPECT_EQ (3, Math::Matrix3<double>::IDENTITY.trace ());
}

TEST (Matrix3Test, trace_of_random_matrix_is_sum_of_diagonal)
{
  const auto matrix = create_random_matrix3 ();
  auto trace = matrix (0,0) + matrix (1,1) + matrix (2,2);

  EXPECT_EQ (trace, matrix.trace ());
}

TEST (Matrix3Test, transpose_of_zero_matrix_is_zero)
{
  auto transpose = Math::Matrix3<double>::ZERO.transpose ();

  for (size_t i = 0; i < 9; ++i)
    EXPECT_EQ (0, transpose[i]);
}

TEST (Matrix3Test, transpose_of_identity_is_identity)
{
  auto transpose = Math::Matrix3<double>::IDENTITY.transpose ();

  for (size_t i = 0; i < 9; ++i)
    EXPECT_EQ (Math::Matrix3<double>::IDENTITY[i], transpose[i]);
}

TEST (Matrix3Test, transpose_of_matrix_swaps_rows_with_columns)
{
  const auto matrix = create_random_matrix3 ();
  auto transpose = matrix.transpose ();

  for (size_t i = 0; i < 3; ++i)
    for (size_t j = 0; j < 3; ++j)
      EXPECT_EQ (matrix (i,j), transpose (j,i));
}

TEST (Matrix3Test, inverse_of_identity_is_identity)
{
  auto inverse = Math::Matrix3<double>::IDENTITY.inverse ();

  for (auto i = 0; i < 9; ++i)
    EXPECT_EQ (Math::Matrix3<double>::IDENTITY[i], inverse[i]);
}

TEST (Matrix3Test, matrix_multiplied_with_its_inverse_from_right_is_identity)
{
  const auto matrix = create_random_matrix3 ();
  auto inverse = matrix.inverse ();
  auto result = matrix * inverse;

  EXPECT_NEAR (1, result (0,0), PRECISION);
  EXPECT_NEAR (0, result (0,1), PRECISION);
  EXPECT_NEAR (0, result (0,2), PRECISION);

  EXPECT_NEAR (0, result (1,0), PRECISION);
  EXPECT_NEAR (1, result (1,1), PRECISION);
  EXPECT_NEAR (0, result (1,2), PRECISION);

  EXPECT_NEAR (0, result (2,0), PRECISION);
  EXPECT_NEAR (0, result (2,1), PRECISION);
  EXPECT_NEAR (1, result (2,2), PRECISION);
}

TEST (Matrix3Test, equality_of_same_matrix_returns_true)
{
  const auto matrix = create_random_matrix3 ();

  EXPECT_EQ (matrix, matrix);
}

TEST (Matrix3Test, equality_of_copied_matrix_returns_true)
{
  const auto matrix = create_random_matrix3 ();
  auto copy = matrix;

  EXPECT_EQ (matrix, copy);
}

TEST (Matrix3Test, equality_of_equal_matrix_returns_true)
{
  const auto c_array = create_double_array_of_size (9);
  const std::array<double, 9> array {{c_array[0], c_array[1], c_array[2],
                                      c_array[3], c_array[4], c_array[5],
                                      c_array[6], c_array[7], c_array[8]}};
  const Math::Matrix3<double> matrix (array);
  const Math::Matrix3<double> equal (array);

  EXPECT_EQ (matrix, equal);

  delete[] c_array;
}

TEST (Matrix3Test, equality_of_matrix_with_one_different_element_returns_false)
{
  const auto matrix = create_random_matrix3 ();

  for (int i = 0; i < 9; ++i) {
    auto other = matrix;
    other[i] += 4;

    EXPECT_FALSE (matrix == other);
  }
}

TEST (Matrix3Test, inequality_of_same_matrix_returns_false)
{
  const auto matrix = create_random_matrix3 ();

  EXPECT_FALSE (matrix != matrix);
}

TEST (Matrix3Test, inequality_of_copied_matrix_returns_false)
{
  const auto matrix = create_random_matrix3 ();
  auto copy = matrix;

  EXPECT_FALSE (matrix != copy);
}

TEST (Matrix3Test, inequality_of_equal_matrix_returns_false)
{
  const auto c_array = create_double_array_of_size (9);
  const std::array<double, 9> array {{c_array[0], c_array[1], c_array[2],
                                      c_array[3], c_array[4], c_array[5],
                                      c_array[6], c_array[7], c_array[8]}};
  const Math::Matrix3<double> matrix (array);
  const Math::Matrix3<double> equal (array);

  EXPECT_FALSE (matrix != equal);

  delete[] c_array;
}

TEST (Matrix3Test, inequality_of_matrix_with_one_different_element_returns_true)
{
  const auto matrix = create_random_matrix3 ();

  for (int i = 0; i < 9; ++i) {
    auto other = matrix;
    other[i] += 4;

    EXPECT_NE (matrix, other);
  }
}

const Math::Matrix3<double> create_random_matrix3 ()
{
  const auto c_array = create_double_array_of_size (9);
  const std::array<double, 9> array {{c_array[0], c_array[1], c_array[2],
                                      c_array[3], c_array[4], c_array[5],
                                      c_array[6], c_array[7], c_array[8]}};
  Math::Matrix3<double> matrix (array);

  delete [] c_array;
  return matrix;
}
