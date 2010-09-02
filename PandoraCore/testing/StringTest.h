#ifndef STRINGTEST_H
#define STRINGTEST_H

#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>

#include <PandoraString.h>

class StringTest : public CppUnit::TestCase
{
    public:
        StringTest() : TestCase("StringTest") {}
        void init();
        void testConstructor();

        static CppUnit::Test *suite();
        void setUp();
        void tearDown();
    private:
};
#endif
