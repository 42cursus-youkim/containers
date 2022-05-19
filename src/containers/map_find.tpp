#ifndef CONTAINERS_MAP_FIND_TPP
#define CONTAINERS_MAP_FIND_TPP

#include "map.hpp"

namespace ft {

template <typename Key,
          typename T,
          typename Compare,
          typename Allocator>
typename map<Key, T, Compare, Allocator>::iterator
map<Key, T, Compare, Allocator>::find(const key_type& key) {
  return tree_.find(key);
}

template <typename Key,
          typename T,
          typename Compare,
          typename Allocator>
typename map<Key, T, Compare, Allocator>::const_iterator
map<Key, T, Compare, Allocator>::find(const key_type& key) const {
  return tree_.find(key);
}

template <typename Key,
          typename T,
          typename Compare,
          typename Allocator>
typename map<Key, T, Compare, Allocator>::size_type
map<Key, T, Compare, Allocator>::count(const key_type& key) const {
  return find(key) != end();
}

template <typename Key,
          typename T,
          typename Compare,
          typename Allocator>
typename map<Key, T, Compare, Allocator>::iterator
map<Key, T, Compare, Allocator>::lower_bound(const key_type& key) {
  return tree_.lower_bound(key);
}

template <typename Key,
          typename T,
          typename Compare,
          typename Allocator>
typename map<Key, T, Compare, Allocator>::const_iterator
map<Key, T, Compare, Allocator>::lower_bound(
    const key_type& key) const {
  return tree_.lower_bound(key);
}

template <typename Key,
          typename T,
          typename Compare,
          typename Allocator>
typename map<Key, T, Compare, Allocator>::iterator
map<Key, T, Compare, Allocator>::upper_bound(const key_type& key) {
  return tree_.upper_bound(key);
}

template <typename Key,
          typename T,
          typename Compare,
          typename Allocator>
typename map<Key, T, Compare, Allocator>::const_iterator
map<Key, T, Compare, Allocator>::upper_bound(
    const key_type& key) const {
  return tree_.upper_bound(key);
}

template <typename Key,
          typename T,
          typename Compare,
          typename Allocator>
pair<typename map<Key, T, Compare, Allocator>::iterator,
     typename map<Key, T, Compare, Allocator>::iterator>
map<Key, T, Compare, Allocator>::equal_range(const key_type& key) {
  return pair<iterator, iterator>(lower_bound(key), upper_bound(key));
}

template <typename Key,
          typename T,
          typename Compare,
          typename Allocator>
pair<typename map<Key, T, Compare, Allocator>::const_iterator,
     typename map<Key, T, Compare, Allocator>::const_iterator>
map<Key, T, Compare, Allocator>::equal_range(
    const key_type& key) const {
  return pair<const_iterator, const_iterator>(lower_bound(key),
                                              upper_bound(key));
}
}  // namespace ft

#endif  // CONTAINERS_MAP_FIND_TPP
