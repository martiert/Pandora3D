/*
-------------------------------------------------------------------------------
File Name : StringTest.cpp

Purpose : Testing the String class of Pandora3D.

Creation Date : 2010-01-26

Last Modified : Thu 02 Sep 2010 15:02:26 CEST

Created By :  Martin Ertsaas
-------------------------------------------------------------------------------
*/

#include "StringTest.h"

using Pandora::Utils::String;

void StringTest::init()
{
    printf("Starting StringTest\n");
}

void StringTest::testConstructor()
{
    printf("\tTestint constructor\n");
}


CppUnit::Test *StringTest::suite()
{
    CppUnit::TestSuite *testSuite = new CppUnit::TestSuite("StringTest");

    testSuite->addTest( new CppUnit::TestCaller<StringTest>(
                "StringTest::init",
                &StringTest::init ));
    testSuite->addTest( new CppUnit::TestCaller<StringTest>(
                "StringTest::testConstructor",
                &StringTest::testConstructor ));

    return testSuite;
}

void StringTest::setUp()
{
}

void StringTest::tearDown()
{
}
