

#include <gtest/gtest.h>

#include "memman.h"

MM_TYPE_REGISTER(int);
MM_TYPE_REGISTER(char);

TEST(TestAllocDealloc, TestAllocDeallocIntSimple)
{
    [[maybe_unused]] int *ptr = MM_ALLOC(int);
    MM_DEALLOC(ptr);
}

TEST(TestAllocDealloc, TestAllocDeallocCharSimple) 
{
    [[maybe_unused]] char *ptr = MM_ALLOC(char);
    MM_DEALLOC(ptr);
}