#ifndef CONTAINERS_VECTOR_ITER_TPP
#define CONTAINERS_VECTOR_ITER_TPP

#include "vector.hpp"

namespace ft {
/// iterators

template <typename T, typename Allocator>
typename VEC::iterator VEC::begin() {
  return data_start_;
}
template <typename T, typename Allocator>
typename VEC::const_iterator VEC::begin() const {
  return data_start_;
}
template <typename T, typename Allocator>
typename VEC::iterator VEC::end() {
  return data_end_;
}
template <typename T, typename Allocator>
typename VEC::const_iterator VEC::end() const {
  return data_end_;
}

/// reverse iterators

template <typename T, typename Allocator>
typename VEC::reverse_iterator VEC::rbegin() {
  return reverse_iterator(end());
}
template <typename T, typename Allocator>
typename VEC::const_reverse_iterator VEC::rbegin() const {
  return const_reverse_iterator(end());
}
template <typename T, typename Allocator>
typename VEC::reverse_iterator VEC::rend() {
  return reverse_iterator(begin());
}
template <typename T, typename Allocator>
typename VEC::const_reverse_iterator VEC::rend() const {
  return const_reverse_iterator(begin());
}
}  // namespace ft

#endif  // CONTAINERS_VECTOR_ITER_TPP
