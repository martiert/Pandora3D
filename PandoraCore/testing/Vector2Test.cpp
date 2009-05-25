#include <cppunit/TestFixture.h>
#include <string>

namespace Pandora
{
    class Vector2Test : public CppUnit::TestCase
    {
        public:
            Vector2Test(std::string name) : CppUnit::TestCase(name) { }

            void runTest()
            {
                CPPUNIT_ASSERT(true);
            }
    };
}

int main()
{
    std::string name = "Vector2Test";
    Pandora::Vector2Test test(name);
//    test.runTest();

    return 0;
}
