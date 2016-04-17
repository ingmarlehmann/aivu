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
int IntConstant::value() const { return value_;  }
} // namespace ast
} // namespace fparser
