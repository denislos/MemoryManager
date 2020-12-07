cmake_minimum_required(VERSION 3.10)

project(MemoryManager)

set(CMAKE_C_STANDARD 11)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(BUILD_SHARED_LIBS ON)
add_subdirectory(external/googletest)

include(cmake/GoogleTest.cmake)

include_directories(memman)

file(GLOB MEMMAN_SRCS
    "memman/memman.c"
)

set(MEMMAN_LIB memman)

add_library(${MEMMAN_LIB} SHARED ${MEMMAN_SRCS})
target_compile_options(${MEMMAN_LIB} PUBLIC -O3 -Wall -Werror -Wextra -Wno-unused-function)


file(GLOB TEST_SRCS
    "tests/test_typeidname.cpp"
    "tests/test_alloc_dealloc.cpp"
    "tests/test_callback.cpp"
    "tests/test_compare.cpp"
    "tests/test_deref.cpp"
    "tests/test_verify_empty.cpp"
    "tests/test_verify_ptr.cpp"
    "tests/test_main.cpp"
)

set(TEST_EXECUTABLE memman_test)

add_executable(${TEST_EXECUTABLE} ${TEST_SRCS})
target_link_libraries(${TEST_EXECUTABLE} PUBLIC gtest gtest_main ${MEMMAN_LIB})
target_compile_options(${TEST_EXECUTABLE} PUBLIC -Wall -Werror -Wextra -Wno-unused-function)

gtest_discover_tests(${TEST_EXECUTABLE})

enable_testing()


file(GLOB DEMO_SRCS
    "demo/demo.c"
    "demo/tree.c"
)

set(DEMO_EXECUTABLE memman_demo)

add_executable(${DEMO_EXECUTABLE} ${DEMO_SRCS})
target_link_libraries(${DEMO_EXECUTABLE} PUBLIC ${MEMMAN_LIB})
target_compile_options(${DEMO_EXECUTABLE} PUBLIC -Wall -Werror -Wextra)