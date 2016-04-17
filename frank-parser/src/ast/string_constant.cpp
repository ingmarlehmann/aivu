#include "ast/string_constant.h"

#include <sstream>
#include "util/util.h"

namespace fparser
{
namespace ast
{
StringConstant::StringConstant(const std::string& value) : value_(value) {}
StringConstant::~StringConstant(){}
void StringConstant::accept(ASTNodeVisitor& visitor) { visitor.visit(*this); }

const std::string &StringConstant::value() const
{
    return value_;
}
} // namespace ast
} // namespace fparser
