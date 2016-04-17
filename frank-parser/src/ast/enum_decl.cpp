#include "ast/enum_decl.h"

#include <sstream>
#include "util/util.h"

namespace fparser
{
namespace ast
{
EnumDecl::EnumDecl() {}
EnumDecl::~EnumDecl() {}
void EnumDecl::accept(ASTNodeVisitor& visitor) { visitor.visit(*this); }
} // namespace ast
} // namespace ast
