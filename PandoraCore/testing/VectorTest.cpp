#include <cppunit/ui/text/TestRunner.h>
#include "Vector2Test.hpp"

int main()
{
    CppUnit::TextUi::TestRunner runner;
    runner.addTest( Vector2Test::suite() );
    runner.run();
    return 0;
}
