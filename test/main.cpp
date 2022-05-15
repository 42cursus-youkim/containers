
// #include "../../src/utils/pair/pair.hpp"
// #include "../../src/utils/tmp/is_integral.hpp"

// int main() {
//   ft::pair<int, string> p1 = ft::make_pair(1, "heello");

//   cout << p1.first << " " << p1.second << "\n";

//   ft::pair<string, double> product1;                    // default
//   constructor ft::pair<string, double> product2("tomatoes", 2.30);  // value
//   init ft::pair<string, double> product3(product2);          // copy
//   constructor

//   product1 = ft::make_pair(string("lightbulbs"),
//                            0.99);  // using make_pair (move)

//   product2.first = "shoes";  // the type of first is string
//   product2.second = 39.90;   // the type of second is double

//   cout << "The price of " << product1.first << " is $" << product1.second
//        << '\n';
//   cout << "The price of " << product2.first << " is $" << product2.second
//        << '\n';
//   cout << "The price of " << product3.first << " is $" << product3.second
//        << '\n';

//   {
//     unsigned int val1 = 1;
//     string val2 = "hello";
//     cout << ft::is_integral<val1> << " " << ft::is_integral(val2) << '\n';
//   }
//   return 0;
// }
#include <iostream>
#include <memory>
#include <pair/pair.hpp>
#include <tmp/integral_constant.hpp>
#include <tmp/is_integral.hpp>
#include <vector/vector.hpp>
#include "test/pair.hpp"
#include "util.hpp"

using std::cout;
using std::string;
template <unsigned n>
struct factorial : ft::integral_constant<int, n * factorial<n - 1>::value> {};

template <>
struct factorial<0> : ft::integral_constant<int, 1> {};

int main() {
  ft::vector<string> v;
  v.push_back("hello");
  v.push_back("world");
  v.push_back("bye");
  for (ft::vector<string>::iterator it = v.begin(); it != v.end(); ++it) {
    cout << *it << ", ";
  }
  cout << '\n';
  v.pop_back();
  for (ft::vector<string>::iterator it = v.begin(); it != v.end(); ++it) {
    cout << *it << ", ";
  }
  cout << '\n';
  ft::vector<string> v1, v2;
  cout << "v1 == v2? " << std::boolalpha << (v1 == v2) << '\n';

  // ft::vector<int> v(10, 1);
  // cout << v.front() << '\n';
  LOG_VAL(v.capacity());
  LOG_VAL(v.size());
  v.reserve(100);
  LOG_VAL(v.capacity());
  LOG_VAL(v.size());
  // test::pair::test_all(1, "hello");

  // std::cout << factorial<5>::value
  //           << '\n';  // constexpr (no calculations on runtime)

  // std::cout << ft::is_integral<int>::value << " "
  //           << ft::is_integral<string>::value << '\n';
  return 0;
}
