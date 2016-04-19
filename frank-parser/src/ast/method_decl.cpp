#include "ast/method_decl.h"

namespace fparser
{
namespace ast
{
MethodDecl::MethodDecl(ASTNode* name, ASTNode* body, ASTNode* comment) : name_(name), body_(body), comment_(comment) {}
MethodDecl::~MethodDecl() {}
ASTNode* MethodDecl::name() const { return name_; }
ASTNode* MethodDecl::body() const { return body_; }
ASTNode* MethodDecl::comment() const { return comment_; }
void MethodDecl::accept(ASTNodeVisitor& visitor) { visitor.visit(*this); }
}  // namespace ast
}  // namespace fparser
