#include <Math/matrix2.h>

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

TEST (Matrix2Test, can_cast_matrix_to_pointer)
{
    Math::Matrix2d matrix1 (4.3, 5.2, 1.7, 4.3);
    auto ptr = (double *) matrix1;
    auto ptr2 = static_cast<double*> (matrix1);

    EXPECT_EQ (ptr[0], matrix1 (0,0));
    EXPECT_EQ (ptr[1], matrix1 (0,1));
    EXPECT_EQ (ptr[2], matrix1 (1,0));
    EXPECT_EQ (ptr[3], matrix1 (1,1));

    EXPECT_EQ (ptr2[0], matrix1 (0,0));
    EXPECT_EQ (ptr2[1], matrix1 (0,1));
    EXPECT_EQ (ptr2[2], matrix1 (1,0));
    EXPECT_EQ (ptr2[3], matrix1 (1,1));

    ptr[2] = 2.1;
    EXPECT_EQ (ptr[2], matrix1 (1,0));

    const Math::Matrix2d matrix2 (3.2, 5.6, 7.1, 2.3);
    auto ptr3 = (const double*) matrix2;
    auto ptr4 = static_cast<const double*> (matrix2);

    EXPECT_EQ (ptr3[0], matrix2 (0,0));
    EXPECT_EQ (ptr3[1], matrix2 (0,1));
    EXPECT_EQ (ptr3[2], matrix2 (1,0));
    EXPECT_EQ (ptr3[3], matrix2 (1,1));

    EXPECT_EQ (ptr4[0], matrix2 (0,0));
    EXPECT_EQ (ptr4[1], matrix2 (0,1));
    EXPECT_EQ (ptr4[2], matrix2 (1,0));
    EXPECT_EQ (ptr4[3], matrix2 (1,1));
}

TEST (Matrix2Test, matrix_multiplication_with_scalar)
{
    const Math::Matrix2d matrix1 (4.5, 2.3, 1.2, 6.7);
    auto matrix2 = matrix1 * 3.4;

    EXPECT_EQ (matrix1 (0,0) * 3.4, matrix2 (0,0));
    EXPECT_EQ (matrix1 (0,1) * 3.4, matrix2 (0,1));
    EXPECT_EQ (matrix1 (1,0) * 3.4, matrix2 (1,0));
    EXPECT_EQ (matrix1 (1,1) * 3.4, matrix2 (1,1));

    matrix2 = 4.5 * matrix1;

    EXPECT_EQ (matrix1 (0,0) * 4.5, matrix2 (0,0));
    EXPECT_EQ (matrix1 (0,1) * 4.5, matrix2 (0,1));
    EXPECT_EQ (matrix1 (1,0) * 4.5, matrix2 (1,0));
    EXPECT_EQ (matrix1 (1,1) * 4.5, matrix2 (1,1));

    matrix2 = matrix1;
    matrix2 *= 2.3;
    EXPECT_EQ (matrix1 (0,0) * 2.3, matrix2 (0,0));
    EXPECT_EQ (matrix1 (0,1) * 2.3, matrix2 (0,1));
    EXPECT_EQ (matrix1 (1,0) * 2.3, matrix2 (1,0));
    EXPECT_EQ (matrix1 (1,1) * 2.3, matrix2 (1,1));
}

TEST (Matrix2Test, matrix_addition)
{
    const Math::Matrix2d matrix1 (3.4, 2.1, 5.6, 7.6);
    const Math::Matrix2d matrix2 (2.1, 5.6, 7.2, 3.2);
    auto matrix3 = matrix1 + matrix2;

    EXPECT_EQ (matrix1 (0,0) + matrix2 (0,0), matrix3 (0,0));
    EXPECT_EQ (matrix1 (0,1) + matrix2 (0,1), matrix3 (0,1));
    EXPECT_EQ (matrix1 (1,0) + matrix2 (1,0), matrix3 (1,0));
    EXPECT_EQ (matrix1 (1,1) + matrix2 (1,1), matrix3 (1,1));

    auto matrix4 (matrix1);
    matrix4 += matrix2;
    EXPECT_EQ (matrix3 (0,0), matrix4 (0,0));
    EXPECT_EQ (matrix3 (0,1), matrix4 (0,1));
    EXPECT_EQ (matrix3 (1,0), matrix4 (1,0));
    EXPECT_EQ (matrix3 (1,1), matrix4 (1,1));
}

TEST (Matrix2Test, matrix_subtraction)
{
    const Math::Matrix2d matrix1 (3.5, 1.2, 6.7, 4.3);
    const Math::Matrix2d matrix2 (2.1, 5.6, 7.2, 3.2);
    auto matrix3 = matrix1 - matrix2;

    EXPECT_EQ (matrix1 (0,0) - matrix2 (0,0), matrix3 (0,0));
    EXPECT_EQ (matrix1 (0,1) - matrix2 (0,1), matrix3 (0,1));
    EXPECT_EQ (matrix1 (1,0) - matrix2 (1,0), matrix3 (1,0));
    EXPECT_EQ (matrix1 (1,1) - matrix2 (1,1), matrix3 (1,1));

    auto matrix4 (matrix1);
    matrix4 -= matrix2;
    EXPECT_EQ (matrix3 (0,0), matrix4 (0,0));
    EXPECT_EQ (matrix3 (0,1), matrix4 (0,1));
    EXPECT_EQ (matrix3 (1,0), matrix4 (1,0));
    EXPECT_EQ (matrix3 (1,1), matrix4 (1,1));
}

TEST (Matrix2Test, matrix_determinand)
{
    const Math::Matrix2d matrix1;
    EXPECT_EQ (1.0, matrix1.determinant ());

    const Math::Matrix2d matrix2 (3.4, 2.3, 4.5, 7.9);
    EXPECT_EQ (3.4 * 7.9 - 2.3 * 4.5, matrix2.determinant ());

    const Math::Matrix2d matrix3 (0.0, 0.0, 0.0, 0.0);
    EXPECT_EQ (0.0, matrix3.determinant ());
}

TEST (Matrix2Test, matrix_multiplication)
{
    const Math::Matrix2d mat1 (2.3, 4.2, 1.2, 6.7);
    const Math::Matrix2d mat2 (4.5, 2.1, 5.6, 9.8);
    auto mat3 = mat1 * mat2;

    EXPECT_EQ (mat1 (0,0) * mat2 (0,0) + mat1 (0,1) * mat2 (1,0), mat3 (0,0));
    EXPECT_EQ (mat1 (0,0) * mat2 (0,1) + mat1 (0,1) * mat2 (1,1), mat3 (0,1));
    EXPECT_EQ (mat1 (1,0) * mat2 (0,0) + mat1 (1,1) * mat2 (1,0), mat3 (1,0));
    EXPECT_EQ (mat1 (1,0) * mat2 (0,1) + mat1 (1,1) * mat2 (1,1), mat3 (1,1));
}

TEST (Matrix2Test, multiplication_with_identity_returns_the_same_matrix)
{
    const Math::Matrix2d identity;
    const Math::Matrix2d matrix (4.5, 3.2, 6.7, 9.8);
    auto result = matrix * identity;

    EXPECT_EQ (result (0,0), matrix (0,0));
    EXPECT_EQ (result (0,1), matrix (0,1));
    EXPECT_EQ (result (1,0), matrix (1,0));
    EXPECT_EQ (result (1,1), matrix (1,1));

    result = identity * matrix;
    EXPECT_EQ (result (0,0), matrix (0,0));
    EXPECT_EQ (result (0,1), matrix (0,1));
    EXPECT_EQ (result (1,0), matrix (1,0));
    EXPECT_EQ (result (1,1), matrix (1,1));
}

TEST (Matrix2Test, division_by_scalar)
{
    const Math::Matrix2d matrix (4.5, 2.1, 4.7, 9.8);
    auto result = matrix / 3.4;

    EXPECT_EQ (matrix (0,0)/3.4, result (0,0));
    EXPECT_EQ (matrix (0,1)/3.4, result (0,1));
    EXPECT_EQ (matrix (1,0)/3.4, result (1,0));
    EXPECT_EQ (matrix (1,1)/3.4, result (1,1));

    result = matrix;
    result /= 3.4;
    EXPECT_EQ (matrix (0,0)/3.4, result (0,0));
    EXPECT_EQ (matrix (0,1)/3.4, result (0,1));
    EXPECT_EQ (matrix (1,0)/3.4, result (1,0));
    EXPECT_EQ (matrix (1,1)/3.4, result (1,1));
}

TEST (Matrix2Test, division_by_zero_throws_invalid_argument)
{
    Math::Matrix2d matrix;

    EXPECT_THROW (matrix / 0.0, std::invalid_argument);
    EXPECT_THROW (matrix /= 0.0, std::invalid_argument);
}

TEST (Matrix2Test, multiplication_with_inverse_returns_identity)
{
    const Math::Matrix2d matrix (3.4, 2.0, 5.6, 7.2);
    auto inverse = matrix.inverse ();

    auto result = inverse * matrix;
    EXPECT_FLOAT_EQ (1, result (0,0));
    EXPECT_FLOAT_EQ (0, result (0,1));
    EXPECT_FLOAT_EQ (0, result (1,0));
    EXPECT_FLOAT_EQ (1, result (1,1));

    result = matrix * inverse;
    EXPECT_FLOAT_EQ (1, result (0,0));
    EXPECT_FLOAT_EQ (0, result (0,1));
    EXPECT_FLOAT_EQ (0, result (1,0));
    EXPECT_FLOAT_EQ (1, result (1,1));
}

TEST (Matrix2Test, inverse_of_singular_matrix_throws_runtime_error)
{
    const Math::Matrix2d matrix (2.6, 4.8, 1.3, 2.4);
    EXPECT_THROW (matrix.inverse (), std::runtime_error);
}

TEST (Matrix2Test, test_equal_matrixes)
{
    const Math::Matrix2d matrix1 (3.4, 1.2, 6.7, 7.7);
    const Math::Matrix2d matrix2 (3.4, 1.2, 6.7, 7.7);
    const Math::Matrix2d matrix3 (5.6, 2.3, 1.2, 7.8);

    EXPECT_EQ (matrix1, matrix2);
    EXPECT_NE (matrix1, matrix3);

    EXPECT_FALSE (matrix1 == matrix3);
    EXPECT_FALSE (matrix1 != matrix2);
}
