
#include <gtest/gtest.h>

#include "memman.h"

MM_TYPE_REGISTER(int)
MM_TYPE_REGISTER(char)

__MM_UNIT_int__ int1;

TEST(SimpleTest, SimpleTest)
{
    [[maybe_unused]] const auto int_index  = MM_TYPEIDNAME(int);
    [[maybe_unused]] const auto char_index = MM_TYPEIDNAME(char);
}