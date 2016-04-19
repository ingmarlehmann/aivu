#ifndef AST_NODE_VISITOR_H_YMA0QY4V
#define AST_NODE_VISITOR_H_YMA0QY4V

namespace fparser
{
namespace ast
{
class ASTNodeList;
class BroadcastMethod;
class DoubleConstant;
class EnumDecl;
class Enumerator;
class FloatConstant;
class FrancaComment;
class Identifier;
class IntConstant;
class Interface;
class MethodArgument;
class MethodBody;
class MethodDecl;
class PackageName;
class Root;
class StringConstant;
class Type;
class VariableDecl;
class Version;

class ASTNodeVisitor
{
 public:
  virtual void visit(ast::ASTNodeList& node)    { (void)node; }
  virtual void visit(ast::BroadcastMethod& node){ (void)node; }
  virtual void visit(ast::DoubleConstant& node) { (void)node; }
  virtual void visit(ast::EnumDecl& node)       { (void)node; }
  virtual void visit(ast::Enumerator& node)     { (void)node; }
  virtual void visit(ast::FloatConstant& node)  { (void)node; }
  virtual void visit(ast::FrancaComment& node)  { (void)node; }
  virtual void visit(ast::Identifier& node)     { (void)node; }
  virtual void visit(ast::IntConstant& node)    { (void)node; }
  virtual void visit(ast::Interface& node)      { (void)node; }
  virtual void visit(ast::MethodArgument& node) { (void)node; }
  virtual void visit(ast::MethodBody& node)     { (void)node; }
  virtual void visit(ast::MethodDecl& node)     { (void)node; }
  virtual void visit(ast::PackageName& node)    { (void)node; }
  virtual void visit(ast::Root& node)           { (void)node; }
  virtual void visit(ast::StringConstant& node) { (void)node; }
  virtual void visit(ast::Type& node)           { (void)node; }
  virtual void visit(ast::VariableDecl& node)   { (void)node; }
  virtual void visit(ast::Version& node)        { (void)node; }

  virtual ~ASTNodeVisitor() { }
};
} // namespace ast
} // namespace fparser

#endif /* end of include guard: AST_NODE_VISITOR_H_YMA0QY4V */
