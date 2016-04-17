#ifndef VARIABLE_DECL_H_J0ZN7XQD
#define VARIABLE_DECL_H_J0ZN7XQD

#include "ast_node.h"

namespace fparser
{
namespace ast
{
class VariableDecl : public ast::ASTNode
{
 public:
  virtual void accept(ASTNodeVisitor& visitor) override;

 public:
  VariableDecl();
  virtual ~VariableDecl();
};
} // namespace ast
} // namespace fparser

#endif /* end of include guard: VARIABLE_DECL_H_J0ZN7XQD */
