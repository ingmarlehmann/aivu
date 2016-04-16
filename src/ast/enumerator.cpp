#include "ast/enumerator.h"

#include <sstream>
#include "util/util.h"

namespace fparser
{
namespace ast
{
Enumerator::Enumerator() {}
Enumerator::~Enumerator() {}
void Enumerator::accept(ASTNodeVisitor& visitor) { visitor.visit(*this); }
void Enumerator::render(std::ostream& ostream, int indent) { render_with_offset(ostream, indent, 0); }
void Enumerator::render_with_offset(std::ostream& ostream, int indent, int offset)
{
  std::stringstream ss;
  ss << ">" << util::spacex(offset) << "Enumerator" << std::endl;
  ostream << ss.str();

  ASTNode::render_with_offset(ostream, indent, offset);
}
}
}
