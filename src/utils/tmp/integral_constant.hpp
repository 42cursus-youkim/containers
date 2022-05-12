#ifndef TMP_INTEGRAL_CONSTANT_HPP
#define TMP_INTEGRAL_CONSTANT_HPP

namespace ft {

template <class T, T v>
struct integral_constant {
  typedef T value_type;
  typedef integral_constant<T, v> type;

  static const T value = v;

  operator T() const { return value; }
};

typedef integral_constant<bool, true> true_type;
typedef integral_constant<bool, false> false_type;

}  // namespace ft

#endif // TMP_INTEGRAL_CONSTANT_HPP
