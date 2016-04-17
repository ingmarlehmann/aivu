cmake_minimum_required(VERSION 2.8.3)

project(frank-all)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

add_subdirectory(frank-parser)
add_subdirectory(frank-astprinter)

#file(COPY ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json DESTINATION ${PROJECT_SOURCE_DIR})
