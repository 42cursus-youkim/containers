#ifndef PAIR_PAIR_TPP
#define PAIR_PAIR_TPP

#include "pair.hpp"

namespace ft {

/// operator

template <class T1, class T2>
pair<T1, T2>& pair<T1, T2>::operator=(
    const pair<T1, T2>& other) {
  if (this != &other) {
    first  = other.first;
    second = other.second;
  }
  return *this;
}

template <class T1, class T2>
pair<const T1, T2>& pair<const T1, T2>::operator=(
    const pair<const T1, T2>& other) {
  if (this != &other) {
    first  = other.first;
    second = other.second;
  }
  return *this;
}

/// make_pair

template <typename T1, typename T2>
pair<T1, T2> make_pair(T1 x, T2 y) {
  return (pair<T1, T2>(x, y));
}

}  // namespace ft

#endif  // PAIR_MAKE_PAIR_TPP
