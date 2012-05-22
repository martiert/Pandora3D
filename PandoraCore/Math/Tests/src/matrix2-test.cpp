#include <matrix2.h>
#include <vector2.h>
#include <gtest/gtest.h>

#include "test-helpers.h"

const Math::Matrix2d create_random_matrix2d ();
const Math::Vec2d create_random_vector2d ();

TEST (Matrix2Test, empty_constructor_makes_identity_matrix)
{
    const Math::Matrix2d mat1;
    EXPECT_EQ (1.0, mat1 (0,0));
    EXPECT_EQ (0.0, mat1 (0,1));
    EXPECT_EQ (0.0, mat1 (1,0));
    EXPECT_EQ (1.0, mat1 (1,1));
}

TEST (Matrix2Test, matrix_copies_array)
{
    auto tmp = create_double_array_of_size (4);
    const Math::Matrix2d mat1 (tmp);

    EXPECT_EQ (tmp[0], mat1 (0,0));
    EXPECT_EQ (tmp[1], mat1 (0,1));
    EXPECT_EQ (tmp[2], mat1 (1,0));
    EXPECT_EQ (tmp[3], mat1 (1,1));

    tmp[0] = 4.5;
    EXPECT_NE (tmp[0], mat1 (0,0));

    delete[] tmp;
}

TEST (Matrix2Test, matrix_can_be_specified)
{
    BEGIN_MULTITEST

    auto tmp = create_double_array_of_size (4);
    const Math::Matrix2d mat1 (tmp[0], tmp[1], tmp[2], tmp[3]);

    EXPECT_EQ (tmp[0], mat1 (0,0));
    EXPECT_EQ (tmp[1], mat1 (0,1));
    EXPECT_EQ (tmp[2], mat1 (1,0));
    EXPECT_EQ (tmp[3], mat1 (1,1));

    delete[] tmp;
    END_MULTITEST
}

TEST (Matrix2Test, matrix_copies_matrix)
{
    BEGIN_MULTITEST

    const auto mat1 = create_random_matrix2d ();
    Math::Matrix2d mat2 (mat1);

    EXPECT_EQ (mat1 (0,0), mat2 (0,0));
    EXPECT_EQ (mat1 (0,1), mat2 (0,1));
    EXPECT_EQ (mat1 (1,0), mat2 (1,0));
    EXPECT_EQ (mat1 (1,1), mat2 (1,1));

    mat2(0,1) = 4.0;
    EXPECT_NE (mat1 (0,1), mat2 (0,1));

    END_MULTITEST
}

TEST (Matrix2Test, index_operator_throws_out_of_range_exception)
{
    const auto mat1 = create_random_matrix2d ();
    auto mat2 = create_random_matrix2d ();

    EXPECT_THROW (mat1 (0,2), std::out_of_range);
    EXPECT_THROW (mat1 (2,0), std::out_of_range);
    EXPECT_THROW (mat2 (0,2), std::out_of_range);
    EXPECT_THROW (mat2 (2,0), std::out_of_range);
}

TEST (Matrix2Test, can_static_cast_matrix_to_pointer)
{
    const auto matrix = create_random_matrix2d ();
    auto ptr = static_cast<const double*> (matrix);

    EXPECT_EQ (ptr[0], matrix (0,0));
    EXPECT_EQ (ptr[1], matrix (0,1));
    EXPECT_EQ (ptr[2], matrix (1,0));
    EXPECT_EQ (ptr[3], matrix (1,1));
}

TEST (Matrix2Test, can_cast_matrix_to_pointer_c_style)
{
    const auto matrix = create_random_matrix2d ();
    auto ptr = (const double *) matrix;

    EXPECT_EQ (ptr[0], matrix (0,0));
    EXPECT_EQ (ptr[1], matrix (0,1));
    EXPECT_EQ (ptr[2], matrix (1,0));
    EXPECT_EQ (ptr[3], matrix (1,1));
}

TEST (Matrix2Test, matrix_multiplication_with_scalar_from_right_multiplies_each_component_with_scalar)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix2d ();
    auto scalar = rand () / 100.0;
    auto res = matrix * scalar;

    EXPECT_EQ (matrix (0,0) * scalar, res (0,0));
    EXPECT_EQ (matrix (0,1) * scalar, res (0,1));
    EXPECT_EQ (matrix (1,0) * scalar, res (1,0));
    EXPECT_EQ (matrix (1,1) * scalar, res (1,1));

    END_MULTITEST
}

TEST (Matrix2Test, matrix_multiplication_with_scalar_from_left_multiplies_each_component_with_scalar)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix2d ();
    auto scalar = rand () / 100.0;
    auto res = scalar * matrix;

    EXPECT_EQ (matrix (0,0) * scalar, res (0,0));
    EXPECT_EQ (matrix (0,1) * scalar, res (0,1));
    EXPECT_EQ (matrix (1,0) * scalar, res (1,0));
    EXPECT_EQ (matrix (1,1) * scalar, res (1,1));

    END_MULTITEST
}

TEST (Matrix2Test, multiplying_scalar_to_matrix_multiplies_each_component_with_scalar)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix2d ();
    auto scalar = rand () / 100.0;
    auto res = matrix;
    res *= scalar;

    EXPECT_EQ (matrix (0,0) * scalar, res (0,0));
    EXPECT_EQ (matrix (0,1) * scalar, res (0,1));
    EXPECT_EQ (matrix (1,0) * scalar, res (1,0));
    EXPECT_EQ (matrix (1,1) * scalar, res (1,1));

    END_MULTITEST
}

TEST (Matrix2Test, adding_two_matrices_adds_component_wise)
{
    BEGIN_MULTITEST

    const auto matrix1 = create_random_matrix2d ();
    const auto matrix2 = create_random_matrix2d ();
    auto res = matrix1 + matrix2;

    EXPECT_EQ (matrix1 (0,0) + matrix2 (0,0), res (0,0));
    EXPECT_EQ (matrix1 (0,1) + matrix2 (0,1), res (0,1));
    EXPECT_EQ (matrix1 (1,0) + matrix2 (1,0), res (1,0));
    EXPECT_EQ (matrix1 (1,1) + matrix2 (1,1), res (1,1));

    END_MULTITEST
}

TEST (Matrix2Test, adding_matrix_to_matrix_adds_component_wise)
{
    BEGIN_MULTITEST

    const auto matrix1 = create_random_matrix2d ();
    const auto matrix2 = create_random_matrix2d ();
    auto res (matrix1);
    res += matrix2;

    EXPECT_EQ (matrix1 (0,0) + matrix2 (0,0), res (0,0));
    EXPECT_EQ (matrix1 (0,1) + matrix2 (0,1), res (0,1));
    EXPECT_EQ (matrix1 (1,0) + matrix2 (1,0), res (1,0));
    EXPECT_EQ (matrix1 (1,1) + matrix2 (1,1), res (1,1));

    END_MULTITEST
}

TEST (Matrix2Test, subtracting_two_matrices_subtracts_component_wise)
{
    BEGIN_MULTITEST

    const auto matrix1 = create_random_matrix2d ();
    const auto matrix2 = create_random_matrix2d ();
    auto res = matrix1 - matrix2;

    EXPECT_EQ (matrix1 (0,0) - matrix2 (0,0), res (0,0));
    EXPECT_EQ (matrix1 (0,1) - matrix2 (0,1), res (0,1));
    EXPECT_EQ (matrix1 (1,0) - matrix2 (1,0), res (1,0));
    EXPECT_EQ (matrix1 (1,1) - matrix2 (1,1), res (1,1));

    END_MULTITEST
}

TEST (Matrix2Test, subtracting_matrix_from_matrix_subtracts_component_wise)
{
    BEGIN_MULTITEST

    const auto matrix1 = create_random_matrix2d ();
    const auto matrix2 = create_random_matrix2d ();
    auto res (matrix1);
    res -= matrix2;

    EXPECT_EQ (matrix1 (0,0) - matrix2 (0,0), res (0,0));
    EXPECT_EQ (matrix1 (0,1) - matrix2 (0,1), res (0,1));
    EXPECT_EQ (matrix1 (1,0) - matrix2 (1,0), res (1,0));
    EXPECT_EQ (matrix1 (1,1) - matrix2 (1,1), res (1,1));

    END_MULTITEST
}

TEST (Matrix2Test, determinant_of_identity_matrix_is_one)
{
    EXPECT_EQ (1.0, Math::Matrix2d::IDENTITY.determinant ());
}

TEST (Matrix2Test, determinant_of_zero_matrix_is_zero)
{
    EXPECT_EQ (0.0, Math::Matrix2d::ZERO.determinant ());
}

TEST (Matrix2Test, determinant_of_matrix_follows_mathematical_rules)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix2d ();

    EXPECT_EQ (matrix[0] * matrix[3] - matrix[1] * matrix[2], matrix.determinant ());

    END_MULTITEST
}

TEST (Matrix2Test, multiplying_matrix_with_identity_from_right_returns_same_matrix)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix2d ();
    auto result = matrix * Math::Matrix2d::IDENTITY;

    EXPECT_EQ (matrix (0,0), result (0,0));
    EXPECT_EQ (matrix (0,1), result (0,1));
    EXPECT_EQ (matrix (1,0), result (1,0));
    EXPECT_EQ (matrix (1,1), result (1,1));

    END_MULTITEST
}

TEST (Matrix2Test, multiplying_matrix_with_identity_from_left_returns_same_matrix)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix2d ();
    auto result = Math::Matrix2d::IDENTITY * matrix;

    EXPECT_EQ (matrix (0,0), result (0,0));
    EXPECT_EQ (matrix (0,1), result (0,1));
    EXPECT_EQ (matrix (1,0), result (1,0));
    EXPECT_EQ (matrix (1,1), result (1,1));

    END_MULTITEST
}

TEST (Matrix2Test, multiply_matrix_with_zero_matrix_from_right_gives_zero_matrix)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix2d ();
    auto result = matrix * Math::Matrix2d::ZERO;

    EXPECT_EQ (0, result (0,0));
    EXPECT_EQ (0, result (0,1));
    EXPECT_EQ (0, result (1,0));
    EXPECT_EQ (0, result (1,1));

    END_MULTITEST
}

TEST (Matrix2Test, multiply_matrix_with_zero_matrix_from_left_gives_zero_matrix)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix2d ();
    auto result = Math::Matrix2d::ZERO * matrix;

    EXPECT_EQ (0, result (0,0));
    EXPECT_EQ (0, result (0,1));
    EXPECT_EQ (0, result (1,0));
    EXPECT_EQ (0, result (1,1));

    END_MULTITEST
}

TEST (Matrix2Test, matrix_multiplication_follows_mathematical_rules)
{
    BEGIN_MULTITEST

    const auto mat1 = create_random_matrix2d ();
    const auto mat2 = create_random_matrix2d ();
    auto result = mat1 * mat2;

    EXPECT_EQ (mat1 (0,0) * mat2 (0,0) + mat1 (0,1) * mat2 (1,0), result (0,0));
    EXPECT_EQ (mat1 (0,0) * mat2 (0,1) + mat1 (0,1) * mat2 (1,1), result (0,1));
    EXPECT_EQ (mat1 (1,0) * mat2 (0,0) + mat1 (1,1) * mat2 (1,0), result (1,0));
    EXPECT_EQ (mat1 (1,0) * mat2 (0,1) + mat1 (1,1) * mat2 (1,1), result (1,1));

    END_MULTITEST
}

TEST (Matrix2Test, dividing_matrix_and_scalar_divides_each_component)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix2d ();
    auto scalar = rand () / 100.0;
    auto result = matrix / scalar;

    EXPECT_EQ (matrix (0,0) / scalar, result (0,0));
    EXPECT_EQ (matrix (0,1) / scalar, result (0,1));
    EXPECT_EQ (matrix (1,0) / scalar, result (1,0));
    EXPECT_EQ (matrix (1,1) / scalar, result (1,1));

    END_MULTITEST
}

TEST (Matrix2Test, dividing_matrix_with_scalar_divides_each_component)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix2d ();
    auto scalar = rand () / 100.0;
    auto result = matrix;
    result /= scalar;

    EXPECT_EQ (matrix (0,0) / scalar, result (0,0));
    EXPECT_EQ (matrix (0,1) / scalar, result (0,1));
    EXPECT_EQ (matrix (1,0) / scalar, result (1,0));
    EXPECT_EQ (matrix (1,1) / scalar, result (1,1));

    END_MULTITEST
}

TEST (Matrix2Test, dividing_matrix_and_zero_throws_invalid_argument)
{
    const auto matrix = create_random_matrix2d ();

    EXPECT_THROW (matrix / 0.0, std::invalid_argument);
}

TEST (Matrix2Test, dividing_matrix_with_zero_throws_invalid_argument)
{
    auto matrix = create_random_matrix2d ();

    EXPECT_THROW (matrix /= 0.0, std::invalid_argument);
}

TEST (Matrix2Test, multiplication_with_inverse_from_right_returns_identity)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix2d ();
    auto inverse = matrix.inverse ();
    auto result = matrix * inverse;

    EXPECT_NEAR (1, result (0,0), PRECISION);
    EXPECT_NEAR (0, result (0,1), PRECISION);
    EXPECT_NEAR (0, result (1,0), PRECISION);
    EXPECT_NEAR (1, result (1,1), PRECISION);

    END_MULTITEST
}

TEST (Matrix2Test, multiplication_with_inverse_from_left_returns_identity)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix2d ();
    auto inverse = matrix.inverse ();
    auto result = inverse * matrix;

    EXPECT_NEAR (1, result (0,0), PRECISION);
    EXPECT_NEAR (0, result (0,1), PRECISION);
    EXPECT_NEAR (0, result (1,0), PRECISION);
    EXPECT_NEAR (1, result (1,1), PRECISION);

    END_MULTITEST
}

TEST (Matrix2Test, multiplying_identity_with_vector_returns_vector)
{
    BEGIN_MULTITEST

    const auto vector = create_random_vector2d ();
    const auto res = Math::Matrix2d::IDENTITY * vector;

    EXPECT_EQ (vector.x, res.x);
    EXPECT_EQ (vector.y, res.y);

    END_MULTITEST
}

TEST (Matrix2Test, multiplying_matrix_with_vector_is_mathematically_correct)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix2d ();
    const auto vector = create_random_vector2d ();
    const auto res = matrix * vector;

    EXPECT_EQ (matrix[0] * vector.x + matrix[1] * vector.y, res.x);
    EXPECT_EQ (matrix[2] * vector.x + matrix[3] * vector.y, res.y);

    END_MULTITEST
}

TEST (Matrix2Test, multiplying_vector_with_identity_returns_vector)
{
    BEGIN_MULTITEST

    const auto vector = create_random_vector2d ();
    const auto res = vector * Math::Matrix2d::IDENTITY;

    EXPECT_EQ (vector.x, res.x);
    EXPECT_EQ (vector.y, res.y);

    END_MULTITEST
}

TEST (Matrix2Test, multiplying_vector_with_matrix_is_mathematically_correct)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix2d ();
    const auto vector = create_random_vector2d ();
    const auto res = vector * matrix;

    EXPECT_EQ (matrix[0] * vector.x + matrix[2] * vector.y, res.x);
    EXPECT_EQ (matrix[1] * vector.x + matrix[3] * vector.y, res.y);

    END_MULTITEST
}

TEST (Matrix2Test, transpose_of_identity_is_identity)
{
    BEGIN_MULTITEST

    auto transpose = Math::Matrix2d::IDENTITY.transpose ();

    EXPECT_EQ (1, transpose (0,0));
    EXPECT_EQ (0, transpose (0,1));
    EXPECT_EQ (0, transpose (1,0));
    EXPECT_EQ (1, transpose (1,1));

    END_MULTITEST
}

TEST (Matrix2Test, transpose_of_matrix_switches_rows_and_columns)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix2d ();
    auto transpose = matrix.transpose ();

    EXPECT_EQ (matrix (0,0), transpose (0,0));
    EXPECT_EQ (matrix (1,0), transpose (0,1));
    EXPECT_EQ (matrix (0,1), transpose (1,0));
    EXPECT_EQ (matrix (1,1), transpose (1,1));

    END_MULTITEST
}

TEST (Matrix2Test, inverse_of_singular_matrix_throws_runtime_error)
{
    const Math::Matrix2d matrix (2.6, 4.8, 1.3, 2.4);

    EXPECT_THROW (matrix.inverse (), std::runtime_error);
}

TEST (Matrix2Test, equal_operator_of_same_matrix_returns_true)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix2d ();

    EXPECT_EQ (matrix, matrix);

    END_MULTITEST
}

TEST (Matrix2Test, equal_operator_of_copies_returns_true)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix2d ();
    const Math::Matrix2d copy (matrix);

    EXPECT_EQ (matrix, copy);

    END_MULTITEST
}

TEST (Matrix2Test, equal_operator_of_similar_matrices_returns_true)
{
    BEGIN_MULTITEST

    auto array = create_double_array_of_size (4);
    const Math::Matrix2d matrix1 (array);
    const Math::Matrix2d matrix2 (array);

    EXPECT_EQ (matrix1, matrix2);

    delete[] array;
    END_MULTITEST
}

TEST (Matrix2Test, equal_operator_of_different_first_components_returns_false)
{
    const Math::Matrix2d matrix1 (3.4, 5.1, 2.1, 7.8);
    const Math::Matrix2d matrix2 (3, 5.1, 2.1, 7.8);

    EXPECT_FALSE (matrix1 == matrix2);
}

TEST (Matrix2Test, equal_operator_of_different_second_components_returns_false)
{
    const Math::Matrix2d matrix1 (3.4, 5.1, 2.1, 7.8);
    const Math::Matrix2d matrix2 (3.4, .1, 2.1, 7.8);

    EXPECT_FALSE (matrix1 == matrix2);
}

TEST (Matrix2Test, equal_operator_of_different_third_components_returns_false)
{
    const Math::Matrix2d matrix1 (3.4, 5.1, 2.1, 7.8);
    const Math::Matrix2d matrix2 (3.4, 5.1, 6.1, 7.8);

    EXPECT_FALSE (matrix1 == matrix2);
}

TEST (Matrix2Test, equal_operator_of_different_forth_components_returns_false)
{
    const Math::Matrix2d matrix1 (3.4, 5.1, 2.1, 7.8);
    const Math::Matrix2d matrix2 (3.4, 5.1, 2.1, 8.8);

    EXPECT_FALSE (matrix1 == matrix2);
}

TEST (Matrix2Test, unequal_operator_of_same_matrix_returns_false)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix2d ();

    EXPECT_FALSE (matrix != matrix);

    END_MULTITEST
}

TEST (Matrix2Test, unequal_operator_of_copies_returns_false)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix2d ();
    const Math::Matrix2d copy (matrix);

    EXPECT_FALSE (matrix != copy);

    END_MULTITEST
}

TEST (Matrix2Test, unequal_operator_of_similar_matrices_returns_false)
{
    BEGIN_MULTITEST

    auto array = create_double_array_of_size (4);
    const Math::Matrix2d matrix1 (array);
    const Math::Matrix2d matrix2 (array);

    EXPECT_FALSE (matrix1 != matrix2);

    delete[] array;
    END_MULTITEST
}

TEST (Matrix2Test, equal_operator_of_different_first_components_returns_true)
{
    const Math::Matrix2d matrix1 (3.4, 5.1, 2.1, 7.8);
    const Math::Matrix2d matrix2 (3, 5.1, 2.1, 7.8);
    EXPECT_NE (matrix1, matrix2);
}

TEST (Matrix2Test, equal_operator_of_different_second_components_returns_true)
{
    const Math::Matrix2d matrix1 (3.4, 5.1, 2.1, 7.8);
    const Math::Matrix2d matrix2 (3.4, .1, 2.1, 7.8);
    EXPECT_NE (matrix1, matrix2);
}

TEST (Matrix2Test, equal_operator_of_different_third_components_returns_true)
{
    const Math::Matrix2d matrix1 (3.4, 5.1, 2.1, 7.8);
    const Math::Matrix2d matrix2 (3.4, 5.1, 6.1, 7.8);
    EXPECT_NE (matrix1, matrix2);
}

TEST (Matrix2Test, equal_operator_of_different_forth_components_returns_true)
{
    const Math::Matrix2d matrix1 (3.4, 5.1, 2.1, 7.8);
    const Math::Matrix2d matrix2 (3.4, 5.1, 2.1, 8.8);
    EXPECT_NE (matrix1, matrix2);
}

// Helper functions

const Math::Matrix2d create_random_matrix2d ()
{
    auto array = create_double_array_of_size (4);
    Math::Matrix2d matrix (array);

    delete [] array;
    return matrix;
}
