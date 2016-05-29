#include "ast/array_variable_decl.h"

namespace fparser
{
namespace ast
{
ArrayVariableDecl::ArrayVariableDecl(const ASTNode& type, const ASTNode& name) : type_(type), name_(name) {}
ArrayVariableDecl::~ArrayVariableDecl() {}
const ASTNode& ArrayVariableDecl::type() const { return type_; }
const ASTNode& ArrayVariableDecl::name() const { return name_; }
void ArrayVariableDecl::accept(ASTNodeVisitor& visitor) { visitor.visit(*this); }
}  // namespace ast
}  // namespace fparser
