/*
-------------------------------------------------------------------------------
File Name : testRunner.cpp

Purpose :

Creation Date : 2010-10-14

Last Modified : Thu Oct 14 13:47:49 2010

Created By :  Martin Ertsås
-------------------------------------------------------------------------------
*/

#include <boost/test/unit_test.hpp>
using boost::unit_test_framework::test_suite;

#include "Vector2_test.h"

//Test program entry point.
test_suite* init_unit_test_suite(int argc, char** args)
{
    test_suite* top_test_suite = BOOST_TEST_SUITE("Master test suite");

    top_test_suite->add(new Vector2_test_suite());

    return top_test_suite;
}
