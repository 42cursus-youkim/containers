#include <iostream>
#include <memory>
#include <utils/pair/pair.hpp>
#include <utils/tmp/integral_constant.hpp>
#include <utils/tmp/is_integral.hpp>
#include <vector.hpp>
#include "test/pair.hpp"
#include "utils/util/util.hpp"

// --- Class foo
template <typename T>
class foo {
 public:
  typedef T value_type;

  foo(void) : value(), _verbose(false){};
  foo(value_type src, const bool verbose = false)
      : value(src), _verbose(verbose){};
  foo(foo const& src, const bool verbose = false)
      : value(src.value), _verbose(verbose){};
  ~foo(void) {
    if (this->_verbose)
      std::cout << "~foo::foo()" << std::endl;
  };
  void m(void) {
    std::cout << "foo::m called [" << this->value << "]" << std::endl;
  };
  void m(void) const {
    std::cout << "foo::m const called [" << this->value << "]"
              << std::endl;
  };
  foo& operator=(value_type src) {
    this->value = src;
    return *this;
  };
  foo& operator=(foo const& src) {
    if (this->_verbose or src._verbose)
      std::cout << "foo::operator=(foo) CALLED" << std::endl;
    this->value = src.value;
    return *this;
  };
  value_type getValue(void) const { return this->value; };
  void switchVerbose(void) { this->_verbose = !(this->_verbose); };

  operator value_type(void) const { return value_type(this->value); }

 private:
  value_type value;
  bool       _verbose;
};

template <typename T>
std::ostream& operator<<(std::ostream& o, foo<T> const& bar) {
  o << bar.getValue();
  return o;
}
// --- End of typename foo

template <typename T>
T inc(T it, int n) {
  while (n-- > 0)
    ++it;
  return (it);
}

template <typename T>
T dec(T it, int n) {
  while (n-- > 0)
    --it;
  return (it);
}

using std::cout;
using std::string;
// template <unsigned n>
// struct factorial : ft::integral_constant<int, n * factorial<n -
// 1>::value>
// {};

// template <>
// struct factorial<0> : ft::integral_constant<int, 1> {};

#define TESTED_TYPE foo<int>
#define TESTED_NAMESPACE ft

#define T_SIZE_TYPE typename TESTED_NAMESPACE::vector<T>::size_type
#include <list>
#include <vector>

template <typename T>
void print_vector(const TESTED_NAMESPACE::vector<T>& v) {
  for (typename TESTED_NAMESPACE::vector<T>::const_iterator it =
           v.begin();
       it != v.end(); ++it) {
    cout << *it << ", ";
  }
  cout << '\n';
}

template <typename T>
void printSize(TESTED_NAMESPACE::vector<T> const& vct,
               bool print_content = true) {
  const T_SIZE_TYPE size         = vct.size();
  const T_SIZE_TYPE capacity     = vct.capacity();
  const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
  // Cannot limit capacity's max value because it's implementation
  // dependent

  std::cout << "size: " << size << std::endl;
  std::cout << "capacity: " << isCapacityOk << std::endl;
  std::cout << "max_size: " << vct.max_size() << std::endl;
  if (print_content) {
    typename TESTED_NAMESPACE::vector<T>::const_iterator it =
        vct.begin();
    typename TESTED_NAMESPACE::vector<T>::const_iterator ite =
        vct.end();
    std::cout << std::endl << "Content is:" << std::endl;
    for (; it != ite; ++it)
      std::cout << "- " << *it << std::endl;
  }
  std::cout << "###############################################"
            << std::endl;
}

void checkErase(
    TESTED_NAMESPACE::vector<TESTED_TYPE> const&                 vct,
    TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator const& it) {
  static int i = 0;
  std::cout << "[" << i++ << "] "
            << "erase: " << it - vct.begin() << std::endl;
  printSize(vct);
}

int main(void) {
  const int                                               size = 5;
  TESTED_NAMESPACE::vector<TESTED_TYPE>                   vct(size);
  TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it(
      vct.rbegin());
  TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator ite(
      vct.rend());

  for (int i = 1; it != ite; ++i)
    *it++ = (i * 7);
  printSize(vct, 1);

  it  = vct.rbegin();
  ite = vct.rbegin();

  std::cout << *(++ite) << std::endl;
  std::cout << *(ite++) << std::endl;
  std::cout << *ite++ << std::endl;
  std::cout << *++ite << std::endl;

  it->m();
  ite->m();

  std::cout << *(++it) << std::endl;
  std::cout << *(it++) << std::endl;
  std::cout << *it++ << std::endl;
  std::cout << *++it << std::endl;

  std::cout << *(--ite) << std::endl;
  std::cout << *(ite--) << std::endl;
  std::cout << *--ite << std::endl;
  std::cout << *ite-- << std::endl;

  (*it).m();
  (*ite).m();

  std::cout << *(--it) << std::endl;
  std::cout << *(it--) << std::endl;
  std::cout << *it-- << std::endl;
  std::cout << *--it << std::endl;

  return (0);
}
