/*
-------------------------------------------------------------------------------
File Name : StackTest.cpp

Purpose :

Creation Date : 2010-01-26

Last Modified : ti. 26. jan. 2010 kl. 13.21 +0100

Created By :  Martin Ertsås
-------------------------------------------------------------------------------
*/

#include "StackTest.h"

using Pandora::Utils::Stack;

void StackTest::init()
{
    printf("Starting StackTest\n");
}

void StackTest::testConstructor()
{
    printf("\tTesting constructor\n");

    CPPUNIT_ASSERT( !intStack->isFull() );
    CPPUNIT_ASSERT( !intStack->isEmpty() );

    CPPUNIT_ASSERT( !floatStack->isFull() );
    CPPUNIT_ASSERT( floatStack->isEmpty() );
}

void StackTest::testStack()
{
    printf("\tTesting Stack\n");

    int inttmp, inttmp2;
    CPPUNIT_ASSERT( intStack->getTop(inttmp) );
    CPPUNIT_ASSERT( intStack->pop(inttmp2) );
    CPPUNIT_ASSERT( inttmp2 == inttmp );
    CPPUNIT_ASSERT( !intStack->isFull() );
    CPPUNIT_ASSERT( !intStack->isEmpty() );
    CPPUNIT_ASSERT( intStack->pop(inttmp) );
    CPPUNIT_ASSERT( !intStack->pop(inttmp) );
    CPPUNIT_ASSERT( intStack->isEmpty() );
    CPPUNIT_ASSERT( !intStack->isFull() );

    floatStack->push(2.1);
    float floattmp, floattmp2;
    CPPUNIT_ASSERT( floatStack->isFull() );
    CPPUNIT_ASSERT( !floatStack->isEmpty() );
    CPPUNIT_ASSERT( floatStack->getTop(floattmp) );
    CPPUNIT_ASSERT( floatStack->pop(floattmp2) );
    CPPUNIT_ASSERT( floattmp == floattmp2 );
    CPPUNIT_ASSERT( floatStack->isEmpty() );
}

CppUnit::Test *StackTest::suite()
{
    CppUnit::TestSuite *testSuite = new CppUnit::TestSuite("StackTest");
    testSuite->addTest( new CppUnit::TestCaller<StackTest>(
                "StackTest::init",
                &StackTest::init ));
    testSuite->addTest( new CppUnit::TestCaller<StackTest>(
                "StackTest::testConstructor",
                &StackTest::testConstructor ));
    testSuite->addTest( new CppUnit::TestCaller<StackTest>(
                "StackTest::testStack",
                &StackTest::testStack ));
    return testSuite;
}

void StackTest::setUp()
{
    intStack = new Stack<int>(4);
    floatStack = new Stack<float>(1);

    intStack->push(2);
    intStack->push(1);
}

void StackTest::tearDown()
{
    delete intStack;
    delete floatStack;
}
