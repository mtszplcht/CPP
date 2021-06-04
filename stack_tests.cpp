#include <gtest/gtest.h>
#include "../src/stack.h"


TEST(Tests, tc1){
    Stack stack;
    ASSERT_EQ(0, stack.pop());
}

TEST(Tests, tc2){
    Stack stack;
    ASSERT_EQ(true, stack.isEmpty());
}

TEST(Tests, tc3){
    Stack stack;
    stack.push(1);
    stack.push(2);
    ASSERT_EQ(2, stack.pop());
}

TEST(Tests, tc4){
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.pop();
    ASSERT_EQ(false, stack.isEmpty());
}

TEST(Tests, tc5){
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.pop();
    stack.push(5);
    ASSERT_EQ(2, stack.size());
}

TEST(Tests, tc6){
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.pop();
    stack.push(5);
    stack.pop();
    stack.push(12);
    ASSERT_EQ(2, stack.size());
}

TEST(Tests, tc7){
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.pop();
    stack.push(5);
    stack.pop();
    stack.push(12);
    stack.push(14);
    ASSERT_EQ(14, stack.pop());
}

TEST(Tests, tc8){
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.pop();
    stack.push(5);
    stack.pop();
    stack.push(12);
    stack.push(14);
    ASSERT_EQ(false, stack.isEmpty());
}

