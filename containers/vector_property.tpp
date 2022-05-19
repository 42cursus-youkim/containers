#ifndef CONTAINERS_VECTOR_PROPERTY_TPP
#define CONTAINERS_VECTOR_PROPERTY_TPP

#include "vector.hpp"

namespace ft {

/// capacity

template <class T, class Allocator>
void VEC::reserve(size_type n) {
  if (n > capacity())
    DoGrow(n);
}

template <class T, class Allocator>
void VEC::resize(size_type n, T val) {
  if (n > size())
    insert(end(), n - size(), val);
  else
    erase(begin() + n, end());
}

/// allocator

template <class T, class Allocator>
typename VEC::allocator_type VEC::get_allocator() const {
  return allocator_;
}

/// capacity

template <class T, class Allocator>
bool VEC::empty() const {
  return size() == 0;
}

template <class T, class Allocator>
typename VEC::size_type VEC::size() const {
  return size_type(data_end_ - data_start_);
}

template <class T, class Allocator>
typename VEC::size_type VEC::max_size() const {
  return allocator_.max_size();
}

template <class T, class Allocator>
typename VEC::size_type VEC::capacity() const {
  return size_type(capacity_ptr_ - data_start_);
}

}  // namespace ft

#endif // CONTAINERS_VECTOR_PROPERTY_TPP
