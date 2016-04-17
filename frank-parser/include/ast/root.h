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

 public:
  Root();
  virtual ~Root();
};
} // namespace ast
} // namespace fparser

#endif /* end of include guard: ROOT_H_VTOUPZSA */
