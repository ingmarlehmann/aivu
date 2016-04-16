#include "ast/root.h"

#include <iostream>
#include "util/util.h"

namespace fparser
{
namespace ast
{
Root::Root() {}
Root::~Root() {}
void Root::accept(ASTNodeVisitor& visitor) { visitor.visit(*this); }
void Root::render(std::ostream& ostream, int indent) { render_with_offset(ostream, indent, 0); }
void Root::render_with_offset(std::ostream& ostream, int indent, int offset)
{
  ostream << ">" << util::spacex(offset) << "Root" << std::endl;
  ASTNode::render_with_offset(ostream, indent, offset);
}
}
}
