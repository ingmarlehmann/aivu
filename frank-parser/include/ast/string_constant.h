#ifndef STRING_CONSTANT_H_SDTMHX1I
#define STRING_CONSTANT_H_SDTMHX1I

#include <ostream>
#include <string>
#include "ast/ast_node.h"

namespace fparser
{
namespace ast
{
class StringConstant : public ast::ASTNode
{
 public:
  StringConstant(const std::string& value);
  virtual ~StringConstant();

 public:
  virtual void accept(ASTNodeVisitor& visitor) override;
  virtual void render(std::ostream& ostream, int indent) override;

 protected:
  virtual void render_with_offset(std::ostream& ostream, int indent, int offset) override;

 private:
  std::string value_;
};
}
}  // namespace fparser

#endif /* end of include guard: STRING_CONSTANT_H_SDTMHX1I */
