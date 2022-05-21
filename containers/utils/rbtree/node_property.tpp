#ifndef RBTREE_NODE_PROPERTY_TPP
#define RBTREE_NODE_PROPERTY_TPP

#include "node.hpp"

namespace ft {

template <typename T, typename Allocator>
bool rb_node<T, Allocator>::has_left_child() const {
  return left != u_nullptr;
}

template <typename T, typename Allocator>
bool rb_node<T, Allocator>::has_right_child() const {
  return right != u_nullptr;
}

template <typename T, typename Allocator>
bool rb_node<T, Allocator>::is_left_child() const {
  return this == this->parent->left;
}

template <typename T, typename Allocator>
bool rb_node<T, Allocator>::is_red() const {
  return not this->is_black;
}

}  // namespace ft

#endif  // RBTREE_NODE_PROPERTY_TPP
