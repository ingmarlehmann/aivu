cmake_minimum_required(VERSION 2.8.3)

project(frank-astprinter)

set(SOURCES
    src/ast_print_visitor.h
    src/ast_print_visitor.cpp
    src/main.cpp
    )

add_executable(${PROJECT_NAME}
    ${SOURCES}
    )

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)

target_link_libraries(${PROJECT_NAME} frank-parser)
target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${FRANK_PARSER_INCLUDE_DIRS}
    )
