

#include "gtest/gtest.h"

#include "memman.h"

#include <stdio.h>

MM_TYPE_REGISTER(int);
MM_TYPE_REGISTER(char);

TEST(TestCallback, TestInit) { mm_init(); }

void return_func([[maybe_unused]] void *addr, int code) {
 code += 1;
  fprintf(stderr, "Error");
  exit(0);
}

TEST(TestCallback, TestDefaultCallbackRet) {
  mm_init();
  mm_attach_callback(return_func);
  int *data = MM_ALLOC(int);
  EXPECT_EXIT([[maybe_unused]] char *d = MM_DEREF(data, char),
              testing::ExitedWithCode(0), "");
  MM_DEALLOC(data);
}

TEST(TestCallback, TestAttachCallback) {
  mm_init();
  mm_attach_callback(return_func);
  int *data = MM_ALLOC(int);
  EXPECT_EXIT([[maybe_unused]] char *d = MM_DEREF(data, char),
              testing::ExitedWithCode(0), "Error");
  MM_DEALLOC(data);
}
TEST(TestCallback, TestWrongDeref) {
  mm_init();
  mm_attach_callback(return_func);
  int *data = MM_ALLOC(int);
  EXPECT_EXIT([[maybe_unused]] char *d = MM_DEREF(data, char),
              testing::ExitedWithCode(0), "Error");
  MM_DEALLOC(data);
}
TEST(TestCallback, TestWrongCompare1) {
  mm_init();
  mm_attach_callback(return_func);
  int *data1 = MM_ALLOC(int);
  int *data2 = MM_ALLOC(int);
  MM_DEALLOC(data1);
  // wtf fail
  EXPECT_EXIT([[maybe_unused]]bool d = MM_COMPARE(data1, data2),
  testing::ExitedWithCode(0), "Error");
  MM_DEALLOC(data2);
}
TEST(TestCallback, TestWrongCompare2) {
  mm_init();
  mm_attach_callback(return_func);
  int *data1 = MM_ALLOC(int);
  int *data2 = MM_ALLOC(int);
  MM_DEALLOC(data2);
  // wft fail
  EXPECT_EXIT([[maybe_unused]]bool d = MM_COMPARE(data1, data2),
  testing::ExitedWithCode(0), "Error");
  MM_DEALLOC(data1);
}
TEST(TestCallback, TestWrongCompare3) {
  mm_init();
  mm_attach_callback(return_func);
  int *data1 = MM_ALLOC(int);
  char *data2 = MM_ALLOC(char);
  EXPECT_EXIT([[maybe_unused]] bool d = MM_COMPARE(data1, data2),
              testing::ExitedWithCode(0), "Error");
  MM_DEALLOC(data1);
  MM_DEALLOC(data2);
}
TEST(TestCallback, TesTFree1) {
  mm_init();
  mm_attach_callback(return_func);
  char *data2 = MM_ALLOC(char);
  MM_DEALLOC(data2);
  // wtf, not die
  EXPECT_EXIT(MM_DEALLOC(data2), testing::ExitedWithCode(0),
   "Error");
}
TEST(TestCallback, TesTFree2) {
  mm_init();
  mm_attach_callback(return_func);
  EXPECT_EXIT(MM_DEALLOC(MM_NULLPTR), testing::ExitedWithCode(0),
              "Error");
}
TEST(TestCallback, verifyPtr) {
  mm_init();
  mm_attach_callback(return_func);
  char *data2 = MM_ALLOC(char);
  // wtf not dead
  EXPECT_EXIT([[maybe_unused]]bool d = MM_VERIFY_PTR(data2, int),
  testing::ExitedWithCode(0), "Error");
  MM_DEALLOC(data2);
}
TEST(TestCallback, verifyEmpty) {
  mm_init();
  mm_attach_callback(return_func);
  char *data2 = MM_ALLOC(char);
  // wft not dead
  EXPECT_EXIT([[maybe_unused]]bool d = MM_VERIFY_EMPTY,
  testing::ExitedWithCode(0), "Error");
  MM_DEALLOC(data2);
}
