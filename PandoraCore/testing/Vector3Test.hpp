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
        }

        void testCompare()
        {
        }

        void testArithmetic()
        {
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

            suite->addTest( new CppUnit::TestCaller<Vector2Test>(
                        "testCompare",
                        &Vector2Test::testCompare));   

            suite->addTest( new CppUnit::TestCaller<Vector2Test>(
                        "testArithmetic",
                        &Vector2Test::testArithmetic));

            suite->addTest( new CppUnit::TestCaller<Vector2Test>(
                        "testGeometric",
                        &Vector2Test::testGeometric));

            return suite;
        }
    private:
};
