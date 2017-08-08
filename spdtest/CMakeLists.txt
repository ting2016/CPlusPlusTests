cmake_minimum_required(VERSION 3.1)
project(spdtest)

set(CMAKE_CXX_STANDARD 11)
set(CXX_STANDARD_REQUIRED ON)

add_executable(spdtest test.cpp)

include(cmake/spdlog.cmake)
add_dependencies(spdtest spdlog)

find_package(Qt5Core)

include_directories(${spdlog_INCLUDE_DIRS})
target_link_libraries(spdtest ${spdlog_LIBS})
target_link_libraries(spdtest Qt5::Core)
target_compile_definitions(spdtest PRIVATE SPDLOG_TRACE_ON=1) # make sure TRACE is enabled
