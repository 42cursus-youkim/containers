#ifndef CONTAINERS_VECTOR_ELEMENT_TPP
#define CONTAINERS_VECTOR_ELEMENT_TPP

#include "vector.hpp"

namespace ft {

/// element access

template <typename T, typename Allocator>
typename vector<T, Allocator>::reference
vector<T, Allocator>::front() {
  return data_start_[0];
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reference
vector<T, Allocator>::front() const {
  return data_start_[0];
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::reference
vector<T, Allocator>::back() {
  return data_end_[-1];
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reference
vector<T, Allocator>::back() const {
  return data_end_[-1];
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::reference vector<T, Allocator>::at(
    size_type n) {
  if (n >= size())
    throw std::out_of_range("vector::at");
  return data_start_[n];
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reference
vector<T, Allocator>::at(size_type n) const {
  if (n >= size())
    throw std::out_of_range("vector::at");
  return data_start_[n];
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::reference
vector<T, Allocator>::operator[](size_type n) {
  return data_start_[n];
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reference
vector<T, Allocator>::operator[](size_type n) const {
  return data_start_[n];
}

}  // namespace ft

#endif  // CONTAINERS_VECTOR_ELEMENT_TPP
