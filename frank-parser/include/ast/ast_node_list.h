#ifndef AST_NODE_LIST_H_NQEHW9IJ
#define AST_NODE_LIST_H_NQEHW9IJ

#include <memory>
#include <vector>
#include "ast_node.h"

namespace fparser
{
namespace ast
{
class ASTNodeList : public ASTNode
{
 public:
  virtual void accept(ASTNodeVisitor& visitor) override;

 public:
  ASTNodeList();
  virtual ~ASTNodeList();

 protected:
  ASTNodeList(const ASTNodeList&) = delete;
  ASTNodeList(ASTNodeList&&) = delete;
};
} // namespace ast
} // namespace fparser

#endif /* end of include guard: AST_NODE_LIST_H_NQEHW9IJ */
