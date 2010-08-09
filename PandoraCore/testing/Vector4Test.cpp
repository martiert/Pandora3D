/*
-------------------------------------------------------------------------------
File Name : Vector4Test.cpp

Purpose :

Creation Date : 2010-02-04

Last Modified : ti. 06. juli 2010 kl. 11.38 +0200

Created [1] :  Martin Ertsås
-------------------------------------------------------------------------------
*/

#include "Vector4Test.h"

using Pandora::Math::Vector4;

void Vector4Test::init()
{
    printf("Starting Vector4Test\t\n");
}

void Vector4Test::testConstructor()
{
    printf("\tTesting constructors\n");

    CPPUNIT_ASSERT( m_1[0] == 1.0f );
    CPPUNIT_ASSERT( m_1[1] == 0.0f );
    CPPUNIT_ASSERT( m_1[2] == 0.0f );
    CPPUNIT_ASSERT( m_1[3] == 0.0f );

    CPPUNIT_ASSERT( m_2[0] == 1.0f );
    CPPUNIT_ASSERT( m_2[1] == 1.0f );
    CPPUNIT_ASSERT( m_2[2] == 1.0f );
    CPPUNIT_ASSERT( m_2[3] == 1.0f );

    CPPUNIT_ASSERT( m_3[0] == 3.0f );
    CPPUNIT_ASSERT( m_3[1] == 4.0f );
    CPPUNIT_ASSERT( m_3[2] == 10.1f );
    CPPUNIT_ASSERT( m_3[3] == 8.9f );

    m_4 = Vector4<float>(m_3);
    CPPUNIT_ASSERT( m_4[0] == 3.0f );
    CPPUNIT_ASSERT( m_4[1] == 4.0f );
    CPPUNIT_ASSERT( m_4[2] == 10.1f );
    CPPUNIT_ASSERT( m_4[3] == 8.9f );
}

void Vector4Test::testAssignment()
{
    printf("\tTesting assignment\n");
    float *real = (float*) m_4;
    CPPUNIT_ASSERT( real[0] == m_4[0] );
    CPPUNIT_ASSERT( real[1] == m_4[1] );
    CPPUNIT_ASSERT( real[2] == m_4[2] );
    CPPUNIT_ASSERT( real[3] == m_4[3] );

    real[2] = 1.0f;
    CPPUNIT_ASSERT( real[2] == m_4[2] );
    CPPUNIT_ASSERT( m_4[2] == 1.0f );
    real[2] = 10.1f;

    CPPUNIT_ASSERT( m_4[0] == m_4[0] );
    CPPUNIT_ASSERT( m_4[1] == m_4[1] );
    CPPUNIT_ASSERT( m_4[0] == real[0] );
    CPPUNIT_ASSERT( m_4[2] == m_4[2] );
    CPPUNIT_ASSERT( m_4[3] == m_4[3] );

    m_4[2] = 1.0f;
    CPPUNIT_ASSERT( m_4[2] == 1.0f );
    CPPUNIT_ASSERT( m_4[2] == real[2] );
    CPPUNIT_ASSERT( m_4[2] == real[2] );
    CPPUNIT_ASSERT( m_4[0] == real[0] );
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
    CPPUNIT_ASSERT( tmp[0] == 4.0f );
    CPPUNIT_ASSERT( tmp[1] == 5.0f );
    CPPUNIT_ASSERT( tmp[2] == 11.1f );
    CPPUNIT_ASSERT( tmp[3] == 9.9f );

    tmp = -m_3;
    CPPUNIT_ASSERT( tmp[0] == -3.0f );
    CPPUNIT_ASSERT( tmp[1] == -4.0f );
    CPPUNIT_ASSERT( tmp[2] == -10.1f );
    CPPUNIT_ASSERT( tmp[3] == -8.9f );

    tmp = m_4 - m_2;
    CPPUNIT_ASSERT( tmp[0] == -1.0f );
    CPPUNIT_ASSERT( tmp[1] == -1.0f );
    CPPUNIT_ASSERT( tmp[2] == 0.0f );
    CPPUNIT_ASSERT( tmp[3] == 0.0f );

    tmp = m_3 * 2.0f;
    CPPUNIT_ASSERT( tmp[0] == 6.0f );
    CPPUNIT_ASSERT( tmp[1] == 8.0f );
    CPPUNIT_ASSERT( tmp[2] == 20.2f );
    CPPUNIT_ASSERT( tmp[3] == 17.8f );

    tmp = m_3 / 2.0f;
    CPPUNIT_ASSERT( tmp[0] == 1.5f );
    CPPUNIT_ASSERT( tmp[1] == 2.0f );
    CPPUNIT_ASSERT( tmp[2] == 5.05f );
    CPPUNIT_ASSERT( tmp[3] == 4.45f );

    tmp *= 2.0f;
    CPPUNIT_ASSERT( tmp[0] == m_3[0] );
    CPPUNIT_ASSERT( tmp[1] == m_3[1] );
    CPPUNIT_ASSERT( tmp[2] == m_3[2] );
    CPPUNIT_ASSERT( tmp[3] == m_3[3] );

    tmp += m_2;
    CPPUNIT_ASSERT( tmp[0] == 4.0f );
    CPPUNIT_ASSERT( tmp[1] == 5.0f );
    CPPUNIT_ASSERT( tmp[2] == 11.1f );
    CPPUNIT_ASSERT( tmp[3] == 9.9f );

    tmp -= m_1;
    CPPUNIT_ASSERT( tmp[0] == 3.0f );
    CPPUNIT_ASSERT( tmp[1] == 5.0f );
    CPPUNIT_ASSERT( tmp[2] == 11.1f );
    CPPUNIT_ASSERT( tmp[3] == 9.9f );

    tmp /= 2.0f;
    CPPUNIT_ASSERT( tmp[0] == 1.5f );
    CPPUNIT_ASSERT( tmp[1] == 2.5f );
    CPPUNIT_ASSERT( tmp[2] == 5.55f );
    CPPUNIT_ASSERT( tmp[3] == 4.95f );

    float tmp2 = m_2 * m_3;
    CPPUNIT_ASSERT( tmp2 == 26.0f );
}

void Vector4Test::testComparison()
{
    printf("\tTesting Comparison\n");

    CPPUNIT_ASSERT( m_2 < m_3 );
    CPPUNIT_ASSERT( m_2 == m_2 );
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
