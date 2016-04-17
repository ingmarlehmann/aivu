#include "ast/type.h"

#include <sstream>
#include "util/util.h"

namespace fparser
{
namespace ast
{
Type::Type(int id, const std::string& name) : id_(id), name_(name) {}
Type::~Type() {}

const std::string &Type::name() const
{
    return name_;
}

int Type::id() const
{
    return id_;
}

void Type::accept(ASTNodeVisitor& visitor) { visitor.visit(*this); }
} // namespace ast
} // namespace fparser
