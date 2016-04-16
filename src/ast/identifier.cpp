
#include "ast/identifier.h"

#include <sstream>
#include "util/util.h"

namespace fparser
{
namespace ast
{
Identifier::Identifier(const std::string& name) : name_(name) {}
Identifier::~Identifier() {}
void Identifier::accept(ASTNodeVisitor& visitor) { visitor.visit(*this); }
void Identifier::render(std::ostream& ostream, int indent) { render_with_offset(ostream, indent, 0); }
void Identifier::render_with_offset(std::ostream& ostream, int indent, int offset)
{
  std::stringstream ss;
  ss << ">" << util::spacex(offset) << "Identifier (name:" << name_ << ")" << std::endl;
  ostream << ss.str();

  ASTNode::render_with_offset(ostream, indent, offset);
}
}  // namespace ast
}
