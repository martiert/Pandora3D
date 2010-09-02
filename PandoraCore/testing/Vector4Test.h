#ifndef VECTOR4TEST_H
#define VECTOR4TEST_H

#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>

#include <PandoraVector4.h>

class Vector4Test : public CppUnit::TestCase
{
    public:
        Vector4Test() : TestCase("Vector4Test") {}
        void init();
        void testConstructor();
        void testAssignment();
        void testArithmetic();
        void testComparison();
        void testGeometry();
        
        static CppUnit::Test *suite();
        void setUp();
        void tearDown();
    private:
        Pandora::Math::Vector4<float> m_1, m_2, m_3, m_4;
};
#endif
