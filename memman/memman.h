

#ifndef MEMMAN_H
#define MEMMAN_H

#include "memman_internal.h"

// defines an integer constant for type identification, unique for each call
#define MM_TYPE_REGISTER(type)                                                            \
static inline size_t _mm_typeidname_##type() {                                            \
	static size_t type_index = 0;                                                     \
	return (type_index == 0) ? (type_index = ++_mm_type_global_counter) : type_index; \
}                                                                                         \
MM_UNITSTR(type);


#define MM_ALLOC(type) ((type*)_mm_alloc_(sizeof(MM_UNITNAME(type)), MM_TYPEIDNAME(type)))
#define MM_DEALLOC(ptr) _mm_free_((void*)ptr)
#define MM_COMPARE(ptr1, ptr2) _mm_compare_(ptr1, ptr2)
#define MM_DEREF(ptr, type) (type*)(_mm_verify_(ptr, MM_TYPEIDNAME(type)) ? ptr : MM_NULLPTR)
#define MM_VERIFY_PTR(ptr, type) _mm_verify_(ptr, MM_TYPEIDNAME(type))
#define MM_VERIFY_EMPTY() _mm_verify_empty_()

#define MM_NULLPTR NULL


#endif // MEMMAN_H
