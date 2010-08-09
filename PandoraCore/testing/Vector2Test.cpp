/*
-------------------------------------------------------------------------------
File Name : Vector2Test.cpp

Purpose : Unit testing of the Pandora::Math::Vec2 implementation.

Creation Date : 2010-01-25

Last Modified : ti. 06. juli 2010 kl. 10.58 +0200

Created [1] :  Martin Ertsås
-------------------------------------------------------------------------------
*/

#include "Vector2Test.h"

using Pandora::Math::Vec2f;

void Vector2Test::init()
{
    printf("Starting Vector2Test\t\n");
}

void Vector2Test::testConstructor()
{
    printf("\tTesting constructors\n");

    CPPUNIT_ASSERT( m_1_0[0] == 1.0f );
    CPPUNIT_ASSERT( m_1_0[1] == 0.0f );
    CPPUNIT_ASSERT( m_0_0[0] == 0.0f );
    CPPUNIT_ASSERT( m_0_0[1] == 0.0f );
    CPPUNIT_ASSERT( m_0_1[0] == 0.0f );
    CPPUNIT_ASSERT( m_0_1[1] == 1.0f );

    Vec2f tmp(m_1_0);
    CPPUNIT_ASSERT( tmp[0] == m_1_0[0] );
    CPPUNIT_ASSERT( tmp[1] == m_1_0[1] );

    float test[] = {1.0f, 4.0f};
    Vec2f tmp2(&test[0]);
    CPPUNIT_ASSERT( tmp2[0] == test[0] );
    CPPUNIT_ASSERT( tmp2[1] == test[1] );
}

void Vector2Test::testAddition()
{
    printf("\tTesting addition\n");

    Vec2f tmp = m_1_0 + m_0_0;
    CPPUNIT_ASSERT( tmp[0] == m_1_0[0] );
    CPPUNIT_ASSERT( tmp[1] == m_1_0[1] );

    tmp = m_1_0 + m_0_1;
    CPPUNIT_ASSERT( tmp[0] == m_1_1[0] );
    CPPUNIT_ASSERT( tmp[1] == m_1_1[1] );

    tmp += m_1_0;
    CPPUNIT_ASSERT( tmp[0] == 2.0f );
    CPPUNIT_ASSERT( tmp[1] == 1.0f );
}

void Vector2Test::testSubtraction()
{
    printf("\tTesting subtraction\n");

    Vec2f tmp = m_4_2 - m_1_1;
    CPPUNIT_ASSERT( tmp[0] == 3.0f );
    CPPUNIT_ASSERT( tmp[1] == 1.0f );

    tmp -= m_1_1;
    CPPUNIT_ASSERT( tmp[0] == 2.0f );
    CPPUNIT_ASSERT( tmp[1] == 0.0f );
}

void Vector2Test::testMultiplication()
{
    printf("\tTesting multiplication\n");

    float tmp = m_4_2 * m_1_1;
    CPPUNIT_ASSERT( tmp == 6.0f );

    Vec2f tmp2 = m_4_2 * 2.5f;
    CPPUNIT_ASSERT( tmp2[0] == 10.0f );
    CPPUNIT_ASSERT( tmp2[1] == 5.0f );

    tmp2 /= 2.5f;
    CPPUNIT_ASSERT( tmp2[0] == 4.0f );
    CPPUNIT_ASSERT( tmp2[1] == 2.0f );

    tmp2 = m_4_2 / 2.0f;
    CPPUNIT_ASSERT( tmp2[0] == 2.0f );
    CPPUNIT_ASSERT( tmp2[1] == 1.0f );

    tmp2 *= 2.0f;
    CPPUNIT_ASSERT( tmp2[0] == 4.0f );
    CPPUNIT_ASSERT( tmp2[1] == 2.0f );
}

void Vector2Test::testArithmetic()
{
    printf("\tTesting arithmetics\n");

    //Dot product
    Vec2f tmp = m_4_2.dotprod(m_4_2);
    CPPUNIT_ASSERT( tmp[0] == 16.0f );
    CPPUNIT_ASSERT( tmp[1] == 4.0f );

    //length
    float length = m_4_2.length();
    CPPUNIT_ASSERT( length == Pandora::Math::Math<float>::Sqrt(20.0f) );
    length = tmp.length();
    CPPUNIT_ASSERT( length == Pandora::Math::Math<float>::Sqrt(272.0f) );

    //normalize
    tmp.normalize();
    CPPUNIT_ASSERT( tmp.length() == 1.0f );
}

void Vector2Test::testComparison()
{
    printf("\tTesting comparison\n");

    CPPUNIT_ASSERT( m_4_2 > m_1_1 );
    CPPUNIT_ASSERT( m_1_1 == m_1_1 );
    CPPUNIT_ASSERT( m_1_0 != m_0_1 );
    CPPUNIT_ASSERT( m_1_0 >= m_0_0 );
    CPPUNIT_ASSERT( m_0_0 < m_1_1 );
    CPPUNIT_ASSERT( m_1_0 <= m_1_1 );
}

void Vector2Test::testAssignment()
{
    printf("\tTesting assignment\n");

    CPPUNIT_ASSERT( m_1_1[0] == m_1_1[0] );
    CPPUNIT_ASSERT( m_1_1[1] == m_1_1[1] );
    CPPUNIT_ASSERT( m_4_2[1] == 2.0f );

    Vec2f tmp;
    float test[2] = {1.0f, 4.0f};
    tmp = &test[0];
    CPPUNIT_ASSERT( tmp[0] == 1.0f );
    CPPUNIT_ASSERT( tmp[1] == 4.0f );

    float *test2 = (float*) tmp;
    CPPUNIT_ASSERT( test2[0] == tmp[0] );
    CPPUNIT_ASSERT( test2[1] == tmp[1] );

    tmp = -m_4_2;
    CPPUNIT_ASSERT( tmp[0] == -m_4_2[0] );
    CPPUNIT_ASSERT( tmp[1] == -m_4_2[1] );
}

CppUnit::Test *Vector2Test::suite()
{
    CppUnit::TestSuite *testSuite = new CppUnit::TestSuite("Vector2Test");
    testSuite->addTest( new CppUnit::TestCaller<Vector2Test>(
                "Vector2Test::init",
                &Vector2Test::init ));
    testSuite->addTest( new CppUnit::TestCaller<Vector2Test>(
                "Vector2Test::testConstructor", 
                &Vector2Test::testConstructor ));
    testSuite->addTest( new CppUnit::TestCaller<Vector2Test>(
                "Vector2Test::testAddition",
                &Vector2Test::testAddition ));
    testSuite->addTest( new CppUnit::TestCaller<Vector2Test>(
                "Vector2Test::testSubtraction",
                &Vector2Test::testSubtraction ));
    testSuite->addTest( new CppUnit::TestCaller<Vector2Test>(
                "Vector2Test::testMultiplication",
                &Vector2Test::testMultiplication ));
    testSuite->addTest( new CppUnit::TestCaller<Vector2Test>(
                "Vector2Test::testArithmetic", 
                &Vector2Test::testArithmetic ));
    testSuite->addTest( new CppUnit::TestCaller<Vector2Test>(
                "Vector2Test::testComparison", 
                &Vector2Test::testComparison ));
    testSuite->addTest( new CppUnit::TestCaller<Vector2Test>(
                "Vector2Test::testAssignment", 
                &Vector2Test::testAssignment ));
    return testSuite;
}

void Vector2Test::setUp()
{
    m_1_1 = Vec2f(1.0f, 1.0f);
    m_1_0 = Vec2f();
    m_0_1 = Vec2f(0.0f, 1.0f);
    m_0_0 = Vec2f(0.0f, 0.0f);
    m_4_2 = Vec2f(4.0f, 2.0f);
}

void Vector2Test::tearDown()
{
}
