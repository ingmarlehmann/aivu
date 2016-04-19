#ifndef INTERFACE_H_KFJUIGW5
#define INTERFACE_H_KFJUIGW5

#include "ast_node.h"
#include "ast_node_visitor.h"

namespace fparser
{
namespace ast
{
class Interface : public ast::ASTNode
{
 public:
  virtual void accept(ASTNodeVisitor& visitor) override;

public:
  Interface();
  virtual ~Interface();
};
} // namespace ast
} // namespace fparser

#endif /* end of include guard: INTERFACE_H_KFJUIGW5 */
