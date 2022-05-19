#ifndef PAIR_PAIR_HPP
#define PAIR_PAIR_HPP

namespace ft {

/** @brief A pair of two elements.
 *
 * references:
 * https://www.cplusplus.com/reference/utility/pair/pair/
 */
template <typename T1, typename T2>
struct pair {
  typedef T1  first_type;
  typedef T2  second_type;

  first_type  first;
  second_type second;

  /// default constructor, value initialized.
  pair() : first(), second() {}

  /// copy constructor.
  template <typename U, typename V>
  pair(const pair<U, V>& other)
      : first(other.first), second(other.second) {}

  /// initialization constructor.
  pair(const first_type& a, const second_type& b)
      : first(a), second(b) {}

  /// assignment operator.
  pair& operator=(const pair& other);
};

/// specialization.
/// TODO: is it in standard?
template <typename T1, typename T2>
struct pair<const T1, T2> {
  typedef T1  first_type;
  typedef T2  second_type;

  first_type  first;
  second_type second;

  /// default constructor, value initialized.
  pair() : first(), second() {}

  /// copy constructor.
  template <typename U, typename V>
  pair(const pair<U, V>& other)
      : first(other.first), second(other.second) {}

  /// initialization constructor.
  pair(const first_type& a, const second_type& b)
      : first(a), second(b) {}

  /// assignment operator.
  pair& operator=(const pair& other);
};

}  // namespace ft

#include "pair.tpp"

#endif  // PAIR_PAIR_HPP
