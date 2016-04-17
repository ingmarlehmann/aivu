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
  virtual std::vector<ASTNode::NodePtr_t>& children();
  
  virtual void render(std::ostream& ostream, int indent) override;
  virtual void accept(ASTNodeVisitor& visitor) override;

 public:
  ASTNodeList();
  virtual ~ASTNodeList();

 protected:
  virtual void render_with_offset(std::ostream& ostream, int indent, int offset) override;

 protected:
  ASTNodeList(const ASTNodeList&) = delete;
  ASTNodeList(ASTNodeList&&) = delete;
};
}
}  // namespace fparser

#endif /* end of include guard: AST_NODE_LIST_H_NQEHW9IJ */
