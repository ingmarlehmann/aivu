#include "ast/double_constant.h"

#include <sstream>
#include "util/util.h"

namespace fparser
{
namespace ast
{
DoubleConstant::DoubleConstant(double value) : value_(value) {}
DoubleConstant::~DoubleConstant(){}
double DoubleConstant::value() const { return value_; }
void DoubleConstant::accept(ASTNodeVisitor& visitor) { visitor.visit(*this); }
} // namespace ast
} // namespace fparser
