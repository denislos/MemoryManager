#ifndef MEMMAN_H
#define MEMMAN_H

#include <stdlib.h>
#include <stdint.h>

// global user callback
extern void (*_mm_callback_)(void* addr, int code);

// converts a type name WITHOUT qualifiers to constant name
#define MM_TYPEIDNAME(type) __MM_TYPEID_##type##__
#define MM_UNITNAME(type) __MM_UNIT_##type##__
#define MM_BLOCKNAME(type) __MM_BLOCK_##type##__

#define MM_BLOCKSIZE_DEFAULT 1000

#ifndef MM_BLOCKSIZE
#define MM_BLOCKSIZE MM_BLOCKSIZE_DEFAULT
#endif

#define MM_NULLPTR 0

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
	type data;\
} MM_UNITNAME(type);

typedef void* MM_TEMPLATE;
MM_UNITSTR(MM_TEMPLATE);

#define MM_UNIT_HDR(ptr)  ((MM_UNITNAME(MM_TEMPLATE)*)((char*)ptr - offsetof(MM_UNITNAME(MM_TEMPLATE), data)))
#define MM_DATA_PTR(strptr, type) (type*)(strptr ? &(((MM_UNITNAME(type)*)strptr)->data) : MM_NULLPTR)
 
void* _mm_alloc_(size_t size, int type_id);
void _mm_free_(void* ptr);

//***********************************
//USER INTERFACE
//***********************************
void mm_attach_callback(void (*callback)(void* addr, int code));
void mm_init();
#define MM_DEREF(ptr, type) (check_type(ptr, type) ? (type*)ptr : _mm_callback_(0, 0))
#define MM_ALLOC(type) MM_DATA_PTR(_mm_alloc_(sizeof(MM_UNITNAME(type)), type)
#define MM_DEALLOC(ptr) _mm_free_((void*)ptr)
#define MM_COMPARE(ptr1, ptr2) true
#define MM_VERIFY_PTR(ptr, type) true
#define MM_VERIFY_EMPTY true

// defines an integer constant for type identification, unique for each call
#define MM_TYPE_REGISTER(type) enum{ MM_TYPEIDNAME(type)=__COUNTER__}; \
MM_UNITSTR(type);


//***********************************
//END USER INTERFACE
//***********************************



#endif // MEMMAN_H
