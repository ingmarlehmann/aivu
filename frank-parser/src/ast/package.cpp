#include "ast/package.h"

namespace fparser
{
namespace ast
{
Package::Package(const std::string& package_name) : package_name_(package_name) {}
Package::~Package() {}
const std::string& Package::package_name() const { return package_name_; }
void Package::accept(ASTNodeVisitor& visitor) { visitor.visit(*this); }
}  // namespace ast
}  // namespace fparser
