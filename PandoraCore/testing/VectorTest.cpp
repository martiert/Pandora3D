#include <cppunit/TestFixture.h>
#include <cppunit/Asserter.h>
#include <string>

#include "../include/PandoraVector2.hpp"

class Vector2Test : public CppUnit::TestFixture
{
    public:
        void setUp()
        {
            m_1_1 = new Pandora::Vector2<float>(1,1);
            m_1_0 = new Pandora::Vector2<float>(1,0);
            m_0_1 = new Pandora::Vector2<float>(0,1);
            m_10_2 = new Pandora::Vector2<float>(10,2);
        }

        void testEqual()
        {
            CPPUNIT_ASSERT(m_1_1 == m_1_1);
            CPPUNIT_ASSERT(!(m_1_1 == m_1_0));
        }

        void tearDown()
        {
            delete m_1_1;
            delete m_1_0;
            delete m_0_1;
            delete m_10_2;
        }
    private:
        Pandora::Vector2<float> *m_1_1, *m_1_0, *m_0_1, *m_10_2;
};

int main()
{
    Vector2Test test;
    test.setUp();
    test.testEqual();
    test.tearDown();
}
