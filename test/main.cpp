#include <containers/vector.hpp>
#include <iostream>
#include <memory>
#include <utils/pair/pair.hpp>
#include <utils/tmp/integral_constant.hpp>
#include <utils/tmp/is_integral.hpp>
#include "test/pair.hpp"
#include "utils/util/util.hpp"

using std::cout;
using std::string;
// template <unsigned n>
// struct factorial : ft::integral_constant<int, n * factorial<n - 1>::value>
// {};

// template <>
// struct factorial<0> : ft::integral_constant<int, 1> {};

template <typename T>
void print_vector(const ft::vector<T>& v) {
  for (typename ft::vector<T>::const_iterator it = v.begin(); it != v.end();
       ++it) {
    cout << *it << ", ";
  }
  cout << '\n';
}

#define TESTED_TYPE std::string
#define TESTED_NAMESPACE ft

#define T_SIZE_TYPE typename TESTED_NAMESPACE::vector<T>::size_type
#include <list>
#include <vector>

template <typename T>
void printSize(TESTED_NAMESPACE::vector<T> const& vct,
               bool print_content = true) {
  const T_SIZE_TYPE size = vct.size();
  const T_SIZE_TYPE capacity = vct.capacity();
  const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
  // Cannot limit capacity's max value because it's implementation dependent

  std::cout << "size: " << size << std::endl;
  std::cout << "capacity: " << isCapacityOk << std::endl;
  std::cout << "max_size: " << vct.max_size() << std::endl;
  if (print_content) {
    typename TESTED_NAMESPACE::vector<T>::const_iterator it = vct.begin();
    typename TESTED_NAMESPACE::vector<T>::const_iterator ite = vct.end();
    std::cout << std::endl << "Content is:" << std::endl;
    for (; it != ite; ++it)
      std::cout << "- " << *it << std::endl;
  }
  std::cout << "###############################################" << std::endl;
}

void checkErase(
    TESTED_NAMESPACE::vector<TESTED_TYPE> const& vct,
    TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator const& it) {
  static int i = 0;
  std::cout << "[" << i++ << "] "
            << "erase: " << it - vct.begin() << std::endl;
  printSize(vct);
}

int main(void) {
  TESTED_NAMESPACE::vector<TESTED_TYPE> vct(10);
  for (unsigned long int i = 0; i < vct.size(); ++i)
    vct[i] = std::string((vct.size() - i), i + 65);
  printSize(vct);

  vct.erase(vct.begin() + 2);
  checkErase(vct, vct.erase(vct.begin() + 2));

  // checkErase(vct, vct.erase(vct.begin()));
  // checkErase(vct, vct.erase(vct.end() - 1));

  // checkErase(vct, vct.erase(vct.begin(), vct.begin() + 3));
  // checkErase(vct, vct.erase(vct.end() - 3, vct.end() - 1));

  // vct.push_back("Hello");
  // vct.push_back("Hi there");
  // printSize(vct);
  // checkErase(vct, vct.erase(vct.end() - 3, vct.end()));

  // vct.push_back("ONE");
  // vct.push_back("TWO");
  // vct.push_back("THREE");
  // vct.push_back("FOUR");
  // printSize(vct);
  // checkErase(vct, vct.erase(vct.begin(), vct.end()));

  return (0);
}
