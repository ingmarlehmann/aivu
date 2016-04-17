#include "ast/double_constant.h"

#include <sstream>
#include "util/util.h"

namespace fparser
{
namespace ast
{
DoubleConstant::DoubleConstant(double value) : value_(value) {}
DoubleConstant::~DoubleConstant(){}
void DoubleConstant::accept(ASTNodeVisitor& visitor) { visitor.visit(*this); }
void DoubleConstant::render(std::ostream& ostream, int indent) { render_with_offset(ostream, indent, 0); }
void DoubleConstant::render_with_offset(std::ostream& ostream, int indent, int offset)
{
  std::stringstream ss;
  ss << ">" << util::spacex(offset) << "DoubleConstant (" << value_ << ")" << std::endl;
  ostream << ss.str();

  ASTNode::render_with_offset(ostream, indent, offset);
}
}
}
