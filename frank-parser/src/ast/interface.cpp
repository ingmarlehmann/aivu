#include "ast/interface.h"

namespace fparser
{
namespace ast
{
Interface::Interface()
{
}
Interface::~Interface(){}
void Interface::accept(ASTNodeVisitor& visitor) { visitor.visit(*this); }
} // namespace ast
} // namespace fparser
