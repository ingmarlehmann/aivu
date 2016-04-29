#ifndef PACKAGE_NAME_H_DHGWATRE
#define PACKAGE_NAME_H_DHGWATRE

#include "ast_node.h"
#include "ast_node_visitor.h"
#include <string>

namespace fparser
{
namespace ast
{
class Package : public ast::ASTNode
{
 public:
  const std::string& package_name() const;

 public:
  virtual void accept(ASTNodeVisitor& visitor) override;

public:
  Package(const std::string& package_name);
  virtual ~Package();

private:
  std::string package_name_; 
  
};
} // namespace ast
} // namespace fparser

#endif /* end of include guard: PACKAGE_NAME_H_DHGWATRE */
