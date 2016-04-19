#ifndef BROADCAST_METHOD_H_5ZD6QIYO
#define BROADCAST_METHOD_H_5ZD6QIYO

#include "ast_node.h"
#include "ast_node_visitor.h"

#include <string>

namespace fparser
{
namespace ast
{
class BroadcastMethod : public ast::ASTNode
{
 public:
  ASTNode* name() const;
  ASTNode* body() const;
  ASTNode* comment() const;
  bool is_selective() const;

 public:
  virtual void accept(ASTNodeVisitor& visitor) override;

public:
  BroadcastMethod(ASTNode* name, ASTNode* body, ASTNode* comment, bool is_selective);
  virtual ~BroadcastMethod();

private:
  ASTNode* name_;
  ASTNode* body_;
  ASTNode* comment_;
  bool is_selective_;
};
} // namespace ast
} // namespace fparser


#endif /* end of include guard: BROADCAST_METHOD_H_5ZD6QIYO */
