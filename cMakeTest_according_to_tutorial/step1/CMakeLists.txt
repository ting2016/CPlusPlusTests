cmake_minimum_required (VERSION 2.6)
project (step1)

# The version number.
set (step1_VERSION_MAJOR 1)
set (step1_VERSION_MINOR 0)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/step1Config.h.in"
  "${PROJECT_BINARY_DIR}/step1Config.h"
  )

# add the binary tree to the search path for include files
# so that we will find step1Config.h
include_directories("${PROJECT_BINARY_DIR}")

# add the executable
add_executable(step1 tutorial.cpp)


