#ifndef MATRIX2TEST_H
#define MATRIX2TEST_H

#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>

#include <PandoraMatrix2.h>

class Matrix2Test : public CppUnit::TestCase
{
    public:
        Matrix2Test() : TestCase("Matrix2Test") {}

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
        Pandora::Math::Mat2d test1, test2;
        double eps;
};
#endif
