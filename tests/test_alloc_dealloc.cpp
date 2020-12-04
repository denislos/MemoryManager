

#include <gtest/gtest.h>

#include "memman.h"

#include <unordered_set>
#include <variant>
#include <vector>


MM_TYPE_REGISTER(int);
MM_TYPE_REGISTER(char);

typedef struct {
    double s[50];
    int k;
    struct {
        struct {
            int a[10];
        } m;
        float f;
    } u[3];
} custom_type_t;

MM_TYPE_REGISTER(custom_type_t);


TEST(TestAllocDealloc, TestAllocDeallocIntSimple)
{
    [[maybe_unused]] int *ptr = MM_ALLOC(int);

    ASSERT_TRUE(ptr != NULL);

    MM_DEALLOC(ptr);
}

TEST(TestAllocDealloc, TestAllocDeallocCharSimple) 
{
    [[maybe_unused]] char *ptr = MM_ALLOC(char);

    ASSERT_TRUE(ptr != NULL);

    MM_DEALLOC(ptr);
}

TEST(TestAllocDealloc, TestAllocDeallocCustomSimpleNotNull)
{
    [[maybe_unused]] custom_type_t *ptr = MM_ALLOC(custom_type_t);
    
    ASSERT_TRUE(ptr != NULL);

    MM_DEALLOC(ptr);
}

TEST(TestAllocDealloc, TestAllocDeallocCustomMultipleNotNull)
{
    constexpr const size_t num_iterations = 10000;
    custom_type_t* ptr_array[num_iterations];

    for (size_t i = 0; i < num_iterations; ++i)
        ptr_array[i] = MM_ALLOC(custom_type_t);

    for (size_t i = 0; i < num_iterations; ++i)
        ASSERT_TRUE(ptr_array[i] != NULL);

    for (size_t i = 0; i < num_iterations; ++i)
        MM_DEALLOC(ptr_array[i]);
}

TEST(TestAllocDealloc, TestAllocDeallocCustomMultipleAllDifferent)
{
    constexpr const size_t num_iterations = 20000;
    std::unordered_set<custom_type_t*> ptr_set;

    for (size_t i = 0; i < num_iterations; ++i)
        ptr_set.insert(MM_ALLOC(custom_type_t));

    /* ASSERT_EQ(ptr_set.size(), num_iterations); */ // fix me

    for ([[maybe_unused]] auto ptr : ptr_set) // fix me
        MM_DEALLOC(ptr);
}

TEST(TestAllocDealloc, TestAllocDeallocCustomIntMultipleIntertwiningNotNull)
{
    constexpr const size_t num_iterations = 15000;
    std::vector<int*> int_ptr_array;
    std::vector<custom_type_t*> custom_ptr_array;

    for (size_t i = 0; i < num_iterations; ++i)
        if (i & 1)
            int_ptr_array.push_back((int*)MM_ALLOC(int)); // FIX ME
        else
            custom_ptr_array.push_back((custom_type_t*)MM_ALLOC(custom_type_t)); // FIX ME

    for ([[maybe_unused]]auto ptr : int_ptr_array) { // fix me
        ASSERT_TRUE(ptr != NULL);
        MM_DEALLOC(ptr);
    }

    for ([[maybe_unused]]auto ptr : custom_ptr_array) { // fix me
        ASSERT_TRUE(ptr != NULL);
        MM_DEALLOC(ptr);
    }
}