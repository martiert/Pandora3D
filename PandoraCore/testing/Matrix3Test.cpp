/*
--------------------------------------------------------------------------------
File Name : Matrix3Test.cpp

Purpose :

Creation Date : 2010-05-04

Last Modified : ma. 28. juni 2010 kl. 16.32 +0200

Created By :  Martin Ertsås
--------------------------------------------------------------------------------
*/

#include "Matrix3Test.h"

using Pandora::Math::Mat3d;
using Pandora::Math::Math;
using Pandora::Math::Mat3d;

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
    CPPUNIT_ASSERT( test1[4] == 2.0 );
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
}

void Matrix3Test::testSubtraction()
{
    printf("\tTesting subtraction\n");
}

void Matrix3Test::testMultiplication()
{
    printf("\tTesting multiplication\n");
}

void Matrix3Test::testArithmetic()
{
    printf("\tTesting arithmetic\n");
}

void Matrix3Test::testComparison()
{
    printf("\tTesting comparison\n");
}

void Matrix3Test::testAssignment()
{
    printf("\tTesting assignment\n");
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
    test1 = Mat3d(  8.0, 2.0, 3.0, 
                    6.0, 2.0, 1.0,
                    9.0, 4.0, 2.0);
    test2 = Mat3d(  4.0, 8.7, 9.2, 
                    2.5, 2.7, 7.1,
                    3.9, 5.8, 2.3);
    eps = Math<double>::EPSILON;
}

void Matrix3Test::tearDown()
{
}
