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

 public:
  int value() const;

 private:
  int value_;
};
}
}  // namespace fparser

#endif /* end of include guard: INT_CONSTANT_H_INBVYJET */
