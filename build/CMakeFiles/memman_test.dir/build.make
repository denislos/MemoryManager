# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alekseyp/MemoryManager

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alekseyp/MemoryManager/build

# Include any dependencies generated for this target.
include CMakeFiles/memman_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/memman_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/memman_test.dir/flags.make

CMakeFiles/memman_test.dir/tests/test_alloc_dealloc.cpp.o: CMakeFiles/memman_test.dir/flags.make
CMakeFiles/memman_test.dir/tests/test_alloc_dealloc.cpp.o: ../tests/test_alloc_dealloc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alekseyp/MemoryManager/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/memman_test.dir/tests/test_alloc_dealloc.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/memman_test.dir/tests/test_alloc_dealloc.cpp.o -c /home/alekseyp/MemoryManager/tests/test_alloc_dealloc.cpp

CMakeFiles/memman_test.dir/tests/test_alloc_dealloc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/memman_test.dir/tests/test_alloc_dealloc.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alekseyp/MemoryManager/tests/test_alloc_dealloc.cpp > CMakeFiles/memman_test.dir/tests/test_alloc_dealloc.cpp.i

CMakeFiles/memman_test.dir/tests/test_alloc_dealloc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/memman_test.dir/tests/test_alloc_dealloc.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alekseyp/MemoryManager/tests/test_alloc_dealloc.cpp -o CMakeFiles/memman_test.dir/tests/test_alloc_dealloc.cpp.s

CMakeFiles/memman_test.dir/tests/test_callback.cpp.o: CMakeFiles/memman_test.dir/flags.make
CMakeFiles/memman_test.dir/tests/test_callback.cpp.o: ../tests/test_callback.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alekseyp/MemoryManager/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/memman_test.dir/tests/test_callback.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/memman_test.dir/tests/test_callback.cpp.o -c /home/alekseyp/MemoryManager/tests/test_callback.cpp

CMakeFiles/memman_test.dir/tests/test_callback.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/memman_test.dir/tests/test_callback.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alekseyp/MemoryManager/tests/test_callback.cpp > CMakeFiles/memman_test.dir/tests/test_callback.cpp.i

CMakeFiles/memman_test.dir/tests/test_callback.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/memman_test.dir/tests/test_callback.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alekseyp/MemoryManager/tests/test_callback.cpp -o CMakeFiles/memman_test.dir/tests/test_callback.cpp.s

CMakeFiles/memman_test.dir/tests/test_compare.cpp.o: CMakeFiles/memman_test.dir/flags.make
CMakeFiles/memman_test.dir/tests/test_compare.cpp.o: ../tests/test_compare.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alekseyp/MemoryManager/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/memman_test.dir/tests/test_compare.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/memman_test.dir/tests/test_compare.cpp.o -c /home/alekseyp/MemoryManager/tests/test_compare.cpp

CMakeFiles/memman_test.dir/tests/test_compare.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/memman_test.dir/tests/test_compare.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alekseyp/MemoryManager/tests/test_compare.cpp > CMakeFiles/memman_test.dir/tests/test_compare.cpp.i

CMakeFiles/memman_test.dir/tests/test_compare.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/memman_test.dir/tests/test_compare.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alekseyp/MemoryManager/tests/test_compare.cpp -o CMakeFiles/memman_test.dir/tests/test_compare.cpp.s

CMakeFiles/memman_test.dir/tests/test_deref.cpp.o: CMakeFiles/memman_test.dir/flags.make
CMakeFiles/memman_test.dir/tests/test_deref.cpp.o: ../tests/test_deref.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alekseyp/MemoryManager/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/memman_test.dir/tests/test_deref.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/memman_test.dir/tests/test_deref.cpp.o -c /home/alekseyp/MemoryManager/tests/test_deref.cpp

CMakeFiles/memman_test.dir/tests/test_deref.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/memman_test.dir/tests/test_deref.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alekseyp/MemoryManager/tests/test_deref.cpp > CMakeFiles/memman_test.dir/tests/test_deref.cpp.i

CMakeFiles/memman_test.dir/tests/test_deref.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/memman_test.dir/tests/test_deref.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alekseyp/MemoryManager/tests/test_deref.cpp -o CMakeFiles/memman_test.dir/tests/test_deref.cpp.s

CMakeFiles/memman_test.dir/tests/test_main.cpp.o: CMakeFiles/memman_test.dir/flags.make
CMakeFiles/memman_test.dir/tests/test_main.cpp.o: ../tests/test_main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alekseyp/MemoryManager/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/memman_test.dir/tests/test_main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/memman_test.dir/tests/test_main.cpp.o -c /home/alekseyp/MemoryManager/tests/test_main.cpp

CMakeFiles/memman_test.dir/tests/test_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/memman_test.dir/tests/test_main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alekseyp/MemoryManager/tests/test_main.cpp > CMakeFiles/memman_test.dir/tests/test_main.cpp.i

CMakeFiles/memman_test.dir/tests/test_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/memman_test.dir/tests/test_main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alekseyp/MemoryManager/tests/test_main.cpp -o CMakeFiles/memman_test.dir/tests/test_main.cpp.s

CMakeFiles/memman_test.dir/tests/test_typeidname.cpp.o: CMakeFiles/memman_test.dir/flags.make
CMakeFiles/memman_test.dir/tests/test_typeidname.cpp.o: ../tests/test_typeidname.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alekseyp/MemoryManager/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/memman_test.dir/tests/test_typeidname.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/memman_test.dir/tests/test_typeidname.cpp.o -c /home/alekseyp/MemoryManager/tests/test_typeidname.cpp

CMakeFiles/memman_test.dir/tests/test_typeidname.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/memman_test.dir/tests/test_typeidname.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alekseyp/MemoryManager/tests/test_typeidname.cpp > CMakeFiles/memman_test.dir/tests/test_typeidname.cpp.i

CMakeFiles/memman_test.dir/tests/test_typeidname.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/memman_test.dir/tests/test_typeidname.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alekseyp/MemoryManager/tests/test_typeidname.cpp -o CMakeFiles/memman_test.dir/tests/test_typeidname.cpp.s

CMakeFiles/memman_test.dir/tests/test_verify_empty.cpp.o: CMakeFiles/memman_test.dir/flags.make
CMakeFiles/memman_test.dir/tests/test_verify_empty.cpp.o: ../tests/test_verify_empty.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alekseyp/MemoryManager/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/memman_test.dir/tests/test_verify_empty.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/memman_test.dir/tests/test_verify_empty.cpp.o -c /home/alekseyp/MemoryManager/tests/test_verify_empty.cpp

CMakeFiles/memman_test.dir/tests/test_verify_empty.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/memman_test.dir/tests/test_verify_empty.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alekseyp/MemoryManager/tests/test_verify_empty.cpp > CMakeFiles/memman_test.dir/tests/test_verify_empty.cpp.i

CMakeFiles/memman_test.dir/tests/test_verify_empty.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/memman_test.dir/tests/test_verify_empty.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alekseyp/MemoryManager/tests/test_verify_empty.cpp -o CMakeFiles/memman_test.dir/tests/test_verify_empty.cpp.s

CMakeFiles/memman_test.dir/tests/test_verify_ptr.cpp.o: CMakeFiles/memman_test.dir/flags.make
CMakeFiles/memman_test.dir/tests/test_verify_ptr.cpp.o: ../tests/test_verify_ptr.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alekseyp/MemoryManager/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/memman_test.dir/tests/test_verify_ptr.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/memman_test.dir/tests/test_verify_ptr.cpp.o -c /home/alekseyp/MemoryManager/tests/test_verify_ptr.cpp

CMakeFiles/memman_test.dir/tests/test_verify_ptr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/memman_test.dir/tests/test_verify_ptr.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alekseyp/MemoryManager/tests/test_verify_ptr.cpp > CMakeFiles/memman_test.dir/tests/test_verify_ptr.cpp.i

CMakeFiles/memman_test.dir/tests/test_verify_ptr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/memman_test.dir/tests/test_verify_ptr.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alekseyp/MemoryManager/tests/test_verify_ptr.cpp -o CMakeFiles/memman_test.dir/tests/test_verify_ptr.cpp.s

# Object files for target memman_test
memman_test_OBJECTS = \
"CMakeFiles/memman_test.dir/tests/test_alloc_dealloc.cpp.o" \
"CMakeFiles/memman_test.dir/tests/test_callback.cpp.o" \
"CMakeFiles/memman_test.dir/tests/test_compare.cpp.o" \
"CMakeFiles/memman_test.dir/tests/test_deref.cpp.o" \
"CMakeFiles/memman_test.dir/tests/test_main.cpp.o" \
"CMakeFiles/memman_test.dir/tests/test_typeidname.cpp.o" \
"CMakeFiles/memman_test.dir/tests/test_verify_empty.cpp.o" \
"CMakeFiles/memman_test.dir/tests/test_verify_ptr.cpp.o"

# External object files for target memman_test
memman_test_EXTERNAL_OBJECTS =

memman_test: CMakeFiles/memman_test.dir/tests/test_alloc_dealloc.cpp.o
memman_test: CMakeFiles/memman_test.dir/tests/test_callback.cpp.o
memman_test: CMakeFiles/memman_test.dir/tests/test_compare.cpp.o
memman_test: CMakeFiles/memman_test.dir/tests/test_deref.cpp.o
memman_test: CMakeFiles/memman_test.dir/tests/test_main.cpp.o
memman_test: CMakeFiles/memman_test.dir/tests/test_typeidname.cpp.o
memman_test: CMakeFiles/memman_test.dir/tests/test_verify_empty.cpp.o
memman_test: CMakeFiles/memman_test.dir/tests/test_verify_ptr.cpp.o
memman_test: CMakeFiles/memman_test.dir/build.make
memman_test: lib/libgtest_main.so.1.10.0
memman_test: libmemman.so
memman_test: lib/libgtest.so.1.10.0
memman_test: CMakeFiles/memman_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alekseyp/MemoryManager/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable memman_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/memman_test.dir/link.txt --verbose=$(VERBOSE)
	/usr/bin/cmake -D TEST_TARGET=memman_test -D TEST_EXECUTABLE=/home/alekseyp/MemoryManager/build/memman_test -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/home/alekseyp/MemoryManager/build -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=memman_test_TESTS -D CTEST_FILE=/home/alekseyp/MemoryManager/build/memman_test[1]_tests.cmake -D TEST_DISCOVERY_TIMEOUT=5 -P /home/alekseyp/MemoryManager/cmake/GoogleTestAddTests.cmake

# Rule to build all files generated by this target.
CMakeFiles/memman_test.dir/build: memman_test

.PHONY : CMakeFiles/memman_test.dir/build

CMakeFiles/memman_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/memman_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/memman_test.dir/clean

CMakeFiles/memman_test.dir/depend:
	cd /home/alekseyp/MemoryManager/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alekseyp/MemoryManager /home/alekseyp/MemoryManager /home/alekseyp/MemoryManager/build /home/alekseyp/MemoryManager/build /home/alekseyp/MemoryManager/build/CMakeFiles/memman_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/memman_test.dir/depend

