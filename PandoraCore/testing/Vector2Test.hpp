#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestCaller.h>

#include "../include/PandoraVector2.hpp"

class Vector2Test : public CppUnit::TestFixture
{
    public:
        void setUp()
        {
            m_1_1 = Pandora::Vector2<float>(1,1);
            m_1_0 = Pandora::Vector2<float>();
            m_0_1 = Pandora::Vector2<float>(0,1);
            m_10_2 =Pandora::Vector2<float>(10,2);
        }

        void testEqual()
        {
            CPPUNIT_ASSERT(m_1_1 == m_1_1);
            CPPUNIT_ASSERT(! (m_1_1 == m_0_1) );
        }

        void testDiff()
        {
            CPPUNIT_ASSERT(m_1_1 != m_0_1);
            CPPUNIT_ASSERT(! (m_1_1 != m_1_1) );
        }

        void testAdd()
        {
            CPPUNIT_ASSERT( (m_1_0 + m_0_1) == m_1_1 );
            CPPUNIT_ASSERT( (m_1_0 + m_1_1) != m_10_2 );
        }

        void testSub()
        {
            CPPUNIT_ASSERT( (m_1_1 - m_1_0) == m_0_1 );
            CPPUNIT_ASSERT( (m_1_1 - m_1_0) != m_1_1 );
        }

        void testAddSubTo()
        {
            m_1_0 += m_0_1;
            CPPUNIT_ASSERT( m_1_0 == m_1_1 );
            m_1_0 -= m_0_1;
            CPPUNIT_ASSERT( m_1_0 == Pandora::Vector2<float>(1,0) );
        }

        void tearDown()
        {
        }

        static CppUnit::Test *suite()
        {
            CppUnit::TestSuite *suite = new CppUnit::TestSuite("Vector2Test");

            suite->addTest( new CppUnit::TestCaller<Vector2Test>(
                        "testEqual",
                        &Vector2Test::testEqual));
            suite->addTest( new CppUnit::TestCaller<Vector2Test>(
                        "testDiff",
                        &Vector2Test::testDiff));
            suite->addTest( new CppUnit::TestCaller<Vector2Test>(
                        "testAdd",
                        &Vector2Test::testAdd));
            suite->addTest( new CppUnit::TestCaller<Vector2Test>(
                        "testSub",
                        &Vector2Test::testSub));
            suite->addTest( new CppUnit::TestCaller<Vector2Test>(
                        "testAddSubTo",
                        &Vector2Test::testAddSubTo));

            return suite;
        }
    private:
        Pandora::Vector2<float> m_1_1, m_1_0, m_0_1, m_10_2;
};
