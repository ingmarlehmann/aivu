#ifndef INT_CONSTANT_H_INBVYJET
#define INT_CONSTANT_H_INBVYJET

#include <ostream>
#include "ast/ast_node.h"

namespace fparser
{
namespace ast
{
class IntConstant : public ast::ASTNode
{
 public:
  IntConstant(int value);
  virtual ~IntConstant();

 public:
  virtual void accept(ASTNodeVisitor& visitor) override;
  virtual void render(std::ostream& ostream, int indent) override;

  virtual int value() const { return value_;  }

 protected:
  virtual void render_with_offset(std::ostream& ostream, int indent, int offset) override;

 private:
  int value_;
};
}
}  // namespace fparser

#endif /* end of include guard: INT_CONSTANT_H_INBVYJET */
