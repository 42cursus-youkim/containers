#include "test.hpp"

#include <iostream>
#include <string>

using std::string;

int main() {
#ifdef DO_STD
  std::cout << "This program is on DO_STD" << std::endl;
#else
  std::cout << "This program is on FT" << std::endl;
#endif

  typedef NS::vector<string> vecStr;
  vecStr                     vec(1, "4");

  vec.push_back("abababab");
  vec.push_back("bye");
  vec.push_back("elllo");
  std::cout << vec.begin()->c_str() << '\n';
  vecStr::const_iterator cit = vec.end();
  cit--;
  vecStr::const_reverse_iterator crit = vec.rbegin();

  std::cout << (cit->capacity() == (crit++)->capacity()) << '\n';
  std::cout << (cit->get_allocator() == (*crit).get_allocator())
            << '\n';
  std::cout << *cit << " " << *crit << '\n';

  mandatory(0);
  return (0);
}
