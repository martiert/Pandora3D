#include <Math/vector4.h>
#include <Math/vector3.h>

#include <gtest/gtest.h>

TEST (Vector4Test, empty_constructor_creates_zero_vector)
{
    const Math::Vec4d vector;
    EXPECT_EQ (0.0, vector.x);
    EXPECT_EQ (0.0, vector.y);
    EXPECT_EQ (0.0, vector.z);
    EXPECT_EQ (0.0, vector.w);
}

TEST (Vector4Test, construction_with_arguments_populates_the_vector_with_those_arguments)
{
    const Math::Vec4d vector (0.1, 7.8, 4.3, 2.3);
    EXPECT_EQ (0.1, vector.x);
    EXPECT_EQ (7.8, vector.y);
    EXPECT_EQ (4.3, vector.z);
    EXPECT_EQ (2.3, vector.w);
}

TEST (Vector4Test, construction_from_array_populates_vector_with_array)
{
    double array[] = {3.4, 3.2, 2.1, 5.4};
    const Math::Vec4d vector (array);
    EXPECT_EQ (array[0], vector.x);
    EXPECT_EQ (array[1], vector.y);
    EXPECT_EQ (array[2], vector.z);
    EXPECT_EQ (array[3], vector.w);
}

TEST (Vector4Test, copy_constructor_copies_each_element)
{
    const Math::Vec4d vector (0.1, 7.8, 4.3, 2.3);
    const Math::Vec4d copy (vector);
    EXPECT_EQ (vector.x, copy.x);
    EXPECT_EQ (vector.y, copy.y);
    EXPECT_EQ (vector.z, copy.z);
    EXPECT_EQ (vector.w, copy.w);
}

TEST (Vector4Test, copy_constructor_makes_hard_copy)
{
    Math::Vec4d vector (0.1, 7.8, 4.3, 2.3);
    const Math::Vec4d copy (vector);
    ++vector.x;
    EXPECT_NE (vector.x, copy.x);
}

TEST (Vector4Test, assignment_from_vector_makes_copy)
{
    const Math::Vec4d vector (0.1, 7.8, 4.3, 2.3);
    Math::Vec4d copy;
    copy = vector;
    EXPECT_EQ (vector.x, copy.x);
    EXPECT_EQ (vector.y, copy.y);
    EXPECT_EQ (vector.z, copy.z);
    EXPECT_EQ (vector.w, copy.w);
}

TEST (Vector4Test, assignment_from_array_assigns_each_element_to_vector)
{
    double array[] = {3.4, 3.2, 2.1, 5.4};
    Math::Vec4d vector;
    vector = array;
    EXPECT_EQ (array[0], vector.x);
    EXPECT_EQ (array[1], vector.y);
    EXPECT_EQ (array[2], vector.z);
    EXPECT_EQ (array[3], vector.w);
}

TEST (Vector4Test, copy_from_Vector3_gives_a_Vector3_with_1_as_the_w_component)
{
    const Math::Vec3d vector3d (4.5, 3.2, 1.9);
    const Math::Vec4d copy (vector3d);
    EXPECT_EQ (vector3d.x, copy.x);
    EXPECT_EQ (vector3d.y, copy.y);
    EXPECT_EQ (vector3d.z, copy.z);
    EXPECT_EQ (1.0, copy.w);
}

TEST (Vector4Test, assigning_from_Vector3_gives_a_Vector3_with_1_as_the_w_component)
{
    const Math::Vec3d vector3d (4.5, 3.2, 1.9);
    Math::Vec4d copy;
    copy = vector3d;
    EXPECT_EQ (vector3d.x, copy.x);
    EXPECT_EQ (vector3d.y, copy.y);
    EXPECT_EQ (vector3d.z, copy.z);
    EXPECT_EQ (1.0, copy.w);
}

TEST (Vector4Test, index_operator_maps_to_x_y_z_w)
{
    const Math::Vec4d vector (2.3, 6.7, 8.9, 1.6);

    EXPECT_EQ (vector.x, vector[0]);
    EXPECT_EQ (vector.y, vector[1]);
    EXPECT_EQ (vector.z, vector[2]);
    EXPECT_EQ (vector.w, vector[3]);
}

TEST (Vector4Test, index_operator_manipulates_data)
{
    Math::Vec4d vector (2.3, 6.7, 8.9, 1.6);
    vector[2] = 5.3;
    EXPECT_EQ (5.3, vector.z);
}

TEST (Vector4Test, index_operator_throws_out_of_range_exception_when_out_of_range)
{
    const Math::Vec4d vector;
    EXPECT_THROW (vector[4], std::out_of_range);
}

TEST (Vector4Test, length_of_zero_vector_is_zero)
{
    const Math::Vec4d zero;
    EXPECT_EQ (0.0, zero.length ());
    EXPECT_EQ (0.0, zero.lengthSquared ());
}

TEST (Vector4Test, lengthSquared_of_vector_is_the_sum_of_the_squared_components)
{
    const Math::Vec4d vector (2.3, 4.5, 7.6, 9.4);

    EXPECT_EQ (vector.x * vector.x +
            vector.y * vector.y +
            vector.z * vector.z +
            vector.w * vector.w, vector.lengthSquared ());
}

TEST (Vector4Test, length_of_vector_is_the_square_root_of_the_squared_length)
{
    const Math::Vec4d vector (2.3, 4.5, 7.6, 9.4);
    EXPECT_EQ (std::sqrt (vector.lengthSquared ()), vector.length ());
}

TEST (Vector4Test, normalization_of_vector_gives_length_of_1)
{
    Math::Vec4d vector (3.2, 4.2, 6.7, 4.3);
    vector.normalize ();
    EXPECT_EQ (1.0, vector.length ());
}

TEST (Vector4Test, normalization_of_zero_vector_throws_domain_error)
{
    Math::Vec4d zero;
    EXPECT_THROW (zero.normalize (), std::domain_error);
}

TEST (Vector4Test, negation_of_vector_negates_each_component)
{
    const Math::Vec4d vector (3.2, 4.3, 1.2, 6.7);
    auto res = -vector;

    EXPECT_EQ (-vector.x, res.x);
    EXPECT_EQ (-vector.y, res.y);
    EXPECT_EQ (-vector.z, res.z);
    EXPECT_EQ (-vector.w, res.w);
}

TEST (Vector4Test, adding_two_vectors_adds_each_component)
{
    const Math::Vec4d vec_1 (3.2, 4.5, 3.1, 6.7);
    const Math::Vec4d vec_2 (4.5, 7.6, 1.1, 2.3);
    auto res = vec_1 + vec_2;

    EXPECT_EQ (vec_1.x + vec_2.x, res.x);
    EXPECT_EQ (vec_1.y + vec_2.y, res.y);
    EXPECT_EQ (vec_1.z + vec_2.z, res.z);
    EXPECT_EQ (vec_1.w + vec_2.w, res.w);
}

TEST (Vector4Test, subtracting_two_vectors_subtracts_each_component)
{
    const Math::Vec4d vec_1 (3.2, 4.5, 3.1, 6.7);
    const Math::Vec4d vec_2 (4.5, 7.6, 1.1, 2.3);
    auto res = vec_1 - vec_2;

    EXPECT_EQ (vec_1.x - vec_2.x, res.x);
    EXPECT_EQ (vec_1.y - vec_2.y, res.y);
    EXPECT_EQ (vec_1.z - vec_2.z, res.z);
    EXPECT_EQ (vec_1.w - vec_2.w, res.w);
}

TEST (Vector4Test, adding_vector_to_vector_adds_each_component)
{
    const Math::Vec4d vec_1 (3.2, 4.5, 3.1, 6.7);
    const Math::Vec4d vec_2 (4.5, 7.6, 1.1, 2.3);
    auto res = vec_1;
    res += vec_2;

    EXPECT_EQ (vec_1.x + vec_2.x, res.x);
    EXPECT_EQ (vec_1.y + vec_2.y, res.y);
    EXPECT_EQ (vec_1.z + vec_2.z, res.z);
    EXPECT_EQ (vec_1.w + vec_2.w, res.w);
}

TEST (Vector4Test, subtracting_vector_from_vector_subtracts_each_component)
{
    const Math::Vec4d vec_1 (3.2, 4.5, 3.1, 6.7);
    const Math::Vec4d vec_2 (4.5, 7.6, 1.1, 2.3);
    auto res = vec_1;
    res -= vec_2;

    EXPECT_EQ (vec_1.x - vec_2.x, res.x);
    EXPECT_EQ (vec_1.y - vec_2.y, res.y);
    EXPECT_EQ (vec_1.z - vec_2.z, res.z);
    EXPECT_EQ (vec_1.w - vec_2.w, res.w);
}

TEST (Vector4Test, multiplying_vector_with_scalar_from_right_multiplies_each_component_with_scalar)
{
    const Math::Vec4d vector (3.2, 4.5, 3.1, 6.7);
    auto res = vector * 2.4;

    EXPECT_EQ (vector.x * 2.4, res.x);
    EXPECT_EQ (vector.y * 2.4, res.y);
    EXPECT_EQ (vector.z * 2.4, res.z);
    EXPECT_EQ (vector.w * 2.4, res.w);
}

TEST (Vector4Test, multiplying_vector_with_scalar_from_left_multiplies_each_component_with_scalar)
{
    const Math::Vec4d vector (3.2, 4.5, 3.1, 6.7);
    auto res = 2.4 * vector;

    EXPECT_EQ (vector.x * 2.4, res.x);
    EXPECT_EQ (vector.y * 2.4, res.y);
    EXPECT_EQ (vector.z * 2.4, res.z);
    EXPECT_EQ (vector.w * 2.4, res.w);
}

TEST (Vector4Test, dividing_vector_with_scalar_from_right_divides_each_component_with_scalar)
{
    const Math::Vec4d vector (3.2, 4.5, 3.1, 6.7);
    auto res = vector / 2.4;

    EXPECT_EQ (vector.x / 2.4, res.x);
    EXPECT_EQ (vector.y / 2.4, res.y);
    EXPECT_EQ (vector.z / 2.4, res.z);
    EXPECT_EQ (vector.w / 2.4, res.w);
}

TEST (Vector4Test, dividing_vector_and_zero_throws_invalid_argument)
{
    const Math::Vec4d vector (3.2, 4.5, 3.1, 6.7);
    EXPECT_THROW (vector / 0.0, std::invalid_argument);
}

TEST (Vector4Test, multiplying_vector_with_scalar_multiplies_each_component_with_scalar)
{
    const Math::Vec4d vector (3.2, 4.5, 3.1, 6.7);
    auto res = vector;
    res *= 2.4;

    EXPECT_EQ (vector.x * 2.4, res.x);
    EXPECT_EQ (vector.y * 2.4, res.y);
    EXPECT_EQ (vector.z * 2.4, res.z);
    EXPECT_EQ (vector.w * 2.4, res.w);
}

TEST (Vector4Test, dividing_vector_with_scalar_divides_each_component_with_scalar)
{
    const Math::Vec4d vector (3.2, 4.5, 3.1, 6.7);
    auto res = vector;
    res /= 2.4;

    EXPECT_EQ (vector.x / 2.4, res.x);
    EXPECT_EQ (vector.y / 2.4, res.y);
    EXPECT_EQ (vector.z / 2.4, res.z);
    EXPECT_EQ (vector.w / 2.4, res.w);
}

TEST (Vector4Test, multiplying_vector_to_vector_multiplies_each_component)
{
    const Math::Vec4d vector (3.2, 4.5, 3.1, 6.7);
    const Math::Vec4d other (5.4, 2.1, 7.6, 9.8);
    auto res = vector;
    res *= other;

    EXPECT_EQ (vector.x * other.x, res.x);
    EXPECT_EQ (vector.y * other.y, res.y);
    EXPECT_EQ (vector.z * other.z, res.z);
    EXPECT_EQ (vector.w * other.w, res.w);
}

TEST (Vector4Test, dividing_vector_with_zero_throws_invalid_argument)
{
    Math::Vec4d vector (3.1, 2.6, 7.1, 8.3);
    EXPECT_THROW (vector /= 0.0, std::invalid_argument);
}

TEST (Vector4Test, dot_product_of_two_vectors_add_the_product_of_the_vectors)
{
    const Math::Vec4d vector (3.2, 4.5, 3.1, 6.7);
    const Math::Vec4d other (5.4, 2.1, 7.6, 9.8);
    auto dotprod = vector.dot (other);
    auto multvec = vector * other;
    EXPECT_EQ (multvec.x + multvec.y + multvec.z + multvec.w, dotprod);
}

TEST (Vector4Test, equality_operator_on_same_object_returns_true)
{
    const Math::Vec4d vector (3.2, 4.5, 3.1, 6.7);
    EXPECT_EQ (vector, vector);
}

TEST (Vector4Test, equality_operator_on_copy_returns_true)
{
    const Math::Vec4d vector (3.2, 4.5, 3.1, 6.7);
    auto copy (vector);
    EXPECT_EQ (vector, copy);
}

TEST (Vector4Test, equality_operator_on_similar_vectors_return_true)
{
    const Math::Vec4d vector (3.2, 4.5, 3.1, 6.7);
    const Math::Vec4d similar (3.2, 4.5, 3.1, 6.7);
    EXPECT_EQ (vector, similar);
}

TEST (Vector4Test, equality_operator_on_different_x_returns_false)
{
    const Math::Vec4d vector (3.2, 4.5, 3.1, 6.7);
    const Math::Vec4d different (2.3, 4.5, 3.1, 6.7);
    EXPECT_FALSE (vector == different);
}

TEST (Vector4Test, equality_operator_on_different_y_returns_false)
{
    const Math::Vec4d vector (3.2, 4.5, 3.1, 6.7);
    const Math::Vec4d different (3.2, 4.0, 3.1, 6.7);
    EXPECT_FALSE (vector == different);
}

TEST (Vector4Test, equality_operator_on_different_z_returns_false)
{
    const Math::Vec4d vector (3.2, 4.5, 3.1, 6.7);
    const Math::Vec4d different (3.2, 4.5, .1, 6.7);
    EXPECT_FALSE (vector == different);
}

TEST (Vector4Test, equality_operator_on_different_w_returns_false)
{
    const Math::Vec4d vector (3.2, 4.5, 3.1, 6.7);
    const Math::Vec4d different (3.2, 4.5, 3.1, 7.8);
    EXPECT_FALSE (vector == different);
}

TEST (Vector4Test, inequality_operator_on_different_x_returns_true)
{
    const Math::Vec4d vector (3.2, 4.5, 3.1, 6.7);
    const Math::Vec4d different (2.3, 4.5, 3.1, 6.7);
    EXPECT_NE (vector, different);
}

TEST (Vector4Test, inequality_operator_on_different_y_returns_true)
{
    const Math::Vec4d vector (3.2, 4.5, 3.1, 6.7);
    const Math::Vec4d different (3.2, 4.0, 3.1, 6.7);
    EXPECT_NE (vector, different);
}

TEST (Vector4Test, inequality_operator_on_different_z_returns_true)
{
    const Math::Vec4d vector (3.2, 4.5, 3.1, 6.7);
    const Math::Vec4d different (3.2, 4.5, .1, 6.7);
    EXPECT_NE (vector, different);
}

TEST (Vector4Test, inequality_operator_on_different_w_returns_true)
{
    const Math::Vec4d vector (3.2, 4.5, 3.1, 6.7);
    const Math::Vec4d different (3.2, 4.5, 3.1, 7.8);
    EXPECT_NE (vector, different);
}

TEST (Vector4Test, inequality_operator_on_same_object_returns_false)
{
    const Math::Vec4d vector (3.2, 4.5, 3.1, 6.7);
    EXPECT_FALSE (vector != vector);
}

TEST (Vector4Test, inequality_operator_on_copy_returns_false)
{
    const Math::Vec4d vector (3.2, 4.5, 3.1, 6.7);
    auto copy (vector);
    EXPECT_FALSE (vector != copy);
}

TEST (Vector4Test, inequality_operator_on_similar_vectors_return_false)
{
    const Math::Vec4d vector (3.2, 4.5, 3.1, 6.7);
    const Math::Vec4d similar (3.2, 4.5, 3.1, 6.7);
    EXPECT_FALSE (vector != similar);
}

TEST (Vector4Test, vector_can_be_casted_c_style)
{
    const Math::Vec4d vector (3.2, 4.5, 3.1, 6.7);
    auto pointer = (const double *) vector;

    EXPECT_EQ (pointer[0], vector.x);
    EXPECT_EQ (pointer[1], vector.y);
    EXPECT_EQ (pointer[2], vector.z);
    EXPECT_EQ (pointer[3], vector.w);
}

TEST (Vector4Test, vector_can_be_statically_casted)
{
    const Math::Vec4d vector (3.2, 4.5, 3.1, 6.7);
    auto pointer = static_cast<const double *> (vector);

    EXPECT_EQ (pointer[0], vector.x);
    EXPECT_EQ (pointer[1], vector.y);
    EXPECT_EQ (pointer[2], vector.z);
    EXPECT_EQ (pointer[3], vector.w);
}

TEST (Vector4Test, changing_the_casted_pointers_changes_the_vector)
{
    Math::Vec4d vector (3.2, 4.5, 3.1, 6.7);
    auto pointer = (double *) vector;
    auto static_ptr = static_cast<double *> (vector);

    ++pointer[2];
    EXPECT_EQ (pointer[2], vector.z);
    EXPECT_EQ (static_ptr[2], vector.z);
}
