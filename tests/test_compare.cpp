

#include <gtest/gtest.h>

#include "memman.h"

MM_TYPE_REGISTER(int);
MM_TYPE_REGISTER(char);

void func_for_callback([[maybe_unused]] void *addr, int code) {
  fprintf(stderr, "Error");
  exit(code);
}

TEST(TestCompare, Test1) {
  [[maybe_unused]] int *first = MM_ALLOC(int);
  ASSERT_FALSE(MM_COMPARE(first, MM_NULLPTR));
  MM_DEALLOC(first);
}

TEST(TestCompare, Test2) {
  [[maybe_unused]] int *first = MM_ALLOC(int);
  ASSERT_TRUE(MM_COMPARE(first, first));
  MM_DEALLOC(first);
}

TEST(TestCompare, Test3) {
  mm_init();
  [[maybe_unused]] int *first = MM_ALLOC(int);
  [[maybe_unused]] char *second = MM_ALLOC(char);
  [[maybe_unused]] char *first_ch = (char *)first;
  ASSERT_TRUE(MM_COMPARE(first, first_ch));
  MM_DEALLOC(first);
  MM_DEALLOC(second);
}

TEST(TestCompare, Test4) {
  mm_init();
  mm_attach_callback(func_for_callback);
  int *first = MM_ALLOC(int);
  int *second = MM_ALLOC(int);
  MM_DEALLOC(first);
  EXPECT_EXIT([[maybe_unused]] bool d = MM_COMPARE(first, second),
              testing::ExitedWithCode(EMPTY_PTR_OP), "Error");
  MM_DEALLOC(second);
}

TEST(TestCompare, Test5) {
  mm_init();
  mm_attach_callback(func_for_callback);
  int *first = MM_ALLOC(int);
  int *second = MM_ALLOC(int);
  MM_DEALLOC(first);
  EXPECT_EXIT([[maybe_unused]] bool d = MM_COMPARE(first, second),
              testing::ExitedWithCode(EMPTY_PTR_OP), "Error");
  MM_DEALLOC(second);
}

TEST(TestCompare, Test6) {
  mm_init();
  mm_attach_callback(func_for_callback);
  int *first = MM_ALLOC(int);
  char *second = MM_ALLOC(char);
  EXPECT_EXIT([[maybe_unused]] bool d = MM_COMPARE(first, second),
              testing::ExitedWithCode(TYPE_DISREP), "Error");
  MM_DEALLOC(first);
  MM_DEALLOC(second);
}