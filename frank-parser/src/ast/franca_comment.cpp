#include "ast/franca_comment.h"

namespace fparser
{
namespace ast
{
FrancaComment::FrancaComment(const std::string& comment) : comment_(comment) {}
FrancaComment::~FrancaComment() {}
void FrancaComment::accept(ASTNodeVisitor& visitor) { visitor.visit(*this); }
const std::string& FrancaComment::comment() const { return comment_; }
}  // namespace ast
}  // namespace fparser
