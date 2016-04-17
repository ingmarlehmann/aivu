#include "ast/string_constant.h"

#include <sstream>
#include "util/util.h"

namespace fparser
{
namespace ast
{
StringConstant::StringConstant(const std::string& value) : value_(value) {}
StringConstant::~StringConstant(){}
void StringConstant::accept(ASTNodeVisitor& visitor) { visitor.visit(*this); }
void StringConstant::render(std::ostream& ostream, int indent) { render_with_offset(ostream, indent, 0); }
void StringConstant::render_with_offset(std::ostream& ostream, int indent, int offset)
{
  std::stringstream ss;
  ss << ">" << util::spacex(offset) << "StringConstant (" << value_ << ")" << std::endl;
  ostream << ss.str();

  ASTNode::render_with_offset(ostream, indent, offset);
}
}
}
