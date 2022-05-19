#ifndef CONTAINERS_SET_PROPERTY_TPP
#define CONTAINERS_SET_PROPERTY_TPP

#include "set.hpp"

namespace ft {

/// capacity
template <typename T, typename Compare, typename Allocator>
bool set<T, Compare, Allocator>::empty() const {
  return tree_.size() == 0;
}

template <typename T, typename Compare, typename Allocator>
typename set<T, Compare, Allocator>::size_type
set<T, Compare, Allocator>::size() const {
  return tree_.size();
}

template <typename T, typename Compare, typename Allocator>
typename set<T, Compare, Allocator>::size_type
set<T, Compare, Allocator>::max_size() const {
  return tree_.max_size();
}

/// allocator
template <typename T, typename Compare, typename Allocator>
typename set<T, Compare, Allocator> ::allocator_type
set<T, Compare, Allocator>::get_allocator() const {
  return alloc_;
}

}  // namespace ft

#endif // CONTAINERS_SET_PROPERTY_TPP
