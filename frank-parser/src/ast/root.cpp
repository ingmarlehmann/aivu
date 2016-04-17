#include "ast/root.h"

#include <iostream>
#include "util/util.h"

namespace fparser
{
namespace ast
{
Root::Root() {}
Root::~Root() {}
void Root::accept(ASTNodeVisitor& visitor) { visitor.visit(*this); }
} // namespace ast
} // namespace fparser
