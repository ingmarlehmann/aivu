#include "ast/package_name.h"

namespace fparser
{
namespace ast
{
PackageName::PackageName(const std::string& package_name) : package_name_(package_name) {}
PackageName::~PackageName() {}
const std::string& PackageName::package_name() const { return package_name_; }
void PackageName::accept(ASTNodeVisitor& visitor) { visitor.visit(*this); }
}  // namespace ast
}  // namespace fparser
