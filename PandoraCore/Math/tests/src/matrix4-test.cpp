#include <matrix4.h>
#include <matrix3.h>
#include <vector4.h>

#include <gtest/gtest.h>

#include "test-helpers.h"

const Math::Matrix4 create_random_matrix4 ();
const Math::Matrix3 create_random_matrix3 ();

const Math::Vector4 create_random_vector4 ();

TEST (Matrix4Test, default_constructor_creates_identity_matrix)
{
    const Math::Matrix4 matrix;

    for (auto i = 0; i < 16; ++i)
        EXPECT_EQ (Math::Matrix4::IDENTITY[i], matrix[i]);
}

TEST (Matrix4Test, constructor_with_arguments_populates_matrix)
{
    BEGIN_MULTITEST

    const auto array = create_double_array_of_size (16);
    const Math::Matrix4 matrix (array[0], array[1], array[2], array[3],
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
    const Math::Matrix4 matrix (array);

    for (auto i = 0; i < 16; ++i)
        EXPECT_EQ (array[i], matrix[i]);

    delete [] array;
    END_MULTITEST
}

TEST (Matrix4Test, matrix_created_from_3d_matrix_is_zero_padded_with_one_at_3_3)
{
    BEGIN_MULTITEST

    const auto matrix3 = create_random_matrix3 ();
    const Math::Matrix4 matrix (matrix3);

    for (auto i = 0; i < 3; ++i)
        for (auto j = 0; j < 3; ++j)
            EXPECT_EQ (matrix3 (i,j), matrix [i*4 + j]);

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

    const auto matrix = create_random_matrix4 ();
    const Math::Matrix4 copy (matrix);

    for (auto j = 0; j < 16; ++j)
        EXPECT_EQ (matrix[j], copy[j]);

    END_MULTITEST
}

TEST (Matrix4Test, matrix_assigned_from_3d_matrix_populates_matrix)
{
    BEGIN_MULTITEST

    const auto matrix3 = create_random_matrix3 ();
    Math::Matrix4 matrix;
    matrix = matrix3;

    for (auto i = 0; i < 3; ++i)
        for (auto j = 0; j < 3; ++j)
            EXPECT_EQ (matrix3 (i,j), matrix [i*4 + j]);

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
    Math::Matrix4 matrix;
    matrix = array;

    for (auto i = 0; i < 16; ++i)
        EXPECT_EQ (array[i], matrix[i]);

    delete [] array;
    END_MULTITEST
}

TEST (Matrix4Test, index_operator_throws_index_operator_out_of_range_exception_for_invalid_input)
{
    const auto matrix1 = create_random_matrix4 ();
    auto matrix2 = create_random_matrix4 ();

    EXPECT_THROW (matrix1 (0,4), Math::Matrix4::index_operator_out_of_range_exception);
    EXPECT_THROW (matrix1 (4,0), Math::Matrix4::index_operator_out_of_range_exception);
    EXPECT_THROW (matrix2 (0,4), Math::Matrix4::index_operator_out_of_range_exception);
    EXPECT_THROW (matrix2 (4,0), Math::Matrix4::index_operator_out_of_range_exception);
    EXPECT_THROW (matrix1[16], Math::Matrix4::index_operator_out_of_range_exception);
    EXPECT_THROW (matrix2[16], Math::Matrix4::index_operator_out_of_range_exception);
}

TEST (Matrix4Test, can_cast_matrix_to_pointer_c_style)
{
    const auto matrix = create_random_matrix4 ();
    auto ptr = (const double*) matrix;

    for (auto i = 0; i < 16; ++i)
        EXPECT_EQ (matrix[i], ptr[i]);
}

TEST (Matrix4Test, can_static_cast_matrix_to_pointer)
{
    const auto matrix = create_random_matrix4 ();
    auto ptr = static_cast<const double*> (matrix);

    for (auto i = 0; i < 16; ++i)
        EXPECT_EQ (matrix[i], ptr[i]);
}

TEST (Matrix4Test, manipulating_the_casted_ptr_manipulates_the_matrix)
{
    auto matrix = create_random_matrix4 ();
    auto ptr = static_cast<double*> (matrix);
    ++ptr[5];

    for (auto i = 0; i < 16; ++i)
        EXPECT_EQ (matrix[i], ptr[i]);
}

TEST (Matrix4Test, multiplying_matrix_with_scalar_from_right_multiplies_each_element_with_scalar)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix4 ();
    const auto scalar = rand () / 100.0;
    const auto result = matrix * scalar;

    for (auto i = 0; i < 16; ++i)
        EXPECT_EQ (matrix[i] * scalar, result[i]);

    END_MULTITEST
}

TEST (Matrix4Test, multiplying_matrix_with_scalar_from_left_multiplies_each_element_with_scalar)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix4 ();
    const auto scalar = rand () / 100.0;
    const auto result = scalar * matrix;

    for (auto i = 0; i < 16; ++i)
        EXPECT_EQ (matrix[i] * scalar, result[i]);

    END_MULTITEST
}

TEST (Matrix4Test, multiplying_scalar_to_matrix_multiplies_each_component_with_scalar)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix4 ();
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

    const auto matrix = create_random_matrix4 ();
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

    const auto matrix = create_random_matrix4 ();
    const auto scalar = rand () / 100.0;
    auto result (matrix);

    if (scalar != 0) {
      result /= scalar;

      for (auto i = 0; i < 16; ++i)
          EXPECT_EQ (matrix[i] / scalar, result[i]);
    }

    END_MULTITEST
}

TEST (Matrix4Test, dividing_matrix_with_zero_throws_division_by_zero_exception)
{
    auto matrix = create_random_matrix4 ();
    EXPECT_THROW (matrix / 0.0, Math::Matrix4::division_by_zero_exception);
    EXPECT_THROW (matrix /= 0.0, Math::Matrix4::division_by_zero_exception);
}

TEST (Matrix4Test, adding_two_matrices_adds_each_component)
{
    BEGIN_MULTITEST

    const auto matrix1 = create_random_matrix4 ();
    const auto matrix2 = create_random_matrix4 ();
    auto result = matrix1 + matrix2;

    for (auto i = 0; i < 16; ++i)
        EXPECT_EQ (matrix1[i] + matrix2[i], result[i]);

    END_MULTITEST
}

TEST (Matrix4Test, adding_matrix_to_matrix_adds_each_component)
{
    BEGIN_MULTITEST

    const auto matrix1 = create_random_matrix4 ();
    const auto matrix2 = create_random_matrix4 ();
    auto result = matrix1;
    result += matrix2;

    for (auto i = 0; i < 16; ++i)
        EXPECT_EQ (matrix1[i] + matrix2[i], result[i]);

    END_MULTITEST
}

TEST (Matrix4Test, subtracting_two_matrices_subtracts_each_component)
{
    BEGIN_MULTITEST

    const auto matrix1 = create_random_matrix4 ();
    const auto matrix2 = create_random_matrix4 ();
    auto result = matrix1 - matrix2;

    for (auto i = 0; i < 16; ++i)
        EXPECT_EQ (matrix1[i] - matrix2[i], result[i]);

    END_MULTITEST
}

TEST (Matrix4Test, subtracting_matrix_from_matrix_subtracts_each_component)
{
    BEGIN_MULTITEST

    const auto matrix1 = create_random_matrix4 ();
    const auto matrix2 = create_random_matrix4 ();
    auto result = matrix1;
    result -= matrix2;

    for (auto i = 0; i < 16; ++i)
        EXPECT_EQ (matrix1[i] - matrix2[i], result[i]);

    END_MULTITEST
}

TEST (Matrix4Test, multiplying_matrix_with_identity_from_right_returns_matrix)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix4 ();
    auto result = matrix * Math::Matrix4::IDENTITY;

    for (auto i = 0; i < 16; ++i)
        EXPECT_EQ (matrix[i], result[i]);

    END_MULTITEST
}

TEST (Matrix4Test, multiplying_matrix_with_identity_from_left_returns_matrix)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix4 ();
    auto result = Math::Matrix4::IDENTITY * matrix;

    for (auto i = 0; i < 16; ++i)
        EXPECT_EQ (matrix[i], result[i]);

    END_MULTITEST
}

TEST (Matrix4Test, multiplying_matrix_with_zero_matrix_from_right_returns_zero_matrix)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix4 ();
    auto result = matrix * Math::Matrix4::ZERO;

    for (auto i = 0; i < 16; ++i)
        EXPECT_EQ (0, result[i]);

    END_MULTITEST
}

TEST (Matrix4Test, multiplying_matrix_with_zero_matrix_from_left_returns_zero_matrix)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix4 ();
    auto result = Math::Matrix4::ZERO * matrix;

    for (auto i = 0; i < 16; ++i)
        EXPECT_EQ (0, result[i]);

    END_MULTITEST
}

TEST (Matrix4Test, matrix_multiplication_follows_mathematical_rules)
{
    BEGIN_MULTITEST

    const auto left = create_random_matrix4 ();
    const auto right = create_random_matrix4 ();
    const auto result = left * right;

    Math::Matrix4 correct = Math::Matrix4::ZERO;

    for (auto i = 0; i < 4; ++i)
        for (auto j = 0; j < 4; ++j)
            for (auto k = 0; k < 4; ++k)
                correct (i,j) += left (i,k) * right (k,j);

    for (auto i = 0; i < 16; ++i)
        EXPECT_EQ (correct[i], result[i]);

    END_MULTITEST
}

TEST (Matrix4Test, transpose_of_identity_is_identity)
{
    const auto trans = Math::Matrix4::IDENTITY.transpose ();

    for (auto i = 0; i < 16; ++i)
        EXPECT_EQ (Math::Matrix4::IDENTITY[i], trans[i]);
}

TEST (Matrix4Test, transpose_of_zero_matrix_is_zero_matrix)
{
    const auto trans = Math::Matrix4::ZERO.transpose ();

    for (auto i = 0; i < 16; ++i)
        EXPECT_EQ (0, trans[i]);
}

TEST (Matrix4Test, transpose_of_matrix_switches_rows_and_columns)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix4 ();
    const auto result = matrix.transpose ();

    for (auto i = 0; i < 4; ++i)
        for (auto j = 0; j < 4; ++j)
            EXPECT_EQ (matrix (j,i), result (i,j));

    END_MULTITEST
}

TEST (Matrix4Test, trace_of_zero_matrix_is_zero)
{
    EXPECT_EQ (0, Math::Matrix4::ZERO.trace ());
}

TEST (Matrix4Test, trace_of_identity_is_four)
{
    EXPECT_EQ (4, Math::Matrix4::IDENTITY.trace ());
}

TEST (Matrix4Test, trace_of_matrix_is_sum_of_diagonal)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix4 ();

    EXPECT_EQ (matrix (0,0) + matrix (1,1) + matrix (2,2) + matrix (3,3), matrix.trace ());

    END_MULTITEST
}

TEST (Matrix4Test, determinant_of_zero_matrix_is_zero)
{
     EXPECT_EQ (0, Math::Matrix4::ZERO.determinant ());
}

TEST (Matrix4Test, determinant_of_identity_matrix_is_one)
{
    EXPECT_EQ (1, Math::Matrix4::IDENTITY.determinant ());
}

TEST (Matrix4Test, determinant_of_given_matrix_gives_correct_result)
{
    const Math::Matrix4 matrix (4, 3, 1, 7,
                                 2, 8, 9, 3,
                                 5, 1, 7, 9,
                                 8, 3, 1, 5);
    EXPECT_EQ (-2246, matrix.determinant ());
}

TEST (Matrix4Test, determinant_of_matrix_follows_mathematical_rules)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix4 ();

    const double sub1 = matrix (1,1) * (matrix (2,2) * matrix (3,3) - matrix (2,3) * matrix (3,2)) -
                        matrix (1,2) * (matrix (2,1) * matrix (3,3) - matrix (2,3) * matrix (3,1)) +
                        matrix (1,3) * (matrix (2,1) * matrix (3,2) - matrix (3,1) * matrix (2,2));

    const double sub2 = matrix (1,0) * (matrix (2,2) * matrix (3,3) - matrix (2,3) * matrix (3,2)) -
                        matrix (1,2) * (matrix (2,0) * matrix (3,3) - matrix (2,3) * matrix (3,0)) +
                        matrix (1,3) * (matrix (2,0) * matrix (3,2) - matrix (2,2) * matrix (3,0));

    const double sub3 = matrix (1,0) * (matrix (2,1) * matrix (3,3) - matrix (2,3) * matrix (3,1)) -
                        matrix (1,1) * (matrix (2,0) * matrix (3,3) - matrix (2,3) * matrix (3,0)) +
                        matrix (1,3) * (matrix (2,0) * matrix (3,1) - matrix (2,1) * matrix (3,0));

    const double sub4 = matrix (1,0) * (matrix (2,1) * matrix (3,2) - matrix (2,2) * matrix (3,1)) -
                        matrix (1,1) * (matrix (2,0) * matrix (3,2) - matrix (2,2) * matrix (3,0)) +
                        matrix (1,2) * (matrix (2,0) * matrix (3,1) - matrix (2,1) * matrix (3,0));

    const double determinant = matrix (0,0) * sub1 - matrix (0,1) * sub2 + matrix (0,2) * sub3 - matrix (0,3) * sub4;

    EXPECT_EQ (determinant, matrix.determinant ());

    END_MULTITEST
}

TEST (Matrix4Test, multiplying_identity_with_vector_returns_the_same_vector)
{
    BEGIN_MULTITEST

    const auto vector = create_random_vector4 ();
    const auto res = Math::Matrix4::IDENTITY * vector;

    EXPECT_EQ (vector.x, res.x);
    EXPECT_EQ (vector.y, res.y);
    EXPECT_EQ (vector.z, res.z);
    EXPECT_EQ (vector.w, res.w);

    END_MULTITEST
}

TEST (Matrix4Test, multiplying_matrix_with_vector_multiplies_the_vector_with_each_row)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix4 ();
    const auto vector = create_random_vector4 ();
    const auto res = matrix * vector;

    EXPECT_EQ (matrix[0]*vector.x  + matrix[1]*vector.y  + matrix[2]*vector.z  + matrix[3]*vector.w,  res.x);
    EXPECT_EQ (matrix[4]*vector.x  + matrix[5]*vector.y  + matrix[6]*vector.z  + matrix[7]*vector.w,  res.y);
    EXPECT_EQ (matrix[8]*vector.x  + matrix[9]*vector.y  + matrix[10]*vector.z + matrix[11]*vector.w, res.z);
    EXPECT_EQ (matrix[12]*vector.x + matrix[13]*vector.y + matrix[14]*vector.z + matrix[15]*vector.w, res.w);

    END_MULTITEST
}

TEST (Matrix4Test, multiplying_vector_with_identity_returns_the_vector)
{
    BEGIN_MULTITEST

    const auto vector = create_random_vector4 ();
    const auto res = vector * Math::Matrix4::IDENTITY;

    EXPECT_EQ (vector.x, res.x);
    EXPECT_EQ (vector.y, res.y);
    EXPECT_EQ (vector.z, res.z);
    EXPECT_EQ (vector.w, res.w);

    END_MULTITEST
}

TEST (Matrix4Test, multiplying_vector_with_matrix_multiplies_the_vector_with_each_column)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix4 ();
    const auto vector = create_random_vector4 ();
    const auto res = vector * matrix;

    EXPECT_EQ (matrix[0]*vector.x + matrix[4]*vector.y + matrix[8]*vector.z  + matrix[12]*vector.w, res.x);
    EXPECT_EQ (matrix[1]*vector.x + matrix[5]*vector.y + matrix[9]*vector.z  + matrix[13]*vector.w, res.y);
    EXPECT_EQ (matrix[2]*vector.x + matrix[6]*vector.y + matrix[10]*vector.z + matrix[14]*vector.w, res.z);
    EXPECT_EQ (matrix[3]*vector.x + matrix[7]*vector.y + matrix[11]*vector.z + matrix[15]*vector.w, res.w);

    END_MULTITEST
}

TEST (Matrix4Test, inverse_of_identity_is_identity)
{
    const auto res = Math::Matrix4::IDENTITY.inverse ();

    for (auto i = 0; i < 16; ++i)
        EXPECT_EQ (Math::Matrix4::IDENTITY[i], res[i]);
}

TEST (Matrix4Test, inverse_of_matrix_times_matrix_is_identity)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix4 ();
    const auto inverse = matrix.inverse ();
    const auto res = inverse * matrix;

    for (auto i = 0; i < 16; ++i)
        EXPECT_NEAR (Math::Matrix4::IDENTITY[i], res[i], PRECISION);

    END_MULTITEST
}

TEST (Matrix4Test, matrix_times_inverse_of_matrix_is_identity)
{
    BEGIN_MULTITEST

    const auto matrix = create_random_matrix4 ();
    const auto inverse = matrix.inverse ();
    const auto res = matrix * inverse;

    for (auto i = 0; i < 16; ++i)
        EXPECT_NEAR (Math::Matrix4::IDENTITY[i], res[i], PRECISION);

    END_MULTITEST
}

TEST (Matrix4Test, inverse_of_singular_matrix_throws_inverse_of_singular_matrix_exception)
{
    const Math::Matrix4 matrix (2, 4, 1, 7,
                                2, 4, 1, 7,
                                2, 4, 1, 7,
                                2, 4, 1, 7);

    EXPECT_THROW (matrix.inverse (), Math::Matrix4::inverse_of_singular_matrix_exception);
}

const Math::Matrix4 create_random_matrix4 ()
{
    auto array = create_double_array_of_size (16);
    Math::Matrix4 matrix (array);

    delete [] array;
    return matrix;
}
