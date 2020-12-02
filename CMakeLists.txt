cmake_minimum_required(VERSION 3.10)

project(MemoryManager)

set(CMAKE_C_STANDARD 11)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(BUILD_SHARED_LIBS ON)
add_subdirectory(external/googletest)


file(GLOB TEST_SRCS
    "tests/test_ci.cpp"
    "tests/test_main.cpp"
)

set(TEST_EXECUTABLE memman_test)

add_executable(${TEST_EXECUTABLE} ${TEST_SRCS})
target_link_libraries(${TEST_EXECUTABLE} PUBLIC gtest gtest_main)
target_compile_options(${TEST_EXECUTABLE} PUBLIC -Wall -Werror -Wextra)

add_test(
    NAME MemoryManagerTest
    COMMAND ./${TEST_EXECUTABLE}
)

enable_testing()