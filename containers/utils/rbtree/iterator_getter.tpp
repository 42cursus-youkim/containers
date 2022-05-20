#ifndef RBTREE_ITERATOR_GETTER_TPP
#define RBTREE_ITERATOR_GETTER_TPP

#include "iterator.hpp"

namespace ft {
/// return the base pointer of the iterator
template <typename T, typename Node>
typename tree_iterator<T, Node>::node_pointer
tree_iterator<T, Node>::base() const {
  return node_;
}

/// move self to the minimum node from given node
template <typename T, typename Node>
void tree_iterator<T, Node>::go_to_min_from(node_pointer node) {
  while (node->has_left_value())
    node = node->left;
  node_ = node;
}

/// move self to the maximum node from given node
template <typename T, typename Node>
void tree_iterator<T, Node>::go_to_max_from(node_pointer node) {
  while (node->has_right_value())
    node = node->right;
  node_ = node;
}

/// check if self is left child of its parent
template <typename T, typename Node>
bool tree_iterator<T, Node>::is_left_child() const {
  return node_ == node_->parent->left;
}
}  // namespace ft

#endif  // RBTREE_ITERATOR_GETTER_TPP
