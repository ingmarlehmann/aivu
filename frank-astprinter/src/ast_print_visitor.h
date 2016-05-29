#ifndef AST_PRINTER_H_2TARC9O7
#define AST_PRINTER_H_2TARC9O7

#include "ast/ast_node_visitor.h"
#include "ast/ast_node.h"

class ASTPrintVisitor : public fparser::ast::ASTNodeVisitor
{
 public:
  ASTPrintVisitor();
  ASTPrintVisitor(int indent_step_size);
  ASTPrintVisitor(int indent_step_size, char const indent_character);

 public:
  virtual void visit(fparser::ast::ASTNodeList&         node) override;
  virtual void visit(fparser::ast::ArrayVariableDecl&   node) override;
  virtual void visit(fparser::ast::AttributeDecl&       node) override;
  virtual void visit(fparser::ast::BroadcastMethodDecl& node) override;
  virtual void visit(fparser::ast::DoubleConstant&      node) override;
  virtual void visit(fparser::ast::EnumDecl&            node) override;
  virtual void visit(fparser::ast::Enumerator&          node) override;
  virtual void visit(fparser::ast::FloatConstant&       node) override;
  virtual void visit(fparser::ast::FrancaComment&       node) override;
  virtual void visit(fparser::ast::Identifier&          node) override;
  virtual void visit(fparser::ast::ImportDecl&          node) override;
  virtual void visit(fparser::ast::IntConstant&         node) override;
  virtual void visit(fparser::ast::Interface&           node) override;
  virtual void visit(fparser::ast::MethodArgument&      node) override;
  virtual void visit(fparser::ast::MethodBody&          node) override;
  virtual void visit(fparser::ast::MethodDecl&          node) override;
  virtual void visit(fparser::ast::Package&             node) override;
  virtual void visit(fparser::ast::Root&                node) override;
  virtual void visit(fparser::ast::StringConstant&      node) override;
  virtual void visit(fparser::ast::StructDecl&          node) override;
  virtual void visit(fparser::ast::Type&                node) override;
  virtual void visit(fparser::ast::VariableDecl&        node) override;
  virtual void visit(fparser::ast::Version&             node) override;

 private:
  void visit_children(fparser::ast::ASTNode& node, ASTPrintVisitor& visitor);
  void increase_indent();
  void decrease_indent();
  std::string nchars(const char character, int num);

 private:
  int  indent_step_size_ = 2;
  char indent_character_ = ' ';
  int  indentation_      = 0;
};

#endif /* end of include guard: AST_PRINTER_H_2TARC9O7 */
