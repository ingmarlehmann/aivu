#include "ast/float_constant.h"

#include <sstream>
#include "util/util.h"

namespace fparser
{
namespace ast
{
FloatConstant::FloatConstant(float value) : value_(value) {}
FloatConstant::~FloatConstant(){}
void FloatConstant::accept(ASTNodeVisitor& visitor) { visitor.visit(*this); }
void FloatConstant::render(std::ostream& ostream, int indent) { render_with_offset(ostream, indent, 0); }
void FloatConstant::render_with_offset(std::ostream& ostream, int indent, int offset)
{
  std::stringstream ss;
  ss << ">" << util::spacex(offset) << "FloatConstant (" << value_ << ")" << std::endl;
  ostream << ss.str();

  ASTNode::render_with_offset(ostream, indent, offset);
}
}
}
