# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_SOURCE_DIR = /home/ting/Proj/CPlusPlusTests/cmake_test/step1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ting/Proj/CPlusPlusTests/cmake_test/step1/bin

# Include any dependencies generated for this target.
include CMakeFiles/step1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/step1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/step1.dir/flags.make

CMakeFiles/step1.dir/tutorial.cpp.o: CMakeFiles/step1.dir/flags.make
CMakeFiles/step1.dir/tutorial.cpp.o: ../tutorial.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ting/Proj/CPlusPlusTests/cmake_test/step1/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/step1.dir/tutorial.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/step1.dir/tutorial.cpp.o -c /home/ting/Proj/CPlusPlusTests/cmake_test/step1/tutorial.cpp

CMakeFiles/step1.dir/tutorial.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/step1.dir/tutorial.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ting/Proj/CPlusPlusTests/cmake_test/step1/tutorial.cpp > CMakeFiles/step1.dir/tutorial.cpp.i

CMakeFiles/step1.dir/tutorial.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/step1.dir/tutorial.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ting/Proj/CPlusPlusTests/cmake_test/step1/tutorial.cpp -o CMakeFiles/step1.dir/tutorial.cpp.s

CMakeFiles/step1.dir/tutorial.cpp.o.requires:

.PHONY : CMakeFiles/step1.dir/tutorial.cpp.o.requires

CMakeFiles/step1.dir/tutorial.cpp.o.provides: CMakeFiles/step1.dir/tutorial.cpp.o.requires
	$(MAKE) -f CMakeFiles/step1.dir/build.make CMakeFiles/step1.dir/tutorial.cpp.o.provides.build
.PHONY : CMakeFiles/step1.dir/tutorial.cpp.o.provides

CMakeFiles/step1.dir/tutorial.cpp.o.provides.build: CMakeFiles/step1.dir/tutorial.cpp.o


# Object files for target step1
step1_OBJECTS = \
"CMakeFiles/step1.dir/tutorial.cpp.o"

# External object files for target step1
step1_EXTERNAL_OBJECTS =

step1: CMakeFiles/step1.dir/tutorial.cpp.o
step1: CMakeFiles/step1.dir/build.make
step1: CMakeFiles/step1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ting/Proj/CPlusPlusTests/cmake_test/step1/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable step1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/step1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/step1.dir/build: step1

.PHONY : CMakeFiles/step1.dir/build

CMakeFiles/step1.dir/requires: CMakeFiles/step1.dir/tutorial.cpp.o.requires

.PHONY : CMakeFiles/step1.dir/requires

CMakeFiles/step1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/step1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/step1.dir/clean

CMakeFiles/step1.dir/depend:
	cd /home/ting/Proj/CPlusPlusTests/cmake_test/step1/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ting/Proj/CPlusPlusTests/cmake_test/step1 /home/ting/Proj/CPlusPlusTests/cmake_test/step1 /home/ting/Proj/CPlusPlusTests/cmake_test/step1/bin /home/ting/Proj/CPlusPlusTests/cmake_test/step1/bin /home/ting/Proj/CPlusPlusTests/cmake_test/step1/bin/CMakeFiles/step1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/step1.dir/depend

