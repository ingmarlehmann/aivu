#ifndef VERSION_H_SM2YXJKY
#define VERSION_H_SM2YXJKY

#include "ast_node.h"
#include "ast_node_visitor.h"

#include <string>

namespace fparser
{
namespace ast
{
class Version : public ast::ASTNode
{
 public:
  ast::IntConstant& major() const;
  ast::IntConstant& minor() const;

 public:
  virtual void accept(ASTNodeVisitor& visitor) override;

 public:
  Version(ast::IntConstant& major, ast::IntConstant& minor);
  virtual ~Version();

 private:
  ast::IntConstant& major_;
  ast::IntConstant& minor_;
};
}  // namespace ast
}  // namespace fparser

#endif /* end of include guard: VERSION_H_SM2YXJKY */
