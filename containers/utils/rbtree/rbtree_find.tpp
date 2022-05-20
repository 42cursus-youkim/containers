#ifndef RBTREE_RBTREE_FIND_TPP
#define RBTREE_RBTREE_FIND_TPP

#include "rbtree.hpp"

namespace ft {

template <typename T, typename Compare>
template <typename Key>
typename rbtree<T, Compare>::iterator rbtree<T, Compare>::find(
    const Key& k) {
  iterator it = lower_bound(k);
  if (it != end() and not comp_(k, *it))
    return it;
  return end();
}

template <typename T, typename Compare>
template <typename Key>
typename rbtree<T, Compare>::const_iterator rbtree<T, Compare>::find(
    const Key& k) const {
  const_iterator it = lower_bound(k);
  if (it != end() and not comp_(k, *it))
    return it;
  return end();
}

template <typename T, typename Compare>
template <typename Key>
typename rbtree<T, Compare>::iterator rbtree<T, Compare>::lower_bound(
    const Key& k) {
  node_pointer root_node = root();
  node_pointer ret       = end_;
  while (root_node != u_nullptr) {
    if (not comp_(root_node->data, k)) {
      ret       = root_node;
      root_node = root_node->left;
    } else
      root_node = root_node->right;
  }
  return iterator(ret);
}

template <typename T, typename Compare>
template <typename Key>
typename rbtree<T, Compare>::const_iterator
rbtree<T, Compare>::lower_bound(const Key& k) const {
  node_pointer root_node = root();
  node_pointer ret       = end_;
  while (root_node != u_nullptr) {
    if (not comp_(root_node->data, k)) {
      ret       = root_node;
      root_node = root_node->left;
    } else
      root_node = root_node->right;
  }
  return const_iterator(ret);
}

template <typename T, typename Compare>
template <typename Key>
typename rbtree<T, Compare>::iterator rbtree<T, Compare>::upper_bound(
    const Key& k) {
  node_pointer root_node = root();
  node_pointer ret       = end_;

  while (root_node != u_nullptr) {
    if (comp_(k, root_node->data)) {
      ret       = root_node;
      root_node = root_node->left;
    } else
      root_node = root_node->right;
  }
  return iterator(ret);
}

template <typename T, typename Compare>
template <typename Key>
typename rbtree<T, Compare>::const_iterator
rbtree<T, Compare>::upper_bound(const Key& k) const {
  node_pointer root_node = root();
  node_pointer ret       = end_;

  while (root_node != u_nullptr) {
    if (comp_(k, root_node->data)) {
      ret       = root_node;
      root_node = root_node->left;
    } else
      root_node = root_node->right;
  }
  return const_iterator(ret);
}

}  // namespace ft

#endif  // RBTREE_RBTREE_FIND_TPP
