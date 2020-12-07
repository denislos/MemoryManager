

#include <gtest/gtest.h>

#include "memman.h"

#include <stdio.h>
#include <string.h>

typedef struct {
    int i;
    char c;
} custom_t;

void dummy_callback([[maybe_unused]] void *addr, [[maybe_unused]] int code) {

}

MM_TYPE_REGISTER(int);
MM_TYPE_REGISTER(char);
MM_TYPE_REGISTER(custom_t);

TEST(TestVerifyPtr, TestNull)
{
    mm_init();
    mm_attach_callback(dummy_callback);

    EXPECT_FALSE(MM_VERIFY_PTR(NULL, int));
    EXPECT_FALSE(MM_VERIFY_PTR(NULL, char));
    EXPECT_FALSE(MM_VERIFY_PTR(NULL, custom_t));
}

TEST(TestVerifyPtr, TestTypeMatching)
{
    mm_init();
    mm_attach_callback(dummy_callback);

    int *iptr = MM_ALLOC(int);
    char *cptr = MM_ALLOC(char);
    custom_t *custom_ptr = MM_ALLOC(custom_t);

    EXPECT_TRUE(MM_VERIFY_PTR(iptr, int));
    EXPECT_TRUE(MM_VERIFY_PTR(cptr, char));
    EXPECT_TRUE(MM_VERIFY_PTR(custom_ptr, custom_t));

    EXPECT_FALSE(MM_VERIFY_PTR(iptr, char));
    EXPECT_FALSE(MM_VERIFY_PTR(iptr, custom_t));

    EXPECT_FALSE(MM_VERIFY_PTR(cptr, int));
    EXPECT_FALSE(MM_VERIFY_PTR(cptr, custom_t));
    
    EXPECT_FALSE(MM_VERIFY_PTR(custom_ptr, int));
    EXPECT_FALSE(MM_VERIFY_PTR(custom_ptr, char));

    MM_DEALLOC(iptr);
    MM_DEALLOC(cptr);
    MM_DEALLOC(custom_ptr);
}

void error_callback([[maybe_unused]] void *addr, [[maybe_unused]] int code) {
    fprintf(stderr, "error\n");
    exit(code);
}


TEST(TestVerifyPtr, TestTypeDisRep)
{
    mm_init();
    mm_attach_callback(error_callback);

    int *iptr = MM_ALLOC(int);

    EXPECT_EXIT(MM_VERIFY_PTR(iptr, char),
                testing::ExitedWithCode(TYPE_DISREP), "error");
   
    MM_DEALLOC(iptr);
}


