#include <Math/vector2.h>

#include <gtest/gtest.h>

TEST (Vector2Test, empty_constructor_gives_zero_vector)
{
    const Math::Vec2d vector;
    EXPECT_EQ (0.0, vector.x);
    EXPECT_EQ (0.0, vector.y);
}

TEST (Vector2Test, constructing_a_vector_with_two_arguments_populates_the_vector_with_those_arguments)
{
    const Math::Vec2d vector (0.1, 2.3);
    EXPECT_EQ (0.1, vector.x);
    EXPECT_EQ (2.3, vector.y);
}

TEST (Vector2Test, constructing_a_vector_with_a_array_of_two_elements_populates_vector_with_the_array)
{
    double tmp[] = {2.3, 1.2};

    const Math::Vec2d vector (tmp);
    EXPECT_EQ (tmp[0], vector.x);
    EXPECT_EQ (tmp[1], vector.y);
}

TEST (Vector2Test, assigning_a_vector_to_an_array_populates_vector_with_given_array)
{
    double tmp[] = {2.3, 1.2};

    const Math::Vec2d vector = tmp;
    EXPECT_EQ (tmp[0], vector.x);
    EXPECT_EQ (tmp[1], vector.y);
}

TEST (Vector2Test, assigning_a_vector_to_another_vector_populates_the_vector)
{
    const Math::Vec2d vector (2.5, 1.2);
    auto copy = vector;
    EXPECT_EQ (vector.x, copy.x);
    EXPECT_EQ (vector.y, copy.y);
}

TEST (Vector2Test, copy_constructor_makes_a_hard_copy)
{
    const Math::Vec2d vector (3.2, 7.6);
    auto copy (vector);
    EXPECT_EQ (vector.x, copy.x);
    EXPECT_EQ (vector.y, copy.y);
    ++copy.x;
    EXPECT_NE (vector.x, copy.x);
}

TEST (Vector2Test, index_operator_maps_to_x_and_y)
{
    Math::Vec2d vector_1 (4.3, 2.1);
    const Math::Vec2d vector_2 (2.3, 1.5);

    EXPECT_EQ (vector_1.x, vector_1[0]);
    EXPECT_EQ (vector_1.y, vector_1[1]);

    EXPECT_EQ (vector_2.x, vector_2[0]);
    EXPECT_EQ (vector_2.y, vector_2[1]);

    vector_1[0] = 2.1;
    EXPECT_EQ (vector_1.x, vector_1[0]);
    EXPECT_EQ (vector_1.y, vector_1[1]);
}

TEST (Vector2Test, index_operator_throws_out_of_range_exception_when_out_of_range)
{
    const Math::Vec2d vector;
    EXPECT_THROW (vector[2], std::out_of_range);
}

TEST (Vector2Test, vector_can_be_casted_to_array_c_style)
{
    Math::Vec2d vector (4.5, 2.1);
    auto pointer = (double *) vector;

    EXPECT_EQ (pointer[0], vector.x);
    EXPECT_EQ (pointer[1], vector.y);
}

TEST (Vector2Test, vector_can_be_static_casted_to_array)
{
    Math::Vec2d vector (4.5, 2.1);
    auto pointer = static_cast<double*> (vector);
    EXPECT_EQ (pointer[0], vector.x);
    EXPECT_EQ (pointer[1], vector.y);
}

TEST (Vector2Test, changing_the_array_we_cast_to_changes_the_vector)
{
    Math::Vec2d vector (4.5, 2.1);
    auto pointer = static_cast<double*> (vector);
    auto tmp = pointer[0];
    ++pointer[0];
    EXPECT_EQ (pointer[0], tmp + 1);
    EXPECT_EQ (vector.x, pointer[0]);
}

TEST (Vector2Test, const_vector_can_be_cast_to_const_ptr)
{
    const Math::Vec2d vector (3.4, 2.1);
    auto const_ptr = (const double*) vector;
    EXPECT_EQ (const_ptr[0], vector.x);
    EXPECT_EQ (const_ptr[1], vector.y);
}

TEST (Vector2Test, zero_vector_gives_zero_length)
{
    const Math::Vec2d vector;
    EXPECT_EQ (0.0, vector.length ());
    EXPECT_EQ (0.0, vector.lengthSquared ());
}

TEST (Vector2Test, length_of_vector_follows_mathematical_rules)
{
    const Math::Vec2d vector (2.3, 1.2);
    EXPECT_EQ ((vector.x * vector.x + vector.y * vector.y), vector.lengthSquared ());
    EXPECT_EQ (std::sqrt (vector.x * vector.x + vector.y * vector.y), vector.length ());
}

TEST (Vector2Test, normalize_non_zero_vector_gives_new_length_of_1)
{
    Math::Vec2d vec_1 (4.0, 3.0);
    vec_1.normalize ();
    EXPECT_EQ (1.0, vec_1.length ());
}

TEST (Vector2Test, normalize_throws_domain_error_for_length_zero)
{
    Math::Vec2d vec;

    EXPECT_THROW (vec.normalize (), std::domain_error);
}

TEST (Vector2Test, vector_negation_negates_each_component)
{
    const Math::Vec2d vec (2.3, 4.2);
    auto neg = -vec;

    EXPECT_EQ (-vec.x, neg.x);
    EXPECT_EQ (-vec.y, neg.y);
}

TEST (Vector2Test, adding_two_vectors_adds_each_component)
{
    const Math::Vec2d vector_1 (2.3, 1.2);
    const Math::Vec2d vector_2 (3.0, 2.9);

    auto res = vector_1 + vector_2;

    EXPECT_EQ (vector_1.x + vector_2.x, res.x);
    EXPECT_EQ (vector_1.y + vector_2.y, res.y);

    res = vector_1 - vector_2;
    EXPECT_EQ (vector_1.x - vector_2.x, res.x);
    EXPECT_EQ (vector_1.y - vector_2.y, res.y);
}

TEST (Vector2Test, multiplying_vector_with_scalar_from_right_multiplies_each_component)
{
    const Math::Vec2d vector (2.3, 1.2);
    auto res = vector * 2.3;
    EXPECT_EQ (vector.x * 2.3, res.x);
    EXPECT_EQ (vector.y * 2.3, res.y);
}

TEST (Vector2Test, dividing_vector_with_scalar_divides_each_component)
{
    const Math::Vec2d vector (2.3, 1.2);
    auto res = vector / 2.3;
    EXPECT_EQ (vector.x / 2.3, res.x);
    EXPECT_EQ (vector.y / 2.3, res.y);
}

TEST (Vector2Test, multiplying_vector_with_scalar_from_left_multiplies_each_component)
{
    const Math::Vec2d vector (2.3, 1.2);
    auto res = 2.3 * vector;
    EXPECT_EQ (vector.x * 2.3, res.x);
    EXPECT_EQ (vector.y * 2.3, res.y);
}

TEST (Vector2Test, dividing_vector_with_zero_throws_invalid_argument)
{
    const Math::Vec2d vector (2.3, 1.2);
    EXPECT_THROW (vector / 0.0, std::invalid_argument);
}

TEST (Vector2Test, multiplying_two_vectors_multiplies_component_wise)
{
    const Math::Vec2d vec1 (2.3, 1.2);
    const Math::Vec2d vec2 (1.4, 4.3);
    auto res = vec1 * vec2;
    EXPECT_EQ (vec1.x * vec2.x, res.x);
    EXPECT_EQ (vec1.y * vec2.y, res.y);
}

TEST (Vector2Test, dot_product_of_two_vectors_gives_the_sum_of_the_vectors_multiplied)
{
    const Math::Vec2d vec1 (2.3, 1.2);
    const Math::Vec2d vec2 (1.4, 4.3);
    auto dot = vec1.dot (vec2);
    auto res = vec1 * vec2;
    EXPECT_EQ (res.x + res.y, dot);
}

TEST (Vector2Test, perp_vector_is_zero_vector_for_zero_vector)
{
    const Math::Vec2d vector;
    auto perp = vector.perp ();

    EXPECT_EQ (0.0, perp.x);
    EXPECT_EQ (0.0, perp.y);
}

TEST (Vector2Test, perpendicular_vector_of_non_zero_vector_is_non_zero)
{
    srand (time (NULL));
    for (int i = 0; i < 20000; ++i) {
        auto val1 = (rand () % 10000) / 10.0 + 1;
        auto val2 = (rand () % 10000) / 10.0 + 1;
        const Math::Vec2d vec (val1, val2);

        const Math::Vec2d perp = vec.perp ();

        EXPECT_TRUE (perp.x != 0.0 || perp.y != 0.0);
    }
}

TEST (Vector2Test, dot_product_with_perp_vector_is_zero)
{
    srand (time (NULL));
    for (int i = 0; i < 20000; ++i) {
        auto val1 = (rand () % 10000) / 10.0 + 1;
        auto val2 = (rand () % 10000) / 10.0 + 1;
        const Math::Vec2d vec (val1, val2);

        auto perp = vec.perp ();
        EXPECT_EQ (0.0, vec.dot (perp));
        EXPECT_EQ (0.0, perp.dot (vec));
    }
}

TEST (Vector2Test, addition_to_vector_gives_same_as_the_vectors_added)
{
    const Math::Vec2d vec1 (2.3, 5.4);
    Math::Vec2d vec2 (9.4, 3.7);

    auto vec3 = vec1 + vec2;
    vec2 += vec1;

    EXPECT_EQ (vec2.x, vec2.x);
    EXPECT_EQ (vec2.y, vec2.y);
}

TEST (Vector2Test, subtraction_from_vector_gives_same_as_vectors_subtracted)
{
    const Math::Vec2d vec1 (2.3, 5.4);
    Math::Vec2d vec2 (9.4, 3.7);

    auto vec3 = vec1 - vec2;
    vec2 -= vec1;

    EXPECT_EQ (vec2.x, vec2.x);
    EXPECT_EQ (vec2.y, vec2.y);
}

TEST (Vector2Test, multiplication_inplace_with_scalar_gives_same_as_vector_times_scalar)
{
    Math::Vec2d vec1 (5.4, 2.3);
    const double scalar = 2.4;

    auto vec2 = vec1 * scalar;
    vec1 *= scalar;

    EXPECT_EQ (vec1.x, vec2.x);
    EXPECT_EQ (vec1.y, vec2.y);
}

TEST (Vector2Test, multiplication_inplace_with_vector_gives_same_as_vector_times_vector)
{
    Math::Vec2d vec1 (5.4, 2.3);
    const Math::Vec2d vec3 (4.5, 2.3);
    auto vec2 = vec1 * vec3;
    vec1 *= vec3;

    EXPECT_EQ (vec1.x, vec2.x);
    EXPECT_EQ (vec1.y, vec2.y);
}

TEST (Vector2Test, division_inplace_with_with_scalar_gives_same_as_vector_divided_by_scalar)
{
    Math::Vec2d vec1 (5.4, 2.3);
    auto scalar = 2.4;

    auto vec2 = vec1 / scalar;
    vec1 /= scalar;

    EXPECT_EQ (vec1.x, vec2.x);
    EXPECT_EQ (vec1.y, vec2.y);
}

TEST (Vector2Test, inplace_division_by_zero_throws_invalid_argument)
{
    Math::Vec2d vec (2.3, 1.2);

    EXPECT_THROW (vec /= 0.0, std::invalid_argument);
}

TEST (Vector2Test, inplace_arithmetic_returns_ref_to_self)
{
    Math::Vec2d vec1 (2.3, 5.4);
    Math::Vec2d vec2 (3.4, 8.7);
    auto tmp = 5.4;

    Math::Vec2d *res;

    res = &(vec1 += vec2);
    EXPECT_EQ (&vec1, res);

    res = &(vec2 -= vec1);
    EXPECT_EQ (&vec2, res);

    res = &(vec1 *= vec2);
    EXPECT_EQ (&vec1, res);

    res = &(vec2 *= tmp);
    EXPECT_EQ (&vec2, res);

    res = &(vec1 /= tmp);
    EXPECT_EQ (&vec1, res);
}

TEST (Vector2Test, equality_operator_gives_true_for_same_vector)
{
    const Math::Vec2d vector (3.2, 1.8);
    EXPECT_EQ (vector, vector);
}

TEST (Vector2Test, equality_operator_gives_true_for_copied_vector)
{
    const Math::Vec2d vector (3.2, 1.8);
    auto copy = vector;
    EXPECT_EQ (copy, vector);
}

TEST (Vector2Test, equality_operator_gives_true_for_vectors_with_equal_components)
{
    const Math::Vec2d vector (3.2, 1.8);
    const Math::Vec2d same (3.2, 1.8);
    EXPECT_EQ (vector, same);
}

TEST (Vector2Test, equality_operator_gives_false_for_unequal_x)
{
    const Math::Vec2d vector (3.2, 1.8);
    const Math::Vec2d different (3.0, 1.8);
    EXPECT_FALSE (vector == different);
}

TEST (Vector2Test, equality_operator_gives_false_for_unequal_y)
{
    const Math::Vec2d vector (3.2, 1.8);
    const Math::Vec2d different (3.2, 2.8);
    EXPECT_FALSE (vector == different);
}

TEST (Vector2Test, non_equal_operator_gives_true_for_unequal_x)
{
    const Math::Vec2d vector (3.2, 1.8);
    const Math::Vec2d different (3.0, 1.8);
    EXPECT_NE (vector, different);
}

TEST (Vector2Test, non_equal_operator_gives_true_for_unequal_y)
{
    const Math::Vec2d vector (3.2, 1.8);
    const Math::Vec2d different (3.2, 2.8);
    EXPECT_NE (vector, different);
}

TEST (Vector2Test, non_equal_operator_gives_false_for_same_vector)
{
    const Math::Vec2d vector (3.2, 1.8);
    EXPECT_FALSE (vector != vector);
}

TEST (Vector2Test, non_equal_operator_gives_false_for_copy)
{
    const Math::Vec2d vector (3.2, 1.8);
    auto copy = vector;
    EXPECT_FALSE (copy != vector);
}

TEST (Vector2Test, non_equal_operator_gives_false_for_vectors_with_equal_components)
{
    const Math::Vec2d vector (3.2, 1.8);
    const Math::Vec2d same (3.2, 1.8);
    EXPECT_FALSE (vector != same);
}

TEST (Vector2Test, orhtonormal_basis_with_zero_vector_throws_domain_error)
{
    Math::Vec2d zero;
    Math::Vec2d vector (4.0, 7.0);
    EXPECT_THROW (generateOrthonormalBasis (zero, vector), std::domain_error);
    EXPECT_THROW (generateOrthonormalBasis (vector, zero), std::domain_error);
}

TEST (Vector2Test, orthonormal_basis_with_equal_vectors_throws_domain_error)
{
    Math::Vec2d vector (4.0, 7.0);
    auto copy = vector;
    EXPECT_THROW (generateOrthonormalBasis (vector, copy), std::domain_error);
}

TEST (Vector2Test, orthonormal_basis_creates_perpendicular_vectors_of_length_1)
{
    Math::Vec2d vec1 (2.0, 1.0);
    Math::Vec2d vec2 (4.0, 7.0);

    Math::generateOrthonormalBasis (vec1, vec2);
    EXPECT_FLOAT_EQ (0.0, vec1.dot (vec2));
    EXPECT_FLOAT_EQ (1.0, vec1.length ());
    EXPECT_FLOAT_EQ (1.0, vec2.length ());
}
