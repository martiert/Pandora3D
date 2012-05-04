#include <Math/vector3.h>

#include <gtest/gtest.h>

TEST (Vector3Test, empty_constructor_gives_zero_vector)
{
    const Math::Vec3d vector;
    EXPECT_EQ (0.0, vector.x);
    EXPECT_EQ (0.0, vector.y);
    EXPECT_EQ (0.0, vector.z);
}

TEST (Vector3Test, constructing_a_vector_with_three_arguments_populates_the_vector_with_those_arguments)
{
    const Math::Vec3d vector (0.1, 2.3, 3.7);
    EXPECT_EQ (0.1, vector.x);
    EXPECT_EQ (2.3, vector.y);
    EXPECT_EQ (3.7, vector.z);
}

TEST (Vector3Test, constructing_a_vector_with_an_array_of_three_elements_populates_vector_with_the_array)
{
    double tmp[] = {2.3, 3.1, 4.7};
    const Math::Vec3d vector (tmp);
    EXPECT_EQ (tmp[0], vector.x);
    EXPECT_EQ (tmp[1], vector.y);
    EXPECT_EQ (tmp[2], vector.z);
}

TEST (Vector3Test, assigning_a_vector_to_an_array_populates_vector_with_given_array)
{
    double tmp[] = {2.3, 3.1, 4.7};
    const Math::Vec3d vector = tmp;
    EXPECT_EQ (tmp[0], vector.x);
    EXPECT_EQ (tmp[1], vector.y);
    EXPECT_EQ (tmp[2], vector.z);
}

TEST (Vector3Test, assigning_a_vector_to_another_vector_populates_the_vector)
{
    const Math::Vec3d vector (0.1, 2.3, 3.7);
    auto copy = vector;
    EXPECT_EQ (vector.x, copy.x);
    EXPECT_EQ (vector.y, copy.y);
    EXPECT_EQ (vector.z, copy.z);
}

TEST (Vector3Test, copy_constructor_makes_hard_copy)
{
    const Math::Vec3d vector (0.1, 2.3, 3.7);
    auto copy (vector);
    EXPECT_EQ (vector.x, copy.x);
    EXPECT_EQ (vector.y, copy.y);
    EXPECT_EQ (vector.z, copy.z);
    ++copy.x;
    EXPECT_NE (vector.x, copy.x);
}

TEST (Vector3Test, index_operator_maps_to_x_y_and_z)
{
    Math::Vec3d vector_1 (4.3, 3.1, 4.1);
    const Math::Vec3d vector_2 (3.3, 1.5, 2.6);

    EXPECT_EQ (vector_1.x, vector_1[0]);
    EXPECT_EQ (vector_1.y, vector_1[1]);
    EXPECT_EQ (vector_1.z, vector_1[2]);

    EXPECT_EQ (vector_2.x, vector_2[0]);
    EXPECT_EQ (vector_2.y, vector_2[1]);
    EXPECT_EQ (vector_2.z, vector_2[2]);

    vector_1[0] = 3.1;
    EXPECT_EQ (vector_1.x, vector_1[0]);
    EXPECT_EQ (vector_1.y, vector_1[1]);
    EXPECT_EQ (vector_1.z, vector_1[2]);
}

TEST (Vector3Test, index_operator_throws_out_of_range_exception_when_out_of_range)
{
    Math::Vec3d vector;
    const Math::Vec3d const_vector;
    double tmp = 3;

    EXPECT_THROW (tmp = vector[3], std::out_of_range);
    EXPECT_THROW (tmp = const_vector[3], std::out_of_range);
}

TEST (Vector3Test, length_of_zero_vector_is_zero)
{
    const Math::Vec3d vector;
    EXPECT_EQ (0.0, vector.length ());
    EXPECT_EQ (0.0, vector.lengthSquared ());
}

TEST (Vector3Test, length_of_vector_follows_mathematical_rules)
{
    const Math::Vec3d vector_1 (2.3, 4.2, 1.2);
    EXPECT_EQ (std::sqrt (vector_1.x*vector_1.x + vector_1.y*vector_1.y + vector_1.z*vector_1.z), vector_1.length ());
    EXPECT_EQ ((vector_1.x*vector_1.x + vector_1.y*vector_1.y + vector_1.z*vector_1.z), vector_1.lengthSquared ());
}

TEST (Vector3Test, normalize_vector_gives_length_of_1)
{
    Math::Vec3d vector (3.2, 1.2, 4.5);
    vector.normalize ();
    EXPECT_FLOAT_EQ (1.0, vector.length ());
}

TEST (Vector3Test, normalize_zero_vector_throws_domain_error)
{
    Math::Vec3d vector;
    EXPECT_THROW (vector.normalize (), std::domain_error);
}

TEST (Vector3Test, negating_a_vector_returns_the_negation_of_each_element)
{
    const Math::Vec3d vec_1 (2.3, 4.2, 8.7);
    auto vec_2 = -vec_1;

    EXPECT_EQ (-vec_2.x, vec_1.x);
    EXPECT_EQ (-vec_2.y, vec_1.y);
    EXPECT_EQ (-vec_2.z, vec_1.z);
}

TEST (Vector3Test, adding_two_vectors_adds_the_vectors_by_elements)
{
    const Math::Vec3d vec_1 (2.3, 4.2, 8.7);
    const Math::Vec3d vec_2 (4.3, 1.2, 5.6);

    auto res = vec_1 + vec_2;
    EXPECT_EQ (vec_1.x + vec_2.x, res.x);
    EXPECT_EQ (vec_1.y + vec_2.y, res.y);
    EXPECT_EQ (vec_1.z + vec_2.z, res.z);
}

TEST (Vector3Test, subtracting_two_vectors_subtracts_the_vectors_by_elements)
{
    const Math::Vec3d vec_1 (2.3, 4.2, 8.7);
    const Math::Vec3d vec_2 (4.3, 1.2, 5.6);

    auto res = vec_1 - vec_2;
    EXPECT_EQ (vec_1.x - vec_2.x, res.x);
    EXPECT_EQ (vec_1.y - vec_2.y, res.y);
    EXPECT_EQ (vec_1.z - vec_2.z, res.z);
}

TEST (Vector3Test, adding_a_vector_to_a_vector_adds_element_wise)
{
    const Math::Vec3d vec_1 (2.3, 4.2, 8.7);
    const Math::Vec3d vec_2 (4.3, 1.2, 5.6);

    auto res = vec_1;
    res += vec_2;
    EXPECT_EQ (vec_1.x + vec_2.x, res.x);
    EXPECT_EQ (vec_1.y + vec_2.y, res.y);
    EXPECT_EQ (vec_1.z + vec_2.z, res.z);
}

TEST (Vector3Test, subtracting_a_vector_from_a_vector_subtracts_element_wise)
{
    const Math::Vec3d vec_1 (2.3, 4.2, 8.7);
    const Math::Vec3d vec_2 (4.3, 1.2, 5.6);

    auto res = vec_1;
    res -= vec_2;
    EXPECT_EQ (vec_1.x - vec_2.x, res.x);
    EXPECT_EQ (vec_1.y - vec_2.y, res.y);
    EXPECT_EQ (vec_1.z - vec_2.z, res.z);
}

TEST (Vector3Test, multiplying_vector_with_scalar_from_right_multiplies_each_element_by_the_scalar)
{
    const Math::Vec3d vector (3.2, 5.4, 1.2);
    auto res = vector * 2.4;
    EXPECT_EQ (vector.x * 2.4, res.x);
    EXPECT_EQ (vector.y * 2.4, res.y);
    EXPECT_EQ (vector.z * 2.4, res.z);
}

TEST (Vector3Test, multiplying_vector_with_scalar_from_left_multiplies_each_element_by_the_scalar)
{
    const Math::Vec3d vector (3.2, 5.4, 1.2);
    auto res = 2.4 * vector;
    EXPECT_EQ (vector.x * 2.4, res.x);
    EXPECT_EQ (vector.y * 2.4, res.y);
    EXPECT_EQ (vector.z * 2.4, res.z);
}

TEST (Vector3Test, dividing_vector_with_scalar_from_right_divides_each_element_by_the_scalar)
{
    const Math::Vec3d vector (3.2, 5.4, 1.2);
    auto res = vector / 2.4;
    EXPECT_EQ (vector.x / 2.4, res.x);
    EXPECT_EQ (vector.y / 2.4, res.y);
    EXPECT_EQ (vector.z / 2.4, res.z);
}

TEST (Vector3Test, multiplying_two_vectors_multiplies_component_wise)
{
    const Math::Vec3d left (3.2, 5.4, 1.2);
    const Math::Vec3d right (3.7, 7.5, 9.2);
    auto res = left * right;

    EXPECT_EQ (left.x * right.x, res.x);
    EXPECT_EQ (left.y * right.y, res.y);
    EXPECT_EQ (left.z * right.z, res.z);
}

TEST (Vector3Test, dividing_a_vector_with_zero_throws_invalid_argument)
{
    const Math::Vec3d vector (3.2, 5.4, 1.2);
    EXPECT_THROW (vector / 0.0, std::invalid_argument);
}

TEST (Vector3Test, cross_product_of_two_vector_follows_mathematical_rules)
{
    const Math::Vec3d vector_1 (3.2, 5.4, 1.2);
    const Math::Vec3d vector_2 (4.3, 2.3, 1.7);
    auto res = vector_1.cross (vector_2);

    EXPECT_EQ (vector_1.y * vector_2.z - vector_1.z * vector_2.y, res.x);
    EXPECT_EQ (vector_1.z * vector_2.x - vector_1.x * vector_2.z, res.y);
    EXPECT_EQ (vector_1.x * vector_2.y - vector_1.y * vector_2.x, res.z);
}

TEST (Vector3Test, dot_product_with_zero_vector_is_zero)
{
    const Math::Vec3d vector (3.2, 5.4, 1.2);
    const Math::Vec3d zero;
    EXPECT_EQ (0.0, vector.dot (zero));
}

TEST (Vector3Test, dot_product_of_two_vectors_add_the_product_of_each_component)
{
    const Math::Vec3d vector_1 (3.2, 5.4, 1.2);
    const Math::Vec3d vector_2 (4.3, 2.3, 1.7);

    auto dotprod = vector_1.dot (vector_2);
    auto vec_prod = vector_1 * vector_2;
    EXPECT_EQ (vec_prod.x + vec_prod.y + vec_prod.z, dotprod);
}

TEST (Vector3Test, multiplying_scalar_to_a_vector_multiplies_each_component_with_the_scalar)
{
    const Math::Vec3d vector (3.2, 5.4, 1.2);
    auto res = vector;
    res *= 2.4;
    EXPECT_EQ (vector.x * 2.4, res.x);
    EXPECT_EQ (vector.y * 2.4, res.y);
    EXPECT_EQ (vector.z * 2.4, res.z);
}

TEST (Vector3Test, dividing_vector_with_a_scalar_divides_each_components_with_the_scalar)
{
    const Math::Vec3d vector (3.2, 5.4, 1.2);
    auto res = vector;
    res /= 4.7;
    EXPECT_EQ (vector.x / 4.7, res.x);
    EXPECT_EQ (vector.y / 4.7, res.y);
    EXPECT_EQ (vector.z / 4.7, res.z);
}

TEST (Vector3Test, multiplying_vector_with_a_vector_multiplies_component_wise)
{
    const Math::Vec3d vector (3.2, 5.4, 1.2);
    const Math::Vec3d other (5.6, 4.2, 7.8);
    auto res = vector;
    res *= other;
    EXPECT_EQ (vector.x * other.x, res.x);
    EXPECT_EQ (vector.y * other.y, res.y);
    EXPECT_EQ (vector.z * other.z, res.z);
}

TEST (Vector3Test, dividing_vector_with_zero_throws_invalid_argument)
{
    Math::Vec3d vector (3.2, 5.4, 1.2);
    EXPECT_THROW (vector /= 0.0, std::invalid_argument);
}

TEST (Vector3Test, equality_operator_returns_true_for_the_same_object)
{
    const Math::Vec3d vector (3.2, 5.4, 1.2);
    EXPECT_EQ (vector, vector);
}

TEST (Vector3Test, equality_operator_returns_true_for_copy)
{
    const Math::Vec3d vector (3.2, 5.4, 1.2);
    auto copy = vector;
    EXPECT_EQ (vector, copy);
}

TEST (Vector3Test, equality_operator_returns_true_for_objects_with_equal_elements)
{
    const Math::Vec3d vector (3.2, 5.4, 1.2);
    const Math::Vec3d other (3.2, 5.4, 1.2);
    EXPECT_EQ (vector, other);
}

TEST (Vector3Test, equality_operator_returns_false_for_object_with_different_x)
{
    const Math::Vec3d vector (3.2, 5.4, 1.2);
    const Math::Vec3d other (5.6, 5.4, 1.2);
    EXPECT_FALSE (vector == other);
}

TEST (Vector3Test, equality_operator_returns_false_for_object_with_different_y)
{
    const Math::Vec3d vector (3.2, 5.4, 1.2);
    const Math::Vec3d other (3.2, 1.4, 1.2);
    EXPECT_FALSE (vector == other);
}

TEST (Vector3Test, equality_operator_returns_false_for_object_with_different_z)
{
    const Math::Vec3d vector (3.2, 5.4, 1.2);
    const Math::Vec3d other (3.2, 5.4, 3.7);
    EXPECT_FALSE (vector == other);
}

TEST (Vector3Test, inequality_operator_returns_false_for_the_same_object)
{
    const Math::Vec3d vector (3.2, 5.4, 1.2);
    EXPECT_FALSE (vector != vector);
}

TEST (Vector3Test, inequality_operator_returns_false_for_copy)
{
    const Math::Vec3d vector (3.2, 5.4, 1.2);
    auto copy = vector;
    EXPECT_FALSE (vector != copy);
}

TEST (Vector3Test, inequality_operator_returns_false)
{
    const Math::Vec3d vector (3.2, 5.4, 1.2);
    const Math::Vec3d other (3.2, 5.4, 1.2);
    EXPECT_FALSE (vector != other);
}

TEST (Vector3Test, inequality_operator_returns_true_for_object_with_different_x)
{
    const Math::Vec3d vector (3.2, 5.4, 1.2);
    const Math::Vec3d other (5.6, 5.4, 1.2);
    EXPECT_NE (vector, other);
}

TEST (Vector3Test, inequality_operator_returns_true_for_object_with_different_y)
{
    const Math::Vec3d vector (3.2, 5.4, 1.2);
    const Math::Vec3d other (3.2, 1.4, 1.2);
    EXPECT_NE (vector, other);
}

TEST (Vector3Test, inequality_operator_returns_true_for_object_with_different_z)
{
    const Math::Vec3d vector (3.2, 5.4, 1.2);
    const Math::Vec3d other (3.2, 5.4, 3.7);
    EXPECT_NE (vector, other);
}

TEST (Vector3Test, vector_can_be_casted_c_style)
{
    const Math::Vec3d vector;
    auto pointer = (const double *) vector;
    EXPECT_EQ (pointer[0], vector.x);
    EXPECT_EQ (pointer[1], vector.y);
    EXPECT_EQ (pointer[2], vector.z);
}

TEST (Vector3Test, vector_can_be_statically_casted)
{
    const Math::Vec3d vector;
    auto pointer = static_cast<const double*> (vector);
    EXPECT_EQ (pointer[0], vector.x);
    EXPECT_EQ (pointer[1], vector.y);
    EXPECT_EQ (pointer[2], vector.z);
}

TEST (Vector3Test, casted_vector_manipulates_the_object)
{
    Math::Vec3d vector;
    auto pointer = static_cast<double*> (vector);
    ++pointer[0];
    EXPECT_EQ (vector.x, pointer[0]);
    EXPECT_EQ (vector.y, pointer[1]);
    EXPECT_EQ (vector.z, pointer[2]);
}

TEST (Vector3Test, othonormal_basis_with_zero_vector_throws_domain_error)
{
    Math::Vec3d vec1 (3.0, 5.0, 7.0);
    Math::Vec3d vec2 (7.0, 9.0, 17.0);
    Math::Vec3d zero (0.0, 0.0, 0.0);

    EXPECT_THROW (Math::generateOrthonormalBasis (zero, vec2, vec1), std::domain_error);
    EXPECT_THROW (Math::generateOrthonormalBasis (vec1, zero, vec2), std::domain_error);
    EXPECT_THROW (Math::generateOrthonormalBasis (vec1, vec2, zero), std::domain_error);
}

TEST (Vector3Test, orthonormal_basis_with_equal_vectors_throws_domain_error)
{
    Math::Vec3d vec1 (3.0, 5.0, 7.0);
    Math::Vec3d vec2 (7.0, 9.0, 17.0);
    EXPECT_THROW (Math::generateOrthonormalBasis (vec1, vec2, vec1), std::domain_error);
    EXPECT_THROW (Math::generateOrthonormalBasis (vec1, vec2, vec2), std::domain_error);
    EXPECT_THROW (Math::generateOrthonormalBasis (vec1, vec1, vec2), std::domain_error);
}

TEST (Vector3Test, orthonormal_basis_gives_vectors_of_length_1)
{
    Math::Vec3d vec1 (3.0, 5.0, 7.0);
    Math::Vec3d vec2 (7.0, 9.0, 17.0);
    Math::Vec3d vec3 (8.4, 2.0, 2.0);

    Math::generateOrthonormalBasis (vec1, vec2, vec3);

    EXPECT_FLOAT_EQ (1, vec1.length ());
    EXPECT_FLOAT_EQ (1, vec2.length ());
    EXPECT_FLOAT_EQ (1, vec3.length ());
}

TEST (Vector3Test, orthonormal_basis_gives_dot_products_of_zero)
{
    Math::Vec3d vec1 (3.0, 5.0, 7.0);
    Math::Vec3d vec2 (7.0, 9.0, 17.0);
    Math::Vec3d vec3 (8.4, 2.0, 2.0);

    Math::generateOrthonormalBasis (vec1, vec2, vec3);
    EXPECT_NEAR (0, vec1.dot (vec2), 1e-8);
    EXPECT_NEAR (0, vec1.dot (vec3), 1e-8);
    EXPECT_NEAR (0, vec2.dot (vec3), 1e-8);
}
