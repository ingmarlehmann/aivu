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
  const std::string& name() const;
  int id() const;

 public:
  virtual void accept(ASTNodeVisitor& visitor) override;

 public:
  Type(int id, const std::string& name);
  virtual ~Type();

 private:
  int id_;
  std::string name_;
};
} // namespace ast
} // namespace fparser

#endif /* end of include guard: TYPE_H_J0ZN7XQD */
