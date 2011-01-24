/*
-------------------------------------------------------------------------------
File Name :

Purpose :

Creation Date : 2010-10-14

Last Modified : on. 27. okt. 2010 kl. 20.27 +0200

Created By :  Martin Ertsaas (martiert@student.matnat.uio.no)
-------------------------------------------------------------------------------
*/

#include "Vector2_test.h"

using Pandora::Math::Vec2f;

Vector2_test::Vector2_test()
{
    float tmp[2] = {4.3f, 1.8f};
    vec1 = Vec2f(2.0f, 3.4f);
    vec2 = Vec2f(vec1);
    vec3 = Vec2f(tmp);
}

void Vector2_test::test_construct()
{
    BOOST_CHECK(vec1[0] == 2.0f);
    BOOST_CHECK(vec1[1] == 3.4f);
    BOOST_CHECK(vec2[0] == vec1[0]);
    BOOST_CHECK(vec2[1] == vec1[1]);
    BOOST_CHECK(vec3[0] == 4.3f);
    BOOST_CHECK(vec3[1] == 1.8f);

    vec2[1] += 3;
    BOOST_CHECK(vec2[1] != vec1[1]);
    vec2[1] -= 3;
}

void Vector2_test::test_equality()
{
    BOOST_CHECK(vec1 != vec3);
    BOOST_CHECK(vec1 < vec3);
    BOOST_CHECK(vec1 == vec2);
    BOOST_CHECK(vec3 > vec1);
    BOOST_CHECK(vec1 <= vec3);
    BOOST_CHECK(vec1 <= vec2);
    BOOST_CHECK(vec3 >= vec1);
    BOOST_CHECK(vec1 >= vec2);
}

void Vector2_test::test_addition()
{
    Vec2f tmp = vec1 + vec2;
    BOOST_CHECK(tmp[0] == vec1[0] + vec2[0]);
    BOOST_CHECK(tmp[1] == vec1[1] + vec2[1]);

    vec1 += vec2;
    BOOST_CHECK(vec1[0] == tmp[0]);
    BOOST_CHECK(vec1[1] == tmp[1]);

    tmp = vec1 - vec2;
    BOOST_CHECK(tmp[0] == vec1[0] - vec2[0]);
    BOOST_CHECK(tmp[1] == vec1[1] - vec2[1]);

    vec1 -= vec2;
    BOOST_CHECK(vec1[0] == tmp[0]);
    BOOST_CHECK(vec1[1] == tmp[1]);
}

void Vector2_test::test_multiplication()
{
    float tmp = vec1 * vec2;
    BOOST_CHECK(tmp == (vec1[0]*vec2[0] + vec1[1]*vec2[1]));

    Vec2f tmp_vec = vec1*4.3f;
    BOOST_CHECK(tmp_vec[0] == vec1[0]*4.3f);
    BOOST_CHECK(tmp_vec[1] == vec1[1]*4.3f);

    vec1 *= 4.3;
    BOOST_CHECK(vec1 == tmp_vec);

    tmp_vec = vec1 / 4.3f;
    BOOST_CHECK(tmp_vec[0] == vec1[0] / 4.3f);
    BOOST_CHECK(tmp_vec[1] == vec1[1] / 4.3f);

    vec1 /= 4.3f;
    BOOST_CHECK(vec1 == tmp_vec);

    tmp_vec = -vec1;
    BOOST_CHECK(tmp_vec[0] == -vec1[0]);
    BOOST_CHECK(tmp_vec[1] == -vec1[1]);
}

void Vector2_test::test_aritmetic()
{
    BOOST_CHECK(vec1.length() == Pandora::Math::Math<float>::Sqrt(vec1 * vec1));
    BOOST_CHECK(vec1.lengthSquared() == vec1 * vec1);
    BOOST_CHECK(vec1 * vec1.perp() == 0);

    Vec2f tmp = vec3.perp();
    BOOST_CHECK(vec1.dotPerp(vec3) == vec1.dotprod(tmp));

    tmp = vec1.dotprod(vec3);
    BOOST_CHECK(tmp[0] == vec1[0] * vec3[0]);
    BOOST_CHECK(tmp[1] == vec1[1] * vec3[1]);

    tmp = vec1;
    Vec2f tmp2 = vec3;
    Vec2f::orthonormalize(tmp, tmp2);
    BOOST_CHECK(tmp.length() == 1.0f);
    BOOST_CHECK(tmp2.length() == 1.0f);
    BOOST_CHECK(Pandora::Math::Math<float>::Abs(tmp * tmp2) < Pandora::Math::Math<float>::EPSILON);

    // Check if we can orthonormalize. No reason to do this if the length is
    // already 1.0, so we just say fuck of if it's already normalized.
    BOOST_CHECK(vec1.length() != 1.0f);
    vec1.normalize();
    BOOST_CHECK(vec1.length() == 1.0f);
}
