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
} // namespace ast
} // namespace fparser
