#ifndef METHOD_ARGUMENT_H_VCZAR2ZT
#define METHOD_ARGUMENT_H_VCZAR2ZT

#include "ast_node.h"
#include "ast_node_visitor.h"

#include <string>

namespace fparser
{
namespace ast
{
class MethodArgument : public ast::ASTNode
{
 public:
  virtual void accept(ASTNodeVisitor& visitor) override;

public:
  MethodArgument();
  virtual ~MethodArgument();
};
} // namespace ast
} // namespace fparser

#endif /* end of include guard: METHOD_ARGUMENT_H_VCZAR2ZT */
