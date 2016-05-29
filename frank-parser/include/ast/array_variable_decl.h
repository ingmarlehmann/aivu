#ifndef IMPLICIT_ARRAY_DECL_H_OAIFJVL7
#define IMPLICIT_ARRAY_DECL_H_OAIFJVL7

#include "ast_node.h"
#include "ast_node_visitor.h"

#include <string>

namespace fparser
{
namespace ast
{
class ArrayVariableDecl : public ast::ASTNode
{
 public:
  const ASTNode& type() const;
  const ASTNode& name() const;

 public:
  virtual void accept(ASTNodeVisitor& visitor) override;

public:
  ArrayVariableDecl(const ASTNode& type, const ASTNode& name);
  virtual ~ArrayVariableDecl();

private:
  const ASTNode& type_;
  const ASTNode& name_;
};
} // namespace ast
} // namespace fparser

#endif /* end of include guard: IMPLICIT_ARRAY_DECL_H_OAIFJVL7 */
