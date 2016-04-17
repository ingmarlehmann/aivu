#ifndef AST_NODE_HXX_NQEHW9IJ
#define AST_NODE_HXX_NQEHW9IJ

#include <memory>
#include <vector>

#include "ast_node_visitor.h"

namespace fparser
{
namespace ast
{
class ASTNode
{
 public:
  typedef ast::ASTNode* NodePtr_t;

 public:
  virtual void accept(ASTNodeVisitor& visitor) = 0;

 public:
  virtual std::vector<NodePtr_t>& children();
  virtual bool has_children() const;

 public:
  virtual ~ASTNode();

 protected:
  ASTNode();
  ASTNode(const ASTNode&);
  ASTNode(ASTNode&&);

 protected:
  std::vector<NodePtr_t> children_;
};
}  // namespace ast
}  // namespace fparser

#endif /* end of include guard: AST_NODE_HXX_NQEHW9IJ */
