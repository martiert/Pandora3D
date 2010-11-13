/*
-------------------------------------------------------------------------------
File Name :

Purpose :

Creation Date : 2010-10-14

Last Modified : lø. 13. nov. 2010 kl. 17.09 +0100

Created By :  Martin Ertsaas (martiert@student.matnat.uio.no)
-------------------------------------------------------------------------------
*/

#include "Vector3_test.h"

using Pandora::Math::Vec3f;

Vector3_test::Vector3_test()
{    
    float tmp[3] = {6.8, 2.1, 9.6};
    vec1 = Vec3f();
    vec2 = Vec3f(4.3, 6.4, 5.4);
    vec3 = Vec3f(vec2);
    vec4 = Vec3f(tmp);
}

void Vector3_test::test_construct()
{
    printf("\tTesting Vec3f constructors\n");
    BOOST_CHECK( vec1[0] == 1.0f );
    BOOST_CHECK( vec1[1] == 0.0f );
    BOOST_CHECK( vec1[2] == 0.0f );
    BOOST_CHECK( vec2[0] == 4.3f );
    BOOST_CHECK( vec2[1] == 6.4f );
    BOOST_CHECK( vec2[2] == 5.4f );
    BOOST_CHECK( vec4[0] == 6.8f );
    BOOST_CHECK( vec4[1] == 2.1f );
    BOOST_CHECK( vec4[2] == 9.6f );
    BOOST_CHECK( vec3[0] == vec2[0] );
    BOOST_CHECK( vec3[1] == vec2[1] );
    BOOST_CHECK( vec3[2] == vec2[2] );
}

void Vector3_test::test_equality()
{
    printf("\tTesting Vec3f equality\n");

    BOOST_CHECK( vec2 == vec3 );
    BOOST_CHECK( vec1 != vec2 );
    BOOST_CHECK( vec1 < vec2 );
    BOOST_CHECK( vec1 <= vec2 );
    BOOST_CHECK( vec2 >= vec3 );
    BOOST_CHECK( vec4 > vec2 );
}

void Vector3_test::test_addition()
{
    printf("\tTesting Vec3f addition\n");
    Vec3f tmp = vec1 + vec2;
    BOOST_CHECK( tmp[0] == vec1[0] + vec2[0] );
    BOOST_CHECK( tmp[1] == vec1[1] + vec2[1] );
    BOOST_CHECK( tmp[2] == vec1[2] + vec2[2] );

    tmp = tmp - vec2;
    BOOST_CHECK( tmp == vec1 );

    tmp += vec2;
    BOOST_CHECK( tmp[0] == vec1[0] + vec2[0] );
    BOOST_CHECK( tmp[1] == vec1[1] + vec2[1] );
    BOOST_CHECK( tmp[2] == vec1[2] + vec2[2] );

    tmp -= vec2;
    BOOST_CHECK( tmp == vec1 );

    tmp = -vec1;
    BOOST_CHECK( tmp[0] == -vec1[0] );
    BOOST_CHECK( tmp[1] == -vec1[1] );
    BOOST_CHECK( tmp[2] == -vec1[2] );
}

void Vector3_test::test_multiplication()
{
    printf("\tTesting Vec3f multiplication\n");

    float tmp_scalar = vec1 * vec2;
    BOOST_CHECK( tmp_scalar == vec1[0]*vec2[0] + vec1[1]*vec2[1] + vec1[2]*vec2[2] );

    Vec3f tmp = vec1 * 2.0f;
    BOOST_CHECK( tmp[0] == vec1[0]*2.0f );
    BOOST_CHECK( tmp[1] == vec1[1]*2.0f );
    BOOST_CHECK( tmp[2] == vec1[2]*2.0f );

    vec1 *= 2.0f;
    BOOST_CHECK( vec1 == tmp );

    tmp = vec1 / 2.0f;
    BOOST_CHECK( tmp[0] == vec1[0]/2.0f );
    BOOST_CHECK( tmp[1] == vec1[1]/2.0f );
    BOOST_CHECK( tmp[2] == vec1[2]/2.0f );

    vec1 /= 2.0f;
    BOOST_CHECK( tmp == vec1 );
}

void Vector3_test::test_aritmetic()
{
    printf("\tTesting Vec3f aritmetic\n");

    BOOST_CHECK( vec1.length() == Pandora::Math::Math<float>::Sqrt(vec1*vec1) );
    BOOST_CHECK( vec1.lengthSquared() == vec1*vec1 );

    BOOST_CHECK( vec2.length() != 1.0 );
    vec2.normalize();
    BOOST_CHECK( Pandora::Math::Math<float>::Abs(vec2.length() - 1.0f) < Pandora::Math::Math<float>::EPSILON );

    Vec3f tmp = vec1.cross(vec2);
    BOOST_CHECK( tmp[0] == vec1[1]*vec2[2] - vec1[2]*vec2[1] );
    BOOST_CHECK( tmp[1] == vec1[2]*vec2[0] - vec1[0]*vec2[2] );
    BOOST_CHECK( tmp[2] == vec1[0]*vec2[1] - vec1[1]*vec2[0] );

    Vec3f::orthonormalize(vec1, vec2, tmp);
    BOOST_CHECK( vec1*vec2 == 0.0f );
    BOOST_CHECK( vec1*tmp == 0.0f );
    BOOST_CHECK( vec2*tmp == 0.0f );
}
