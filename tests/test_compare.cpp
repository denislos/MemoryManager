

#include <gtest/gtest.h>

#include "memman.h"

TEST(TestCompare, TestTentative) {
  [[maybe_unused]] int *first = MM_ALLOC(int);
  [[maybe_unused]] char *second = MM_ALLOC(char);
  [[maybe_unused]] char *first_ch = (char *)first;
  ASSERT_TRUE(MM_COMPARE(first, first_ch));
  // TODO uncomment when done
  // EXPECT_FALSE(MM_COMPARE(second, first));
  MM_DEALLOC(first);
  MM_DEALLOC(second);
}