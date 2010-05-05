/*
-------------------------------------------------------------------------------
File Name : ListTest.cpp

Purpose : Testing the List class of Pandora3D.

Creation Date : 2010-01-26

Last Modified : on. 05. mai 2010 kl. 21.22 +0200

Created By :  Martin Ertsås
-------------------------------------------------------------------------------
*/

#include "ListTest.h"

using Pandora::Utils::List;

void ListTest::init()
{
    printf("Starting ListTest\n");
}

void ListTest::testList()
{
    printf("\tTesting insertion\n");
    CPPUNIT_ASSERT( floatList->length() == 0 );
    CPPUNIT_ASSERT( charList->length() == 1 );

    floatList->insert(4.0f);
    charList->insert('b');
    CPPUNIT_ASSERT( floatList->exists(4.0f) );
    CPPUNIT_ASSERT( !floatList->exists('a') );
    CPPUNIT_ASSERT( charList->exists('b') );
    CPPUNIT_ASSERT( !charList->exists('c') );
    CPPUNIT_ASSERT( floatList->length() == 1 );
    CPPUNIT_ASSERT( charList->length() == 2 );
    CPPUNIT_ASSERT( floatList->length() < charList->length() );

    CPPUNIT_ASSERT( floatList->remove(4.0f) );
    CPPUNIT_ASSERT( floatList->length() == 0 );
    CPPUNIT_ASSERT( !floatList->remove(2.0f) );

    CPPUNIT_ASSERT( charList->exists('a') );
    CPPUNIT_ASSERT( charList->remove('a') );
    CPPUNIT_ASSERT( charList->length() == 1 );
    CPPUNIT_ASSERT( !charList->remove('a') );
    CPPUNIT_ASSERT( charList->length() == 1 );
}

CppUnit::Test *ListTest::suite()
{
    CppUnit::TestSuite *testSuite = new CppUnit::TestSuite("ListTest");
    testSuite->addTest( new CppUnit::TestCaller<ListTest>(
                "ListTest::init",
                &ListTest::init ));
    testSuite->addTest( new CppUnit::TestCaller<ListTest>(
                "ListTest::testList",
                &ListTest::testList ));
    return testSuite;
}

void ListTest::setUp()
{
    floatList = new List<float>();
    charList = new List<char>('a');
}

void ListTest::tearDown()
{
    delete floatList;
    delete charList;
}
