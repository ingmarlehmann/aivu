#include "parser.h"

#include "gen_bison_parser.hpp"
#include "gen_flex_defines.h"

#include <iostream>
#include <functional>
#include <cassert>
#include <algorithm>

#include "ast/root.h"

extern std::function<void(const char*)> g_bison_error_callback;
extern std::function<void(const char*)> g_flex_error_callback;
extern std::function<int(yyscan_t)> g_yywrap_callback;

extern fparser::ast::Root* g_root_node;

namespace fparser
{
FidlParser::FidlParser()
{
  ::g_bison_error_callback = std::bind(&FidlParser::parser_error_callback, this, std::placeholders::_1);
  ::g_flex_error_callback = std::bind(&FidlParser::lexer_error_callback, this, std::placeholders::_1);
  ::g_yywrap_callback = std::bind(&FidlParser::yywrap_callback, this, std::placeholders::_1);
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
void FidlParser::push_package(ast::ASTNode* package) { package_stack_.push_back(package); }
void FidlParser::pop_package() { package_stack_.pop_back(); }
ast::ASTNode* FidlParser::current_package() { return package_stack_.empty() ? nullptr : *(package_stack_.end()); }
ast::Root* FidlParser::root() { return root_node_; }
void FidlParser::parse_include(const std::string& filename)
{
  // std::cout << "Parsing include file '" << filename << "'\n";

  FILE* file_ptr = fopen(filename.c_str(), "r");
  if (file_ptr == nullptr)
  {
    std::cerr << "ERROR: failed to open include '" << filename << "'" << std::endl;
    return;
  }

  YY_BUFFER_STATE new_buf = yy_create_buffer(file_ptr, YY_BUF_SIZE, lexer_);
  yypush_buffer_state(new_buf, lexer_);

  ++include_depth_;
}

int FidlParser::yywrap_callback(void* lexer)
{
  if (include_depth_ > 0)
  {
    // std::cout << "Found EOF in include file. Popping state in lexer. \n";
    yypop_buffer_state(lexer_);
    --include_depth_;
    pop_package();
    return 0;
  }

  // std::cout << "Found EOF in base file. Terminating lexer. \n";
  return 1;
}

void FidlParser::pop_include() {}
ParserStatus FidlParser::parse(const std::string& file, bool debug)
{
  clear();

  // std::cout << "Opening file '" << file << "' for parsing\n";

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

  // std::cout << "Initializing lexer.\n";

  yylex_init(&lexer_);
  yyset_extra(this, lexer_);
  yyset_in(file_ptr, lexer_);

  // std::cout << "Starting parsing of '" << file << "'.\n";

  yyparse(this, lexer_);

  // std::cout << "Done parsing '" << file << "'.\n";

  root_node_ = g_root_node;

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
  // const std::string& source_line = get_line(yyget_lineno(lexer_));
  const std::string& source_line = std::string("xxx");

  std::cout << current_file_ << ":" << yyget_lineno(lexer_) << ":" << yyget_column(lexer_) - yyget_leng(lexer_) << ": " << error_msg << std::endl;
  std::cout << ">" << source_line;

  first_error_ = ParserStatus::PARSING_ERROR;
}

void FidlParser::lexer_error_callback(const char* error_msg)
{
  const std::string& source_line = get_line(yyget_lineno(lexer_));

  std::cout << current_file_ << ":" << yyget_lineno(lexer_) << ":" << yyget_column(lexer_) - yyget_leng(lexer_) << ": " << error_msg << std::endl;
  std::cout << ">" << source_line;

  first_error_ = ParserStatus::LEXING_ERROR;
}
}  // namespace fparser
