#ifndef AST_PRINTER_H_2TARC9O7
#define AST_PRINTER_H_2TARC9O7

#include "ast/ast_node_visitor.h"
#include "ast/ast_node.h"

class ASTPrintVisitor : public fparser::ast::ASTNodeVisitor {
   public:
    virtual void visit(fparser::ast::ASTNodeList& node) override;
    virtual void visit(fparser::ast::DoubleConstant& node) override;
    virtual void visit(fparser::ast::EnumDecl& node) override;
    virtual void visit(fparser::ast::Enumerator& node) override;
    virtual void visit(fparser::ast::FloatConstant& node) override;
    virtual void visit(fparser::ast::Identifier& node) override;
    virtual void visit(fparser::ast::IntConstant& node) override;
    virtual void visit(fparser::ast::Root& node) override;
    virtual void visit(fparser::ast::StringConstant& node) override;
    virtual void visit(fparser::ast::Type& node) override;
    virtual void visit(fparser::ast::VariableDecl& node) override;

   private:
    void visit_children(fparser::ast::ASTNode& node, ASTPrintVisitor& visitor);
    void increase_indent();
    void decrease_indent();
    std::string nchars(const char character, int num);

    int indent_step_ = 2;
    int indentation_ = 0;
};

#endif /* end of include guard: AST_PRINTER_H_2TARC9O7 */
