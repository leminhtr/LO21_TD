cmake_minimum_required(VERSION 3.6)
project(TD1)

set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_BINARY_DIR})
include_directories(D:/School/UTC/A16-P17/P17/LO21/TD/TD1/ex.8)
set(SOURCE_FILES main.cpp fonction.cpp fonction.cpp fonction.h)
add_executable(TD1 ${SOURCE_FILES})