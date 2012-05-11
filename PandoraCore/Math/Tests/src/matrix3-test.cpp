#include <Math/matrix3.h>

#include <gtest/gtest.h>
#include <cmath>

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
    const double array[] {3.2, 4.5, 1.2,
                    6.7, 4.3, 8.7,
                    3.1, 8.9, 2.3};

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
}

TEST (Matrix3Test, matrix_can_be_specified)
{
    const Math::Matrix3d tmp (3.4, 5.6, 7.1,
                              4.5, 2.1, 9.8,
                              2.2, 4.7, 3.3);
    EXPECT_EQ (3.4, tmp (0,0));
    EXPECT_EQ (5.6, tmp (0,1));
    EXPECT_EQ (7.1, tmp (0,2));
    EXPECT_EQ (4.5, tmp (1,0));
    EXPECT_EQ (2.1, tmp (1,1));
    EXPECT_EQ (9.8, tmp (1,2));
    EXPECT_EQ (2.2, tmp (2,0));
    EXPECT_EQ (4.7, tmp (2,1));
    EXPECT_EQ (3.3, tmp (2,2));
}

TEST (Matrix3Test, matrix_can_be_copied)
{
    const Math::Matrix3d matrix1 (3.4, 2.1, 5.6,
                                  7.8, 3.2, 4.5,
                                  9.2, 3.4, 1.1);
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
}

TEST (Matrix3Test, matrix_can_be_assigned)
{
    const Math::Matrix3d matrix1 (3.4, 2.1, 5.6,
                                  7.8, 3.2, 4.5,
                                  9.2, 3.4, 1.1);
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
}

TEST (Matrix3Test, index_operator_throws_out_of_range_exception_for_invalid_input)
{
    const Math::Matrix3d mat1;
    Math::Matrix3d mat2;

    EXPECT_THROW (mat1 (0,3), std::out_of_range);
    EXPECT_THROW (mat1 (3,0), std::out_of_range);
    EXPECT_THROW (mat2 (0,3), std::out_of_range);
    EXPECT_THROW (mat2 (3,0), std::out_of_range);
    EXPECT_THROW (mat1 [9], std::out_of_range);
    EXPECT_THROW (mat2 [9], std::out_of_range);
}

TEST (Matrix3Test, can_cast_matrix_to_pointer_c_style)
{
    const Math::Matrix3d matrix (2.3, 4.1, 6.5,
                                  1.8, 4.5, 9.8,
                                  4.4, 3.2, 3.4);
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
    const Math::Matrix3d matrix (2.3, 4.1, 6.5,
                            1.8, 4.5, 9.8,
                            4.4, 3.2, 3.4);
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
    Math::Matrix3d matrix (2.3, 4.1, 6.5,
                            1.8, 4.5, 9.8,
                            4.4, 3.2, 3.4);
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
    Math::Matrix3d matrix (2.3, 5.1, 3.3,
                            7.8, 5.9, 9.9,
                            8.7, 4.3, 2.2);

    auto result (matrix);
    result *= 5.6;

    EXPECT_EQ (matrix (0,0) * 5.6, result (0,0));
    EXPECT_EQ (matrix (0,1) * 5.6, result (0,1));
    EXPECT_EQ (matrix (0,2) * 5.6, result (0,2));
    EXPECT_EQ (matrix (1,0) * 5.6, result (1,0));
    EXPECT_EQ (matrix (1,1) * 5.6, result (1,1));
    EXPECT_EQ (matrix (1,2) * 5.6, result (1,2));
    EXPECT_EQ (matrix (2,0) * 5.6, result (2,0));
    EXPECT_EQ (matrix (2,1) * 5.6, result (2,1));
    EXPECT_EQ (matrix (2,2) * 5.6, result (2,2));
}

TEST (Matrix3Test, multipling_matrix_with_scalar_from_right_multiplies_each_component)
{
    const Math::Matrix3d matrix (2.3, 4.1, 6.5,
                                  1.8, 4.5, 9.8,
                                  4.4, 3.2, 3.4);

    auto result = matrix * 4.3;

    EXPECT_EQ (matrix (0,0) * 4.3, result (0,0));
    EXPECT_EQ (matrix (0,1) * 4.3, result (0,1));
    EXPECT_EQ (matrix (0,2) * 4.3, result (0,2));
    EXPECT_EQ (matrix (1,0) * 4.3, result (1,0));
    EXPECT_EQ (matrix (1,1) * 4.3, result (1,1));
    EXPECT_EQ (matrix (1,2) * 4.3, result (1,2));
    EXPECT_EQ (matrix (2,0) * 4.3, result (2,0));
    EXPECT_EQ (matrix (2,1) * 4.3, result (2,1));
    EXPECT_EQ (matrix (2,2) * 4.3, result (2,2));
}

TEST (Matrix3Test, multipling_matrix_with_scalar_from_left_multiplies_each_component)
{
    const Math::Matrix3d matrix (2.3, 4.1, 6.5,
                                  1.8, 4.5, 9.8,
                                  4.4, 3.2, 3.4);

    auto result = 4.3 * matrix;

    EXPECT_EQ (matrix (0,0) * 4.3, result (0,0));
    EXPECT_EQ (matrix (0,1) * 4.3, result (0,1));
    EXPECT_EQ (matrix (0,2) * 4.3, result (0,2));
    EXPECT_EQ (matrix (1,0) * 4.3, result (1,0));
    EXPECT_EQ (matrix (1,1) * 4.3, result (1,1));
    EXPECT_EQ (matrix (1,2) * 4.3, result (1,2));
    EXPECT_EQ (matrix (2,0) * 4.3, result (2,0));
    EXPECT_EQ (matrix (2,1) * 4.3, result (2,1));
    EXPECT_EQ (matrix (2,2) * 4.3, result (2,2));
}

TEST (Matrix3Test, dividing_scalar_to_matrix_divides_each_component)
{
    const Math::Matrix3d matrix (2.3, 4.1, 6.5,
                                 1.8, 4.5, 9.8,
                                 4.4, 3.2, 3.4);

    auto result (matrix);
    result /= 4.3;

    EXPECT_EQ (matrix (0,0) / 4.3, result (0,0));
    EXPECT_EQ (matrix (0,1) / 4.3, result (0,1));
    EXPECT_EQ (matrix (0,2) / 4.3, result (0,2));
    EXPECT_EQ (matrix (1,0) / 4.3, result (1,0));
    EXPECT_EQ (matrix (1,1) / 4.3, result (1,1));
    EXPECT_EQ (matrix (1,2) / 4.3, result (1,2));
    EXPECT_EQ (matrix (2,0) / 4.3, result (2,0));
    EXPECT_EQ (matrix (2,1) / 4.3, result (2,1));
    EXPECT_EQ (matrix (2,2) / 4.3, result (2,2));
}

TEST (Matrix3Test, dividing_matrix_and_scalar_divides_each_component)
{
    const Math::Matrix3d matrix (2.3, 4.1, 6.5,
                                 1.8, 4.5, 9.8,
                                 4.4, 3.2, 3.4);

    auto result = matrix / 4.3;

    EXPECT_EQ (matrix (0,0) / 4.3, result (0,0));
    EXPECT_EQ (matrix (0,1) / 4.3, result (0,1));
    EXPECT_EQ (matrix (0,2) / 4.3, result (0,2));
    EXPECT_EQ (matrix (1,0) / 4.3, result (1,0));
    EXPECT_EQ (matrix (1,1) / 4.3, result (1,1));
    EXPECT_EQ (matrix (1,2) / 4.3, result (1,2));
    EXPECT_EQ (matrix (2,0) / 4.3, result (2,0));
    EXPECT_EQ (matrix (2,1) / 4.3, result (2,1));
    EXPECT_EQ (matrix (2,2) / 4.3, result (2,2));

}

TEST (Matrix3Test, adding_matrix_with_matrix_adds_each_element)
{
    const Math::Matrix3d matrix1 (2.3, 4.1, 6.5,
                                  1.8, 4.5, 9.8,
                                  4.4, 3.2, 3.4);


    const Math::Matrix3d matrix2 (4.5, 2.1, 7.6,
                                  1.2, 3.4, 5.6,
                                  9.8, 7.2, 4.2);

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
}

TEST (Matrix2Test, adding_two_matrices_adds_each_element)
{
    const Math::Matrix3d matrix1 (2.3, 4.1, 6.5,
                                  1.8, 4.5, 9.8,
                                  4.4, 3.2, 3.4);


    const Math::Matrix3d matrix2 (4.5, 2.1, 7.6,
                                  1.2, 3.4, 5.6,
                                  9.8, 7.2, 4.2);
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
    const Math::Matrix3d matrix1 (2.3, 4.1, 6.5,
                                  1.8, 4.5, 9.8,
                                  4.4, 3.2, 3.4);


    const Math::Matrix3d matrix2 (4.5, 2.1, 7.6,
                                  1.2, 3.4, 5.6,
                                  9.8, 7.2, 4.2);

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
}

TEST (Matrix3Test, subtracting_two_matrices_subtracts_each_element)
{
    const Math::Matrix3d matrix1 (2.3, 4.1, 6.5,
                                  1.8, 4.5, 9.8,
                                  4.4, 3.2, 3.4);


    const Math::Matrix3d matrix2 (4.5, 2.1, 7.6,
                                  1.2, 3.4, 5.6,
                                  9.8, 7.2, 4.2);
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
    const Math::Matrix3d matrix (2.3, 4.1, 6.5,
                                 1.8, 4.5, 9.8,
                                 4.4, 3.2, 3.4);

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
    const Math::Matrix3d matrix (3.2, 5.1, 6.5,
                                 6.5, 3.2, 1.2,
                                 7.8, 2.4, 9.8);
    const Math::Matrix3d zero (0, 0, 0,
                               0, 0, 0,
                               0, 0, 0);
    auto result = matrix * zero;

    for (size_t i = 0; i < 9; ++i)
        EXPECT_EQ (0, result[i]);
}

TEST (Matrix3Test, matrix_multipliplied_with_zero_matrix_from_left_is_zero_matrix)
{
    const Math::Matrix3d matrix (3.2, 5.1, 6.5,
                                 6.5, 3.2, 1.2,
                                 7.8, 2.4, 9.8);
    const Math::Matrix3d zero (0, 0, 0,
                               0, 0, 0,
                               0, 0, 0);
    auto result = zero * matrix;

    for (size_t i = 0; i < 9; ++i)
        EXPECT_EQ (0, result[i]);
}

TEST (Matrix3Test, matrix_multipliplied_with_identity_from_right_is_the_same_matrix_again)
{
    const Math::Matrix3d matrix (3.2, 5.1, 6.5,
                                 6.5, 3.2, 1.2,
                                 7.8, 2.4, 9.8);
    const Math::Matrix3d identity;
    auto result = matrix * identity;

    for (size_t i = 0; i < 9; ++i)
        EXPECT_EQ (matrix[i], result[i]);
}

TEST (Matrix3Test, matrix_multipliplied_with_identity_from_left_is_the_same_matrix_again)
{
    const Math::Matrix3d matrix (3.2, 5.1, 6.5,
                                 6.5, 3.2, 1.2,
                                 7.8, 2.4, 9.8);
    const Math::Matrix3d identity;
    auto result = identity * matrix;

    for (size_t i = 0; i < 9; ++i)
        EXPECT_EQ (matrix[i], result[i]);
}

TEST (Matrix3Test, matrix_matrix_multiplication_follows_normal_mathematical_rules)
{
    const Math::Matrix3d mat1 (2.3, 4.1, 6.5,
                               1.7, 8.7, 2.3,
                               2.4, 5.9, 1.1);
    const Math::Matrix3d mat2 (5.6, 4.1, 2.6,
                               6.6, 4.1, 6.9,
                               2.7, 4.3, 1.7);

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

TEST (Matrix3Test, division_by_zero_throws_invalid_argument)
{
    Math::Matrix3d matrix;

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
    srand (time (NULL));
    for (int i = 0; i < 1000; ++i) {
        Math::Matrix3d randmatrix;
        for (int i = 0; i < 9; ++i) {
            randmatrix[i] = rand ();
        }

        auto trace = randmatrix (0,0) + randmatrix (1,1) + randmatrix (2,2);
        EXPECT_EQ (trace, randmatrix.trace ());
    }
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
    const Math::Matrix3d matrix (3.2, 1.2, 6.7,
                                 4.3, 1.8, 6.5,
                                 2.1, 7.8, 5.4);
    auto transpose = matrix.transpose ();

    for (size_t i = 0; i < 3; ++i)
        for (size_t j = 0; j < 3; ++j)
            EXPECT_EQ (matrix (i,j), transpose (j,i));
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
    const Math::Matrix3d matrix (3.5, 7.0, 4.5,
                                 1.0, 8.0, 5.0,
                                 9.0, 5.5, 1.0);
    auto inverse = matrix.inverse ();
    auto result = matrix * inverse;
    double precision = std::pow (10, -15);

    EXPECT_NEAR (1, result (0,0), precision);
    EXPECT_NEAR (0, result (0,1), precision);
    EXPECT_NEAR (0, result (0,2), precision);

    EXPECT_NEAR (0, result (1,0), precision);
    EXPECT_NEAR (1, result (1,1), precision);
    EXPECT_NEAR (0, result (1,2), precision);

    EXPECT_NEAR (0, result (2,0), precision);
    EXPECT_NEAR (0, result (2,1), precision);
    EXPECT_NEAR (1, result (2,2), precision);
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
    const Math::Matrix3d matrix (4.3, 2.1, 6.7,
                                 6.7, 3.2, 1.1,
                                 9.8, 5.5, 3.2);
    EXPECT_EQ (matrix, matrix);
}

TEST (Matrix3Test, equality_of_copied_matrix_returns_true)
{
    const Math::Matrix3d matrix (4.3, 2.1, 6.7,
                                 6.7, 3.2, 1.1,
                                 9.8, 5.5, 3.2);
    auto copy = matrix;
    EXPECT_EQ (matrix, copy);
}

TEST (Matrix3Test, equality_of_equal_matrix_returns_true)
{
    const Math::Matrix3d matrix (4.3, 2.1, 6.7,
                                 6.7, 3.2, 1.1,
                                 9.8, 5.5, 3.2);
    const Math::Matrix3d equal (4.3, 2.1, 6.7,
                                 6.7, 3.2, 1.1,
                                 9.8, 5.5, 3.2);

    EXPECT_EQ (matrix, equal);
}

TEST (Matrix3Test, equality_of_matrix_with_one_different_element_returns_false)
{
    const Math::Matrix3d matrix (4.3, 2.1, 6.7,
                                 6.7, 3.2, 1.1,
                                 9.8, 5.5, 3.2);
    for (int i = 0; i < 9; ++i) {
        auto other = matrix;
        other[i] += 4;
        EXPECT_FALSE (matrix == other);
    }
}

TEST (Matrix3Test, inequality_of_same_matrix_returns_false)
{
    const Math::Matrix3d matrix (4.3, 2.1, 6.7,
                                 6.7, 3.2, 1.1,
                                 9.8, 5.5, 3.2);
    EXPECT_FALSE (matrix != matrix);
}

TEST (Matrix3Test, inequality_of_copied_matrix_returns_false)
{
    const Math::Matrix3d matrix (4.3, 2.1, 6.7,
                                 6.7, 3.2, 1.1,
                                 9.8, 5.5, 3.2);
    auto copy = matrix;
    EXPECT_FALSE (matrix != copy);
}

TEST (Matrix3Test, inequality_of_equal_matrix_returns_false)
{
    const Math::Matrix3d matrix (4.3, 2.1, 6.7,
                                 6.7, 3.2, 1.1,
                                 9.8, 5.5, 3.2);
    const Math::Matrix3d equal (4.3, 2.1, 6.7,
                                 6.7, 3.2, 1.1,
                                 9.8, 5.5, 3.2);

    EXPECT_FALSE (matrix != equal);
}

TEST (Matrix3Test, inequality_of_matrix_with_one_different_element_returns_true)
{
    const Math::Matrix3d matrix (4.3, 2.1, 6.7,
                                 6.7, 3.2, 1.1,
                                 9.8, 5.5, 3.2);
    for (int i = 0; i < 9; ++i) {
        auto other = matrix;
        other[i] += 4;
        EXPECT_NE (matrix, other);
    }
}
