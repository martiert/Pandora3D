#include <matrix3.h>
#include <gtest/gtest.h>

#include "test-helpers.h"

const Math::Matrix3d create_random_matrix3d ();

TEST (Matrix3Test, empty_constructor_makes_identity_matrix)
{
    const Math::Matrix3d matrix;

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

TEST (Matrix3Test, index_out_of_range_throws_out_of_range_exception)
{
    const Math::Matrix3d mat1;
    Math::Matrix3d mat2;

    EXPECT_THROW (mat1 (0,3), std::out_of_range);
    EXPECT_THROW (mat1 (3,0), std::out_of_range);
    EXPECT_THROW (mat2 (0,3), std::out_of_range);
    EXPECT_THROW (mat2 (3,0), std::out_of_range);
}

TEST (Matrix3Test, matrix_can_be_constructed_from_array)
{
    BEGIN_MULTITEST

    const auto array = create_double_array_of_size (9);
    const Math::Matrix3d tmp (array);

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

    END_MULTITEST
}

TEST (Matrix3Test, matrix_can_be_specified)
{
    BEGIN_MULTITEST

    const auto array = create_double_array_of_size (9);
    const Math::Matrix3d tmp (array[0], array[1], array[2],
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

    END_MULTITEST
}

TEST (Matrix3Test, matrix_can_be_copied)
{
    BEGIN_MULTITEST

    const auto matrix1 = create_random_matrix3d ();
    const Math::Matrix3d copy (matrix1);

    EXPECT_EQ (matrix1 (0,0), copy (0,0));
    EXPECT_EQ (matrix1 (0,1), copy (0,1));
    EXPECT_EQ (matrix1 (0,2), copy (0,2));

    EXPECT_EQ (matrix1 (1,0), copy (1,0));
    EXPECT_EQ (matrix1 (1,1), copy (1,1));
    EXPECT_EQ (matrix1 (1,2), copy (1,2));

    EXPECT_EQ (matrix1 (2,0), copy (2,0));
    EXPECT_EQ (matrix1 (2,1), copy (2,1));
    EXPECT_EQ (matrix1 (2,2), copy (2,2));

    END_MULTITEST
}

TEST (Matrix3Test, matrix_can_be_assigned)
{
    BEGIN_MULTITEST

    const auto matrix1 = create_random_matrix3d ();
    const Math::Matrix3d copy = matrix1;

    EXPECT_EQ (matrix1 (0,0), copy (0,0));
    EXPECT_EQ (matrix1 (0,1), copy (0,1));
    EXPECT_EQ (matrix1 (0,2), copy (0,2));

    EXPECT_EQ (matrix1 (1,0), copy (1,0));
    EXPECT_EQ (matrix1 (1,1), copy (1,1));
    EXPECT_EQ (matrix1 (1,2), copy (1,2));

    EXPECT_EQ (matrix1 (2,0), copy (2,0));
    EXPECT_EQ (matrix1 (2,1), copy (2,1));
    EXPECT_EQ (matrix1 (2,2), copy (2,2));

    END_MULTITEST
}

TEST (Matrix3Test, index_operator_throws_out_of_range_exception_for_invalid_input)
{
    const auto mat1 = create_random_matrix3d ();
    auto mat2 = create_random_matrix3d ();

    EXPECT_THROW (mat1 (0,3), std::out_of_range);
    EXPECT_THROW (mat1 (3,0), std::out_of_range);
    EXPECT_THROW (mat2 (0,3), std::out_of_range);
    EXPECT_THROW (mat2 (3,0), std::out_of_range);
    EXPECT_THROW (mat1 [9], std::out_of_range);
    EXPECT_THROW (mat2 [9], std::out_of_range);
}

TEST (Matrix3Test, can_cast_matrix_to_pointer_c_style)
{
    const auto matrix = create_random_matrix3d ();
    auto ptr = (const double *) matrix;

    EXPECT_EQ (matrix (0,0), ptr[0]);
    EXPECT_EQ (matrix (0,1), ptr[1]);
    EXPECT_EQ (matrix (0,2), ptr[2]);
    EXPECT_EQ (matrix (1,0), ptr[3]);
    EXPECT_EQ (matrix (1,1), ptr[4]);
    EXPECT_EQ (matrix (1,2), ptr[5]);
    EXPECT_EQ (matrix (2,0), ptr[6]);
    EXPECT_EQ (matrix (2,1), ptr[7]);
    EXPECT_EQ (matrix (2,2), ptr[8]);
}

TEST (Matrix3Test, can_static_cast_matrix_to_pointer)
{
    const auto matrix = create_random_matrix3d ();
    auto ptr = static_cast<const double*> (matrix);

    EXPECT_EQ (matrix (0,0), ptr[0]);
    EXPECT_EQ (matrix (0,1), ptr[1]);
    EXPECT_EQ (matrix (0,2), ptr[2]);
    EXPECT_EQ (matrix (1,0), ptr[3]);
    EXPECT_EQ (matrix (1,1), ptr[4]);
    EXPECT_EQ (matrix (1,2), ptr[5]);
    EXPECT_EQ (matrix (2,0), ptr[6]);
    EXPECT_EQ (matrix (2,1), ptr[7]);
    EXPECT_EQ (matrix (2,2), ptr[8]);
}

TEST (Matrix3Test, manipulating_the_casted_ptr_manipulates_the_matrix)
{
    auto matrix = create_random_matrix3d ();
    auto ptr = static_cast<double*> (matrix);
    ++ptr[3];

    EXPECT_EQ (matrix (0,0), ptr[0]);
    EXPECT_EQ (matrix (0,1), ptr[1]);
    EXPECT_EQ (matrix (0,2), ptr[2]);
    EXPECT_EQ (matrix (1,0), ptr[3]);
    EXPECT_EQ (matrix (1,1), ptr[4]);
    EXPECT_EQ (matrix (1,2), ptr[5]);
    EXPECT_EQ (matrix (2,0), ptr[6]);
    EXPECT_EQ (matrix (2,1), ptr[7]);
    EXPECT_EQ (matrix (2,2), ptr[8]);
}

TEST (Matrix3Test, multiply_scalar_to_matrix_multiplies_each_component_of_the_matrix)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix3d ();
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

    END_MULTITEST
}

TEST (Matrix3Test, multipling_matrix_with_scalar_from_right_multiplies_each_component)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix3d ();
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

    END_MULTITEST
}

TEST (Matrix3Test, multipling_matrix_with_scalar_from_left_multiplies_each_component)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix3d ();
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

    END_MULTITEST
}

TEST (Matrix3Test, dividing_scalar_to_matrix_divides_each_component)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix3d ();
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

    END_MULTITEST
}

TEST (Matrix3Test, dividing_matrix_and_scalar_divides_each_component)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix3d ();
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

    END_MULTITEST
}

TEST (Matrix3Test, adding_matrix_with_matrix_adds_each_element)
{
    BEGIN_MULTITEST

    const auto matrix1 = create_random_matrix3d ();
    const auto matrix2 = create_random_matrix3d ();
    Math::Matrix3d result (matrix1);
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

    END_MULTITEST
}

TEST (Matrix2Test, adding_two_matrices_adds_each_element)
{
    BEGIN_MULTITEST

    const auto matrix1 = create_random_matrix3d ();
    const auto matrix2 = create_random_matrix3d ();
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

    END_MULTITEST
}

TEST (Matrix3Test, subtracting_matrix_from_matrix_subtracts_each_element)
{
    BEGIN_MULTITEST

    const auto matrix1 = create_random_matrix3d ();
    const auto matrix2 = create_random_matrix3d ();
    Math::Matrix3d result (matrix1);
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

    END_MULTITEST
}

TEST (Matrix3Test, subtracting_two_matrices_subtracts_each_element)
{
    BEGIN_MULTITEST

    const auto matrix1 = create_random_matrix3d ();
    const auto matrix2 = create_random_matrix3d ();
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

    END_MULTITEST
}

TEST (Matrix3Test, determinant_of_zero_matrix_is_zero)
{
    const Math::Matrix3d zero (0, 0, 0,
                               0, 0, 0,
                               0, 0, 0);

    EXPECT_EQ (0, zero.determinant ());
}

TEST (Matrix3Test, determinant_of_identity_matrix_is_one)
{
    const Math::Matrix3d identity;
    EXPECT_EQ (1, identity.determinant ());
}

TEST (Matrix3Test, matrix_determinant_follows_mathematical_rules)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix3d ();

    auto det = matrix (0,0) * (matrix (1,1) * matrix (2,2) -
                               matrix (1,2) * matrix (2,1)) -
               matrix (0,1) * (matrix (1,0) * matrix (2,2) -
                               matrix (2,0) * matrix (1,2)) +
               matrix (0,2) * (matrix (1,0) * matrix (2,1) -
                               matrix (2,0) * matrix (1,1));

    EXPECT_EQ (det, matrix.determinant ());

    END_MULTITEST
}

TEST (Matrix3Test, matrix_multipliplied_with_zero_matrix_from_right_is_zero_matrix)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix3d ();
    const Math::Matrix3d zero (0, 0, 0,
                               0, 0, 0,
                               0, 0, 0);
    auto result = matrix * zero;

    for (size_t i = 0; i < 9; ++i)
        EXPECT_EQ (0, result[i]);

    END_MULTITEST
}

TEST (Matrix3Test, matrix_multipliplied_with_zero_matrix_from_left_is_zero_matrix)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix3d ();
    const Math::Matrix3d zero (0, 0, 0,
                               0, 0, 0,
                               0, 0, 0);
    auto result = zero * matrix;

    for (size_t i = 0; i < 9; ++i)
        EXPECT_EQ (0, result[i]);

    END_MULTITEST
}

TEST (Matrix3Test, matrix_multipliplied_with_identity_from_right_is_the_same_matrix_again)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix3d ();
    const Math::Matrix3d identity;
    auto result = matrix * identity;

    for (size_t i = 0; i < 9; ++i)
        EXPECT_EQ (matrix[i], result[i]);

    END_MULTITEST
}

TEST (Matrix3Test, matrix_multipliplied_with_identity_from_left_is_the_same_matrix_again)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix3d ();
    const Math::Matrix3d identity;
    auto result = identity * matrix;

    for (size_t i = 0; i < 9; ++i)
        EXPECT_EQ (matrix[i], result[i]);

    END_MULTITEST
}

TEST (Matrix3Test, matrix_matrix_multiplication_follows_normal_mathematical_rules)
{
    BEGIN_MULTITEST

    const auto mat1 = create_random_matrix3d ();
    const auto mat2 = create_random_matrix3d ();
    auto result = mat1 * mat2;

    for (auto i = 0; i < 3; ++i) {
        for (auto j = 0; j < 3; ++j) {
            auto res = 0.0;
            for (auto k = 0; k < 3; ++k)
                res += mat1 (i,k) * mat2 (k,j);
            EXPECT_EQ (res, result (i,j));
        }
    }

    END_MULTITEST
}

TEST (Matrix3Test, division_by_zero_throws_invalid_argument)
{
    auto matrix = create_random_matrix3d ();

    EXPECT_THROW (matrix / 0.0, std::invalid_argument);
    EXPECT_THROW (matrix /= 0.0, std::invalid_argument);
}

TEST (Matrix3Test, trace_of_zero_matrix_is_zero)
{
    const Math::Matrix3d zero (0, 0, 0,
                               0, 0, 0,
                               0, 0, 0);
    EXPECT_EQ (0, zero.trace ());
}

TEST (Matrix3Test, trace_of_identity_matrix_is_three)
{
    const Math::Matrix3d identity;
    EXPECT_EQ (3, identity.trace ());
}

TEST (Matrix3Test, trace_of_random_matrix_is_sum_of_diagonal)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix3d ();
    auto trace = matrix (0,0) + matrix (1,1) + matrix (2,2);

    EXPECT_EQ (trace, matrix.trace ());

    END_MULTITEST
}

TEST (Matrix3Test, transpose_of_zero_matrix_is_zero)
{
    const Math::Matrix3d zero (0, 0, 0,
                               0, 0, 0,
                               0, 0, 0);
    auto transpose = zero.transpose ();

    for (size_t i = 0; i < 9; ++i)
        EXPECT_EQ (0, transpose[i]);
}

TEST (Matrix3Test, transpose_of_identity_is_identity)
{
    const Math::Matrix3d identity;
    auto transpose = identity.transpose ();

    for (size_t i = 0; i < 9; ++i)
        EXPECT_EQ (identity[i], transpose[i]);
}

TEST (Matrix3Test, transpose_of_matrix_swaps_rows_with_columns)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix3d ();
    auto transpose = matrix.transpose ();

    for (size_t i = 0; i < 3; ++i)
        for (size_t j = 0; j < 3; ++j)
            EXPECT_EQ (matrix (i,j), transpose (j,i));

    END_MULTITEST
}

TEST (Matrix3Test, inverse_of_identity_is_identity)
{
    const Math::Matrix3d matrix;
    auto inverse = matrix.inverse ();

    EXPECT_EQ (1, inverse (0,0));
    EXPECT_EQ (0, inverse (0,1));
    EXPECT_EQ (0, inverse (0,2));

    EXPECT_EQ (0, inverse (1,0));
    EXPECT_EQ (1, inverse (1,1));
    EXPECT_EQ (0, inverse (1,2));

    EXPECT_EQ (0, inverse (2,0));
    EXPECT_EQ (0, inverse (2,1));
    EXPECT_EQ (1, inverse (2,2));
}

TEST (Matrix3Test, matrix_multiplied_with_its_inverse_from_right_is_identity)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix3d ();
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

    END_MULTITEST
}

TEST (Matrix3Test, inverse_of_zero_matrix_throws_runtime_error)
{
    const Math::Matrix3d matrix (0, 0, 0,
                                 0, 0, 0,
                                 0, 0, 0);
    EXPECT_THROW (matrix.inverse (), std::runtime_error);
}

TEST (Matrix3Test, inverse_of_singular_matrix_throws_runtime_error)
{
    const Math::Matrix3d matrix (3.2, 6.4, 1.6,
                                 2.2, 4.4, 1.1,
                                 6.8, 13.6, 3.4);

    EXPECT_THROW (matrix.inverse (), std::runtime_error);
}

TEST (Matrix3Test, equality_of_same_matrix_returns_true)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix3d ();

    EXPECT_EQ (matrix, matrix);

    END_MULTITEST
}

TEST (Matrix3Test, equality_of_copied_matrix_returns_true)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix3d ();
    auto copy = matrix;

    EXPECT_EQ (matrix, copy);

    END_MULTITEST
}

TEST (Matrix3Test, equality_of_equal_matrix_returns_true)
{
    BEGIN_MULTITEST

    auto array = create_double_array_of_size (9);
    const Math::Matrix3d matrix (array);
    const Math::Matrix3d equal (array);

    EXPECT_EQ (matrix, equal);

    delete[] array;

    END_MULTITEST
}

TEST (Matrix3Test, equality_of_matrix_with_one_different_element_returns_false)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix3d ();

    for (int i = 0; i < 9; ++i) {
        auto other = matrix;
        other[i] += 4;

        EXPECT_FALSE (matrix == other);
    }
    END_MULTITEST
}

TEST (Matrix3Test, inequality_of_same_matrix_returns_false)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix3d ();

    EXPECT_FALSE (matrix != matrix);

    END_MULTITEST
}

TEST (Matrix3Test, inequality_of_copied_matrix_returns_false)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix3d ();
    auto copy = matrix;

    EXPECT_FALSE (matrix != copy);

    END_MULTITEST
}

TEST (Matrix3Test, inequality_of_equal_matrix_returns_false)
{
    BEGIN_MULTITEST

    auto array = create_double_array_of_size (9);
    const Math::Matrix3d matrix (array);
    const Math::Matrix3d equal (array);

    EXPECT_FALSE (matrix != equal);

    delete[] array;

    END_MULTITEST
}

TEST (Matrix3Test, inequality_of_matrix_with_one_different_element_returns_true)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix3d ();

    for (int i = 0; i < 9; ++i) {
        auto other = matrix;
        other[i] += 4;

        EXPECT_NE (matrix, other);
    }
    END_MULTITEST
}

const Math::Matrix3d create_random_matrix3d ()
{
    auto array = create_double_array_of_size (9);
    Math::Matrix3d matrix (array);

    delete [] array;
    return matrix;
}
