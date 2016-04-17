#include "ast/variable_decl.h"

#include <sstream>
#include "util/util.h"

namespace fparser
{
namespace ast
{
VariableDecl::VariableDecl() {}
VariableDecl::~VariableDecl() {}
void VariableDecl::accept(ASTNodeVisitor& visitor) { visitor.visit(*this); }
void VariableDecl::render(std::ostream& ostream, int indent) { render_with_offset(ostream, indent, 0); }
void VariableDecl::render_with_offset(std::ostream& ostream, int indent, int offset)
{
  std::stringstream ss;
  ss << ">" << util::spacex(offset) << "VariableDecl" << std::endl;
  ostream << ss.str();

  ASTNode::render_with_offset(ostream, indent, offset);
}
}
}
