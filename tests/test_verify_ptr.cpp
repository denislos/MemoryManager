

#include <gtest/gtest.h>

#include "memman.h"

MM_TYPE_REGISTER(int);
MM_TYPE_REGISTER(char);
MM_TYPE_REGISTER(double);

typedef struct custom_type_t {
    char b[3];

    bool operator==(const custom_type_t& rhs) const {
        return (b[0] == rhs.b[0]) &
               (b[1] == rhs.b[1]) &
               (b[2] == rhs.b[2]);
         
    }
} custom_type_t;

MM_TYPE_REGISTER(custom_type_t);

static void test_callback_([[maybe_unused]] void* addr, [[maybe_unused]] int code)
{
    fprintf(stderr, "Error");
    exit(code);
}

TEST(TestVerifyPtr, TestCheckIntAllocCorrect)
{
    int* ptr = MM_ALLOC(int);
    ASSERT_TRUE(MM_VERIFY_PTR(ptr, int));
    MM_DEALLOC(ptr);
}

TEST(TestVerifyPtr, TestCheckIntAllocIncorrectType)
{
    mm_init();
    mm_attach_callback(test_callback_);

    int* ptr = MM_ALLOC(int);
    EXPECT_EXIT(MM_VERIFY_PTR(ptr, char),
                testing::ExitedWithCode(TYPE_DISREP), "Error");
    MM_DEALLOC(ptr);
}

TEST(TestVerifyPtr, TestCheckAfterDealloc)
{
    mm_init();
    mm_attach_callback(test_callback_);

    char* ptr = MM_ALLOC(char);
    MM_DEALLOC(ptr);
    EXPECT_EXIT(MM_VERIFY_PTR(ptr, char),
                testing::ExitedWithCode(EMPTY_PTR_OP), "Error");
}


TEST(TestVerifyPtr, TestCheckWrite)
{
    mm_init();
    mm_attach_callback(test_callback_);

    char* c_ptr = MM_ALLOC(char);
    int*  i_ptr = MM_ALLOC(int);
    *i_ptr = 0xDEADCADA;
    *c_ptr = 0xFF;

    ASSERT_TRUE(MM_VERIFY_PTR(c_ptr, char));
    ASSERT_TRUE(MM_VERIFY_PTR(i_ptr, int));
    
    MM_DEALLOC(i_ptr);
    MM_DEALLOC(c_ptr);
}

TEST(TestVerifyPtr, VerifyPtrWriteCheckAfterDealloc)
{
    mm_init();
    mm_attach_callback(test_callback_);

    char* a = MM_ALLOC(char);
    char* b = MM_ALLOC(char);

    const char value_a = 'a';
    const char value_b = 'b';

    *a = value_a;
    *b = value_b;

    MM_DEALLOC(b);

    ASSERT_EQ(*a, value_a);

    MM_DEALLOC(a);
}

TEST(TestVerifyPtr, VerifyPtrWriteCustomCheckAfterDealloc)
{
    mm_init();
    mm_attach_callback(test_callback_);

    custom_type_t* a = MM_ALLOC(custom_type_t);
    custom_type_t* b = MM_ALLOC(custom_type_t);

    const custom_type_t value_a = {
        .b = {-3, 2, 9}
    };

    *a = value_a;

    MM_DEALLOC(b);

    ASSERT_EQ(*a, value_a);

    MM_DEALLOC(a);
}