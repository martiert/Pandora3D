#include "test-helpers.h"

TEST (Matrix4Test, default_constructor_creates_identity_matrix)
{
    const Math::Matrix4d matrix;

    for (auto i = 0; i < 4; ++i) {
        for (auto j = 0; j < 4; ++j) {
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

    for (auto i = 0; i < 16; ++i)
        EXPECT_EQ (array[i], matrix[i]);

    delete [] array;
    END_MULTITEST
}

TEST (Matrix4Test, matrix_constructed_from_array_populates_matrix_with_array_values)
{
    BEGIN_MULTITEST

    auto array = create_double_array_of_size (16);
    const Math::Matrix4d matrix (array);

    for (auto i = 0; i < 16; ++i)
        EXPECT_EQ (array[i], matrix[i]);

    delete [] array;
    END_MULTITEST
}

TEST (Matrix4Test, matrix_created_from_3d_matrix_is_zero_padded_with_one_at_3_3)
{
    BEGIN_MULTITEST

    const auto matrix3d = create_random_matrix3d ();
    const Math::Matrix4d matrix (matrix3d);

    for (auto i = 0; i < 3; ++i)
        for (auto j = 0; j < 3; ++j)
            EXPECT_EQ (matrix3d (i,j), matrix [i*4 + j]);

    for (auto i = 0; i < 3; ++i) {
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

    for (auto j = 0; j < 16; ++j)
        EXPECT_EQ (matrix[j], copy[j]);

    END_MULTITEST
}

TEST (Matrix4Test, matrix_assigned_from_3d_matrix_populates_matrix)
{
    BEGIN_MULTITEST

    const auto matrix3d = create_random_matrix3d ();
    Math::Matrix4d matrix;
    matrix = matrix3d;

    for (auto i = 0; i < 3; ++i)
        for (auto j = 0; j < 3; ++j)
            EXPECT_EQ (matrix3d (i,j), matrix [i*4 + j]);

    for (auto i = 0; i < 3; ++i) {
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

    for (auto i = 0; i < 16; ++i)
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

    for (auto i = 0; i < 16; ++i)
        EXPECT_EQ (matrix[i], ptr[i]);
}

TEST (Matrix4Test, can_static_cast_matrix_to_pointer)
{
    const auto matrix = create_random_matrix4d ();
    auto ptr = static_cast<const double*> (matrix);

    for (auto i = 0; i < 16; ++i)
        EXPECT_EQ (matrix[i], ptr[i]);
}

TEST (Matrix4Test, manipulating_the_casted_ptr_manipulates_the_matrix)
{
    auto matrix = create_random_matrix4d ();
    auto ptr = static_cast<double*> (matrix);
    ++ptr[5];

    for (auto i = 0; i < 16; ++i)
        EXPECT_EQ (matrix[i], ptr[i]);
}

TEST (Matrix4Test, multiplying_matrix_with_scalar_from_right_multiplies_each_element_with_scalar)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix4d ();
    const auto scalar = rand () / 100.0;
    const auto result = matrix * scalar;

    for (auto i = 0; i < 16; ++i)
        EXPECT_EQ (matrix[i] * scalar, result[i]);

    END_MULTITEST
}

TEST (Matrix4Test, multiplying_matrix_with_scalar_from_left_multiplies_each_element_with_scalar)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix4d ();
    const auto scalar = rand () / 100.0;
    const auto result = scalar * matrix;

    for (auto i = 0; i < 16; ++i)
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

    for (auto i = 0; i < 16; ++i)
        EXPECT_EQ (matrix[i] * scalar, result[i]);

    END_MULTITEST
}

TEST (Matrix4Test, dividing_matrix_with_scalar_from_right_divides_each_element_with_scalar)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix4d ();
    const auto scalar = rand () / 100.0;

    if (scalar != 0) {
      const auto result = matrix / scalar;

      for (auto i = 0; i < 16; ++i)
          EXPECT_EQ (matrix[i] / scalar, result[i]);
    }

    END_MULTITEST
}

TEST (Matrix4Test, dividing_scalar_to_matrix_divides_each_element_with_scalar)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix4d ();
    const auto scalar = rand () / 100.0;
    auto result (matrix);

    if (scalar != 0) {
      result /= scalar;

      for (auto i = 0; i < 16; ++i)
          EXPECT_EQ (matrix[i] / scalar, result[i]);
    }

    END_MULTITEST
}

TEST (Matrix4Test, dividing_matrix_with_zero_throws_invalid_argument)
{
    auto matrix = create_random_matrix4d ();
    EXPECT_THROW (matrix / 0.0, std::invalid_argument);
    EXPECT_THROW (matrix /= 0.0, std::invalid_argument);
}

TEST (Matrix4Test, adding_two_matrices_adds_each_component)
{
    BEGIN_MULTITEST

    const auto matrix1 = create_random_matrix4d ();
    const auto matrix2 = create_random_matrix4d ();
    auto result = matrix1 + matrix2;

    for (auto i = 0; i < 16; ++i)
        EXPECT_EQ (matrix1[i] + matrix2[i], result[i]);

    END_MULTITEST
}

TEST (Matrix4Test, adding_matrix_to_matrix_adds_each_component)
{
    BEGIN_MULTITEST

    const auto matrix1 = create_random_matrix4d ();
    const auto matrix2 = create_random_matrix4d ();
    auto result = matrix1;
    result += matrix2;

    for (auto i = 0; i < 16; ++i)
        EXPECT_EQ (matrix1[i] + matrix2[i], result[i]);

    END_MULTITEST
}

TEST (Matrix4Test, subtracting_two_matrices_subtracts_each_component)
{
    BEGIN_MULTITEST

    const auto matrix1 = create_random_matrix4d ();
    const auto matrix2 = create_random_matrix4d ();
    auto result = matrix1 - matrix2;

    for (auto i = 0; i < 16; ++i)
        EXPECT_EQ (matrix1[i] - matrix2[i], result[i]);

    END_MULTITEST
}

TEST (Matrix4Test, subtracting_matrix_from_matrix_subtracts_each_component)
{
    BEGIN_MULTITEST

    const auto matrix1 = create_random_matrix4d ();
    const auto matrix2 = create_random_matrix4d ();
    auto result = matrix1;
    result -= matrix2;

    for (auto i = 0; i < 16; ++i)
        EXPECT_EQ (matrix1[i] - matrix2[i], result[i]);

    END_MULTITEST
}

TEST (Matrix4Test, multiplying_matrix_with_identity_from_right_returns_matrix)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix4d ();
    const Math::Matrix4d identity;
    auto result = matrix * identity;

    for (auto i = 0; i < 16; ++i)
        EXPECT_EQ (matrix[i], result[i]);

    END_MULTITEST
}

TEST (Matrix4Test, multiplying_matrix_with_identity_from_left_returns_matrix)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix4d ();
    const Math::Matrix4d identity;
    auto result = identity * matrix;

    for (auto i = 0; i < 16; ++i)
        EXPECT_EQ (matrix[i], result[i]);

    END_MULTITEST
}

TEST (Matrix4Test, multiplying_matrix_with_zero_matrix_from_right_returns_zero_matrix)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix4d ();
    const Math::Matrix4d zero (0, 0, 0, 0,
                               0, 0, 0, 0,
                               0, 0, 0, 0,
                               0, 0, 0, 0);
    auto result = matrix * zero;

    for (auto i = 0; i < 16; ++i)
        EXPECT_EQ (0, result[i]);

    END_MULTITEST
}

TEST (Matrix4Test, multiplying_matrix_with_zero_matrix_from_left_returns_zero_matrix)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix4d ();
    const Math::Matrix4d zero (0, 0, 0, 0,
                               0, 0, 0, 0,
                               0, 0, 0, 0,
                               0, 0, 0, 0);
    auto result = zero * matrix;

    for (auto i = 0; i < 16; ++i)
        EXPECT_EQ (0, result[i]);

    END_MULTITEST
}

TEST (Matrix4Test, matrix_multiplication_follows_mathematical_rules)
{
    BEGIN_MULTITEST

    const auto left = create_random_matrix4d ();
    const auto right = create_random_matrix4d ();
    const auto result = left * right;

    for (auto i = 0; i < 4; ++i) {
        for (auto j = 0; j < 4; ++j) {
            double element = 0;
            for (auto k = 0; k < 4; ++k)
                element += left (i,k) * right (k,j);
            EXPECT_EQ (element, result (i,j));
        }
    }

    END_MULTITEST
}

TEST (Matrix4Test, transpose_of_identity_is_identity)
{
    const Math::Matrix4d identity;
    const auto trans = identity.transpose ();

    for (auto i = 0; i < 16; ++i)
        EXPECT_EQ (identity[i], trans[i]);
}

TEST (Matrix4Test, transpose_of_zero_matrix_is_zero_matrix)
{
    const Math::Matrix4d zero (0, 0, 0, 0,
                               0, 0, 0, 0,
                               0, 0, 0, 0,
                               0, 0, 0, 0);
    const auto trans = zero.transpose ();

    for (auto i = 0; i < 16; ++i)
        EXPECT_EQ (0, trans[i]);
}

TEST (Matrix4Test, transpose_of_matrix_switches_rows_and_columns)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix4d ();
    const auto result = matrix.transpose ();

    for (auto i = 0; i < 4; ++i)
        for (auto j = 0; j < 4; ++j)
            EXPECT_EQ (matrix (j,i), result (i,j));

    END_MULTITEST
}

TEST (Matrix4Test, trace_of_zero_matrix_is_zero)
{
    const Math::Matrix4d zero (0, 0, 0, 0,
                               0, 0, 0, 0,
                               0, 0, 0, 0,
                               0, 0, 0, 0);

    EXPECT_EQ (0, zero.trace ());
}

TEST (Matrix4Test, trace_of_identity_is_four)
{
    const Math::Matrix4d identity;
    EXPECT_EQ (4, identity.trace ());
}

TEST (Matrix4Test, trace_of_matrix_is_sum_of_diagonal)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix4d ();

    EXPECT_EQ (matrix (0,0) + matrix (1,1) + matrix (2,2) + matrix (3,3), matrix.trace ());

    END_MULTITEST
}

TEST (Matrix4Test, determinant_of_zero_matrix_is_zero)
{
     const Math::Matrix4d zero (0, 0, 0, 0,
                               0, 0, 0, 0,
                               0, 0, 0, 0,
                               0, 0, 0, 0);
     EXPECT_EQ (0, zero.determinant ());
}

TEST (Matrix4Test, determinant_of_identity_matrix_is_one)
{
    const Math::Matrix4d identity;

    EXPECT_EQ (1, identity.determinant ());
}
