#ifndef GENERAL_GENERAL_HPP
#define GENERAL_GENERAL_HPP

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

#endif  // GENERAL_GENERAL_HPP
