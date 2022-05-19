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
void tree_const_iterator<T, Node>::tree_min(node_pointer node) {
  while (node->left != u_nullptr)
    node = node->left;
  node_ = node;
}

template <typename T, typename Node>
void tree_const_iterator<T, Node>::tree_max(node_pointer node) {
  while (node->right != u_nullptr)
    node = node->right;
  node_ = node;
}

template <typename T, typename Node>
bool tree_const_iterator<T, Node>::tree_is_left_child() const {
  return node_ == node_->parent->left;
}

}  // namespace ft

#endif // RBTREE_CONST_ITERATOR_GETTER_TPP
