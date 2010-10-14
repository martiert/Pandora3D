#ifndef VECTOR2_TEST_H
#define VECTOR2_TEST_H

#include <boost/test/unit_test.hpp>

#include "PandoraVector2.h"

class Vector2_test
{
    public:
        Vector2_test();

        void test_construct();

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

        add(test_construct_case);
    }
};
#endif
