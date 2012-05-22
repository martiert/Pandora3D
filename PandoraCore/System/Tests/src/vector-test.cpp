#include <vector.h>
#include <gtest/gtest.h>

TEST (VectorTest, empty_vector_have_size_of_0)
{
    System::Vector<int> vector;
    EXPECT_EQ (0, vector.size ());
}

TEST (VectorTest, appending_one_element_gives_size_of_1)
{
    System::Vector<int> vector;
    vector.append (1);

    EXPECT_EQ (1, vector.size ());
}

TEST (VectorTest, appending_one_and_two_gives_size_of_2)
{
    System::Vector<int> vector;
    vector.append (1);
    vector.append (2);

    EXPECT_EQ (2, vector.size ());
}

TEST (VectorTest, default_capacity_is_20)
{
    System::Vector<int> vector;
    EXPECT_EQ (20, vector.capacity ());
}

TEST (VectorTest, capacity_can_be_set_in_constructor)
{
    System::Vector<int> vector (40);
    EXPECT_EQ (40, vector.capacity ());
}

TEST (VectorTest, appending_1_2_will_give_element_at_0_equal_1)
{
    System::Vector<int> vector;
    vector.append (1);
    vector.append (2);

    EXPECT_EQ (1, vector.element_at (0));
}
