#ifndef MATRIX4TEST_H
#define MATRIX4TEST_H

#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>

#include "../Math/include/PandoraMatrix4.h"

class Matrix4Test : public CppUnit::TestCase
{
    public:
        Matrix4Test() : TestCase("Matrix4Test") {}

        void init();
        void testConstructor();
        void testAddition();
        void testSubtraction();
        void testMultiplication();
        void testArithmetic();
        void testComparison();
        void testAssignment();

        static CppUnit::Test *suite();
        void setUp();
        void tearDown();
    private:
        Pandora::Math::Mat4d test1, test2, test3;
        double eps;
};
#endif
