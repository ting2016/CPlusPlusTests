# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_SOURCE_DIR = /home/ting/Proj/spdtest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ting/Proj/spdtest/bin

# Utility rule file for spdlog.

# Include the progress variables for this target.
include CMakeFiles/spdlog.dir/progress.make

CMakeFiles/spdlog: CMakeFiles/spdlog-complete


CMakeFiles/spdlog-complete: spdlog-prefix/src/spdlog-stamp/spdlog-install
CMakeFiles/spdlog-complete: spdlog-prefix/src/spdlog-stamp/spdlog-mkdir
CMakeFiles/spdlog-complete: spdlog-prefix/src/spdlog-stamp/spdlog-download
CMakeFiles/spdlog-complete: spdlog-prefix/src/spdlog-stamp/spdlog-update
CMakeFiles/spdlog-complete: spdlog-prefix/src/spdlog-stamp/spdlog-patch
CMakeFiles/spdlog-complete: spdlog-prefix/src/spdlog-stamp/spdlog-configure
CMakeFiles/spdlog-complete: spdlog-prefix/src/spdlog-stamp/spdlog-build
CMakeFiles/spdlog-complete: spdlog-prefix/src/spdlog-stamp/spdlog-install
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ting/Proj/spdtest/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'spdlog'"
	/usr/bin/cmake -E make_directory /home/ting/Proj/spdtest/bin/CMakeFiles
	/usr/bin/cmake -E touch /home/ting/Proj/spdtest/bin/CMakeFiles/spdlog-complete
	/usr/bin/cmake -E touch /home/ting/Proj/spdtest/bin/spdlog-prefix/src/spdlog-stamp/spdlog-done

spdlog-prefix/src/spdlog-stamp/spdlog-install: spdlog-prefix/src/spdlog-stamp/spdlog-build
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ting/Proj/spdtest/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Performing install step for 'spdlog'"
	cd /home/ting/Proj/spdtest/bin/spdlog-prefix/src/spdlog-build && $(MAKE) install
	cd /home/ting/Proj/spdtest/bin/spdlog-prefix/src/spdlog-build && /usr/bin/cmake -E touch /home/ting/Proj/spdtest/bin/spdlog-prefix/src/spdlog-stamp/spdlog-install

spdlog-prefix/src/spdlog-stamp/spdlog-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ting/Proj/spdtest/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Creating directories for 'spdlog'"
	/usr/bin/cmake -E make_directory /home/ting/Proj/spdtest/bin/spdlog-prefix/src/spdlog
	/usr/bin/cmake -E make_directory /home/ting/Proj/spdtest/bin/spdlog-prefix/src/spdlog-build
	/usr/bin/cmake -E make_directory /home/ting/Proj/spdtest/vendor/spdlog
	/usr/bin/cmake -E make_directory /home/ting/Proj/spdtest/bin/spdlog-prefix/tmp
	/usr/bin/cmake -E make_directory /home/ting/Proj/spdtest/bin/spdlog-prefix/src/spdlog-stamp
	/usr/bin/cmake -E make_directory /home/ting/Proj/spdtest/bin/spdlog-prefix/src
	/usr/bin/cmake -E touch /home/ting/Proj/spdtest/bin/spdlog-prefix/src/spdlog-stamp/spdlog-mkdir

spdlog-prefix/src/spdlog-stamp/spdlog-download: spdlog-prefix/src/spdlog-stamp/spdlog-gitinfo.txt
spdlog-prefix/src/spdlog-stamp/spdlog-download: spdlog-prefix/src/spdlog-stamp/spdlog-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ting/Proj/spdtest/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Performing download step (git clone) for 'spdlog'"
	cd /home/ting/Proj/spdtest/bin/spdlog-prefix/src && /usr/bin/cmake -P /home/ting/Proj/spdtest/bin/spdlog-prefix/tmp/spdlog-gitclone.cmake
	cd /home/ting/Proj/spdtest/bin/spdlog-prefix/src && /usr/bin/cmake -E touch /home/ting/Proj/spdtest/bin/spdlog-prefix/src/spdlog-stamp/spdlog-download

spdlog-prefix/src/spdlog-stamp/spdlog-update: spdlog-prefix/src/spdlog-stamp/spdlog-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ting/Proj/spdtest/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Performing update step for 'spdlog'"
	cd /home/ting/Proj/spdtest/bin/spdlog-prefix/src/spdlog && /usr/bin/cmake -P /home/ting/Proj/spdtest/bin/spdlog-prefix/tmp/spdlog-gitupdate.cmake

spdlog-prefix/src/spdlog-stamp/spdlog-patch: spdlog-prefix/src/spdlog-stamp/spdlog-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ting/Proj/spdtest/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "No patch step for 'spdlog'"
	/usr/bin/cmake -E echo_append
	/usr/bin/cmake -E touch /home/ting/Proj/spdtest/bin/spdlog-prefix/src/spdlog-stamp/spdlog-patch

spdlog-prefix/src/spdlog-stamp/spdlog-configure: spdlog-prefix/tmp/spdlog-cfgcmd.txt
spdlog-prefix/src/spdlog-stamp/spdlog-configure: spdlog-prefix/src/spdlog-stamp/spdlog-update
spdlog-prefix/src/spdlog-stamp/spdlog-configure: spdlog-prefix/src/spdlog-stamp/spdlog-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ting/Proj/spdtest/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Performing configure step for 'spdlog'"
	cd /home/ting/Proj/spdtest/bin/spdlog-prefix/src/spdlog-build && /usr/bin/cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/home/ting/Proj/spdtest/vendor/spdlog -DSPDLOG_BUILD_TESTING=OFF "-GCodeBlocks - Unix Makefiles" /home/ting/Proj/spdtest/bin/spdlog-prefix/src/spdlog
	cd /home/ting/Proj/spdtest/bin/spdlog-prefix/src/spdlog-build && /usr/bin/cmake -E touch /home/ting/Proj/spdtest/bin/spdlog-prefix/src/spdlog-stamp/spdlog-configure

spdlog-prefix/src/spdlog-stamp/spdlog-build: spdlog-prefix/src/spdlog-stamp/spdlog-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ting/Proj/spdtest/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Performing build step for 'spdlog'"
	cd /home/ting/Proj/spdtest/bin/spdlog-prefix/src/spdlog-build && $(MAKE)
	cd /home/ting/Proj/spdtest/bin/spdlog-prefix/src/spdlog-build && /usr/bin/cmake -E touch /home/ting/Proj/spdtest/bin/spdlog-prefix/src/spdlog-stamp/spdlog-build

spdlog: CMakeFiles/spdlog
spdlog: CMakeFiles/spdlog-complete
spdlog: spdlog-prefix/src/spdlog-stamp/spdlog-install
spdlog: spdlog-prefix/src/spdlog-stamp/spdlog-mkdir
spdlog: spdlog-prefix/src/spdlog-stamp/spdlog-download
spdlog: spdlog-prefix/src/spdlog-stamp/spdlog-update
spdlog: spdlog-prefix/src/spdlog-stamp/spdlog-patch
spdlog: spdlog-prefix/src/spdlog-stamp/spdlog-configure
spdlog: spdlog-prefix/src/spdlog-stamp/spdlog-build
spdlog: CMakeFiles/spdlog.dir/build.make

.PHONY : spdlog

# Rule to build all files generated by this target.
CMakeFiles/spdlog.dir/build: spdlog

.PHONY : CMakeFiles/spdlog.dir/build

CMakeFiles/spdlog.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/spdlog.dir/cmake_clean.cmake
.PHONY : CMakeFiles/spdlog.dir/clean

CMakeFiles/spdlog.dir/depend:
	cd /home/ting/Proj/spdtest/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ting/Proj/spdtest /home/ting/Proj/spdtest /home/ting/Proj/spdtest/bin /home/ting/Proj/spdtest/bin /home/ting/Proj/spdtest/bin/CMakeFiles/spdlog.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/spdlog.dir/depend

