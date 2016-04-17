#include "ast/enumerator.h"

#include <sstream>
#include "util/util.h"

namespace fparser
{
namespace ast
{
Enumerator::Enumerator() {}
Enumerator::~Enumerator() {}
void Enumerator::accept(ASTNodeVisitor& visitor) { visitor.visit(*this); }
} // namespace ast
} // namespace fparser
