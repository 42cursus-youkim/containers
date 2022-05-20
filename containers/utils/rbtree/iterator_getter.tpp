#ifndef RBTREE_ITERATOR_GETTER_TPP
#define RBTREE_ITERATOR_GETTER_TPP

#include "iterator.hpp"

namespace ft {
/// return the base pointer of the iterator
template <typename T>
typename tree_iterator<T>::node_pointer tree_iterator<T>::base()
    const {
  return node_;
}

/// move self to the minimum node from given node
template <typename T>
typename tree_iterator<T>::node_pointer
tree_iterator<T>::min_child_from(node_pointer node) const {
  while (node->has_left_child())
    node = node->left;
  return node;
}

/// move self to the maximum node from given node
template <typename T>
typename tree_iterator<T>::node_pointer
tree_iterator<T>::max_child_from(node_pointer node) const {
  while (node->has_right_child())
    node = node->right;
  return node;
}

/// check if self is left child of its parent
template <typename T>
bool tree_iterator<T>::is_left_child() const {
  return node_ == node_->parent->left;
}
}  // namespace ft

#endif  // RBTREE_ITERATOR_GETTER_TPP
