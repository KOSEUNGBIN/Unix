cmake_minimum_required(VERSION 3.8)
project(Unix)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES   Assignment/week7/basicshell.c)
add_executable(Unix ${SOURCE_FILES})