#ifndef SETTEST_H
#define SETTEST_H

#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>

#include <PandoraSet.h>

class SetTest : public CppUnit::TestCase
{
    public:
        SetTest() : TestCase("SetTest") {}
        void init();
        void testConstructor();
        void testInsert();
        void testExistence();
        void testRemove();
        void testPointer();
        void testRemoveAll();

        static CppUnit::Test *suite();
        void setUp();
        void tearDown();
    private:
        Pandora::Utils::Set<char> *charSet;
        Pandora::Utils::Set<float> *floatSet;
        Pandora::Utils::Set<int> *noincSet;
};
#endif
