#ifndef FLOAT_CONSTANT_H_8IQK3PF4
#define FLOAT_CONSTANT_H_8IQK3PF4

#include <ostream>
#include "ast/ast_node.h"

namespace fparser
{
namespace ast
{
class FloatConstant : public ast::ASTNode
{
 public:
  FloatConstant(float value);
  virtual ~FloatConstant();

 public:
  virtual void accept(ASTNodeVisitor& visitor) override;
  virtual void render(std::ostream& ostream, int indent) override;

 protected:
  virtual void render_with_offset(std::ostream& ostream, int indent, int offset) override;

 private:
  float value_;
};
}
}  // namespace fparser

#endif /* end of include guard: FLOAT_CONSTANT_H_8IQK3PF4 */
