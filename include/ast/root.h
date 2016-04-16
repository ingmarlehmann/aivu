#ifndef ROOT_H_VTOUPZSA
#define ROOT_H_VTOUPZSA

#include "ast_node.h"

namespace fparser
{
namespace ast
{
class Root : public ast::ASTNode
{
 public:
  virtual void accept(ASTNodeVisitor& visitor) override;
  virtual void render(std::ostream& ostream, int indent) override;

 protected:
  virtual void render_with_offset(std::ostream& ostream, int indent, int offset) override;

 public:
  Root();
  virtual ~Root();
};
}
}  // namespace fparser

#endif /* end of include guard: ROOT_H_VTOUPZSA */
