#ifndef CONTAINERS_VECTOR_IMPL_TPP
#define CONTAINERS_VECTOR_IMPL_TPP

#include <algorithm>
#include "vector.hpp"

namespace ft {

/// implementation details

/// returns
template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator
vector<T, Allocator>::UninitializedFillN(iterator          from,
                                         size_type         count,
                                         const value_type& val) {
  for (size_type i = 0; i < count; ++i)
    allocator_.construct(from + i, val);
  return from + count;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::size_type vector<T, Allocator>::Index(
    iterator it) const {
  return size_type(it - begin());
}

/// creates new storage, rellocates all elements to new one
template <typename T, typename Allocator>
void vector<T, Allocator>::DoGrow(size_type new_capacity) {
  if (new_capacity > max_size())
    throw std::length_error(
        "ft::vector::reserve: maximum capacity exceeded");

  const size_type length         = size();
  const size_type old_capacity   = capacity();
  pointer         new_data_begin = allocator_.allocate(new_capacity);

  for (size_type i = 0; i < length; ++i) {
    allocator_.construct(new_data_begin + i, data_start_[i]);
    allocator_.destroy(data_start_ + i);
  }
  allocator_.deallocate(data_start_, old_capacity);

  data_start_   = new_data_begin;
  data_end_     = data_start_ + length;
  capacity_ptr_ = data_start_ + new_capacity;
}

/// get suitable new capacity
template <typename T, typename Allocator>
typename vector<T, Allocator>::size_type
vector<T, Allocator>::GetNewCapacity(size_type at_least) const {
  const size_type max_possible_size(max_size());
  const size_type current_capacity(capacity());

  if (at_least > max_possible_size)
    throw std::length_error(
        "ft::vector::reserve: maximum capacity exceeded");
  else if (current_capacity > max_possible_size / 2)
    return at_least;
  return std::max(at_least, 2 * current_capacity);
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator
vector<T, Allocator>::LeftShift(iterator from, size_type diff) {
  if (diff == 0)
    return from;

  for (iterator it = from; it + diff < end(); ++it) {
    *it = it[diff];
  }
  for (iterator it = end() - 1; it + diff > end(); --it)
    allocator_.destroy(it);
  data_end_ -= diff;

  return from;
}

/// @brief Moves from amount elements to the right
template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator
vector<T, Allocator>::RightShift(iterator from, size_type diff) {
  if (diff == 0)
    return from;

  const size_type from_index = Index(from);
  const size_type new_size   = size() + diff;
  const size_type affected   = size() - from_index;

  if (new_size >= capacity())
    reserve(GetNewCapacity(new_size));

  for (size_type i = 0; i < affected; i++) {
    size_type from_i  = from_index + (affected - i - 1);
    size_type to_i    = from_i + diff;
    data_start_[to_i] = data_start_[from_i];
  }

  data_end_ = data_start_ + new_size;
  return data_start_ + from_index;
}

}  // namespace ft

#endif  // CONTAINERS_VECTOR_IMPL_TPP
