#ifndef RBTREE_RBTREE_ITER_TPP
#define RBTREE_RBTREE_ITER_TPP

#include <algorithm>
#include "rbtree.hpp"

namespace ft {
template <typename T, typename Compare, typename Alloc>
typename rbtree<T, Compare, Alloc>::iterator
rbtree<T, Compare, Alloc>::begin() {
  return iterator(begin_);
}

template <typename T, typename Compare, typename Alloc>
typename rbtree<T, Compare, Alloc>::const_iterator
rbtree<T, Compare, Alloc>::begin() const {
  return const_iterator(begin_);
}

template <typename T, typename Compare, typename Alloc>
typename rbtree<T, Compare, Alloc>::iterator
rbtree<T, Compare, Alloc>::end() {
  return iterator(end_);
}

template <typename T, typename Compare, typename Alloc>
typename rbtree<T, Compare, Alloc>::const_iterator
rbtree<T, Compare, Alloc>::end() const {
  return const_iterator(end_);
}

/// Getters
template <typename T, typename Compare, typename Alloc>
typename rbtree<T, Compare, Alloc>::size_type
rbtree<T, Compare, Alloc>::size() const {
  return size_;
}

template <typename T, typename Compare, typename Alloc>
typename rbtree<T, Compare, Alloc>::size_type
rbtree<T, Compare, Alloc>::max_size() const {
  return std::min<size_type>(
      alloc_.max_size(), std::numeric_limits<difference_type>::max());
}
}  // namespace ft

#endif  // RBTREE_RBTREE_ITER_TPP
