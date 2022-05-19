#ifndef CONTAINERS_SET_TPP
#define CONTAINERS_SET_TPP

#include "set.hpp"

namespace ft {

/// Constructors & Destructor

template <typename T, typename Compare, typename Allocator>
set<T, Compare, Allocator>::set(const key_compare&    comp,
                                const allocator_type& alloc)
    : comp_(comp), alloc_(alloc), tree_(value_compare(comp)) {}

template <typename T, typename Compare, typename Allocator>
template <typename InputIterator>
set<T, Compare, Allocator>::set(InputIterator         first,
                                InputIterator         last,
                                const key_compare&    comp,
                                const allocator_type& alloc)
    : comp_(comp), alloc_(alloc), tree_(value_compare(comp_)) {
  insert(first, last);
}

template <typename T, typename Compare, typename Allocator>
set<T, Compare, Allocator>::set(const set& other)
    : comp_(other.comp_), alloc_(other.alloc_), tree_(other.tree_) {}

template <typename T, typename Compare, typename Allocator>
set<T, Compare, Allocator>::~set() {}

/// Operators
template <typename T, typename Compare, typename Allocator>
set<T, Compare, Allocator>& set<T, Compare, Allocator>::operator=(
    const set& other) {
  if (this != &other) {
    this->clear();
    alloc_ = other.alloc_;
    comp_  = other.comp_;
    insert(other.begin(), other.end());
  }
  return (*this);
}
}  // namespace ft

#endif  // CONTAINERS_SET_TPP
