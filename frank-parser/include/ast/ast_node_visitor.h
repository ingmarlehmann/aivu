#ifndef AST_NODE_VISITOR_H_YMA0QY4V
#define AST_NODE_VISITOR_H_YMA0QY4V

namespace fparser
{
namespace ast
{
class ASTNodeList;
class BroadcastMethodDecl;
class DoubleConstant;
class EnumDecl;
class Enumerator;
class FloatConstant;
class FrancaComment;
class Identifier;
class ImplicitArrayDecl;
class ImportDecl;
class IntConstant;
class Interface;
class MethodArgument;
class MethodBody;
class MethodDecl;
class PackageName;
class Root;
class StringConstant;
class StructDecl;
class Type;
class VariableDecl;
class Version;

class ASTNodeVisitor
{
 public:
  virtual void visit(ast::ASTNodeList&         node)  = 0;
  virtual void visit(ast::BroadcastMethodDecl& node)  = 0;
  virtual void visit(ast::DoubleConstant&      node)  = 0;
  virtual void visit(ast::EnumDecl&            node)  = 0;
  virtual void visit(ast::Enumerator&          node)  = 0;
  virtual void visit(ast::FloatConstant&       node)  = 0;
  virtual void visit(ast::FrancaComment&       node)  = 0;
  virtual void visit(ast::Identifier&          node)  = 0;
  virtual void visit(ast::ImplicitArrayDecl&   node)  = 0;
  virtual void visit(ast::ImportDecl&          node)  = 0;
  virtual void visit(ast::IntConstant&         node)  = 0;
  virtual void visit(ast::Interface&           node)  = 0;
  virtual void visit(ast::MethodArgument&      node)  = 0;
  virtual void visit(ast::MethodBody&          node)  = 0;
  virtual void visit(ast::MethodDecl&          node)  = 0;
  virtual void visit(ast::PackageName&         node)  = 0;
  virtual void visit(ast::Root&                node)  = 0;
  virtual void visit(ast::StringConstant&      node)  = 0;
  virtual void visit(ast::StructDecl&          node)  = 0;
  virtual void visit(ast::Type&                node)  = 0;
  virtual void visit(ast::VariableDecl&        node)  = 0;
  virtual void visit(ast::Version&             node)  = 0;

  virtual ~ASTNodeVisitor() { }
};
} // namespace ast
} // namespace fparser

#endif /* end of include guard: AST_NODE_VISITOR_H_YMA0QY4V */
