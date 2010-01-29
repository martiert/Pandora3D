/*
-------------------------------------------------------------------------------
File Name : Vector3Test.cpp

Purpose : The implementation of the Test class for 3D vectors.

Creation Date : 2010-01-28

Last Modified : fr. 29. jan. 2010 kl. 16.47 +0100

Created By :  Martin Ertsås
-------------------------------------------------------------------------------
*/

#include "Vector3Test.h"

void Vector3Test::init()
{
    printf("Starting Vector3Test\n");
}

void Vector3Test::testConstructor()
{
    printf("\tTesting constructors\n");

    CPPUNIT_ASSERT( m_1_1_1.x == 1.0f );
    CPPUNIT_ASSERT( m_1_1_1.y == 1.0f );
    CPPUNIT_ASSERT( m_1_1_1.z == 1.0f );

    CPPUNIT_ASSERT( m_2_4_1.x == 2.0f );
    CPPUNIT_ASSERT( m_2_4_1.y == 4.0f );
    CPPUNIT_ASSERT( m_2_4_1.z == 1.0f );

    CPPUNIT_ASSERT( m_1_0_0.x == 1.0f );
    CPPUNIT_ASSERT( m_1_0_0.y == 0.0f );
    CPPUNIT_ASSERT( m_1_0_0.z == 0.0f );

    Pandora::Math::Vector3<float> tmp(m_2_4_1);
    CPPUNIT_ASSERT( tmp.x == 2.0f );
    CPPUNIT_ASSERT( tmp.y == 4.0f );
    CPPUNIT_ASSERT( tmp.z == 1.0f );

    tmp.x = 3.0f;
    CPPUNIT_ASSERT( m_2_4_1.x == 2.0f );
}

void Vector3Test::testAssignment()
{
    printf("\tTesting assignment\n");

    float *tmp = (float*) m_2_4_1;
    const float *tmp2 = (const float*) m_2_4_1;

    CPPUNIT_ASSERT( tmp[0] == m_2_4_1.x );
    CPPUNIT_ASSERT( tmp[1] == m_2_4_1.y );
    CPPUNIT_ASSERT( tmp[2] == m_2_4_1.z );

    CPPUNIT_ASSERT( tmp2[0] == m_2_4_1.x );
    CPPUNIT_ASSERT( tmp2[1] == m_2_4_1.y );
    CPPUNIT_ASSERT( tmp2[2] == m_2_4_1.z );

    tmp[0] = 4.0f;
    CPPUNIT_ASSERT( m_2_4_1.x == 4.0f );
    CPPUNIT_ASSERT( tmp[0] == m_2_4_1.x );
    CPPUNIT_ASSERT( tmp2[0] == m_2_4_1.x );
}

void Vector3Test::testEquality()
{
    printf("\tTesting equality\n");

    Pandora::Math::Vector3<float> tmp(m_1_1_1);
    CPPUNIT_ASSERT( tmp == m_1_1_1 );
    CPPUNIT_ASSERT( m_1_1_1 != m_1_0_0 );
    CPPUNIT_ASSERT( m_1_1_1 >= m_1_0_0 );
    CPPUNIT_ASSERT( m_2_4_1 > m_1_0_0 );
    CPPUNIT_ASSERT( m_1_1_1 <= m_2_4_1 );
    CPPUNIT_ASSERT( m_1_0_0 < m_2_4_1 );

    CPPUNIT_ASSERT( !(m_1_1_1 < m_2_4_1) );
    CPPUNIT_ASSERT( !(m_1_1_1 > m_1_0_0) );
}

void Vector3Test::testArithmetic()
{
    printf("\tTesting arithmetic\n");

    Pandora::Math::Vector3<float> tmp = m_1_0_0 + m_1_1_1;
    CPPUNIT_ASSERT( tmp == Pandora::Math::Vector3<float>(2.0f, 1.0f, 1.0f) );

    tmp = m_1_1_1 - m_1_0_0;
    CPPUNIT_ASSERT( tmp == Pandora::Math::Vector3<float>(0.0f, 1.0f, 1.0f) );

    tmp = m_2_4_1 * 1.5f;
    CPPUNIT_ASSERT( tmp == Pandora::Math::Vector3<float>(3.0f, 6.0f, 1.5f) );

    tmp = m_2_4_1 / 2.0f;
    CPPUNIT_ASSERT( tmp == Pandora::Math::Vector3<float>(1.0f, 2.0f, 0.5f) );

    tmp = m_1_1_1;
    m_1_1_1 += m_1_0_0;
    CPPUNIT_ASSERT( m_1_1_1 == Pandora::Math::Vector3<float>(2.0f, 1.0f, 1.0f) );

    m_1_1_1 = tmp;
    m_1_1_1 -= m_2_4_1;
    CPPUNIT_ASSERT( m_1_1_1 == Pandora::Math::Vector3<float>(-1.0f, -3.0f, 0.0f) );

    tmp = m_2_4_1;
    m_2_4_1 *= 1.5f;
    CPPUNIT_ASSERT( m_2_4_1 == Pandora::Math::Vector3<float>(3.0f, 6.0f, 1.5f) );

    m_2_4_1 = tmp;
    m_2_4_1 /= 2.0f;
    CPPUNIT_ASSERT( m_2_4_1 == Pandora::Math::Vector3<float>(1.0f, 2.0f, 0.5f) );
}

void Vector3Test::testGeometry()
{
    printf("\tTesting geometry\n");

    Pandora::Math::Vector3<float> tmp = m_2_4_1;
    CPPUNIT_ASSERT( m_1_0_0.length() == 1.0f );
    CPPUNIT_ASSERT( m_1_1_1.lengthSquared() == 3.0f );
    CPPUNIT_ASSERT( m_1_1_1.length() == Pandora::Math::Math<float>::Sqrt(3.0f) );
    CPPUNIT_ASSERT( tmp.normalizeChecked() );

    tmp = Pandora::Math::Vector3<float>(0.0f, 0.0f, 0.0f);
    CPPUNIT_ASSERT( tmp.length() == 0.0f );
    CPPUNIT_ASSERT( !tmp.normalizeChecked() );
    CPPUNIT_ASSERT( tmp.lengthSquared() == 0.0f );

    tmp = m_2_4_1.cross(m_2_4_1);
    CPPUNIT_ASSERT( tmp.x == 0.0f );
    CPPUNIT_ASSERT( tmp.y == 0.0f );
    CPPUNIT_ASSERT( tmp.z == 0.0f );

    tmp = m_1_1_1.cross(m_2_4_1);
    CPPUNIT_ASSERT( tmp.x == -3.0f );
    CPPUNIT_ASSERT( tmp.y == 1.0f );
    CPPUNIT_ASSERT( tmp.z == 2.0f );
}

CppUnit::Test *Vector3Test::suite()
{
    CppUnit::TestSuite *testSuite = new CppUnit::TestSuite("Vector3Test");

    testSuite->addTest( new CppUnit::TestCaller<Vector3Test>(
                "Vector3Test::init",
                &Vector3Test::init ));
    testSuite->addTest( new CppUnit::TestCaller<Vector3Test>(
                "Vector3Test::testConstructor",
                &Vector3Test::testConstructor ));
    testSuite->addTest( new CppUnit::TestCaller<Vector3Test>(
                "Vector3Test::testAssignment",
                &Vector3Test::testAssignment ));
    testSuite->addTest( new CppUnit::TestCaller<Vector3Test>(
                "Vector3Test::testEquality",
                &Vector3Test::testEquality ));
    testSuite->addTest( new CppUnit::TestCaller<Vector3Test>(
                "Vector3Test::testArithmetic",
                &Vector3Test::testArithmetic ));
    testSuite->addTest( new CppUnit::TestCaller<Vector3Test>(
                "Vector3Test::testGeometry",
                &Vector3Test::testGeometry ));

    return testSuite;
}

void Vector3Test::setUp()
{
    float tmp[3] = {2.0f, 4.0f, 1.0f};
    m_1_1_1 = Pandora::Math::Vector3<float>(1.0f, 1.0f, 1.0f);
    m_2_4_1 = Pandora::Math::Vector3<float>(tmp);
    m_1_0_0 = Pandora::Math::Vector3<float>();
}

void Vector3Test::tearDown()
{
}
