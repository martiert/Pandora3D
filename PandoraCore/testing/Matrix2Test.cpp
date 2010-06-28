/*
--------------------------------------------------------------------------------
File Name : Matrix2Test.cpp

Purpose :

Creation Date : 2010-05-04

Last Modified : ma. 28. juni 2010 kl. 16.13 +0200

Created By :  Martin Ertsås
--------------------------------------------------------------------------------
*/

#include "Matrix2Test.h"

using Pandora::Math::Mat2d;
using Pandora::Math::Math;
using Pandora::Math::Vec2d;

void Matrix2Test::init()
{
    printf("Starting Matrix2Test\t\n");
}

void Matrix2Test::testConstructor()
{
    printf("\tTesting constructor\n");

    Mat2d test(Mat2d::ZERO);
    CPPUNIT_ASSERT( test == Mat2d::ZERO );

    test = Mat2d(Mat2d::IDENTITY);
    CPPUNIT_ASSERT( test == Mat2d::IDENTITY );

    double array[4] = {3.1, 4.8, 7.6, 9.2};
    test = Mat2d(array);
    CPPUNIT_ASSERT( test[0] == array[0] );
    CPPUNIT_ASSERT( test[1] == array[1] );
    CPPUNIT_ASSERT( test[2] == array[2] );
    CPPUNIT_ASSERT( test[3] == array[3] );

    test = Mat2d(2.1, 4.1, 8.3, 9.71);
    CPPUNIT_ASSERT( test[0] == 2.1 );
    CPPUNIT_ASSERT( test[1] == 4.1 );
    CPPUNIT_ASSERT( test[2] == 8.3 );
    CPPUNIT_ASSERT( test[3] == 9.71 );
}

void Matrix2Test::testAddition()
{
    printf("\tTesting addition\n");

    CPPUNIT_ASSERT( Mat2d::ZERO + Mat2d::IDENTITY == Mat2d::IDENTITY );

    Mat2d tmp = test1 + Mat2d::IDENTITY;
    CPPUNIT_ASSERT( tmp[0] == test1[0] + 1.0 );
    CPPUNIT_ASSERT( tmp[1] == test1[1] );
    CPPUNIT_ASSERT( tmp[2] == test1[2] );
    CPPUNIT_ASSERT( tmp[3] == test1[3] + 1.0 );

    tmp = test1 + test2;
    CPPUNIT_ASSERT( Math<double>::Abs(tmp[0] - test1[0] - test2[0]) <= eps );
    CPPUNIT_ASSERT( Math<double>::Abs(tmp[1] - test1[1] - test2[1]) <= eps );
    CPPUNIT_ASSERT( Math<double>::Abs(tmp[2] - test1[2] - test2[2]) <= eps );
    CPPUNIT_ASSERT( Math<double>::Abs(tmp[3] - test1[3] - test2[3]) <= eps );

    tmp = test1;
    tmp += test2;
    CPPUNIT_ASSERT( Math<double>::Abs(tmp[0] - test1[0] - test2[0]) <= eps );
    CPPUNIT_ASSERT( Math<double>::Abs(tmp[1] - test1[1] - test2[1]) <= eps );
    CPPUNIT_ASSERT( Math<double>::Abs(tmp[2] - test1[2] - test2[2]) <= eps );
    CPPUNIT_ASSERT( Math<double>::Abs(tmp[3] - test1[3] - test2[3]) <= eps );
}

void Matrix2Test::testSubtraction()
{
    printf("\tTesting subtraction\n");

    CPPUNIT_ASSERT( Mat2d::ZERO - Mat2d::IDENTITY == -Mat2d::IDENTITY );

    Mat2d tmp = test1 - Mat2d::IDENTITY;
    CPPUNIT_ASSERT( tmp[0] == test1[0] - 1.0 );
    CPPUNIT_ASSERT( tmp[1] == test1[1] );
    CPPUNIT_ASSERT( tmp[2] == test1[2] );
    CPPUNIT_ASSERT( tmp[3] == test1[3] - 1.0 );

    tmp = test1 - test2;
    CPPUNIT_ASSERT( Math<double>::Abs(tmp[0] - test1[0] + test2[0]) <= eps );
    CPPUNIT_ASSERT( Math<double>::Abs(tmp[1] - test1[1] + test2[1]) <= eps );
    CPPUNIT_ASSERT( Math<double>::Abs(tmp[2] - test1[2] + test2[2]) <= eps );
    CPPUNIT_ASSERT( Math<double>::Abs(tmp[3] - test1[3] + test2[3]) <= eps );

    tmp = test1;
    tmp -= test2;
    CPPUNIT_ASSERT( Math<double>::Abs(tmp[0] - test1[0] + test2[0]) <= eps );
    CPPUNIT_ASSERT( Math<double>::Abs(tmp[1] - test1[1] + test2[1]) <= eps );
    CPPUNIT_ASSERT( Math<double>::Abs(tmp[2] - test1[2] + test2[2]) <= eps );
    CPPUNIT_ASSERT( Math<double>::Abs(tmp[3] - test1[3] + test2[3]) <= eps );
}

void Matrix2Test::testMultiplication()
{
    printf("\tTesting multiplication\n");

    //Matrix matrix multiplication
    Mat2d tmp = test1 * Mat2d::IDENTITY;
    CPPUNIT_ASSERT( tmp == test1 );

    tmp = test1 * test2;
    CPPUNIT_ASSERT( tmp[0] == test1[0]*test2[0] + test1[1]*test2[2] );
    CPPUNIT_ASSERT( tmp[1] == test1[0]*test2[1] + test1[1]*test2[3] );
    CPPUNIT_ASSERT( tmp[2] == test1[2]*test2[0] + test1[3]*test2[2] );
    CPPUNIT_ASSERT( tmp[3] == test1[2]*test2[1] + test1[3]*test2[3] );

    //Matrix scalar multiplication
    tmp = test1 * 1.0;
    CPPUNIT_ASSERT( tmp == test1 );
    tmp = 1.0 * test1;
    CPPUNIT_ASSERT( tmp == test1 );
    tmp = 3.4 * test2;
    CPPUNIT_ASSERT( tmp[0] == test2[0] * 3.4 );
    CPPUNIT_ASSERT( tmp[1] == test2[1] * 3.4 );
    CPPUNIT_ASSERT( tmp[2] == test2[2] * 3.4 );
    CPPUNIT_ASSERT( tmp[3] == test2[3] * 3.4 );

    //Matrix vector multiplication
    Vec2d vec(1.0, 0.0);
    Vec2d ans = test1 * vec;
    CPPUNIT_ASSERT( ans[0] == test1[0] );
    CPPUNIT_ASSERT( ans[1] == test1[2] );

    vec[1] = 3.2;
    ans = test2 * vec;
    CPPUNIT_ASSERT( ans[0] == test2[0] + test2[1]*3.2 );
    CPPUNIT_ASSERT( ans[1] == test2[2] + test2[3]*3.2 );

    //Self multiplication
    tmp = test1;
    tmp *= 2.3;
    CPPUNIT_ASSERT( tmp[0] == test1[0]*2.3 );
    CPPUNIT_ASSERT( tmp[1]== test1[1]*2.3 );
    CPPUNIT_ASSERT( tmp[2] == test1[2]*2.3 );
    CPPUNIT_ASSERT( tmp[3] == test1[3]*2.3 );

    tmp = test1;
    tmp *= test2;
    CPPUNIT_ASSERT( tmp[0] == test1[0]*test2[0] );
    CPPUNIT_ASSERT( tmp[1] == test1[1]*test2[1] );
    CPPUNIT_ASSERT( tmp[2] == test1[2]*test2[2] );
    CPPUNIT_ASSERT( tmp[3] == test1[3]*test2[3] );

    tmp = Mat2d::ZERO;
    tmp = test1.dot(test2);
    CPPUNIT_ASSERT( tmp[0] == test1[0]*test2[0] );
    CPPUNIT_ASSERT( tmp[1] == test1[1]*test2[1] );
    CPPUNIT_ASSERT( tmp[2] == test1[2]*test2[2] );
    CPPUNIT_ASSERT( tmp[3] == test1[3]*test2[3] );       
}

void Matrix2Test::testArithmetic()
{
    printf("\tTesting arithmetic\n");
    double det = test1.det();
    CPPUNIT_ASSERT( det == test1[0]*test1[3] - test1[1]*test1[2] );
    det = Mat2d::IDENTITY.det();
    CPPUNIT_ASSERT( det == 1.0 );

    Mat2d inv = Mat2d::IDENTITY.inverse();
    CPPUNIT_ASSERT( inv[0] == 1.0 );
    CPPUNIT_ASSERT( inv[1] == 0.0 );
    CPPUNIT_ASSERT( inv[2] == 0.0 );
    CPPUNIT_ASSERT( inv[3] == 1.0 );

    inv = test1.inverse();
    Mat2d tmp = inv * test1;
    CPPUNIT_ASSERT( tmp == Mat2d::IDENTITY );

    tmp = test1 * inv;
    CPPUNIT_ASSERT( tmp == Mat2d::IDENTITY );

    tmp = test2.transpose();
    CPPUNIT_ASSERT( tmp[0] == test2[0] );
    CPPUNIT_ASSERT( tmp[1]== test2[2] );
    CPPUNIT_ASSERT( tmp[2] == test2[1] );
    CPPUNIT_ASSERT( tmp[3] == test2[3] );
}

void Matrix2Test::testComparison()
{
    printf("\tTesting comparison\n");

    Mat2d tmp = test1;
    CPPUNIT_ASSERT( test2 != test1 );
    CPPUNIT_ASSERT( test1 == tmp );
    tmp *= 2.0;
    CPPUNIT_ASSERT( test1 < tmp );
    CPPUNIT_ASSERT( tmp > test1 );
    tmp[2] = test1[2];
    CPPUNIT_ASSERT( !(tmp > test1) );
    CPPUNIT_ASSERT( test1 <= tmp );
    CPPUNIT_ASSERT( tmp >= test1 );
}

void Matrix2Test::testAssignment()
{
    printf("\tTesting assignment\n");

    double *tmp = (double*) test1;
    CPPUNIT_ASSERT( tmp[0] == test1[0] );
    CPPUNIT_ASSERT( tmp[1] == test1[1] );
    CPPUNIT_ASSERT( tmp[2] == test1[2] );
    CPPUNIT_ASSERT( tmp[3] == test1[3] );
    tmp[3] = 0.32;
    CPPUNIT_ASSERT( tmp[3] == test1[3] );

    const double *tmp2 = (const double*) test2;
    CPPUNIT_ASSERT( tmp2[0] == test2[0] );
    CPPUNIT_ASSERT( tmp2[1] == test2[1] );
    CPPUNIT_ASSERT( tmp2[2] == test2[2] );
    CPPUNIT_ASSERT( tmp2[3] == test2[3] );

    test2(1,0) = 3.2;
    test2(0,1) = 4.5;
    CPPUNIT_ASSERT( test2[2] == 3.2 );
    CPPUNIT_ASSERT( test2[1] == 4.5 );

    Vec2d vec1 = test1.getRow(0);
    CPPUNIT_ASSERT( vec1[0] == test1[0] );
    CPPUNIT_ASSERT( vec1[1] == test1[1] );
    vec1[1] = 4.0;
    test1.setRow(0,vec1);
    CPPUNIT_ASSERT( test1[1] == 4.0 );

    vec1 = test1.getColumn(1);
    CPPUNIT_ASSERT( vec1[0] == test1[1] );
    CPPUNIT_ASSERT( vec1[1] == test1[3] );
    vec1[0] = 2.3;
    test1.setColumn(0, vec1);
    CPPUNIT_ASSERT( test1[0] == 2.3 );
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
    test1 = Mat2d(8.0, 2.0, 3.0, 6.0);
    test2 = Mat2d(4.0, 8.7, 9.2, 2.5);
    eps = Math<double>::EPSILON;
}

void Matrix2Test::tearDown()
{
}
