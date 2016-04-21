#ifndef METHOD_DECL_H_WSVLVKHR
#define METHOD_DECL_H_WSVLVKHR

#include "ast_node.h"
#include "ast_node_visitor.h"

#include <string>

namespace fparser
{
namespace ast
{
class MethodDecl : public ast::ASTNode
{
 public:
  ASTNode* name() const;
  ASTNode* body() const;
  ASTNode* comment() const;
  bool     fire_and_forget() const;

 public:
  virtual void accept(ASTNodeVisitor& visitor) override;

 public:
  MethodDecl(ASTNode* name, ASTNode* method_body, ASTNode* comment, bool fire_and_forget);
  virtual ~MethodDecl();

 private:
  ASTNode* name_ = nullptr;
  ASTNode* body_ = nullptr;
  ASTNode* comment_ = nullptr;
  bool     is_fire_and_forget_ = false;
};
}  // namespace ast
}  // namespace fparser

#endif /* end of include guard: METHOD_DECL_H_WSVLVKHR */
