#include "ast/method_decl.h"

namespace fparser
{
namespace ast
{
MethodDecl::MethodDecl(ASTNode* name, ASTNode* body, ASTNode* comment, bool fire_and_forget) : name_(name), body_(body), comment_(comment), is_fire_and_forget_(fire_and_forget) {}
MethodDecl::~MethodDecl() {}
ASTNode* MethodDecl::name() const { return name_; }
ASTNode* MethodDecl::body() const { return body_; }
ASTNode* MethodDecl::comment() const { return comment_; }
bool MethodDecl::fire_and_forget() const { return is_fire_and_forget_; }
void MethodDecl::accept(ASTNodeVisitor& visitor) { visitor.visit(*this); }
}  // namespace ast
}  // namespace fparser
