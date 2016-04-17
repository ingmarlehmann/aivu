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
  virtual void render(std::ostream& ostream, int indent) override;

 protected:
  virtual void render_with_offset(std::ostream& ostream, int indent, int offset) override;

};
} // namespace ast
}  // namespace fparser

#endif /* end of include guard: ENUM_DECL_H_FYAVVCMT */
