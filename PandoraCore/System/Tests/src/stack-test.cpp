#include <stack.h>
#include <gtest/gtest.h>

TEST (StackTest, empty_stack_has_size_of_0)
{
    System::Stack<int> stack;
    EXPECT_EQ (0, stack.size ());
}

TEST (StackTest, pushing_one_element_on_stack_gives_size_of_1)
{
    System::Stack<int> stack;
    stack.push (1);

    EXPECT_EQ (1, stack.size ());
}

TEST (StackTest, pushing_two_elements_on_the_stack_gives_size_of_2)
{
    System::Stack<int> stack;
    stack.push (1);
    stack.push (1);

    EXPECT_EQ (2, stack.size ());
}

TEST (StackTest, pushing_and_element_and_then_poping_it_gives_stack_size_of_0)
{
    System::Stack<int> stack;
    stack.push (1);
    stack.pop ();

    EXPECT_EQ (0, stack.size ());
}

TEST (StackTest, poping_empty_stack_throws_underflow_error)
{
    System::Stack<int> stack;
    EXPECT_THROW (stack.pop (), std::underflow_error);
}

TEST (StackTest, stack_has_default_max_size_of_8)
{
    System::Stack<int> stack;
    EXPECT_EQ (8, stack.max_size ());
}

TEST (StackTest, can_set_max_size_on_stack_during_creation)
{
    System::Stack<int> stack (4);
    EXPECT_EQ (4, stack.max_size ());
}

TEST (StackTest, pushing_one_and_then_poping_returns_one)
{
    System::Stack<int> stack;
    stack.push (1);

    EXPECT_EQ (1, stack.pop ());
}

TEST (StackTest, pushing_one_and_two_and_poping_twice_returns_two_and_one)
{
    System::Stack<int> stack;
    stack.push (1);
    stack.push (2);

    EXPECT_EQ (2, stack.pop ());
    EXPECT_EQ (1, stack.pop ());
}

TEST (StackTest, pushing_one_two_and_three_and_poping_trice_returns_three_two_and_one)
{
    System::Stack<int> stack;
    stack.push (1);
    stack.push (2);
    stack.push (3);

    EXPECT_EQ (3, stack.pop ());
    EXPECT_EQ (2, stack.pop ());
    EXPECT_EQ (1, stack.pop ());
}

TEST (StackTest, making_stack_of_size_one_and_pushing_twice_throws_overflow_error)
{
    System::Stack<int> stack (1);
    stack.push (1);

    EXPECT_THROW (stack.push (2), std::overflow_error);
}

TEST (StackTest, pushing_1_on_stack_and_peaking_gives_one)
{
    System::Stack<int> stack;
    stack.push (1);

    EXPECT_EQ (1, stack.peak ());
}

TEST (StackTest, pushing_2_on_stack_and_peaking_gives_two)
{
    System::Stack<int> stack;
    stack.push (2);

    EXPECT_EQ (2, stack.peak ());
}

TEST (StackTest, pushing_one_and_two_and_peaking_twice_gives_two_both_times)
{
    System::Stack<int> stack;
    stack.push (1);
    stack.push (2);

    EXPECT_EQ (2, stack.peak ());
    EXPECT_EQ (2, stack.peak ());
}

TEST (StackTest, pushing_one_two_and_three_then_peaking_poping_and_peaking_gives_three_three_two)
{
    System::Stack<int> stack;
    stack.push (1);
    stack.push (2);
    stack.push (3);

    EXPECT_EQ (3, stack.peak ());
    EXPECT_EQ (3, stack.pop ());
    EXPECT_EQ (2, stack.peak ());
}

TEST (StackTest, peaking_on_empty_stack_throws_logic_error)
{
    System::Stack<int> stack;
    EXPECT_THROW (stack.peak (), std::logic_error);
}
