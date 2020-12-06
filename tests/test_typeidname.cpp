

#include <gtest/gtest.h>

#include "memman.h"

typedef struct {
    int a;
    int b[5];
    double v;
    struct {
        float q;
    } my_struct;
} custom_type_t1;

typedef struct {
    int a;
    int b[5];
    double v;
    struct {
        float q;
    } my_struct;
} custom_type_t2;

typedef union {
    int a;
    int b;
    custom_type_t2 c;
} custom_type_t3;

MM_TYPE_REGISTER(int);
MM_TYPE_REGISTER(char);
MM_TYPE_REGISTER(custom_type_t1);
MM_TYPE_REGISTER(custom_type_t2);
MM_TYPE_REGISTER(custom_type_t3);

TEST(TestTypeidname, TestIntSameId)
{
    ASSERT_EQ(MM_TYPEIDNAME(int), MM_TYPEIDNAME(int));
}

TEST(TestTypeidname, TestCustomSameId)
{
    ASSERT_EQ(MM_TYPEIDNAME(custom_type_t1), MM_TYPEIDNAME(custom_type_t1));
}

TEST(TestTypeidname, TestIntCharDifferentId)
{
    ASSERT_NE(MM_TYPEIDNAME(int), MM_TYPEIDNAME(char));
}

TEST(TestTypeidname, TestIntCustomDifferentId)
{
    ASSERT_NE(MM_TYPEIDNAME(int), MM_TYPEIDNAME(custom_type_t1));
}

TEST(TestTypeidname, TestCharCustomDifferentId)
{
    ASSERT_NE(MM_TYPEIDNAME(char), MM_TYPEIDNAME(custom_type_t1));
}

TEST(TestTypeidname, TestCopyCustomDifferentId)
{
    ASSERT_NE(MM_TYPEIDNAME(custom_type_t1), MM_TYPEIDNAME(custom_type_t2));
}

TEST(TestTypeidname, TestCustomUCustomStrDifferentId)
{
    ASSERT_NE(MM_TYPEIDNAME(custom_type_t3), MM_TYPEIDNAME(custom_type_t2));
}

TEST(TestTypeidname, TestTypeidnameNotChangingWithInterference)
{
    const auto initial_value = MM_TYPEIDNAME(custom_type_t1);
    [[maybe_unused]] const auto interference = MM_TYPEIDNAME(int);
    const auto final_value = MM_TYPEIDNAME(custom_type_t1);

    ASSERT_EQ(initial_value, final_value);
}

TEST(TestTypeidname, TestIntTypeidnameNotChangingMultiple)
{
    const auto initial_value = MM_TYPEIDNAME(int);
    
    const size_t num_iterations = 10;
    for (size_t i = 0; i < num_iterations; ++i)
    {
        ASSERT_EQ(initial_value, MM_TYPEIDNAME(int));
    }
}

TEST(TestTypeidname, TestCustomTypeidnameNotChangingMultiple)
{
    const auto initial_value = MM_TYPEIDNAME(custom_type_t1);
    
    const size_t num_iterations = 10;
    for (size_t i = 0; i < num_iterations; ++i)
    {
        ASSERT_EQ(initial_value, MM_TYPEIDNAME(custom_type_t1));
    }
}