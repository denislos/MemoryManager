

#include <gtest/gtest.h>

#include "memman.h"


TEST(TestVerifyEmpty, TestTentative) 
{
    [[maybe_unused]] int *first = MM_ALLOC(int);
    [[maybe_unused]] char *second = MM_ALLOC(char);
    // TODO uncomment when done
    // ASSERT_FALSE(MM_VERIFY_EMPTY());
    MM_DEALLOC(first);
    MM_DEALLOC(second);
    ASSERT_TRUE(MM_VERIFY_EMPTY());
}