/*
-------------------------------------------------------------------------------
File Name : test.cpp

Purpose : Running all the test from Pandora3D.

Creation Date : 2010-01-25

Last Modified : ti. 26. jan. 2010 kl. 12.38 +0100

Created By :  Martin Ertsås
-------------------------------------------------------------------------------
*/

#include <cppunit/ui/text/TestRunner.h>
#include "Vector2Test.h"
#include "ListTest.h"
#include "MathTest.h"
#include "SetTest.h"
#include "StackTest.h"

int main(int argc, char **argv)
{
    CppUnit::TextUi::TestRunner runner;

    runner.addTest( Vector2Test::suite() );
    runner.addTest( ListTest::suite() );
    runner.addTest( MathTest::suite() );
    runner.addTest( SetTest::suite() );
    runner.addTest( StackTest::suite() );

    runner.run();
    return 0;
}
