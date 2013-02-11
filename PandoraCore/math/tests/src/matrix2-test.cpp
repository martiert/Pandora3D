#include "test-helpers.h"

#include <matrix2.h>
#include <vector2.h>
#include <gtest/gtest.h>

const Math::Matrix2d create_random_matrix2();
const Math::Vec2d create_random_vector2();

class Matrix2Test : public ::testing::Test
{
protected:
    void SetUp();
    void TearDown();

    double * array;
    Math::Matrix2d random_matrix;
    Math::Matrix2d random_matrix2;
    Math::Vec2d random_vector;
    double scalar;
};

void Matrix2Test::SetUp()
{
    array = create_double_array_of_size(4);
    random_matrix = create_random_matrix2();
    random_matrix2 = create_random_matrix2();
    random_vector = create_random_vector2();
    scalar = rand() / 100.0;
}

void Matrix2Test::TearDown()
{
    delete[] array;
}

TEST_F(Matrix2Test, empty_constructor_makes_identity_matrix)
{
    const Math::Matrix2d matrix;
    EXPECT_EQ(1.0, matrix(0,0));
    EXPECT_EQ(0.0, matrix(0,1));
    EXPECT_EQ(0.0, matrix(1,0));
    EXPECT_EQ(1.0, matrix(1,1));
}

TEST_F(Matrix2Test, matrix_can_be_specified)
{
    const Math::Matrix2d matrix({array[0], array[1], array[2], array[3]});

    EXPECT_EQ(array[0], matrix(0,0));
    EXPECT_EQ(array[1], matrix(0,1));
    EXPECT_EQ(array[2], matrix(1,0));
    EXPECT_EQ(array[3], matrix(1,1));
}

TEST_F(Matrix2Test, copy_constructor_copies_internals)
{
    const Math::Matrix2d matrix(array);

    EXPECT_EQ(array[0], matrix(0,0));
    EXPECT_EQ(array[1], matrix(0,1));
    EXPECT_EQ(array[2], matrix(1,0));
    EXPECT_EQ(array[3], matrix(1,1));

    array[0] += 4.5;
    EXPECT_NE(array[0], matrix(0,0));
}

TEST_F(Matrix2Test, matrix_copies_matrix)
{
    Math::Matrix2d matrix(random_matrix);

    EXPECT_EQ(random_matrix(0,0), matrix(0,0));
    EXPECT_EQ(random_matrix(0,1), matrix(0,1));
    EXPECT_EQ(random_matrix(1,0), matrix(1,0));
    EXPECT_EQ(random_matrix(1,1), matrix(1,1));

    matrix(0,1) = 4.0;
    EXPECT_NE(random_matrix(0,1), matrix(0,1));
}

TEST_F(Matrix2Test, determinant_of_identity_matrix_is_one)
{
    Math::Matrix2d identity;
    EXPECT_EQ(1.0, matrix_determinant(identity));
}

TEST_F(Matrix2Test, transpose_of_identity_is_identity)
{
    Math::Matrix2d identity;
    auto transpose = matrix_transpose(identity);

    EXPECT_EQ(1, transpose(0,0));
    EXPECT_EQ(0, transpose(0,1));
    EXPECT_EQ(0, transpose(1,0));
    EXPECT_EQ(1, transpose(1,1));
}

TEST_F(Matrix2Test, trace_of_identity_is_two)
{
    Math::Matrix2d identity;
    EXPECT_EQ(2, matrix_trace(identity));
}

TEST_F(Matrix2Test, adjugate_of_identity_matrix_is_identity)
{
    Math::Matrix2d identity;
    auto adjugate = matrix_adjugate(identity);

    EXPECT_EQ(1, adjugate(0,0));
    EXPECT_EQ(0, adjugate(0,1));
    EXPECT_EQ(0, adjugate(1,0));
    EXPECT_EQ(1, adjugate(1,1));
}

TEST_F(Matrix2Test, inverse_of_identity_is_identity)
{
    Math::Matrix2d identity;
    auto inverse = matrix_inverse(identity);

    EXPECT_EQ(1, inverse(0,0));
    EXPECT_EQ(0, inverse(0,1));
    EXPECT_EQ(0, inverse(1,0));
    EXPECT_EQ(1, inverse(1,1));
}

TEST_F(Matrix2Test, adding_matrix_to_matrix_adds_component_wise)
{
    auto result = random_matrix;
    result += random_matrix2;

    EXPECT_EQ(random_matrix(0,0) + random_matrix2(0,0), result(0,0));
    EXPECT_EQ(random_matrix(0,1) + random_matrix2(0,1), result(0,1));
    EXPECT_EQ(random_matrix(1,0) + random_matrix2(1,0), result(1,0));
    EXPECT_EQ(random_matrix(1,1) + random_matrix2(1,1), result(1,1));
}

TEST_F(Matrix2Test, subtracting_matrix_from_matrix_subtracts_component_wise)
{
    auto result(random_matrix);
    result -= random_matrix2;

    EXPECT_EQ(random_matrix(0,0) - random_matrix2(0,0), result(0,0));
    EXPECT_EQ(random_matrix(0,1) - random_matrix2(0,1), result(0,1));
    EXPECT_EQ(random_matrix(1,0) - random_matrix2(1,0), result(1,0));
    EXPECT_EQ(random_matrix(1,1) - random_matrix2(1,1), result(1,1));
}

TEST_F(Matrix2Test, multiplying_scalar_to_matrix_multiplies_each_component_with_scalar)
{
    auto result = random_matrix;
    result *= scalar;

    EXPECT_EQ(random_matrix(0,0) * scalar, result(0,0));
    EXPECT_EQ(random_matrix(0,1) * scalar, result(0,1));
    EXPECT_EQ(random_matrix(1,0) * scalar, result(1,0));
    EXPECT_EQ(random_matrix(1,1) * scalar, result(1,1));
}

TEST_F(Matrix2Test, dividing_matrix_with_scalar_divides_each_component)
{
    auto result = random_matrix;
    result /= scalar;

    EXPECT_FLOAT_EQ(random_matrix(0,0) / scalar, result(0,0));
    EXPECT_FLOAT_EQ(random_matrix(0,1) / scalar, result(0,1));
    EXPECT_FLOAT_EQ(random_matrix(1,0) / scalar, result(1,0));
    EXPECT_FLOAT_EQ(random_matrix(1,1) / scalar, result(1,1));
}

TEST_F(Matrix2Test, adding_two_matrices_adds_component_wise)
{
    auto result = random_matrix + random_matrix2;

    EXPECT_EQ(random_matrix(0,0) + random_matrix2(0,0), result(0,0));
    EXPECT_EQ(random_matrix(0,1) + random_matrix2(0,1), result(0,1));
    EXPECT_EQ(random_matrix(1,0) + random_matrix2(1,0), result(1,0));
    EXPECT_EQ(random_matrix(1,1) + random_matrix2(1,1), result(1,1));
}

TEST_F(Matrix2Test, subtracting_two_matrices_subtracts_component_wise)
{
    auto result = random_matrix - random_matrix2;

    EXPECT_EQ(random_matrix(0,0) - random_matrix2(0,0), result(0,0));
    EXPECT_EQ(random_matrix(0,1) - random_matrix2(0,1), result(0,1));
    EXPECT_EQ(random_matrix(1,0) - random_matrix2(1,0), result(1,0));
    EXPECT_EQ(random_matrix(1,1) - random_matrix2(1,1), result(1,1));
}

TEST_F(Matrix2Test, matrix_multiplication_with_scalar_from_right_multiplies_each_component_with_scalar)
{
    auto result = random_matrix * scalar;

    EXPECT_EQ(random_matrix(0,0) * scalar, result(0,0));
    EXPECT_EQ(random_matrix(0,1) * scalar, result(0,1));
    EXPECT_EQ(random_matrix(1,0) * scalar, result(1,0));
    EXPECT_EQ(random_matrix(1,1) * scalar, result(1,1));
}

TEST_F(Matrix2Test, matrix_multiplication_with_scalar_from_left_multiplies_each_component_with_scalar)
{
    auto result = scalar * random_matrix;

    EXPECT_EQ(random_matrix(0,0) * scalar, result(0,0));
    EXPECT_EQ(random_matrix(0,1) * scalar, result(0,1));
    EXPECT_EQ(random_matrix(1,0) * scalar, result(1,0));
    EXPECT_EQ(random_matrix(1,1) * scalar, result(1,1));
}

TEST_F(Matrix2Test, dividing_matrix_and_scalar_divides_each_component)
{
    auto result = random_matrix / scalar;

    EXPECT_FLOAT_EQ(random_matrix(0,0) / scalar, result(0,0));
    EXPECT_FLOAT_EQ(random_matrix(0,1) / scalar, result(0,1));
    EXPECT_FLOAT_EQ(random_matrix(1,0) / scalar, result(1,0));
    EXPECT_FLOAT_EQ(random_matrix(1,1) / scalar, result(1,1));
}

TEST_F(Matrix2Test, multiplying_identity_with_vector_returns_vector)
{
    Math::Matrix2d identity;
    auto result = identity * random_vector;

    EXPECT_EQ(random_vector[0], result[0]);
    EXPECT_EQ(random_vector[1], result[1]);
}

TEST_F(Matrix2Test, multiplying_vector_with_identity_returns_vector)
{
    Math::Matrix2d identity;
    auto result = random_vector * identity;

    EXPECT_EQ(random_vector[0], result[0]);
    EXPECT_EQ(random_vector[1], result[1]);

}

TEST_F(Matrix2Test, multiplying_matrix_with_identity_from_right_returns_same_matrix)
{
    Math::Matrix2d identity;
    auto result = random_matrix * identity;

    EXPECT_EQ(random_matrix(0,0), result(0,0));
    EXPECT_EQ(random_matrix(0,1), result(0,1));
    EXPECT_EQ(random_matrix(1,0), result(1,0));
    EXPECT_EQ(random_matrix(1,1), result(1,1));
}

TEST_F(Matrix2Test, equal_operator_of_same_matrix_returns_true)
{
    EXPECT_EQ(random_matrix, random_matrix);
}

TEST_F(Matrix2Test, unequal_operator_of_same_matrix_returns_false)
{
    EXPECT_FALSE(random_matrix != random_matrix);
}

TEST_F(Matrix2Test, determinant_of_zero_matrix_is_zero)
{
    Math::Matrix2d zero {{0, 0, 0, 0}};
    EXPECT_EQ(0.0, matrix_determinant(zero));
}

TEST_F(Matrix2Test, determinant_of_matrix_follows_mathematical_rules)
{
    EXPECT_EQ(random_matrix[0] * random_matrix[3] - random_matrix[1] * random_matrix[2],
            matrix_determinant(random_matrix));
}

TEST_F(Matrix2Test, multiplying_matrix_with_identity_from_left_returns_same_matrix)
{
    Math::Matrix2d identity;
    auto result = identity * random_matrix;

    EXPECT_EQ(random_matrix(0,0), result(0,0));
    EXPECT_EQ(random_matrix(0,1), result(0,1));
    EXPECT_EQ(random_matrix(1,0), result(1,0));
    EXPECT_EQ(random_matrix(1,1), result(1,1));
}

TEST_F(Matrix2Test, multiply_matrix_with_zero_matrix_from_right_gives_zero_matrix)
{
    Math::Matrix2d zero {{0, 0, 0, 0}};
    auto result = random_matrix * zero;

    EXPECT_EQ(0, result(0,0));
    EXPECT_EQ(0, result(0,1));
    EXPECT_EQ(0, result(1,0));
    EXPECT_EQ(0, result(1,1));
}

TEST_F(Matrix2Test, multiply_matrix_with_zero_matrix_from_left_gives_zero_matrix)
{
    Math::Matrix2d zero {{0, 0, 0, 0}};
    auto result = zero * random_matrix;

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

TEST_F(Matrix2Test, trace_of_matrix_gives_the_sum_of_the_diagonal)
{
    EXPECT_EQ(random_matrix(0,0) + random_matrix(1,1), matrix_trace(random_matrix));
}

TEST_F(Matrix2Test, adjugate_of_matrix_gives_the_adjugate)
{
    auto adjugate = matrix_adjugate(random_matrix);

    EXPECT_EQ(random_matrix(1,1),   adjugate(0,0));
    EXPECT_EQ(-random_matrix(0,1),  adjugate(0,1));
    EXPECT_EQ(-random_matrix(1,0),  adjugate(1,0));
    EXPECT_EQ(random_matrix(0,0),   adjugate(1,1));
}

TEST_F(Matrix2Test, transpose_of_matrix_switches_rows_and_columns)
{
    auto transpose = matrix_transpose(random_matrix);

    EXPECT_EQ(random_matrix(0,0), transpose(0,0));
    EXPECT_EQ(random_matrix(1,0), transpose(0,1));
    EXPECT_EQ(random_matrix(0,1), transpose(1,0));
    EXPECT_EQ(random_matrix(1,1), transpose(1,1));
}

TEST_F(Matrix2Test, multiplication_with_inverse_from_right_returns_identity)
{
    auto inverse = matrix_inverse(random_matrix);
    auto result = random_matrix * inverse;

    EXPECT_NEAR(1, result(0,0), PRECISION);
    EXPECT_NEAR(0, result(0,1), PRECISION);
    EXPECT_NEAR(0, result(1,0), PRECISION);
    EXPECT_NEAR(1, result(1,1), PRECISION);
}

TEST_F(Matrix2Test, multiplication_with_inverse_from_left_returns_identity)
{
    auto inverse = matrix_inverse(random_matrix);
    auto result = inverse * random_matrix;

    EXPECT_NEAR(1, result(0,0), PRECISION);
    EXPECT_NEAR(0, result(0,1), PRECISION);
    EXPECT_NEAR(0, result(1,0), PRECISION);
    EXPECT_NEAR(1, result(1,1), PRECISION);
}

TEST_F(Matrix2Test, multiplying_matrix_with_vector_is_mathematically_correct)
{
    const auto res = random_matrix * random_vector;

    EXPECT_EQ(random_matrix[0] * random_vector[0] + random_matrix[1] * random_vector[1], res[0]);
    EXPECT_EQ(random_matrix[2] * random_vector[0] + random_matrix[3] * random_vector[1], res[1]);
}

TEST_F(Matrix2Test, multiplying_vector_with_matrix_is_mathematically_correct)
{
    const auto res = random_vector * random_matrix;

    EXPECT_EQ(random_matrix[0] * random_vector[0] + random_matrix[2] * random_vector[1], res[0]);
    EXPECT_EQ(random_matrix[1] * random_vector[0] + random_matrix[3] * random_vector[1], res[1]);
}

TEST_F(Matrix2Test, equal_operator_of_copies_returns_true)
{
    const Math::Matrix2d copy(random_matrix);

    EXPECT_EQ(random_matrix, copy);
}

TEST_F(Matrix2Test, equal_operator_of_similar_matrices_returns_true)
{
    const Math::Matrix2d matrix1(array);
    const Math::Matrix2d matrix2(array);

    EXPECT_EQ(matrix1, matrix2);
}

TEST_F(Matrix2Test, equal_operator_of_different_components_returns_false)
{
    const Math::Matrix2d matrix1({3.4, 5.1, 2.1, 7.8});
    const Math::Matrix2d matrix2({3, 5.1, 2.8, 7.8});

    EXPECT_FALSE(matrix1 == matrix2);
}

TEST_F(Matrix2Test, unequal_operator_of_copies_returns_false)
{
    const Math::Matrix2d copy(random_matrix);

    EXPECT_FALSE(random_matrix != copy);
}

TEST_F(Matrix2Test, unequal_operator_of_similar_matrices_returns_false)
{
    const Math::Matrix2d matrix1(array);
    const Math::Matrix2d matrix2(array);

    EXPECT_FALSE(matrix1 != matrix2);
}

TEST_F(Matrix2Test, equal_operator_of_different_components_returns_true)
{
    const Math::Matrix2d matrix1({3.4, 5.1, 2.8, 7.8});
    const Math::Matrix2d matrix2({3, 5.1, 2.1, 7.8});
    EXPECT_NE(matrix1, matrix2);
}

TEST_F(Matrix2Test, index_operators_out_of_range_asserts)
{
    const auto copy = random_matrix;
    EXPECT_DEATH(random_matrix[4], "Index operator out of range");
    EXPECT_DEATH(copy[4], "Index operator out of range");
    EXPECT_DEATH(random_matrix(0,2), "Index operator out of range");
    EXPECT_DEATH(random_matrix(2,0), "Index operator out of range");
    EXPECT_DEATH(copy(0,2), "Index operator out of range");
    EXPECT_DEATH(copy(2,0), "Index operator out of range");
}
// Helper functions

const Math::Matrix2d create_random_matrix2()
{
    auto array = create_double_array_of_size(4);
    Math::Matrix2d matrix(array);
    delete[] array;
    return matrix;
}
