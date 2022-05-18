#ifndef RBTREE_ITERATOR_TPP
#define RBTREE_ITERATOR_TPP

#include "iterator.hpp"
namespace ft {
/// Constructors & Destructor
template <typename T, typename Node>
tree_iterator<T, Node>::tree_iterator() {}

template <typename T, typename Node>
tree_iterator<T, Node>::tree_iterator(const node_pointer other)
    : node_(other) {}

template <typename T, typename Node>
tree_iterator<T, Node>::tree_iterator(const tree_iterator& other)
    : node_(other.base()) {}

template <typename T, typename Node>
tree_iterator<T, Node>::tree_iterator(const const_iterator& other)
    : node_(other.base()) {}

template <typename T, typename Node>
tree_iterator<T, Node>::~tree_iterator() {}

/// Getters/Setters

template <typename T, typename Node>
typename tree_iterator<T, Node>::node_pointer
tree_iterator<T, Node>::base() const {
  return node_;
}

template <typename T, typename Node>
void tree_iterator<T, Node>::tree_min(node_pointer node) {
  while (node->left != u_nullptr)
    node = node->left;
  node_ = node;
}

template <typename T, typename Node>
void tree_iterator<T, Node>::tree_max(node_pointer node) {
  while (node->right != u_nullptr)
    node = node->right;
  node_ = node;
}

template <typename T, typename Node>
bool tree_iterator<T, Node>::tree_is_left_child() const {
  return node_ == node_->parent->left;
}

/// Operators
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

template <typename T, typename Node>
tree_iterator<T, Node>& tree_iterator<T, Node>::operator++() {
  if (node_->right != u_nullptr) {
    tree_min(node_->right);
    return *this;
  }
  while (!tree_is_left_child())
    node_ = node_->parent;
  node_ = node_->parent;
  return *this;
}

template <typename T, typename Node>
tree_iterator<T, Node> tree_iterator<T, Node>::operator++(int) {
  tree_iterator temp(*this);
  ++(*this);
  return temp;
}

template <typename T, typename Node>
tree_iterator<T, Node>& tree_iterator<T, Node>::operator--() {
  if (node_->left != u_nullptr) {
    tree_max(node_->left);
    return *this;
  }
  while (tree_is_left_child())
    node_ = node_->parent;
  node_ = node_->parent;
  return *this;
}

template <typename T, typename Node>
tree_iterator<T, Node> tree_iterator<T, Node>::operator--(int) {
  tree_iterator temp(*this);
  --(*this);
  return temp;
}

}  // namespace ft

#endif  // RBTREE_ITERATOR_TPP
