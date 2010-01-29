/*
-------------------------------------------------------------------------------
File Name : test.cpp

Purpose : Running all the test from Pandora3D.

Creation Date : 2010-01-25

Last Modified : fr. 29. jan. 2010 kl. 16.15 +0100

Created By :  Martin Ertsås
-------------------------------------------------------------------------------
*/

#include <cppunit/ui/text/TestRunner.h>

#include "Vector2Test.h"
#include "Vector3Test.h"
#include "ListTest.h"
#include "MathTest.h"
#include "SetTest.h"
#include "StackTest.h"
#include "VectorTest.h"

int main(int argc, char **argv)
{
    CppUnit::TextUi::TestRunner runner;

    //Testing Utils library.
    runner.addTest( ListTest::suite() );
    runner.addTest( SetTest::suite() );
    runner.addTest( StackTest::suite() );
    runner.addTest( VectorTest::suite() );

    //Testing Math library
    runner.addTest( MathTest::suite() );
    runner.addTest( Vector2Test::suite() );
    runner.addTest( Vector3Test::suite() );


    runner.run();
    return 0;
}
