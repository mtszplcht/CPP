#include <gtest/gtest.h>
#include <string>
#include "../src/queue.h"


TEST(Tests, tc1){
    Queue q;
    ASSERT_EQ(true, q.isEmpty());
}
TEST(Tests, tc2){
    Queue q;
    q.enqueue(1);
    ASSERT_EQ(false, q.isEmpty());
}
TEST(Tests, tc3){
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    ASSERT_EQ(1, q.peek());
}
TEST(Tests, tc4){
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.dequeue();
    ASSERT_EQ(2, q.peek());
}
TEST(Tests, tc5){
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.dequeue();
    q.dequeue();
    ASSERT_EQ(true, q.isEmpty());
}