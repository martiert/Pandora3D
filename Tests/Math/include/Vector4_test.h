#ifndef VECTOR4_TEST_H
#define VECTOR4_TEST_H

#include <boost/test/unit_test.hpp>

#include "PandoraVector4.h"
#include "PandoraMath.h"

class Vector4_test
{
    public:
        Vector4_test();

        void test_construct();
        void test_equality();

        void test_addition();
        void test_multiplication();

        void test_aritmetic();

    private:
        Pandora::Math::Vec4f vec1, vec2, vec3, vec4;
};

class Vector4_test_suite : public boost::unit_test_framework::test_suite
{
    public:
        Vector4_test_suite() : boost::unit_test_framework::test_suite("Vector4_test_suite")
    {
        boost::shared_ptr<Vector4_test> instance(new Vector4_test());

        boost::unit_test_framework::test_case* test_construct_case = BOOST_CLASS_TEST_CASE(
                &Vector4_test::test_construct, instance);
        boost::unit_test_framework::test_case* test_equality_case = BOOST_CLASS_TEST_CASE(
                &Vector4_test::test_equality, instance);
        boost::unit_test_framework::test_case* test_addition_case = BOOST_CLASS_TEST_CASE(
                &Vector4_test::test_addition, instance);
        boost::unit_test_framework::test_case* test_multiplic_case = BOOST_CLASS_TEST_CASE(
                &Vector4_test::test_multiplication, instance);
        boost::unit_test_framework::test_case* test_aritmetic_case = BOOST_CLASS_TEST_CASE(
                &Vector4_test::test_aritmetic, instance);

        add(test_construct_case);
        add(test_equality_case);
        add(test_addition_case);
        add(test_multiplic_case);
        add(test_aritmetic_case);
    }
};
#endif
