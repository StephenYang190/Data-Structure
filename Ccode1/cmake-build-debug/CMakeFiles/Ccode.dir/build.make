# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /cygdrive/c/Users/HP/.CLion2019.2/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/HP/.CLion2019.2/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/d/code_personal/data_structure/Ccode1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/d/code_personal/data_structure/Ccode1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Ccode.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Ccode.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Ccode.dir/flags.make

CMakeFiles/Ccode.dir/task5.c.o: CMakeFiles/Ccode.dir/flags.make
CMakeFiles/Ccode.dir/task5.c.o: task5.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/d/code_personal/data_structure/Ccode1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Ccode.dir/task5.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Ccode.dir/task5.c.o   -c /cygdrive/d/code_personal/data_structure/Ccode1/cmake-build-debug/task5.c

CMakeFiles/Ccode.dir/task5.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Ccode.dir/task5.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/d/code_personal/data_structure/Ccode1/cmake-build-debug/task5.c > CMakeFiles/Ccode.dir/task5.c.i

CMakeFiles/Ccode.dir/task5.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Ccode.dir/task5.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/d/code_personal/data_structure/Ccode1/cmake-build-debug/task5.c -o CMakeFiles/Ccode.dir/task5.c.s

# Object files for target Ccode
Ccode_OBJECTS = \
"CMakeFiles/Ccode.dir/task5.c.o"

# External object files for target Ccode
Ccode_EXTERNAL_OBJECTS =

Ccode.exe: CMakeFiles/Ccode.dir/task5.c.o
Ccode.exe: CMakeFiles/Ccode.dir/build.make
Ccode.exe: CMakeFiles/Ccode.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/d/code_personal/data_structure/Ccode1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Ccode.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Ccode.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Ccode.dir/build: Ccode.exe

.PHONY : CMakeFiles/Ccode.dir/build

CMakeFiles/Ccode.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Ccode.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Ccode.dir/clean

CMakeFiles/Ccode.dir/depend:
	cd /cygdrive/d/code_personal/data_structure/Ccode1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/d/code_personal/data_structure/Ccode1 /cygdrive/d/code_personal/data_structure/Ccode1 /cygdrive/d/code_personal/data_structure/Ccode1/cmake-build-debug /cygdrive/d/code_personal/data_structure/Ccode1/cmake-build-debug /cygdrive/d/code_personal/data_structure/Ccode1/cmake-build-debug/CMakeFiles/Ccode.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Ccode.dir/depend

