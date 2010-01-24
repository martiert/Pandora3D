/*
-------------------------------------------------------------------------------
File Name : Vector2Test.cpp

Purpose : Unit testing of the Pandora::Math::Vec2 implementation.

Creation Date : 2010-01-19

Last Modified : sø. 24. jan. 2010 kl. 22.56 +0100

Created By :  Martin Ertsås
-------------------------------------------------------------------------------
*/

#include "Vector2Test.h"

using Pandora::Math::Vec2f;

void Vector2Test::testConstructor()
{
    CPPUNIT_ASSERT( m_1_0.x == 1.0f );
    CPPUNIT_ASSERT( m_1_0.y == 0.0f );
    CPPUNIT_ASSERT( m_0_0.x == 0.0f );
    CPPUNIT_ASSERT( m_0_0.y == 0.0f );
    CPPUNIT_ASSERT( m_0_1.x == 0.0f );
    CPPUNIT_ASSERT( m_0_1.y == 1.0f );

    Vec2f tmp(m_1_0);
    CPPUNIT_ASSERT( tmp.x == m_1_0.x );
    CPPUNIT_ASSERT( tmp.y == m_1_0.y );

    float test[] = {1.0f, 4.0f};
    Vec2f tmp2(&test[0]);
    CPPUNIT_ASSERT( tmp2.x == test[0] );
    CPPUNIT_ASSERT( tmp2.y == test[1] );
}

void Vector2Test::testAddition()
{
    Vec2f tmp = m_1_0 + m_0_0;
    CPPUNIT_ASSERT( tmp.x == m_1_0.x );
    CPPUNIT_ASSERT( tmp.y == m_1_0.y );

    tmp = m_1_0 + m_0_1;
    CPPUNIT_ASSERT( tmp.x == m_1_1.x );
    CPPUNIT_ASSERT( tmp.y == m_1_1.y );

    tmp += m_1_0;
    CPPUNIT_ASSERT( tmp.x == 2.0f );
    CPPUNIT_ASSERT( tmp.y == 1.0f );
}

void Vector2Test::testSubtraction()
{
    Vec2f tmp = m_4_2 - m_1_1;
    CPPUNIT_ASSERT( tmp.x == 3.0f );
    CPPUNIT_ASSERT( tmp.y == 1.0f );

    tmp -= m_1_1;
    CPPUNIT_ASSERT( tmp.x == 2.0f );
    CPPUNIT_ASSERT( tmp.y == 0.0f );
}

void Vector2Test::testMultiplication()
{
    float tmp = m_4_2 * m_1_1;
    CPPUNIT_ASSERT( tmp == 6.0f );

    Vec2f tmp2 = m_4_2 * 2.5f;
    CPPUNIT_ASSERT( tmp2.x == 10.0f );
    CPPUNIT_ASSERT( tmp2.y == 5.0f );

    tmp2 /= 2.5f;
    CPPUNIT_ASSERT( tmp2.x == 4.0f );
    CPPUNIT_ASSERT( tmp2.y == 2.0f );

    tmp2 = m_4_2 / 2.0f;
    CPPUNIT_ASSERT( tmp2.x == 2.0f );
    CPPUNIT_ASSERT( tmp2.y == 1.0f );

    tmp2 *= 2.0f;
    CPPUNIT_ASSERT( tmp2.x == 4.0f );
    CPPUNIT_ASSERT( tmp2.y == 2.0f );

    tmp2 *= m_1_0;
    CPPUNIT_ASSERT( tmp2.x == 4.0f );
    CPPUNIT_ASSERT( tmp2.y == 0.0f );

    tmp2 = m_4_2.dotprod(m_0_1);
    CPPUNIT_ASSERT( tmp2.x == 0.0f );
    CPPUNIT_ASSERT( tmp2.y == 2.0f );
}

void Vector2Test::testArritmetic()
{

}

void Vector2Test::testComparsion()
{
}

void Vector2Test::testAssignment()
{
}

CppUnit::Test *Vector2Test::suite()
{
    CppUnit::TestSuite *testSuite = new CppUnit::TestSuite("Vector2Test");
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
                "Vector2Test::testArritmetic", 
                &Vector2Test::testArritmetic ));
    testSuite->addTest( new CppUnit::TestCaller<Vector2Test>(
                "Vector2Test::testComparsion", 
                &Vector2Test::testComparsion ));
    testSuite->addTest( new CppUnit::TestCaller<Vector2Test>(
                "Vector2Test::testAssignment", 
                &Vector2Test::testComparsion ));
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
