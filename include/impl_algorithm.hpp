#ifndef __IMPL_ALGORITHM_H__
#define __IMPL_ALGORITHM_H__

namespace ft {

template <typename T>
const T& min(const T& a, const T& b) {
  return a < b ? a : b;
}

template <typename T>
const T& max(const T& a, const T& b) {
  return a > b ? a : b;
}

template <typename T>
bool equal(const T& a, const T& b) {
  return a == b;
}

template <typename T>
void swap(T& a, T& b) {
  T tmp(a);
  a = b;
  b = tmp;
}

}  // namespace ft
#endif  // __IMPL_ALGORITHM_H__
