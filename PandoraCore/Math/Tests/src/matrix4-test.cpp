#include "test-helpers.h"

TEST (Matrix4Test, default_constructor_creates_identity_matrix)
{
    const Math::Matrix4d matrix;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (i == j)
                EXPECT_EQ (1, matrix (i,j));
            else
              EXPECT_EQ (0, matrix (i,j));
        }
    }
}

TEST (Matrix4Test, constructor_with_arguments_populates_matrix)
{
    BEGIN_MULTITEST

    auto array = create_double_array_of_size (16);
    const Math::Matrix4d matrix (array[0], array[1], array[2], array[3],
                                    array[4], array[5], array[6], array[7],
                                    array[8], array[9], array[10], array[11],
                                    array[12], array[13], array[14], array[15]);

    for (size_t i = 0; i < 16; ++i)
        EXPECT_EQ (array[i], matrix[i]);

    delete [] array;
    END_MULTITEST
}

TEST (Matrix4Test, matrix_constructed_from_array_populates_matrix_with_array_values)
{
    BEGIN_MULTITEST

    auto array = create_double_array_of_size (16);
    const Math::Matrix4d matrix (array);

    for (size_t i = 0; i < 16; ++i)
        EXPECT_EQ (array[i], matrix[i]);

    delete [] array;
    END_MULTITEST
}

TEST (Matrix4Test, matrix_created_from_3d_matrix_is_zero_padded_with_one_at_3_3)
{
    BEGIN_MULTITEST
    auto matrix3d = create_random_matrix3d ();
    Math::Matrix4d matrix (matrix3d);

    for (size_t i = 0; i < 3; ++i)
        for (size_t j = 0; j < 3; ++j)
            EXPECT_EQ (matrix3d (i,j), matrix [i*4 + j]);

    for (size_t i = 0; i < 3; ++i) {
        EXPECT_EQ (0, matrix (3,i));
        EXPECT_EQ (0, matrix (i,3));
    }

    EXPECT_EQ (1, matrix (3,3));

    END_MULTITEST
}

TEST (Matrix4Test, copied_matrix_copies_the_elements_from_the_other_matrix)
{
    BEGIN_MULTITEST
    auto matrix = create_random_matrix4d ();
    Math::Matrix4d copy (matrix);

    for (size_t j = 0; j < 16; ++j)
        EXPECT_EQ (matrix[j], copy[j]);

    END_MULTITEST
}
