#include "ast/struct_decl.h"

namespace fparser
{
namespace ast
{
StructDecl::StructDecl(const ASTNode& name, const ASTNode& members, const ASTNode* comment) : name_(name), members_(members), comment_(comment) {}
StructDecl::~StructDecl() {}
const ASTNode& StructDecl::name() const { return name_; }
const ASTNode& StructDecl::members() const { return members_; }
const ASTNode* StructDecl::comment() const { return comment_; }
void StructDecl::accept(ASTNodeVisitor& visitor) { visitor.visit(*this); }
}  // namespace ast
}  // namespace fparser
