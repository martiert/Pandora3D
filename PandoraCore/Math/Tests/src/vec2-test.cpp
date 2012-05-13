#include "test-helpers.h"

TEST (Vector2Test, empty_constructor_gives_zero_vector)
{
    const Math::Vec2d vector;
    EXPECT_EQ (0.0, vector.x);
    EXPECT_EQ (0.0, vector.y);
}

TEST (Vector2Test, constructing_a_vector_with_two_arguments_populates_the_vector_with_those_arguments)
{
    BEGIN_MULTITEST

    auto tmp = create_double_array_of_size (2);
    const Math::Vec2d vector (tmp[0], tmp[1]);

    EXPECT_EQ (tmp[0], vector.x);
    EXPECT_EQ (tmp[1], vector.y);

    delete[] tmp;
    END_MULTITEST
}

TEST (Vector2Test, constructing_a_vector_with_a_array_of_two_elements_populates_vector_with_the_array)
{
    BEGIN_MULTITEST

    auto array = create_double_array_of_size (2);
    const Math::Vec2d vector (array);

    EXPECT_EQ (array[0], vector.x);
    EXPECT_EQ (array[1], vector.y);

    delete[] array;
    END_MULTITEST
}

TEST (Vector2Test, assigning_a_vector_to_an_array_populates_vector_with_given_array)
{
    BEGIN_MULTITEST

    auto array = create_double_array_of_size (2);
    const Math::Vec2d vector = array;

    EXPECT_EQ (array[0], vector.x);
    EXPECT_EQ (array[1], vector.y);

    delete[] array;
    END_MULTITEST
}

TEST (Vector2Test, assigning_a_vector_to_another_vector_populates_the_vector)
{
    BEGIN_MULTITEST

    const auto vector = create_random_vector2d ();
    auto copy = vector;

    EXPECT_EQ (vector.x, copy.x);
    EXPECT_EQ (vector.y, copy.y);

    END_MULTITEST
}

TEST (Vector2Test, copy_constructor_makes_a_hard_copy)
{
    BEGIN_MULTITEST

    const auto vector = create_random_vector2d ();
    auto copy (vector);

    EXPECT_EQ (vector.x, copy.x);
    EXPECT_EQ (vector.y, copy.y);
    ++copy.x;
    EXPECT_NE (vector.x, copy.x);

    END_MULTITEST
}

TEST (Vector2Test, index_operator_maps_to_x_and_y)
{
    BEGIN_MULTITEST

    auto vector = create_random_vector2d ();
    const auto const_vector = create_random_vector2d ();

    EXPECT_EQ (vector.x, vector[0]);
    EXPECT_EQ (vector.y, vector[1]);

    vector[0] += 4.2;
    EXPECT_EQ (vector.x, vector[0]);

    EXPECT_EQ (const_vector.x, const_vector[0]);
    EXPECT_EQ (const_vector.y, const_vector[1]);

    END_MULTITEST
}

TEST (Vector2Test, index_operator_throws_out_of_range_exception_when_out_of_range)
{
    const Math::Vec2d vector;
    EXPECT_THROW (vector[2], std::out_of_range);
}

TEST (Vector2Test, vector_can_be_casted_to_array_c_style)
{
    auto vector = create_random_vector2d ();
    auto pointer = (double *) vector;

    EXPECT_EQ (pointer[0], vector.x);
    EXPECT_EQ (pointer[1], vector.y);
}

TEST (Vector2Test, vector_can_be_static_casted_to_array)
{
    auto vector = create_random_vector2d ();
    auto pointer = static_cast<double*> (vector);

    EXPECT_EQ (pointer[0], vector.x);
    EXPECT_EQ (pointer[1], vector.y);
}

TEST (Vector2Test, changing_the_array_we_cast_to_changes_the_vector)
{
    auto vector = create_random_vector2d ();
    auto pointer = static_cast<double*> (vector);
    auto tmp = pointer[0];

    ++pointer[0];
    EXPECT_EQ (pointer[0], tmp + 1);
    EXPECT_EQ (vector.x, pointer[0]);
}

TEST (Vector2Test, const_vector_can_be_cast_to_const_ptr)
{
    const auto vector = create_random_vector2d ();
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
    BEGIN_MULTITEST

    const auto vector = create_random_vector2d ();
    EXPECT_EQ ((vector.x * vector.x + vector.y * vector.y), vector.lengthSquared ());
    EXPECT_EQ (std::sqrt (vector.x * vector.x + vector.y * vector.y), vector.length ());

    END_MULTITEST
}

TEST (Vector2Test, normalize_non_zero_vector_gives_new_length_of_1)
{
    BEGIN_MULTITEST 

    auto vec_1 = create_random_vector2d ();
    vec_1.normalize ();
    EXPECT_FLOAT_EQ (1.0, vec_1.length ());

    END_MULTITEST
}

TEST (Vector2Test, normalize_throws_domain_error_for_length_zero)
{
    Math::Vec2d vec;

    EXPECT_THROW (vec.normalize (), std::domain_error);
}

TEST (Vector2Test, vector_negation_negates_each_component)
{
    BEGIN_MULTITEST

    const auto vec = create_random_vector2d ();
    auto neg = -vec;

    EXPECT_EQ (-vec.x, neg.x);
    EXPECT_EQ (-vec.y, neg.y);

    END_MULTITEST
}

TEST (Vector2Test, adding_two_vectors_adds_each_component)
{
    BEGIN_MULTITEST

    const auto vector_1 = create_random_vector2d ();
    const auto vector_2 = create_random_vector2d ();
    auto res = vector_1 + vector_2;

    EXPECT_EQ (vector_1.x + vector_2.x, res.x);
    EXPECT_EQ (vector_1.y + vector_2.y, res.y);

    END_MULTITEST
}

TEST (Vector2Test, subtracting_two_vectors_subtracts_each_component)
{
    BEGIN_MULTITEST

    const auto vector_1 = create_random_vector2d ();
    const auto vector_2 = create_random_vector2d ();
    auto res = vector_1 - vector_2;

    EXPECT_EQ (vector_1.x - vector_2.x, res.x);
    EXPECT_EQ (vector_1.y - vector_2.y, res.y);

    END_MULTITEST
}

TEST (Vector2Test, multiplying_vector_with_scalar_from_right_multiplies_each_component)
{
    BEGIN_MULTITEST

    const auto vector = create_random_vector2d ();
    auto res = vector * 2.3;

    EXPECT_EQ (vector.x * 2.3, res.x);
    EXPECT_EQ (vector.y * 2.3, res.y);

    END_MULTITEST
}

TEST (Vector2Test, dividing_vector_with_scalar_divides_each_component)
{
    BEGIN_MULTITEST

    const auto vector = create_random_vector2d ();
    double scalar = rand () / 100.0;
    auto res = vector / scalar;

    EXPECT_EQ (vector.x / scalar, res.x);
    EXPECT_EQ (vector.y / scalar, res.y);

    END_MULTITEST
}

TEST (Vector2Test, multiplying_vector_with_scalar_from_left_multiplies_each_component)
{
    BEGIN_MULTITEST

    const auto vector = create_random_vector2d ();
    auto scalar = rand () / 100.0;
    auto res = scalar * vector;

    EXPECT_EQ (vector.x * scalar, res.x);
    EXPECT_EQ (vector.y * scalar, res.y);

    END_MULTITEST
}

TEST (Vector2Test, dividing_vector_with_zero_throws_invalid_argument)
{
    const auto vector = create_random_vector2d ();
    EXPECT_THROW (vector / 0.0, std::invalid_argument);
}

TEST (Vector2Test, multiplying_two_vectors_multiplies_component_wise)
{
    BEGIN_MULTITEST

    const auto vec1 = create_random_vector2d ();
    const auto vec2 = create_random_vector2d ();
    auto res = vec1 * vec2;

    EXPECT_EQ (vec1.x * vec2.x, res.x);
    EXPECT_EQ (vec1.y * vec2.y, res.y);

    END_MULTITEST
}

TEST (Vector2Test, dot_product_of_two_vectors_gives_the_sum_of_the_vectors_multiplied)
{
    BEGIN_MULTITEST

    const auto vec1 = create_random_vector2d ();
    const auto vec2 = create_random_vector2d ();

    auto dot = vec1.dot (vec2);
    auto mult = vec1 * vec2;
    EXPECT_EQ (mult.x + mult.y, dot);

    END_MULTITEST
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
    BEGIN_MULTITEST

    const auto vector = create_random_vector2d ();
    auto perp = vector.perp ();

    EXPECT_TRUE (perp.x != 0.0 || perp.y != 0.0);

    END_MULTITEST
}

TEST (Vector2Test, dot_product_with_perp_vector_is_zero)
{
    BEGIN_MULTITEST

    const auto vector = create_random_vector2d ();
    auto perp = vector.perp ();

    EXPECT_EQ (0.0, vector.dot (perp));
    EXPECT_EQ (0.0, perp.dot (vector));

    END_MULTITEST
}

TEST (Vector2Test, addition_to_vector_gives_same_as_the_vectors_added)
{
    BEGIN_MULTITEST

    const auto vec1 = create_random_vector2d ();
    auto vec2 = create_random_vector2d ();

    auto vec3 = vec1 + vec2;
    vec2 += vec1;

    EXPECT_EQ (vec2.x, vec2.x);
    EXPECT_EQ (vec2.y, vec2.y);

    END_MULTITEST
}

TEST (Vector2Test, subtraction_from_vector_gives_same_as_vectors_subtracted)
{
    BEGIN_MULTITEST

    const auto vec1 = create_random_vector2d ();
    auto vec2 = create_random_vector2d ();

    auto vec3 = vec1 - vec2;
    vec2 -= vec1;

    EXPECT_EQ (vec2.x, vec2.x);
    EXPECT_EQ (vec2.y, vec2.y);

    END_MULTITEST
}

TEST (Vector2Test, multiplication_inplace_with_scalar_gives_same_as_vector_times_scalar)
{
    BEGIN_MULTITEST

    auto vec1 = create_random_vector2d ();
    auto scalar = rand () / 100.0;

    auto vec2 = vec1 * scalar;
    vec1 *= scalar;

    EXPECT_EQ (vec1.x, vec2.x);
    EXPECT_EQ (vec1.y, vec2.y);

    END_MULTITEST
}

TEST (Vector2Test, multiplication_inplace_with_vector_gives_same_as_vector_times_vector)
{
    BEGIN_MULTITEST

    const auto vec1 = create_random_vector2d ();
    auto vec2 = create_random_vector2d ();

    auto vec3 = vec1 * vec2;
    vec2 *= vec1;

    EXPECT_EQ (vec3.x, vec2.x);
    EXPECT_EQ (vec3.y, vec2.y);

    END_MULTITEST
}

TEST (Vector2Test, division_inplace_with_with_scalar_gives_same_as_vector_divided_by_scalar)
{
    BEGIN_MULTITEST

    auto vec1 = create_random_vector2d ();
    auto scalar = rand () / 100.0;

    auto vec2 = vec1 / scalar;
    vec1 /= scalar;

    EXPECT_EQ (vec1.x, vec2.x);
    EXPECT_EQ (vec1.y, vec2.y);

    END_MULTITEST
}

TEST (Vector2Test, inplace_division_by_zero_throws_invalid_argument)
{
    auto vec = create_random_vector2d ();

    EXPECT_THROW (vec /= 0.0, std::invalid_argument);
}

TEST (Vector2Test, inplace_arithmetic_returns_ref_to_self)
{
    BEGIN_MULTITEST

    auto vec1 = create_random_vector2d ();
    auto vec2 = create_random_vector2d ();
    auto tmp = rand () / 100.0;

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

    END_MULTITEST
}

TEST (Vector2Test, equality_operator_gives_true_for_same_vector)
{
    BEGIN_MULTITEST

    const auto vector = create_random_vector2d ();
    EXPECT_EQ (vector, vector);

    END_MULTITEST
}

TEST (Vector2Test, equality_operator_gives_true_for_copied_vector)
{
    BEGIN_MULTITEST

    const auto vector = create_random_vector2d ();
    auto copy = vector;

    EXPECT_EQ (copy, vector);

    END_MULTITEST
}

TEST (Vector2Test, equality_operator_gives_true_for_vectors_with_equal_components)
{
    BEGIN_MULTITEST

    auto array = create_double_array_of_size (2);
    const Math::Vec2d vector (array);
    const Math::Vec2d same (array);

    EXPECT_EQ (vector, same);

    delete[] array;
    END_MULTITEST
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
    BEGIN_MULTITEST

    const auto vector = create_random_vector2d ();
    EXPECT_FALSE (vector != vector);

    END_MULTITEST
}

TEST (Vector2Test, non_equal_operator_gives_false_for_copy)
{
    BEGIN_MULTITEST

    const auto vector = create_random_vector2d ();
    auto copy = vector;
    EXPECT_FALSE (copy != vector);

    END_MULTITEST
}

TEST (Vector2Test, non_equal_operator_gives_false_for_vectors_with_equal_components)
{
    BEGIN_MULTITEST

    auto array = create_double_array_of_size (2);
    const Math::Vec2d vector (array);
    const Math::Vec2d same (array);
    EXPECT_FALSE (vector != same);

    delete[] array;
    END_MULTITEST
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
    int i = 0;
    BEGIN_MULTITEST

    auto vec1 = create_random_vector2d ();
    auto vec2 = create_random_vector2d ();

    if (vec1 != vec2) {
        Math::generateOrthonormalBasis (vec1, vec2);
        EXPECT_NEAR (0.0, vec1.dot (vec2), PRECISION);
        EXPECT_NEAR (1.0, vec1.length (), PRECISION);
        EXPECT_NEAR (1.0, vec2.length (), PRECISION);
    }

    END_MULTITEST
}
