#include <iostream>
#include <vector>

#include "ast/ast_node_list.h"
#include "ast/enum_decl.h"
#include "ast/identifier.h"
#include "ast/int_constant.h"
#include "ast/root.h"
#include "parser.h"

class EnumVisitor : public fparser::ast::ASTNodeVisitor
{
 public:
  virtual void visit(fparser::ast::Root& node)
  {
    std::cout << "Visiting RootNode" << std::endl;
    visit_children(node, *this);
  }

  virtual void visit(fparser::ast::ASTNodeList& node)
  {
    std::cout << "Visiting NodeList" << std::endl;
    visit_children(node, *this);
  }

  virtual void visit(fparser::ast::Identifier& node)
  {
    std::cout << "Visiting Identifier" << std::endl;
    std::cout << " - name: " << node.name() << std::endl;
    visit_children(node, *this);
  }

  virtual void visit(fparser::ast::EnumDecl& node)
  {
    std::cout << "Visiting EnumDecl" << std::endl;
    visit_children(node, *this);
  }

 private:
  void visit_children(fparser::ast::ASTNode& node, EnumVisitor& visitor)
  {
    for (auto curr_node : node.children())
    {
      curr_node->accept(visitor);
    }
  }
};

int main(int argc, char** argv)
{
  if (argc < 2)
  {
    std::cerr << "ERROR: no file specified." << std::endl;
    std::cout << "usage: fidl_parser <file>" << std::endl;
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

  fparser::ast::Root* local_root_node = parser.root();

  if (local_root_node != nullptr)
  {
    EnumVisitor enum_visitor;
    local_root_node->accept(enum_visitor);

    // local_root_node->render(std::cout, 2);
  }

  return 0;
}
