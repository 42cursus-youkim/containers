#ifndef RBTREE_CONST_ITERATOR_OPERATOR_TPP
#define RBTREE_CONST_ITERATOR_OPERATOR_TPP

#include "const_iterator.hpp"

namespace ft {

template <typename T, typename Node>
typename tree_const_iterator<T, Node>::reference
tree_const_iterator<T, Node>::operator*() const {
  return node_->data;
}

template <typename T, typename Node>
typename tree_const_iterator<T, Node>::pointer
tree_const_iterator<T, Node>::operator->() const {
  return &node_->data;
}

template <typename T, typename Node>
bool tree_const_iterator<T, Node>::operator==(
    const tree_const_iterator& other) const {
  return node_ == other.node_;
}

template <typename T, typename Node>
bool tree_const_iterator<T, Node>::operator!=(
    const tree_const_iterator& other) const {
  return node_ != other.node_;
}

template <typename T, typename Node>
tree_const_iterator<T, Node>& tree_const_iterator<T, Node>::operator=(
    const tree_const_iterator& other) {
  node_ = other.node_;
  return (*this);
}

template <typename T, typename Node>
tree_const_iterator<T, Node>&
tree_const_iterator<T, Node>::operator++() {
  if (node_->has_right_child()) {
    tree_min(node_->right);
    return *this;
  }
  while (!tree_is_left_child())
    node_ = node_->parent;
  node_ = node_->parent;
  return *this;
}

template <typename T, typename Node>
tree_const_iterator<T, Node> tree_const_iterator<T, Node>::operator++(
    int) {
  tree_const_iterator temp(*this);
  ++(*this);
  return temp;
}

template <typename T, typename Node>
tree_const_iterator<T, Node>&
tree_const_iterator<T, Node>::operator--() {
  if (node_->has_left_child()) {
    tree_max(node_->left);
    return *this;
  }
  while (tree_is_left_child())
    node_ = node_->parent;
  node_ = node_->parent;
  return *this;
}

template <typename T, typename Node>
tree_const_iterator<T, Node> tree_const_iterator<T, Node>::operator--(
    int) {
  tree_const_iterator temp(*this);
  --(*this);
  return temp;
}

}  // namespace ft

#endif  // RBTREE_CONST_ITERATOR_OPERATOR_TPP
