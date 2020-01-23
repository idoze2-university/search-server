cmake_minimum_required(VERSION 3.15)
project(untitled1)

set(CMAKE_CXX_STANDARD 14)
include_directories(${CMAKE_SOURCE_DIR})
file(GLOB_RECURSE SRCS *.cpp)
file(GLOB_RECURSE HEADERS *.h)

add_executable(${SRCS} ${HEADERS} main.cpp)