/*
--------------------------------------------------------------------------------
File Name :

Purpose :

Creation Date : 2011-02-15

Last Modified : Tue 15 Feb 2011 12:20:27 PM CET

Created By :  Martin Ertsaas (martiert@student.matnat.uio.no)
--------------------------------------------------------------------------------
*/

#include "Matrix3_test.h"

using Pandora::Math::Mat3f;
using Pandora::Math::Mat2f;
using Pandora::Math::Vec3f;
using Pandora::Math::Math;

Matrix3_test::Matrix3_test()
{
    float array[9] = {3.4f, 1.2f, 0.1f,
                    2.1f, 4.7f, 9.9f,
                    1.6f, 10.3f, 2.5f};
    Mat2f tmp(3.2f, 1.1f, 6.7f, 8.9f);

    mat2 = Mat3f(Math<float>::PI, Vec3f::e1);
    mat3 = Mat3f(array);
    mat4 = Mat3f(tmp);
}

void Matrix3_test::test_construct()
{
    BOOST_ASSERT( mat1[0] == 1.0f );
    BOOST_ASSERT( mat1[1] == 0.0f );
    BOOST_ASSERT( mat1[2] == 0.0f );
    BOOST_ASSERT( mat1[3] == 0.0f );
    BOOST_ASSERT( mat1[4] == 1.0f );
    BOOST_ASSERT( mat1[5] == 0.0f );
    BOOST_ASSERT( mat1[6] == 0.0f );
    BOOST_ASSERT( mat1[7] == 0.0f );
    BOOST_ASSERT( mat1[8] == 1.0f );

    BOOST_ASSERT( mat2[0] == 1.0f );
    BOOST_ASSERT( mat2[1] == 0.0f );
    BOOST_ASSERT( mat2[2] == 0.0f );
    BOOST_ASSERT( mat2[3] == 0.0f );
    BOOST_ASSERT( mat2[4] == Math<float>::Cos(Math<float>::PI) );
    BOOST_ASSERT( mat2[5] == -Math<float>::Sin(Math<float>::PI) );
    BOOST_ASSERT( mat2[6] == 0.0f );
    BOOST_ASSERT( mat2[7] == Math<float>::Sin(Math<float>::PI) );
    BOOST_ASSERT( mat2[8] == Math<float>::Cos(Math<float>::PI) );
}   

void Matrix3_test::test_equality()
{
}

void Matrix3_test::test_addition()
{
}

void Matrix3_test::test_multiplication()
{
}

void Matrix3_test::test_aritmetic()
{
}
