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
  const std::string& value() const;
  
 public:
  virtual void accept(ASTNodeVisitor& visitor) override;
 
 public:
  StringConstant(const std::string& value);
  virtual ~StringConstant();

 private:
  std::string value_;
};
} // namespace ast
} // namespace fparser

#endif /* end of include guard: STRING_CONSTANT_H_SDTMHX1I */
