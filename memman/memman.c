#include "memman.h"

#ifdef __cplusplus
extern "C" {
#endif

void (*_mm_callback_)(void* addr, int code);

void mm_attach_callback(void (*callback)(void* addr, int code))
{
	_mm_callback_ = callback;
}

void mm_init()
{
	_mm_callback_ = 0;
}

void* _mm_alloc_(size_t size, int type_id)
{
	MM_UNITNAME(MM_TEMPLATE)* unit = (MM_UNITNAME(MM_TEMPLATE) * )malloc(size);
	if (!unit) return 0;
	unit->busy = 1;
	unit->type_id = type_id;
	return (void*)unit;
}

void _mm_free_(void* ptr)
{
	MM_UNITNAME(MM_TEMPLATE)* unit = MM_UNIT_HDR(ptr);
	unit->busy = 0;
	free((void*)unit);
}

#ifdef __cplusplus
}
#endif
