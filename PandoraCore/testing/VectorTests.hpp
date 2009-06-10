#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

class VectorTests : public CppUnit::TestCase
{
    CPPUNIT_TEST_SUIT(VectorTests);
    CPPUNIT_TEST(testVector2);
    CPPUNIT_TEST(testVector3);
    CPPUNIT_TEST(testVectro4);
    public:
        void setUp();
        void tearDown();
        void testVector2();
        void testVector3();
        void testVector4();
};
