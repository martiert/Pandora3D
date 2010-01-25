#ifndef LISTTEST_H
#define LISTTEST_H

#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>

#include "../include/PandoraList.h"

class ListTest : public CppUnit::TestCase
{
    public:
        ListTest() : TestCase("ListTest") {}
        void init();
        void testList();

        static CppUnit::Test *suite();
        void setUp();
        void tearDown();
    private:
        Pandora::Utils::List<float> *floatList;
        Pandora::Utils::List<char> *charList;
};
#endif
