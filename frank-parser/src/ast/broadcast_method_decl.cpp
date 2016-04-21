#include "ast/broadcast_method_decl.h"

namespace fparser
{
namespace ast
{
BroadcastMethodDecl::BroadcastMethodDecl(ASTNode* name, ASTNode* body, ASTNode* comment, bool is_selective)
    : name_(name), body_(body), comment_(comment), is_selective_(is_selective)
{
}
ASTNode* BroadcastMethodDecl::name() const { return name_; }
ASTNode* BroadcastMethodDecl::body() const { return body_; }
ASTNode* BroadcastMethodDecl::comment() const { return comment_; }
bool BroadcastMethodDecl::is_selective() const { return is_selective_; }
BroadcastMethodDecl::~BroadcastMethodDecl() {}
void BroadcastMethodDecl::accept(ASTNodeVisitor& visitor) { visitor.visit(*this); }
}  // namespace ast
}  // namespace fparser
