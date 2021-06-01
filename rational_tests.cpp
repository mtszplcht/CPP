#include <gtest/gtest.h>
#include "../src/rational.h"

Rational r2(2,11), r3(1,-3), r5(18,6);
Rational res1 = 3 + r2 * r3;
Rational res2 = (3 + r2) * r3;
Rational res3 = 3 + r3 * (r2 + 2) / (r5 - r3);
Rational rr1(1,-8), rr2(3,5), rr3(-4,-3);
Rational res4 = rr1 * rr2 / 3;
Rational res5 = rr2 + rr3 * 2;

TEST(Tests, tc1){
    ASSERT_EQ(97, res1.numerator());
}

TEST(Tests, tc2){
    ASSERT_EQ(33, res1.denominator());
}

TEST(Tests, tc3){
    ASSERT_EQ(-35, res2.numerator());
}

TEST(Tests, tc4){
    ASSERT_EQ(33, res2.denominator());
}

TEST(Tests, tc5){
    ASSERT_EQ(153, res3.numerator());
}

TEST(Tests, tc6){
    ASSERT_EQ(55, res3.denominator());
}
TEST(Tests, tc7){
    ASSERT_EQ(-1, res4.numerator());
}
TEST(Tests, tc8){
    ASSERT_EQ(40, res4.denominator());
}
TEST(Tests, tc9){
    ASSERT_EQ(49, res5.numerator());
}
TEST(Tests, tc10){
    ASSERT_EQ(15, res5.denominator());
}

