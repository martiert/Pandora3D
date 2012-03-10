#include <Math/vector2.h>

#include <gtest/gtest.h>

TEST (Vector2Test, construction)
{
    double tmp[] = {2.3, 1.2};

    const Math::Vec2d vector_1;
    EXPECT_EQ (0.0, vector_1.x);
    EXPECT_EQ (0.0, vector_1.y);

    const Math::Vec2d vector_2 (0.1, 2.3);
    EXPECT_EQ (0.1, vector_2.x);
    EXPECT_EQ (2.3, vector_2.y);

    const Math::Vec2d vector_3 (tmp);
    EXPECT_EQ (tmp[0], vector_3.x);
    EXPECT_EQ (tmp[1], vector_3.y);

    auto vector_4 = vector_1;
    EXPECT_EQ (vector_1.x, vector_4.x);
    EXPECT_EQ (vector_1.y, vector_4.y);

    const Math::Vec2d vector_5 = tmp;
    EXPECT_EQ (tmp[0], vector_5.x);
    EXPECT_EQ (tmp[1], vector_5.y);
}

TEST (Vector2Test, index_operator_valid_input)
{
    Math::Vec2d vector_1 (4.3, 2.1);
    const Math::Vec2d vector_2 (2.3, 1.5);

    EXPECT_EQ (4.3, vector_1[0]);
    EXPECT_EQ (2.1, vector_1[1]);

    EXPECT_EQ (2.3, vector_2[0]);
    EXPECT_EQ (1.5, vector_2[1]);

    vector_1[0] = 2.1;
    EXPECT_EQ (2.1, vector_1[0]);
    EXPECT_EQ (2.1, vector_1[1]);
}

TEST (Vector2Test, index_operator_throws_out_of_range_exception_when_out_of_range)
{
    Math::Vec2d vector;
    const Math::Vec2d const_vector;
    double tmp = 2;

    EXPECT_THROW (tmp = vector[2], std::out_of_range);
    EXPECT_THROW (tmp = const_vector[2], std::out_of_range);
}

TEST (Vector2Test, vector_can_be_casted)
{
    Math::Vec2d vector;
    auto pointer = (double *) vector;

    EXPECT_EQ (pointer[0], vector.x);
    EXPECT_EQ (pointer[1], vector.y);

    auto pointer2 = static_cast<double*> (vector);
    EXPECT_EQ (pointer2[0], vector.x);
    EXPECT_EQ (pointer2[1], vector.y);

    auto tmp = pointer2[0];
    ++pointer2[0];
    EXPECT_EQ (pointer2[0], tmp + 1);
    EXPECT_EQ (pointer2[0], pointer[0]);
    EXPECT_EQ (vector.x, pointer2[0]);

    const Math::Vec2d vector2 (3.4, 2.1);
    auto const_ptr = (const double*) vector2;
    EXPECT_EQ (const_ptr[0], vector2.x);
    EXPECT_EQ (const_ptr[1], vector2.y);
}

TEST (Vector2Test, length)
{
    const Math::Vec2d vector_1 (2.3, 1.2);
    const Math::Vec2d vector_2;

    EXPECT_EQ ((vector_1.x * vector_1.x + vector_1.y * vector_1.y), vector_1.lengthSquared ());
    EXPECT_EQ (0.0, vector_2.lengthSquared ());

    EXPECT_EQ (std::sqrt (vector_1.x * vector_1.x + vector_1.y * vector_1.y), vector_1.length ());
    EXPECT_EQ (0.0, vector_2.length ());
}

TEST (Vector2Test, normalize_gives_length_of_1)
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

TEST (Vector2Test, negation)
{
    const Math::Vec2d vec_1 (2.3, 4.2);
    auto vec_2 = -vec_1;

    EXPECT_EQ (-vec_1.x, vec_2.x);
    EXPECT_EQ (-vec_1.y, vec_2.y);
}

TEST (Vector2Test, addition)
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

TEST (Vector2Test, multiplication)
{
    const Math::Vec2d vector_1 (2.3, 1.2);

    auto res = vector_1 * 2.3;
    EXPECT_EQ (vector_1.x * 2.3, res.x);
    EXPECT_EQ (vector_1.y * 2.3, res.y);

    res = vector_1 / 2.3;
    EXPECT_EQ (vector_1.x / 2.3, res.x);
    EXPECT_EQ (vector_1.y / 2.3, res.y);

    res = 2.3 * vector_1;
    EXPECT_EQ (vector_1.x * 2.3, res.x);
    EXPECT_EQ (vector_1.y * 2.3, res.y);

    EXPECT_THROW (vector_1 / 0.0, std::invalid_argument);

    const Math::Vec2d vec1 (2.3, 1.2);
    const Math::Vec2d vec2 (1.4, 4.3);

    res = vec1 * vec2;

    EXPECT_EQ (vec1.x * vec2.x, res.x);
    EXPECT_EQ (vec1.y * vec2.y, res.y);

    auto dot = vec1.dot (vec2);
    EXPECT_EQ ((vec1.x * vec2.x + vec1.y * vec2.y), dot);
}

TEST (Vector2Test, perp_vector_is_only_zero_vec_for_zero_vector)
{
    srand (time (NULL));
    for (int i = 0; i < 20000; ++i) {
        auto val1 = (rand () % 10000) / 10.0;
        auto val2 = (rand () % 10000) / 10.0;
        const Math::Vec2d vec (val1, val2);

        const Math::Vec2d perp = vec.perp ();

        if (vec.x != 0.0 || vec.y != 0.0)
            EXPECT_TRUE (perp.x != 0.0 || perp.y != 0.0);
        else {
            EXPECT_EQ (0.0, perp.x);
            EXPECT_EQ (0.0, perp.y);
        }
    }

    const Math::Vec2d vec (0.0, 0.0);
    auto perp = vec.perp ();

    EXPECT_EQ (0.0, perp.x);
    EXPECT_EQ (0.0, perp.y);
}

TEST (Vector2Test, dot_product_with_perp_vector_is_zero)
{
    srand (time (NULL));
    for (int i = 0; i < 20000; ++i) {
        auto val1 = (rand () % 10000) / 10.0;
        auto val2 = (rand () % 10000) / 10.0;
        const Math::Vec2d vec (val1, val2);

        auto perp = vec.perp ();
        EXPECT_EQ (0.0, vec.dot (perp));
        EXPECT_EQ (0.0, perp.dot (vec));
    }
}

TEST (Vector2Test, addition_to_vector2)
{
    const Math::Vec2d vec1 (2.3, 5.4);
    Math::Vec2d vec2 (9.4, 3.7);

    auto vec3 = vec1 + vec2;
    vec2 += vec1;

    EXPECT_EQ (vec2.x, vec2.x);
    EXPECT_EQ (vec2.y, vec2.y);
}

TEST (Vector2Test, subtraction_from_vector2)
{
    const Math::Vec2d vec1 (2.3, 5.4);
    Math::Vec2d vec2 (9.4, 3.7);

    auto vec3 = vec1 - vec2;
    vec2 -= vec1;

    EXPECT_EQ (vec2.x, vec2.x);
    EXPECT_EQ (vec2.y, vec2.y);
}

TEST (Vector2Test, multiplication_inplace)
{
    Math::Vec2d vec1 (5.4, 2.3);
    const double scalar = 2.4;

    auto vec2 = vec1 * scalar;
    vec1 *= scalar;

    EXPECT_EQ (vec1.x, vec2.x);
    EXPECT_EQ (vec1.y, vec2.y);

    const Math::Vec2d vec3 (4.5, 2.3);
    vec2 = vec1 * vec3;
    vec1 *= vec3;

    EXPECT_EQ (vec1.x, vec2.x);
    EXPECT_EQ (vec1.y, vec2.y);
}

TEST (Vector2Test, division_inplace)
{
    Math::Vec2d vec1 (5.4, 2.3);
    auto scalar = 2.4;

    auto vec2 = vec1 / scalar;
    vec1 /= scalar;

    EXPECT_EQ (vec1.x, vec2.x);
    EXPECT_EQ (vec1.y, vec2.y);
}

TEST (Vector2Test, test_inplace_division_by_zero_throws_invalid_argument)
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

TEST (Vector2Test, comparison_operators)
{
    const Math::Vec2d vec1 (3.4, 1.7);
    const Math::Vec2d vec2 (3.6, 7.8);
    const Math::Vec2d vec3 (3.4, 1.1);
    const Math::Vec2d vec4 (3.4, 8.1);
    const Math::Vec2d vec5 (3.4, 1.7);
    const Math::Vec2d vec6 (1.4, 1.7);

    EXPECT_EQ (vec1, vec5);
    EXPECT_NE (vec1, vec2);
    EXPECT_LE (vec1, vec5);
    EXPECT_LE (vec1, vec2);
    EXPECT_LE (vec1, vec4);
    EXPECT_GE (vec1, vec5);
    EXPECT_GE (vec1, vec6);
    EXPECT_GE (vec1, vec3);
    EXPECT_GT (vec1, vec3);
    EXPECT_GT (vec1, vec6);
    EXPECT_LT (vec1, vec2);
    EXPECT_LT (vec1, vec4);

    EXPECT_FALSE (vec1 == vec2);
    EXPECT_FALSE (vec1 != vec5);
    EXPECT_FALSE (vec1 > vec5);
    EXPECT_FALSE (vec1 >= vec2);
    EXPECT_FALSE (vec1 < vec6);
    EXPECT_FALSE (vec1 <= vec6);
}

TEST (Vector2Test, orthonormal_basis)
{
    Math::Vec2d vec1 (2.0, 1.0);
    Math::Vec2d vec2 (4.0, 7.0);

    EXPECT_NE (vec1.dot (vec2), 0.0);

    Math::generateOrthonormalBasis (vec1, vec2);
    EXPECT_FLOAT_EQ (0.0, vec1.dot (vec2));
    EXPECT_FLOAT_EQ (1.0, vec1.length ());
    EXPECT_FLOAT_EQ (1.0, vec2.length ());

    vec1 = Math::Vec2d (0.0, 0.0);
    EXPECT_THROW (generateOrthonormalBasis (vec1, vec2), std::domain_error);
    EXPECT_THROW (generateOrthonormalBasis (vec2, vec1), std::domain_error);

    auto vec3 = vec2;
    EXPECT_THROW (generateOrthonormalBasis (vec2, vec3), std::domain_error);
}
