#ifndef BROADCAST_METHOD_H_5ZD6QIYO
#define BROADCAST_METHOD_H_5ZD6QIYO

#include "ast_node.h"
#include "ast_node_visitor.h"

#include <string>

namespace fparser
{
namespace ast
{
class BroadcastMethodDecl : public ast::ASTNode
{
 public:
  const ASTNode& name() const;
  const ASTNode& body() const;
  const ASTNode* comment() const;
  bool is_selective() const;

 public:
  virtual void accept(ASTNodeVisitor& visitor) override;

 public:
  BroadcastMethodDecl(const ASTNode& name, const ASTNode& body, const ASTNode* comment, bool is_selective);
  virtual ~BroadcastMethodDecl();

 private:
  const ASTNode& name_;
  const ASTNode& body_;
  const ASTNode* comment_ = nullptr;
  bool is_selective_ = false;
};
}  // namespace ast
}  // namespace fparser

#endif /* end of include guard: BROADCAST_METHOD_H_5ZD6QIYO */
