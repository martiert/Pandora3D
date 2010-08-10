/*
--------------------------------------------------------------------------------
File Name : Matrix3Test.cpp

Purpose :

Creation Date : 2010-05-04

Last Modified : ti. 10. aug. 2010 kl. 14.03 +0200

Created By :  Martin Ertsås
--------------------------------------------------------------------------------
*/

#include "Matrix3Test.h"

using Pandora::Math::Mat3d;
using Pandora::Math::Math;
using Pandora::Math::Mat3d;
using Pandora::Math::Vec3d;

void Matrix3Test::init()
{
    printf("Starting Matrix3Test\t\n");
}

void Matrix3Test::testConstructor()
{
    printf("\tTesting constructor\n");

    CPPUNIT_ASSERT( test1[0] == 8.0 );
    CPPUNIT_ASSERT( test1[1] == 2.0 );
    CPPUNIT_ASSERT( test1[2] == 3.0 );
    CPPUNIT_ASSERT( test1[3] == 6.0 );
    CPPUNIT_ASSERT( test1[4] == -2.0 );
    CPPUNIT_ASSERT( test1[5] == 1.0 );
    CPPUNIT_ASSERT( test1[6] == 9.0 );
    CPPUNIT_ASSERT( test1[7] == 4.0 );
    CPPUNIT_ASSERT( test1[8] == 2.0 );

    Mat3d tmp(test1);
    for(int i = 0; i < 9; i++)
        CPPUNIT_ASSERT( tmp[i] == test1[i] );

    double array[9] = { 3.4, 4.1, 8.1,
                        9.4, 8.3, 9.6,
                        2.3, 5.1, 4.3};
    Mat3d tmp2(array);
    for(int i = 0; i < 9; i++)
        CPPUNIT_ASSERT( tmp2[i] == array[i] );

    Pandora::Math::Mat2d mat;
    Mat3d tmp3(mat);
    CPPUNIT_ASSERT( tmp3[0] == mat[0] );
    CPPUNIT_ASSERT( tmp3[1] == mat[1] );
    CPPUNIT_ASSERT( tmp3[2] == 0.0 );
    CPPUNIT_ASSERT( tmp3[3] == mat[2] );
    CPPUNIT_ASSERT( tmp3[4] == mat[3] );
    CPPUNIT_ASSERT( tmp3[5] == 0.0 );
    CPPUNIT_ASSERT( tmp3[6] == 0.0 );
    CPPUNIT_ASSERT( tmp3[7] == 0.0 );
    CPPUNIT_ASSERT( tmp3[8] == 1.0 );
}

void Matrix3Test::testAddition()
{
    printf("\tTesting addition\n");

    Mat3d tmp = test1 + test2;
    for(int i = 0; i < 9; i++)
        CPPUNIT_ASSERT( tmp[i] == test1[i] + test2[i] );
}

void Matrix3Test::testSubtraction()
{
    printf("\tTesting subtraction\n");
    Mat3d tmp = test1 - test2;
    for(int i = 0; i < 9; i++)
        CPPUNIT_ASSERT( tmp[i] == test1[i] - test2[i] );
}

void Matrix3Test::testMultiplication()
{
    printf("\tTesting multiplication\n");

    //Matrix-scalar multiplication.
    Mat3d tmp = test2 * 2.3;
    for(int i = 0; i < 9; i++)
        CPPUNIT_ASSERT( tmp[i] == test2[i] * 2.3 );
    tmp = 2.3 * test2;
    for(int i = 0; i < 9; i++)
        CPPUNIT_ASSERT( tmp[i] == test2[i] * 2.3 );

    //Matrix-vector multiplication.
    Pandora::Math::Vec3d vec1(3.4, 2.3, 8.1);
    Pandora::Math::Vec3d vectmp = test2 * vec1;
    for(int i = 0; i < 3; i++)
        CPPUNIT_ASSERT( vectmp[i] == vec1[0]*test2[i*3] + vec1[1]*test2[i*3+1] 
                + vec1[2]*test2[i*3+2] );

    //Matrix-Matrix multiplication
    tmp = test2 * Mat3d::IDENTITY;
    CPPUNIT_ASSERT( tmp == test2 );
    tmp = test2 * test1;
    CPPUNIT_ASSERT( tmp[0] == test2[0]*test1[0] + test2[1]*test1[3] + 
            test2[2]*test1[6] );
    CPPUNIT_ASSERT( tmp[1] == test2[0]*test1[1] + test2[1]*test1[4] +
            test2[2]*test1[7] );
    CPPUNIT_ASSERT( tmp[2] == test2[0]*test1[2] + test2[1]*test1[5] +
            test2[2]*test1[8] );

    CPPUNIT_ASSERT( tmp[3] == test2[3]*test1[0] + test2[4]*test1[3] +
            test2[5]*test1[6] );
    CPPUNIT_ASSERT( tmp[4] == test2[3]*test1[1] + test2[4]*test1[4] +
            test2[5]*test1[7] );
    CPPUNIT_ASSERT( tmp[5] == test2[3]*test1[2] + test2[4]*test1[5] +
            test2[5]*test1[8] );

    CPPUNIT_ASSERT( tmp[6] == test2[6]*test1[0] + test2[7]*test1[3] +
            test2[8]*test1[6] );
    CPPUNIT_ASSERT( tmp[7] == test2[6]*test1[1] + test2[7]*test1[4] +
            test2[8]*test1[7] );
    CPPUNIT_ASSERT( tmp[8] == test2[6]*test1[2] + test2[7]*test1[5] +
            test2[8]*test1[8] );
}

void Matrix3Test::testArithmetic()
{
    printf("\tTesting arithmetic\n");
    Mat3d tmp1 = test1.abs();
    CPPUNIT_ASSERT( tmp1 >= Mat3d::ZERO );

    double deter = test1.det();
    CPPUNIT_ASSERT( deter == 56.0 );

    Mat3d inv = Mat3d::IDENTITY.inverse();
    CPPUNIT_ASSERT( inv == Mat3d::IDENTITY );
    inv = test3.inverse();
    tmp1 = inv*test3;
    CPPUNIT_ASSERT( tmp1 == Mat3d::IDENTITY );
    tmp1 = test3*inv;
    CPPUNIT_ASSERT( tmp1 == Mat3d::IDENTITY );

    tmp1 = test1.transpose();
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            CPPUNIT_ASSERT( tmp1(i,j) == test1(j,i) );

    tmp1 = -test1;
    for(int i = 0; i < 9; i++)
        CPPUNIT_ASSERT( tmp1[i] == -test1[i] );
}

void Matrix3Test::testComparison()
{
    printf("\tTesting comparison\n");

    CPPUNIT_ASSERT( test1 > test2 );
    CPPUNIT_ASSERT( test2 < test3 );

    Mat3d tmp = test1;
    CPPUNIT_ASSERT( tmp == test1 );
    CPPUNIT_ASSERT( tmp <= test1 );
    CPPUNIT_ASSERT( tmp >= test1 );
    tmp[2] += 2;
    CPPUNIT_ASSERT( test1 <= tmp );

    tmp[2] -= 4;
    CPPUNIT_ASSERT( test1 >= tmp );
    CPPUNIT_ASSERT( test1 != test2 );
    CPPUNIT_ASSERT( test1 != tmp );
}

void Matrix3Test::testAssignment()
{
    printf("\tTesting assignment\n");

    Mat3d tmp = test1;
    CPPUNIT_ASSERT( tmp == test1 );
    tmp[2] += 3;
    CPPUNIT_ASSERT( tmp != test1 );

    double *arr = (double*) test1;
    arr[2] += 3;
    CPPUNIT_ASSERT( test1 == tmp );
}

CppUnit::Test *Matrix3Test::suite()
{  
    CppUnit::TestSuite *testSuite = new CppUnit::TestSuite("Matrix3Test");
    testSuite->addTest( new CppUnit::TestCaller<Matrix3Test>(
                "Matrix3Test::init",
                &Matrix3Test::init ));
    testSuite->addTest( new CppUnit::TestCaller<Matrix3Test>(
                "Matrix3Test::testConstructor",
                &Matrix3Test::testConstructor ));
    testSuite->addTest( new CppUnit::TestCaller<Matrix3Test>(
                "Matrix3Test::testAddition",
                &Matrix3Test::testAddition ));
    testSuite->addTest( new CppUnit::TestCaller<Matrix3Test>(
                "Matrix3Test::testSubtraction",
                &Matrix3Test::testSubtraction ));
    testSuite->addTest( new CppUnit::TestCaller<Matrix3Test>(
                "Matrix3Test::testMultiplication",
                &Matrix3Test::testMultiplication ));
    testSuite->addTest( new CppUnit::TestCaller<Matrix3Test>(
                "Matrix3Test::testArithmetic",
                &Matrix3Test::testArithmetic ));
    testSuite->addTest( new CppUnit::TestCaller<Matrix3Test>(
                "Matrix3Test::testComparison",
                &Matrix3Test::testComparison ));
    testSuite->addTest( new CppUnit::TestCaller<Matrix3Test>(
                "Matrix3Test::testAssignment",
                &Matrix3Test::testAssignment ));

    return testSuite;
}

void Matrix3Test::setUp()
{
    //Do not touch. Need to have this exact data since we have hardcoded the
    //determinant check. If you wan't to, please fix, but I'm to lazy!
    //
    //Never touch the test3 matrix. This is only used for the inverse, which
    //is sensitive to floating point errors.
    test1 = Mat3d(  8.0, 2.0, 3.0, 
                    6.0, -2.0, 1.0,
                    9.0, 4.0, 2.0);
    test2 = Mat3d(  4.0, 8.7, 9.2, 
                    2.5, 2.7, 7.1,
                    3.9, 5.8, 2.3);
    test3 = Mat3d(  4.5, 1.0, -2.0,
                    -3.0, 3.5, 2.0,
                    -3.0, 2.5, 4.5);
    eps = Math<double>::EPSILON;
}

void Matrix3Test::tearDown()
{
}
