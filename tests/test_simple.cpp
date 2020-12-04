#include <gtest/gtest.h>

#include "memman.h"
#include <iostream>
MM_TYPE_REGISTER(int);
MM_TYPE_REGISTER(char);

TEST(SimpleTest, SimpleTest)
{
    [[maybe_unused]] const auto int_index  = MM_TYPEIDNAME(int);
    [[maybe_unused]] const auto char_index = MM_TYPEIDNAME(char);
}

TEST(Simple, callback_init) { mm_init(); }

void return_func(void *addr, int code) {
  std::cout << "Error in " << addr << "code " << code << "\n";
}
TEST(Simple, attach_callback) { mm_attach_callback(return_func); }

TEST(Simple, MM_ALLOC_DEALLOC) {
  [[maybe_unused]] int *first = MM_ALLOC(int);
  [[maybe_unused]] char *second = MM_ALLOC(char);
  MM_DEALLOC(first);
  MM_DEALLOC(second);
}
TEST(Simple, MM_VERIFY_PTR) {
  [[maybe_unused]] int *first = MM_ALLOC(int);
  [[maybe_unused]] char *second = MM_ALLOC(char);
  ASSERT_TRUE(MM_VERIFY_PTR(first, int));
  ASSERT_TRUE(MM_VERIFY_PTR(second, char));
  // TODO uncomment when done
  // EXPECT_FALSE(MM_VERIFY_PTR(second, int));
  // EXPECT_FALSE(MM_VERIFY_PTR(first, char));
  // EXPECT_FALSE(MM_VERIFY_PTR(first, wrong_name));

  MM_DEALLOC(first);
  MM_DEALLOC(second);
}
TEST(Simple, MM_compare) {
  [[maybe_unused]] int *first = MM_ALLOC(int);
  [[maybe_unused]] char *second = MM_ALLOC(char);
  [[maybe_unused]] char *first_ch = (char *)first;
  ASSERT_TRUE(MM_COMPARE(first, first_ch));
  // TODO uncomment when done
  // EXPECT_FALSE(MM_COMPARE(second, first));
  MM_DEALLOC(first);
  MM_DEALLOC(second);
}
TEST(Simple, MM_VERIFY_EMPTY) {
  [[maybe_unused]] int *first = MM_ALLOC(int);
  [[maybe_unused]] char *second = MM_ALLOC(char);
  // TODO uncomment when done
  // ASSERT_FALSE(MM_VERIFY_EMPTY());
  MM_DEALLOC(first);
  MM_DEALLOC(second);
  ASSERT_TRUE(MM_VERIFY_EMPTY());
}
