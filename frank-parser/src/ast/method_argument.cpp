#include "ast/method_argument.h"

namespace fparser
{
namespace ast
{
MethodArgument::MethodArgument() {}
MethodArgument::~MethodArgument() {}
void MethodArgument::accept(ASTNodeVisitor& visitor) { visitor.visit(*this); }
} // namespace ast
} // namespace fparser
