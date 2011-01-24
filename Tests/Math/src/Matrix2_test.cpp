/*
-------------------------------------------------------------------------------
File Name :

Purpose :

Creation Date : 2010-10-14

Last Modified : lø. 25. des. 2010 kl. 12.58 +0100

Created By :  Martin Ertsaas (martiert@student.matnat.uio.no)
-------------------------------------------------------------------------------
*/

#include "Matrix2_test.h"

using Pandora::Math::Mat2f;
using Pandora::Math::Vec2f;
using Pandora::Math::Math;

Matrix2_test::Matrix2_test()
{
    float arr[4] = {4.0f, 6.5f, 8.0f, 9.5f};
    mat1 = Mat2f(arr);
    mat2 = Mat2f(4.0f, 2.1f, 3.7f, 8.4f);
    mat3 = Mat2f(mat1);
}

void Matrix2_test::test_construct()
{
    BOOST_ASSERT( mat1[0] == 4.0f );
    BOOST_ASSERT( mat1[1] == 6.5f );
    BOOST_ASSERT( mat1[2] == 8.0f );
    BOOST_ASSERT( mat1[3] == 9.5f );

    BOOST_ASSERT( mat2[0] == 4.0f );
    BOOST_ASSERT( mat2[1] == 2.1f );
    BOOST_ASSERT( mat2[2] == 3.7f );
    BOOST_ASSERT( mat2[3] == 8.4f );

    BOOST_ASSERT( mat1 == mat3 );
}

void Matrix2_test::test_equality()
{
    BOOST_ASSERT( mat1 == mat3 );
    BOOST_ASSERT( mat1 > mat2 );
    BOOST_ASSERT( mat2 != mat3 );
    BOOST_ASSERT( mat2 < mat1 );
    BOOST_ASSERT( mat1 <= mat3 );
    BOOST_ASSERT( mat1 >= mat2 );
    BOOST_ASSERT( mat2 <= mat1 );
    BOOST_ASSERT( mat1 >= mat3 );
}

void Matrix2_test::test_addition()
{
    Mat2f tmp = -mat1;
    BOOST_ASSERT( tmp[0] == -mat1[0] );
    BOOST_ASSERT( tmp[1] == -mat1[1] );
    BOOST_ASSERT( tmp[2] == -mat1[2] );
    BOOST_ASSERT( tmp[3] == -mat1[3] );

    tmp = mat3 - mat1;
    BOOST_ASSERT( tmp[0] == mat3[0] - mat1[0] );
    BOOST_ASSERT( tmp[1] == mat3[1] - mat1[1] );
    BOOST_ASSERT( tmp[2] == mat3[2] - mat1[2] );
    BOOST_ASSERT( tmp[3] == mat3[3] - mat1[3] );

    tmp = mat3 + mat1;
    BOOST_ASSERT( tmp[0] == mat3[0] + mat1[0] );
    BOOST_ASSERT( tmp[1] == mat3[1] + mat1[1] );
    BOOST_ASSERT( tmp[2] == mat3[2] + mat1[2] );
    BOOST_ASSERT( tmp[3] == mat3[3] + mat1[3] );

    mat1 += mat3;
    BOOST_ASSERT( tmp == mat1 );
    mat1 -= mat3;
    BOOST_ASSERT( mat1 == tmp - mat3 );
}

void Matrix2_test::test_multiplication()
{
    Mat2f tmp = mat1*mat3;
    BOOST_ASSERT( tmp[0] == mat1[0]*mat3[0] + mat1[1]*mat3[2] );
    BOOST_ASSERT( tmp[1] == mat1[0]*mat3[1] + mat1[1]*mat3[3] );
    BOOST_ASSERT( tmp[2] == mat1[2]*mat3[0] + mat1[3]*mat3[2] );
    BOOST_ASSERT( tmp[3] == mat1[2]*mat3[1] + mat1[3]*mat3[3] );

    tmp = mat3*4.5f;
    BOOST_ASSERT( tmp[0] == mat3[0]*4.5f );
    BOOST_ASSERT( tmp[1] == mat3[1]*4.5f );
    BOOST_ASSERT( tmp[2] == mat3[2]*4.5f );
    BOOST_ASSERT( tmp[3] == mat3[3]*4.5f );

    Vec2f vectmp(2.4f, 3.7f);
    Vec2f tmp2 = mat2*vectmp;
    BOOST_ASSERT( tmp2[0] == mat2[0]*vectmp[0] + mat2[1]*vectmp[1] );
    BOOST_ASSERT( tmp2[1] == mat2[2]*vectmp[0] + mat2[3]*vectmp[1] );

    tmp = mat2/0.5f;
    BOOST_ASSERT( tmp[0] == mat2[0]/0.5f );
    BOOST_ASSERT( tmp[1] == mat2[1]/0.5f );
    BOOST_ASSERT( tmp[2] == mat2[2]/0.5f );
    BOOST_ASSERT( tmp[3] == mat2[3]/0.5f );

    mat2 /= 0.5f;
    BOOST_ASSERT( tmp == mat2 );
    mat2 *= 0.5f;
    tmp = mat3;
    tmp *= 4.5f;
    BOOST_ASSERT( tmp == mat3 * 4.5f );
}

void Matrix2_test::test_aritmetic()
{
    Mat2f result = mat1 * mat1.inverse();

    BOOST_ASSERT( result == Mat2f::IDENTITY );
    BOOST_ASSERT( mat1.det() == mat1[0]*mat1[3] - mat1[1]*mat1[2] );
    BOOST_ASSERT( mat2.det() == mat2[0]*mat2[3] - mat2[1]*mat2[2] );
    BOOST_ASSERT( result.det() == 1.0f );

    result = mat3.transpose();
    BOOST_ASSERT( result[0] == mat3[0] );
    BOOST_ASSERT( result[1] == mat3[2] );
    BOOST_ASSERT( result[2] == mat3[1] );
    BOOST_ASSERT( result[3] == mat3[3] );

    float trace = mat2.trace();
    BOOST_ASSERT( trace == mat2[0] + mat2[3] );

    result = mat2;
    result.orthonormalize();
    BOOST_ASSERT( result[0]*result[1] + result[2]*result[3] == 0.0f );
    BOOST_ASSERT( result[0]*result[2] + result[1]*result[3] == 0.0f );

    BOOST_ASSERT( result[0]*result[0] + result[1]*result[1] == 1.0f );
    BOOST_ASSERT( result[0]*result[0] + result[2]*result[2] == 1.0f );
    BOOST_ASSERT( result[1]*result[1] + result[3]*result[3] == 1.0f );
    BOOST_ASSERT( result[2]*result[2] + result[3]*result[3] == 1.0f );

    Mat2f rotate = Mat2f(Math<float>::Cos(0.4f), -Math<float>::Sin(0.4f),
                         Math<float>::Sin(0.4f), Math<float>::Cos(0.4f));
    BOOST_ASSERT( rotate.toAngle() ==  0.4f );
}
