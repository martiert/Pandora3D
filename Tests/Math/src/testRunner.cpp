/*
-------------------------------------------------------------------------------
File Name : testRunner.cpp

Purpose :

Creation Date : 2010-10-14

Last Modified : on. 27. okt. 2010 kl. 20.23 +0200

Created By :  Martin Ertsås
-------------------------------------------------------------------------------
*/

#include <boost/test/unit_test.hpp>
using boost::unit_test_framework::test_suite;

#include "Vector2_test.h"
#include "Vector3_test.h"

//Test program entry point.
test_suite* init_unit_test_suite(int argc, char** args)
{
    test_suite* top_test_suite = BOOST_TEST_SUITE("Master test suite");

    top_test_suite->add(new Vector2_test_suite());
    top_test_suite->add(new Vector3_test_suite());

    return top_test_suite;
}
