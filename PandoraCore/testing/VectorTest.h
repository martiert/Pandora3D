#ifndef VECTORTEST_H
#define VECTORTEST_H

#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>

#include <PandoraVector.h>

class VectorTest : public CppUnit::TestCase
{
    public:
        VectorTest() : TestCase("VectorTest") { }
        void init();
        void testGetter();
        void testIndexing();

        static CppUnit::Test *suite();
        void setUp();
        void tearDown();
    private:
        Pandora::Utils::Vector<int> *intVec;
        Pandora::Utils::Vector<float> *floatVec;
        Pandora::Utils::Vector<char> *noincVec;
};
#endif
