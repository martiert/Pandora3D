/*
-------------------------------------------------------------------------------
File Name :

Purpose :

Creation Date : 2010-10-14

Last Modified : ti. 19. okt. 2010 kl. 11.02 +0200

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
}

void Vector2_test::test_equality()
{
    BOOST_CHECK(vec1 != vec3);
    BOOST_CHECK(vec1 < vec3);
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
}

void Vector2_test::test_aritmetic()
{
}
