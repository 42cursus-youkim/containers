#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

#include "integral_constant.hpp"

/**
 * @brief
 *
 * https://www.cplusplus.com/reference/type_traits/is_integral/?kw=is_integral
 *
 * bool
 * char
 * char16_t (C++11)
 * char32_t (C++11)
 * wchar_t
 * signed char
 * short int
 * int
 * long int
 * long long int (C++11)
 * unsigned char
 * unsigned short int
 * unsigned int
 * unsigned long int
 * unsigned long long int (C++11)
 */

/// template specialization helper
#define IS_INTEGRAL(type) \
  template <>             \
  struct is_integral<type> : public true_type {};

namespace ft {

/// default false
template <typename T>
struct is_integral : public false_type {};

/// sfinae helper
IS_INTEGRAL(bool)
IS_INTEGRAL(char)
IS_INTEGRAL(wchar_t)
IS_INTEGRAL(signed char)
IS_INTEGRAL(short int)
IS_INTEGRAL(int)
IS_INTEGRAL(long int)
// IS_INTEGRAL(long long int)
IS_INTEGRAL(unsigned char)
IS_INTEGRAL(unsigned short int)
IS_INTEGRAL(unsigned int)
IS_INTEGRAL(unsigned long int)
// IS_INTEGRAL(unsigned long long int)

}  // namespace ft

#endif  // IS_INTEGRAL_HPP
