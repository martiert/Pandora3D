/*
-------------------------------------------------------------------------------
File Name : VectorTest.cpp

Purpose :

Creation Date : 2010-01-26

Last Modified : on. 27. jan. 2010 kl. 11.36 +0100

Created By :  Martin Ertsås
-------------------------------------------------------------------------------
*/

#include "VectorTest.h"

using Pandora::Utils::Vector;

void VectorTest::init()
{
    printf("Starting VectorTest\n");
}

void VectorTest::testGetter()
{
    printf("\tTesting Getters\n");

    CPPUNIT_ASSERT( intVec->getElements() == 0 );
    CPPUNIT_ASSERT( intVec->getSize() == 4 );
    CPPUNIT_ASSERT( intVec->getIncrement() == 4 );

    CPPUNIT_ASSERT( floatVec->getElements() == 0 );
    CPPUNIT_ASSERT( floatVec->getSize() == 2 );
    CPPUNIT_ASSERT( floatVec->getIncrement() == 1 );

    CPPUNIT_ASSERT( noincVec->getElements() == 1 );
    CPPUNIT_ASSERT( noincVec->getSize() == 2 );
    CPPUNIT_ASSERT( noincVec->getIncrement() == 0 );

    intVec->setSize(12);
    intVec->setIncrement(1);
    CPPUNIT_ASSERT( intVec->getSize() == 12 );
    CPPUNIT_ASSERT( intVec->getIncrement() == 1 );
}

void VectorTest::testIndexing()
{
    printf("\tTesting indexing\n");
    char *tmp = noincVec->c_ptr();
    CPPUNIT_ASSERT( tmp[0] == 'c' );
}

CppUnit::Test *VectorTest::suite()
{
    CppUnit::TestSuite *testSuite = new CppUnit::TestSuite("VectorTest");
    testSuite->addTest( new CppUnit::TestCaller<VectorTest>(
                "VectorTest::init",
                &VectorTest::init ));
    testSuite->addTest( new CppUnit::TestCaller<VectorTest>(
                "VectorTest::testGetter",
                &VectorTest::testGetter ));
    testSuite->addTest( new CppUnit::TestCaller<VectorTest>(
                "VectorTest::testIndexing",
                &VectorTest::testIndexing ));
    return testSuite;
}

void VectorTest::setUp()
{
    intVec = new Vector<int>();
    floatVec = new Vector<float>(2,1);
    noincVec = new Vector<char>(2,0);
    noincVec->append('c');
}

void VectorTest::tearDown()
{
    delete intVec;
    delete floatVec;
    delete noincVec;
}
