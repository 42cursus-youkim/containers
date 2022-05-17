#ifndef PAIR_PAIR_TPP
#define PAIR_PAIR_TPP

#include "pair.hpp"

namespace ft {

/// operator

template <typename T1, typename T2>
pair<T1, T2>& pair<T1, T2>::operator=(const pair<T1, T2>& p) {
  if (this != &p) {
    first = p.first;
    second = p.second;
  }
  return *this;
}

template <class T1, class T2>
ft::pair<const T1, T2>& ft::pair<const T1, T2>::operator=(
    const ft::pair<const T1, T2>& p) {
  if (this != &p) {
    first = p.first;
    second = p.second;
  }
  return *this;
}

/// relational operators

template <typename T1, typename T2>
bool operator==(const pair<T1, T2>& left, const pair<T1, T2>& right) {
  return left.first == right.first and left.second == right.second;
}

template <typename T1, typename T2>
bool operator!=(const pair<T1, T2>& left, const pair<T1, T2>& right) {
  return not(left == right);
}

template <typename T1, typename T2>
bool operator<(const pair<T1, T2>& left, const pair<T1, T2>& right) {
  return left.first < right.first or
         (not(right.first < left.first) and left.second < right.second);
}

template <typename T1, typename T2>
bool operator>(const pair<T1, T2>& left, const pair<T1, T2>& right) {
  return left > right;
}

template <typename T1, typename T2>
bool operator<=(const pair<T1, T2>& left, const pair<T1, T2>& right) {
  return left == right or left < right;
}

template <typename T1, typename T2>
bool operator>=(const pair<T1, T2>& left, const pair<T1, T2>& right) {
  return left == right or left > right;
}

/// make_pair

template <typename T1, typename T2>
pair<T1, T2> make_pair(T1 x, T2 y) {
  return (pair<T1, T2>(x, y));
}

}  // namespace ft

#endif  // PAIR_MAKE_PAIR_TPP
