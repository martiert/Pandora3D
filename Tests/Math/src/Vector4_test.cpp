/*
-------------------------------------------------------------------------------
File Name :

Purpose :

Creation Date : 2010-10-14

Last Modified : sø. 19. des. 2010 kl. 13.40 +0100

Created By :  Martin Ertsaas (martiert@student.matnat.uio.no)
-------------------------------------------------------------------------------
*/

#include "Vector4_test.h"

using Pandora::Math::Vec4f;

Vector4_test::Vector4_test()
{
    float arr[4] = {4.1f, 6.5f, 7.8f, 9.3f};
    vec1 = Vec4f(1.0f, 4.0f, 3.1f, 5.6f);
    vec2 = Vec4f(4.1f, 3.7f, 6.7f, 3.2f);
    vec3 = vec1 * 0.45f;
    vec4 = Vec4f(arr);
}

void Vector4_test::test_construct()
{
    BOOST_ASSERT( vec1[0] == 1.0f );
    BOOST_ASSERT( vec1[1] == 4.0f );
    BOOST_ASSERT( vec1[2] == 3.1f );
    BOOST_ASSERT( vec1[3] == 5.6f );

    Vec4f tmp = Vec4f(vec1);
    BOOST_ASSERT( vec1[0] == tmp[0] );
    BOOST_ASSERT( vec1[1] == tmp[1] );
    BOOST_ASSERT( vec1[2] == tmp[2] );
    BOOST_ASSERT( vec1[3] == tmp[3] );

    tmp = vec4;
    BOOST_ASSERT( vec4[0] == tmp[0] );
    BOOST_ASSERT( vec4[1] == tmp[1] );
    BOOST_ASSERT( vec4[2] == tmp[2] );
    BOOST_ASSERT( vec4[3] == tmp[3] );

    BOOST_ASSERT( vec4[0] == 4.1f );
    BOOST_ASSERT( vec4[1] == 6.5f );
    BOOST_ASSERT( vec4[2] == 7.8f );
    BOOST_ASSERT( vec4[3] == 9.3f );
}

void Vector4_test::test_equality()
{
    Vec4f tmp = vec1;
    BOOST_ASSERT( vec1 == tmp );
    BOOST_ASSERT( vec1 >= vec3 );
    BOOST_ASSERT( vec1 > vec3 );
    BOOST_ASSERT( vec1 <= tmp );
    BOOST_ASSERT( vec2 != vec3 );
    BOOST_ASSERT( vec3 < vec4 );
}

void Vector4_test::test_addition()
{
    Vec4f tmp = vec1 + vec4;
    BOOST_ASSERT( tmp[0] == vec1[0] + vec4[0] );
    BOOST_ASSERT( tmp[1] == vec1[1] + vec4[1] );
    BOOST_ASSERT( tmp[2] == vec1[2] + vec4[2] );
    BOOST_ASSERT( tmp[3] == vec1[3] + vec4[3] );

    tmp = -vec1;
    BOOST_ASSERT( tmp[0] == -vec1[0] );
    BOOST_ASSERT( tmp[1] == -vec1[1] );
    BOOST_ASSERT( tmp[2] == -vec1[2] );
    BOOST_ASSERT( tmp[3] == -vec1[3] );

    tmp = vec4 - vec1;
    BOOST_ASSERT( tmp[0] == vec4[0] - vec1[0] );
    BOOST_ASSERT( tmp[1] == vec4[1] - vec1[1] );
    BOOST_ASSERT( tmp[2] == vec4[2] - vec1[2] );
    BOOST_ASSERT( tmp[3] == vec4[3] - vec1[3] );

    tmp += vec1;
    BOOST_ASSERT( tmp == vec4 );

    tmp -= vec2;
    BOOST_ASSERT( tmp == vec4 - vec2 );
}

void Vector4_test::test_multiplication()
{
    float squared = vec1*vec1;
    BOOST_ASSERT( squared == vec1.lengthSquared() );

    BOOST_ASSERT( vec3[0] == vec1[0]*0.45f );
    BOOST_ASSERT( vec3[1] == vec1[1]*0.45f );
    BOOST_ASSERT( vec3[2] == vec1[2]*0.45f );
    BOOST_ASSERT( vec3[3] == vec1[3]*0.45f );

    Vec4f tmp = vec1 / 0.5f;

    BOOST_ASSERT( tmp[0] == vec1[0] / 0.5f );
    BOOST_ASSERT( tmp[1] == vec1[1] / 0.5f );
    BOOST_ASSERT( tmp[2] == vec1[2] / 0.5f );
    BOOST_ASSERT( tmp[3] == vec1[3] / 0.5f );

    tmp = vec1;
    tmp *= 4.3f;
    BOOST_ASSERT( tmp == vec1*4.3f );

    tmp /= 4.3f;
    BOOST_ASSERT( tmp == vec1 );

    tmp = vec1*0.45f;
    Vec4f tmp2 = 0.45f*vec1;
    BOOST_ASSERT( tmp == tmp2 );
}

void Vector4_test::test_aritmetic()
{
    BOOST_ASSERT( vec1.length() == Pandora::Math::Math<float>::Sqrt(vec1.lengthSquared()) );

    vec2.normalize();
    BOOST_ASSERT( vec2.length() == 1.0f );
}
