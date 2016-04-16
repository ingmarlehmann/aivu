#include "ast/ast_node_list.h"

#include <ostream>
#include <vector>

#include "util/util.h"

namespace fparser
{
namespace ast
{
ASTNodeList::ASTNodeList() {}
ASTNodeList::~ASTNodeList() {}
void ASTNodeList::accept(ASTNodeVisitor& visitor) { visitor.visit(*this); }
std::vector<ASTNode::NodePtr_t>& ASTNodeList::children() { return children_; }
void ASTNodeList::render(std::ostream& ostream, int indent) { render_with_offset(ostream, indent, 0); }
void ASTNodeList::render_with_offset(std::ostream& ostream, int indent, int offset)
{
  ostream << ">" << util::spacex(offset) << "ASTNodeList(" << children_.size() << ")" << std::endl;
  ASTNode::render_with_offset(ostream, indent, offset);
}
}
}
