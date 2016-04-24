#ifndef ENUM_DECL_H_FYAVVCMT
#define ENUM_DECL_H_FYAVVCMT

#include "ast_node.h"
#include <string>

namespace fparser
{
namespace ast
{
class EnumDecl : public ast::ASTNode
{
 public:
  const ASTNode& name() const;
  const ASTNode& children() const;
  const ASTNode* comment() const;

 public:
  virtual void accept(ASTNodeVisitor& visitor) override;

 public:
  EnumDecl(const ASTNode& name, const ASTNode& children, const ASTNode* comment);
  virtual ~EnumDecl();

 private:
  const ASTNode& name_;
  const ASTNode& children_;
  const ASTNode* comment_ = nullptr;
};
}  // namespace ast
}  // namespace fparser

#endif /* end of include guard: ENUM_DECL_H_FYAVVCMT */
