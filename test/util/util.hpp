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

#define LOG_VAL(x) logging::val(#x, x)

#define LOG_CLASS_COPY \
  logging::val(__func__, GRN "is copy constructed")
#define LOG_CLASS                                        \
  do {                                                   \
    const string specialMethod = __func__;               \
    if (specialMethod.at(0) == '~')                      \
      logging::val(specialMethod, RED "is destructed");  \
    else if (specialMethod == "operator=")               \
      logging::val(specialMethod, YEL "is assigned");    \
    else                                                 \
      logging::val(specialMethod, GRN "is constructed"); \
  } while (0)

#define FUN cout << BHRED "trace: " BBLU << __func__ << ": " HCYN
namespace logging {

template <typename T>
void val(const string& str, T value) {
  cout << BBLU << str << HYEL ": " MAG << value << END "\n";
}

}  // namespace logging

// Test
#define MSG_OK(str) cout << HWHT "✅ " BBLU << str << "\n" END;
#define MSG_OK_SAME(expr1, expr2) \
  MSG_OK(BGRN #expr1 BHWHT "==" BGRN #expr2)
#define MSG_OK_DIFF(expr1, expr2) \
  MSG_OK(BBLU #expr1 BHWHT "!=" BBLU #expr2)

#define ASSERT_TRUE(expr) \
  do {                    \
    assert(expr);         \
    MSG_OK(expr);         \
  } while (0)

#define ASSERT_FALSE(expr) \
  do {                     \
    assert(!(expr));       \
    MSG_OK(!(expr));       \
  } while (0)

#define ASSERT_EQ(expr1, expr2) \
  do {                          \
    assert(expr1 == expr2);     \
    MSG_OK_SAME(expr1, expr2)   \
  } while (0)

#define ASSERT_NEQ(expr1, expr2) \
  do {                           \
    assert(expr1 != expr2);      \
    MSG_OK_DIFF(expr1, expr2)    \
  } while (0)

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
#define TEST_SUBJECT test::subject(__func__)

#endif  // __UTIL_H__
