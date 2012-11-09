#include <matrix4.h>
#include <matrix3.h>
#include <vector4.h>

#include <gtest/gtest.h>

#include "test-helpers.h"

const Math::Matrix4d create_random_matrix4();
const Math::Matrix3<double> create_random_matrix3();
const Math::Vec4d create_random_vector4();

class Matrix4Test : public ::testing::Test
{
  protected:
    void SetUp();

    Math::Matrix4d random_matrix;
    Math::Matrix4d random_matrix2;
    Math::Vec4d random_vector;
    double scalar;
};

void Matrix4Test::SetUp()
{
  random_matrix = create_random_matrix4();
  random_matrix2 = create_random_matrix4();
  random_vector = create_random_vector4();
  scalar = rand() / 100.0;
}

TEST_F(Matrix4Test, default_constructor_creates_identity_matrix)
{
  const Math::Matrix4d matrix;

  for (auto i = 0; i < 16; ++i)
    EXPECT_EQ(Math::Matrix4d::IDENTITY[i], matrix[i]);
}

TEST_F(Matrix4Test, constructor_with_arguments_populates_matrix)
{
  const auto array = create_double_array_of_size(16);
  const Math::Matrix4d matrix(array[0], array[1], array[2], array[3],
                                      array[4], array[5], array[6], array[7],
                                      array[8], array[9], array[10], array[11],
                                      array[12], array[13], array[14], array[15]);

  for (auto i = 0; i < 16; ++i)
    EXPECT_EQ(array[i], matrix[i]);

  delete [] array;
}

TEST_F(Matrix4Test, matrix_constructed_from_array_populates_matrix_with_array_values)
{
  auto c_array = create_double_array_of_size(16);
  std::array<double, 16> array {{c_array[0], c_array[1], c_array[2], c_array[3],
                                 c_array[4], c_array[5], c_array[6], c_array[7],
                                 c_array[8], c_array[9], c_array[10], c_array[11],
                                 c_array[12], c_array[13], c_array[14], c_array[15]}};
  const Math::Matrix4d matrix(array);

  for (auto i = 0; i < 16; ++i)
    EXPECT_EQ(array[i], matrix[i]);

  delete [] c_array;
}

TEST_F(Matrix4Test, matrix_created_from_3d_matrix_is_zero_padded_with_one_at_3_3)
{
  const auto matrix3 = create_random_matrix3();
  const Math::Matrix4d matrix(matrix3);

  for (auto i = 0; i < 3; ++i)
    for (auto j = 0; j < 3; ++j)
      EXPECT_EQ(matrix3(i,j), matrix [i*4 + j]);

  for (auto i = 0; i < 3; ++i) {
    EXPECT_EQ(0, matrix(3,i));
    EXPECT_EQ(0, matrix(i,3));
  }

  EXPECT_EQ(1, matrix(3,3));
}

TEST_F(Matrix4Test, copied_matrix_copies_the_elements_from_the_other_matrix)
{
  const auto matrix = create_random_matrix4();
  const Math::Matrix4d copy(matrix);

  for (auto j = 0; j < 16; ++j)
    EXPECT_EQ(matrix[j], copy[j]);
}

TEST_F(Matrix4Test, matrix_assigned_from_3d_matrix_populates_matrix)
{
  const auto matrix3 = create_random_matrix3();
  Math::Matrix4d matrix;
  matrix = matrix3;

  for (auto i = 0; i < 3; ++i)
    for (auto j = 0; j < 3; ++j)
      EXPECT_EQ(matrix3(i,j), matrix [i*4 + j]);

  for (auto i = 0; i < 3; ++i) {
    EXPECT_EQ(0, matrix(3,i));
    EXPECT_EQ(0, matrix(i,3));
  }

  EXPECT_EQ(1, matrix(3,3));
}

TEST_F(Matrix4Test, matrix_assigned_from_array_populates_matrix)
{
  auto c_array = create_double_array_of_size(16);
  std::array<double, 16> array {{c_array[0],  c_array[1],  c_array[2],  c_array[3],
                                 c_array[4],  c_array[5],  c_array[6],  c_array[7],
                                 c_array[8],  c_array[9],  c_array[10], c_array[11],
                                 c_array[12], c_array[13], c_array[14], c_array[15]}};
  Math::Matrix4d matrix;
  matrix = array;

  for (auto i = 0; i < 16; ++i)
    EXPECT_EQ(array[i], matrix[i]);

  delete [] c_array;
}

TEST_F(Matrix4Test, multiplying_matrix_with_scalar_from_right_multiplies_each_element_with_scalar)
{
  const auto result = random_matrix * scalar;

  for (auto i = 0; i < 16; ++i)
    EXPECT_EQ(random_matrix[i] * scalar, result[i]);
}

TEST_F(Matrix4Test, multiplying_matrix_with_scalar_from_left_multiplies_each_element_with_scalar)
{
  const auto result = scalar * random_matrix;

  for (auto i = 0; i < 16; ++i)
    EXPECT_EQ(random_matrix[i] * scalar, result[i]);
}

TEST_F(Matrix4Test, multiplying_scalar_to_matrix_multiplies_each_component_with_scalar)
{
  auto result(random_matrix);
  result *= scalar;

  for (auto i = 0; i < 16; ++i)
    EXPECT_EQ(random_matrix[i] * scalar, result[i]);
}

TEST_F(Matrix4Test, dividing_matrix_with_scalar_from_right_divides_each_element_with_scalar)
{
  const auto result = random_matrix / scalar;

  for (auto i = 0; i < 16; ++i)
    EXPECT_EQ(random_matrix[i] / scalar, result[i]);
}

TEST_F(Matrix4Test, dividing_scalar_to_matrix_divides_each_element_with_scalar)
{
  auto result(random_matrix);

  result /= scalar;

  for (auto i = 0; i < 16; ++i)
    EXPECT_EQ(random_matrix[i] / scalar, result[i]);
}

TEST_F(Matrix4Test, adding_two_matrices_adds_each_component)
{
  auto result = random_matrix + random_matrix2;

  for (auto i = 0; i < 16; ++i)
    EXPECT_EQ(random_matrix[i] + random_matrix2[i], result[i]);
}

TEST_F(Matrix4Test, adding_matrix_to_matrix_adds_each_component)
{
  auto result = random_matrix;
  result += random_matrix2;

  for (auto i = 0; i < 16; ++i)
    EXPECT_EQ(random_matrix[i] + random_matrix2[i], result[i]);
}

TEST_F(Matrix4Test, subtracting_two_matrices_subtracts_each_component)
{
  const auto random_matrix = create_random_matrix4();
  const auto random_matrix2 = create_random_matrix4();
  auto result = random_matrix - random_matrix2;

  for (auto i = 0; i < 16; ++i)
    EXPECT_EQ(random_matrix[i] - random_matrix2[i], result[i]);
}

TEST_F(Matrix4Test, subtracting_matrix_from_matrix_subtracts_each_component)
{
  auto result = random_matrix;
  result -= random_matrix2;

  for (auto i = 0; i < 16; ++i)
    EXPECT_EQ(random_matrix[i] - random_matrix2[i], result[i]);
}

TEST_F(Matrix4Test, multiplying_matrix_with_identity_from_right_returns_matrix)
{
  auto result = random_matrix * Math::Matrix4d::IDENTITY;

  for (auto i = 0; i < 16; ++i)
    EXPECT_EQ(random_matrix[i], result[i]);
}

TEST_F(Matrix4Test, multiplying_random_matrix_with_identity_from_left_returns_random_matrix)
{
  auto result = Math::Matrix4d::IDENTITY * random_matrix;

  for (auto i = 0; i < 16; ++i)
    EXPECT_EQ(random_matrix[i], result[i]);
}

TEST_F(Matrix4Test, multiplying_random_matrix_with_zero_random_matrix_from_right_returns_zero_random_matrix)
{
  auto result = random_matrix * Math::Matrix4d::ZERO;

  for (auto i = 0; i < 16; ++i)
    EXPECT_EQ(0, result[i]);
}

TEST_F(Matrix4Test, multiplying_random_matrix_with_zero_random_matrix_from_left_returns_zero_random_matrix)
{
  auto result = Math::Matrix4d::ZERO * random_matrix;

  for (auto i = 0; i < 16; ++i)
    EXPECT_EQ(0, result[i]);
}

TEST_F(Matrix4Test, matrix_multiplication_follows_mathematical_rules)
{
  const auto result = random_matrix * random_matrix2;

  Math::Matrix4d correct = Math::Matrix4d::ZERO;

  for (auto i = 0; i < 4; ++i)
    for (auto j = 0; j < 4; ++j)
      for (auto k = 0; k < 4; ++k)
        correct(i,j) += random_matrix(i,k) * random_matrix2(k,j);

  for (auto i = 0; i < 16; ++i)
    EXPECT_EQ(correct[i], result[i]);
}

TEST_F(Matrix4Test, transpose_of_identity_is_identity)
{
  const auto trans = Math::Matrix4d::IDENTITY.transpose();

  for (auto i = 0; i < 16; ++i)
    EXPECT_EQ(Math::Matrix4d::IDENTITY[i], trans[i]);
}

TEST_F(Matrix4Test, transpose_of_zero_matrix_is_zero_matrix)
{
  const auto trans = Math::Matrix4d::ZERO.transpose();

  for (auto i = 0; i < 16; ++i)
    EXPECT_EQ(0, trans[i]);
}

TEST_F(Matrix4Test, transpose_of_matrix_switches_rows_and_columns)
{
  const auto result = random_matrix.transpose();

  for (auto i = 0; i < 4; ++i)
    for (auto j = 0; j < 4; ++j)
      EXPECT_EQ(random_matrix(j,i), result(i,j));
}

TEST_F(Matrix4Test, trace_of_zero_matrix_is_zero)
{
  EXPECT_EQ(0, Math::Matrix4d::ZERO.trace());
}

TEST_F(Matrix4Test, trace_of_identity_is_four)
{
  EXPECT_EQ(4, Math::Matrix4d::IDENTITY.trace());
}

TEST_F(Matrix4Test, trace_of_matrix_is_sum_of_diagonal)
{
  EXPECT_EQ(random_matrix(0,0) + random_matrix(1,1) + random_matrix(2,2) + random_matrix(3,3), random_matrix.trace());
}

TEST_F(Matrix4Test, determinant_of_zero_matrix_is_zero)
{
  EXPECT_EQ(0, Math::Matrix4d::ZERO.determinant());
}

TEST_F(Matrix4Test, determinant_of_identity_matrix_is_one)
{
  EXPECT_EQ(1, Math::Matrix4d::IDENTITY.determinant());
}

TEST_F(Matrix4Test, determinant_of_given_matrix_gives_correct_result)
{
  const Math::Matrix4d matrix(4, 3, 1, 7,
    2, 8, 9, 3,
    5, 1, 7, 9,
    8, 3, 1, 5);
  EXPECT_EQ(-2246, matrix.determinant());
}

TEST_F(Matrix4Test, determinant_of_matrix_follows_mathematical_rules)
{
  const double sub1 = random_matrix(1,1) *(random_matrix(2,2) * random_matrix(3,3) - random_matrix(2,3) * random_matrix(3,2)) -
  random_matrix(1,2) *(random_matrix(2,1) * random_matrix(3,3) - random_matrix(2,3) * random_matrix(3,1)) +
  random_matrix(1,3) *(random_matrix(2,1) * random_matrix(3,2) - random_matrix(3,1) * random_matrix(2,2));

  const double sub2 = random_matrix(1,0) *(random_matrix(2,2) * random_matrix(3,3) - random_matrix(2,3) * random_matrix(3,2)) -
  random_matrix(1,2) *(random_matrix(2,0) * random_matrix(3,3) - random_matrix(2,3) * random_matrix(3,0)) +
  random_matrix(1,3) *(random_matrix(2,0) * random_matrix(3,2) - random_matrix(2,2) * random_matrix(3,0));

  const double sub3 = random_matrix(1,0) *(random_matrix(2,1) * random_matrix(3,3) - random_matrix(2,3) * random_matrix(3,1)) -
  random_matrix(1,1) *(random_matrix(2,0) * random_matrix(3,3) - random_matrix(2,3) * random_matrix(3,0)) +
  random_matrix(1,3) *(random_matrix(2,0) * random_matrix(3,1) - random_matrix(2,1) * random_matrix(3,0));

  const double sub4 = random_matrix(1,0) *(random_matrix(2,1) * random_matrix(3,2) - random_matrix(2,2) * random_matrix(3,1)) -
  random_matrix(1,1) *(random_matrix(2,0) * random_matrix(3,2) - random_matrix(2,2) * random_matrix(3,0)) +
  random_matrix(1,2) *(random_matrix(2,0) * random_matrix(3,1) - random_matrix(2,1) * random_matrix(3,0));

  const double determinant = random_matrix(0,0) * sub1 - random_matrix(0,1) * sub2 + random_matrix(0,2) * sub3 - random_matrix(0,3) * sub4;

  EXPECT_EQ(determinant, random_matrix.determinant());
}

TEST_F(Matrix4Test, multiplying_identity_with_vector_returns_the_same_vector)
{
  const auto res = Math::Matrix4d::IDENTITY * random_vector;

  EXPECT_EQ(random_vector[0], res[0]);
  EXPECT_EQ(random_vector[1], res[1]);
  EXPECT_EQ(random_vector[2], res[2]);
  EXPECT_EQ(random_vector[3], res[3]);
}

TEST_F(Matrix4Test, multiplying_matrix_with_random_vector_multiplies_the_random_vector_with_each_row)
{
  const auto res = random_matrix * random_vector;

  EXPECT_EQ(random_matrix[0]*random_vector[0]  + random_matrix[1]*random_vector[1]  + random_matrix[2]*random_vector[2]  + random_matrix[3]*random_vector[3],  res[0]);
  EXPECT_EQ(random_matrix[4]*random_vector[0]  + random_matrix[5]*random_vector[1]  + random_matrix[6]*random_vector[2]  + random_matrix[7]*random_vector[3],  res[1]);
  EXPECT_EQ(random_matrix[8]*random_vector[0]  + random_matrix[9]*random_vector[1]  + random_matrix[10]*random_vector[2] + random_matrix[11]*random_vector[3], res[2]);
  EXPECT_EQ(random_matrix[12]*random_vector[0] + random_matrix[13]*random_vector[1] + random_matrix[14]*random_vector[2] + random_matrix[15]*random_vector[3], res[3]);
}

TEST_F(Matrix4Test, multiplying_random_vector_with_identity_returns_the_random_vector)
{
  const auto res = random_vector * Math::Matrix4d::IDENTITY;

  EXPECT_EQ(random_vector[0], res[0]);
  EXPECT_EQ(random_vector[1], res[1]);
  EXPECT_EQ(random_vector[2], res[2]);
  EXPECT_EQ(random_vector[3], res[3]);
}

TEST_F(Matrix4Test, multiplying_random_vector_with_matrix_multiplies_the_random_vector_with_each_column)
{
  const auto res = random_vector * random_matrix;

  EXPECT_EQ(random_matrix[0]*random_vector[0] + random_matrix[4]*random_vector[1] + random_matrix[8]*random_vector[2]  + random_matrix[12]*random_vector[3], res[0]);
  EXPECT_EQ(random_matrix[1]*random_vector[0] + random_matrix[5]*random_vector[1] + random_matrix[9]*random_vector[2]  + random_matrix[13]*random_vector[3], res[1]);
  EXPECT_EQ(random_matrix[2]*random_vector[0] + random_matrix[6]*random_vector[1] + random_matrix[10]*random_vector[2] + random_matrix[14]*random_vector[3], res[2]);
  EXPECT_EQ(random_matrix[3]*random_vector[0] + random_matrix[7]*random_vector[1] + random_matrix[11]*random_vector[2] + random_matrix[15]*random_vector[3], res[3]);
}

TEST_F(Matrix4Test, inverse_of_identity_is_identity)
{
  const auto res = Math::Matrix4d::IDENTITY.inverse();

  for (auto i = 0; i < 16; ++i)
    EXPECT_EQ(Math::Matrix4d::IDENTITY[i], res[i]);
}

TEST_F(Matrix4Test, inverse_of_matrix_times_matrix_is_identity)
{
  const auto inverse = random_matrix.inverse();
  const auto res = inverse * random_matrix;

  for (auto i = 0; i < 16; ++i)
    EXPECT_NEAR(Math::Matrix4d::IDENTITY[i], res[i], PRECISION);
}

TEST_F(Matrix4Test, matrix_times_inverse_of_matrix_is_identity)
{
  const auto inverse = random_matrix.inverse();
  const auto res = random_matrix * inverse;

  for (auto i = 0; i < 16; ++i)
    EXPECT_NEAR(Math::Matrix4d::IDENTITY[i], res[i], PRECISION);
}

TEST_F(Matrix4Test, equality_operator_on_same_matrix_returns_true)
{
  EXPECT_EQ(random_matrix, random_matrix);
}

TEST_F(Matrix4Test, equality_operator_on_copy_of_matrix_returns_true)
{
  const auto copy = random_matrix;

  EXPECT_EQ(copy, random_matrix);
}

TEST_F(Matrix4Test, equality_operator_on_different_matrix_returns_false)
{
  const auto matrix = create_random_matrix4();
  const auto other = create_random_matrix4();

  EXPECT_FALSE(other == matrix);
}

TEST_F(Matrix4Test, inequality_of_same_matrix_returns_false)
{
  const auto matrix = create_random_matrix4();

  EXPECT_FALSE(matrix != matrix);
}

TEST_F(Matrix4Test, inequality_of_copies_matrix_returns_false)
{
  const auto matrix = create_random_matrix4();
  const auto copy = matrix;

  EXPECT_FALSE(copy != matrix);
}

TEST_F(Matrix4Test, inequality_of_different_matrix_returns_true)
{
  const auto matrix = create_random_matrix4();
  const auto other = create_random_matrix4();

  EXPECT_NE(matrix, other);
}

const Math::Matrix4d create_random_matrix4()
{
  auto c_array = create_double_array_of_size(16);
  std::array<double, 16> array {{c_array[0],  c_array[1],  c_array[2],  c_array[3],
                                 c_array[4],  c_array[5],  c_array[6],  c_array[7],
                                 c_array[8],  c_array[9],  c_array[10], c_array[11],
                                 c_array[12], c_array[13], c_array[14], c_array[15]}};
  Math::Matrix4d matrix(array);

  delete [] c_array;
  return matrix;
}
