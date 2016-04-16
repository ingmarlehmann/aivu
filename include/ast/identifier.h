#ifndef IDENTIFIER_H_CN2ULECA
#define IDENTIFIER_H_CN2ULECA

#include "ast_node.h"
#include <string>

namespace fparser
{
namespace ast
{
class Identifier : public ast::ASTNode
{
 public:
  Identifier(const std::string& name);
  virtual ~Identifier();

 public:
  virtual void accept(ASTNodeVisitor& visitor) override;
  virtual void render(std::ostream& ostream, int indent) override;

 public:
  const std::string& name() const { return name_; }
 protected:
  virtual void render_with_offset(std::ostream& ostream, int indent, int offset) override;

 private:
  std::string name_;
};
}  // namespace ast
}  // namespace fparser

#endif /* end of include guard: IDENTIFIER_H_CN2ULECA */
