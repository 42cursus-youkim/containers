#ifndef CONTAINERS_VECTOR_ITER_TPP
#define CONTAINERS_VECTOR_ITER_TPP

#include "vector.hpp"

namespace ft {
/// iterators

template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator
vector<T, Allocator>::begin() {
  return data_start_;
}
template <typename T, typename Allocator>
typename vector<T, Allocator>::const_iterator
vector<T, Allocator>::begin() const {
  return data_start_;
}
template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::end() {
  return data_end_;
}
template <typename T, typename Allocator>
typename vector<T, Allocator>::const_iterator
vector<T, Allocator>::end() const {
  return data_end_;
}

/// reverse iterators

template <typename T, typename Allocator>
typename vector<T, Allocator>::reverse_iterator
vector<T, Allocator>::rbegin() {
  return reverse_iterator(end());
}
template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reverse_iterator
vector<T, Allocator>::rbegin() const {
  return const_reverse_iterator(end());
}
template <typename T, typename Allocator>
typename vector<T, Allocator>::reverse_iterator
vector<T, Allocator>::rend() {
  return reverse_iterator(begin());
}
template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reverse_iterator
vector<T, Allocator>::rend() const {
  return const_reverse_iterator(begin());
}
}  // namespace ft

#endif  // CONTAINERS_VECTOR_ITER_TPP
