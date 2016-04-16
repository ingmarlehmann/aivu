#include "ast/type.h"

#include <sstream>
#include "util/util.h"

namespace fparser
{
namespace ast
{
Type::Type(int id, const std::string& name) : id_(id), name_(name) {}
Type::~Type() {}
void Type::accept(ASTNodeVisitor& visitor) { visitor.visit(*this); }
void Type::render(std::ostream& ostream, int indent) { render_with_offset(ostream, indent, 0); }
void Type::render_with_offset(std::ostream& ostream, int indent, int offset)
{
  std::stringstream ss;
  ss << ">" << util::spacex(offset) << "Type (" << (name_.empty() ? "\"\"" : name_) << ")" << std::endl;
  ostream << ss.str();

  ASTNode::render_with_offset(ostream, indent, offset);
}
}
}
