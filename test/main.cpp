#include <iostream>

#include "../../src/utils/pair/pair.hpp"

using std::cout;
using std::string;

int main() {
  ft::pair<int, string> p1 = ft::make_pair(1, "heello");

  cout << p1.first << " " << p1.second << "\n";

  ft::pair<string, double> product1;                    // default constructor
  ft::pair<string, double> product2("tomatoes", 2.30);  // value init
  ft::pair<string, double> product3(product2);          // copy constructor

  product1 = ft::make_pair(string("lightbulbs"),
                           0.99);  // using make_pair (move)

  product2.first = "shoes";  // the type of first is string
  product2.second = 39.90;   // the type of second is double

  cout << "The price of " << product1.first << " is $" << product1.second
       << '\n';
  cout << "The price of " << product2.first << " is $" << product2.second
       << '\n';
  cout << "The price of " << product3.first << " is $" << product3.second
       << '\n';
  return 0;
}
