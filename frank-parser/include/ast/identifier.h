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
  const std::string& name() const;

 public:
  virtual void accept(ASTNodeVisitor& visitor) override;

 public:
   Identifier(const std::string& name);
   virtual ~Identifier();

 private:
  std::string name_;
};
} // namespace ast
} // namespace fparser

#endif /* end of include guard: IDENTIFIER_H_CN2ULECA */
