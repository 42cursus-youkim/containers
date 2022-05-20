#ifndef RBTREE_ITERATOR_OPERATOR_TPP
#define RBTREE_ITERATOR_OPERATOR_TPP

#include "iterator.hpp"

namespace ft {
template <typename T>
typename tree_iterator<T>::reference tree_iterator<T>::operator*()
    const {
  return node_->data;
}

template <typename T>
typename tree_iterator<T>::pointer tree_iterator<T>::operator->()
    const {
  return &node_->data;
}

template <typename T>
bool tree_iterator<T>::operator==(const tree_iterator& other) const {
  return node_ == other.node_;
}

template <typename T>
bool tree_iterator<T>::operator!=(const tree_iterator& other) const {
  return node_ != other.node_;
}

template <typename T>
tree_iterator<T>& tree_iterator<T>::operator=(
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
template <typename T>
tree_iterator<T>& tree_iterator<T>::operator++() {
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
template <typename T>
tree_iterator<T> tree_iterator<T>::operator++(int) {
  tree_iterator temp(*this);
  ++(*this);
  return temp;
}

/// move to next biggest element then return
template <typename T>
tree_iterator<T>& tree_iterator<T>::operator--() {
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
template <typename T>
tree_iterator<T> tree_iterator<T>::operator--(int) {
  tree_iterator temp(*this);
  --(*this);
  return temp;
}
}  // namespace ft

#endif  // RBTREE_ITERATOR_OPERATOR_TPP
