#include "ast/attribute_decl.h"

namespace fparser
{
namespace ast
{
AttributeDecl::AttributeDecl(const ASTNode& type, const ASTNode& id) : type_(type), id_(id) {}
const ASTNode& AttributeDecl::type() const { return type_; }
const ASTNode& AttributeDecl::id() const { return id_; }
AttributeDecl::~AttributeDecl() {}
void AttributeDecl::accept(ASTNodeVisitor& visitor) { visitor.visit(*this); }
}  // namespace ast
}  // namespace fparser
