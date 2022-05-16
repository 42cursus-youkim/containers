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
template <unsigned n>
struct factorial : ft::integral_constant<int, n * factorial<n - 1>::value> {};

template <>
struct factorial<0> : ft::integral_constant<int, 1> {};

template <typename T>
void print_vector(const ft::vector<T>& v) {
  for (typename ft::vector<T>::const_iterator it = v.begin(); it != v.end();
       ++it) {
    cout << *it << ", ";
  }
  cout << '\n';
}

#define TESTED_TYPE int
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

int main(void) {
  TESTED_NAMESPACE::vector<TESTED_TYPE> vct(7);

  for (unsigned long int i = 0; i < vct.size(); ++i) {
    vct.at(i) = static_cast<int>((vct.size() - i) * 3);
    std::cout << "vct.at(): " << vct.at(i) << " | ";
    std::cout << "vct[]: " << vct[i] << std::endl;
  }
  printSize(vct);

  TESTED_NAMESPACE::vector<TESTED_TYPE> const vct_c(vct);

  std::cout << "front(): " << vct.front() << " " << vct_c.front() << std::endl;
  std::cout << "back(): " << vct.back() << " " << vct_c.back() << std::endl;

  try {
    vct.at(10) = 42;
  } catch (std::out_of_range& e) {
    std::cout << "Catch out_of_range exception!" << std::endl;
  } catch (std::exception& e) {
    std::cout << "Catch exception: " << e.what() << std::endl;
  }
  return (0);
}
