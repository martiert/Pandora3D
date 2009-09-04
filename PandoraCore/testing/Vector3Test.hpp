#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>

#include "../include/PandoraVector3.hpp"

class Vector3Test : public CppUnit::TestFixture
{
    public:
        void setUp()
        {
            m_1_1_1 = Pandora::Vector3<float>(1,1,1);
            m_1_1_0 = Pandora::Vector3<float>(1,1,0);
            m_1_0_0 = Pandora::Vector3<float>(1,0,0);
        }

        void testCompare()
        {
            CPPUNIT_ASSERT( m_1_1_1 == Pandora::Vector3<float>(1,1,1) );
            CPPUNIT_ASSERT( !(m_1_1_1 == m_1_1_0) );

            CPPUNIT_ASSERT( m_1_1_1 != m_1_1_0 );
            CPPUNIT_ASSERT( !(m_1_1_1 != m_1_1_1) );
        }

        void testArithmetic()
        {
        }

        void testAssign()
        {
            CPPUNIT_ASSERT( m_1_0_0[0] == 1 );
            CPPUNIT_ASSERT( m_1_0_0[1] == 0 );
            CPPUNIT_ASSERT( m_1_0_0[2] == 0 );

            /*
            float* m = (float*) m_1_0_0;
            CPPUNIT_ASSERT( m[0] == 1 );
            CPPUNIT_ASSERT( m[1] == 0 );
            CPPUNIT_ASSERT( m[2] == 0 );

            m[1] = 3;
            CPPUNIT_ASSERT( m_1_0_0[1] == 3 );
            m[1] = 0;*/
        }

        void testGeometric()
        {
        }

        void tearDown()
        {
        }

        static CppUnit::Test *suite()
        {
            CppUnit::TestSuite *suite = new CppUnit::TestSuite("Vector3Test");

            suite->addTest( new CppUnit::TestCaller<Vector3Test>(
                        "testCompare",
                        &Vector3Test::testCompare));   

            suite->addTest( new CppUnit::TestCaller<Vector3Test>(
                        "testArithmetic",
                        &Vector3Test::testArithmetic));

            suite->addTest( new CppUnit::TestCaller<Vector3Test>(
                        "testAssignment",
                        &Vector3Test::testAssign));

            suite->addTest( new CppUnit::TestCaller<Vector3Test>(
                        "testGeometric",
                        &Vector3Test::testGeometric));

            return suite;
        }
    private:
        Pandora::Vector3<float> m_1_1_1, m_1_1_0, m_1_0_0;
};
