#include "ast/int_constant.h"

#include <sstream>
#include "util/util.h"

namespace fparser
{
namespace ast
{
IntConstant::IntConstant(int value) : value_(value) {}
IntConstant::~IntConstant(){}
void IntConstant::accept(ASTNodeVisitor& visitor) { visitor.visit(*this); }
void IntConstant::render(std::ostream& ostream, int indent) { render_with_offset(ostream, indent, 0); }
void IntConstant::render_with_offset(std::ostream& ostream, int indent, int offset)
{
  std::stringstream ss;
  ss << ">" << util::spacex(offset) << "IntConstant (value:" << value_ << ")" << std::endl;
  ostream << ss.str();

  ASTNode::render_with_offset(ostream, indent, offset);
}
}
}
