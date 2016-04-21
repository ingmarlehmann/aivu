#ifndef METHOD_BODY_H_1LWC2ASS
#define METHOD_BODY_H_1LWC2ASS

#include "ast_node.h"
#include "ast_node_visitor.h"

#include <string>

namespace fparser
{
namespace ast
{
class MethodBody : public ast::ASTNode
{
 public:
  ASTNode* in_args() const;
  ASTNode* out_args() const;

 public:
  virtual void accept(ASTNodeVisitor& visitor) override;

 public:
  MethodBody(ASTNode* in_args, ASTNode* out_args);
  virtual ~MethodBody();

 private:
  ASTNode* in_args_ = nullptr;
  ASTNode* out_args_ = nullptr;
};
}  // namespace ast
}  // namespace fparser

#endif /* end of include guard: METHOD_BODY_H_1LWC2ASS */
