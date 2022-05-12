#ifndef __UTILS_H__
#define __UTILS_H__

#include <sstream>
#include <string>

namespace ft {

template <typename T>
std::string to_string(T value) {
  std::ostringstream os;

  os << value;
  return os.str();
}

}  // namespace ft

#endif  // __UTILS_H__
