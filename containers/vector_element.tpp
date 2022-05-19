#ifndef CONTAINERS_VECTOR_ELEMENT_TPP
#define CONTAINERS_VECTOR_ELEMENT_TPP

#include "vector.hpp"

namespace ft {

/// element access

template <class T, class Allocator>
typename VEC::reference VEC::front() {
  return data_start_[0];
}

template <class T, class Allocator>
typename VEC::const_reference VEC::front() const {
  return data_start_[0];
}

template <class T, class Allocator>
typename VEC::reference VEC::back() {
  return data_end_[-1];
}

template <class T, class Allocator>
typename VEC::const_reference VEC::back() const {
  return data_end_[-1];
}

template <class T, class Allocator>
typename VEC::reference VEC::at(size_type n) {
  if (n >= size())
    throw std::out_of_range("vector::at");
  return data_start_[n];
}

template <class T, class Allocator>
typename VEC::const_reference VEC::at(size_type n) const {
  if (n >= size())
    throw std::out_of_range("vector::at");
  return data_start_[n];
}

template <class T, class Allocator>
typename VEC::reference VEC::operator[](size_type n) {
  return data_start_[n];
}

template <class T, class Allocator>
typename VEC::const_reference VEC::operator[](size_type n) const {
  return data_start_[n];
}

}  // namespace ft

#endif // CONTAINERS_VECTOR_ELEMENT_TPP
