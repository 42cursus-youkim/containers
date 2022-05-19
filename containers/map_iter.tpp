#ifndef CONTAINERS_MAP_ITER_TPP
#define CONTAINERS_MAP_ITER_TPP

#include "map.hpp"

namespace ft {

/// begin
template <typename Key,
          typename T,
          typename Compare,
          typename Allocator>
typename map<Key, T, Compare, Allocator>::iterator
map<Key, T, Compare, Allocator>::begin() {
  return tree_.begin();
}

template <typename Key,
          typename T,
          typename Compare,
          typename Allocator>
typename map<Key, T, Compare, Allocator>::const_iterator
map<Key, T, Compare, Allocator>::begin() const {
  return tree_.begin();
}


/// end
template <typename Key,
          typename T,
          typename Compare,
          typename Allocator>
typename map<Key, T, Compare, Allocator>::iterator
map<Key, T, Compare, Allocator>::end() {
  return tree_.end();
}

template <typename Key,
          typename T,
          typename Compare,
          typename Allocator>
typename map<Key, T, Compare, Allocator>::const_iterator
map<Key, T, Compare, Allocator>::end() const {
  return tree_.end();
}

/// rbegin
template <typename Key,
          typename T,
          typename Compare,
          typename Allocator>
typename map<Key, T, Compare, Allocator>::reverse_iterator
map<Key, T, Compare, Allocator>::rbegin() {
  return reverse_iterator(tree_.end());
}

template <typename Key,
          typename T,
          typename Compare,
          typename Allocator>
typename map<Key, T, Compare, Allocator>::const_reverse_iterator
map<Key, T, Compare, Allocator>::rbegin() const {
  return reverse_iterator(tree_.end());
}

/// rend
template <typename Key,
          typename T,
          typename Compare,
          typename Allocator>
typename map<Key, T, Compare, Allocator>::reverse_iterator
map<Key, T, Compare, Allocator>::rend() {
  return reverse_iterator(tree_.begin());
}

template <typename Key,
          typename T,
          typename Compare,
          typename Allocator>
typename map<Key, T, Compare, Allocator>::const_reverse_iterator
map<Key, T, Compare, Allocator>::rend() const {
  return reverse_iterator(tree_.begin());
}

}  // namespace ft

#endif  // CONTAINERS_MAP_ITER_TPP
