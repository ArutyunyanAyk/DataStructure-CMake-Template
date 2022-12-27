#include <gtest.h>
#include "../lib_queue/queue.h"

TEST(test_lib_queue, can_create_queue) {
    ASSERT_NO_THROW(Queue<int>s1(10));
}

TEST(test_lib_queue, can_create_queue_with_neg_size) {
    ASSERT_ANY_THROW(Queue<int>s1(-1));
}

TEST(test_lib_queue, can_do_funk_top)
{
    Queue<int>s1(5);
    s1.push(3);
    int res = s1.Top();
    EXPECT_EQ(res, 3);
    EXPECT_FALSE(s1.isEmpty());
}

TEST(test_lib_queue, can_do_funk_pop)
{
    Queue<int>s1(5);
    s1.push(3);
    int res = s1.Pop();
    EXPECT_EQ(res, 3);
}

TEST(test_lib_queue, can_get_top) {
    Queue<int>s1(5);
    s1.push(2);
    int res = s1.Top();
    EXPECT_EQ(res, 2);
    ASSERT_NO_THROW(s1.Top());
}

TEST(test_lib_queue, cant_get_top_when_queue_is_Empty)
{
    Queue<int>s1(5);
    s1.push(1);
    s1.Pop();
    ASSERT_ANY_THROW(s1.Top());
}

TEST(test_lib_queue, can_get_pop) {
    Queue<int>s1(5);
    s1.push(2);
    ASSERT_NO_THROW(s1.Pop());
}

TEST(test_lib_queue, cant_get_pop_when_queue_is_Empty)
{
    Queue<int>s1(5);
    s1.push(1);
    s1.Pop();
    ASSERT_ANY_THROW(s1.Pop());
}