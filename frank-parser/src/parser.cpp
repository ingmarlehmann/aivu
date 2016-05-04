#include "parser.h"

#include "gen_bison_parser.hpp"
#include "gen_flex_defines.h"

#include <iostream>
#include <functional>
#include <cassert>
#include <algorithm>

#include "ast/root.h"
#include "ast/package.h"
#include "ast/import_decl.h"
#include "ast/string_constant.h"

extern std::function<void(const char*)> g_bison_error_callback;
extern std::function<void(const char*)> g_flex_error_callback;
extern std::function<int(yyscan_t)> g_yywrap_callback;

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

  open_files_.clear();

  first_error_ = ParserStatus::SUCCESS;
}
void FidlParser::add_root_object(ast::ASTNode* object)
{
  if (ast::Package* package = dynamic_cast<ast::Package*>(object))
  {
    root_node_->add_child(object);
    set_current_package(package);
  }
  else if (ast::ImportDecl* import = dynamic_cast<ast::ImportDecl*>(object))
  {
    current_package()->add_child(object);
    ast::StringConstant const* filename = dynamic_cast<ast::StringConstant const*>(&(import->filename()));
    assert(filename);
    parse_import(filename->value());
  }
  else
  {
    current_package()->add_child(object);
  }
}
void FidlParser::set_current_package(ast::Package* package)
{
  assert(!open_files_.empty());
  //std::cout << "setting current package to: " << package << "\n";
  open_files_.back().package_ = package;
}
ast::Package* FidlParser::current_package()
{
  assert(!open_files_.empty());
  //std::cout << "getting current package: " << open_files_.back().package_ << "\n";
  return open_files_.back().package_;
}
const std::string& FidlParser::current_file() const
{
  assert(!open_files_.empty());
  return open_files_.back().filename_;
}
FILE* FidlParser::current_file_ptr()
{
  assert(!open_files_.empty());
  return open_files_.back().file_ptr_;
}
ast::Root* FidlParser::root() { return root_node_; }
void FidlParser::parse_import(const std::string& filename)
{
  //std::cout << "Parsing include file '" << filename << "'\n";

  bool ok = open_and_buffer_file(&open_files_, filename);
  if (!ok)
  {
    return;
  }

  YY_BUFFER_STATE new_buf = yy_create_buffer(open_files_.back().file_ptr_, YY_BUF_SIZE, lexer_);
  yypush_buffer_state(new_buf, lexer_);
}

int FidlParser::yywrap_callback(void* lexer)
{
  if (open_files_.size() > 1)
  {
    pop_import();
    return 0;
  }

  // std::cout << "Found EOF in base file. Terminating lexer. \n";
  return 1;
}
void FidlParser::pop_import()
{
  // std::cout << "Found EOF in include file. Popping state in lexer. \n";
  yypop_buffer_state(lexer_);

  assert(open_files_.size() > 1);
  open_files_.pop_back();
}
bool FidlParser::open_and_buffer_file(std::vector<ParserFileInfo>* open_files, const std::string& filename)
{
  FILE* file_ptr = fopen(filename.c_str(), "r");
  if (file_ptr == nullptr)
  {
    std::cerr << "ERROR: failed to open file '" << filename << "'" << std::endl;
    first_error_ = ParserStatus::ERROR_FILE_NOT_FOUND;
    return false;
  }

  ParserFileInfo file_info;
  file_info.file_ptr_ = file_ptr;
  file_info.filename_ = filename;

  char line[512];
  while (fgets(line, sizeof(line), file_info.file_ptr_))
  {
    file_info.file_content_.push_back(std::string(line));
  }
  //std::cout << "buffered " << file_info.file_content_.size() << " lines of file " << filename << "\n";
  rewind(file_info.file_ptr_);

  open_files->push_back(file_info);

  return true;
}
ParserStatus FidlParser::parse(const std::string& file, bool debug)
{
  clear();

  //std::cout << "Opening file '" << file << "' for parsing\n";
  bool ok = open_and_buffer_file(&open_files_, file);
  if (!ok)
  {
    return first_error_;
  }

  assert(open_files_.size() == 1);

  //std::cout << "Initializing lexer.\n";

  yylex_init(&lexer_);

  if (debug)
  {
    yyset_debug(1, lexer_);
    yydebug = 1;
  }

  yyset_extra(this, lexer_);
  yyset_in(current_file_ptr(), lexer_);

  //std::cout << "Starting parsing of '" << current_file() << "'.\n";

  root_node_ = new ast::Root();

  yyparse(this, lexer_);

  //std::cout << "Done parsing '" << current_file() << "'.\n";

  yylex_destroy(lexer_);

  return first_error_;
}
const std::string& FidlParser::get_line(const std::vector<std::string>& file_buffer, int lineno)
{
  const static std::string empty("");

  assert(lineno <= file_buffer.size());
  if (lineno <= file_buffer.size())
  {
    return file_buffer.at(lineno - 1);
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
  const std::string& source_line = get_line(open_files_.back().file_content_, yyget_lineno(lexer_));
  // const std::string& source_line = std::string("xxx");

  std::cout << open_files_.back().filename_ << ":" << yyget_lineno(lexer_) << ":" << yyget_column(lexer_) - yyget_leng(lexer_) << ": " << error_msg
            << std::endl;
  std::cout << ">" << source_line;

  first_error_ = ParserStatus::PARSING_ERROR;
}

void FidlParser::lexer_error_callback(const char* error_msg)
{
  const std::string& source_line = get_line(open_files_.back().file_content_, yyget_lineno(lexer_));

  std::cout << open_files_.back().filename_ << ":" << yyget_lineno(lexer_) << ":" << yyget_column(lexer_) - yyget_leng(lexer_) << ": " << error_msg
            << std::endl;
  std::cout << ">" << source_line;

  first_error_ = ParserStatus::LEXING_ERROR;
}
}  // namespace fparser
