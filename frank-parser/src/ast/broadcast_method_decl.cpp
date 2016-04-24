#include "ast/broadcast_method_decl.h"

namespace fparser
{
namespace ast
{
BroadcastMethodDecl::BroadcastMethodDecl(const ASTNode& name, const ASTNode& body, const ASTNode* comment, bool is_selective)
    : name_(name), body_(body), comment_(comment), is_selective_(is_selective)
{
}
const ASTNode& BroadcastMethodDecl::name() const { return name_; }
const ASTNode& BroadcastMethodDecl::body() const { return body_; }
const ASTNode* BroadcastMethodDecl::comment() const { return comment_; }
bool BroadcastMethodDecl::is_selective() const { return is_selective_; }
BroadcastMethodDecl::~BroadcastMethodDecl() {}
void BroadcastMethodDecl::accept(ASTNodeVisitor& visitor) { visitor.visit(*this); }
}  // namespace ast
}  // namespace fparser
