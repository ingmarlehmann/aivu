#include "ast/import_decl.h"

namespace fparser
{
namespace ast
{
ImportDecl::ImportDecl(const ASTNode& filename, const ASTNode* import_namespace) : filename_(filename), import_namespace_(import_namespace)
{
}
const ASTNode& ImportDecl::filename() const { return filename_; }
const ASTNode* ImportDecl::import_namespace() const { return import_namespace_; }
ImportDecl::~ImportDecl(){}
void ImportDecl::accept(ASTNodeVisitor& visitor) { visitor.visit(*this); }
} // namespace ast
} // namespace fparser
