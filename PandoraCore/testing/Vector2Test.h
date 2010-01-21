#ifndef VECTOR2TEST_H
#define VECTOR2TEST_H

#include <iostream>
#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>

#include "../include/PandoraVector2.h"

class Vector2Test : public CppUnit::TestCase
{
    public:
        Vector2Test() : TestCase("Vector2Test") {}

        void testConstructor();
        void testArritmetic();
        void testComparsion();
        void testAssignment();
        static CppUnit::Test *suite();
};
#endif
