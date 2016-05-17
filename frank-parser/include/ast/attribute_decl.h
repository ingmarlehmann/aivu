#ifndef ATTRIBUTE_DECL_H_UJKLAKMT
#define ATTRIBUTE_DECL_H_UJKLAKMT

#include "ast_node.h"
#include "ast_node_visitor.h"

#include <string>

namespace fparser
{
namespace ast
{
class AttributeDecl : public ast::ASTNode
{
 public:
  const ASTNode& type() const;
  const ASTNode& id() const;

 public:
  virtual void accept(ASTNodeVisitor& visitor) override;

 public:
  AttributeDecl(const ASTNode& type, const ASTNode& id);
  virtual ~AttributeDecl();

 private:
  const ASTNode& type_;
  const ASTNode& id_;
};
}  // namespace ast
}  // namespace fparser

#endif /* end of include guard: ATTRIBUTE_DECL_H_UJKLAKMT */
