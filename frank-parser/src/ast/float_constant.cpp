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
} // namespace ast
} // namespace fparser
