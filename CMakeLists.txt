cmake_minimum_required(VERSION 3.8)
project(Unix)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES   Assignment/week5/3-10.c)
add_executable(Unix ${SOURCE_FILES})