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

 private:
  float value_;
};
} // namespace ast
} // namespace fparser

#endif /* end of include guard: FLOAT_CONSTANT_H_8IQK3PF4 */
