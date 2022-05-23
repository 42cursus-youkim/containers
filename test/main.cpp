// #include <stdlib.h>
// #include "test.hpp"

#include <iostream>
#include <string>
// #include <vector>
#include "vector.hpp"
#define NS ft

using std::string;

int main() {
  typedef NS::vector<string> vecStr;
  {
    vecStr vec(1, "4");

    // vec.push_back("abababab");
    // vec.push_back("bye");
    // vec.push_back("elllo");
  }
  // std::cout << vec.begin()->c_str() << '\n';
  // vecStr::const_iterator cit = vec.end();
  // cit--;
  // vecStr::const_reverse_iterator crit = vec.rbegin();

  // std::cout << (cit->capacity() == (crit++)->capacity()) << '\n';
  // std::cout << (cit->get_allocator() == (*crit).get_allocator())
  //           << '\n';
  // std::cout << *cit << " " << *crit << '\n';
  while (1) {
  };
  return (0);
}
