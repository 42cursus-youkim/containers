#ifndef PAIR_PAIR_HPP
#define PAIR_PAIR_HPP

namespace ft {

/** @brief A pair of two elements.
 *
 * references:
 * https://www.cplusplus.com/reference/utility/pair/pair/
 */
template <class T1, class T2>
struct pair {
  typedef T1 first_type;
  typedef T2 second_type;

  first_type first;
  second_type second;

  /// default constructor, value initialized.
  pair() : first(), second() {}

  /// copy constructor.
  template <class U, class V>
  pair(const pair<U, V>& pr) : first(pr.first), second(pr.second) {}

  /// initialization constructor.
  pair(const first_type& a, const second_type& b) : first(a), second(b) {}

  /// assignment operator.
  pair& operator=(const pair& p) {
    if (this != &p) {
      first = p.first;
      second = p.second;
    }
    return *this;
  }
};

}  // namespace ft

#include "pair.tpp"

#endif  // PAIR_PAIR_HPP
