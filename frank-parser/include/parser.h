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
  ParserStatus parse(const std::string& file, bool debug = false);
  void clear();
  fparser::ast::Root* root();

 public:
  void* lexer_ = nullptr;
  std::istream* is_ = nullptr;

 public:
  FidlParser();
  ~FidlParser();

 private:
  void lexer_error_callback(const char* error_msg);
  void parser_error_callback(const char* error_msg);
  const std::string& get_line(int lineno);
  std::string nchars(char const character, int num);

 private:
  fparser::ast::Root* root_node_ = nullptr;

  std::string current_file_;
  std::vector<std::string> file_content_;
  ParserStatus first_error_ = ParserStatus::SUCCESS;
};
}  // namespace fparser

int FidlParser_parse(fparser::FidlParser* parser);

#endif /* end of include guard: PARSER_H_CKBOSIVH */
