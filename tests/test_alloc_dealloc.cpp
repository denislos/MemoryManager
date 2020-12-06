

#include <gtest/gtest.h>

#include "memman.h"

#include <unordered_set>
#include <variant>
#include <vector>


MM_TYPE_REGISTER(int);
MM_TYPE_REGISTER(char);
MM_TYPE_REGISTER(double);

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

typedef struct {
    double s[50];
    struct {
        struct {
            int a[10];
        } m;
        float f;
        int k;
    } u[3];
} custom_type_y;

MM_TYPE_REGISTER(custom_type_t);
MM_TYPE_REGISTER(custom_type_y);

TEST(TestAllocDealloc, TestAllocDeallocIntSimple)
{
    int *ptr = MM_ALLOC(int);

    ASSERT_TRUE(ptr != NULL);

    MM_DEALLOC(ptr);
}

TEST(TestAllocDealloc, TestAllocDeallocCharSimple)
{
    char *ptr = MM_ALLOC(char);

    ASSERT_TRUE(ptr != NULL);

    MM_DEALLOC(ptr);
}

TEST(TestAllocDealloc, TestAllocDeallocDoubleSimple)
{
    double *ptr = MM_ALLOC(double);

    ASSERT_TRUE(ptr != NULL);

    MM_DEALLOC(ptr);
}

TEST(TestAllocDealloc, TestAllocDeallocCustomSimple1NotNull)
{
    custom_type_t *ptr = MM_ALLOC(custom_type_t);

    ASSERT_TRUE(ptr != NULL);

    MM_DEALLOC(ptr);
}

TEST(TestAllocDealloc, TestAllocDeallocCustomSimple2NotNull)
{
    custom_type_y *ptr = MM_ALLOC(custom_type_y);

    ASSERT_TRUE(ptr != NULL);

    MM_DEALLOC(ptr);
}

TEST(TestAllocDealloc, TestAllocDeallocIntMultipleNotNull)
{
    constexpr const size_t num_iterations = 10000;
    int* ptr_array[num_iterations];

    for (size_t i = 0; i < num_iterations; ++i)
        ptr_array[i] = MM_ALLOC(int);

    for (size_t i = 0; i < num_iterations; ++i)
        ASSERT_TRUE(ptr_array[i] != NULL);

    for (size_t i = 0; i < num_iterations; ++i)
        MM_DEALLOC(ptr_array[i]);
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

    ASSERT_EQ(ptr_set.size(), num_iterations);

    for (auto ptr : ptr_set)
        MM_DEALLOC(ptr);
}

TEST(TestAllocDealloc, TestAllocDeallocCustomIntMultipleIntertwiningNotNull)
{
    constexpr const size_t num_iterations = 15000;
    std::vector<int*> int_ptr_array;
    std::vector<custom_type_t*> custom_ptr_array;

    for (size_t i = 0; i < num_iterations; ++i)
        if (i & 1)
            int_ptr_array.push_back(MM_ALLOC(int));
        else
            custom_ptr_array.push_back(MM_ALLOC(custom_type_t));

    for (auto ptr : int_ptr_array) {
        ASSERT_TRUE(ptr != NULL);
        MM_DEALLOC(ptr);
    }

    for (auto ptr : custom_ptr_array) {
        ASSERT_TRUE(ptr != NULL);
        MM_DEALLOC(ptr);
    }
}

TEST(TestAllocDealloc, TestAllocDeallocCustomCustomMultipleIntertwiningNotNull)
{
    constexpr const size_t num_iterations = 10000;
    std::vector<custom_type_t*> custom_t_ptr_array;
    std::vector<custom_type_y*> custom_y_ptr_array;

    for (size_t i = 0; i < num_iterations; ++i)
        if (i & 1)
            custom_t_ptr_array.push_back(MM_ALLOC(custom_type_t));
        else
            custom_y_ptr_array.push_back(MM_ALLOC(custom_type_y));

    for (auto ptr : custom_t_ptr_array) {
        ASSERT_TRUE(ptr != NULL);
        MM_DEALLOC(ptr);
    }

    for (auto ptr : custom_y_ptr_array) {
        ASSERT_TRUE(ptr != NULL);
        MM_DEALLOC(ptr);
    }
}
