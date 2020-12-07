#include "memman.h"

#ifdef __cplusplus
extern "C" {
#endif

static void (*_mm_callback_)(void* addr, int code);
static unsigned int _mm_global_alloc_, _mm_really_alloc_;
static __mm_block__* _mm_last_allocated_block_ = 0;
size_t _mm_type_global_counter = 0u;

void mm_attach_callback(void (*callback)(void* addr, int code))
{
	_mm_callback_ = callback;
}

static void _mm_default_callback_(void* addr, int code)
{
	printf("Memory Manager error addr %p code %d", addr, code);
	exit(code);
}

void mm_init()
{
	_mm_callback_ =_mm_default_callback_;
	_mm_global_alloc_ = 0;
	_mm_really_alloc_ = 0;
}

void* _mm_alloc_(size_t size, int type_id)
{
	__mm_block__* workblock;
	if (!_mm_last_allocated_block_ || (MM_BLOCKSIZE - _mm_last_allocated_block_->cur_offset < size))
	{
		workblock = (__mm_block__*)malloc(sizeof(__mm_block__));
		if (!workblock) return 0;
		workblock->cur_offset = 0;
		workblock->units_used = 0;
		_mm_last_allocated_block_ = workblock;
		_mm_really_alloc_ += sizeof(__mm_block__);
	}
	workblock = _mm_last_allocated_block_;

	workblock->units_used++;
	MM_UNITNAME(MM_TEMPLATE)* unit = (MM_UNITNAME(MM_TEMPLATE) * )(&workblock->data[workblock->cur_offset]);
	workblock->cur_offset += size;

	unit->busy = 1;
	unit->size = size;
	unit->canary = MM_CANARY_VAL;
	_mm_global_alloc_ += size;
	unit->type_id = type_id;
	unit->hdr = workblock;
	return (void*)MM_DATA_PTR(unit);
}

void _mm_free_(void* ptr)
{
	MM_UNITNAME(MM_TEMPLATE)* unit;
	__mm_block__* workblock;

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
	if (unit->canary != MM_CANARY_VAL)
	{
		_mm_callback_(ptr, CANARY_DEAD);
		return;
	}
	workblock = unit->hdr;
	workblock->units_used--;
	_mm_global_alloc_ -= (unit->size);
	unit->busy = 0;
	unit->type_id = -1;
	unit->canary = 0;
	if (!(workblock->units_used))
	{
		free(workblock);
		_mm_really_alloc_ -= sizeof(__mm_block__);
	}
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
		if (unit1->canary != MM_CANARY_VAL)
		{
			_mm_callback_(ptr1, CANARY_DEAD);
			return 0;
		}
		if (unit2->canary != MM_CANARY_VAL)
		{
			_mm_callback_(ptr2, CANARY_DEAD);
			return 0;
		}

		return ptr1 == ptr2;
	}
	return !(ptr1 || ptr2);
}

int _mm_verify_(void* ptr, int type_id)
{
	MM_UNITNAME(MM_TEMPLATE)* unit;
	if (!ptr) return 1;
	unit = MM_UNIT_HDR(ptr);

	if (!unit->busy)
	{
		_mm_callback_(ptr, EMPTY_PTR_OP);
		return 0;
	}

	if (unit->type_id != type_id)
	{
		_mm_callback_(ptr, TYPE_DISREP);
		return 0;
	}

	if (unit->canary != MM_CANARY_VAL)
	{
		_mm_callback_(ptr, CANARY_DEAD);
		return 0;
	}

	return 1;
}

int _mm_verify_empty_()
{
	if (_mm_global_alloc_)
	{
		_mm_callback_(0, ALLOCK_NOT_EMPTY);
		return 0;
	}
	return 1;
}

#ifdef __cplusplus
}
#endif
