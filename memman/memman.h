#ifndef MEMMAN_H
#define MEMMAN_H

#include <stdlib.h>
#include <stdint.h>

// global counter
extern size_t _mm_type_global_counter;

// global user callback
extern void (*_mm_callback_)(void* addr, int code);

// converts a type name WITHOUT qualifiers to constant name
#define MM_TYPEIDNAME(type) _mm_typeidname_##type()
#define MM_UNITNAME(type) __MM_UNIT_##type##__
#define MM_BLOCKNAME(type) __MM_BLOCK_##type##__

#define MM_BLOCKSIZE_DEFAULT 10

#ifndef MM_BLOCKSIZE
#define MM_BLOCKSIZE MM_BLOCKSIZE_DEFAULT
#endif

//***********************************
//USER INTERFACE
//***********************************

#ifdef __cplusplus
extern "C" {
#endif
void mm_attach_callback(void (*callback)(void* addr, int code));
void mm_init();
#ifdef __cplusplus
}
#endif
#define MM_DEREF(ptr, type) (check_type(ptr, type) ? (type*)ptr : _mm_callback_(0, 0))
#define MM_ALLOC(type) (type*)&_mm_type_global_counter
#define MM_DEALLOC(ptr)
#define MM_COMPARE(ptr1, ptr2) true
#define MM_NULLPTR 0
#define MM_VERIFY_PTR(ptr, type) true
#define MM_VERIFY_EMPTY() true

// defines an integer constant for type identification, unique for each call
#define MM_TYPE_REGISTER(type)                              \
static inline size_t _mm_typeidname_##type() {              \
	static size_t type_index = _mm_type_global_counter++;   \
	return type_index;                                      \
}                                                           \
typedef struct                                              \
{                                                           \
	bool busy;                                              \
	int type_id;                                            \
	void* hdr;                                              \
	type data;                                              \
} MM_UNITNAME(type);


//***********************************
//END USER INTERFACE
//***********************************



#endif // MEMMAN_H
