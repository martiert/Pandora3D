#include <quaternion.h>
#include <vector3.h>
#include <gtest/gtest.h>
#include <cmath>

#include "test-helpers.h"

Math::Vec3d create_random_vector3 ();
Math::Matrix4<double> create_random_matrix4 ();
Math::Matrix4<double> create_random_rotation_matrix ();
Math::Matrix4<double> create_positive_diagonal_matrix ();
Math::Quaternion<double> create_random_quaternion ();

Math::Quaternion<double> create_quaternion_from_matrix (const Math::Matrix4<double>& matrix);
Math::Quaternion<double> slerp (const Math::Quaternion<double>& from, const Math::Quaternion<double>& to, const double& t);
Math::Matrix4<double> make_matrix_from_quaternion (const Math::Quaternion<double>& quat);

TEST (QuaternionTest, default_quaternion_is_identity_quaternion)
{
  const Math::Quaternion<double> quat;

  EXPECT_EQ (1, quat.w ());
  EXPECT_EQ (0, quat.x ());
  EXPECT_EQ (0, quat.y ());
  EXPECT_EQ (0, quat.z ());
}

TEST (QuaternionTest, creating_quaternion_with_arguments_populates_quaternion_with_arguments)
{
  const auto array = create_double_array_of_size (4);
  const Math::Quaternion<double> quat (array[0], array[1], array[2], array[3]);

  EXPECT_EQ (array[0], quat.w ());
  EXPECT_EQ (array[1], quat.x ());
  EXPECT_EQ (array[2], quat.y ());
  EXPECT_EQ (array[3], quat.z ());

  delete[] array;
}

TEST (QuaternionTest, creating_quaternion_from_array_populates_quaternion)
{
  const auto array = create_double_array_of_size (4);
  const Math::Quaternion<double> quat (array);

  EXPECT_EQ (array[0], quat.w ());
  EXPECT_EQ (array[1], quat.x ());
  EXPECT_EQ (array[2], quat.y ());
  EXPECT_EQ (array[3], quat.z ());

  delete[] array;
}

TEST (QuaternionTest, creating_quaternion_with_real_element_and_imaginary_vector_sets_quaternion)
{
  const auto vector = create_random_vector3 ();
  const auto real = create_random_scalar ();
  Math::Quaternion<double> quat (real, vector);

  EXPECT_EQ (real, quat.w ());
  EXPECT_EQ (vector.x, quat.x ());
  EXPECT_EQ (vector.y, quat.y ());
  EXPECT_EQ (vector.z, quat.z ());
}

TEST (QuaternionTest, creating_quaternion_around_axis_with_angle_creates_correct_quaternion)
{
  const auto axis = create_random_vector3 ();
  const auto angle = create_random_scalar ();
  const Math::Quaternion<double> quat (axis, angle);

  EXPECT_EQ (std::cos (angle), quat.w ());
  EXPECT_EQ (std::sin (angle) * axis.x, quat.x ());
  EXPECT_EQ (std::sin (angle) * axis.y, quat.y ());
  EXPECT_EQ (std::sin (angle) * axis.z, quat.z ());
}

TEST (QuaternionTest, creating_quaternion_from_identity_matrix_creates_the_identity_quaternion)
{
  Math::Quaternion<double> quat (Math::Matrix4<double>::IDENTITY);

  EXPECT_EQ (1, quat.w ());
  EXPECT_EQ (0, quat.x());
  EXPECT_EQ (0, quat.y ());
  EXPECT_EQ (0, quat.z ());
}

TEST (QuaternionTest, creating_quaternion_from_positive_diagonal_matrix_gives_real_part_as_half_of_the_squared_trace_and_zero_imaginary_part)
{
  const auto matrix = create_positive_diagonal_matrix ();
  const Math::Quaternion<double> quat (matrix);

  EXPECT_EQ (0.5 * std::sqrt (matrix.trace ()), quat.w ());
  EXPECT_EQ (0, quat.x ());
  EXPECT_EQ (0, quat.y ());
  EXPECT_EQ (0, quat.x ());
}

TEST (QuaternionTest, quaternion_creating_from_matrix_is_correct)
{
  const auto matrix = create_random_matrix4 ();
  const Math::Quaternion<double> quat (matrix);
  const auto correct_quat = create_quaternion_from_matrix (matrix);

  EXPECT_EQ (correct_quat.w (), quat.w ());
  EXPECT_EQ (correct_quat.x (), quat.x ());
  EXPECT_EQ (correct_quat.y (), quat.y ());
  EXPECT_EQ (correct_quat.z (), quat.z ());
}

TEST (QuaternionTest, creating_quaternion_from_identity_matrix_and_creating_matrix_from_quaternion_returns_identity)
{
  const Math::Quaternion<double> quat (Math::Matrix4<double>::IDENTITY);
  const auto result = quat.create_matrix ();

  for (auto i = 0; i < 16; ++i)
    EXPECT_EQ (Math::Matrix4<double>::IDENTITY[i], result[i]);
}

TEST (QuaternionTest, creating_quaternion_from_simple_rotation_matrix_and_getting_the_matrix_from_the_quaternion_gives_the_same_matrix)
{
  const auto matrix = create_random_rotation_matrix ();
  const Math::Quaternion<double> quat (matrix);
  const auto result = quat.create_matrix ();

  for (auto i = 0; i < 16; ++i)
    EXPECT_FLOAT_EQ (matrix[i], result[i]);
}

TEST (QuaternionTest, creating_matrix_from_identity_quaternion_gives_identity_matrix)
{
  const Math::Quaternion<double> quat;
  const auto res = quat.create_matrix ();

  for (auto i = 0; i < 16; ++i)
    EXPECT_EQ (Math::Matrix4<double>::IDENTITY[i], res[i]);
}

TEST (QuaternionTest, creating_matrix_from_quaternion_gives_correct_matrix)
{
  const auto quat = create_random_quaternion ();
  const auto res = quat.create_matrix ();
  const auto correct = make_matrix_from_quaternion (quat);

  for (auto i = 0; i < 16; ++i)
    EXPECT_EQ (correct[i], res[i]);
}

TEST (QuaternionTest, creating_matrix_from_zero_quaternion_throws_can_not_make_matrix_from_zero_quaternion_exception)
{
  Math::Quaternion<double> quat;
  quat.w () = 0;

  EXPECT_THROW (quat.create_matrix (), Math::Quaternion<double>::can_not_make_matrix_from_zero_quaternion_exception);
}

TEST (QuaternionTest, norm_of_identity_quaternion_is_1)
{
  const Math::Quaternion<double> quat;
  EXPECT_EQ (1, quat.norm ());
}

TEST (QuaternionTest, norm_of_quaternion_with_only_real_element_set_is_the_real_element)
{
  auto quat = create_random_quaternion ();
  quat.x () = 0;
  quat.y () = 0;
  quat.z () = 0;

  EXPECT_EQ (quat.w (), quat.norm ());
}

TEST (QuaternionTest, norm_of_quaternion_with_only_imaginary_part_is_the_length_of_the_imaginary_vector)
{
  auto quat = create_random_quaternion ();
  quat.w () = 0;

  EXPECT_EQ (std::sqrt (quat.x () * quat.x () + quat.y () * quat.y () + quat.z () * quat.z ()), quat.norm ());
}

TEST (QuaternionTest, norm_of_quaternion_is_the_square_root_of_the_sum_of_the_squared_elements)
{
  const auto quat = create_random_quaternion ();
  auto res = std::sqrt (quat.w () * quat.w () +
                        quat.x () * quat.x () +
                        quat.y () * quat.y () +
                        quat.z () * quat.z ());

  EXPECT_FLOAT_EQ (res, quat.norm ());
}

TEST (QuaternionTest, conjugate_of_identity_quaternion_is_identity_quaternion)
{
  const Math::Quaternion<double> quaternion;
  const auto conjugate = quaternion.conjugate ();

  EXPECT_EQ (1, conjugate.w ());
  EXPECT_EQ (0, conjugate.x ());
  EXPECT_EQ (0, conjugate.y ());
  EXPECT_EQ (0, conjugate.z ());
}

TEST (QuaternionTest, conjugate_of_quaternion_switches_the_sign_of_the_imaginary_part)
{
  const auto quaternion = create_random_quaternion ();
  const auto res = quaternion.conjugate ();

  EXPECT_EQ (quaternion.w (), res.w ());
  EXPECT_EQ (-quaternion.x (), res.x ());
  EXPECT_EQ (-quaternion.y (), res.y ());
  EXPECT_EQ (-quaternion.z (), res.z ());
}

TEST (QuaternionTest, adding_two_quaternions_adds_the_real_parts_and_the_imaginary_parts_into_a_new_quaternion)
{
  const auto left = create_random_quaternion ();
  const auto right = create_random_quaternion ();
  const auto res = left + right;

  EXPECT_EQ (left.w () + right.w (), res.w ());
  EXPECT_EQ (left.x () + right.x (), res.x ());
  EXPECT_EQ (left.y () + right.y (), res.y ());
  EXPECT_EQ (left.z () + right.z (), res.z ());
}

TEST (QuaternionTest, subtracting_two_quaternions_subtracts_the_real_parts_and_the_imaginary_parts_into_a_new_quaternion)
{
  const auto left = create_random_quaternion ();
  const auto right = create_random_quaternion ();
  const auto res = left - right;

  EXPECT_EQ (left.w () - right.w (), res.w ());
  EXPECT_EQ (left.x () - right.x (), res.x ());
  EXPECT_EQ (left.y () - right.y (), res.y ());
  EXPECT_EQ (left.z () - right.z (), res.z ());
}

TEST (QuaternionTest, multiplying_quaternion_and_scalar_multiplies_each_component_of_the_quaternion)
{
  const auto quat = create_random_quaternion ();
  const auto scalar = create_random_scalar ();
  const auto res = quat * scalar;

  EXPECT_EQ (quat.w () * scalar, res.w ());
  EXPECT_EQ (quat.x () * scalar, res.x ());
  EXPECT_EQ (quat.y () * scalar, res.y ());
  EXPECT_EQ (quat.z () * scalar, res.z ());
}

TEST (QuaternionTest, dividing_quaternion_with_scalar_divides_each_component_of_the_quaternion)
{
  const auto quat = create_random_quaternion ();
  const auto scalar = create_random_scalar ();
  const auto res = quat / scalar;

  EXPECT_EQ (quat.w () / scalar, res.w ());
  EXPECT_EQ (quat.x () / scalar, res.x ());
  EXPECT_EQ (quat.y () / scalar, res.y ());
  EXPECT_EQ (quat.z () / scalar, res.z ());
}

TEST (QuaternionTest, multiplying_quaternions_with_only_real_part_gives_a_quaternion_with_only_the_real_parts_multiplied_and_no_imaginary_part)
{
  Math::Quaternion<double> left;
  Math::Quaternion<double> right;

  left.w () = create_random_scalar ();
  right.w () = create_random_scalar ();

  auto res = left * right;

  EXPECT_EQ (left.w () * right.w (), res.w ());
  EXPECT_EQ (0, res.x ());
  EXPECT_EQ (0, res.y ());
  EXPECT_EQ (0, res.z ());
}

TEST (QuaternionTest, multiplying_quaternions_with_only_imaginary_parts_gives_the_cross_product_of_the_imaginary_as_the_imaginary_part_and_the_negative_dot_product_as_the_real)
{
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
}

TEST (QuaternionTest, multiplying_two_quaternions_follows_normal_rules)
{
  auto left = create_random_quaternion ();
  auto right = create_random_quaternion ();
  auto res = left * right;

  auto imag = left.imag.cross (right.imag) + left.real * right.imag + right.real * left.imag;
  auto real = left.real * right.real - left.imag.dot (right.imag);

  EXPECT_EQ (imag.x, res.x ());
  EXPECT_EQ (imag.y, res.y ());
  EXPECT_EQ (imag.z, res.z ());
  EXPECT_EQ (real, res.w ());
}

TEST (QuaternionTest, inverse_of_a_quaternion_is_the_conjugate_divded_by_the_norm_squared)
{
  const auto quat = create_random_quaternion ();
  const auto res = quat.inverse ();

  const auto normsquared = quat.norm () * quat.norm ();
  const auto inverse = quat.conjugate () / normsquared;

  EXPECT_FLOAT_EQ (inverse.w (), res.w ());
  EXPECT_FLOAT_EQ (inverse.x (), res.x ());
  EXPECT_FLOAT_EQ (inverse.y (), res.y ());
  EXPECT_FLOAT_EQ (inverse.z (), res.z ());
}

TEST (QuaternionTest, inverse_of_quaternion_multiplied_with_the_quaternion_should_be_identity)
{
  const auto quat = create_random_quaternion ();
  const auto inverse = quat.inverse ();
  const auto res = inverse * quat;

  EXPECT_NEAR (1, res.w (), PRECISION);
  EXPECT_NEAR (0, res.x (), PRECISION);
  EXPECT_NEAR (0, res.y (), PRECISION);
  EXPECT_NEAR (0, res.z (), PRECISION);
}

TEST (QuaternionTest, quaternion_multiplied_with_its_inverse_should_be_identity)
{
  const auto quat = create_random_quaternion ();
  const auto inverse = quat.inverse ();
  const auto res = quat * inverse;

  EXPECT_NEAR (1, res.w (), PRECISION);
  EXPECT_NEAR (0, res.x (), PRECISION);
  EXPECT_NEAR (0, res.y (), PRECISION);
  EXPECT_NEAR (0, res.z (), PRECISION);
}

TEST (QuaternionTest, normalizing_quaternion_gives_a_unit_quaternion)
{
  auto quat = create_random_quaternion ();
  quat.normalize ();

  EXPECT_FLOAT_EQ (1, quat.norm ());
}

TEST (QuaternionTest, normalizing_zero_quaternion_throw_normalizing_zero_quaternion_exception)
{
  Math::Quaternion<double> quat;
  quat.w () = 0;

  EXPECT_THROW (quat.normalize (), Math::Quaternion<double>::normalizing_zero_quaternion_exception);
}

TEST (QuaternionTest, dividing_quaternion_by_zero_throws_division_by_zero_exception)
{
  Math::Quaternion<double> quat;

  EXPECT_THROW (quat /= 0.0, Math::Quaternion<double>::division_by_zero_exception);
  EXPECT_THROW (quat / 0.0, Math::Quaternion<double>::division_by_zero_exception);
}

TEST (QuaternionTest, spherical_linear_interpolation_between_from_and_to_with_t_equal_zero_returns_from)
{
  auto from = create_random_quaternion ();
  auto to = create_random_quaternion ();
  from.normalize ();
  to.normalize ();

  const auto res = Math::Quaternion<double>::slerp (from, to, 0);

  EXPECT_EQ (from.w (), res.w ());
  EXPECT_EQ (from.x (), res.x ());
  EXPECT_EQ (from.y (), res.y ());
  EXPECT_EQ (from.z (), res.z ());
}

TEST (QuaternionTest, sperical_linear_interpolation_between_from_ant_to_with_t_equal_one_return_to)
{
  auto from = create_random_quaternion ();
  auto to = create_random_quaternion ();
  from.normalize ();
  to.normalize ();

  const auto res = Math::Quaternion<double>::slerp (from, to, 1);

  EXPECT_EQ (to.w (), res.w ());
  EXPECT_EQ (to.x (), res.x ());
  EXPECT_EQ (to.y (), res.y ());
  EXPECT_EQ (to.z (), res.z ());
}

TEST (QuaternionTest, sperical_linear_interpolation_makes_correct_quaternion)
{
  auto from = create_random_quaternion ();
  auto to = create_random_quaternion ();
  from.normalize ();
  to.normalize ();

  const auto t = (rand () % 400) / 400.0;
  const auto res = Math::Quaternion<double>::slerp (from, to, t);
  const auto correct = slerp (from, to, t);

  EXPECT_EQ (correct.w (), res.w ());
  EXPECT_EQ (correct.x (), res.x ());
  EXPECT_EQ (correct.y (), res.y ());
  EXPECT_EQ (correct.z (), res.z ());
}

// Helper function
Math::Quaternion<double> create_random_quaternion ()
{
  auto array = create_double_array_of_size (4);
  Math::Quaternion<double> quat (array);

  delete[] array;
  return quat;
}

Math::Matrix4<double> create_random_rotation_matrix ()
{
  Math::Matrix4<double> result;
  const auto angle = (rand () % 300) / 200.0;
  result (0,0) = std::cos (angle);
  result (0,2) = std::sin (angle);
  result (2,0) = -result (0,2);
  result (2,2) = result (0,0);

  return result;
}

Math::Matrix4<double> create_positive_diagonal_matrix ()
{
  Math::Matrix4<double> matrix;
  for (auto i = 0; i < 3; ++i) {
    const auto scalar = create_random_scalar ();
    matrix (i,i) = std::abs (scalar);
  }
  return matrix;
}

Math::Matrix4<double> make_matrix_from_quaternion (const Math::Quaternion<double>& quat)
{
  Math::Matrix4<double> matrix;
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

Math::Quaternion<double> create_quaternion_from_large_real_component (const Math::Matrix4<double>& matrix)
{
  Math::Quaternion<double> result;
  result.w () = 0.5 * std::sqrt (matrix.trace ());
  result.x () = 0.25 * (matrix (2,1) - matrix (1,2))/result.w ();
  result.y () = 0.25 * (matrix (0,2) - matrix (2,0))/result.w ();
  result.z () = 0.25 * (matrix (1,0) - matrix (0,1))/result.w ();

  return result;
}


Math::Quaternion<double> create_quaternion_from_small_real_component (const Math::Matrix4<double>& matrix)
{
  Math::Quaternion<double> result;
  result.w () = 0.5 * std::sqrt (matrix.trace ());
  result.x () = 0.5 * std::sqrt (matrix (0,0) - matrix (1,1) - matrix (2,2) + matrix (3,3));
  result.y () = 0.5 * std::sqrt (-matrix (0,0) + matrix (1,1) - matrix (2,2) + matrix (3,3));
  result.z () = 0.5 * std::sqrt (-matrix (0,0) - matrix (1,1) + matrix (2,2) + matrix (3,3));

  return result;
}

Math::Quaternion<double> create_quaternion_from_matrix (const Math::Matrix4<double>& matrix)
{
  const auto u = matrix (0,0) + matrix (1,1) + matrix (2,2);

  if (u > matrix (0,0) && u > matrix (1,1) && u > matrix (2,2))
    return create_quaternion_from_large_real_component (matrix);

  return create_quaternion_from_small_real_component (matrix);
}

Math::Quaternion<double> slerp (const Math::Quaternion<double>& from, const Math::Quaternion<double>& to, const double& t)
{
  const auto angle = std::acos (from.real * to.real + from.imag.dot (to.imag));
  const auto from_scale = std::sin (angle * (1 - t))/std::sin (angle);
  const auto to_scale = std::sin (angle * t)/std::sin (angle);

  return from * from_scale + to * to_scale;
}
