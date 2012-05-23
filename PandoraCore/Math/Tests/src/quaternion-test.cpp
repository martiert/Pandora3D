#include <quaternion.h>
#include <vector3.h>
#include <gtest/gtest.h>

#include "test-helpers.h"

const Math::Quat4d create_random_quaternion ();
const Math::Vec3d create_random_vector3d ();

TEST (QuaternionTest, default_quaternion_is_unit_quaternion)
{
    const Math::Quat4d quat;

    EXPECT_EQ (1, quat.w ());
    EXPECT_EQ (0, quat.x ());
    EXPECT_EQ (0, quat.y ());
    EXPECT_EQ (0, quat.z ());
}

TEST (QuaternionTest, creating_quaternion_with_arguments_populates_quaternion_with_arguments)
{
    const Math::Quat4d quat (4.1, 2.3, 6.7, 3.1);
    EXPECT_EQ (4.1, quat.w ());
    EXPECT_EQ (2.3, quat.x ());
    EXPECT_EQ (6.7, quat.y ());
    EXPECT_EQ (3.1, quat.z ());
}

TEST (QuaternionTest, creating_quaternion_from_array_populates_quaternion)
{
    auto array = create_double_array_of_size (4);
    const Math::Quat4d quat (array);

    EXPECT_EQ (array[0], quat.w ());
    EXPECT_EQ (array[1], quat.x ());
    EXPECT_EQ (array[2], quat.y ());
    EXPECT_EQ (array[3], quat.z ());

    delete[] array;
}

TEST (QuaternionTest, creating_quaternion_with_real_element_and_imaginary_vector_sets_quaternion)
{
    auto vector = create_random_vector3d ();
    Math::Quat4d quat (3.2, vector);

    EXPECT_EQ (3.2, quat.w ());
    EXPECT_EQ (vector.x, quat.x ());
    EXPECT_EQ (vector.y, quat.y ());
    EXPECT_EQ (vector.z, quat.z ());
}

// Helper function
const Math::Quat4d create_random_quaternion ()
{
    auto array = create_double_array_of_size (4);
    Math::Quat4d quat (array);

    delete[] array;
    return quat;
}
