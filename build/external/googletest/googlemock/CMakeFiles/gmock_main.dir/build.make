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
include external/googletest/googlemock/CMakeFiles/gmock_main.dir/depend.make

# Include the progress variables for this target.
include external/googletest/googlemock/CMakeFiles/gmock_main.dir/progress.make

# Include the compile flags for this target's objects.
include external/googletest/googlemock/CMakeFiles/gmock_main.dir/flags.make

external/googletest/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o: external/googletest/googlemock/CMakeFiles/gmock_main.dir/flags.make
external/googletest/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o: ../external/googletest/googlemock/src/gmock_main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alekseyp/MemoryManager/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object external/googletest/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o"
	cd /home/alekseyp/MemoryManager/build/external/googletest/googlemock && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gmock_main.dir/src/gmock_main.cc.o -c /home/alekseyp/MemoryManager/external/googletest/googlemock/src/gmock_main.cc

external/googletest/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock_main.dir/src/gmock_main.cc.i"
	cd /home/alekseyp/MemoryManager/build/external/googletest/googlemock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alekseyp/MemoryManager/external/googletest/googlemock/src/gmock_main.cc > CMakeFiles/gmock_main.dir/src/gmock_main.cc.i

external/googletest/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock_main.dir/src/gmock_main.cc.s"
	cd /home/alekseyp/MemoryManager/build/external/googletest/googlemock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alekseyp/MemoryManager/external/googletest/googlemock/src/gmock_main.cc -o CMakeFiles/gmock_main.dir/src/gmock_main.cc.s

# Object files for target gmock_main
gmock_main_OBJECTS = \
"CMakeFiles/gmock_main.dir/src/gmock_main.cc.o"

# External object files for target gmock_main
gmock_main_EXTERNAL_OBJECTS =

lib/libgmock_main.so.1.10.0: external/googletest/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o
lib/libgmock_main.so.1.10.0: external/googletest/googlemock/CMakeFiles/gmock_main.dir/build.make
lib/libgmock_main.so.1.10.0: lib/libgmock.so.1.10.0
lib/libgmock_main.so.1.10.0: lib/libgtest.so.1.10.0
lib/libgmock_main.so.1.10.0: external/googletest/googlemock/CMakeFiles/gmock_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alekseyp/MemoryManager/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library ../../../lib/libgmock_main.so"
	cd /home/alekseyp/MemoryManager/build/external/googletest/googlemock && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gmock_main.dir/link.txt --verbose=$(VERBOSE)
	cd /home/alekseyp/MemoryManager/build/external/googletest/googlemock && $(CMAKE_COMMAND) -E cmake_symlink_library ../../../lib/libgmock_main.so.1.10.0 ../../../lib/libgmock_main.so.1.10.0 ../../../lib/libgmock_main.so

lib/libgmock_main.so: lib/libgmock_main.so.1.10.0
	@$(CMAKE_COMMAND) -E touch_nocreate lib/libgmock_main.so

# Rule to build all files generated by this target.
external/googletest/googlemock/CMakeFiles/gmock_main.dir/build: lib/libgmock_main.so

.PHONY : external/googletest/googlemock/CMakeFiles/gmock_main.dir/build

external/googletest/googlemock/CMakeFiles/gmock_main.dir/clean:
	cd /home/alekseyp/MemoryManager/build/external/googletest/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock_main.dir/cmake_clean.cmake
.PHONY : external/googletest/googlemock/CMakeFiles/gmock_main.dir/clean

external/googletest/googlemock/CMakeFiles/gmock_main.dir/depend:
	cd /home/alekseyp/MemoryManager/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alekseyp/MemoryManager /home/alekseyp/MemoryManager/external/googletest/googlemock /home/alekseyp/MemoryManager/build /home/alekseyp/MemoryManager/build/external/googletest/googlemock /home/alekseyp/MemoryManager/build/external/googletest/googlemock/CMakeFiles/gmock_main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : external/googletest/googlemock/CMakeFiles/gmock_main.dir/depend
