
#include "ast/identifier.h"

#include <sstream>
#include "util/util.h"

namespace fparser
{
namespace ast
{
Identifier::Identifier(const std::string& name) : name_(name) {}
Identifier::~Identifier() {}
const std::string &Identifier::name() const { return name_; }

void Identifier::accept(ASTNodeVisitor& visitor) { visitor.visit(*this); }
} // namespace ast
} // namespace fparser
