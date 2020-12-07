

#include "gtest/gtest.h"

#include "memman.h"

MM_TYPE_REGISTER(int);
MM_TYPE_REGISTER(char);


static void test_callback_([[maybe_unused]] void* addr, [[maybe_unused]] int code)
{
    // Do nothing
}

typedef struct {
    char arr[MM_BLOCKSIZE/2];
} type_big_t;

MM_TYPE_REGISTER(type_big_t);

TEST(TestVerifyEmpty, TestSimple)
{
    mm_attach_callback(test_callback_);
    ASSERT_EQ(MM_VERIFY_EMPTY(), 1);

    int* int_ptr = MM_ALLOC(int);
    ASSERT_EQ(MM_VERIFY_EMPTY(), 0);
    MM_DEALLOC(int_ptr);
    ASSERT_EQ(MM_VERIFY_EMPTY(), 1);

    char* char_ptr = MM_ALLOC(char);
    ASSERT_EQ(MM_VERIFY_EMPTY(), 0);
    MM_DEALLOC(char_ptr);
    ASSERT_EQ(MM_VERIFY_EMPTY(), 1);
}

TEST(TestVerifyEmpty, TestOneBlock)
{
    mm_attach_callback(test_callback_);
    constexpr size_t NUM_ELEMENTS = MM_BLOCKSIZE/sizeof(char);

    char* arr[NUM_ELEMENTS];

    ASSERT_EQ(MM_VERIFY_EMPTY(), 1);
    for (size_t i = 0; i < NUM_ELEMENTS; i++) {
        arr[i] = MM_ALLOC(char);
        ASSERT_EQ(MM_VERIFY_EMPTY(), 0);
    }

    for (size_t i = 0; i < NUM_ELEMENTS; i++) {
        ASSERT_EQ(MM_VERIFY_EMPTY(), 0);
        MM_DEALLOC(arr[i]);
    }
    ASSERT_EQ(MM_VERIFY_EMPTY(), 1);
}

TEST(TestVerifyEmpty, TestArraysBig)
{
    mm_attach_callback(test_callback_);
    constexpr size_t NUM_ELEMENTS = 100000;

    int* arr_int[NUM_ELEMENTS];
    char* arr_char[NUM_ELEMENTS];

    ASSERT_EQ(MM_VERIFY_EMPTY(), 1);
    for (size_t i = 0; i < NUM_ELEMENTS; i++) {
        arr_int[i] = MM_ALLOC(int);
        arr_char[i] = MM_ALLOC(char);
        ASSERT_EQ(MM_VERIFY_EMPTY(), 0);
    }

    for (size_t i = 0; i < NUM_ELEMENTS; i++) {
        ASSERT_EQ(MM_VERIFY_EMPTY(), 0);
        MM_DEALLOC(arr_int[i]);
        MM_DEALLOC(arr_char[i]);
    }
    ASSERT_EQ(MM_VERIFY_EMPTY(), 1);
}

TEST(TestVerifyEmpty, TestBigData)
{
    mm_attach_callback(test_callback_);
    constexpr size_t NUM_ELEMENTS = 1000;

    type_big_t* arr[NUM_ELEMENTS];

    ASSERT_EQ(MM_VERIFY_EMPTY(), 1);    
    for (size_t i = 0; i < NUM_ELEMENTS; i++) {
        arr[i] = MM_ALLOC(type_big_t);
        ASSERT_EQ(MM_VERIFY_EMPTY(), 0);
    }

    for (size_t i = 0; i < NUM_ELEMENTS; i++) {
        ASSERT_EQ(MM_VERIFY_EMPTY(), 0);
        MM_DEALLOC(arr[i]);
    }
    ASSERT_EQ(MM_VERIFY_EMPTY(), 1);
}