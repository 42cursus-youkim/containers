#ifndef RBTREE_NODE_PROPERTY_TPP
#define RBTREE_NODE_PROPERTY_TPP

#include "node.hpp"

namespace ft {

template <typename T, typename Allocator>
bool rb_node<T, Allocator>::has_left_value() const {
  return left != u_nullptr;
}

template <typename T, typename Allocator>
bool rb_node<T, Allocator>::has_right_value() const {
  return right != u_nullptr;
}

template <typename T, typename Allocator>
bool rb_node<T, Allocator>::is_left_child() const {
  return this == this->parent->left;
}

}  // namespace ft

#endif  // RBTREE_NODE_PROPERTY_TPP
