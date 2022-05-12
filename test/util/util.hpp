#ifndef __UTIL_H__
#define __UTIL_H__

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include "color.hpp"

using std::cerr;
using std::cout;
using std::string;

// Logger

#define LOG_VAL(x) log::val(#x, x)

#define LOG_CLASS_COPY log::val(__func__, GRN "is copy constructed")
#define LOG_CLASS                                    \
  do {                                               \
    const string specialMethod = __func__;           \
    if (specialMethod.at(0) == '~')                  \
      log::val(specialMethod, RED "is destructed");  \
    else if (specialMethod == "operator=")           \
      log::val(specialMethod, YEL "is assigned");    \
    else                                             \
      log::val(specialMethod, GRN "is constructed"); \
  } while (0)

namespace log {

template <typename T>
void val(const string& str, T value) {
  cout << BBLU << str << HYEL ": " MAG << value << END "\n";
}

}  // namespace log

// Test
#define TEST_EXPECT(expr)                                                   \
  do {                                                                      \
    assert(expr);                                                           \
    cout << HWHT "{ assert " BBLU << #expr << HWHT " } " BGRN " OK!\n" END; \
  } while (0);

namespace test {

template <typename T>
void header(T const& t) {
  cout << BHYEL << string(40, '-') << "\n";
  cout << "[[[ Testing " BBLU << t << BHYEL " ]]]\n" END;
}

template <typename T>
void subject(T const& t) {
  cout << MAG "\n[ case " BCYN << t << MAG " ]\n" END;
}

}  // namespace test

#endif  // __UTIL_H__
