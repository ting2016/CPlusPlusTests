cmake_minimum_required (VERSION 2.6)
project (step2)

# The version number.
set (step2_VERSION_MAJOR 1)
set (step2_VERSION_MINOR 0)

# should we use our own math functions
option(USE_MYMATH "Use tutorial provided math implementation" ON)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/step2Config.h.in"
  "${PROJECT_BINARY_DIR}/step2Config.h"
  )

# add the binary tree to the search path for include files
# so that we will find step2Config.h
include_directories ("${PROJECT_BINARY_DIR}")

# add the MathFunctions library?
if (USE_MYMATH)
  include_directories ("${PROJECT_SOURCE_DIR}/MathFunctions")
  add_subdirectory (MathFunctions)
  set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif ()

# add the executable
add_executable (step2 tutorial.cpp)
target_link_libraries (step2  ${EXTRA_LIBS})

