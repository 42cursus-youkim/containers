#ifndef CONTAINERS_MAP_PROPERTY_TPP
#define CONTAINERS_MAP_PROPERTY_TPP

#include "map.hpp"

namespace ft {

/// capacity
template <typename Key,
          typename T,
          typename Compare,
          typename Allocator>
bool map<Key, T, Compare, Allocator>::empty() const {
  return tree_.size() == 0;
}

template <typename Key,
          typename T,
          typename Compare,
          typename Allocator>
typename map<Key, T, Compare, Allocator>::size_type
map<Key, T, Compare, Allocator>::size() const {
  return tree_.size();
}

template <typename Key,
          typename T,
          typename Compare,
          typename Allocator>
typename map<Key, T, Compare, Allocator>::size_type
map<Key, T, Compare, Allocator>::max_size() const {
  return tree_.max_size();
}

/// allocator
template <typename Key,
          typename T,
          typename Compare,
          typename Allocator>
typename map<Key, T, Compare, Allocator>::allocator_type
map<Key, T, Compare, Allocator>::get_allocator() const {
  return alloc_;
}

}  // namespace ft

#endif  // CONTAINERS_MAP_PROPERTY_TPP
