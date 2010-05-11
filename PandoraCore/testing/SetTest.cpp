/*
-------------------------------------------------------------------------------
File Name : SetTest.cpp

Purpose : Testing the Set class of Pandora3D.

Creation Date : 2010-01-26

Last Modified : ti. 11. mai 2010 kl. 11.30 +0200

Created By :  Martin Ertsås
-------------------------------------------------------------------------------
*/

#include "SetTest.h"

using Pandora::Utils::Set;

void SetTest::init()
{
    printf("Starting SetTest\t\n");
}

void SetTest::testConstructor()
{
    printf("\tTesting constructor\n");
    CPPUNIT_ASSERT( charSet->getSize() == 6 );
    CPPUNIT_ASSERT( charSet->getIncrement() == 4 );
    CPPUNIT_ASSERT( charSet->getElements() == 0 );

    CPPUNIT_ASSERT( floatSet->getSize() == 2 );
    CPPUNIT_ASSERT( floatSet->getIncrement() == 1 );
    CPPUNIT_ASSERT( floatSet->getElements() == 2 );

    CPPUNIT_ASSERT( noincSet->getSize() == 1 );
    CPPUNIT_ASSERT( noincSet->getIncrement() == 0 );
    CPPUNIT_ASSERT( noincSet->getElements() == 1 );
}

void SetTest::testInsert()
{
    printf("\tTesting insertion\n");
    CPPUNIT_ASSERT( charSet->insert('a') );
    CPPUNIT_ASSERT( charSet->getElements() == 1 );
    CPPUNIT_ASSERT( charSet->getSize() == 6 );
    CPPUNIT_ASSERT( charSet->getIncrement() == 4 );

    CPPUNIT_ASSERT( floatSet->getElements() == 2 );
    CPPUNIT_ASSERT( floatSet->getSize() == 2 );
    CPPUNIT_ASSERT( floatSet->getIncrement() == 1 );
    CPPUNIT_ASSERT( floatSet->insert(1.0) );
    CPPUNIT_ASSERT( floatSet->getElements() == 3 );
    CPPUNIT_ASSERT( floatSet->getSize() == 3 );
    CPPUNIT_ASSERT( floatSet->getIncrement() == 1 );

    CPPUNIT_ASSERT( noincSet->getElements() == 1 );
    CPPUNIT_ASSERT( noincSet->getSize() == 1 );
    CPPUNIT_ASSERT( noincSet->getIncrement() == 0 );
    CPPUNIT_ASSERT( !noincSet->insert(2) );
    CPPUNIT_ASSERT( noincSet->getElements() == 1 );
    CPPUNIT_ASSERT( noincSet->getSize() == 1 );
    CPPUNIT_ASSERT( noincSet->getIncrement() == 0 );
}

void SetTest::testExistence()
{
    printf("\tTesting existence\n");

    CPPUNIT_ASSERT( noincSet->exists(4) );
    CPPUNIT_ASSERT( !noincSet->exists(8) );

    CPPUNIT_ASSERT( !charSet->exists('a') );
    CPPUNIT_ASSERT( !charSet->exists('b') );

    CPPUNIT_ASSERT( floatSet->exists(4.0) );
    CPPUNIT_ASSERT( floatSet->exists(2.0) );
    CPPUNIT_ASSERT( !floatSet->exists(3.0) );
}

void SetTest::testRemove()
{
    printf("\tTesting remove\t\n");

    CPPUNIT_ASSERT( !charSet->remove('a') );

    CPPUNIT_ASSERT( noincSet->remove(4) );
    CPPUNIT_ASSERT( !noincSet->remove(8) );
    CPPUNIT_ASSERT( noincSet->getElements() == 0 );
    CPPUNIT_ASSERT( noincSet->insert(4) );

    CPPUNIT_ASSERT( !floatSet->remove(3.0) );
    CPPUNIT_ASSERT( floatSet->remove(2.0) );
    CPPUNIT_ASSERT( floatSet->getElements() == 1 );
    CPPUNIT_ASSERT( floatSet->insert(3.0) );
    CPPUNIT_ASSERT( floatSet->getElements() == 2 );
}

void SetTest::testPointer()
{
    printf("\tTesting pointer\t\n");

    char *charPtr = charSet->getPointer();
    int *intPtr = noincSet->getPointer();
    float *floatPtr = floatSet->getPointer();

    CPPUNIT_ASSERT( charPtr );
    CPPUNIT_ASSERT( intPtr );
    CPPUNIT_ASSERT( floatPtr );

    CPPUNIT_ASSERT( noincSet->exists(intPtr[0]) );
    CPPUNIT_ASSERT( floatSet->exists(floatPtr[0]) );
    CPPUNIT_ASSERT( floatSet->exists(floatPtr[1]) );
    CPPUNIT_ASSERT( floatPtr[0] == 4.0 );
    CPPUNIT_ASSERT( floatSet->remove(floatPtr[0]) );
    CPPUNIT_ASSERT( floatPtr[0] == 2.0 );
}

void SetTest::testRemoveAll()
{
    printf("\tTesting remove all\n");

    charSet->removeAll();
    noincSet->removeAll();
    floatSet->removeAll();

    CPPUNIT_ASSERT( charSet->getElements() == 0 );
    CPPUNIT_ASSERT( !charSet->exists('a') );

    CPPUNIT_ASSERT( noincSet->getElements() == 0 );
    CPPUNIT_ASSERT( !noincSet->exists(4) );

    CPPUNIT_ASSERT( floatSet->getElements() == 0 );
    CPPUNIT_ASSERT( !floatSet->exists(4.0) );
    CPPUNIT_ASSERT( !floatSet->exists(2.0) );
}

CppUnit::Test *SetTest::suite()
{
    CppUnit::TestSuite *testSuite = new CppUnit::TestSuite("SetTest");
    testSuite->addTest( new CppUnit::TestCaller<SetTest>(
                "SetTest::init",
                &SetTest::init ));
    testSuite->addTest( new CppUnit::TestCaller<SetTest>(
                "SetTest::testConstructor",
                &SetTest::testConstructor ));
    testSuite->addTest( new CppUnit::TestCaller<SetTest>(
                "SetTest::testInsert",
                &SetTest::testInsert ));
    testSuite->addTest( new CppUnit::TestCaller<SetTest>(
                "SetTest::testExistence",
                &SetTest::testExistence ));
    testSuite->addTest( new CppUnit::TestCaller<SetTest>(
                "SetTest::testRemove",
                &SetTest::testRemove ));
    testSuite->addTest( new CppUnit::TestCaller<SetTest>(
                "SetTest::testPointer",
                &SetTest::testPointer ));
    testSuite->addTest( new CppUnit::TestCaller<SetTest>(
                "SetTest::testRemoveAll",
                &SetTest::testRemoveAll ));
    return testSuite;
}

void SetTest::setUp()
{
    charSet = new Set<char>();
    floatSet = new Set<float>(2, 1);
    noincSet = new Set<int>(1,0);

    CPPUNIT_ASSERT( floatSet->insert(4.0) );
    CPPUNIT_ASSERT( floatSet->insert(2.0) );
    CPPUNIT_ASSERT( noincSet->insert(4) );
}

void SetTest::tearDown()
{
    delete charSet;
    delete floatSet;
    delete noincSet;
}
