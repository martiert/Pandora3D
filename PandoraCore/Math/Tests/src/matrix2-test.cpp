#include <matrix2.h>

#include <gtest/gtest.h>

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
    double tmp[] {2.3, 4.2, 1.5, 7.6};
    const Math::Matrix2d mat1 (tmp);

    EXPECT_EQ (tmp[0], mat1 (0,0));
    EXPECT_EQ (tmp[1], mat1 (0,1));
    EXPECT_EQ (tmp[2], mat1 (1,0));
    EXPECT_EQ (tmp[3], mat1 (1,1));

    tmp[0] = 4.5;
    EXPECT_NE (tmp[0], mat1 (0,0));
}

TEST (Matrix2Test, matrix_can_be_specified)
{
    const Math::Matrix2d mat1 (2.3, 4.1, 5.6, 7.2);

    EXPECT_EQ (2.3, mat1 (0,0));
    EXPECT_EQ (4.1, mat1 (0,1));
    EXPECT_EQ (5.6, mat1 (1,0));
    EXPECT_EQ (7.2, mat1 (1,1));
}

TEST (Matrix2Test, matrix_copies_matrix)
{
    const Math::Matrix2d mat1 (2.3, 1.2, 4.5, 6.7);
    Math::Matrix2d mat2 (mat1);

    EXPECT_EQ (mat1 (0,0), mat2 (0,0));
    EXPECT_EQ (mat1 (0,1), mat2 (0,1));
    EXPECT_EQ (mat1 (1,0), mat2 (1,0));
    EXPECT_EQ (mat1 (1,1), mat2 (1,1));

    mat2(0,1) = 4.0;
    EXPECT_NE (mat1 (0,1), mat2 (0,1));
}

TEST (Matrix2Test, index_operator_throws_out_of_range_exception)
{
    const Math::Matrix2d mat1;
    Math::Matrix2d mat2;

    EXPECT_THROW (mat1 (0,2), std::out_of_range);
    EXPECT_THROW (mat1 (2,0), std::out_of_range);
    EXPECT_THROW (mat2 (0,2), std::out_of_range);
    EXPECT_THROW (mat2 (2,0), std::out_of_range);
}

TEST (Matrix2Test, can_static_cast_matrix_to_pointer)
{
    const Math::Matrix2d matrix (4.3, 5.2, 1.7, 4.3);
    auto ptr = static_cast<const double*> (matrix);

    EXPECT_EQ (ptr[0], matrix (0,0));
    EXPECT_EQ (ptr[1], matrix (0,1));
    EXPECT_EQ (ptr[2], matrix (1,0));
    EXPECT_EQ (ptr[3], matrix (1,1));
}

TEST (Matrix2Test, can_cast_matrix_to_pointer_c_style)
{
    const Math::Matrix2d matrix (4.3, 5.2, 1.7, 4.3);
    auto ptr = (const double *) matrix;

    EXPECT_EQ (ptr[0], matrix (0,0));
    EXPECT_EQ (ptr[1], matrix (0,1));
    EXPECT_EQ (ptr[2], matrix (1,0));
    EXPECT_EQ (ptr[3], matrix (1,1));
}

TEST (Matrix2Test, matrix_multiplication_with_scalar_from_right_multiplies_each_component_with_scalar)
{
    const Math::Matrix2d matrix (4.5, 2.3, 1.2, 6.7);
    auto res = matrix * 3.4;

    EXPECT_EQ (matrix (0,0) * 3.4, res (0,0));
    EXPECT_EQ (matrix (0,1) * 3.4, res (0,1));
    EXPECT_EQ (matrix (1,0) * 3.4, res (1,0));
    EXPECT_EQ (matrix (1,1) * 3.4, res (1,1));
}

TEST (Matrix2Test, matrix_multiplication_with_scalar_from_left_multiplies_each_component_with_scalar)
{
    const Math::Matrix2d matrix (4.5, 2.3, 1.2, 6.7);
    auto res = 4.5 * matrix;

    EXPECT_EQ (matrix (0,0) * 4.5, res (0,0));
    EXPECT_EQ (matrix (0,1) * 4.5, res (0,1));
    EXPECT_EQ (matrix (1,0) * 4.5, res (1,0));
    EXPECT_EQ (matrix (1,1) * 4.5, res (1,1));
}

TEST (Matrix2Test, multiplying_scalar_to_matrix_multiplies_each_component_with_scalar)
{
    const Math::Matrix2d matrix (4.5, 2.3, 1.2, 6.7);
    auto res = matrix;
    res *= 2.3;

    EXPECT_EQ (matrix (0,0) * 2.3, res (0,0));
    EXPECT_EQ (matrix (0,1) * 2.3, res (0,1));
    EXPECT_EQ (matrix (1,0) * 2.3, res (1,0));
    EXPECT_EQ (matrix (1,1) * 2.3, res (1,1));
}

TEST (Matrix2Test, adding_two_matrices_adds_component_wise)
{
    const Math::Matrix2d matrix1 (3.4, 2.1, 5.6, 7.6);
    const Math::Matrix2d matrix2 (2.1, 5.6, 7.2, 3.2);
    auto res = matrix1 + matrix2;

    EXPECT_EQ (matrix1 (0,0) + matrix2 (0,0), res (0,0));
    EXPECT_EQ (matrix1 (0,1) + matrix2 (0,1), res (0,1));
    EXPECT_EQ (matrix1 (1,0) + matrix2 (1,0), res (1,0));
    EXPECT_EQ (matrix1 (1,1) + matrix2 (1,1), res (1,1));
}

TEST (Matrix2Test, adding_matrix_to_matrix_adds_component_wise)
{
    const Math::Matrix2d matrix1 (3.4, 2.1, 5.6, 7.6);
    const Math::Matrix2d matrix2 (2.1, 5.6, 7.2, 3.2);
    auto res (matrix1);
    res += matrix2;

    EXPECT_EQ (matrix1 (0,0) + matrix2 (0,0), res (0,0));
    EXPECT_EQ (matrix1 (0,1) + matrix2 (0,1), res (0,1));
    EXPECT_EQ (matrix1 (1,0) + matrix2 (1,0), res (1,0));
    EXPECT_EQ (matrix1 (1,1) + matrix2 (1,1), res (1,1));
}

TEST (Matrix2Test, subtracting_two_matrices_subtracts_component_wise)
{
    const Math::Matrix2d matrix1 (3.5, 1.2, 6.7, 4.3);
    const Math::Matrix2d matrix2 (2.1, 5.6, 7.2, 3.2);
    auto res = matrix1 - matrix2;

    EXPECT_EQ (matrix1 (0,0) - matrix2 (0,0), res (0,0));
    EXPECT_EQ (matrix1 (0,1) - matrix2 (0,1), res (0,1));
    EXPECT_EQ (matrix1 (1,0) - matrix2 (1,0), res (1,0));
    EXPECT_EQ (matrix1 (1,1) - matrix2 (1,1), res (1,1));
}

TEST (Matrix2Test, subtracting_matrix_from_matrix_subtracts_component_wise)
{
    const Math::Matrix2d matrix1 (3.5, 1.2, 6.7, 4.3);
    const Math::Matrix2d matrix2 (2.1, 5.6, 7.2, 3.2);
    auto res (matrix1);
    res -= matrix2;

    EXPECT_EQ (matrix1 (0,0) - matrix2 (0,0), res (0,0));
    EXPECT_EQ (matrix1 (0,1) - matrix2 (0,1), res (0,1));
    EXPECT_EQ (matrix1 (1,0) - matrix2 (1,0), res (1,0));
    EXPECT_EQ (matrix1 (1,1) - matrix2 (1,1), res (1,1));
}

TEST (Matrix2Test, determinant_of_identity_matrix_is_one)
{
    const Math::Matrix2d identity;
    EXPECT_EQ (1.0, identity.determinant ());
}

TEST (Matrix2Test, determinant_of_zero_matrix_is_zero)
{
    const Math::Matrix2d zero (0, 0, 0, 0);
    EXPECT_EQ (0.0, zero.determinant ());
}

TEST (Matrix2Test, determinant_of_matrix_follows_mathematical_rules)
{
    const Math::Matrix2d matrix (3.4, 2.3, 4.5, 7.9);
    EXPECT_EQ (matrix[0] * matrix[3] - matrix[1] * matrix[2], matrix.determinant ());
}

TEST (Matrix2Test, multiplying_matrix_with_identity_from_right_returns_same_matrix)
{
    const Math::Matrix2d matrix (4.5, 2.1, 2.6, 7.4);
    const Math::Matrix2d identity;
    auto result = matrix * identity;

    EXPECT_EQ (matrix (0,0), result (0,0));
    EXPECT_EQ (matrix (0,1), result (0,1));
    EXPECT_EQ (matrix (1,0), result (1,0));
    EXPECT_EQ (matrix (1,1), result (1,1));
}

TEST (Matrix2Test, multiplying_matrix_with_identity_from_left_returns_same_matrix)
{
    const Math::Matrix2d matrix (4.5, 2.1, 2.6, 7.4);
    const Math::Matrix2d identity;
    auto result = identity * matrix;

    EXPECT_EQ (matrix (0,0), result (0,0));
    EXPECT_EQ (matrix (0,1), result (0,1));
    EXPECT_EQ (matrix (1,0), result (1,0));
    EXPECT_EQ (matrix (1,1), result (1,1));
}

TEST (Matrix2Test, multiply_matrix_with_zero_matrix_from_right_gives_zero_matrix)
{
    const Math::Matrix2d matrix (4.5, 2.1, 2.6, 7.4);
    const Math::Matrix2d zero (0, 0, 0, 0);
    auto result = matrix * zero;

    EXPECT_EQ (0, result (0,0));
    EXPECT_EQ (0, result (0,1));
    EXPECT_EQ (0, result (1,0));
    EXPECT_EQ (0, result (1,1));
}

TEST (Matrix2Test, multiply_matrix_with_zero_matrix_from_left_gives_zero_matrix)
{
    const Math::Matrix2d matrix (4.5, 2.1, 2.6, 7.4);
    const Math::Matrix2d zero (0, 0, 0, 0);
    auto result = zero * matrix;

    EXPECT_EQ (0, result (0,0));
    EXPECT_EQ (0, result (0,1));
    EXPECT_EQ (0, result (1,0));
    EXPECT_EQ (0, result (1,1));
}

TEST (Matrix2Test, matrix_multiplication_follows_mathematical_rules)
{
    const Math::Matrix2d mat1 (2.3, 4.2, 1.2, 6.7);
    const Math::Matrix2d mat2 (4.5, 2.1, 5.6, 9.8);
    auto result = mat1 * mat2;

    EXPECT_EQ (mat1 (0,0) * mat2 (0,0) + mat1 (0,1) * mat2 (1,0), result (0,0));
    EXPECT_EQ (mat1 (0,0) * mat2 (0,1) + mat1 (0,1) * mat2 (1,1), result (0,1));
    EXPECT_EQ (mat1 (1,0) * mat2 (0,0) + mat1 (1,1) * mat2 (1,0), result (1,0));
    EXPECT_EQ (mat1 (1,0) * mat2 (0,1) + mat1 (1,1) * mat2 (1,1), result (1,1));
}

TEST (Matrix2Test, dividing_matrix_and_scalar_divides_each_component)
{
    const Math::Matrix2d matrix (4.5, 2.1, 4.7, 9.8);
    auto result = matrix / 3.4;

    EXPECT_EQ (matrix (0,0) / 3.4, result (0,0));
    EXPECT_EQ (matrix (0,1) / 3.4, result (0,1));
    EXPECT_EQ (matrix (1,0) / 3.4, result (1,0));
    EXPECT_EQ (matrix (1,1) / 3.4, result (1,1));
}

TEST (Matrix2Test, dividing_matrix_with_scalar_divides_each_component)
{
    const Math::Matrix2d matrix (4.5, 2.1, 4.7, 9.8);
    auto result = matrix;
    result /= 3.4;

    EXPECT_EQ (matrix (0,0) / 3.4, result (0,0));
    EXPECT_EQ (matrix (0,1) / 3.4, result (0,1));
    EXPECT_EQ (matrix (1,0) / 3.4, result (1,0));
    EXPECT_EQ (matrix (1,1) / 3.4, result (1,1));
}

TEST (Matrix2Test, dividing_matrix_and_zero_throws_invalid_argument)
{
    const Math::Matrix2d matrix;
    EXPECT_THROW (matrix / 0.0, std::invalid_argument);
}

TEST (Matrix2Test, dividing_matrix_with_zero_throws_invalid_argument)
{
    Math::Matrix2d matrix;
    EXPECT_THROW (matrix /= 0.0, std::invalid_argument);
}

TEST (Matrix2Test, multiplication_with_inverse_from_right_returns_identity)
{
    const Math::Matrix2d matrix (3.4, 2.0, 5.6, 7.2);
    auto inverse = matrix.inverse ();
    auto result = matrix * inverse;

    EXPECT_FLOAT_EQ (1, result (0,0));
    EXPECT_FLOAT_EQ (0, result (0,1));
    EXPECT_FLOAT_EQ (0, result (1,0));
    EXPECT_FLOAT_EQ (1, result (1,1));
}

TEST (Matrix2Test, multiplication_with_inverse_from_left_returns_identity)
{
    const Math::Matrix2d matrix (3.4, 2.0, 5.6, 7.2);
    auto inverse = matrix.inverse ();
    auto result = inverse * matrix;

    EXPECT_FLOAT_EQ (1, result (0,0));
    EXPECT_FLOAT_EQ (0, result (0,1));
    EXPECT_FLOAT_EQ (0, result (1,0));
    EXPECT_FLOAT_EQ (1, result (1,1));
}

TEST (Matrix2Test, transpose_of_identity_is_identity)
{
    const Math::Matrix2d identity;
    auto transpose = identity.transpose ();

    EXPECT_EQ (1, transpose (0,0));
    EXPECT_EQ (0, transpose (0,1));
    EXPECT_EQ (0, transpose (1,0));
    EXPECT_EQ (1, transpose (1,1));
}

TEST (Matrix2Test, transpose_of_matrix_switches_rows_and_columns)
{
    srand (time (NULL));
    for (int i = 0; i < 1000; ++i) {
        Math::Matrix2d matrix;
        matrix (0,0) = rand ();
        matrix (0,1) = rand ();
        matrix (1,0) = rand ();
        matrix (1,1) = rand ();
        auto transpose = matrix.transpose ();

        EXPECT_EQ (matrix (0,0), transpose (0,0));
        EXPECT_EQ (matrix (1,0), transpose (0,1));
        EXPECT_EQ (matrix (0,1), transpose (1,0));
        EXPECT_EQ (matrix (1,1), transpose (1,1));
    }
}

TEST (Matrix2Test, inverse_of_singular_matrix_throws_runtime_error)
{
    const Math::Matrix2d matrix (2.6, 4.8, 1.3, 2.4);
    EXPECT_THROW (matrix.inverse (), std::runtime_error);
}

TEST (Matrix2Test, equal_operator_of_same_matrix_returns_true)
{
    const Math::Matrix2d matrix (3.4, 5.1, 2.1, 7.8);
    EXPECT_EQ (matrix, matrix);
}

TEST (Matrix2Test, equal_operator_of_copies_returns_true)
{
    const Math::Matrix2d matrix (3.4, 5.1, 2.1, 7.8);
    const Math::Matrix2d copy (matrix);
    EXPECT_EQ (matrix, copy);
}

TEST (Matrix2Test, equal_operator_of_similar_matrices_returns_true)
{
    const Math::Matrix2d matrix1 (3.4, 5.1, 2.1, 7.8);
    const Math::Matrix2d matrix2 (3.4, 5.1, 2.1, 7.8);
    EXPECT_EQ (matrix1, matrix2);
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
    const Math::Matrix2d matrix (3.4, 5.1, 2.1, 7.8);
    EXPECT_FALSE (matrix != matrix);
}

TEST (Matrix2Test, unequal_operator_of_copies_returns_false)
{
    const Math::Matrix2d matrix (3.4, 5.1, 2.1, 7.8);
    const Math::Matrix2d copy (matrix);
    EXPECT_FALSE (matrix != copy);
}

TEST (Matrix2Test, unequal_operator_of_similar_matrices_returns_false)
{
    const Math::Matrix2d matrix1 (3.4, 5.1, 2.1, 7.8);
    const Math::Matrix2d matrix2 (3.4, 5.1, 2.1, 7.8);
    EXPECT_FALSE (matrix1 != matrix2);
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
