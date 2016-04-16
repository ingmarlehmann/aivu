#ifndef TYPE_H_J0ZN7XQD
#define TYPE_H_J0ZN7XQD

#include "ast_node.h"

namespace fparser
{
namespace ast
{
class Type : public ast::ASTNode
{
 public:
  virtual void accept(ASTNodeVisitor& visitor) override;
  virtual void render(std::ostream& ostream, int indent) override;

 public:
  Type(int id, const std::string& name);
  virtual ~Type();

 protected:
  virtual void render_with_offset(std::ostream& ostream, int indent, int offset) override;

 private:
  int id_;
  std::string name_;
};
}
}  // namespace fparser

#endif /* end of include guard: TYPE_H_J0ZN7XQD */
