#include <gtest/gtest.h>
#include <string>
#include "../src/set.h"


TEST(Tests, tc1){
    Set<int>set(5);
    ASSERT_EQ(true, set.isEmpty());
}
TEST(Tests, tc2){
    Set<int> set;
    ASSERT_EQ(0, set.size());
}
TEST(Tests, tc3){
    Set<int> set;
    set.insert(4);
    ASSERT_EQ(false, set.isEmpty());
}
TEST(Tests, tc4){
    Set<int> set;
    set.insert(4);
    set.insert(4);
    ASSERT_EQ(1, set.size());
}
TEST(Tests, tc5){
    Set<int> set;
    set.insert(4);
    set.insert(5);
    set.insert(6);
    ASSERT_EQ(true, set.includes(5));
}
TEST(Tests, tc6){
    Set<int> set;
    set.insert(4);
    set.insert(5);
    set.insert(6);
    ASSERT_EQ(3, set.size());
}
TEST(Tests, tc7){
    Set<int> set;
    set.insert(4);
    set.insert(5);
    set.insert(6);
    set.erase(10);
    ASSERT_EQ(3, set.size());
}
TEST(Tests, tc8){
    Set<int> set;
    set.insert(4);
    set.insert(5);
    set.insert(6);
    set.erase(10);
    set.insert(6);
    set.insert(6);
    ASSERT_EQ(3, set.size());
}

TEST(Tests, tc9){
    Set<const char*> set;
    set.insert("hello");
    ASSERT_EQ(1, set.size());
}

TEST(Tests, tc10){
    Set<const char*> set;
    set.insert("hello");
    set.insert("hello");
    ASSERT_EQ(1, set.size());
}

TEST(Tests, tc11){
    Set<const char*> set;
    set.insert("hello");
    set.insert("abc");
    ASSERT_EQ(true, set.includes("abc"));
}
TEST(Tests, tc12){
    Set<const char*> set;
    set.insert("hello");
    set.insert("abc");
    set.erase("hello");
    ASSERT_EQ(1, set.size());
}
