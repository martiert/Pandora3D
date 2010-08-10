/*
--------------------------------------------------------------------------------
File Name : Matrix4Test.cpp

Purpose :

Creation Date : 2010-05-04

Last Modified : ti. 10. aug. 2010 kl. 18.15 +0200

Created By :  Martin Ertsås
--------------------------------------------------------------------------------
*/

#include "Matrix4Test.h"

using Pandora::Math::Mat4d;
using Pandora::Math::Math;
using Pandora::Math::Mat4d;
using Pandora::Math::Vec4d;
using Pandora::Math::Mat3d;
using Pandora::Math::Vec3d;

void Matrix4Test::init()
{
    printf("Starting Matrix4Test\t\n");
}

void Matrix4Test::testConstructor()
{
    printf("\tTesting constructor\n");

    CPPUNIT_ASSERT( test1[0] == 8.0 );
    CPPUNIT_ASSERT( test1[1] == 4.1 );
    CPPUNIT_ASSERT( test1[2] == 2.0 );
    CPPUNIT_ASSERT( test1[3] == 5.1 );
    CPPUNIT_ASSERT( test1[4] == -7.6 );
    CPPUNIT_ASSERT( test1[5] == 2.4 );
    CPPUNIT_ASSERT( test1[6] == 9.1 );
    CPPUNIT_ASSERT( test1[7] == 4.3 );
    CPPUNIT_ASSERT( test1[8] == 9.0 );
    CPPUNIT_ASSERT( test1[9] == -5.0 );
    CPPUNIT_ASSERT( test1[10] == -4.3 );
    CPPUNIT_ASSERT( test1[11] == 16.2 );
    CPPUNIT_ASSERT( test1[12] == 5.4 );
    CPPUNIT_ASSERT( test1[13] == 8.1 );
    CPPUNIT_ASSERT( test1[14] == 9.4 );
    CPPUNIT_ASSERT( test1[15] == 2.3 );

    CPPUNIT_ASSERT( test3[0] == 1.0 );
    CPPUNIT_ASSERT( test3[1] == 0.0 );
    CPPUNIT_ASSERT( test3[2] == 0.0 );
    CPPUNIT_ASSERT( test3[3] == 0.0 );
    CPPUNIT_ASSERT( test3[4] == 0.0 );
    CPPUNIT_ASSERT( test3[5] == Math<double>::Cos(1.8) );
    CPPUNIT_ASSERT( test3[6] == -Math<double>::Sin(1.8) );
    CPPUNIT_ASSERT( test3[7] == 0.0 );
    CPPUNIT_ASSERT( test3[8] == 0.0 );
    CPPUNIT_ASSERT( test3[9] == Math<double>::Sin(1.8) );
    CPPUNIT_ASSERT( test3[10] == Math<double>::Cos(1.8) );
    CPPUNIT_ASSERT( test3[11] == 0.0 );
    CPPUNIT_ASSERT( test3[12] == 0.0 );
    CPPUNIT_ASSERT( test3[13] == 0.0 );
    CPPUNIT_ASSERT( test3[14] == 0.0 );
    CPPUNIT_ASSERT( test3[15] == 1.0 );

    Mat4d tmp(test1);
    for(int i = 0; i < 16; i++)
        CPPUNIT_ASSERT( tmp[i] == test1[i] );

    Mat3d tmp2( 3.1, 4.2, 6.5, 
                2.3, 1.2, 9.3, 
                5.4, 2.3, 1.2 );

    tmp = Mat4d(tmp2);
    CPPUNIT_ASSERT( tmp[0] == 3.1 );
    CPPUNIT_ASSERT( tmp[1] == 4.2 );
    CPPUNIT_ASSERT( tmp[2] == 6.5 );
    CPPUNIT_ASSERT( tmp[3] == 0 );
    CPPUNIT_ASSERT( tmp[4] == 2.3 );
    CPPUNIT_ASSERT( tmp[5] == 1.2 );
    CPPUNIT_ASSERT( tmp[6] == 9.3 );
    CPPUNIT_ASSERT( tmp[7] == 0.0 );
    CPPUNIT_ASSERT( tmp[8] == 5.4 );
    CPPUNIT_ASSERT( tmp[9] == 2.3 );
    CPPUNIT_ASSERT( tmp[10] == 1.2 );
    CPPUNIT_ASSERT( tmp[11] == 0.0 );
    CPPUNIT_ASSERT( tmp[12] == 0.0 );
    CPPUNIT_ASSERT( tmp[13] == 0.0 );
    CPPUNIT_ASSERT( tmp[14] == 0.0 );
    CPPUNIT_ASSERT( tmp[15] == 1.0 );

    Vec3d tmp3(2.3, 4.1, 2.3);
    tmp = Mat4d(tmp3, true);

    CPPUNIT_ASSERT( tmp[0] == tmp3[0] );
    CPPUNIT_ASSERT( tmp[1] == 0.0 );
    CPPUNIT_ASSERT( tmp[2] == 0.0 );
    CPPUNIT_ASSERT( tmp[3] == 0.0 );
    CPPUNIT_ASSERT( tmp[4] == 0.0 );
    CPPUNIT_ASSERT( tmp[5] == tmp3[1] );
    CPPUNIT_ASSERT( tmp[6] == 0.0 );
    CPPUNIT_ASSERT( tmp[7] == 0.0 );
    CPPUNIT_ASSERT( tmp[8] == 0.0 );
    CPPUNIT_ASSERT( tmp[9] == 0.0 );
    CPPUNIT_ASSERT( tmp[10] == tmp3[2] );
    CPPUNIT_ASSERT( tmp[11] == 0.0 );
    CPPUNIT_ASSERT( tmp[12] == 0.0 );
    CPPUNIT_ASSERT( tmp[13] == 0.0 );
    CPPUNIT_ASSERT( tmp[14] == 0.0 );
    CPPUNIT_ASSERT( tmp[15] == 1.0 );
}

void Matrix4Test::testAddition()
{
    printf("\tTesting addition\n");

    Mat4d tmp = test1 + Mat4d::ZERO;
    for(int i = 0; i < 16; i++)
        CPPUNIT_ASSERT( tmp[i] == test1[i] );

    tmp = test1 + test2;

    for(int i = 0; i < 16; i++)
        CPPUNIT_ASSERT( tmp[i] == (test1[i] + test2[i]));

    test1 += test2;
    for(int i = 0; i < 16; i++)
        CPPUNIT_ASSERT( tmp[i] == test1[i] );
}

void Matrix4Test::testSubtraction()
{
    printf("\tTesting subtraction\n");

    Mat4d tmp = test1 - test2;
    for(int i = 0; i < 16; i++)
        CPPUNIT_ASSERT( tmp[i] == (test1[i] - test2[i]) );

    test1 -= test2;
    for(int i = 0; i < 16; i++)
        CPPUNIT_ASSERT( tmp[i] == test1[i] );
}

void Matrix4Test::testMultiplication()
{
    printf("\tTesting multiplication\n");

    Mat4d tmp = test1 * Mat4d::IDENTITY;
    for(int i = 0; i < 16; i++)
        CPPUNIT_ASSERT( tmp[i] == test1[i] );

    tmp = test1 * Mat4d::ZERO;
    for(int i = 0; i < 16; i++)
        CPPUNIT_ASSERT( tmp[i] == 0.0 );

    tmp = test3 * test3.inverse();
    for(int i = 0; i < 16; i++)
        CPPUNIT_ASSERT( tmp[i] == Mat4d::IDENTITY[i] );

    tmp = test1;
    test1 *= 4.0;
    for(int i = 0; i < 16; i++)
        CPPUNIT_ASSERT( test1[i] == 4.0*tmp[i] );

    test1 /= 4.0;
    for(int i = 0; i < 16; i++)
        CPPUNIT_ASSERT( test1[i] == tmp[i] );

    Vec4d tmpvec(1, 0, 0, 0);
    Vec4d tmpvec2 = test1 * tmpvec;
    for(int i = 0; i < 4; i++)
        CPPUNIT_ASSERT( tmpvec2[i] == (test1[i*4]*tmpvec[0] + test1[i*4 + 1]*tmpvec[1] + test1[i*4 + 2]*tmpvec[2] + test1[i*4 + 3]*tmpvec[3]) );

    tmp = test1.dotprod(test2);
    for(int i = 0; i < 16; i++)
        CPPUNIT_ASSERT( tmp[i] == test1[i]*test2[i] );

    tmp = test1 * 4.0;
    for(int i = 0; i < 16; i++)
        CPPUNIT_ASSERT( tmp[i] == test1[i] * 4.0 );

    tmp = test1 / 4.0;
    for(int i = 0; i < 16; i++)
        CPPUNIT_ASSERT( tmp[i] == test1[i] / 4.0 );
}

void Matrix4Test::testArithmetic()
{
    printf("\tTesting arithmetic\n");

    Mat4d tmp = test1.transpose();

    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            CPPUNIT_ASSERT( tmp[i*4 + j] == test1[j*4 + i] );

    double det = Mat4d::IDENTITY.det();
    CPPUNIT_ASSERT( det == 1.0 );
    CPPUNIT_ASSERT( test2.det() == 3407.0 );

    tmp = -test1;
    for(int i = 0; i < 16; i++)
        CPPUNIT_ASSERT( tmp[i] == -(test1[i]) );
}

void Matrix4Test::testComparison()
{
    printf("\tTesting comparison\n");

    CPPUNIT_ASSERT( test1 != test2 );
    CPPUNIT_ASSERT( test1 > test2 );
    CPPUNIT_ASSERT( test1 >= test2 );
    test1[0] = -3.0;
    CPPUNIT_ASSERT( test1 < test2 );
    CPPUNIT_ASSERT( test1 <= test2 );

    Mat4d tmp = test1;
    CPPUNIT_ASSERT( tmp == test1 );
    tmp[4]++;
    CPPUNIT_ASSERT( tmp >= test1 );
    CPPUNIT_ASSERT( tmp > test1 );
}

void Matrix4Test::testAssignment()
{
    printf("\tTesting assignment\n");
    CPPUNIT_ASSERT( test1[3*4 + 2] == test1(3,2) );
    test1[4] = 2.0;
    CPPUNIT_ASSERT( test1[4] == 2.0 );
    CPPUNIT_ASSERT( test1(1,0) == 2.0 );

    double *tmp = (double*) test1;
    for(int i = 0; i < 16; i++)
        CPPUNIT_ASSERT( tmp[i] == test1[i] );

    tmp[4] = 9.4;
    CPPUNIT_ASSERT( test1[4] == 9.4 );
}

CppUnit::Test *Matrix4Test::suite()
{  
    CppUnit::TestSuite *testSuite = new CppUnit::TestSuite("Matrix4Test");
    testSuite->addTest( new CppUnit::TestCaller<Matrix4Test>(
                "Matrix4Test::init",
                &Matrix4Test::init ));
    testSuite->addTest( new CppUnit::TestCaller<Matrix4Test>(
                "Matrix4Test::testConstructor",
                &Matrix4Test::testConstructor ));
    testSuite->addTest( new CppUnit::TestCaller<Matrix4Test>(
                "Matrix4Test::testAddition",
                &Matrix4Test::testAddition ));
    testSuite->addTest( new CppUnit::TestCaller<Matrix4Test>(
                "Matrix4Test::testSubtraction",
                &Matrix4Test::testSubtraction ));
    testSuite->addTest( new CppUnit::TestCaller<Matrix4Test>(
                "Matrix4Test::testMultiplication",
                &Matrix4Test::testMultiplication ));
    testSuite->addTest( new CppUnit::TestCaller<Matrix4Test>(
                "Matrix4Test::testArithmetic",
                &Matrix4Test::testArithmetic ));
    testSuite->addTest( new CppUnit::TestCaller<Matrix4Test>(
                "Matrix4Test::testComparison",
                &Matrix4Test::testComparison ));
    testSuite->addTest( new CppUnit::TestCaller<Matrix4Test>(
                "Matrix4Test::testAssignment",
                &Matrix4Test::testAssignment ));

    return testSuite;
}

void Matrix4Test::setUp()
{
    //Do not touch. Need to have this exact data since we have hardcoded the
    //determinant check. If you wan't to, please fix, but I'm to lazy!
    //
    //Never touch the test3 matrix. This is only used for the inverse, which
    //is sensitive to floating point errors.
    eps = Math<double>::EPSILON;

    double tmp[16] = { 4.0, 2.0, 1.0, -4.0,
                       5.0, 1.0, -3.0, 1.0,
                       3.0, 8.0, -8.0, 2.0,
                       1.0, 3.0, 9.0, 8.0 };
    double rad = 1.8;
    Vec4d tmpvec(1.0, 0.0, 0.0);

    test1 = Mat4d( 8.0, 4.1, 2.0, 5.1,
                   -7.6, 2.4, 9.1, 4.3,
                   9.0, -5.0, -4.3, 16.2,
                   5.4, 8.1, 9.4, 2.3 );

    test2 = Mat4d(tmp);
    test3 = Mat4d(rad, tmpvec);
}

void Matrix4Test::tearDown()
{
}
