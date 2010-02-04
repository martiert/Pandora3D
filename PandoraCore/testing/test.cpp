/*
-------------------------------------------------------------------------------
File Name : test.cpp

Purpose : Running all the test from Pandora3D.

Creation Date : 2010-01-25

Last Modified : to. 04. feb. 2010 kl. 14.21 +0100

Created By :  Martin Ertsås
-------------------------------------------------------------------------------
*/

#include <cppunit/ui/text/TestRunner.h>

#include "ListTest.h"
#include "SetTest.h"
#include "StackTest.h"
#include "VectorTest.h"
#include "MathTest.h"
#include "Vector2Test.h"
#include "Vector3Test.h"
#include "Vector4Test.h"

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
    runner.addTest( Vector4Test::suite() );


    runner.run();
    return 0;
}
