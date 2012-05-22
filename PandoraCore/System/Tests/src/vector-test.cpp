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

TEST (VectorTest, appending_when_size_is_equal_to_capacity_increases_capacity_by_20)
{
    System::Vector<int> vector (2);
    vector.append (1);
    vector.append (2);
    vector.append (3);

    EXPECT_EQ (22, vector.capacity ());
    EXPECT_EQ (3, vector.size ());
}

TEST (VectorTest, removing_an_element_decreases_the_size)
{
    System::Vector<int> vector;
    vector.append (1);
    vector.append (2);
    vector.remove_at (0);

    EXPECT_EQ (1, vector.size ());
}

TEST (VectorTest, successfully_removing_and_element_returns_true)
{
    System::Vector<int> vector;
    vector.append (1);
    vector.append (2);

    EXPECT_EQ (1, vector.remove_at (0));
}

TEST (VectorTest, trying_to_remove_an_element_outside_of_the_populated_vector_throws_out_of_range_exception)
{
    System::Vector<int> vector;

    EXPECT_THROW (vector.remove_at (3), std::out_of_range);
}

TEST (VectorTest, appending_1_2_and_3_and_removing_at_1_returns_2)
{
    System::Vector<int> vector;
    vector.append (1);
    vector.append (2);
    vector.append (3);

    EXPECT_EQ (2, vector.remove_at (1));
}

TEST (VectorTest, appending_1_2_and_3_and_removint_at_1_twice_returns_2_and_3)
{
    System::Vector<int> vector;
    vector.append (1);
    vector.append (2);
    vector.append (3);

    EXPECT_EQ (2, vector.remove_at (1));
    EXPECT_EQ (3, vector.remove_at (1));
}

TEST (VectorTest, trying_to_use_element_at_on_vector_outside_of_its_range_throws_out_of_range_exception)
{
    System::Vector<int> vector;

    EXPECT_THROW (vector.element_at (3), std::out_of_range);
}

TEST (VectorTest, trying_to_increment_capacity_of_vector_with_increment_by_set_to_0_throws_overflow_error)
{
    System::Vector<int> vector (1, 0);
    vector.append (1);

    EXPECT_THROW (vector.append (2), std::overflow_error);
}

TEST (VectorTest, after_resizing_vector_have_same_elements)
{
    System::Vector<int> vector (3);
    vector.append (1);
    vector.append (2);
    vector.append (3);
    vector.append (4);

    EXPECT_EQ (1, vector.element_at (0));
    EXPECT_EQ (2, vector.element_at (1));
    EXPECT_EQ (3, vector.element_at (2));
    EXPECT_EQ (4, vector.element_at (3));
}
