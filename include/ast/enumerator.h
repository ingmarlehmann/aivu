#ifndef ENUMERATOR_H_Q3WD4API
#define ENUMERATOR_H_Q3WD4API

#include "ast_node.h"
#include <string>

namespace fparser
{
namespace ast
{
class Enumerator : public ast::ASTNode
{
 public:
  Enumerator();
  virtual ~Enumerator();

 public:
  virtual void accept(ASTNodeVisitor& visitor) override;
  virtual void render(std::ostream& ostream, int indent) override;

 protected:
  virtual void render_with_offset(std::ostream& ostream, int indent, int offset) override;
};
}
}  // namespace fparser

#endif /* end of include guard: ENUMERATOR_H_Q3WD4API */
