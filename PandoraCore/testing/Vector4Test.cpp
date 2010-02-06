/*
-------------------------------------------------------------------------------
File Name : Vector4Test.cpp

Purpose :

Creation Date : 2010-02-04

Last Modified : sø. 07. feb. 2010 kl. 00.24 +0100

Created By :  Martin Ertsås
-------------------------------------------------------------------------------
*/

#include "Vector4Test.h"

using Pandora::Math::Vector4;

void Vector4Test::init()
{
    printf("Starting Vector4Test\n");
}

void Vector4Test::testConstructor()
{
    printf("\tTesting constructors\n");

    CPPUNIT_ASSERT( m_1.x == 1.0f );
    CPPUNIT_ASSERT( m_1.y == 0.0f );
    CPPUNIT_ASSERT( m_1.z == 0.0f );
    CPPUNIT_ASSERT( m_1.w == 0.0f );

    CPPUNIT_ASSERT( m_2.x == 1.0f );
    CPPUNIT_ASSERT( m_2.y == 1.0f );
    CPPUNIT_ASSERT( m_2.z == 1.0f );
    CPPUNIT_ASSERT( m_2.w == 1.0f );

    CPPUNIT_ASSERT( m_3.x == 3.0f );
    CPPUNIT_ASSERT( m_3.y == 4.0f );
    CPPUNIT_ASSERT( m_3.z == 10.1f );
    CPPUNIT_ASSERT( m_3.w == 8.9f );

    m_4 = Vector4<float>(m_3);
    CPPUNIT_ASSERT( m_4.x == 3.0f );
    CPPUNIT_ASSERT( m_4.y == 4.0f );
    CPPUNIT_ASSERT( m_4.z == 10.1f );
    CPPUNIT_ASSERT( m_4.w == 8.9f );
}

void Vector4Test::testAssignment()
{
    printf("\tTesting assignment\n");
    float *real = (float*) m_4;
    CPPUNIT_ASSERT( real[0] == m_4.x );
    CPPUNIT_ASSERT( real[1] == m_4.y );
    CPPUNIT_ASSERT( real[2] == m_4.z );
    CPPUNIT_ASSERT( real[3] == m_4.w );

    real[2] = 1.0f;
    CPPUNIT_ASSERT( real[2] == m_4.z );
    CPPUNIT_ASSERT( m_4.z == 1.0f );
    real[2] = 10.1f;

    CPPUNIT_ASSERT( m_4[0] == m_4.x );
    CPPUNIT_ASSERT( m_4[1] == m_4.y );
    CPPUNIT_ASSERT( m_4[0] == real[0] );
    CPPUNIT_ASSERT( m_4[2] == m_4.z );
    CPPUNIT_ASSERT( m_4[3] == m_4.w );

    m_4[2] = 1.0f;
    CPPUNIT_ASSERT( m_4.z == 1.0f );
    CPPUNIT_ASSERT( m_4[2] == real[2] );
    CPPUNIT_ASSERT( m_4.z == real[2] );
    CPPUNIT_ASSERT( m_4.x == real[0] );
    m_4[2] = 10.1f;

    float test = m_4[2];
    test = 2.0f;
    CPPUNIT_ASSERT( m_4[2] != test );

    const float *tmp2 = (const float*) m_4;
    CPPUNIT_ASSERT( m_4[1] == tmp2[1] );
    
    m_4 = m_1;
    CPPUNIT_ASSERT( m_4[0] == m_1[0] );
    CPPUNIT_ASSERT( m_4[1] == m_1[1] );
    CPPUNIT_ASSERT( m_4[2] == m_1[2] );
    CPPUNIT_ASSERT( m_4[3] == m_1[3] );

    float tmp3[] = {0.1f, 2.0f, 4.0f, 3.1f};
    m_4 = tmp3;
    CPPUNIT_ASSERT( m_4[0] != m_1[0] );
    CPPUNIT_ASSERT( m_4[0] == 0.1f );
    CPPUNIT_ASSERT( m_4[1] == 2.0f );
    CPPUNIT_ASSERT( m_4[2] == 4.0f );
    CPPUNIT_ASSERT( m_4[3] == 3.1f );
}

void Vector4Test::testArithmetic()
{
    printf("\tTesting arithmetic\n");

    Vector4<float> tmp = m_2 + m_3;
    CPPUNIT_ASSERT( tmp.x == 4.0f );
    CPPUNIT_ASSERT( tmp.y == 5.0f );
    CPPUNIT_ASSERT( tmp.z == 11.1f );
    CPPUNIT_ASSERT( tmp.w == 9.9f );

    tmp = -m_3;
    CPPUNIT_ASSERT( tmp.x == -3.0f );
    CPPUNIT_ASSERT( tmp.y == -4.0f );
    CPPUNIT_ASSERT( tmp.z == -10.1f );
    CPPUNIT_ASSERT( tmp.w == -8.9f );

    tmp = m_4 - m_2;
    CPPUNIT_ASSERT( tmp.x == -1.0f );
    CPPUNIT_ASSERT( tmp.y == -1.0f );
    CPPUNIT_ASSERT( tmp.z == 0.0f );
    CPPUNIT_ASSERT( tmp.w == 0.0f );

    tmp = m_3 * 2.0f;
    CPPUNIT_ASSERT( tmp.x == 6.0f );
    CPPUNIT_ASSERT( tmp.y == 8.0f );
    CPPUNIT_ASSERT( tmp.z == 20.2f );
    CPPUNIT_ASSERT( tmp.w == 17.8f );

    tmp = m_3 / 2.0f;
    CPPUNIT_ASSERT( tmp.x == 1.5f );
    CPPUNIT_ASSERT( tmp.y == 2.0f );
    CPPUNIT_ASSERT( tmp.z == 5.05f );
    CPPUNIT_ASSERT( tmp.w == 4.45f );

    tmp *= 2.0f;
    CPPUNIT_ASSERT( tmp.x == m_3.x );
    CPPUNIT_ASSERT( tmp.y == m_3.y );
    CPPUNIT_ASSERT( tmp.z == m_3.z );
    CPPUNIT_ASSERT( tmp.w == m_3.w );

    tmp += m_2;
    CPPUNIT_ASSERT( tmp.x == 4.0f );
    CPPUNIT_ASSERT( tmp.y == 5.0f );
    CPPUNIT_ASSERT( tmp.z == 11.1f );
    CPPUNIT_ASSERT( tmp.w == 9.9f );

    tmp -= m_1;
    CPPUNIT_ASSERT( tmp.x == 3.0f );
    CPPUNIT_ASSERT( tmp.y == 5.0f );
    CPPUNIT_ASSERT( tmp.z == 11.1f );
    CPPUNIT_ASSERT( tmp.w == 9.9f );

    tmp /= 2.0f;
    CPPUNIT_ASSERT( tmp.x == 1.5f );
    CPPUNIT_ASSERT( tmp.y == 2.5f );
    CPPUNIT_ASSERT( tmp.z == 5.55f );
    CPPUNIT_ASSERT( tmp.w == 4.95f );

    float tmp2 = m_2 * m_3;
    CPPUNIT_ASSERT( tmp2 == 26.0f );
}

void Vector4Test::testComparison()
{
    printf("\tTesting Comparison\n");
}

void Vector4Test::testGeometry()
{
    printf("\tTesting Geometry\n");
}

CppUnit::Test *Vector4Test::suite()
{
    CppUnit::TestSuite *testSuite = new CppUnit::TestSuite("Vector4Test");

    testSuite->addTest( new CppUnit::TestCaller<Vector4Test>(
                "Vector4Test::init",
                &Vector4Test::init ));
    testSuite->addTest( new CppUnit::TestCaller<Vector4Test>(
                "Vector4Test::testConstructor",
                &Vector4Test::testConstructor ));
    testSuite->addTest( new CppUnit::TestCaller<Vector4Test>(
                "Vector4Test::testAssignment",
                &Vector4Test::testAssignment ));
    testSuite->addTest( new CppUnit::TestCaller<Vector4Test>(
                "Vector4Test::testArithmetic",
                &Vector4Test::testArithmetic ));
    testSuite->addTest( new CppUnit::TestCaller<Vector4Test>(
                "Vector4Test::testComparison",
                &Vector4Test::testComparison ));
    testSuite->addTest( new CppUnit::TestCaller<Vector4Test>(
                "Vector4test::testGeometry",
                &Vector4Test::testGeometry ));

    return testSuite;
}

void Vector4Test::setUp()
{
    float tmp[] = {3.0f, 4.0f, 10.1f, 8.9f};
    m_2 = Vector4<float>(1.0f, 1.0f, 1.0f, 1.0f);
    m_3 = Vector4<float>(tmp);
    m_4 = Vector4<float>(0.0f, 0.0f, 1.0f, 1.0f);
}

void Vector4Test::tearDown()
{
}
