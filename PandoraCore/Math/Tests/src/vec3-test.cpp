#include <Math/vector3.h>

#include <gtest/gtest.h>
#include <cmath>

TEST (Vector3Test, construction)
{
    float tmp[] = {2.3f, 3.1f, 4.7f};
    const Math::Vec3f vector_1;
    const Math::Vec3f vector_2 (0.1f, 2.3f, 3.7f);
    const Math::Vec3f vector_3 (tmp);
    const Math::Vec3f vector_4 = vector_1;
    const Math::Vec3f vector_5 = tmp;
    const Math::Vec3f vector_6 (vector_1);

    EXPECT_FLOAT_EQ (0.0f, vector_1.x ());
    EXPECT_FLOAT_EQ (0.0f, vector_1.y ());
    EXPECT_FLOAT_EQ (0.0f, vector_1.z ());

    EXPECT_FLOAT_EQ (0.1f, vector_2.x ());
    EXPECT_FLOAT_EQ (2.3f, vector_2.y ());
    EXPECT_FLOAT_EQ (3.7f, vector_2.z ());

    EXPECT_FLOAT_EQ (tmp[0], vector_3.x ());
    EXPECT_FLOAT_EQ (tmp[1], vector_3.y ());
    EXPECT_FLOAT_EQ (tmp[2], vector_3.z ());

    EXPECT_FLOAT_EQ (vector_1.x (), vector_4.x ());
    EXPECT_FLOAT_EQ (vector_1.y (), vector_4.y ());
    EXPECT_FLOAT_EQ (vector_1.z (), vector_4.z ());

    EXPECT_FLOAT_EQ (tmp[0], vector_5.x ());
    EXPECT_FLOAT_EQ (tmp[1], vector_5.y ());
    EXPECT_FLOAT_EQ (tmp[2], vector_5.z ());

    EXPECT_FLOAT_EQ (vector_1.x (), vector_6.x ());
    EXPECT_FLOAT_EQ (vector_1.y (), vector_6.y ());
    EXPECT_FLOAT_EQ (vector_1.x (), vector_6.z ());
}

TEST (Vector3Test, index_operator_valid_input)
{
    Math::Vec3f vector_1 (4.3f, 3.1f, 4.1f);
    const Math::Vec3f vector_3 (3.3f, 1.5f, 2.6f);

    EXPECT_FLOAT_EQ (4.3f, vector_1[0]);
    EXPECT_FLOAT_EQ (3.1f, vector_1[1]);
    EXPECT_FLOAT_EQ (4.1f, vector_1[2]);

    EXPECT_FLOAT_EQ (3.3f, vector_3[0]);
    EXPECT_FLOAT_EQ (1.5f, vector_3[1]);
    EXPECT_FLOAT_EQ (2.6f, vector_3[2]);

    vector_1[0] = 3.1f;
    EXPECT_FLOAT_EQ (3.1f, vector_1[0]);
    EXPECT_FLOAT_EQ (3.1f, vector_1[1]);
    EXPECT_FLOAT_EQ (4.1f, vector_1[2]);
}

TEST (Vector3Test, index_operator_throws_out_of_range_exception_when_out_of_range)
{
    Math::Vec3f vector;
    const Math::Vec3f const_vector;
    float tmp = 3;

    EXPECT_THROW (tmp = vector[3], std::out_of_range);
    EXPECT_THROW (tmp = const_vector[3], std::out_of_range);

    vector[0] = tmp;
}

TEST (Vector3Test, length)
{
    const Math::Vec3f vector_1 (2.3f, 4.2f, 1.2f);
    const Math::Vec3f vector_2;

    EXPECT_FLOAT_EQ ((vector_1.x ()*vector_1.x () + vector_1.y ()*vector_1.y () + vector_1.z ()*vector_1.z ()), vector_1.lengthSquared ());
    EXPECT_FLOAT_EQ (0.0f, vector_2.lengthSquared ());

    EXPECT_FLOAT_EQ (std::sqrt (vector_1.x ()*vector_1.x () + vector_1.y ()*vector_1.y () + vector_1.z ()*vector_1.z ()), vector_1.length ());
    EXPECT_FLOAT_EQ (0.0f, vector_2.lengthSquared ());
}

TEST (Vector3Test, normalize)
{
    Math::Vec3f vec_1 (3.2f, 1.2f, 4.5f);
    Math::Vec3f vec_2;

    EXPECT_NE (1.0f, vec_1.length ());
    vec_1.normalize ();
    EXPECT_FLOAT_EQ (1.0f, vec_1.length ());

    EXPECT_THROW (vec_2.normalize (), std::domain_error);
}

TEST (Vector3Test, negation)
{
    const Math::Vec3f vec_1 (2.3f, 4.2f, 8.7f);
    const Math::Vec3f vec_2 = -vec_1;

    EXPECT_FLOAT_EQ (-vec_2.x (), vec_1.x ());
    EXPECT_FLOAT_EQ (-vec_2.y (), vec_1.y ());
    EXPECT_FLOAT_EQ (-vec_2.z (), vec_1.z ());
}

TEST (Vector3Test, addition)
{
    const Math::Vec3f vec_1 (2.3f, 4.2f, 8.7f);
    const Math::Vec3f vec_2 (4.3f, 1.2f, 5.6f);

    Math::Vec3f vec_3 = vec_1 + vec_2;
    EXPECT_FLOAT_EQ (vec_1.x () + vec_2.x (), vec_3.x ());
    EXPECT_FLOAT_EQ (vec_1.y () + vec_2.y (), vec_3.y ());
    EXPECT_FLOAT_EQ (vec_1.z () + vec_2.z (), vec_3.z ());

    vec_3 = vec_1 - vec_2;
    EXPECT_FLOAT_EQ (vec_1.x () - vec_2.x (), vec_3.x ());
    EXPECT_FLOAT_EQ (vec_1.y () - vec_2.y (), vec_3.y ());
    EXPECT_FLOAT_EQ (vec_1.z () - vec_2.z (), vec_3.z ());

    vec_3 = vec_1;
    vec_3 += vec_2;
    EXPECT_FLOAT_EQ (vec_1.x () + vec_2.x (), vec_3.x ());
    EXPECT_FLOAT_EQ (vec_1.y () + vec_2.y (), vec_3.y ());
    EXPECT_FLOAT_EQ (vec_1.z () + vec_2.z (), vec_3.z ());

    vec_3 = vec_1;
    vec_3 -= vec_2;
    EXPECT_FLOAT_EQ (vec_1.x () - vec_2.x (), vec_3.x ());
    EXPECT_FLOAT_EQ (vec_1.y () - vec_2.y (), vec_3.y ());
    EXPECT_FLOAT_EQ (vec_1.z () - vec_2.z (), vec_3.z ());
}

TEST (Vector3Test, multiplication)
{
    const Math::Vec3f vector_1 (3.2f, 5.4f, 1.2f);

    Math::Vec3f res = vector_1 * 2.4f;
    EXPECT_FLOAT_EQ (vector_1.x () * 2.4f, res.x ());
    EXPECT_FLOAT_EQ (vector_1.y () * 2.4f, res.y ());
    EXPECT_FLOAT_EQ (vector_1.z () * 2.4f, res.z ());

    res = vector_1 / 2.4f;
    EXPECT_FLOAT_EQ (vector_1.x () / 2.4f, res.x ());
    EXPECT_FLOAT_EQ (vector_1.y () / 2.4f, res.y ());
    EXPECT_FLOAT_EQ (vector_1.z () / 2.4f, res.z ());

    res = 2.3f * vector_1;
    EXPECT_FLOAT_EQ (vector_1.x () * 2.3f, res.x ());
    EXPECT_FLOAT_EQ (vector_1.y () * 2.3f, res.y ());
    EXPECT_FLOAT_EQ (vector_1.z () * 2.3f, res.z ());

    const Math::Vec3f vector_2 (3.7f, 7.5f, 9.2f);
    res = vector_1 * vector_2;

    EXPECT_FLOAT_EQ (vector_1.x () * vector_2.x (), res.x ());
    EXPECT_FLOAT_EQ (vector_1.y () * vector_2.y (), res.y ());
    EXPECT_FLOAT_EQ (vector_1.z () * vector_2.z (), res.z ());

    EXPECT_THROW (vector_1 / 0.0f, std::invalid_argument);

    const Math::Vec3f vector_3 (4.3f, 2.3f, 1.7f);
    res = vector_1.cross (vector_3);

    EXPECT_FLOAT_EQ (vector_1.y () * vector_3.z () - vector_1.z () * vector_3.y (), res.x ());
    EXPECT_FLOAT_EQ (vector_1.z () * vector_3.x () - vector_1.x () * vector_3.z (), res.y ());
    EXPECT_FLOAT_EQ (vector_1.x () * vector_3.y () - vector_1.y () * vector_3.x (), res.z ());

    Math::Vec3f vector_4 = vector_1;
    vector_4 *= 2.4f;
    EXPECT_FLOAT_EQ (vector_1.x () * 2.4f, vector_4.x ());
    EXPECT_FLOAT_EQ (vector_1.y () * 2.4f, vector_4.y ());
    EXPECT_FLOAT_EQ (vector_1.z () * 2.4f, vector_4.z ());

    vector_4 = vector_3;
    vector_4 /= 4.7f;
    EXPECT_FLOAT_EQ (vector_3.x () / 4.7f, vector_4.x ());
    EXPECT_FLOAT_EQ (vector_3.y () / 4.7f, vector_4.y ());
    EXPECT_FLOAT_EQ (vector_3.z () / 4.7f, vector_4.z ());

    vector_4 = vector_1;
    vector_4 *= vector_3;
    EXPECT_FLOAT_EQ (vector_1.x () * vector_3.x (), vector_4.x ());
    EXPECT_FLOAT_EQ (vector_1.y () * vector_3.y (), vector_4.y ());
    EXPECT_FLOAT_EQ (vector_1.z () * vector_3.z (), vector_4.z ());

    EXPECT_THROW (vector_4 /= 0.0f, std::invalid_argument);
}

TEST (Vector3Test, comparison_operators)
{
    const Math::Vec3f vec1 (3.4f, 1.7f, 4.3f);
    const Math::Vec3f vec2 (3.6f, 7.8f, 1.2f);
    const Math::Vec3f vec3 (3.4f, 1.1f, 8.5f);
    const Math::Vec3f vec4 (3.4f, 8.1f, 4.3f);
    const Math::Vec3f vec5 (3.4f, 1.7f, 4.3f);
    const Math::Vec3f vec6 (1.4f, 1.7f, 6.7f);
    const Math::Vec3f vec7 (3.4f, 1.1f, 9.5f);
    const Math::Vec3f vec8 (3.4f, 1.1f, 0.5f);

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
    EXPECT_LT (vec3, vec7);
    EXPECT_LE (vec3, vec7);
    EXPECT_GE (vec3, vec8);

    EXPECT_FALSE (vec1 == vec2);
    EXPECT_FALSE (vec1 != vec5);
    EXPECT_FALSE (vec1 > vec5);
    EXPECT_FALSE (vec1 >= vec2);
    EXPECT_FALSE (vec1 < vec6);
    EXPECT_FALSE (vec1 <= vec6);
}

TEST (Vector3Test, orthonormal_basis)
{
    Math::Vec3f vec1 (3.0f, 5.0f, 7.0f);
    Math::Vec3f vec2 (7.0f, 9.0f, 17.0f);
    Math::Vec3f vec3 (8.4f, 2.0f, 2.0f);

    EXPECT_NE (0.0, vec1.dot (vec2));
    EXPECT_NE (0.0, vec1.dot (vec3));
    EXPECT_NE (0.0, vec2.dot (vec3));

    Math::generateOrthonormalBasis (vec1, vec2, vec3);
    EXPECT_NEAR (0, vec1.dot (vec2), 1e-6);
    EXPECT_NEAR (0, vec1.dot (vec3), 1e-6);
    EXPECT_NEAR (0, vec2.dot (vec3), 1e-6);
    EXPECT_FLOAT_EQ (1, vec1.length ());
    EXPECT_FLOAT_EQ (1, vec2.length ());
    EXPECT_FLOAT_EQ (1, vec3.length ());

    Math::Vec3f tmp (0.0f, 0.0f, 0.0f);
    EXPECT_THROW (Math::generateOrthonormalBasis (tmp, vec2, vec3), std::domain_error);
    EXPECT_THROW (Math::generateOrthonormalBasis (vec1, tmp, vec3), std::domain_error);
    EXPECT_THROW (Math::generateOrthonormalBasis (vec1, vec2, tmp), std::domain_error);

    tmp = vec2;
    EXPECT_THROW (Math::generateOrthonormalBasis (tmp, vec2, vec3), std::domain_error);
    tmp = vec1;
    EXPECT_THROW (Math::generateOrthonormalBasis (vec1, tmp, vec3), std::domain_error);
    tmp = vec3;
    EXPECT_THROW (Math::generateOrthonormalBasis (tmp, vec2, vec3), std::domain_error);
}
