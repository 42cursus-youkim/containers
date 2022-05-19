#ifndef CONTAINERS_MAP_TPP
#define CONTAINERS_MAP_TPP

#include "map.hpp"

namespace ft {

/// Constructors & Destructor
template <typename Key,
          typename T,
          typename Compare,
          typename Allocator>
map<Key, T, Compare, Allocator>::map(const key_compare&    comp,
                                     const allocator_type& alloc)
    : comp_(comp), alloc_(alloc), tree_(value_compare(comp)) {}

template <typename Key,
          typename T,
          typename Compare,
          typename Allocator>
template <typename InputIterator>
map<Key, T, Compare, Allocator>::map(InputIterator         first,
                                     InputIterator         last,
                                     const key_compare&    comp,
                                     const allocator_type& alloc)
    : comp_(comp), alloc_(alloc), tree_(value_compare(comp_)) {
  insert(first, last);
}

template <typename Key,
          typename T,
          typename Compare,
          typename Allocator>
map<Key, T, Compare, Allocator>::map(const map& other)
    : comp_(other.comp_), alloc_(other.alloc_), tree_(other.tree_) {}

template <typename Key,
          typename T,
          typename Compare,
          typename Allocator>
map<Key, T, Compare, Allocator>::~map() {}

/// Operators
template <typename Key,
          typename T,
          typename Compare,
          typename Allocator>
map<Key, T, Compare, Allocator>&
map<Key, T, Compare, Allocator>::operator=(
    const map<Key, T, Compare, Allocator>& other) {
  if (this != &other) {
    this->clear();
    alloc_ = other.alloc_;
    comp_  = other.comp_;
    insert(other.begin(), other.end());
  }
  return (*this);
}
}  // namespace ft

#endif  // CONTAINERS_MAP_TPP
