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

  /// Constructors & Destructor

  /** @brief default constructor.
   *
   * value initialized.
   */
  pair() : first(), second() {}

  /** @brief copy constructor.
   *
   *  @param a
   */
  template <class U, class V>
  pair(const first_type& a, const second_type& b) : first(a), second(b) {}

  /**
   * @brief initialization constructor.
   *
   * @param pr
   */
  pair(const pair<U, V>& pr) : first(pr.first), second(pr.second) {}

  // Operators
  pair& operator=(const pair& p) {
    if (*this != &p) {
      first = p.first;
      second = p.second;
    }
    return *this;
  }
};

}  // namespace ft

template <class T1, class T2>
ft::pair<T1, T2> make_pair(T1 x, T2 y) {
  return (ft::pair<T1, T2>(x, y));
}

#include <utils/pair/make_pair.tpp>
#include <utils/pair/relational_operator.tpp>

#endif  // PAIR_PAIR_HPP
