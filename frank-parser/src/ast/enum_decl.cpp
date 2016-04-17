#include "ast/enum_decl.h"

#include <sstream>
#include "util/util.h"

namespace fparser
{
namespace ast
{
EnumDecl::EnumDecl() {}
EnumDecl::~EnumDecl() {}
void EnumDecl::accept(ASTNodeVisitor& visitor) { visitor.visit(*this); }
void EnumDecl::render(std::ostream& ostream, int indent) { render_with_offset(ostream, indent, 0); }
void EnumDecl::render_with_offset(std::ostream& ostream, int indent, int offset)
{
  std::stringstream ss;
  ss << ">" << util::spacex(offset) << "EnumDecl" << std::endl;
  ostream << ss.str();

  ASTNode::render_with_offset(ostream, indent, offset);
}
}  // namespace ast
}
