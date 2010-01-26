/*
-------------------------------------------------------------------------------
File Name : VectorTest.cpp

Purpose :

Creation Date : 2010-01-26

Last Modified : ti. 26. jan. 2010 kl. 13.59 +0100

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


}

CppUnit::Test *VectorTest::suite()
{
    CppUnit::TestSuite *testSuite = new CppUnit::TestSuite("VectorTest");
    testSuite->addTest( new CppUnit::TestCaller<VectorTest>(
                "VectorTest::init",
                &VectorTest::init ));
    testSuite->addTest( new CppUnit::TestCaller<VectorTest>(
                "VectorTest::init",
                &VectorTest::testConstructor ));
    return testSuite;
}

void VectorTest::setUp()
{
    intVec = new Vector<int>();
    floatVec = new Vector<float>(2,1);
    noincVec = new Vector<char>(2,0);
}

void VectorTest::tearDown()
{
    delete intVec;
    delete floatVec;
    delete noincVec;
}
