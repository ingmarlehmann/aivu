#include "util/util.h"

#include <string>

namespace fparser
{
namespace util
{
std::string spacex(int num_spaces)
{
  std::string result;
  result.append(num_spaces, ' ');

  return result;
}

std::string dashx(int num_dashes)
{
  std::string result;
  result.append(num_dashes, '-');

  return result;
}
}
}
