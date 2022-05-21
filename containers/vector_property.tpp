#ifndef CONTAINERS_VECTOR_PROPERTY_TPP
#define CONTAINERS_VECTOR_PROPERTY_TPP

#include "vector.hpp"

namespace ft {

/// capacity

template <typename T, typename Allocator>
void vector<T, Allocator>::reserve(size_type n) {
  if (n > capacity())
    DoGrow(n);
}

template <typename T, typename Allocator>
void vector<T, Allocator>::resize(size_type n, T val) {
  if (n > size())
    insert(end(), n - size(), val);
  else
    erase(begin() + n, end());
}

/// allocator

template <typename T, typename Allocator>
typename vector<T, Allocator>::allocator_type
vector<T, Allocator>::get_allocator() const {
  return allocator_;
}

/// capacity

template <typename T, typename Allocator>
bool vector<T, Allocator>::empty() const {
  return size() == 0;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::size_type vector<T, Allocator>::size()
    const {
  return size_type(data_end_ - data_start_);
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::size_type
vector<T, Allocator>::max_size() const {
  return allocator_.max_size();
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::size_type
vector<T, Allocator>::capacity() const {
  return size_type(capacity_ptr_ - data_start_);
}

}  // namespace ft

#endif  // CONTAINERS_VECTOR_PROPERTY_TPP
