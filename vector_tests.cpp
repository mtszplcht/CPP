#include <gtest/gtest.h>
#include <string>
#include "../src/vector.h"


TEST(Tests, tc1){
    Vector<int> v;
    ASSERT_EQ(true, v.isEmpty());
}
TEST(Tests, tc2){
    Vector<int> v;
    v.push_back(5);
    v.push_back(10);
    ASSERT_EQ(2, v.getLength());
}
TEST(Tests, tc3){
    Vector<int> v;
    v.push_back(5);
    v.push_back(10);
    v.pop_back();
    ASSERT_EQ(1, v.getLength());
}

TEST(Tests, tc4){
    Vector<int> v;
    v.push_back(5);
    v.push_back(10);
    v.pop_back();
    v.push_back(15);
    v.push_back(20);
    ASSERT_EQ(20, v.getElement(2));
}
TEST(Tests, tc5){
    Vector<int> v;
    for(int i=0; i<15; i++){
        v.push_back(i);
    }
    ASSERT_EQ(15, v.getLength());
}
TEST(Tests, tc6){
    Vector<int> v;
    for(int i=0; i<15; i++){
        v.push_back(i);
    }
    ASSERT_EQ(20, v.getCapacity());
}
TEST(Tests, tc7){
    Vector<int> v;
    for(int i=0; i<15; i++){
        v.push_back(i);
    }
    ASSERT_EQ(10, v.getElement(10));
}