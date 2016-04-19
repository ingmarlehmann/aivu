#include "ast/method_body.h"

namespace fparser
{
namespace ast
{
MethodBody::MethodBody(ASTNode* in_args, ASTNode* out_args) : in_args_(in_args), out_args_(out_args)
{
}
MethodBody::~MethodBody(){}
ASTNode* MethodBody::in_args() const { return in_args_; }
ASTNode* MethodBody::out_args() const { return out_args_; }
void MethodBody::accept(ASTNodeVisitor& visitor) { visitor.visit(*this); }
} // namespace ast
} // namespace fparser
