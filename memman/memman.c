#include "memman.h"

#ifdef __cplusplus
extern "C" {
#endif

// global counter
size_t _mm_type_global_counter = 0u;

void (*_mm_callback_)(void* addr, int code);

void mm_attach_callback(void (*callback)(void* addr, int code))
{
	_mm_callback_ = callback;
}

void mm_init()
{
	_mm_callback_ = 0;
}

#ifdef __cplusplus
}
#endif
