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
include CMakeFiles/memman.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/memman.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/memman.dir/flags.make

CMakeFiles/memman.dir/memman/memman.c.o: CMakeFiles/memman.dir/flags.make
CMakeFiles/memman.dir/memman/memman.c.o: ../memman/memman.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alekseyp/MemoryManager/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/memman.dir/memman/memman.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/memman.dir/memman/memman.c.o   -c /home/alekseyp/MemoryManager/memman/memman.c

CMakeFiles/memman.dir/memman/memman.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/memman.dir/memman/memman.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/alekseyp/MemoryManager/memman/memman.c > CMakeFiles/memman.dir/memman/memman.c.i

CMakeFiles/memman.dir/memman/memman.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/memman.dir/memman/memman.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/alekseyp/MemoryManager/memman/memman.c -o CMakeFiles/memman.dir/memman/memman.c.s

# Object files for target memman
memman_OBJECTS = \
"CMakeFiles/memman.dir/memman/memman.c.o"

# External object files for target memman
memman_EXTERNAL_OBJECTS =

libmemman.so: CMakeFiles/memman.dir/memman/memman.c.o
libmemman.so: CMakeFiles/memman.dir/build.make
libmemman.so: CMakeFiles/memman.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alekseyp/MemoryManager/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library libmemman.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/memman.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/memman.dir/build: libmemman.so

.PHONY : CMakeFiles/memman.dir/build

CMakeFiles/memman.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/memman.dir/cmake_clean.cmake
.PHONY : CMakeFiles/memman.dir/clean

CMakeFiles/memman.dir/depend:
	cd /home/alekseyp/MemoryManager/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alekseyp/MemoryManager /home/alekseyp/MemoryManager /home/alekseyp/MemoryManager/build /home/alekseyp/MemoryManager/build /home/alekseyp/MemoryManager/build/CMakeFiles/memman.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/memman.dir/depend

