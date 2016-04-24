#include "ast/implicit_array_decl.h"

namespace fparser
{
namespace ast
{
ImplicitArrayDecl::ImplicitArrayDecl(const ASTNode& type, const ASTNode& name) : type_(type), name_(name) {}
ImplicitArrayDecl::~ImplicitArrayDecl() {}
const ASTNode& ImplicitArrayDecl::type() const { return type_; }
const ASTNode& ImplicitArrayDecl::name() const { return name_; }
void ImplicitArrayDecl::accept(ASTNodeVisitor& visitor) { visitor.visit(*this); }
}  // namespace ast
}  // namespace fparser
