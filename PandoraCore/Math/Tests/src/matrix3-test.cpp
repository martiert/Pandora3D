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
