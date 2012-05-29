#include <quaternion.h>
#include <vector3.h>
#include <gtest/gtest.h>

#include "test-helpers.h"

const Math::Quaternion create_random_quaternion ();
const Math::Matrix4 create_random_matrix4 ();
const Math::Vector3 create_random_vector3 ();
const Math::Matrix4 make_matrix_from_quaternion (const Math::Quaternion& quat);
const Math::Quaternion create_quaternion_from_matrix (const Math::Matrix4& matrix);

TEST (QuaternionTest, default_quaternion_is_identity_quaternion)
{
    const Math::Quaternion quat;

    EXPECT_EQ (1, quat.w ());
    EXPECT_EQ (0, quat.x ());
    EXPECT_EQ (0, quat.y ());
    EXPECT_EQ (0, quat.z ());
}

TEST (QuaternionTest, creating_quaternion_with_arguments_populates_quaternion_with_arguments)
{
    BEGIN_MULTITEST

    const auto array = create_double_array_of_size (4);
    const Math::Quaternion quat (array[0], array[1], array[2], array[3]);

    EXPECT_EQ (array[0], quat.w ());
    EXPECT_EQ (array[1], quat.x ());
    EXPECT_EQ (array[2], quat.y ());
    EXPECT_EQ (array[3], quat.z ());

    delete[] array;

    END_MULTITEST
}

TEST (QuaternionTest, creating_quaternion_from_array_populates_quaternion)
{
    BEGIN_MULTITEST

    const auto array = create_double_array_of_size (4);
    const Math::Quaternion quat (array);

    EXPECT_EQ (array[0], quat.w ());
    EXPECT_EQ (array[1], quat.x ());
    EXPECT_EQ (array[2], quat.y ());
    EXPECT_EQ (array[3], quat.z ());

    delete[] array;

    END_MULTITEST
}

TEST (QuaternionTest, creating_quaternion_with_real_element_and_imaginary_vector_sets_quaternion)
{
    BEGIN_MULTITEST

    const auto vector = create_random_vector3 ();
    const auto real = create_random_scalar ();
    Math::Quaternion quat (real, vector);

    EXPECT_EQ (real, quat.w ());
    EXPECT_EQ (vector.x, quat.x ());
    EXPECT_EQ (vector.y, quat.y ());
    EXPECT_EQ (vector.z, quat.z ());

    END_MULTITEST
}

TEST (QuaternionTest, creating_quaternion_from_identity_matrix_creates_the_identity_quaternion)
{
    Math::Quaternion quat (Math::Matrix4::IDENTITY);

    EXPECT_EQ (1, quat.w ());
    EXPECT_EQ (0, quat.x());
    EXPECT_EQ (0, quat.y ());
    EXPECT_EQ (0, quat.z ());
}

TEST (QuaternionTest, creating_quaternion_from_positive_diagonal_matrix_gives_real_part_as_half_of_the_squared_trace_and_zero_imaginary_part)
{
    BEGIN_MULTITEST

    Math::Matrix4 matrix;
    for (auto i = 0; i < 3; ++i) {
        const auto scalar = create_random_scalar ();
        matrix (i,i) = std::abs (scalar);
    }
    const Math::Quaternion quat (matrix);

    EXPECT_EQ (0.5 * std::sqrt (matrix.trace ()), quat.w ());
    EXPECT_EQ (0, quat.x ());
    EXPECT_EQ (0, quat.y ());
    EXPECT_EQ (0, quat.x ());

    END_MULTITEST
}

TEST (QuaternionTest, quaternion_creating_from_matrix_is_correct)
{
    const auto matrix = create_random_matrix4 ();
    const Math::Quaternion quat (matrix);
    const auto correct_quat = create_quaternion_from_matrix (matrix);

    EXPECT_EQ (correct_quat.w (), quat.w ());
    EXPECT_EQ (correct_quat.x (), quat.x ());
    EXPECT_EQ (correct_quat.y (), quat.y ());
    EXPECT_EQ (correct_quat.z (), quat.z ());
}

TEST (QuaternionTest, creating_matrix_from_identity_quaternion_gives_identity_matrix)
{
    const Math::Quaternion quat;
    const auto res = quat.create_matrix ();

    for (auto i = 0; i < 16; ++i)
        EXPECT_EQ (Math::Matrix4::IDENTITY[i], res[i]);
}

TEST (QuaternionTest, creating_matrix_from_quaternion_gives_correct_matrix)
{
    BEGIN_MULTITEST

    const auto quat = create_random_quaternion ();
    const auto res = quat.create_matrix ();
    const auto correct = make_matrix_from_quaternion (quat);

    for (auto i = 0; i < 16; ++i)
        EXPECT_EQ (correct[i], res[i]);

    END_MULTITEST
}

TEST (QuaternionTest, creating_matrix_from_zero_quaternion_throws_can_not_make_matrix_from_zero_quaternion_exception)
{
    Math::Quaternion quat;
    quat.w () = 0;

    EXPECT_THROW (quat.create_matrix (), Math::Quaternion::can_not_make_matrix_from_zero_quaternion_exception);
}

TEST (QuaternionTest, norm_of_identity_quaternion_is_1)
{
    const Math::Quaternion quat;
    EXPECT_EQ (1, quat.norm ());
}

TEST (QuaternionTest, norm_of_quaternion_with_only_real_element_set_is_the_real_element)
{
    BEGIN_MULTITEST

    auto quat = create_random_quaternion ();
    quat.x () = 0;
    quat.y () = 0;
    quat.z () = 0;

    EXPECT_EQ (quat.w (), quat.norm ());

    END_MULTITEST
}

TEST (QuaternionTest, norm_of_quaternion_with_only_imaginary_part_is_the_length_of_the_imaginary_vector)
{
    BEGIN_MULTITEST

    auto quat = create_random_quaternion ();
    quat.w () = 0;

    EXPECT_EQ (std::sqrt (quat.x () * quat.x () + quat.y () * quat.y () + quat.z () * quat.z ()), quat.norm ());

    END_MULTITEST
}

TEST (QuaternionTest, norm_of_quaternion_is_the_square_root_of_the_sum_of_the_squared_elements)
{
    BEGIN_MULTITEST

    const auto quat = create_random_quaternion ();
    auto res = std::sqrt (quat.w () * quat.w () +
                          quat.x () * quat.x () +
                          quat.y () * quat.y () +
                          quat.z () * quat.z ());

    EXPECT_FLOAT_EQ (res, quat.norm ());

    END_MULTITEST
}

TEST (QuaternionTest, conjugate_of_identity_quaternion_is_identity_quaternion)
{
    const Math::Quaternion quaternion;
    const auto conjugate = quaternion.conjugate ();

    EXPECT_EQ (1, conjugate.w ());
    EXPECT_EQ (0, conjugate.x ());
    EXPECT_EQ (0, conjugate.y ());
    EXPECT_EQ (0, conjugate.z ());
}

TEST (QuaternionTest, conjugate_of_quaternion_switches_the_sign_of_the_imaginary_part)
{
    BEGIN_MULTITEST

    const auto quaternion = create_random_quaternion ();
    const auto res = quaternion.conjugate ();

    EXPECT_EQ (quaternion.w (), res.w ());
    EXPECT_EQ (-quaternion.x (), res.x ());
    EXPECT_EQ (-quaternion.y (), res.y ());
    EXPECT_EQ (-quaternion.z (), res.z ());

    END_MULTITEST
}

TEST (QuaternionTest, adding_two_quaternions_adds_the_real_parts_and_the_imaginary_parts_into_a_new_quaternion)
{
    BEGIN_MULTITEST

    const auto left = create_random_quaternion ();
    const auto right = create_random_quaternion ();
    const auto res = left + right;

    EXPECT_EQ (left.w () + right.w (), res.w ());
    EXPECT_EQ (left.x () + right.x (), res.x ());
    EXPECT_EQ (left.y () + right.y (), res.y ());
    EXPECT_EQ (left.z () + right.z (), res.z ());

    END_MULTITEST
}

TEST (QuaternionTest, subtracting_two_quaternions_subtracts_the_real_parts_and_the_imaginary_parts_into_a_new_quaternion)
{
    BEGIN_MULTITEST

    const auto left = create_random_quaternion ();
    const auto right = create_random_quaternion ();
    const auto res = left - right;

    EXPECT_EQ (left.w () - right.w (), res.w ());
    EXPECT_EQ (left.x () - right.x (), res.x ());
    EXPECT_EQ (left.y () - right.y (), res.y ());
    EXPECT_EQ (left.z () - right.z (), res.z ());

    END_MULTITEST
}

TEST (QuaternionTest, multiplying_quaternion_and_scalar_multiplies_each_component_of_the_quaternion)
{
    BEGIN_MULTITEST

    const auto quat = create_random_quaternion ();
    const auto scalar = create_random_scalar ();
    const auto res = quat * scalar;

    EXPECT_EQ (quat.w () * scalar, res.w ());
    EXPECT_EQ (quat.x () * scalar, res.x ());
    EXPECT_EQ (quat.y () * scalar, res.y ());
    EXPECT_EQ (quat.z () * scalar, res.z ());

    END_MULTITEST
}

TEST (QuaternionTest, dividing_quaternion_with_scalar_divides_each_component_of_the_quaternion)
{
    BEGIN_MULTITEST

    const auto quat = create_random_quaternion ();
    const auto scalar = create_random_scalar ();
    const auto res = quat / scalar;

    EXPECT_EQ (quat.w () / scalar, res.w ());
    EXPECT_EQ (quat.x () / scalar, res.x ());
    EXPECT_EQ (quat.y () / scalar, res.y ());
    EXPECT_EQ (quat.z () / scalar, res.z ());

    END_MULTITEST
}

TEST (QuaternionTest, multiplying_quaternions_with_only_real_part_gives_a_quaternion_with_only_the_real_parts_multiplied_and_no_imaginary_part)
{
    BEGIN_MULTITEST

    Math::Quaternion left;
    Math::Quaternion right;

    left.w () = create_random_scalar ();
    right.w () = create_random_scalar ();

    auto res = left * right;

    EXPECT_EQ (left.w () * right.w (), res.w ());
    EXPECT_EQ (0, res.x ());
    EXPECT_EQ (0, res.y ());
    EXPECT_EQ (0, res.z ());

    END_MULTITEST
}

TEST (QuaternionTest, multiplying_quaternions_with_only_imaginary_parts_gives_the_cross_product_of_the_imaginary_as_the_imaginary_part_and_the_negative_dot_product_as_the_real)
{
    BEGIN_MULTITEST

    auto left = create_random_quaternion ();
    auto right = create_random_quaternion ();
    left.w () = 0;
    right.w () = 0;

    auto res = left * right;

    auto crossprod = left.imag.cross (right.imag);

    EXPECT_EQ (crossprod.x, res.x ());
    EXPECT_EQ (crossprod.y, res.y ());
    EXPECT_EQ (crossprod.z, res.z ());
    EXPECT_EQ (-left.imag.dot (right.imag), res.w ());

    END_MULTITEST
}

TEST (QuaternionTest, multiplying_two_quaternions_follows_normal_rules)
{
    BEGIN_MULTITEST

    auto left = create_random_quaternion ();
    auto right = create_random_quaternion ();
    auto res = left * right;

    auto imag = left.imag.cross (right.imag) + left.real * right.imag + right.real * left.imag;
    auto real = left.real * right.real - left.imag.dot (right.imag);

    EXPECT_EQ (imag.x, res.x ());
    EXPECT_EQ (imag.y, res.y ());
    EXPECT_EQ (imag.z, res.z ());
    EXPECT_EQ (real, res.w ());

    END_MULTITEST
}

TEST (QuaternionTest, inverse_of_a_quaternion_is_the_conjugate_divded_by_the_norm_squared)
{
    BEGIN_MULTITEST

    const auto quat = create_random_quaternion ();
    const auto res = quat.inverse ();

    const auto normsquared = quat.norm () * quat.norm ();
    const auto inverse = quat.conjugate () / normsquared;

    EXPECT_FLOAT_EQ (inverse.w (), res.w ());
    EXPECT_FLOAT_EQ (inverse.x (), res.x ());
    EXPECT_FLOAT_EQ (inverse.y (), res.y ());
    EXPECT_FLOAT_EQ (inverse.z (), res.z ());

    END_MULTITEST
}

TEST (QuaternionTest, normalizing_quaternion_gives_a_unit_quaternion)
{
    BEGIN_MULTITEST

    auto quat = create_random_quaternion ();

    if (quat.norm () != 0) {
        quat.normalize ();
        EXPECT_FLOAT_EQ (1, quat.norm ());
    }

    END_MULTITEST
}

TEST (QuaternionTest, normalizing_zero_quaternion_throw_normalizing_zero_quaternion_exception)
{
    Math::Quaternion quat;
    quat.w () = 0;
    EXPECT_THROW (quat.normalize (), Math::Quaternion::normalizing_zero_quaternion_exception);
}

TEST (QuaternionTest, dividing_quaternion_by_zero_throws_division_by_zero_exception)
{
    Math::Quaternion quat;

    EXPECT_THROW (quat /= 0.0, Math::Quaternion::division_by_zero_exception);
    EXPECT_THROW (quat / 0.0, Math::Quaternion::division_by_zero_exception);
}

// Helper function
const Math::Quaternion create_random_quaternion ()
{
    auto array = create_double_array_of_size (4);
    Math::Quaternion quat (array);

    delete[] array;
    return quat;
}

const Math::Matrix4 make_matrix_from_quaternion (const Math::Quaternion& quat)
{
    Math::Matrix4 matrix;
    const auto s = 2.0 / quat.norm ();

    matrix (0,0) -= s * (quat.y () * quat.y () + quat.z () * quat.z ());
    matrix (0,1) += s * (quat.x () * quat.y () - quat.w () * quat.z ());
    matrix (0,2) += s * (quat.x () * quat.z () + quat.w () * quat.y ());

    matrix (1,0) += s * (quat.x () * quat.y () + quat.w () * quat.z ());
    matrix (1,1) -= s * (quat.x () * quat.x () + quat.z () * quat.z ());
    matrix (1,2) += s * (quat.y () * quat.z () - quat.w () * quat.x ());

    matrix (2,0) += s * (quat.x () * quat.z () - quat.w () * quat.y ());
    matrix (2,1) += s * (quat.y () * quat.z () + quat.w () * quat.x ());
    matrix (2,2) -= s * (quat.x () * quat.x () + quat.y () * quat.y ());

    return matrix;
}

const Math::Quaternion create_quaternion_from_matrix (const Math::Matrix4& matrix)
{
    const auto u = matrix (0,0) + matrix (1,1) + matrix (2,2);
    Math::Quaternion result;

    result.w () = 0.5 * std::sqrt (matrix.trace ());

    if (u > matrix (0,0) && u > matrix (1,1) && u > matrix (2,2)) {
        result.x () = 0.25 * (matrix (2,1) - matrix (1,2))/result.w ();
        result.y () = 0.25 * (matrix (0,2) - matrix (2,0))/result.w ();
        result.z () = 0.25 * (matrix (1,0) - matrix (0,1))/result.w ();
    } else {
        result.x () = 0.5 * std::sqrt (matrix (0,0) - matrix (1,1) - matrix (2,2) + matrix (3,3));
        result.y () = 0.5 * std::sqrt (-matrix (0,0) + matrix (1,1) - matrix (2,2) + matrix (3,3));
        result.z () = 0.5 * std::sqrt (-matrix (0,0) - matrix (1,1) + matrix (2,2) + matrix (3,3));
    }

    return result;
}
