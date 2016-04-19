
#include "ast/broadcast_method.h"

namespace fparser
{
namespace ast
{
BroadcastMethod::BroadcastMethod(ASTNode* name, ASTNode* body, ASTNode* comment, bool is_selective)
    : name_(name), body_(body), comment_(comment), is_selective_(is_selective)
{
}
ASTNode* BroadcastMethod::name() const { return name_; }
ASTNode* BroadcastMethod::body() const { return body_; }
ASTNode* BroadcastMethod::comment() const { return comment_; }
bool BroadcastMethod::is_selective() const { return is_selective_; }
BroadcastMethod::~BroadcastMethod() {}
void BroadcastMethod::accept(ASTNodeVisitor& visitor) { visitor.visit(*this); }
}  // namespace ast
}  // namespace fparser
