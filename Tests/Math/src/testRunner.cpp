/*
-------------------------------------------------------------------------------
File Name : testRunner.cpp

Purpose :

Creation Date : 2010-10-14

Last Modified : Tue 15 Feb 2011 12:00:56 PM CET

Created By :  Martin Ertsås
-------------------------------------------------------------------------------
*/

#include <boost/test/unit_test.hpp>
using boost::unit_test_framework::test_suite;

#include "Vector2_test.h"
#include "Vector3_test.h"
#include "Vector4_test.h"
#include "Matrix2_test.h"
#include "Matrix3_test.h"

//Test program entry point.
test_suite* init_unit_test_suite(int argc, char** args)
{
    test_suite* top_test_suite = BOOST_TEST_SUITE("Master test suite");

    top_test_suite->add(new Vector2_test_suite());
    top_test_suite->add(new Vector3_test_suite());
    top_test_suite->add(new Vector4_test_suite());
    top_test_suite->add(new Matrix2_test_suite());
    top_test_suite->add(new Matrix3_test_suite());

    return top_test_suite;
}
