#ifndef RBTREE_CONST_ITERATOR_OPERATOR_TPP
#define RBTREE_CONST_ITERATOR_OPERATOR_TPP

#include "const_iterator.hpp"

namespace ft {

/// imitate pointer arithmetic

template <typename T>
typename tree_const_iterator<T>::reference
tree_const_iterator<T>::operator*() const {
  return node_->data;
}

template <typename T>
typename tree_const_iterator<T>::pointer
tree_const_iterator<T>::operator->() const {
  return &node_->data;
}

/// compare iterators
template <typename T>
bool tree_const_iterator<T>::operator==(
    const tree_const_iterator& other) const {
  return node_ == other.node_;
}

template <typename T>
bool tree_const_iterator<T>::operator!=(
    const tree_const_iterator& other) const {
  return node_ != other.node_;
}

template <typename T>
tree_const_iterator<T>& tree_const_iterator<T>::operator=(
    const tree_const_iterator& other) {
  node_ = other.node_;
  return (*this);
}

template <typename T>
tree_const_iterator<T>& tree_const_iterator<T>::operator++() {
  if (node_->has_right_child()) {
    node_ = min_child_from(node_->right);
    return *this;
  }
  while (not is_left_child())
    node_ = node_->parent;
  node_ = node_->parent;
  return *this;
}

template <typename T>
tree_const_iterator<T> tree_const_iterator<T>::operator++(int) {
  tree_const_iterator temp(*this);
  ++(*this);
  return temp;
}

template <typename T>
tree_const_iterator<T>& tree_const_iterator<T>::operator--() {
  if (node_->has_left_child()) {
    node_ = max_child_from(node_->left);
    return *this;
  }
  while (is_left_child())
    node_ = node_->parent;
  node_ = node_->parent;
  return *this;
}

template <typename T>
tree_const_iterator<T> tree_const_iterator<T>::operator--(int) {
  tree_const_iterator temp(*this);
  --(*this);
  return temp;
}

}  // namespace ft

#endif  // RBTREE_CONST_ITERATOR_OPERATOR_TPP
