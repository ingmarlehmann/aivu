#include "ast/variable_decl.h"

#include <sstream>
#include "util/util.h"

namespace fparser
{
namespace ast
{
VariableDecl::VariableDecl() {}
VariableDecl::~VariableDecl() {}
void VariableDecl::accept(ASTNodeVisitor& visitor) { visitor.visit(*this); }
} // namespace ast
} // namespace fparser
