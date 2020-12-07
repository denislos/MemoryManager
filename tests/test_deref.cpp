

#include "gtest/gtest.h"

#include "memman.h"

MM_TYPE_REGISTER(int);
MM_TYPE_REGISTER(double);
MM_TYPE_REGISTER(char);

typedef struct {
	int a;
	char b;
	double d;
} type_1;

typedef struct {
	int a;
	char b;
	double d;
} type_2;

MM_TYPE_REGISTER(type_1);
MM_TYPE_REGISTER(type_2);

TEST(TestDeref, TestDerefPtrs)
{
	{
		int* _fi_ptr = MM_ALLOC(int);
		int* _si_ptr = MM_DEREF(_fi_ptr, int);

		ASSERT_EQ(_fi_ptr, _si_ptr);

		MM_DEALLOC(_fi_ptr);
	}
	
	{
		double* _fi_ptr = MM_ALLOC(double);
		double* _si_ptr = MM_DEREF(_fi_ptr, double);

		ASSERT_EQ(_fi_ptr, _si_ptr);

		MM_DEALLOC(_fi_ptr);
	}
	
	{
		char* _fi_ptr = MM_ALLOC(char);
		char* _si_ptr = MM_DEREF(_fi_ptr, char);

		ASSERT_EQ(_fi_ptr, _si_ptr);

		MM_DEALLOC(_fi_ptr);
	}
}

TEST(TestDeref, TestDerefValues)
{
	{
		const int elem = 6; 
		
		int* _fi_ptr = MM_ALLOC(int);
		*_fi_ptr = elem;
		int* _si_ptr = MM_DEREF(_fi_ptr, int);

		ASSERT_EQ(elem, *_si_ptr);

		MM_DEALLOC(_fi_ptr);
	}
	
	{
		const double elem = 6.01;
		
		double* _fi_ptr = MM_ALLOC(double);
		*_fi_ptr = elem;
		double* _si_ptr = MM_DEREF(_fi_ptr, double);

		ASSERT_EQ(elem, *_si_ptr);

		MM_DEALLOC(_fi_ptr);
	}
	
	{
		const char elem = 'm';
		
		char* _fi_ptr = MM_ALLOC(char);
		*_fi_ptr = elem;
		char* _si_ptr = MM_DEREF(_fi_ptr, char);

		ASSERT_EQ(elem, *_si_ptr);

		MM_DEALLOC(_fi_ptr);
	}
}

void return_func2([[maybe_unused]] void *addr, [[maybe_unused]] int code) {
	// for invalid cases;
}

TEST(TestDeref, TestDerefInvalidCases)
{	
	mm_init();
	mm_attach_callback(return_func2);
	
	{
		int* _fi_ptr = MM_ALLOC(int);
		ASSERT_EQ(MM_DEREF(_fi_ptr, double), (double*)MM_NULLPTR);
		MM_DEALLOC(_fi_ptr);
	}
	
	{
		double* _fi_ptr = MM_ALLOC(double);
		ASSERT_EQ(MM_DEREF(_fi_ptr, char), (char*)MM_NULLPTR);
		MM_DEALLOC(_fi_ptr);
	}
	
	{
		char* _fi_ptr = MM_ALLOC(char);
		ASSERT_EQ(MM_DEREF(_fi_ptr, int), (int*)MM_NULLPTR);
		MM_DEALLOC(_fi_ptr);
	}
}


TEST(TestDeref, TestDerefDifferentTypesWithCommonStructure)
{		
	mm_init();
	mm_attach_callback(return_func2);
	
	{
		type_1* _fi_ptr = MM_ALLOC(type_1);
		type_2* _si_ptr = MM_ALLOC(type_2);;

		ASSERT_EQ(_fi_ptr, MM_DEREF(_fi_ptr, type_1));
		ASSERT_EQ(_si_ptr, MM_DEREF(_si_ptr, type_2));
		
		ASSERT_EQ(MM_DEREF(_fi_ptr, type_2),(type_2*)MM_NULLPTR);
		ASSERT_EQ(MM_DEREF(_si_ptr, type_1),(type_1*)MM_NULLPTR);

		MM_DEALLOC(_fi_ptr);
		MM_DEALLOC(_si_ptr);
	}
}
