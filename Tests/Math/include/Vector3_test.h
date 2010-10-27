#ifndef VECTOR3_TEST_H
#define VECTOR3_TEST_H

#include <boost/test/unit_test.hpp>

#include "PandoraVector3.h"
#include "PandoraMath.h"

class Vector3_test
{
    public:
        Vector3_test();

        void test_construct();
        void test_equality();

        void test_addition();
        void test_multiplication();

        void test_aritmetic();

    private:
        Pandora::Math::Vec3f vec1, vec2, vec3;
};

class Vector3_test_suite : public boost::unit_test_framework::test_suite
{
    public:
        Vector3_test_suite() : boost::unit_test_framework::test_suite("Vector3_test_suite")
    {
        boost::shared_ptr<Vector3_test> instance(new Vector3_test());

        boost::unit_test_framework::test_case* test_construct_case = BOOST_CLASS_TEST_CASE(
                &Vector3_test::test_construct, instance);
        boost::unit_test_framework::test_case* test_equality_case = BOOST_CLASS_TEST_CASE(
                &Vector3_test::test_equality, instance);
        boost::unit_test_framework::test_case* test_addition_case = BOOST_CLASS_TEST_CASE(
                &Vector3_test::test_addition, instance);
        boost::unit_test_framework::test_case* test_multiplic_case = BOOST_CLASS_TEST_CASE(
                &Vector3_test::test_multiplication, instance);
        boost::unit_test_framework::test_case* test_aritmetic_case = BOOST_CLASS_TEST_CASE(
                &Vector3_test::test_aritmetic, instance);

        add(test_construct_case);
        add(test_equality_case);
        add(test_addition_case);
        add(test_multiplic_case);
        add(test_aritmetic_case);
    }
};
#endif
