cmake_minimum_required(VERSION 3.8)
project(Unix)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES  week5/fileaddmode.c)
add_executable(Unix ${SOURCE_FILES})