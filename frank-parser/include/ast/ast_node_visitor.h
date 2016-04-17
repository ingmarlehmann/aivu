#ifndef AST_NODE_VISITOR_H_YMA0QY4V
#define AST_NODE_VISITOR_H_YMA0QY4V

namespace fparser
{
namespace ast
{
class ASTNodeList;
class DoubleConstant;
class EnumDecl;
class Enumerator;
class FloatConstant;
class Identifier;
class IntConstant;
class Root;
class StringConstant;
class Type;
class VariableDecl;

class ASTNodeVisitor
{
 public:
  virtual void visit(ast::ASTNodeList& node)    { (void)node; }
  virtual void visit(ast::DoubleConstant& node) { (void)node; }
  virtual void visit(ast::EnumDecl& node)       { (void)node; }
  virtual void visit(ast::Enumerator& node)     { (void)node; }
  virtual void visit(ast::FloatConstant& node)  { (void)node; }
  virtual void visit(ast::Identifier& node)     { (void)node; }
  virtual void visit(ast::IntConstant& node)    { (void)node; }
  virtual void visit(ast::Root& node)           { (void)node; }
  virtual void visit(ast::StringConstant& node) { (void)node; }
  virtual void visit(ast::Type& node)           { (void)node; }
  virtual void visit(ast::VariableDecl& node)   { (void)node; }

  virtual ~ASTNodeVisitor() { }
};
} // namespace ast
} // namespace fparser

#endif /* end of include guard: AST_NODE_VISITOR_H_YMA0QY4V */
