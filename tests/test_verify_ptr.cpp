

#include <gtest/gtest.h>

#include "memman.h"

MM_TYPE_REGISTER(int);
MM_TYPE_REGISTER(char);

TEST(TestVerifyPtr, TestTentative)
{
    [[maybe_unused]] int *first = MM_ALLOC(int);
    [[maybe_unused]] char *second = MM_ALLOC(char);
    //ASSERT_TRUE(MM_VERIFY_PTR(first, int));
    //ASSERT_TRUE(MM_VERIFY_PTR(second, char));
    // TODO uncomment when done
    // EXPECT_FALSE(MM_VERIFY_PTR(second, int));
    // EXPECT_FALSE(MM_VERIFY_PTR(first, char));
    // EXPECT_FALSE(MM_VERIFY_PTR(first, wrong_name));

    MM_DEALLOC(first);
    MM_DEALLOC(second);
}