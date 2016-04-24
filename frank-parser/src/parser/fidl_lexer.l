%{
#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>
#include "ast/ast_node.h"
#include "gen_bison_parser.hpp"

int yycolumn = 1;

#define SAVE_TOKEN     yylval.t_string = new std::string(yytext, yyleng)
#define TOKEN(t)       (yylval.t_token = t)
#define YY_USER_ACTION \
    yylloc.first_line = yylloc.last_line = yylineno; \
    yylloc.first_column = yycolumn; yylloc.last_column = yycolumn + (int)yyleng - 1; \
    yycolumn += (int)yyleng;

std::function<void(char const*)> flex_error_callback;

extern "C" int yywrap() { }
%}

%option yylineno
        /*%option debug*/

    /*                   */
    /* Reserved keywords */
    /* ================= */
    /*                   */
ATTRIBUTE               attribute

IMPORT                  import
FROM                    from
VERSION                 version
BROADCAST               broadcast
SELECTIVE               selective
FIREANDFORGET           fireAndForget

IN                      in
OUT                     out
MAJOR                   major
MINOR                   minor
PACKAGE                 package
METHOD                  method
EXTENDS                 extends
POLYMORPHIC             polymorphic

ENUMERATION             enumeration
STRUCT                  struct
UNION                   union
MAP                     map
TYPECOLLECTION          typeCollection

TYPEDEF                 typedef
IS                      is
TO                      to
INTERFACE               interface
CONST                   const
ARRAY                   array
OF                      of

INTEGER                 Integer
UINT64                  UInt64
INT64                   Int64
TRUE                    true
FALSE                   false

UINT32                  UInt32
INT32                   Int32
UINT16                  UInt16
INT16                   Int16
UINT8                   UInt8
INT8                    Int8

BOOLEAN                 Boolean
FLOAT                   Float
DOUBLE                  Double
STRING                  String
BYTEBUFFER              ByteBuffer

    /* ===================================================== */
    /* OPERATORS                                             */
    /* ===================================================== */
TPLUS                   \+
TMINUS                  -
TTIMES                  \*
TDIVIDE                 \/
TMOD                    %
TOR                     \|
TAND                    &
TNOT                    ~
TXOR                    \^
TLSHIFT                 <<
TRSHIFT                 >>
TLOR                    \|\|
TLAND                   &&
TLNOT                   !
TLT                     <
TGT                     >
TLE                     <=
TGE                     >=
TEQ                     ==
TNE                     !=
    /* ===================================================== */
    /* DELIMITERS                                            */
    /* ===================================================== */
TLPAREN                 (
TRPAREN                 )
TLBRACKET               \[
TRBRACKET               \]
TLBRACE                 \{
TRBRACE                 \}
TCOMMA                  ,
TPERIOD                 .
TSEMI                   ;
TCOLON                  :
 
    /* ===================================================== */
    /* ASSIGNMENT                                             */
    /* ===================================================== */
TEQUALS                 =

    /* ===================================================== */
    
    /* ===================================================== */
    /* COMMENTS                                              */
    /* ===================================================== */
FRANCA_COMMENT          \<\*{2,}([^*]|[\r\n]|(\*+([^*\>]|[\r\n])))*\*{2,}\>
C_COMMENT               \/\/.*
    /* ===================================================== */

    /* ===================================================== */
    /* Identifiers */
    /* ===================================================== */
IDENTIFIER              [a-zA-Z_$][0-9a-zA-Z_$]*
    /* ===================================================== */

    /* ===================================================== */
    /* CONSTANTS */
    /* ===================================================== */
HEX_PREFIX              0[xX]
HEX_DIGITS              [0-9a-fA-F]+
BIN_PREFIX              0[bB]
BIN_DIGITS              [01]+

    /*integer constants (K&R2: A.2.5.1)*/
INTEGER_SUFFIX_OPT      (([uU]ll)|([uU]LL)|(ll[uU]?)|(LL[uU]?)|([uU][lL])|([lL][uU]?)|[uU])?

INT_CONST_DEC           (0{INTEGER_SUFFIX_OPT})|([1-9][0-9]*{INTEGER_SUFFIX_OPT})
INT_CONST_OCT           0[0-7]*{INTEGER_SUFFIX_OPT}
INT_CONST_HEX           {HEX_PREFIX}{HEX_DIGITS}{INTEGER_SUFFIX_OPT}
INT_CONST_BIN           {BIN_PREFIX}{BIN_DIGITS}{INTEGER_SUFFIX_OPT}

    /*floating constants (K&R2: A.2.5.3)*/
EXPONENT_PART           [eE][-+]?[0-9]+
FRACTIONAL_CONSTANT     ([0-9]*\.[0-9]+)|([0-9]+\.)
FLOAT_CONST             (({FRACTIONAL_CONSTANT}{EXPONENT_PART}?)|([0-9]+{EXPONENT_PART}))[FfLl]?
DOUBLE_CONST            (({FRACTIONAL_CONSTANT}{EXPONENT_PART}?)|([0-9]+{EXPONENT_PART}))[Dd]?
BINARY_EXPONENT_PART    [pP][+-]?[0-9]+
HEX_FRACTIONAL_CONSTANT (({HEX_DIGITS})?\.{HEX_DIGITS})|({HEX_DIGITS}\.)
FLOAT_CONST_HEX         {HEX_PREFIX}({HEX_DIGITS}|{HEX_FRACTIONAL_CONSTANT}){BINARY_EXPONENT_PART}[FfLl]?
DOUBLE_CONST_HEX        {HEX_PREFIX}({HEX_DIGITS}|{HEX_FRACTIONAL_CONSTANT}){BINARY_EXPONENT_PART}[Dd]?
    /* ===================================================== */

PACKAGE_NAME_ID         [a-zA-Z_]{1}[a-zA-Z0-9_]*
PACKAGE_NAME            {PACKAGE_NAME_ID}(\.{PACKAGE_NAME_ID})*
%%

    /*                   */
    /* Reserved keywords */
    /* ================= */
    /*                   */
    /*{ATTRIBUTE}               return TOKEN(TATTRIBUTE);*/

    /*{IMPORT}              return TOKEN(TIMPORT);*/
    /*{FROM}                    return TOKEN(TFROM);*/
    /*{EXTENDS}             return TOKEN(TEXTENDS);*/
    /*{POLYMORPHIC}         return TOKEN(TPOLYMORPHIC);*/
    /*{UNION}                   return TOKEN(TUNION);*/
    /*{MAP}                 return TOKEN(TMAP);*/
    /*{TYPECOLLECTION}      return TOKEN(TTYPECOLLECTION);*/
    /*{CONST}                   return TOKEN(TCONST);*/
    /*{ARRAY}                   return TOKEN(TARRAY);*/
    /*{OF}                  return TOKEN(TOF);*/

    /*{TYPEDEF}             return TOKEN(TTYPEDEF);*/
    /*{IS}                  return TOKEN(TIS);*/
    /*{TO}                  return TOKEN(TTO);*/
    /*{CONST}                   return TOKEN(TCONST);*/
    /*{ARRAY}                   return TOKEN(TARRAY);*/
    /*{OF}                  return TOKEN(TOF);*/

{FIREANDFORGET}  return      TOKEN(TFIREANDFORGET);
{METHOD}         return      TOKEN(TMETHOD);
{STRUCT}         return      TOKEN(TSTRUCT);
{BROADCAST}      return      TOKEN(TBROADCAST);
{SELECTIVE}      return      TOKEN(TSELECTIVE);
{VERSION}        return      TOKEN(TVERSION);
{IN}             return      TOKEN(TIN);
{OUT}            return      TOKEN(TOUT);
{MAJOR}          return      TOKEN(TMAJOR);
{MINOR}          return      TOKEN(TMINOR);
{PACKAGE}        return      TOKEN(TPACKAGE);
{ENUMERATION}    return      TOKEN(TENUMERATION);
{INTERFACE}      return      TOKEN(TINTERFACE);

{INTEGER}        return      TOKEN(TINTEGER);
{UINT64}         return      TOKEN(TUINT64);
{INT64}          return      TOKEN(TINT64);
{TRUE}           return      TOKEN(TTRUE);
{FALSE}          return      TOKEN(TFALSE);

{UINT32}         return      TOKEN(TUINT32);
{INT32}          return      TOKEN(TINT32);
{UINT16}         return      TOKEN(TUINT16);
{INT16}          return      TOKEN(TINT16);
{UINT8}          return      TOKEN(TUINT8);
{INT8}           return      TOKEN(TINT8);

{BOOLEAN}        return      TOKEN(TBOOLEAN);
{FLOAT}          return      TOKEN(TFLOAT);
{DOUBLE}         return      TOKEN(TDOUBLE);
{STRING}         return      TOKEN(TSTRING);
{BYTEBUFFER}     return      TOKEN(TBYTEBUFFER);

{FRANCA_COMMENT} SAVE_TOKEN; return TFRANCACOMMENT;
{C_COMMENT}      SAVE_TOKEN; return TCCOMMENT;

    /* Identifiers */
{IDENTIFIER}     SAVE_TOKEN; return TIDENTIFIER;

{PACKAGE_NAME}   SAVE_TOKEN; return TPACKAGENAME;

{INT_CONST_DEC}         { yylval.t_longlong = strtol(yytext, NULL, 0); return TINT_CONST_DEC; }
{INT_CONST_OCT}         { yylval.t_longlong = strtol(yytext, NULL, 0); return TINT_CONST_OCT; }
{INT_CONST_HEX}         { yylval.t_longlong = strtol(yytext, NULL, 0); return TINT_CONST_HEX; }
{INT_CONST_BIN}         { yylval.t_longlong = strtol(yytext, NULL, 2); return TINT_CONST_BIN; }

{FLOAT_CONST}           { yylval.t_float  = strtof(yytext, NULL); return TFLOAT_CONST;      }
{FLOAT_CONST_HEX}       { yylval.t_float  = strtof(yytext, NULL); return TFLOAT_CONST_HEX;  }
{DOUBLE_CONST}          { yylval.t_double = strtod(yytext, NULL); return TDOUBLE_CONST;     }
{DOUBLE_CONST_HEX}      { yylval.t_double = strtod(yytext, NULL); return TDOUBLE_CONST_HEX; }

{TPLUS}                 return TOKEN(TPLUS);
{TMINUS}                return TOKEN(TMINUS);
{TTIMES}                return TOKEN(TTIMES);
{TDIVIDE}               return TOKEN(TDIVIDE);
{TMOD}                  return TOKEN(TMOD);
{TOR}                   return TOKEN(TOR);
{TAND}                  return TOKEN(TAND);
{TNOT}                  return TOKEN(TNOT);
{TXOR}                  return TOKEN(TXOR);
{TLSHIFT}               return TOKEN(TLSHIFT);
{TRSHIFT}               return TOKEN(TRSHIFT);
{TLOR}                  return TOKEN(TLOR);
{TLAND}                 return TOKEN(TLAND);
{TLNOT}                 return TOKEN(TLNOT);
{TLT}                   return TOKEN(TLT);
{TGT}                   return TOKEN(TGT);
{TLE}                   return TOKEN(TLE);
{TGE}                   return TOKEN(TGE);
{TEQ}                   return TOKEN(TEQ);
{TNE}                   return TOKEN(TNE);

    /*{TLPAREN}               return TOKEN(TLPAREN);*/
    /*{TRPAREN}               return TOKEN(TRPAREN);*/
{TLBRACKET}             return TOKEN(TLBRACKET);
{TRBRACKET}             return TOKEN(TRBRACKET);
{TLBRACE}               return TOKEN(TLBRACE);
{TRBRACE}               return TOKEN(TRBRACE);
    /*{TCOMMA}                return TOKEN(TCOMMA);*/
    /*{TPERIOD}               return TOKEN(TPERIOD);*/
    /*{TSEMI}                 return TOKEN(TSEMI);*/
    /*{TCOLON}                return TOKEN(TCOLON); */

{TEQUALS}               return TOKEN(TEQUALS);

[\r?\n]                 { yycolumn = 0; }
[ \t]
.                       { 
                            if(flex_error_callback) 
                            { 
                                std::stringstream ss;
                                ss << "[invalid token (char): '" << std::hex << yytext << "']";
                                flex_error_callback(ss.str().c_str()); 
                            } 
                            yyterminate(); 
                        } 
%%
