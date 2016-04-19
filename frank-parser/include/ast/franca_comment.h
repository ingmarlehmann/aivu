#ifndef FRANCA_COMMENT_H_8TQ67JCO
#define FRANCA_COMMENT_H_8TQ67JCO

#include "ast_node.h"
#include "ast_node_visitor.h"

#include <string>

namespace fparser
{
namespace ast
{
class FrancaComment : public ast::ASTNode
{
 public:
  const std::string& comment() const;

 public:
  virtual void accept(ASTNodeVisitor& visitor) override;

 public:
  FrancaComment(const std::string& comment);
  virtual ~FrancaComment();

 private:
  std::string comment_;
};
}  // namespace ast
}  // namespace fparser

#endif /* end of include guard: FRANCA_COMMENT_H_8TQ67JCO */
