# Specify the minimum version for CMake

cmake_minimum_required(VERSION 2.8)

# Project's name

project(hello)

add_executable(hello ${PROJECT_SOURCE_DIR}/test.cpp)
