

#ifndef MEMMAN_INTERNAL_H
#define MEMMAN_INTERNAL_H

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stddef.h>


// converts a type name WITHOUT qualifiers to constant name
#define MM_TYPEIDNAME(type) _mm_typeidname_##type()
#define MM_UNITNAME(type) __MM_UNIT_##type##__
#define MM_BLOCKNAME(type) __MM_BLOCK_##type##__

#define MM_BLOCKSIZE_DEFAULT 4096

#ifndef MM_BLOCKSIZE
#define MM_BLOCKSIZE MM_BLOCKSIZE_DEFAULT
#endif

#ifndef MM_CANARY_VAL
#define MM_CANARY_VAL 0x55555555
#endif


enum
{
	OK = 0,
	TYPE_DISREP,
	EMPTY_PTR_OP,
	ALLOCK_NOT_EMPTY,
	CANARY_DEAD,
	ALLOCK_TOO_LARGE,
};

typedef struct
{
	size_t cur_offset;
	int units_used;
	char data[MM_BLOCKSIZE];
} __mm_block__;

#define MM_UNITSTR(type) typedef struct \
{\
	int busy;\
	int type_id;\
	__mm_block__* hdr;\
	size_t size;\
	int canary;\
	type data;\
} __attribute__((packed)) MM_UNITNAME(type) ;

typedef void* MM_TEMPLATE;
MM_UNITSTR(MM_TEMPLATE);

#define MM_UNIT_HDR(ptr)  ((MM_UNITNAME(MM_TEMPLATE)*)((char*)ptr - offsetof(MM_UNITNAME(MM_TEMPLATE), data)))
#define MM_DATA_PTR(strptr) (strptr ? &(((MM_UNITNAME(MM_TEMPLATE)*)strptr)->data) : MM_NULLPTR)

#ifdef __cplusplus
extern "C" {
#endif
extern size_t _mm_type_global_counter;

void* _mm_alloc_(size_t size, int type_id);
void _mm_free_(void* ptr);
int _mm_compare_(void* ptr1, void* ptr2);
int _mm_verify_(void* ptr, int type_id);
int _mm_verify_empty_();

void mm_attach_callback(void (*callback)(void* addr, int code));
void mm_init();

#ifdef __cplusplus
}
#endif

#endif // MEMMAN_INTERNAL_H