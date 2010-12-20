/*
-------------------------------------------------------------------------------
File Name :

Purpose :

Creation Date : 2010-10-14

Last Modified : sø. 19. des. 2010 kl. 13.40 +0100

Created By :  Martin Ertsaas (martiert@student.matnat.uio.no)
-------------------------------------------------------------------------------
*/

#include "Matrix2_test.h"

using Pandora::Math::Mat2f;

Matrix2_test::Matrix2_test()
{
    float arr[4] = {4.1f, 6.5f, 7.8f, 9.3f};
    mat1 = Mat2f(arr);
    mat2 = Mat2f(4.0f, 2.1f, 3.7f, 8.4f);
    mat3 = Mat2f(mat1);
}

void Matrix2_test::test_construct()
{
    printf("\tTesting Mat2f constructors\n");
    BOOST_ASSERT( mat1[0] == 4.1f );
    BOOST_ASSERT( mat1[1] == 6.5f );
    BOOST_ASSERT( mat1[2] == 7.8f );
    BOOST_ASSERT( mat1[3] == 9.3f );

    BOOST_ASSERT( mat2[0] == 4.0f );
    BOOST_ASSERT( mat2[1] == 2.1f );
    BOOST_ASSERT( mat2[2] == 3.7f );
    BOOST_ASSERT( mat2[3] == 8.4f );

    BOOST_ASSERT( mat1 == mat3 );
}

void Matrix2_test::test_equality()
{
    printf("\tTesting Mat2f equality\n");

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
    printf("\tTesting Mat2f addition\n");
}

void Matrix2_test::test_multiplication()
{
    printf("\tTesting Mat2f multiplication\n");
}

void Matrix2_test::test_aritmetic()
{
    printf("\tTesting Mat2f aritmetic\n");
}
