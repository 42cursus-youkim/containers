#ifndef RBTREE_CONST_ITERATOR_GETTER_TPP
#define RBTREE_CONST_ITERATOR_GETTER_TPP

#include "const_iterator.hpp"

namespace ft {

template <typename T, typename Node>
typename tree_const_iterator<T, Node>::node_pointer
tree_const_iterator<T, Node>::base() const {
  return node_;
}

template <typename T, typename Node>
typename tree_const_iterator<T, Node>::node_pointer
tree_const_iterator<T, Node>::min_child_from(
    node_pointer node) const {
  while (node->has_left_child())
    node = node->left;
  return node;
}

template <typename T, typename Node>
typename tree_const_iterator<T, Node>::node_pointer
tree_const_iterator<T, Node>::max_child_from(
    node_pointer node) const {
  while (node->has_right_child())
    node = node->right;
  return node;
}

template <typename T, typename Node>
bool tree_const_iterator<T, Node>::is_left_child() const {
  return node_ == node_->parent->left;
}

}  // namespace ft

#endif  // RBTREE_CONST_ITERATOR_GETTER_TPP
