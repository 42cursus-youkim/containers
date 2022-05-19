#ifndef RBTREE_RBTREE_ITER_TPP
#define RBTREE_RBTREE_ITER_TPP

#include "rbtree.hpp"

namespace ft {
template <typename T, typename Compare>
typename rbtree<T, Compare>::iterator rbtree<T, Compare>::begin() {
  return iterator(begin_);
}

template <typename T, typename Compare>
typename rbtree<T, Compare>::const_iterator
rbtree<T, Compare>::begin() const {
  return const_iterator(begin_);
}

template <typename T, typename Compare>
typename rbtree<T, Compare>::iterator rbtree<T, Compare>::end() {
  return iterator(end_);
}

template <typename T, typename Compare>
typename rbtree<T, Compare>::const_iterator rbtree<T, Compare>::end()
    const {
  return const_iterator(end_);
}

/// Getters
template <typename T, typename Compare>
typename rbtree<T, Compare>::size_type rbtree<T, Compare>::size()
    const {
  return size_;
}

template <typename T, typename Compare>
typename rbtree<T, Compare>::size_type rbtree<T, Compare>::max_size()
    const {
  return std::min<size_type>(
      alloc_.max_size(), std::numeric_limits<difference_type>::max());
}
}  // namespace ft

#endif  // RBTREE_RBTREE_ITER_TPP
