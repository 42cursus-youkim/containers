#include <iostream>

#include "../../src/utils/pair/pair.hpp"

using std::cout;
using std::string;

int main() {
  ft::pair<int, string> p1(1, "heello");

  cout << p1.first << " " << p1.second << "\n";
}
