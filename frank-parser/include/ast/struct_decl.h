#ifndef STRUCT_DECL_H_JP6RD4TF
#define STRUCT_DECL_H_JP6RD4TF


#include "ast_node.h"
#include "ast_node_visitor.h"

#include <string>

namespace fparser
{
namespace ast
{
class StructDecl : public ast::ASTNode
{
 public:
  const ASTNode& name() const;
  const ASTNode& members() const;
  const ASTNode* comment() const;

 public:
  virtual void accept(ASTNodeVisitor& visitor) override;

public:
  StructDecl(const ASTNode& name, const ASTNode& members, const ASTNode* comment);
  virtual ~StructDecl();

private:
  const ASTNode& name_;
  const ASTNode& members_;
  const ASTNode* comment_ = nullptr;
};
} // namespace ast
} // namespace fparser

#endif /* end of include guard: STRUCT_DECL_H_JP6RD4TF */
