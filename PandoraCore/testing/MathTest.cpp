/*
-------------------------------------------------------------------------------
File Name : MathTest.cpp

Purpose : Testing the Math class in Pandora3D

Creation Date : 2010-01-26

Last Modified : ti. 11. mai 2010 kl. 11.30 +0200

Created By :  Martin Ertsås
-------------------------------------------------------------------------------
*/

#include "MathTest.h"

using Pandora::Math::Math;

void MathTest::init()
{
    printf("Starting MathTest\t\n");
}

void MathTest::testTrigonometries()
{
    printf("\tTesting trigonometries\n");

    CPPUNIT_ASSERT( Math<double>::Abs( Math<double>::Cos(4.0) - cos(4.0) ) 
            < eps );
    CPPUNIT_ASSERT( Math<double>::Abs( Math<double>::Sin(4.0) - sin(4.0) )
            < eps );
    CPPUNIT_ASSERT( Math<double>::Abs( Math<double>::Tan(4.0) - tan(4.0) ) 
            < eps);

    CPPUNIT_ASSERT( Math<double>::Abs( Math<double>::Acos(0.2) - acos(0.2) ) 
            < eps );
    CPPUNIT_ASSERT( Math<double>::Abs( Math<double>::Acos(1.2) - 0.0 ) < eps );
    CPPUNIT_ASSERT( Math<double>::Abs( Math<double>::Acos(-0.2) - acos(-0.2) ) 
            < eps );
    CPPUNIT_ASSERT( Math<double>::Abs( Math<double>::Acos(-1.2) - Math<double>::PI )
            < eps );

    CPPUNIT_ASSERT( Math<double>::Abs( Math<double>::Asin(0.2) - asin(0.2) )
            < eps );
    CPPUNIT_ASSERT( Math<double>::Abs( Math<double>::Asin(1.2) - 
                Math<double>::HALF_PI ) < eps );
    CPPUNIT_ASSERT( Math<double>::Abs( Math<double>::Asin(-0.2) - asin(-0.2) )
            < eps );
    CPPUNIT_ASSERT( Math<double>::Abs( Math<double>::Asin(-1.2) - 
                -Math<double>::HALF_PI ) < eps );

    CPPUNIT_ASSERT( Math<double>::Abs( Math<double>::Atan(0.2) - atan(0.2) )
            < eps );
    CPPUNIT_ASSERT( Math<double>::Abs( Math<double>::Atan(1.2) - atan(1.2) )
            < eps );
    CPPUNIT_ASSERT( Math<double>::Abs( Math<double>::Atan(-1.2) - atan(-1.2) )
            < eps );
    CPPUNIT_ASSERT( Math<double>::Abs( Math<double>::Atan(12.2) - atan(12.2) )
            < eps );

    CPPUNIT_ASSERT( Math<double>::Abs( Math<double>::Atan2(2.0, 4.1) - 
                atan2(2.0, 4.1) ) < eps );
}

void MathTest::testRound()
{
    printf("\tTesting round\t\n");

    CPPUNIT_ASSERT( Math<double>::Abs( Math<double>::Abs(1.2) - 1.2 )
            < eps );
    CPPUNIT_ASSERT( Math<double>::Abs( Math<double>::Abs(-1.2) - 1.2 )
            < eps );
    
    CPPUNIT_ASSERT( Math<double>::Abs( Math<double>::Round(1.2) - 1 )
            < eps );
    CPPUNIT_ASSERT( Math<double>::Abs( Math<double>::Round(1.8) - 2 )
            < eps );
    CPPUNIT_ASSERT( Math<double>::Abs( Math<double>::Round(-1.8) - -2 )
            < eps );
    CPPUNIT_ASSERT( Math<double>::Abs( Math<double>::Round(-1.2) - -1 )
            < eps );

    CPPUNIT_ASSERT( Math<double>::Abs( Math<double>::Floor(1.2) - 1 )
            < eps );
    CPPUNIT_ASSERT( Math<double>::Abs( Math<double>::Floor(1.8) - 1 )
            < eps );
    CPPUNIT_ASSERT( Math<double>::Abs( Math<double>::Floor(-1.2) - -2 )
            < eps );
    CPPUNIT_ASSERT( Math<double>::Abs( Math<double>::Floor(-1.8) - -2 )
            < eps );

    CPPUNIT_ASSERT( Math<double>::Abs( Math<double>::Ceil(1.2) - 2 )
            < eps );
    CPPUNIT_ASSERT( Math<double>::Abs( Math<double>::Ceil(1.8) - 2 )
            < eps );
    CPPUNIT_ASSERT( Math<double>::Abs( Math<double>::Ceil(-1.2) - -1 )
            < eps );
    CPPUNIT_ASSERT( Math<double>::Abs( Math<double>::Ceil(-1.8) - -1 )
            < eps );
}

void MathTest::testPow()
{
    printf("\tTesting pow/log\t\n");

    CPPUNIT_ASSERT( Math<double>::Abs( Math<double>::Exp(4.0) - exp(4.0) )
            < eps );
    CPPUNIT_ASSERT( Math<double>::Abs( Math<double>::Exp(-4.0) - exp(-4.0) )
            < eps );
    CPPUNIT_ASSERT( Math<double>::Abs( Math<double>::Exp(0.0) - exp(0.0) )
            < eps );

    CPPUNIT_ASSERT( Math<double>::Abs( Math<double>::Log(1.0) - 0.0 ) 
            < eps );
    CPPUNIT_ASSERT( Math<double>::Abs( Math<double>::Log(0.1) - log(0.1) )
            < eps );
    CPPUNIT_ASSERT( Math<double>::Log(0.0) == log(0.0) );
    CPPUNIT_ASSERT( Math<double>::Log(8.0) < log(9.5) );

    CPPUNIT_ASSERT( Math<double>::Abs( Math<double>::Log10(1.0) - log10(1.0) )
            < eps );
    CPPUNIT_ASSERT( Math<double>::Log10(0.0) == log10(0.0) );
    CPPUNIT_ASSERT( Math<double>::Abs( Math<double>::Log10(0.1) - log10(0.1) )
            < eps );
    CPPUNIT_ASSERT( Math<double>::Log10(50.0) < Math<double>::Log10(50.1) );

    CPPUNIT_ASSERT( Math<double>::Abs( Math<double>::Pow(4.0,3.0) - pow(4.0,3.0) )
            < eps );
    CPPUNIT_ASSERT( Math<double>::Abs( Math<double>::Pow(-1.9,8.0) - pow(-1.9,8.0) )
            < eps );
    CPPUNIT_ASSERT( Math<double>::Abs( Math<double>::Pow(0.0, 100.0) - 0.0 )
            < eps );
    CPPUNIT_ASSERT( Math<double>::Abs( Math<double>::Pow(8.1, 0.0) - 1.0 )
            < eps );
}

CppUnit::Test *MathTest::suite()
{
    CppUnit::TestSuite *testSuite = new CppUnit::TestSuite("MathTest");
    testSuite->addTest( new CppUnit::TestCaller<MathTest>(
                "MathTest::init",
                &MathTest::init ));
    testSuite->addTest( new CppUnit::TestCaller<MathTest>(
                "MathTest::testTrigonometries",
                &MathTest::testTrigonometries ));
    testSuite->addTest( new CppUnit::TestCaller<MathTest>(
                "MathTest::testRound",
                &MathTest::testRound ));
    testSuite->addTest( new CppUnit::TestCaller<MathTest>(
                "MathTest::testPow",
                &MathTest::testPow ));
    return testSuite;
}

void MathTest::setUp()
{
    eps = Math<double>::EPSILON;
}

void MathTest::tearDown()
{
}
