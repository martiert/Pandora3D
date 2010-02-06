#ifndef STACKTEST_H
#define STACKTEST_H

#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>

#include "../System/PandoraStack.h"

class StackTest : public CppUnit::TestCase
{
    public:
        StackTest() : TestCase("StackTest") {}
        void init();
        void testConstructor();
        void testStack();

        static CppUnit::Test *suite();
        void setUp();
        void tearDown();
    private:
        Pandora::Utils::Stack<int> *intStack;
        Pandora::Utils::Stack<float> *floatStack;
};
#endif
