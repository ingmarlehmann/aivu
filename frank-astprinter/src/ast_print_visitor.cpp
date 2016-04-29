#include "ast_print_visitor.h"

#include <iostream>

#include "ast/ast_node.h"
#include "ast/ast_node_list.h"
#include "ast/broadcast_method_decl.h"
#include "ast/double_constant.h"
#include "ast/enum_decl.h"
#include "ast/enumerator.h"
#include "ast/float_constant.h"
#include "ast/franca_comment.h"
#include "ast/identifier.h"
#include "ast/implicit_array_decl.h"
#include "ast/import_decl.h"
#include "ast/int_constant.h"
#include "ast/interface.h"
#include "ast/method_argument.h"
#include "ast/method_body.h"
#include "ast/method_decl.h"
#include "ast/package.h"
#include "ast/root.h"
#include "ast/string_constant.h"
#include "ast/struct_decl.h"
#include "ast/type.h"
#include "ast/variable_decl.h"
#include "ast/version.h"

ASTPrintVisitor::ASTPrintVisitor() {}
ASTPrintVisitor::ASTPrintVisitor(int indent_step_size) : indent_step_size_(indent_step_size) {}
ASTPrintVisitor::ASTPrintVisitor(int indent_step_size, const char indent_character) : indent_step_size_(indent_step_size), indent_character_(indent_character)
{
}

void ASTPrintVisitor::visit(fparser::ast::ImplicitArrayDecl &node)
{
  std::cout << nchars(indent_character_, indentation_) << "ImplicitArrayDecl" << std::endl;
  visit_children(node, *this);
}

void ASTPrintVisitor::visit(fparser::ast::StructDecl &node)
{
  std::cout << nchars(indent_character_, indentation_) << "StructDecl" << std::endl;
  visit_children(node, *this);
}

void ASTPrintVisitor::visit(fparser::ast::MethodArgument &node)
{
  std::cout << nchars(indent_character_, indentation_) << "MethodArgument" << std::endl;
  visit_children(node, *this);
}

void ASTPrintVisitor::visit(fparser::ast::MethodBody &node)
{
  std::cout << nchars(indent_character_, indentation_) << "MethodBody" << std::endl;
  visit_children(node, *this);
}

void ASTPrintVisitor::visit(fparser::ast::MethodDecl &node)
{
  std::string is_fire_and_forget = node.fire_and_forget() ? "true" : "false";
  std::cout << nchars(indent_character_, indentation_) << "MethodDecl(fireAndForget:" << is_fire_and_forget << ")" << std::endl;
  visit_children(node, *this);
}

void ASTPrintVisitor::visit(fparser::ast::ImportDecl &node)
{
  std::cout << nchars(indent_character_, indentation_) << "ImportDecl()" << std::endl;
  visit_children(node, *this);
}

void ASTPrintVisitor::visit(fparser::ast::Package &node)
{
  std::cout << nchars(indent_character_, indentation_) << "Package(" << node.package_name() << ")" << std::endl;
  visit_children(node, *this);
}

void ASTPrintVisitor::visit(fparser::ast::BroadcastMethodDecl &node)
{
  std::string is_selective = node.is_selective() ? "true" : "false";
  std::cout << nchars(indent_character_, indentation_) << "BroadcastMethodDecl(selective:" << is_selective << ")" << std::endl;
  // std::cout << "num children: " << node.children().size() << "\n";
  visit_children(node, *this);
}

void ASTPrintVisitor::visit(fparser::ast::Root &node)
{
  std::cout << nchars(indent_character_, indentation_) << "RootNode" << std::endl;
  visit_children(node, *this);
}

void ASTPrintVisitor::visit(fparser::ast::FrancaComment &node)
{
  std::cout << nchars(indent_character_, indentation_) << "FrancaComment(" << node.comment() << ")" << std::endl;
  visit_children(node, *this);
}

void ASTPrintVisitor::visit(fparser::ast::Interface &node)
{
  std::cout << nchars(indent_character_, indentation_) << "Interface" << std::endl;
  visit_children(node, *this);
}

void ASTPrintVisitor::visit(fparser::ast::Version &node)
{
  std::cout << nchars(indent_character_, indentation_) << "Version" << std::endl;
  visit_children(node, *this);
}

void ASTPrintVisitor::visit(fparser::ast::StringConstant &node)
{
  std::cout << nchars(indent_character_, indentation_) << "StringConstant(" << node.value() << ")" << std::endl;
  visit_children(node, *this);
}

void ASTPrintVisitor::visit(fparser::ast::Type &node)
{
  std::cout << nchars(indent_character_, indentation_) << "Type(" << node.id() << "," << node.name() << ")" << std::endl;
  visit_children(node, *this);
}

void ASTPrintVisitor::visit(fparser::ast::VariableDecl &node)
{
  std::cout << nchars(indent_character_, indentation_) << "VariableDecl" << std::endl;
  visit_children(node, *this);
}

void ASTPrintVisitor::visit(fparser::ast::ASTNodeList &node)
{
  std::cout << nchars(indent_character_, indentation_) << "NodeList" << std::endl;
  visit_children(node, *this);
}

void ASTPrintVisitor::visit(fparser::ast::DoubleConstant &node)
{
  std::cout << nchars(indent_character_, indentation_) << "DoubleConstant" << std::endl;
  visit_children(node, *this);
}

void ASTPrintVisitor::visit(fparser::ast::Identifier &node)
{
  std::cout << nchars(indent_character_, indentation_) << "Identifier(" << node.name() << ")" << std::endl;
  visit_children(node, *this);
}

void ASTPrintVisitor::visit(fparser::ast::IntConstant &node)
{
  std::cout << nchars(indent_character_, indentation_) << "IntConstant(" << node.value() << ")" << std::endl;
  visit_children(node, *this);
}

void ASTPrintVisitor::visit(fparser::ast::EnumDecl &node)
{
  std::cout << nchars(indent_character_, indentation_) << "EnumDecl" << std::endl;
  visit_children(node, *this);
}

void ASTPrintVisitor::visit(fparser::ast::Enumerator &node)
{
  std::cout << nchars(indent_character_, indentation_) << "Enumerator" << std::endl;
  visit_children(node, *this);
}

void ASTPrintVisitor::visit(fparser::ast::FloatConstant &node)
{
  std::cout << nchars(indent_character_, indentation_) << "FloatConstant" << std::endl;
  visit_children(node, *this);
}

void ASTPrintVisitor::visit_children(fparser::ast::ASTNode &node, ASTPrintVisitor &visitor)
{
  for (auto curr_node : node.children())
  {
    increase_indent();
    curr_node->accept(visitor);
    decrease_indent();
  }
}

void ASTPrintVisitor::increase_indent() { indentation_ += indent_step_size_; }
void ASTPrintVisitor::decrease_indent()
{
  if (indentation_ + indent_step_size_ >= 0)
  {
    indentation_ -= indent_step_size_;
  }
}

std::string ASTPrintVisitor::nchars(const char character, int num)
{
  std::string ret;
  ret.append(num, character);

  return ret;
}
