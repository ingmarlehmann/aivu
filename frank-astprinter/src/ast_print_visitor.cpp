#include "ast_print_visitor.h"

#include <iostream>

#include "ast/ast_node.h"
#include "ast/ast_node_list.h"
#include "ast/double_constant.h"
#include "ast/enumerator.h"
#include "ast/enum_decl.h"
#include "ast/float_constant.h"
#include "ast/identifier.h"
#include "ast/int_constant.h"
#include "ast/root.h"
#include "ast/string_constant.h"
#include "ast/type.h"
#include "ast/variable_decl.h"

void ASTPrintVisitor::visit(fparser::ast::Root &node)
{
    std::cout << nchars(' ', indentation_) << "RootNode" << std::endl;
    visit_children(node, *this);
}

void ASTPrintVisitor::visit(fparser::ast::StringConstant &node)
{
    std::cout << nchars(' ', indentation_) << "StringConstant(" << node.value() << ")" << std::endl;
    visit_children(node, *this);
}

void ASTPrintVisitor::visit(fparser::ast::Type &node)
{
    std::cout << nchars(' ', indentation_) << "Type(" << node.id() << "," << node.name() << ")" << std::endl;
    visit_children(node, *this);
}

void ASTPrintVisitor::visit(fparser::ast::VariableDecl &node)
{
    std::cout << nchars(' ', indentation_) << "VariableDecl" << std::endl;
    visit_children(node, *this);
}

void ASTPrintVisitor::visit(fparser::ast::ASTNodeList &node)
{
    std::cout << nchars(' ', indentation_) << "NodeList" << std::endl;
    visit_children(node, *this);
}

void ASTPrintVisitor::visit(fparser::ast::DoubleConstant &node)
{
    std::cout << nchars(' ', indentation_) << "DoubleConstant" << std::endl;
    visit_children(node, *this);
}

void ASTPrintVisitor::visit(fparser::ast::Identifier &node)
{
    std::cout << nchars(' ', indentation_) << "Identifier(" << node.name() << ")" << std::endl;
    visit_children(node, *this);
}

void ASTPrintVisitor::visit(fparser::ast::IntConstant &node)
{
    std::cout << nchars(' ', indentation_) << "IntConstant(" << node.value() << ")" << std::endl;
    visit_children(node, *this);
}

void ASTPrintVisitor::visit(fparser::ast::EnumDecl &node)
{
    std::cout << nchars(' ', indentation_) << "EnumDecl" << std::endl;
    visit_children(node, *this);
}

void ASTPrintVisitor::visit(fparser::ast::Enumerator &node)
{
    std::cout << nchars(' ', indentation_) << "Enumerator" << std::endl;
    visit_children(node, *this);
}

void ASTPrintVisitor::visit(fparser::ast::FloatConstant &node)
{
    std::cout << nchars(' ', indentation_) << "FloatConstant" << std::endl;
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

void ASTPrintVisitor::increase_indent()
{
    indentation_ += indent_step_;
}

void ASTPrintVisitor::decrease_indent()
{
    if(indentation_ + indent_step_ >= 0)
    {
        indentation_ -= indent_step_;
    }
}

std::string ASTPrintVisitor::nchars(const char character, int num)
{
    std::string ret;
    ret.append(num, character);

    return ret;
}
