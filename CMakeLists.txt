cmake_minimum_required(VERSION 2.8)

project(fidl_parser)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

find_package(BISON)
find_package(FLEX)

BISON_TARGET(FidlParser src/parser/fidl_parser.y ${CMAKE_CURRENT_BINARY_DIR}/gen_bison_parser.cpp)
FLEX_TARGET(FidlLexer src/parser/fidl_lexer.l  ${CMAKE_CURRENT_BINARY_DIR}/gen_flex_lexer.cpp)
ADD_FLEX_BISON_DEPENDENCY(FidlLexer FidlParser)

set(SOURCES 
        src/ast/ast_node.cpp
        src/ast/ast_node_list.cpp
        src/ast/double_constant.cpp
        src/ast/enum_decl.cpp
        src/ast/enumerator.cpp
        src/ast/float_constant.cpp
        src/ast/identifier.cpp
        src/ast/int_constant.cpp
        src/ast/root.cpp
        src/ast/string_constant.cpp
        src/ast/type.cpp
        src/ast/variable_decl.cpp
        src/parser/fidl_lexer.l
        src/parser/fidl_parser.y
        src/util/util.cpp
        src/main.cpp
        src/parser.cpp
        include/ast/ast_node.h
        include/ast/ast_node_list.h
        include/ast/double_constant.h
        include/ast/enum_decl.h
        include/ast/enumerator.h
        include/ast/float_constant.h
        include/ast/int_constant.h
        include/ast/identifier.h
        include/ast/root.h
        include/ast/string_constant.h
        include/ast/type.h
        include/ast/variable_decl.h
        include/util/util.h
        include/parser.h
        )

add_executable(fidl_parser 
        ${SOURCES}
        ${BISON_FidlParser_OUTPUTS}
        ${FLEX_FidlLexer_OUTPUTS}
        )

set_property(TARGET fidl_parser PROPERTY CXX_STANDARD 11)

target_include_directories(fidl_parser 
    PRIVATE 
        ${CMAKE_CURRENT_BINARY_DIR}
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/include
        )

add_custom_command(TARGET fidl_parser POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy
                       ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json ${PROJECT_SOURCE_DIR}
        )
