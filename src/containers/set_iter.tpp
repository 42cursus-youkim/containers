#ifndef CONTAINERS_SET_ITER_TPP
#define CONTAINERS_SET_ITER_TPP

#include "set.hpp"

namespace ft {

/// begin
template <typename T, typename Compare, typename Allocator>
typename set<T, Compare, Allocator>::iterator
set<T, Compare, Allocator>::begin() {
  return tree_.begin();
}

template <typename T, typename Compare, typename Allocator>
typename set<T, Compare, Allocator>::const_iterator
set<T, Compare, Allocator>::begin() const {
  return tree_.begin();
}

/// end
template <typename T, typename Compare, typename Allocator>
typename set<T, Compare, Allocator>::iterator
set<T, Compare, Allocator>::end() {
  return tree_.end();
}

template <typename T, typename Compare, typename Allocator>
typename set<T, Compare, Allocator>::const_iterator
set<T, Compare, Allocator>::end() const {
  return tree_.end();
}

/// rbegin
template <typename T, typename Compare, typename Allocator>
typename set<T, Compare, Allocator>::reverse_iterator
set<T, Compare, Allocator>::rbegin() {
  return reverse_iterator(tree_.end());
}

template <typename T, typename Compare, typename Allocator>
typename set<T, Compare, Allocator>::const_reverse_iterator
set<T, Compare, Allocator>::rbegin() const {
  return reverse_iterator(tree_.end());
}

/// rend
template <typename T, typename Compare, typename Allocator>
typename set<T, Compare, Allocator>::reverse_iterator
set<T, Compare, Allocator>::rend() {
  return reverse_iterator(tree_.begin());
}

template <typename T, typename Compare, typename Allocator>
typename set<T, Compare, Allocator>::const_reverse_iterator
set<T, Compare, Allocator>::rend() const {
  return reverse_iterator(tree_.begin());
}

}  // namespace ft

#endif // CONTAINERS_SET_ITER_TPP
