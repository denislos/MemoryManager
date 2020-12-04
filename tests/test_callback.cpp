

#include "gtest/gtest.h"

#include "memman.h"

#include <iostream>

TEST(TestCallback, TestInit) { mm_init(); }

void return_func(void *addr, int code) {
  std::cout << "Error in " << addr << "code " << code << "\n";
}
TEST(TestCallback, TestAttachCallback) { mm_attach_callback(return_func); }