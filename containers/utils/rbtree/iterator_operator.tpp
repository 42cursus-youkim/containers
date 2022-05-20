#ifndef RBTREE_ITERATOR_OPERATOR_TPP
#define RBTREE_ITERATOR_OPERATOR_TPP

#include "iterator.hpp"

namespace ft {
template <typename T, typename Node>
typename tree_iterator<T, Node>::reference
tree_iterator<T, Node>::operator*() const {
  return node_->data;
}

template <typename T, typename Node>
typename tree_iterator<T, Node>::pointer
tree_iterator<T, Node>::operator->() const {
  return &node_->data;
}

template <typename T, typename Node>
bool tree_iterator<T, Node>::operator==(
    const tree_iterator& other) const {
  return node_ == other.node_;
}

template <typename T, typename Node>
bool tree_iterator<T, Node>::operator!=(
    const tree_iterator& other) const {
  return node_ != other.node_;
}

template <typename T, typename Node>
tree_iterator<T, Node>& tree_iterator<T, Node>::operator=(
    const tree_iterator& other) {
  node_ = other.node_;
  return (*this);
}

/**
 * @brief  move to next smallest element then return
 *
 * @b case-1: start from 8
 *    find smallest value from right-element 11 -> result: 10
 * @b case-2: start from 11
 *    move to its parent until it is left child of its parent,
 *    then once more -> result: 13
 *
 *     13
 *    / \
 *  [8]  17
 *  / \
 * 1  [11]
 *    /
 *   10
 */
template <typename T, typename Node>
tree_iterator<T, Node>& tree_iterator<T, Node>::operator++() {
  if (node_->has_right_child()) {
    node_ = min_child_from(node_->right);
    return *this;
  }
  while (not is_left_child())
    node_ = node_->parent;
  node_ = node_->parent;
  return *this;
}

/// return current, then move to next smallest element
template <typename T, typename Node>
tree_iterator<T, Node> tree_iterator<T, Node>::operator++(int) {
  tree_iterator temp(*this);
  ++(*this);
  return temp;
}

/// move to next biggest element then return
template <typename T, typename Node>
tree_iterator<T, Node>& tree_iterator<T, Node>::operator--() {
  if (node_->has_left_child()) {
    node_ = max_child_from(node_->left);
    return *this;
  }
  while (is_left_child())
    node_ = node_->parent;
  node_ = node_->parent;
  return *this;
}

/// return current, then move to next biggest element
template <typename T, typename Node>
tree_iterator<T, Node> tree_iterator<T, Node>::operator--(int) {
  tree_iterator temp(*this);
  --(*this);
  return temp;
}
}  // namespace ft

#endif  // RBTREE_ITERATOR_OPERATOR_TPP
