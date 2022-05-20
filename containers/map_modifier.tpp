#ifndef CONTAINERS_MAP_MODIFIER_TPP
#define CONTAINERS_MAP_MODIFIER_TPP

#include "map.hpp"

namespace ft {

template <typename Key,
          typename T,
          typename Compare,
          typename Allocator>
ft::pair<typename map<Key, T, Compare, Allocator>::iterator, bool>
map<Key, T, Compare, Allocator>::insert(const value_type& val) {
  return tree_.insert(val);
}

template <typename Key,
          typename T,
          typename Compare,
          typename Allocator>
typename map<Key, T, Compare, Allocator>::iterator
map<Key, T, Compare, Allocator>::insert(iterator          position,
                                        const value_type& val) {
  return tree_.insert(position.base(), val);
}

template <typename Key,
          typename T,
          typename Compare,
          typename Allocator>
template <typename InputIterator>
void map<Key, T, Compare, Allocator>::insert(InputIterator first,
                                             InputIterator last) {
  tree_.insert(first, last);
}

template <typename Key,
          typename T,
          typename Compare,
          typename Allocator>
void map<Key, T, Compare, Allocator>::erase(iterator position) {
  tree_.erase(position.base());
}

template <typename Key,
          typename T,
          typename Compare,
          typename Allocator>
typename map<Key, T, Compare, Allocator>::size_type
map<Key, T, Compare, Allocator>::erase(const key_type& k) {
  iterator target = find(k);
  if (target == end())
    return 0;

  erase(target);
  return 1;
}

template <typename Key,
          typename T,
          typename Compare,
          typename Allocator>
void map<Key, T, Compare, Allocator>::erase(iterator first,
                                            iterator last) {
  while (first != last)
    erase(first++);
}

template <typename Key,
          typename T,
          typename Compare,
          typename Allocator>
void map<Key, T, Compare, Allocator>::swap(map& other) {
  tree_.swap(other.tree_);
  std::swap(comp_, other.comp_);
  std::swap(alloc_, other.alloc_);
}

template <typename Key,
          typename T,
          typename Compare,
          typename Allocator>
void map<Key, T, Compare, Allocator>::clear() {
  tree_.clear();
}

}  // namespace ft

#endif  // CONTAINERS_MAP_MODIFIER_TPP
