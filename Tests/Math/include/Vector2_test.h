#ifndef VECTOR2_TEST_H
#define VECTOR2_TEST_H

#include <boost/test/unit_test.hpp>

#include "PandoraVector2.h"

class Vector2_test
{
    public:
        Vector2_test();

        void test_construct();
        void test_equality();

        void test_addition();
        void test_multiplication();

        void test_aritmetic();

    private:
        Pandora::Math::Vec2f vec1, vec2, vec3;
};

class Vector2_test_suite : public boost::unit_test_framework::test_suite
{
    public:
        Vector2_test_suite() : boost::unit_test_framework::test_suite("Vector2_test_suite")
    {
        boost::shared_ptr<Vector2_test> instance(new Vector2_test());

        boost::unit_test_framework::test_case* test_construct_case = BOOST_CLASS_TEST_CASE(
                &Vector2_test::test_construct, instance);
        boost::unit_test_framework::test_case* test_equality_case = BOOST_CLASS_TEST_CASE(
                &Vector2_test::test_equality, instance);
        boost::unit_test_framework::test_case* test_addition_case = BOOST_CLASS_TEST_CASE(
                &Vector2_test::test_addition, instance);
        boost::unit_test_framework::test_case* test_multiplic_case = BOOST_CLASS_TEST_CASE(
                &Vector2_test::test_multiplication, instance);
        boost::unit_test_framework::test_case* test_aritmetic_case = BOOST_CLASS_TEST_CASE(
                &Vector2_test::test_aritmetic, instance);

        add(test_construct_case);
        add(test_equality_case);
        add(test_addition_case);
        add(test_multiplic_case);
        add(test_aritmetic_case);
    }
};
#endif
