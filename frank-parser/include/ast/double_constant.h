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
  double value() const;

 public:
  virtual void accept(ASTNodeVisitor& visitor) override;
 
 public:
  DoubleConstant(double value);
  virtual ~DoubleConstant();

 private:
  double value_;
};
} // namespace ast
} // namespace fparser

#endif /* end of include guard: DOUBLE_CONSTANT_H_QJLIO4FK */
