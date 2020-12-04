

#include <gtest/gtest.h>

#include "memman.h"

MM_TYPE_REGISTER(int);
MM_TYPE_REGISTER(char);

typedef struct {
    int a;
    int b;
} custom_type_t;

MM_TYPE_REGISTER(custom_type_t);

TEST(TestTypeidname, TestIntSameId)
{
    ASSERT_EQ(MM_TYPEIDNAME(int), MM_TYPEIDNAME(int));
}

TEST(TestTypeidname, TestCustomSameId)
{
    ASSERT_EQ(MM_TYPEIDNAME(custom_type_t), MM_TYPEIDNAME(custom_type_t));
}

TEST(TestTypeidname, TestIntCharDifferentId)
{
    ASSERT_TRUE(MM_TYPEIDNAME(int) != MM_TYPEIDNAME(char));
}

TEST(TestTypeidname, TestIntCustomDifferentId)
{
    ASSERT_TRUE(MM_TYPEIDNAME(int) != MM_TYPEIDNAME(custom_type_t));
}
