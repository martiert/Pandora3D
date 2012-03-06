#include <Math/vector3.h>

#include <gtest/gtest.h>

TEST (Vector3Test, construction)
{
    double tmp[] = {2.3, 3.1, 4.7};

    const Math::Vec3d vector_1;
    EXPECT_EQ (0.0, vector_1.x ());
    EXPECT_EQ (0.0, vector_1.y ());
    EXPECT_EQ (0.0, vector_1.z ());

    const Math::Vec3d vector_2 (0.1, 2.3, 3.7);
    EXPECT_EQ (0.1, vector_2.x ());
    EXPECT_EQ (2.3, vector_2.y ());
    EXPECT_EQ (3.7, vector_2.z ());

    const Math::Vec3d vector_3 (tmp);
    EXPECT_EQ (tmp[0], vector_3.x ());
    EXPECT_EQ (tmp[1], vector_3.y ());
    EXPECT_EQ (tmp[2], vector_3.z ());

    auto vector_4 = vector_1;
    EXPECT_EQ (vector_1.x (), vector_4.x ());
    EXPECT_EQ (vector_1.y (), vector_4.y ());
    EXPECT_EQ (vector_1.z (), vector_4.z ());

    const Math::Vec3d vector_5 = tmp;
    EXPECT_EQ (tmp[0], vector_5.x ());
    EXPECT_EQ (tmp[1], vector_5.y ());
    EXPECT_EQ (tmp[2], vector_5.z ());

    const Math::Vec3d vector_6 (vector_1);
    EXPECT_EQ (vector_1.x (), vector_6.x ());
    EXPECT_EQ (vector_1.y (), vector_6.y ());
    EXPECT_EQ (vector_1.x (), vector_6.z ());
}

TEST (Vector3Test, index_operator_valid_input)
{
    Math::Vec3d vector_1 (4.3, 3.1, 4.1);
    const Math::Vec3d vector_3 (3.3, 1.5, 2.6);

    EXPECT_EQ (4.3, vector_1[0]);
    EXPECT_EQ (3.1, vector_1[1]);
    EXPECT_EQ (4.1, vector_1[2]);

    EXPECT_EQ (3.3, vector_3[0]);
    EXPECT_EQ (1.5, vector_3[1]);
    EXPECT_EQ (2.6, vector_3[2]);

    vector_1[0] = 3.1;
    EXPECT_EQ (3.1, vector_1[0]);
    EXPECT_EQ (3.1, vector_1[1]);
    EXPECT_EQ (4.1, vector_1[2]);
}

TEST (Vector3Test, index_operator_throws_out_of_range_exception_when_out_of_range)
{
    Math::Vec3d vector;
    const Math::Vec3d const_vector;
    double tmp = 3;

    EXPECT_THROW (tmp = vector[3], std::out_of_range);
    EXPECT_THROW (tmp = const_vector[3], std::out_of_range);

    vector[0] = tmp;
}

TEST (Vector3Test, length)
{
    const Math::Vec3d vector_1 (2.3, 4.2, 1.2);
    const Math::Vec3d vector_2;

    EXPECT_EQ ((vector_1.x ()*vector_1.x () + vector_1.y ()*vector_1.y () + vector_1.z ()*vector_1.z ()), vector_1.lengthSquared ());
    EXPECT_EQ (0.0, vector_2.lengthSquared ());

    EXPECT_EQ (std::sqrt (vector_1.x ()*vector_1.x () + vector_1.y ()*vector_1.y () + vector_1.z ()*vector_1.z ()), vector_1.length ());
    EXPECT_EQ (0.0, vector_2.lengthSquared ());
}

TEST (Vector3Test, normalize)
{
    Math::Vec3d vec_1 (3.2, 1.2, 4.5);
    Math::Vec3d vec_2;

    EXPECT_NE (1.0, vec_1.length ());
    vec_1.normalize ();
    EXPECT_FLOAT_EQ (1.0, vec_1.length ());

    EXPECT_THROW (vec_2.normalize (), std::domain_error);
}

TEST (Vector3Test, negation)
{
    const Math::Vec3d vec_1 (2.3, 4.2, 8.7);
    auto vec_2 = -vec_1;

    EXPECT_EQ (-vec_2.x (), vec_1.x ());
    EXPECT_EQ (-vec_2.y (), vec_1.y ());
    EXPECT_EQ (-vec_2.z (), vec_1.z ());
}

TEST (Vector3Test, addition)
{
    const Math::Vec3d vec_1 (2.3, 4.2, 8.7);
    const Math::Vec3d vec_2 (4.3, 1.2, 5.6);

    auto vec_3 = vec_1 + vec_2;
    EXPECT_EQ (vec_1.x () + vec_2.x (), vec_3.x ());
    EXPECT_EQ (vec_1.y () + vec_2.y (), vec_3.y ());
    EXPECT_EQ (vec_1.z () + vec_2.z (), vec_3.z ());

    vec_3 = vec_1 - vec_2;
    EXPECT_EQ (vec_1.x () - vec_2.x (), vec_3.x ());
    EXPECT_EQ (vec_1.y () - vec_2.y (), vec_3.y ());
    EXPECT_EQ (vec_1.z () - vec_2.z (), vec_3.z ());

    vec_3 = vec_1;
    vec_3 += vec_2;
    EXPECT_EQ (vec_1.x () + vec_2.x (), vec_3.x ());
    EXPECT_EQ (vec_1.y () + vec_2.y (), vec_3.y ());
    EXPECT_EQ (vec_1.z () + vec_2.z (), vec_3.z ());

    vec_3 = vec_1;
    vec_3 -= vec_2;
    EXPECT_EQ (vec_1.x () - vec_2.x (), vec_3.x ());
    EXPECT_EQ (vec_1.y () - vec_2.y (), vec_3.y ());
    EXPECT_EQ (vec_1.z () - vec_2.z (), vec_3.z ());
}

TEST (Vector3Test, multiplication)
{
    const Math::Vec3d vector_1 (3.2, 5.4, 1.2);

    auto res = vector_1 * 2.4;
    EXPECT_EQ (vector_1.x () * 2.4, res.x ());
    EXPECT_EQ (vector_1.y () * 2.4, res.y ());
    EXPECT_EQ (vector_1.z () * 2.4, res.z ());

    res = 2.4 * vector_1;
    EXPECT_EQ (vector_1.x () * 2.4, res.x ());
    EXPECT_EQ (vector_1.y () * 2.4, res.y ());
    EXPECT_EQ (vector_1.z () * 2.4, res.z ());

    res = vector_1 / 2.4;
    EXPECT_EQ (vector_1.x () / 2.4, res.x ());
    EXPECT_EQ (vector_1.y () / 2.4, res.y ());
    EXPECT_EQ (vector_1.z () / 2.4, res.z ());

    res = 2.3 * vector_1;
    EXPECT_EQ (vector_1.x () * 2.3, res.x ());
    EXPECT_EQ (vector_1.y () * 2.3, res.y ());
    EXPECT_EQ (vector_1.z () * 2.3, res.z ());

    const Math::Vec3d vector_2 (3.7, 7.5, 9.2);
    res = vector_1 * vector_2;

    EXPECT_EQ (vector_1.x () * vector_2.x (), res.x ());
    EXPECT_EQ (vector_1.y () * vector_2.y (), res.y ());
    EXPECT_EQ (vector_1.z () * vector_2.z (), res.z ());

    EXPECT_THROW (vector_1 / 0.0, std::invalid_argument);

    const Math::Vec3d vector_3 (4.3, 2.3, 1.7);
    res = vector_1.cross (vector_3);

    EXPECT_EQ (vector_1.y () * vector_3.z () - vector_1.z () * vector_3.y (), res.x ());
    EXPECT_EQ (vector_1.z () * vector_3.x () - vector_1.x () * vector_3.z (), res.y ());
    EXPECT_EQ (vector_1.x () * vector_3.y () - vector_1.y () * vector_3.x (), res.z ());

    auto vector_4 = vector_1;
    vector_4 *= 2.4;
    EXPECT_EQ (vector_1.x () * 2.4, vector_4.x ());
    EXPECT_EQ (vector_1.y () * 2.4, vector_4.y ());
    EXPECT_EQ (vector_1.z () * 2.4, vector_4.z ());

    vector_4 = vector_3;
    vector_4 /= 4.7;
    EXPECT_EQ (vector_3.x () / 4.7, vector_4.x ());
    EXPECT_EQ (vector_3.y () / 4.7, vector_4.y ());
    EXPECT_EQ (vector_3.z () / 4.7, vector_4.z ());

    vector_4 = vector_1;
    vector_4 *= vector_3;
    EXPECT_EQ (vector_1.x () * vector_3.x (), vector_4.x ());
    EXPECT_EQ (vector_1.y () * vector_3.y (), vector_4.y ());
    EXPECT_EQ (vector_1.z () * vector_3.z (), vector_4.z ());

    EXPECT_THROW (vector_4 /= 0.0, std::invalid_argument);
}

TEST (Vector3Test, comparison_operators)
{
    const Math::Vec3d vec1 (3.4, 1.7, 4.3);
    const Math::Vec3d vec2 (3.6, 7.8, 1.2);
    const Math::Vec3d vec3 (3.4, 1.1, 8.5);
    const Math::Vec3d vec4 (3.4, 8.1, 4.3);
    const Math::Vec3d vec5 (3.4, 1.7, 4.3);
    const Math::Vec3d vec6 (1.4, 1.7, 6.7);
    const Math::Vec3d vec7 (3.4, 1.1, 9.5);
    const Math::Vec3d vec8 (3.4, 1.1, 0.5);

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
    Math::Vec3d vec1 (3.0, 5.0, 7.0);
    Math::Vec3d vec2 (7.0, 9.0, 17.0);
    Math::Vec3d vec3 (8.4, 2.0, 2.0);

    EXPECT_NE (0.0, vec1.dot (vec2));
    EXPECT_NE (0.0, vec1.dot (vec3));
    EXPECT_NE (0.0, vec2.dot (vec3));

    Math::generateOrthonormalBasis (vec1, vec2, vec3);
    EXPECT_NEAR (0, vec1.dot (vec2), 1e-8);
    EXPECT_NEAR (0, vec1.dot (vec3), 1e-8);
    EXPECT_NEAR (0, vec2.dot (vec3), 1e-8);
    EXPECT_FLOAT_EQ (1, vec1.length ());
    EXPECT_FLOAT_EQ (1, vec2.length ());
    EXPECT_FLOAT_EQ (1, vec3.length ());

    Math::Vec3d tmp (0.0, 0.0, 0.0);
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
