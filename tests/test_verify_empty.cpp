

#include <gtest/gtest.h>

#include "memman.h"

MM_TYPE_REGISTER(int);
MM_TYPE_REGISTER(char);

TEST(TestVerifyEmpty, TestTentative) 
{
    [[maybe_unused]] int *first = MM_ALLOC(int);
    [[maybe_unused]] char *second = MM_ALLOC(char);
    // TODO uncomment when done
    MM_DEALLOC(first);
    MM_DEALLOC(second);
    //ASSERT_FALSE(MM_VERIFY_EMPTY);
}