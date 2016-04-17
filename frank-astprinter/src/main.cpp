#include <iostream>
#include <vector>

#include "ast/ast_node_list.h"
#include "ast/enum_decl.h"
#include "ast/identifier.h"
#include "ast/int_constant.h"
#include "ast/root.h"
#include "parser.h"

#include "ast_print_visitor.h"

int main(int argc, char** argv)
{
  if (argc < 2)
  {
    std::string program_name(argv[0]);

    std::cerr << "ERROR: no input file specified." << std::endl;
    std::cout << "usage: " << program_name << " <file>" << std::endl;
    return -1;
  }

  std::string filename(argv[1]);

  fparser::FidlParser parser;
  fparser::ParserStatus status = parser.parse(filename);
  if(fparser::ParserStatus::SUCCESS != status)
  {
      std::cout << "Failed to parse file '" << filename << "'" << std::endl;
      return -1;
  }

  fparser::ast::Root* root_node = parser.root();

  if (root_node != nullptr)
  {
    ASTPrintVisitor ast_print_visitor(2, ' ');
    root_node->accept(ast_print_visitor);
  }

  return 0;
}
