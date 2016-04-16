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
  virtual void render(std::ostream& ostream, int indent) override;

 public:
  VariableDecl();
  virtual ~VariableDecl();

 protected:
  virtual void render_with_offset(std::ostream& ostream, int indent, int offset) override;
};
}
}  // namespace fparser

#endif /* end of include guard: VARIABLE_DECL_H_J0ZN7XQD */
