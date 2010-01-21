/*
-------------------------------------------------------------------------------
File Name : Vector2Test.cpp

Purpose : Unit testing of the Pandora::Math::Vec2 implementation.

Creation Date : 2010-01-19

Last Modified : ti. 19. jan. 2010 kl. 16.24 +0100

Created By :  Martin Ertsås
-------------------------------------------------------------------------------
*/

#include "Vector2Test.h"

using Pandora::Math::Vec2f;

void Vector2Test::testConstructor()
{
    Vec2f identity;
    Vec2f zero(0.0f, 0.0f);
    Vec2f rand(4.3f, 8.5f);
    
    CPPUNIT_ASSERT( identity.x == 1.0f );
    CPPUNIT_ASSERT( identity.y == 0.0f );
    CPPUNIT_ASSERT( zero.x == 0.0f );
    CPPUNIT_ASSERT( zero.y == 0.0f );
    CPPUNIT_ASSERT( rand.x == 4.3f );
    CPPUNIT_ASSERT( rand.y == 8.5f );
}

void Vector2Test::testArritmetic()
{
    Vec2f identity;
    Vec2f zero(0.0f, 0.0f);
    Vec2f identy;
    Vec2f ones(1.0f, 1.0f);
    Vec2f rand(4.25f, 8.5f);
    Vec2f rand2(3.25f, 7.5f);

    Vec2f tmp = ones + rand2;
    ones += rand2;
    CPPUNIT_ASSERT( tmp.x = rand.x && tmp.y == rand.y );
    CPPUNIT_ASSERT( ones.x == rand.x && ones.y == rand.y );
    ones -= rand2;
    CPPUNIT_ASSERT( ones.x == 1.0f && ones.y == 1.0f );
    float length = zero.length();
    CPPUNIT_ASSERT( length == 0.0f );
    length == rand.length();
    printf("%.16f\n", length);
    CPPUNIT_ASSERT( length == Pandora::Math::Math<float>::Sqrt(rand.x*rand.x + rand.y*rand.y) );
}

void Vector2Test::testComparsion()
{
}

void Vector2Test::testAssignment()
{
}

CppUnit::Test *Vector2Test::suite()
{
    CppUnit::TestSuite *testSuite = new CppUnit::TestSuite("Vector2Test");
    testSuite->addTest( new CppUnit::TestCaller<Vector2Test>(
                "Vector2Test::testConstructor", 
                &Vector2Test::testConstructor ));
    testSuite->addTest( new CppUnit::TestCaller<Vector2Test>(
                "Vector2Test::testArritmetic", 
                &Vector2Test::testArritmetic ));
    testSuite->addTest( new CppUnit::TestCaller<Vector2Test>(
                "Vector2Test::testComparsion", 
                &Vector2Test::testComparsion ));
    testSuite->addTest( new CppUnit::TestCaller<Vector2Test>(
                "Vector2Test::testAssignment", 
                &Vector2Test::testComparsion ));
    return testSuite;
}
