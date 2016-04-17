#ifndef DOUBLE_CONSTANT_H_QJLIO4FK
#define DOUBLE_CONSTANT_H_QJLIO4FK

#include <ostream>
#include "ast/ast_node.h"

namespace fparser
{
namespace ast
{
class DoubleConstant : public ast::ASTNode
{
 public:
  DoubleConstant(double value);
  virtual ~DoubleConstant();

 public:
  virtual void accept(ASTNodeVisitor& visitor) override;
  virtual void render(std::ostream& ostream, int indent) override;

 protected:
  virtual void render_with_offset(std::ostream& ostream, int indent, int offset) override;

 private:
  double value_;
};
}
}  // namespace fparser

#endif /* end of include guard: DOUBLE_CONSTANT_H_QJLIO4FK */
