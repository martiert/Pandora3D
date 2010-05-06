/*
--------------------------------------------------------------------------------
File Name : Matrix2Test.cpp

Purpose :

Creation Date : 2010-05-04

Last Modified : to. 06. mai 2010 kl. 17.50 +0200

Created By :  Martin Ertsås
--------------------------------------------------------------------------------
*/

#include "Matrix2Test.h"

using Pandora::Math::Mat2f;

void Matrix2Test::init()
{
    printf("Starting Matrix2Test\n");
}

void Matrix2Test::testConstructor()
{
    printf("\tTesting constructor\n");

    Mat2f test(Mat2f::ZERO);
    CPPUNIT_ASSERT( test == Mat2f::ZERO );

    test = Mat2f(Mat2f::IDENTITY);
    CPPUNIT_ASSERT( test == Mat2f::IDENTITY );

    float array[4] = {3.1f, 4.8f, 7.6f, 9.2f};
    test = Mat2f(array);
    CPPUNIT_ASSERT( test[0] == array[0] );
    CPPUNIT_ASSERT( test[1] == array[1] );
    CPPUNIT_ASSERT( test[2] == array[2] );
    CPPUNIT_ASSERT( test[3] == array[3] );

    test = Mat2f(2.1f, 4.1f, 8.3f, 9.71f);
    CPPUNIT_ASSERT( test[0] == 2.1f );
    CPPUNIT_ASSERT( test[1] == 4.1f );
    CPPUNIT_ASSERT( test[2] == 8.3f );
    CPPUNIT_ASSERT( test[3] == 9.71f );
}

void Matrix2Test::testAddition()
{
    printf("\tTesting addition\n");

    CPPUNIT_ASSERT( Mat2f::ZERO + Mat2f::IDENTITY == Mat2f::IDENTITY );
    Mat2f tmp = test1 + test2;

}

void Matrix2Test::testSubtraction()
{
    printf("\tTesting subtraction\n");
}

void Matrix2Test::testMultiplication()
{
    printf("\tTesting multiplication\n");
}

void Matrix2Test::testArithmetic()
{
    printf("\tTesting arithmetic\n");
}

void Matrix2Test::testComparison()
{
    printf("\tTesting comparison\n");
}

void Matrix2Test::testAssignment()
{
    printf("\tTesting assignment\n");
}

CppUnit::Test *Matrix2Test::suite()
{  
    CppUnit::TestSuite *testSuite = new CppUnit::TestSuite("Matrix2Test");
    testSuite->addTest( new CppUnit::TestCaller<Matrix2Test>(
                "Matrix2Test::init",
                &Matrix2Test::init ));
    testSuite->addTest( new CppUnit::TestCaller<Matrix2Test>(
                "Matrix2Test::testConstructor",
                &Matrix2Test::testConstructor ));
    testSuite->addTest( new CppUnit::TestCaller<Matrix2Test>(
                "Matrix2Test::testAddition",
                &Matrix2Test::testAddition ));
    testSuite->addTest( new CppUnit::TestCaller<Matrix2Test>(
                "Matrix2Test::testSubtraction",
                &Matrix2Test::testSubtraction ));
    testSuite->addTest( new CppUnit::TestCaller<Matrix2Test>(
                "Matrix2Test::testMultiplication",
                &Matrix2Test::testMultiplication ));
    testSuite->addTest( new CppUnit::TestCaller<Matrix2Test>(
                "Matrix2Test::testArithmetic",
                &Matrix2Test::testArithmetic ));
    testSuite->addTest( new CppUnit::TestCaller<Matrix2Test>(
                "Matrix2Test::testComparison",
                &Matrix2Test::testComparison ));
    testSuite->addTest( new CppUnit::TestCaller<Matrix2Test>(
                "Matrix2Test::testAssignment",
                &Matrix2Test::testAssignment ));

    return testSuite;
}

void Matrix2Test::setUp()
{
    test1 = Mat2f(4.1, 2.1, 3.1, 5.9);
    test2 = Mat2f(1.3f, 8.7f, 9.2f, 2.3f);
}

void Matrix2Test::tearDown()
{
}
