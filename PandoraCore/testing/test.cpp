/*
-------------------------------------------------------------------------------
File Name : test.cpp

Purpose : Running all the test from Pandora3D.

Creation Date : 2010-01-25

Last Modified : Thu 02 Sep 2010 15:20:06 CEST

Created By :  Martin Ertsås
-------------------------------------------------------------------------------
*/

#include <cppunit/ui/text/TestRunner.h>

#include "ListTest.h"
#include "SetTest.h"
#include "StackTest.h"
#include "VectorTest.h"
#include "StringTest.h"
#include "MathTest.h"
#include "Vector2Test.h"
#include "Vector3Test.h"
#include "Vector4Test.h"
#include "Matrix2Test.h"
#include "Matrix3Test.h"
#include "Matrix4Test.h"

int main(int argc, char **argv)
{
    CppUnit::TextUi::TestRunner runner;

    //Testing Utils library.
    runner.addTest( ListTest::suite() );
    runner.addTest( SetTest::suite() );
    runner.addTest( StackTest::suite() );
    runner.addTest( VectorTest::suite() );
    runner.addTest( StringTest::suite() );

    //Testing Math library
    runner.addTest( MathTest::suite() );
    runner.addTest( Vector2Test::suite() );
    runner.addTest( Vector3Test::suite() );
    runner.addTest( Vector4Test::suite() );
    runner.addTest( Matrix2Test::suite() );
    runner.addTest( Matrix3Test::suite() );
    runner.addTest( Matrix4Test::suite() );

    runner.run();
    return 0;
}
