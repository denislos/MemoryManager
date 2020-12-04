#ifndef MEMMAN_H
#define MEMMAN_H

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stddef.h>

extern size_t _mm_type_global_counter;

// global user callback
//extern void (*_mm_callback_)(void* addr, int code);
//extern unsigned int _mm_global_alloc_;

// converts a type name WITHOUT qualifiers to constant name
#define MM_TYPEIDNAME(type) _mm_typeidname_##type()
#define MM_UNITNAME(type) __MM_UNIT_##type##__
#define MM_BLOCKNAME(type) __MM_BLOCK_##type##__

#define MM_BLOCKSIZE_DEFAULT 1000

#ifndef MM_BLOCKSIZE
#define MM_BLOCKSIZE MM_BLOCKSIZE_DEFAULT
#endif

#define MM_NULLPTR 0

enum
{
	OK = 0,
	TYPE_DISREP,
	EMPTY_PTR_OP,
	ALLOCK_NOT_EMPTY,
};

typedef struct
{
	size_t cur_offset;
	int units_used;
} __mm_block__;

#define MM_UNITSTR(type) typedef struct \
{\
	int busy;\
	int type_id;\
	__mm_block__* hdr;\
	size_t size;\
	type data;\
} MM_UNITNAME(type);

typedef void* MM_TEMPLATE;
MM_UNITSTR(MM_TEMPLATE);

#define MM_UNIT_HDR(ptr)  ((MM_UNITNAME(MM_TEMPLATE)*)((char*)ptr - offsetof(MM_UNITNAME(MM_TEMPLATE), data)))
#define MM_DATA_PTR(strptr) (strptr ? &(((MM_UNITNAME(MM_TEMPLATE)*)strptr)->data) : MM_NULLPTR)

#ifdef __cplusplus
extern "C" {
#endif

void* _mm_alloc_(size_t size, int type_id);
void _mm_free_(void* ptr);
int _mm_compare_(void* ptr1, void* ptr2);
int _mm_verify_(void* ptr, int type_id);
int _mm_verify_empty_();

//***********************************
//USER INTERFACE
//***********************************
void mm_attach_callback(void (*callback)(void* addr, int code));
void mm_init();

#ifdef __cplusplus
}
#endif

#define MM_DEREF(ptr, type) (type*)(_mm_verify_(ptr, MM_TYPEIDNAME(type)) ? ptr : MM_NULLPTR)
#define MM_ALLOC(type) ((type*)_mm_alloc_(sizeof(MM_UNITNAME(type)), MM_TYPEIDNAME(type)))
#define MM_DEALLOC(ptr) _mm_free_((void*)ptr)
#define MM_COMPARE(ptr1, ptr2) _mm_compare_(ptr1, ptr2)
#define MM_VERIFY_PTR(ptr, type) _mm_verify_(ptr, MM_TYPEIDNAME(type))
#define MM_VERIFY_EMPTY _mm_verify_empty_()

// defines an integer constant for type identification, unique for each call
#define MM_TYPE_REGISTER(type) \
static inline size_t _mm_typeidname_##type() {   \
	static size_t type_index = _mm_type_global_counter++; \
	return type_index; \
} \
MM_UNITSTR(type);


//***********************************
//END USER INTERFACE
//***********************************



#endif // MEMMAN_H
