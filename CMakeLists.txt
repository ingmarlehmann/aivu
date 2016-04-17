cmake_minimum_required(VERSION 2.8.3)

project(frank-all)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

add_subdirectory(frank-parser)
add_subdirectory(frank-astprinter)
