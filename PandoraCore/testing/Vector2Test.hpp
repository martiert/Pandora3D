#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestSuite.h>
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

        void testCompare()
        {
            //Test of operator==
            CPPUNIT_ASSERT(m_1_1 == m_1_1);
            CPPUNIT_ASSERT(! (m_1_1 == m_0_1) );

            //Test of operator!=
            CPPUNIT_ASSERT(m_1_1 != m_0_1);
            CPPUNIT_ASSERT(! (m_1_1 != m_1_1) );
        }

        void testArithmetic()
        {
            //Test of operator+
            CPPUNIT_ASSERT( (m_1_0 + m_0_1) == m_1_1 );
            CPPUNIT_ASSERT( (m_1_0 + m_1_1) != m_10_2 );

            //Test of operator-
            CPPUNIT_ASSERT( (m_1_1 - m_1_0) == m_0_1 );
            CPPUNIT_ASSERT( (m_1_1 - m_1_0) != m_1_1 );

            //Test of operator+= and operator-=
            m_1_0 += m_0_1;
            CPPUNIT_ASSERT( m_1_0 == m_1_1 );
            m_1_0 -= m_0_1;
            CPPUNIT_ASSERT( m_1_0 == Pandora::Vector2<float>(1,0) );

            //Test of operator*
            CPPUNIT_ASSERT( m_1_0 * m_0_1 == 0.0f );
            CPPUNIT_ASSERT( m_1_0 * m_10_2 == 10.0f );

            //Test of operator*
            CPPUNIT_ASSERT( m_1_0 * 2 == Pandora::Vector2<float>(2,0) );
            CPPUNIT_ASSERT( m_0_1 * 2 == Pandora::Vector2<float>(0,2) );
            CPPUNIT_ASSERT( m_1_1 * 4 == Pandora::Vector2<float>(4,4) );

            //Test of operator/
            CPPUNIT_ASSERT( m_1_0 / 2 == Pandora::Vector2<float>(0.5, 0) );
            CPPUNIT_ASSERT( m_0_1 / 2 == Pandora::Vector2<float>(0, 0.5) );
            CPPUNIT_ASSERT( m_1_1 / 4 == Pandora::Vector2<float>(0.25, 0.25) );
        }

        void testAssign()
        {        
            //Test of operator[]
            CPPUNIT_ASSERT( m_1_0[0] == 1 );
            CPPUNIT_ASSERT( m_1_0[1] == 0 );

            //Test of operator Real*
            float *m = (float*)m_1_0;
            CPPUNIT_ASSERT( m[0] == 1 );
            CPPUNIT_ASSERT( m[1] == 0 );
        
            //Test of operator-
            CPPUNIT_ASSERT( -m_1_0 == Pandora::Vector2<float>(-1, 0) );
            CPPUNIT_ASSERT( -m_0_1 == Pandora::Vector2<float>(0, -1) );
            CPPUNIT_ASSERT( -m_1_1 == Pandora::Vector2<float>(-1, -1) );
        }

        void testGeometric()
        {
            //Test of length
            CPPUNIT_ASSERT( m_1_0.length() == 1);
            CPPUNIT_ASSERT( m_0_1.length() == 1);

            //Test of squaredLength
            CPPUNIT_ASSERT( m_1_0.squaredLength() == 1 );
            CPPUNIT_ASSERT( m_0_1.squaredLength() == 1 );
            CPPUNIT_ASSERT( m_1_1.squaredLength() == 2 );

            //Test of dot product
            CPPUNIT_ASSERT( m_1_0.dot(m_0_1) == 0.0f );
            CPPUNIT_ASSERT( m_1_0.dot(m_10_2) == 10.0f );

            //Test of normalize
            m_1_1.normalize();
            CPPUNIT_ASSERT( m_1_1.length() < 1.0f + 0.0000001 && m_1_1.length() > 1.0f - 0.0000001 );
            m_1_1 = Pandora::Vector2<float>(1,1);

            //Test of perp
            CPPUNIT_ASSERT( m_1_1.perp() == Pandora::Vector2<float>(1, -1) );
            CPPUNIT_ASSERT( m_1_0.perp() == Pandora::Vector2<float>(0, -1) );
            CPPUNIT_ASSERT( m_0_1.perp() == m_1_0 );
        }

        void tearDown()
        {
        }

        static CppUnit::Test *suite()
        {
            CppUnit::TestSuite *suite = new CppUnit::TestSuite("Vector2Test");

            suite->addTest( new CppUnit::TestCaller<Vector2Test>(
                        "testCompare",
                        &Vector2Test::testCompare));   

            suite->addTest( new CppUnit::TestCaller<Vector2Test>(
                        "testArithmetic",
                        &Vector2Test::testArithmetic));

            suite->addTest( new CppUnit::TestCaller<Vector2Test>(
                        "testAssignment",
                        &Vector2Test::testAssign));


            suite->addTest( new CppUnit::TestCaller<Vector2Test>(
                        "testGeometric",
                        &Vector2Test::testGeometric));

            return suite;
        }
    private:
        Pandora::Vector2<float> m_1_1, m_1_0, m_0_1, m_10_2;
};
