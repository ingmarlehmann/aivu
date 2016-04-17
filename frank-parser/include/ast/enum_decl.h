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
  EnumDecl();
  virtual ~EnumDecl();

 public:
  virtual void accept(ASTNodeVisitor& visitor) override;
};
} // namespace ast
} // namespace fparser

#endif /* end of include guard: ENUM_DECL_H_FYAVVCMT */
