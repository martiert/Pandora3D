#include <Math/vector2.h>

#include <gtest/gtest.h>
#include <cmath>

TEST (Vector2Test, construction)
{
    float tmp[] = {2.3f, 1.2f};
    const Math::Vec2f vector_1;
    const Math::Vec2f vector_2 (0.1f, 2.3f);
    const Math::Vec2f vector_3 (tmp);
    const Math::Vec2f vector_4 = vector_1;
    const Math::Vec2f vector_5 = tmp;

    EXPECT_EQ (vector_1.x (), 0.0f);
    EXPECT_EQ (vector_1.y (), 0.0f);

    EXPECT_EQ (vector_2.x (), 0.1f);
    EXPECT_EQ (vector_2.y (), 2.3f);

    EXPECT_EQ (vector_3.x (), tmp[0]);
    EXPECT_EQ (vector_3.y (), tmp[1]);

    EXPECT_EQ (vector_4.x (), vector_1.x ());
    EXPECT_EQ (vector_4.y (), vector_1.y ());

    EXPECT_EQ (vector_5.x (), tmp[0]);
    EXPECT_EQ (vector_5.y (), tmp[1]);
}

TEST (Vector2Test, index_operator_valid_input)
{
    Math::Vec2f vector_1 (4.3f, 2.1f);
    const Math::Vec2f vector_2 (2.3f, 1.5f);

    EXPECT_EQ (vector_1[0], 4.3f);
    EXPECT_EQ (vector_1[1], 2.1f);

    EXPECT_EQ (vector_2[0], 2.3f);
    EXPECT_EQ (vector_2[1], 1.5f);

    vector_1[0] = 2.1f;
    EXPECT_EQ (vector_1[0], 2.1f);
    EXPECT_EQ (vector_1[1], 2.1f);
}

TEST (Vector2Test, index_operator_throws_out_of_range_exception_when_out_of_range)
{
    Math::Vec2f vector;
    const Math::Vec2f const_vector;
    float tmp = 2;

    EXPECT_THROW (tmp = vector[2], std::out_of_range);
    EXPECT_THROW (tmp = const_vector[2], std::out_of_range);

    vector[0] = tmp;
}

TEST (Vector2Test, length)
{
    const Math::Vec2f vector_1 (2.3f, 1.2f);
    const Math::Vec2f vector_2;

    EXPECT_EQ (vector_1.lengthSquared (), (vector_1.x () * vector_1.x () + vector_1.y () * vector_1.y ()));
    EXPECT_EQ (vector_2.lengthSquared (), 0.0f);

    EXPECT_EQ (vector_1.length (), std::sqrt (vector_1.x () * vector_1.x () + vector_1.y () * vector_1.y ()));
    EXPECT_EQ (vector_2.length (), 0.0f);
}

TEST (Vector2Test, normalize_gives_length_of_1)
{
    Math::Vec2f vec_1 (4.0f, 3.0f);
    vec_1.normalize ();
    EXPECT_EQ (vec_1.length (), 1.0f);
}

TEST (Vector2Test, normalize_throws_domain_error_for_length_zero)
{
    Math::Vec2f vec;

    EXPECT_THROW (vec.normalize (), std::domain_error);
}

TEST (Vector2Test, negation)
{
    const Math::Vec2f vec_1 (2.3f, 4.2f);
    const Math::Vec2f vec_2 = -vec_1;

    EXPECT_EQ (vec_2.x (), -vec_1.x ());
    EXPECT_EQ (vec_2.y (), -vec_1.y ());
}

TEST (Vector2Test, addition)
{
    const Math::Vec2f vector_1 (2.3f, 1.2f);
    const Math::Vec2f vector_2 (3.0f, 2.9f);

    Math::Vec2f res = vector_1 + vector_2;

    EXPECT_EQ (res.x (), vector_1.x () + vector_2.x ());
    EXPECT_EQ (res.y (), vector_1.y () + vector_2.y ());

    res = vector_1 - vector_2;
    EXPECT_EQ (res.x (), vector_1.x () - vector_2.x ());
    EXPECT_EQ (res.y (), vector_1.y () - vector_2.y ());
}

TEST (Vector2Test, multiplication)
{
    const Math::Vec2f vector_1 (2.3f, 1.2f);

    Math::Vec2f res = vector_1 * 2.3f;
    EXPECT_EQ (res.x (), vector_1.x () * 2.3f);
    EXPECT_EQ (res.y (), vector_1.y () * 2.3f);

    res = vector_1 / 2.3f;
    EXPECT_EQ (res.x (), vector_1.x () / 2.3f);
    EXPECT_EQ (res.y (), vector_1.y () / 2.3f);

    res = 2.3f * vector_1;
    EXPECT_EQ (res.x (), vector_1.x () * 2.3f);
    EXPECT_EQ (res.y (), vector_1.y () * 2.3f);

    EXPECT_THROW (vector_1 / 0.0f, std::invalid_argument);

    const Math::Vec2f vec1 (2.3f, 1.2f);
    const Math::Vec2f vec2 (1.4f, 4.3f);

    res = vec1 * vec2;

    EXPECT_EQ (res.x (), vec1.x () * vec2.x ());
    EXPECT_EQ (res.y (), vec1.y () * vec2.y ());

    float dot = vec1.dot (vec2);
    EXPECT_EQ (dot, (vec1.x () * vec2.x () + vec1.y () * vec2.y ()));
}

TEST (Vector2Test, perp_vector_is_only_zero_vec_for_zero_vector)
{
    srand (time (NULL));
    for (int i = 0; i < 20000; ++i) {
        float val1 = (rand () % 10000) / 10.0f;
        float val2 = (rand () % 10000) / 10.0f;
        const Math::Vec2f vec (val1, val2);

        const Math::Vec2f perp = vec.perp ();

        if (vec.x () != 0.0f || vec.y () != 0.0f)
            EXPECT_TRUE (perp.x () != 0.0f || perp.y () != 0.0f);
        else {
            EXPECT_EQ (perp.x (), 0.0f);
            EXPECT_EQ (perp.y (), 0.0f);
        }
    }

    const Math::Vec2f vec (0.0f, 0.0f);
    const Math::Vec2f perp = vec.perp ();

    EXPECT_EQ (perp.x (), 0.0f);
    EXPECT_EQ (perp.y (), 0.0f);
}

TEST (Vector2Test, dot_product_with_perp_vector_is_zero)
{
    srand (time (NULL));
    for (int i = 0; i < 20000; ++i) {
        float val1 = (rand () % 10000) / 10.0f;
        float val2 = (rand () % 10000) / 10.0f;
        const Math::Vec2f vec (val1, val2);

        const Math::Vec2f perp = vec.perp ();
        EXPECT_EQ (vec.dot (perp), 0.0f);
        EXPECT_EQ (perp.dot (vec), 0.0f);
    }
}

TEST (Vector2Test, addition_to_vector2)
{
    const Math::Vec2f vec1 (2.3f, 5.4f);
    Math::Vec2f vec2 (9.4f, 3.7f);

    const Math::Vec2f vec3 = vec1 + vec2;
    vec2 += vec1;

    EXPECT_EQ (vec2.x (), vec2.x ());
    EXPECT_EQ (vec2.y (), vec2.y ());
}

TEST (Vector2Test, subtraction_from_vector2)
{
    const Math::Vec2f vec1 (2.3f, 5.4f);
    Math::Vec2f vec2 (9.4f, 3.7f);

    const Math::Vec2f vec3 = vec1 - vec2;
    vec2 -= vec1;

    EXPECT_EQ (vec2.x (), vec2.x ());
    EXPECT_EQ (vec2.y (), vec2.y ());
}

TEST (Vector2Test, multiplication_inplace)
{
    Math::Vec2f vec1 (5.4f, 2.3f);
    const float scalar = 2.4f;

    Math::Vec2f vec2 = vec1 * scalar;
    vec1 *= scalar;

    EXPECT_FLOAT_EQ (vec1.x (), vec2.x ());
    EXPECT_FLOAT_EQ (vec1.y (), vec2.y ());

    const Math::Vec2f vec3 (4.5f, 2.3f);
    vec2 = vec1 * vec3;
    vec1 *= vec3;

    EXPECT_FLOAT_EQ (vec1.x (), vec2.x ());
    EXPECT_FLOAT_EQ (vec1.y (), vec2.y ());
}

TEST (Vector2Test, division_inplace)
{
    Math::Vec2f vec1 (5.4f, 2.3f);
    const float scalar = 2.4f;

    Math::Vec2f vec2 = vec1 / scalar;
    vec1 /= scalar;

    EXPECT_FLOAT_EQ (vec1.x (), vec2.x ());
    EXPECT_FLOAT_EQ (vec1.y (), vec2.y ());
}

TEST (Vector2Test, test_inplace_division_by_zero_throws_invalid_argument)
{
    Math::Vec2f vec (2.3f, 1.2f);

    EXPECT_THROW (vec /= 0.0f, std::invalid_argument);
}

TEST (Vector2Test, inplace_arithmetic_returns_ref_to_self)
{
    Math::Vec2f vec1 (2.3f, 5.4f);
    Math::Vec2f vec2 (3.4f, 8.7f);
    const float tmp = 5.4f;

    Math::Vec2f *res;

    res = &(vec1 += vec2);
    EXPECT_EQ (res, &vec1);

    res = &(vec2 -= vec1);
    EXPECT_EQ (res, &vec2);

    res = &(vec1 *= vec2);
    EXPECT_EQ (res, &vec1);

    res = &(vec2 *= tmp);
    EXPECT_EQ (res, &vec2);

    res = &(vec1 /= tmp);
    EXPECT_EQ (res, &vec1);
}

TEST (Vector2Test, comparison_operators)
{
    const Math::Vec2f vec1 (3.4f, 1.7f);
    const Math::Vec2f vec2 (3.6f, 7.8f);
    const Math::Vec2f vec3 (3.4f, 1.1f);
    const Math::Vec2f vec4 (3.4f, 8.1f);
    const Math::Vec2f vec5 (3.4f, 1.7f);
    const Math::Vec2f vec6 (1.4f, 1.7f);

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
    Math::Vec2f vec1 (2.5f, 1.2f);
    Math::Vec2f vec2 (4.5f, 7.0f);

    EXPECT_NE (vec1.dot (vec2), 0.0f);

    Math::generateOrthonormalBasis (vec1, vec2);
    EXPECT_FLOAT_EQ (vec1.dot (vec2), 0.0f);
    EXPECT_FLOAT_EQ (vec1.length (), 1.0f);
    EXPECT_FLOAT_EQ (vec2.length (), 1.0f);

    vec1 = Math::Vec2f (0.0f, 0.0f);
    EXPECT_THROW (generateOrthonormalBasis (vec1, vec2), std::domain_error);
    EXPECT_THROW (generateOrthonormalBasis (vec2, vec1), std::domain_error);

    Math::Vec2f vec3 = vec2;
    EXPECT_THROW (generateOrthonormalBasis (vec2, vec3), std::domain_error);
}
