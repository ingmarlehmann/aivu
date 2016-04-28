#ifndef IMPORT_DECL_H_YSIV19YX
#define IMPORT_DECL_H_YSIV19YX

#include "ast_node.h"
#include "ast_node_visitor.h"

#include <string>

namespace fparser
{
namespace ast
{
class ImportDecl : public ast::ASTNode
{
 public:
  const ASTNode& filename() const;
  const ASTNode* import_namespace() const;

 public:
  virtual void accept(ASTNodeVisitor& visitor) override;

public:
  ImportDecl(const ASTNode& filename, const ASTNode* import_namespace);
  virtual ~ImportDecl();

private:
  const ASTNode& filename_;
  const ASTNode* import_namespace_ = nullptr;
};
} // namespace ast
} // namespace fparser

#endif /* end of include guard: IMPORT_DECL_H_YSIV19YX */
