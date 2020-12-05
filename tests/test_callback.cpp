

#include "gtest/gtest.h"

#include "memman.h"

#include <stdio.h>

MM_TYPE_REGISTER(int);
MM_TYPE_REGISTER(char);

TEST(TestCallback, TestInit) { mm_init(); }

TEST(TestCallback, TestDefaultCallbackRet) {
  mm_init();
  int *data = MM_ALLOC(int);
  EXPECT_EXIT([[maybe_unused]] char *d = MM_DEREF(data, char),
              testing::ExitedWithCode(TYPE_DISREP), "");
  MM_DEALLOC(data);
}

void return_func([[maybe_unused]] void *addr, int code) {
  fprintf(stderr, "Error");
  exit(code);
}
TEST(TestCallback, TestAttachCallback) {
  mm_init();
  mm_attach_callback(return_func);
  int *data = MM_ALLOC(int);
  EXPECT_EXIT([[maybe_unused]] char *d = MM_DEREF(data, char),
              testing::ExitedWithCode(TYPE_DISREP), "Error");
  MM_DEALLOC(data);
}
TEST(TestCallback, TestWrongDeref) {
  mm_init();
  mm_attach_callback(return_func);
  int *data = MM_ALLOC(int);
  EXPECT_EXIT([[maybe_unused]] char *d = MM_DEREF(data, char),
              testing::ExitedWithCode(TYPE_DISREP), "Error");
  MM_DEALLOC(data);
}
TEST(TestCallback, TestWrongCompare1) {
  mm_init();
  mm_attach_callback(return_func);
  int *data1 = MM_ALLOC(int);
  int *data2 = MM_ALLOC(int);
  MM_DEALLOC(data1);
  // wtf fail
  // EXPECT_EXIT([[maybe_unused]]bool d = MM_COMPARE(data1, data2),
  // testing::ExitedWithCode(EMPTY_PTR_OP), "Error");
  MM_DEALLOC(data2);
}
TEST(TestCallback, TestWrongCompare2) {
  mm_init();
  mm_attach_callback(return_func);
  int *data1 = MM_ALLOC(int);
  int *data2 = MM_ALLOC(int);
  MM_DEALLOC(data2);
  // wft fail
  // EXPECT_EXIT([[maybe_unused]]bool d = MM_COMPARE(data1, data2),
  // testing::ExitedWithCode(EMPTY_PTR_OP), "Error");
  MM_DEALLOC(data1);
}
TEST(TestCallback, TestWrongCompare3) {
  mm_init();
  mm_attach_callback(return_func);
  int *data1 = MM_ALLOC(int);
  char *data2 = MM_ALLOC(char);
  EXPECT_EXIT([[maybe_unused]] bool d = MM_COMPARE(data1, data2),
              testing::ExitedWithCode(TYPE_DISREP), "Error");
  MM_DEALLOC(data1);
  MM_DEALLOC(data2);
}
TEST(TestCallback, TesTFree1) {
  mm_init();
  mm_attach_callback(return_func);
  char *data2 = MM_ALLOC(char);
  MM_DEALLOC(data2);
  // wtf, not die
  // EXPECT_EXIT(MM_DEALLOC(data2), testing::ExitedWithCode(EMPTY_PTR_OP),
  // "Error");
}
TEST(TestCallback, TesTFree2) {
  mm_init();
  mm_attach_callback(return_func);
  EXPECT_EXIT(MM_DEALLOC(MM_NULLPTR), testing::ExitedWithCode(EMPTY_PTR_OP),
              "Error");
}
TEST(TestCallback, verifyPtr) {
  mm_init();
  mm_attach_callback(return_func);
  char *data2 = MM_ALLOC(char);
  // wtf not dead
  // EXPECT_EXIT([[maybe_unused]]bool d = MM_VERIFY_PTR(data2, char),
  // testing::ExitedWithCode(EMPTY_PTR_OP), "Error");
  MM_DEALLOC(data2);
}
TEST(TestCallback, verifyEmpty) {
  mm_init();
  mm_attach_callback(return_func);
  char *data2 = MM_ALLOC(char);
  // wft not dead
  // EXPECT_EXIT([[maybe_unused]]bool d = MM_VERIFY_EMPTY,
  // testing::ExitedWithCode(EMPTY_PTR_OP), "Error");
  MM_DEALLOC(data2);
}
