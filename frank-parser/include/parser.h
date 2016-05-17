#ifndef PARSER_H_CKBOSIVH
#define PARSER_H_CKBOSIVH

#include <string>
#include "ast/ast_node.h"

namespace fparser
{
namespace ast
{
class Package;
}

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

 public:
  FidlParser();
  ~FidlParser();

 public:  // will be called from fidl_parser.y
  
  // Add a top level element to the ast root node.
  //
  // Depending on the object type, some custom actions
  // may be performed such as parsing an include file,
  // setting current package name, etc.
  void add_root_object(ast::ASTNode* object);

  ast::Package* current_package();
  const std::string& current_file() const;
  FILE* current_file_ptr();

 private:  // will be invoked by callbacks in fidl_parser.y
  void lexer_error_callback(const char* error_msg);
  void parser_error_callback(const char* error_msg);
  int yywrap_callback(void* lexer);

 private:
  struct ParserFileInfo
  {
      //~ParserFileInfo() { if(file_ptr_ != nullptr) { fclose(file_ptr_); file_ptr_ = nullptr; } }

      std::vector<std::string> file_content_;
      ast::Package* package_ = nullptr;
      FILE* file_ptr_ = nullptr;
      std::string filename_;
  };
  
  void parse_import(const std::string& filename);
  void pop_import();

  void set_current_package(ast::Package* package);

  const std::string& get_line(const std::vector<std::string>& file_buffer, int lineno);
  std::string nchars(char const character, int num);

  bool open_and_buffer_file(std::vector<ParserFileInfo>* files, const std::string& filename);

 private:
  fparser::ast::Root* root_node_ = nullptr;

  std::vector<ParserFileInfo> open_files_;
  std::vector<std::string> include_directories_;
  ParserStatus first_error_ = ParserStatus::SUCCESS;
};
}  // namespace fparser

#endif /* end of include guard: PARSER_H_CKBOSIVH */
