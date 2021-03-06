# MemoryManager

`memman` is a fast C library that enables smart memory allocation, type checking, memory leakage and memory bounds checking. 

## API

#### `Callback funсtion` ####
If any runtime problem appears, this function is called to signal user about error. Default function just prints address and error code, after which calls exit(). 

You can change it by calling `void mm_attach_callback(void (*callback)(void* addr, int code))`.

 
#### `MM_TYPE_REGISTER(type)` ####
Registers a C type in `memman` infrastructure. This routine should be treated as declaration and should be called in a global scope. For every type used in `memman` library registration through this method is required.

````C++
MM_TYPE_REGISTER(int);
MM_TYPE_REGISTER(custom_type_t);
````

#### `type* MM_ALLOC(type)` ####
Allocates dynamically an object of a type `type` and returnes a pointer `type*` to the allocated memory

````C++
double* d = MM_ALLOC(double);
````

If allocation is failed, MM_NULLPTR is returned

If size of structure is too big( >= MM_BLOCK_SIZE) callback function is executed and MM_NULLPTR is returned

#### `MM_DEALLOC(ptr)` ####
Deallocates safely memory at `ptr` with bounds checking and verification



````C++
MM_DEALLOC(d);
````

Can call callback function if:
* invoked with MM_NULLPTR
* invoked with already dealloced pointer
#### `type* MM_DEREF(ptr, type)` ####
Endeavors to convert a type of pointer `ptr` to type* and returns a converted pointer in case of success. If types are not compatible, termination routine is called.

````C++
int* i_ptr = MM_ALLOC(int);
int value = *MM_DEREF(i_ptr, int);
````
#### `int MM_COMPARE(ptr1, ptr2)` ####
Checks whether pointers `ptr1` and `ptr2` are equal. Returns an error if the pointers are not compatible.

````C++
int*  a = MM_ALLOC(int);
int*  b = MM_ALLOC(int);
char* c = MM_ALLOC(char);

MM_COMPARE(a, a);          // returns 1
MM_COMPARE(a, b);          // returns 0
MM_COMPARE(a, MM_NULLPTR); // returns 0
MM_COMPARE(a, c);          // Error: callback routine is called
````

#### `int MM_VERIFY_PTR(ptr, type)` ####
Checks whether a pointer `ptr` references an object of type `type`. In addition, an allocated object and pointer `ptr` are checked for constistency.

````C++
int* a = MM_ALLOC(int);
MM_VERIFY_PTR(a, int); // returns 1
MM_DEALLOC(a);
MM_VERIFY_PTR(a);      // Error: callback routine is called
````

#### `int MM_VERIFY_EMPTY()` ####
Checks whether there is no deallocated memory in the `memman` system. Returns 1 in case of success. Callback routine is called if there is memory leakage.

````C++
char* c = MM_ALLOC(char);
MM_VERIFY_EMPTY(); // Error: memory leakage has been detected, callback routine will be invoked
````

## Demo

You can find application of `memman` library to parsing a toy-tree (DFS) in `demo` folder.

## Integration

In order to integrate `memman` C library into their project, the one should include `memman.h` header file and link with `memman` shared library. 

## Requirements
*   [Cmake](https://cmake.org/) >= 3.10
*   C++ Compiler supporting C++17 standard
*   C Compiler supporting C11 standard

## Cloning the repository

````bash
git clone --recursive https://github.com/denislos/MemoryManager.git
````

## Building the project

````bash
mkdir build && cd build
cmake .. && make
````

## Testing

````bash
ctest --verbose
````
