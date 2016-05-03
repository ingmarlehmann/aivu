#ifndef PARSER_H_CKBOSIVH
#define PARSER_H_CKBOSIVH

#include <string>
#include "ast/ast_node.h"

namespace fparser
{
enum class ParserStatus
{
  SUCCESS,
  ERROR_FILE_NOT_FOUND,
  LEXING_ERROR,
  PARSING_ERROR,
  UNKNOWN_ERROR
};

class FidlParser
{
 public:
  ParserStatus 
    parse(const std::string& file, bool debug = false);
  
  void clear();
  
  fparser::ast::Root* 
    root();

 public:
  void* lexer_ = nullptr;

 public:
  FidlParser();
  ~FidlParser();

 public: // will be called from within the parser
  void parse_include(const std::string& filename);
  void pop_include();

 private: // will be called from within the parser
  void lexer_error_callback(const char* error_msg);
  void parser_error_callback(const char* error_msg);
  int  yywrap_callback(void* lexer);
  
 private:
  const std::string& get_line(int lineno);
  std::string nchars(char const character, int num);

 private:
  fparser::ast::Root* root_node_ = nullptr;

  int include_depth_ = 0;

  std::string current_file_;
  std::vector<std::string> file_content_;
  ParserStatus first_error_ = ParserStatus::SUCCESS;
};
}  // namespace fparser

int FidlParser_parse(fparser::FidlParser* parser);

#endif /* end of include guard: PARSER_H_CKBOSIVH */
