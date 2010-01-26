//A unit test for the Math class in Pandora3D.

#ifndef MATHTEST_H
#define MATHTEST_H

#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>
#include <math.h>

#include "../include/PandoraMath.h"

class MathTest : public CppUnit::TestCase
{
    public:
        MathTest() : TestCase("MathTest") {}
        void init();
        void testTrigonometries();
        void testRound();
        void testPow();

        static CppUnit::Test *suite();
    private:
};
#endif
