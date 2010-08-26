#ifndef MATRIX3TEST_H
#define MATRIX3TEST_H

#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>

#include "../Math/include/PandoraMatrix3.h"

class Matrix3Test : public CppUnit::TestCase
{
    public:
        Matrix3Test() : TestCase("Matrix3Test") {}

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
        Pandora::Math::Mat3d test1, test2, test3;
        double eps;
};
#endif
