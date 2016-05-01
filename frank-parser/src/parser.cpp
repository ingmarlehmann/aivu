#include "parser.h"

#include "gen_bison_parser.hpp"
#include "gen_flex_defines.h"

#include <iostream>
#include <functional>
#include <cassert>

#include "ast/root.h"

extern std::function<void(const char*)> bison_error_callback;
extern std::function<void(const char*)> flex_error_callback;

extern fparser::ast::Root* root_node;

namespace fparser
{
FidlParser::FidlParser()
{
  ::bison_error_callback = std::bind(&FidlParser::parser_error_callback, this, std::placeholders::_1);
  ::flex_error_callback = std::bind(&FidlParser::lexer_error_callback, this, std::placeholders::_1);
}
FidlParser::~FidlParser() { clear(); }
void FidlParser::clear()
{
  if (root_node_)
  {
    delete root_node_;
  }

  file_content_.clear();

  first_error_ = ParserStatus::SUCCESS;
}
ast::Root* FidlParser::root() { return root_node_; }
ParserStatus FidlParser::parse(const std::string& file, bool debug)
{
  clear();

  FILE* file_ptr = fopen(file.c_str(), "r");
  if (file_ptr == nullptr)
  {
    std::cerr << "ERROR: failed to open file '" << file << "'" << std::endl;
    return ParserStatus::ERROR_FILE_NOT_FOUND;
  }

  current_file_ = file;

  char line[512];
  while (fgets(line, sizeof(line), file_ptr))
  {
    file_content_.push_back(std::string(line));
  }
  rewind(file_ptr);

  if (debug)
  {
    yyset_debug(1, lexer_);
  }

  yylex_init(&lexer_);
  yyset_extra(this, lexer_);

  yyset_in(file_ptr, lexer_);

  yyparse(lexer_);

  root_node_ = root_node;

  fclose(file_ptr);

  yylex_destroy(lexer_);

  return first_error_;
}
const std::string& FidlParser::get_line(int lineno)
{
  static std::string empty("");

  assert(lineno <= file_content_.size());
  if (lineno <= file_content_.size())
  {
    return file_content_[lineno - 1];
  }

  return empty;
}

std::string FidlParser::nchars(char const character, int num)
{
  std::string str;
  str.append(num, character);

  return str;
}

void FidlParser::parser_error_callback(const char* error_msg)
{
   const std::string& source_line = get_line(yyget_lineno(lexer_));

   std::cout << current_file_ << ":" << yyget_lineno(lexer_) << ":" << yyget_column(lexer_)-yyget_leng(lexer_) << ": " << error_msg << std::endl;
   std::cout << ">" << source_line;

   first_error_ = ParserStatus::PARSING_ERROR;
}

void FidlParser::lexer_error_callback(const char* error_msg)
{
   const std::string& source_line = get_line(yyget_lineno(lexer_));

   std::cout << current_file_ << ":" << yyget_lineno(lexer_) << ":" << yyget_column(lexer_)-yyget_leng(lexer_) << ": " << error_msg << std::endl;
   std::cout << ">" << source_line;

   first_error_ = ParserStatus::LEXING_ERROR;
}
}  // namespace fparser
