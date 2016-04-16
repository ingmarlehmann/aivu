#include "ast/ast_node.h"

namespace fparser
{
namespace ast
{
ASTNode::ASTNode() {}
ASTNode::ASTNode(const ASTNode&) {}
ASTNode::ASTNode(ASTNode&&) {}
ASTNode::~ASTNode()
{
  for (std::size_t i = 0; i < children_.size(); ++i)
  {
    delete children_[i];
  }
}

std::vector<ASTNode::NodePtr_t>& ASTNode::children() { return children_; }
void ASTNode::render(std::ostream& ostream, int indent) { render_with_offset(ostream, indent, 0); }
void ASTNode::render_with_offset(std::ostream& ostream, int indent, int offset)
{
  for (std::size_t i = 0; i < children_.size(); ++i)
  {
    children_[i]->render_with_offset(ostream, indent, offset + indent);
  }
}
}
}
