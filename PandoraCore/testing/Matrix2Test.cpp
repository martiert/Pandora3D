/*
--------------------------------------------------------------------------------
File Name : Matrix2Test.cpp

Purpose :

Creation Date : 2010-05-04

Last Modified : ti. 04. mai 2010 kl. 21.21 +0200

Created By :  Martin Ertsås
--------------------------------------------------------------------------------
*/

#include "Matrix2Test.h"

using Pandora::Math::Mat2f;

void Matrix2Test::init()
{
    printf("Starting Matrix2Test\n");
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
}

void Matrix2Test::setUp()
{
}

void Matrix2Test::tearDown()
{
}
