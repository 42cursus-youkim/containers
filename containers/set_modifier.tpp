#ifndef CONTAINERS_SET_MODIFIER_TPP
#define CONTAINERS_SET_MODIFIER_TPP

#include "set.hpp"

namespace ft {
template <typename T, typename Compare, typename Allocator>
ft::pair<typename set<T, Compare, Allocator>::iterator, bool>
set<T, Compare, Allocator>::insert(const value_type& val) {
  return tree_.insert(val);
}

template <typename T, typename Compare, typename Allocator>
typename set<T, Compare, Allocator>::iterator
set<T, Compare, Allocator>::insert(iterator          position,
                                   const value_type& val) {
  return tree_.insert(position.base(), val);
}

template <typename T, typename Compare, typename Allocator>
template <typename InputIterator>
void set<T, Compare, Allocator>::insert(InputIterator first,
                                        InputIterator last) {
  tree_.insert(first, last);
}

template <typename T, typename Compare, typename Allocator>
void set<T, Compare, Allocator>::erase(iterator position) {
  tree_.erase(position.base());
}

template <typename T, typename Compare, typename Allocator>
typename set<T, Compare, Allocator>::size_type
set<T, Compare, Allocator>::erase(const value_type& val) {
  iterator target = find(val);
  if (target != end()) {
    erase(target);
    return 1;
  }
  return 0;
}

template <typename T, typename Compare, typename Allocator>
void set<T, Compare, Allocator>::erase(iterator first,
                                       iterator last) {
  while (first != last)
    erase(first++);
}

template <typename T, typename Compare, typename Allocator>
void set<T, Compare, Allocator>::swap(set& other) {
  tree_.swap(other.tree_);
  std::swap(comp_, other.comp_);
  std::swap(alloc_, other.alloc_);
}

template <typename T, typename Compare, typename Allocator>
void set<T, Compare, Allocator>::clear() {
  tree_.clear();
}

}  // namespace ft

#endif  // CONTAINERS_SET_MODIFIER_TPP
