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
