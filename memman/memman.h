#ifndef MEMMAN_H
#define MEMMAN_H

#include <stdlib.h>

// global user callback
extern void (*_mm_callback_)(void* addr, int code);

// in case of error we call user callback
void mm_attach_callback(void (*callback)(void* addr, int code));
void mm_init();


#define DEREF(ptr, type) (check_type(ptr, type) ? (type*)ptr : _mm_callback_(0, 0))

#define ALLOC(type)

// converts a type name WITHOUT qualifiers to constant name
#define MM_TYPEIDNAME(type) __MM_TYPEID_##type##__
#define MM_UNITNAME(type) __MM_UNIT_##type##__
#define MM_BLOCKNAME(type) __MM_BLOCK_##type##__

#define MM_BLOCKSIZE_DEFAULT 10

#ifndef MM_BLOCKSIZE
#define MM_BLOCKSIZE MM_BLOCKSIZE_DEFAULT
#endif

// defines an integer constant for type identification, unique for each call
#define MM_TYPE_REGISTER(type) enum{ MM_TYPEIDNAME(type)=__COUNTER__}; \
typedef struct \
{\
	bool busy;\
	int type_id;\
	void* hdr;\
	type data;\
} MM_UNITNAME(type);\
typedef struct \
{\
	void* prev;\
	void* next;\
	int used_cnt;\
	MM_UNITNAME(type) data[MM_BLOCKSIZE];\
}MM_BLOCKNAME(type);

#define MM_END_TYPE_REGISTER



#endif MEMMAN_H
