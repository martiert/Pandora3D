//A unit test for the Vec2 class of Pandora3D.

#ifndef VECTOR2TEST_H
#define VECTOR2TEST_H

#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>

#include <PandoraVector2.h>

class Vector2Test : public CppUnit::TestCase
{
    public:
        Vector2Test() : TestCase("Vector2Test") {}

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
        Pandora::Math::Vec2f m_1_0, m_0_1, m_0_0, m_1_1, m_4_2;
};
#endif
