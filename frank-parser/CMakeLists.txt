cmake_minimum_required(VERSION 2.8.3)

project(frank-parser)

find_package(BISON)
find_package(FLEX)

BISON_TARGET(FidlParser src/parser/fidl_parser.y ${CMAKE_CURRENT_BINARY_DIR}/gen_bison_parser.cpp)
FLEX_TARGET(FidlLexer src/parser/fidl_lexer.l  ${CMAKE_CURRENT_BINARY_DIR}/gen_flex_lexer.cpp)
ADD_FLEX_BISON_DEPENDENCY(FidlLexer FidlParser)

set(SOURCES 
        src/ast/ast_node.cpp
        src/ast/ast_node_list.cpp
        src/ast/broadcast_method_decl.cpp
        src/ast/double_constant.cpp
        src/ast/enum_decl.cpp
        src/ast/enumerator.cpp
        src/ast/float_constant.cpp
        src/ast/franca_comment.cpp
        src/ast/identifier.cpp
        src/ast/int_constant.cpp
        src/ast/interface.cpp
        src/ast/method_argument.cpp
        src/ast/method_body.cpp
        src/ast/method_decl.cpp
        src/ast/package_name.cpp
        src/ast/root.cpp
        src/ast/string_constant.cpp
        src/ast/type.cpp
        src/ast/variable_decl.cpp
        src/ast/version.cpp
        src/parser.cpp
        src/parser/fidl_lexer.l
        src/parser/fidl_parser.y
        src/util/util.cpp
        include/ast/ast_node.h
        include/ast/ast_node_list.h
        include/ast/ast_node_visitor.h
        include/ast/broadcast_method_decl.h
        include/ast/double_constant.h
        include/ast/enum_decl.h
        include/ast/enumerator.h
        include/ast/float_constant.h
        include/ast/franca_comment.h
        include/ast/identifier.h
        include/ast/int_constant.h
        include/ast/interface.h
        include/ast/method_argument.h
        include/ast/method_body.h
        include/ast/method_decl.h
        include/ast/package_name.h
        include/ast/root.h
        include/ast/string_constant.h
        include/ast/type.h
        include/ast/variable_decl.h
        include/ast/version.h
        include/parser.h
        include/util/util.h
        )

add_library(${PROJECT_NAME}
        ${SOURCES}
        ${BISON_FidlParser_OUTPUTS}
        ${FLEX_FidlLexer_OUTPUTS}
        )

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)

target_include_directories(${PROJECT_NAME}
    PRIVATE 
        ${CMAKE_CURRENT_BINARY_DIR}
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/include
        )
