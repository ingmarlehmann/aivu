%{
    #define YYDEBUG 1

    #include <vector>
    #include <cstdio>
    #include <string>
    #include <memory>
    #include <functional>

    #include "ast/ast_node.h"
    #include "ast/ast_node_list.h"
    #include "ast/broadcast_method_decl.h"
    #include "ast/double_constant.h"
    #include "ast/enum_decl.h"
    #include "ast/enumerator.h"
    #include "ast/float_constant.h"
    #include "ast/franca_comment.h"
    #include "ast/identifier.h"
    #include "ast/int_constant.h"
    #include "ast/interface.h"
    #include "ast/method_argument.h"
    #include "ast/method_body.h"
    #include "ast/method_decl.h"
    #include "ast/package_name.h"
    #include "ast/root.h"
    #include "ast/string_constant.h"
    #include "ast/type.h"
    #include "ast/variable_decl.h"
    #include "ast/version.h"

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
    std::string*           t_string;
    int                    t_token;
    long long              t_longlong;
    float                  t_float;
    double                 t_double;
}

%token <t_string>   TIDENTIFIER     "_identifier_(definition)"
%token <t_string>   TPACKAGENAME    "_package name_(definition)"
%token <t_string>   TFRANCACOMMENT  "_franca comment_(definition)"
%token <t_string>   TCCOMMENT       "_c-style comment_(definition)"

%token <t_token>    TINTERFACE      "_interface_(keyword)"
%token <t_token>    TPACKAGE        "_package_(keyword)"
%token <t_token>    TVERSION        "_version_(keyword)"
%token <t_token>    TMAJOR          "_major_(keyword)"
%token <t_token>    TMINOR          "_minor_(keyword)"
%token <t_token>    TMETHOD         "_method_(keyword)"
%token <t_token>    TIN             "_in_(keyword)"
%token <t_token>    TOUT            "_out_(keyword)"
%token <t_token>    TBROADCAST      "_broadcast_(keyword)"
%token <t_token>    TSELECTIVE      "_selective_(keyword)"
%token <t_token>    TFIREANDFORGET  "_fireAndForget_(keyword)"

%token <t_token>    TENUMERATION    "_enumeration_(keyword)"
%token <t_token>    TINTEGER        "_Integer_(keyword)"
%token <t_token>    TUINT64         "_UInt64_(keyword)"
%token <t_token>    TINT64          "_Int64_(keyword)"
%token <t_token>    TTRUE           "_true_(keyword)"
%token <t_token>    TFALSE          "_false_(keyword)"

%token <t_token>    TUINT32         "_UInt32_(keyword)"
%token <t_token>    TINT32          "_Int32_(keyword)"
%token <t_token>    TUINT16         "_UInt16_(keyword)"
%token <t_token>    TINT16          "_Int16_(keyword)"
%token <t_token>    TUINT8          "_UInt8_(keyword)"
%token <t_token>    TINT8           "_Int8_(keyword)"

%token <t_token>    TBOOLEAN        "_Boolean_(keyword)"
%token <t_token>    TFLOAT          "_Float_(keyword)"
%token <t_token>    TDOUBLE         "_Double_(keyword)"
%token <t_token>    TSTRING         "_String_(keyword)"
%token <t_token>    TBYTEBUFFER     "_ByteBuffer_(keyword)"

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

%type <t_ast_node> constant
%type <t_ast_node> document
%type <t_ast_node> double_constant
%type <t_ast_node> enum_decl
%type <t_ast_node> enumerator
%type <t_ast_node> enumerator_list
%type <t_ast_node> float_constant
%type <t_ast_node> franca_comment
%type <t_ast_node> identifier
%type <t_ast_node> interface
%type <t_ast_node> interface_member
%type <t_ast_node> interface_member_list
%type <t_ast_node> int_constant
%type <t_ast_node> method_argument
%type <t_ast_node> method_argument_list
%type <t_ast_node> method_decl
%type <t_ast_node> method_body
%type <t_ast_node> method_in_arguments
%type <t_ast_node> method_out_arguments
%type <t_ast_node> package_name
%type <t_ast_node> type
%type <t_ast_node> variable_decl
%type <t_ast_node> version
/*%type <t_ast_node> variable_decl_list   "Variable declarator list"*/

%start document

%%

document : package_name interface { add_child(root_node, $1); add_child(root_node, $2); }
              ;

interface : TINTERFACE identifier TLBRACE version interface_member_list TRBRACE 
                { $$ = new ast::Interface(); add_child($$, $2); add_child($$, $4); add_child($$, $5); }
          | franca_comment TINTERFACE identifier TLBRACE version interface_member_list TRBRACE 
                { $$ = new ast::Interface(); add_child($$, $1); add_child($$, $3); add_child($$, $5); add_child($$, $6); }
          ;

interface_member_list : interface_member { $$ = new ast::ASTNodeList(); add_child($$, $1); }
                      | interface_member_list interface_member { $$ = $1; add_child($$, $2); }
                      ;

interface_member : enum_decl { $$ = $1; }
                 | method_decl { $$ = $1; }
                 | variable_decl { $$ = $1; } /* this is not valid! REMOVE */
                 ;

package_name : TPACKAGE TPACKAGENAME { $$ = new ast::PackageName(*$2); delete $2; }
             ;

version : TVERSION TLBRACE TMAJOR int_constant TMINOR int_constant TRBRACE
            { $$ = new ast::Version(*dynamic_cast<ast::IntConstant*>($4), *dynamic_cast<ast::IntConstant*>($6)); 
                add_child($$, $4); add_child($$, $6); }
        ;

/*variable_decl_list : variable_decl { $$ = new ast::ASTNodeList(); add_child($$, $1); }*/
                   /*| variable_decl_list variable_decl { add_child($1, $2); $$ = $1; }*/
                   /*;*/


method_decl : TBROADCAST identifier TLBRACE method_body TRBRACE 
                { $$ = new ast::BroadcastMethodDecl($2, $4, nullptr, false); add_child($$, $2); add_child($$, $4); }
            | franca_comment TBROADCAST identifier TLBRACE method_body TRBRACE 
                { $$ = new ast::BroadcastMethodDecl($3, $5, $1, false); add_child($$, $3); add_child($$, $5); add_child($$, $1); }
            ;

method_decl : TBROADCAST identifier TSELECTIVE TLBRACE method_body TRBRACE 
                { $$ = new ast::BroadcastMethodDecl($2, $5, nullptr, true); add_child($$, $2); add_child($$, $5); }
            | franca_comment TBROADCAST identifier TSELECTIVE TLBRACE method_body TRBRACE 
                { $$ = new ast::BroadcastMethodDecl($3, $6, $1, true); add_child($$, $3); add_child($$, $6); add_child($$, $1); }
            ;

method_decl : TMETHOD identifier TFIREANDFORGET TLBRACE method_in_arguments TRBRACE 
                { $$ = new ast::MethodDecl($2, $5, nullptr, true); add_child($$, $2); add_child($$, $5); }
            | franca_comment TMETHOD identifier TFIREANDFORGET TLBRACE method_in_arguments TRBRACE
                { $$ = new ast::MethodDecl($3, $6, $1, true); add_child($$, $3); add_child($$, $6); add_child($$, $1); }
            ;

method_decl : TMETHOD identifier TLBRACE method_body TRBRACE 
                { $$ = new ast::MethodDecl($2, $4, nullptr, false); add_child($$, $2); add_child($$, $4); }
            | franca_comment TMETHOD identifier TLBRACE method_body TRBRACE 
                { $$ = new ast::MethodDecl($3, $5, $1, false); add_child($$, $3); add_child($$, $5); add_child($$, $1); }
            ;

method_body : method_out_arguments { $$ = new ast::MethodBody(nullptr, $1); add_child($$, $1); }
            | method_out_arguments method_in_arguments 
                { $$ = new ast::MethodBody($2, $1); add_child($$, $1); add_child($$, $2); }
            | method_in_arguments method_out_arguments 
                { $$ = new ast::MethodBody($1, $2); add_child($$, $2); add_child($$, $1); }
            ;

method_in_arguments : TIN TLBRACE method_argument_list TRBRACE { $$ = $3; }
method_out_arguments : TOUT TLBRACE method_argument_list TRBRACE { $$ = $3; }

method_argument_list : method_argument { $$ = new ast::ASTNodeList(); add_child($$, $1); }
                     | method_argument_list method_argument { $$ = $1; add_child($$, $2); }
                     ;

method_argument : type identifier { $$ = new ast::MethodArgument(); add_child($$, $1); add_child($$, $2); }
                | franca_comment type identifier 
                    { $$ = new ast::MethodArgument(); 
                        add_child($$, $1); add_child($$, $2); add_child($$, $3); }
                ;

enum_decl : TENUMERATION identifier TLBRACE enumerator_list TRBRACE 
                { $$ = new ast::EnumDecl(); add_child($$, $2); add_child($$, $4); }
          | franca_comment TENUMERATION identifier TLBRACE enumerator_list TRBRACE 
                { $$ = new ast::EnumDecl(); add_child($$, $1); add_child($$, $3); add_child($$, $5); }
          ;

enumerator_list : enumerator { $$ = new ast::ASTNodeList(); add_child($$,$1); }
                | enumerator_list enumerator { add_child($1,$2); $$ = $1; }
                ;

enumerator : identifier { $$ = new ast::Enumerator(); add_child($$, $1); }
           | identifier TEQUALS int_constant { $$ = new ast::Enumerator(); add_child($$, $1); add_child($$, $3); }
           | franca_comment identifier { $$ = new ast::Enumerator(); add_child($$, $1); add_child($$, $2); }
           | franca_comment identifier TEQUALS int_constant { $$ = new ast::Enumerator(); add_child($$, $1); add_child($$, $2); add_child($$, $4); }
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

franca_comment : TFRANCACOMMENT { $$ = new ast::FrancaComment(*$1); delete $1; }

variable_decl : type identifier { $$ = new ast::VariableDecl(); add_child($$, $1); add_child($$, $2); }
              | type identifier TEQUALS constant { $$ = new ast::VariableDecl(); add_child($$, $2); add_child($$, $4); }
              ;

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

