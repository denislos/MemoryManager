

#include <gtest/gtest.h>

#include "memman.h"

MM_TYPE_REGISTER(int);
MM_TYPE_REGISTER(char);

typedef struct {
    int a;
    int b[5];
    double v;
    struct {
        float q;
    } my_struct;
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

TEST(TestTypeidname, TestTypeidnameNotChangingWithInterference)
{
    const auto initial_value = MM_TYPEIDNAME(custom_type_t);
    [[maybe_unused]] const auto interference = MM_TYPEIDNAME(int);
    const auto final_value = MM_TYPEIDNAME(custom_type_t);

    ASSERT_EQ(initial_value, final_value);
}

TEST(TestTypeidname, TestTypeidnameNotChangingMultiple)
{
    const auto initial_value = MM_TYPEIDNAME(custom_type_t);
    
    const size_t num_iterations = 10;
    for (size_t i = 0; i < num_iterations; ++i)
        ASSERT_EQ(initial_value, MM_TYPEIDNAME(custom_type_t)); 
}