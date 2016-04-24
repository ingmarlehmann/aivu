#include "ast/enum_decl.h"

#include <sstream>
#include "util/util.h"

namespace fparser
{
namespace ast
{
EnumDecl::EnumDecl(const ASTNode& name, const ASTNode& children, const ASTNode* comment) : name_(name), children_(children), comment_(comment) {}
EnumDecl::~EnumDecl() {}
const ASTNode& EnumDecl::name() const { return name_; }
const ASTNode& EnumDecl::children() const { return children_; }
const ASTNode* EnumDecl::comment() const { return comment_; }
void EnumDecl::accept(ASTNodeVisitor& visitor) { visitor.visit(*this); }
}  // namespace ast
}  // namespace ast
