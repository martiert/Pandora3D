#ifndef VECTOR3TEST_H
#define VECTOR3TEST_H

#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>

#include "../include/PandoraVector3.h"

class Vector3Test : public CppUnit::TestCase
{
    public:
        Vector3Test() : TestCase("Vector3Test") {}
        void init();
        void testConstructor();

        static CppUnit::Test *suite();
        void setUp();
        void tearDown();
    private:
        Pandora::Math::Vec3<float> *m_1_1_1;
        Pandora::Math::Vec3<float> *m_2_4_1;
        Pandora::Math::Vec3<float> *m_1_0_0;
};
#endif
