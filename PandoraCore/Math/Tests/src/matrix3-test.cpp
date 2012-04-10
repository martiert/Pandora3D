#include <Math/matrix3.h>

#include <gtest/gtest.h>

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

TEST (Matrix3Test, index_operator_throws_out_of_range_exception)
{
    const Math::Matrix3d mat1;
    Math::Matrix3d mat2;

    EXPECT_THROW (mat1 (0,3), std::out_of_range);
    EXPECT_THROW (mat1 (3,0), std::out_of_range);
    EXPECT_THROW (mat2 (0,3), std::out_of_range);
    EXPECT_THROW (mat2 (3,0), std::out_of_range);
}

TEST (Matrix3Test, can_cast_matrix_to_pointer)
{
    Math::Matrix3d matrix1 (2.3, 4.1, 6.5,
                            1.8, 4.5, 9.8,
                            4.4, 3.2, 3.4);
    auto ptr = (double *) matrix1;
    auto ptr2 = static_cast<double*> (matrix1);

    EXPECT_EQ (matrix1 (0,0), ptr[0]);
    EXPECT_EQ (matrix1 (0,1), ptr[1]);
    EXPECT_EQ (matrix1 (0,2), ptr[2]);
    EXPECT_EQ (matrix1 (1,0), ptr[3]);
    EXPECT_EQ (matrix1 (1,1), ptr[4]);
    EXPECT_EQ (matrix1 (1,2), ptr[5]);
    EXPECT_EQ (matrix1 (2,0), ptr[6]);
    EXPECT_EQ (matrix1 (2,1), ptr[7]);
    EXPECT_EQ (matrix1 (2,2), ptr[8]);

    EXPECT_EQ (matrix1 (0,0), ptr2[0]);
    EXPECT_EQ (matrix1 (0,1), ptr2[1]);
    EXPECT_EQ (matrix1 (0,2), ptr2[2]);
    EXPECT_EQ (matrix1 (1,0), ptr2[3]);
    EXPECT_EQ (matrix1 (1,1), ptr2[4]);
    EXPECT_EQ (matrix1 (1,2), ptr2[5]);
    EXPECT_EQ (matrix1 (2,0), ptr2[6]);
    EXPECT_EQ (matrix1 (2,1), ptr2[7]);
    EXPECT_EQ (matrix1 (2,2), ptr2[8]);

    ptr[4] = 6.7;
    EXPECT_EQ (6.7, matrix1 (1,1));

    const Math::Matrix3d matrix2 (4.6, 2.3, 1.7,
                                  9.7, 4.3, 7.9,
                                  5.2, 6.1, 3.3);
    auto ptr3 = (const double*) matrix2;
    auto ptr4 = static_cast<const double*> (matrix2);

    EXPECT_EQ (matrix2 (0,0), ptr3[0]);
    EXPECT_EQ (matrix2 (0,1), ptr3[1]);
    EXPECT_EQ (matrix2 (0,2), ptr3[2]);
    EXPECT_EQ (matrix2 (1,0), ptr3[3]);
    EXPECT_EQ (matrix2 (1,1), ptr3[4]);
    EXPECT_EQ (matrix2 (1,2), ptr3[5]);
    EXPECT_EQ (matrix2 (2,0), ptr3[6]);
    EXPECT_EQ (matrix2 (2,1), ptr3[7]);
    EXPECT_EQ (matrix2 (2,2), ptr3[8]);

    EXPECT_EQ (matrix2 (0,0), ptr4[0]);
    EXPECT_EQ (matrix2 (0,1), ptr4[1]);
    EXPECT_EQ (matrix2 (0,2), ptr4[2]);
    EXPECT_EQ (matrix2 (1,0), ptr4[3]);
    EXPECT_EQ (matrix2 (1,1), ptr4[4]);
    EXPECT_EQ (matrix2 (1,2), ptr4[5]);
    EXPECT_EQ (matrix2 (2,0), ptr4[6]);
    EXPECT_EQ (matrix2 (2,1), ptr4[7]);
    EXPECT_EQ (matrix2 (2,2), ptr4[8]);
}

TEST (Matrix3Test, multiply_with_scalar)
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

TEST (Matrix3Test, matrix_with_scalar_multiplication)
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

TEST (Matrix3Test, matrix_scalar_division)
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

TEST (Matrix3Test, matrix_with_scalar_division)
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

TEST (Matrix3Test, scalar_matrix_multiplication)
{
    const Math::Matrix3d matrix (2.3, 4.1, 6.5,
                                  1.8, 4.5, 9.8,
                                  4.4, 3.2, 3.4);

    auto result = 2.7 * matrix;

    EXPECT_EQ (matrix (0,0) * 2.7, result (0,0));
    EXPECT_EQ (matrix (0,1) * 2.7, result (0,1));
    EXPECT_EQ (matrix (0,2) * 2.7, result (0,2));
    EXPECT_EQ (matrix (1,0) * 2.7, result (1,0));
    EXPECT_EQ (matrix (1,1) * 2.7, result (1,1));
    EXPECT_EQ (matrix (1,2) * 2.7, result (1,2));
    EXPECT_EQ (matrix (2,0) * 2.7, result (2,0));
    EXPECT_EQ (matrix (2,1) * 2.7, result (2,1));
    EXPECT_EQ (matrix (2,2) * 2.7, result (2,2));
}

TEST (Matrix3Test, matrix_addition)
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

TEST (Matrix2Test, matrix_to_matrix_addition)
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

TEST (Matrix3Test, matrix_subtraction)
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

TEST (Matrix3Test, matrix_to_matrix_subtraction)
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

TEST (Matrix3Test, matrix_determinant)
{
    const Math::Matrix3d matrix1;
    EXPECT_EQ (1.0, matrix1.determinant ());

    const Math::Matrix3d matrix2 (0, 0, 0, 0, 0, 0, 0, 0, 0);
    EXPECT_EQ (0.0, matrix2.determinant ());

    const Math::Matrix3d matrix3(2.3, 4.1, 6.5,
                                 1.8, 4.5, 9.8,
                                 4.4, 3.2, 3.4);

    auto det = matrix3 (0,0) * (matrix3 (1,1) * matrix3 (2,2) -
                               matrix3 (1,2) * matrix3 (2,1)) -
               matrix3 (0,1) * (matrix3 (1,0) * matrix3 (2,2) -
                               matrix3 (2,0) * matrix3 (1,2)) +
               matrix3 (0,2) * (matrix3 (1,0) * matrix3 (2,1) -
                               matrix3 (2,0) * matrix3 (1,1));

    EXPECT_EQ (det, matrix3.determinant ());
}

TEST (Matrix3Test, matrix_matrix_multiplication)
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
            for (auto k = 0; k < 3; ++k) {
                res += mat1 (i,k) * mat2 (k,j);
            }
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

TEST (Matrix3Test, multiplication_with_identity_returns_the_same_matrix)
{
    const Math::Matrix3d identity;
    const Math::Matrix3d matrix (3.2, 4.5, 6.7,
                                 1.2, 8.8, 4.1,
                                 9.7, 4.8, 4.3);

    auto result = matrix * identity;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            EXPECT_EQ (matrix (i,j), result (i,j));

    result = identity * matrix;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            EXPECT_EQ (matrix (i,j), result (i,j));
}
