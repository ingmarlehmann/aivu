#include "ast/version.h"
#include "ast/int_constant.h"

namespace fparser
{
namespace ast
{
Version::Version(ast::IntConstant& major, ast::IntConstant& minor) : major_(major), minor_(minor)
{
}
Version::~Version(){}

ast::IntConstant& Version::major() const { return major_;  }
ast::IntConstant& Version::minor() const { return minor_;  }
void Version::accept(ASTNodeVisitor& visitor) { visitor.visit(*this); }
} // namespace ast
} // namespace fparser
