#include "memman.h"

#ifdef __cplusplus
extern "C" {
#endif

static void (*_mm_callback_)(void* addr, int code);
static unsigned int _mm_global_alloc_;

void mm_attach_callback(void (*callback)(void* addr, int code))
{
	_mm_callback_ = callback;
}

static void _mm_default_callback_(void* addr, int code)
{
	printf("Memory Manager error addr %X code %d", addr, code);
	exit(code);
}

void mm_init()
{
	_mm_callback_ =_mm_default_callback_;
}

void* _mm_alloc_(size_t size, int type_id)
{
	MM_UNITNAME(MM_TEMPLATE)* unit = (MM_UNITNAME(MM_TEMPLATE) * )malloc(size);
	if (!unit) return 0;
	unit->busy = 1;
	unit->size = size;
	_mm_global_alloc_ += size;
	unit->type_id = type_id;
	return (void*)unit;
}

void _mm_free_(void* ptr)
{
	MM_UNITNAME(MM_TEMPLATE)* unit;

	if (ptr)
	{
		unit = MM_UNIT_HDR(ptr);
	}
	else
	{
		_mm_callback_(ptr, EMPTY_PTR_OP);
		return;
	}

	if(!unit->busy)
	{
		_mm_callback_(ptr, EMPTY_PTR_OP);
		return;
	}

	unit->busy = 0;
	_mm_global_alloc_ += unit->size;
	free((void*)unit);
}

int _mm_compare_(void* ptr1, void* ptr2)
{
	MM_UNITNAME(MM_TEMPLATE) *unit1, *unit2;
	if (ptr1 && ptr2)
	{
		unit1 = MM_UNIT_HDR(ptr1);
		unit2 = MM_UNIT_HDR(ptr2);
		if (unit1->type_id != unit2->type_id)
		{
			_mm_callback_(ptr1, TYPE_DISREP);
			return 0;
		}
		if (!unit1->busy)
		{
			_mm_callback_(ptr1, EMPTY_PTR_OP);
			return 0;
		}
		if (!unit2->busy)
		{
			_mm_callback_(ptr2, EMPTY_PTR_OP);
			return 0;
		}
		return ptr1 == ptr2;
	}
	return !(ptr1 || ptr2);
}

void _mm_verify_(void* ptr, int type_id)
{
	MM_UNITNAME(MM_TEMPLATE)* unit;
	if (!ptr) return;
	unit = MM_UNIT_HDR(ptr);
	if (!unit->busy) 
		_mm_callback_(ptr, EMPTY_PTR_OP);
	if (unit->type_id != type_id)
		_mm_callback_(ptr, TYPE_DISREP);
	return;
}

void _mm_verify_empty_()
{
	if(_mm_global_alloc_) _mm_callback_(0, ALLOCK_NOT_EMPTY);
}

#ifdef __cplusplus
}
#endif
