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

    const auto array = create_double_array_of_size (16);
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

    const auto matrix3d = create_random_matrix3d ();
    const Math::Matrix4d matrix (matrix3d);

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

    const auto matrix = create_random_matrix4d ();
    const Math::Matrix4d copy (matrix);

    for (size_t j = 0; j < 16; ++j)
        EXPECT_EQ (matrix[j], copy[j]);

    END_MULTITEST
}

TEST (Matrix4Test, matrix_assigned_from_3d_matrix_populates_matrix)
{
    BEGIN_MULTITEST

    const auto matrix3d = create_random_matrix3d ();
    Math::Matrix4d matrix;
    matrix = matrix3d;

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

TEST (Matrix4Test, matrix_assigned_from_array_populates_matrix)
{
    BEGIN_MULTITEST

    auto array = create_double_array_of_size (16);
    Math::Matrix4d matrix;
    matrix = array;

    for (size_t i = 0; i < 16; ++i)
        EXPECT_EQ (array[i], matrix[i]);

    delete [] array;
    END_MULTITEST
}

TEST (Matrix4Test, index_operator_throws_out_of_range_exception_for_invalid_input)
{
    const auto matrix1 = create_random_matrix4d ();
    auto matrix2 = create_random_matrix4d ();

    EXPECT_THROW (matrix1 (0,4), std::out_of_range);
    EXPECT_THROW (matrix1 (4,0), std::out_of_range);
    EXPECT_THROW (matrix2 (0,4), std::out_of_range);
    EXPECT_THROW (matrix2 (4,0), std::out_of_range);
    EXPECT_THROW (matrix1[16], std::out_of_range);
    EXPECT_THROW (matrix2[16], std::out_of_range);
}

TEST (Matrix4Test, can_cast_matrix_to_pointer_c_style)
{
    const auto matrix = create_random_matrix4d ();
    auto ptr = (const double*) matrix;

    for (size_t i = 0; i < 16; ++i)
        EXPECT_EQ (matrix[i], ptr[i]);
}

TEST (Matrix4Test, can_static_cast_matrix_to_pointer)
{
    const auto matrix = create_random_matrix4d ();
    auto ptr = static_cast<const double*> (matrix);

    for (size_t i = 0; i < 16; ++i)
        EXPECT_EQ (matrix[i], ptr[i]);
}

TEST (Matrix4Test, manipulating_the_casted_ptr_manipulates_the_matrix)
{
    auto matrix = create_random_matrix4d ();
    auto ptr = static_cast<double*> (matrix);
    ++ptr[5];

    for (size_t i = 0; i < 16; ++i)
        EXPECT_EQ (matrix[i], ptr[i]);
}

TEST (Matrix4Test, multiplying_matrix_with_scalar_from_right_multiplies_each_element_with_scalar)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix4d ();
    const auto scalar = rand () / 100.0;
    const auto result = matrix * scalar;

    for (size_t i = 0; i < 16; ++i)
        EXPECT_EQ (matrix[i] * scalar, result[i]);

    END_MULTITEST
}

TEST (Matrix4Test, multiplying_matrix_with_scalar_from_left_multiplies_each_element_with_scalar)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix4d ();
    const auto scalar = rand () / 100.0;
    const auto result = scalar * matrix;

    for (size_t i = 0; i < 16; ++i)
        EXPECT_EQ (matrix[i] * scalar, result[i]);

    END_MULTITEST
}

TEST (Matrix4Test, multiplying_scalar_to_matrix_multiplies_each_component_with_scalar)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix4d ();
    const auto scalar = rand () / 100.0;
    auto result (matrix);
    result *= scalar;

    for (size_t i = 0; i < 16; ++i)
        EXPECT_EQ (matrix[i] * scalar, result[i]);

    END_MULTITEST

}
