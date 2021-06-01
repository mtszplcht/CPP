#include <gtest/gtest.h>
#include "../src/stack.h"

Stack stack;

TEST(Tests, tc1){
    ASSERT_EQ(0, stack.pop());
}

TEST(Tests, tc2){
    ASSERT_EQ(true, stack.isEmpty());
}

TEST(Tests, tc3){
    stack.push(1);
    stack.push(2);
    ASSERT_EQ(2, stack.pop());
}

TEST(Tests, tc4){
    ASSERT_EQ(false, stack.isEmpty());
}

TEST(Tests, tc5){
    stack.push(5);
    ASSERT_EQ(2, stack.size());
}

TEST(Tests, tc6){
    stack.push(12);
    ASSERT_EQ(3, stack.size());
}

TEST(Tests, tc7){
    stack.push(14);
    ASSERT_EQ(14, stack.pop());
}

TEST(Tests, tc8){
    stack.push(14);
    ASSERT_EQ(false, stack.isEmpty());
}

