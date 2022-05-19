#ifndef RBTREE_NODE_TPP
#define RBTREE_NODE_TPP

#include "node.hpp"

namespace ft {
template <typename T, typename Allocator>
rb_node<T, Allocator>::rb_node() {
  this->is_black = true;
  this->left = this->right = this->parent = u_nullptr;
}

template <typename T, typename Allocator>
rb_node<T, Allocator>::rb_node(value_type data) {
  this->data     = data;
  this->is_black = false;
  this->left = this->right = this->parent = u_nullptr;
}
}  // namespace ft

#endif // RBTREE_NODE_TPP
