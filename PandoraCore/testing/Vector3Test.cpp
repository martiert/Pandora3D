/*
-------------------------------------------------------------------------------
File Name : Vector3Test.cpp

Purpose : The implementation of the Test class for 3D vectors.

Creation Date : 2010-01-28

Last Modified : fr. 29. jan. 2010 kl. 00.58 +0100

Created By :  Martin Ertsås
-------------------------------------------------------------------------------
*/

#include "Vector3Test.h"

void Vector3Test::init()
{
    printf("Testing Vector3\n");
}

void Vector3Test::testConstructor()
{
    printf("\tTesting constructors\n");

    CPPUNIT_ASSERT( m_1_1_1->x == 1.0f );
    CPPUNIT_ASSERT( m_1_1_1->y == 1.0f );
    CPPUNIT_ASSERT( m_1_1_1->z == 1.0f );

    CPPUNIT_ASSERT( m_2_4_1->x == 2.0f );
    CPPUNIT_ASSERT( m_2_4_1->y == 4.0f );
    CPPUNIT_ASSERT( m_2_4_1->z == 1.0f );

    CPPUNIT_ASSERT( m_1_0_0->x == 1.0f );
    CPPUNIT_ASSERT( m_1_0_0->y == 0.0f );
    CPPUNIT_ASSERT( m_1_0_0->z == 0.0f );

    Pandora::Math::Vec3<float> tmp(*m_2_4_1);
    CPPUNIT_ASSERT( tmp.x == 2.0f );
    CPPUNIT_ASSERT( tmp.y == 4.0f );
    CPPUNIT_ASSERT( tmp.z == 1.0f );

    tmp.x = 3.0f;
    CPPUNIT_ASSERT( m_2_4_1->x == 2.0f );
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
    return testSuite;
}

void Vector3Test::setUp()
{
    float tmp[3] = {2.0f, 4.0f, 1.0f};
    m_1_1_1 = new Pandora::Math::Vec3<float>(1.0f, 1.0f, 1.0f);
    m_2_4_1 = new Pandora::Math::Vec3<float>(tmp);
    m_1_0_0 = new Pandora::Math::Vec3<float>();
}

void Vector3Test::tearDown()
{
    delete m_1_1_1;
    delete m_2_4_1;
    delete m_1_0_0;
}
