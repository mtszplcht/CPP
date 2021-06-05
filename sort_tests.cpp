#include <gtest/gtest.h>
#include <string>
#include "../src/sort.h"


TEST(Tests, test1){
    int tab[]{3,7,1,8,3,5,9};
    SortExample::quick_sort(tab, 0, 6);
    ASSERT_EQ("1335789",SortExample::print(tab, 7));
    ASSERT_EQ(5 ,SortExample::binary_search(tab, 0, 6, 8));
}

TEST(Tests, test2){
    int tab[]{4,6,1,0,2};
    SortExample::quick_sort(tab, 0, 4);
    ASSERT_EQ("01246",SortExample::print(tab, 5));
    ASSERT_EQ(0 ,SortExample::binary_search(tab, 0, 4, 0));
}
