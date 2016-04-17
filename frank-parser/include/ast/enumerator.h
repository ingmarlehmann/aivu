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
};
} // namespace ast
} // namespace fparser

#endif /* end of include guard: ENUMERATOR_H_Q3WD4API */
