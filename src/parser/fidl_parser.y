%{
    #define YYDEBUG 1

    #include <vector>
    #include <cstdio>
    #include <string>
    #include <memory>
    #include <functional>

    #include "ast/ast_node.h"
    #include "ast/ast_node_list.h"
    #include "ast/double_constant.h"
    #include "ast/enum_decl.h"
    #include "ast/enumerator.h"
    #include "ast/float_constant.h"
    #include "ast/identifier.h"
    #include "ast/int_constant.h"
    #include "ast/root.h"
    #include "ast/string_constant.h"
    #include "ast/type.h"
    #include "ast/variable_decl.h"

    using namespace fparser;
    std::function<void(const char*)> bison_error_callback;

    extern int yylex();
    extern int yylineno;
    void yyerror(const char *s) 
    { 
        if(bison_error_callback)
        {
            bison_error_callback(s);
        }
    }

    ast::Root* root_node = new ast::Root();
    
    void add_child(ast::ASTNode* parent, ast::ASTNode* child)
    {
        parent->children().push_back(child);
    }
%}

%define parse.error verbose
%define parse.trace
%define parse.lac full
%locations

%union{
    fparser::ast::ASTNode* t_ast_node;
    std::string*  t_string;
    int           t_token;
    long long     t_longlong;
    float         t_float;
    double        t_double;
}

%token <t_string>   TIDENTIFIER     "Identifier"

%token <t_string>   TFRANCACOMMENT  "Franca comment"
%token <t_string>   TCCOMMENT       "C-style comment"

%token <t_ast_node> TENUMERATION    "Enumeration"
%token <t_token>    TINTEGER        "Integer"
%token <t_token>    TUINT64         "UInt64"
%token <t_token>    TINT64          "Int64"
%token <t_token>    TTRUE           "TRUE"
%token <t_token>    TFALSE          "FALSE"

%token <t_token>    TUINT32         "UInt32"
%token <t_token>    TINT32          "Int32"
%token <t_token>    TUINT16         "UInt16"
%token <t_token>    TINT16          "Int16"
%token <t_token>    TUINT8          "UInt8"
%token <t_token>    TINT8           "Int8"

%token <t_token>    TBOOLEAN        "Boolean"
%token <t_token>    TFLOAT          "Float"
%token <t_token>    TDOUBLE         "Double"
%token <t_token>    TSTRING         "String"
%token <t_token>    TBYTEBUFFER     "ByteBuffer"

%token <t_longlong> TINT_CONST_DEC  "_integer_constant_decimal_"
%token <t_longlong> TINT_CONST_OCT  "_integer_constant_octal_"
%token <t_longlong> TINT_CONST_HEX  "_integer_constant_hexadecimal_"
%token <t_token>    TINT_CONST_BIN  "_integer_constant_binary_"

%token <t_float>    TFLOAT_CONST        "_float_constant_"
%token <t_float>    TFLOAT_CONST_HEX    "_float_constant_hex_"
%token <t_double>   TDOUBLE_CONST       "_double_constant_"
%token <t_double>   TDOUBLE_CONST_HEX   "_double_constant_hex_"

%token <t_token>    TPLUS       "_+_"
%token <t_token>    TMINUS
%token <t_token>    TTIMES
%token <t_token>    TDIVIDE
%token <t_token>    TMOD
%token <t_token>    TOR
%token <t_token>    TAND
%token <t_token>    TNOT
%token <t_token>    TXOR
%token <t_token>    TLSHIFT
%token <t_token>    TRSHIFT
%token <t_token>    TLOR
%token <t_token>    TLAND
%token <t_token>    TLNOT
%token <t_token>    TLT
%token <t_token>    TGT
%token <t_token>    TLE
%token <t_token>    TGE
%token <t_token>    TEQ
%token <t_token>    TNE

%token <t_token>    TLPAREN
%token <t_token>    TRPAREN
%token <t_token>    TLBRACKET
%token <t_token>    TRBRACKET
%token <t_token>    TLBRACE
%token <t_token>    TRBRACE
%token <t_token>    TCOMMA
%token <t_token>    TPERIOD
%token <t_token>    TSEMI
%token <t_token>    TCOLON

%token <t_token>    TEQUALS

%type <t_ast_node> document_root
%type <t_ast_node> root_element
%type <t_ast_node> root_element_list
%type <t_ast_node> variable_decl
/*%type <t_ast_node> variable_decl_list   "Variable declarator list"*/
%type <t_ast_node> enum_decl
%type <t_ast_node> enumerator_list
%type <t_ast_node> enumerator
%type <t_ast_node> constant
%type <t_ast_node> int_constant
%type <t_ast_node> float_constant
%type <t_ast_node> double_constant
%type <t_ast_node> type
%type <t_ast_node> identifier

%start document_root

%%

document_root : root_element_list { add_child(root_node, $1); }
              ;

root_element_list : root_element { $$ = new ast::ASTNodeList(); add_child($$, $1); }
                  | root_element_list root_element { add_child($1, $2); $$ = $1; }
                  ;

root_element : variable_decl { $$ = $1; }
             | enum_decl { $$ = $1; }
             ;

/*variable_decl_list : variable_decl { $$ = new ast::ASTNodeList(); add_child($$, $1); }*/
                   /*| variable_decl_list variable_decl { add_child($1, $2); $$ = $1; }*/
                   /*;*/

variable_decl : type identifier { $$ = new ast::VariableDecl(); add_child($$, $1); add_child($$, $2); }
              | type identifier TEQUALS constant { $$ = new ast::VariableDecl(); add_child($$, $2); add_child($$, $4); }
              ;

enum_decl : TENUMERATION identifier TLBRACE enumerator_list TRBRACE { $$ = new ast::EnumDecl(); add_child($$, $2); add_child($$, $4); }

enumerator_list : enumerator { $$ = new ast::ASTNodeList(); add_child($$,$1); }
                | enumerator_list enumerator { add_child($1,$2); $$ = $1; }
                ;

enumerator : identifier { $$ = new ast::Enumerator(); add_child($$, $1); }
           | identifier TEQUALS int_constant { $$ = new ast::Enumerator(); add_child($$, $1); add_child($$, $3); }
           ;

/*expression : unary_expression {  }*/
           /*| binary_expression {  }*/
           /*| constant {  }*/
           /*;*/

/*unary_expression : {} ;*/
/*binary_expression : {} ;*/

/*constant : */

    /*unary_expression (++x, x++, !x, ...)*/
    /*binary_expression (x = y+z, d = 5*10, ...)*/
    /*tenary_expression (a = b ? c : d) */

identifier : TIDENTIFIER { $$ = new ast::Identifier(*$1); delete $1; }

constant : int_constant { $$ = $1; }
         | float_constant { $$ = $1; }
         | double_constant { $$ = $1; }

int_constant : TINT_CONST_DEC { $$ = new ast::IntConstant($1); }
         | TINT_CONST_OCT { $$ = new ast::IntConstant($1); }
         | TINT_CONST_HEX { $$ = new ast::IntConstant($1); }
         | TINT_CONST_BIN { $$ = new ast::IntConstant($1); }
         ;

float_constant : TFLOAT_CONST { $$ = new ast::FloatConstant($1); }
         | TFLOAT_CONST_HEX { $$ = new ast::FloatConstant($1); }
         ;

double_constant : TDOUBLE_CONST { $$ = new ast::DoubleConstant($1); }
         | TDOUBLE_CONST_HEX { $$ = new ast::DoubleConstant($1); }
         ;

type : TINTEGER    { $$ = new ast::Type(0,  std::string("Integer")); }
     | TUINT64     { $$ = new ast::Type(0,  std::string("UInt64")); }
     | TINT64      { $$ = new ast::Type(0,  std::string("Int64")); }
     | TTRUE       { $$ = new ast::Type(0,  std::string("true")); }
     | TFALSE      { $$ = new ast::Type(0,  std::string("false")); }
     | TUINT32     { $$ = new ast::Type(0,  std::string("UInt32")); }
     | TINT32      { $$ = new ast::Type(0,  std::string("Int32")); }
     | TUINT16     { $$ = new ast::Type(0,  std::string("UInt16")); }
     | TINT16      { $$ = new ast::Type(0,  std::string("Int16")); }
     | TUINT8      { $$ = new ast::Type(0,  std::string("UInt8")); }
     | TINT8       { $$ = new ast::Type(0,  std::string("Int8")); }
     | TBOOLEAN    { $$ = new ast::Type(0,  std::string("Boolean")); }
     | TFLOAT      { $$ = new ast::Type(0,  std::string("Float")); }
     | TDOUBLE     { $$ = new ast::Type(0,  std::string("Double")); }
     | TSTRING     { $$ = new ast::Type(0,  std::string("String")); }
     | TBYTEBUFFER { $$ = new ast::Type(0,  std::string("ByteBuffer")); }
;

%%

