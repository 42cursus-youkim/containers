#ifndef RBTREE_NODE_PROPERTY_TPP
#define RBTREE_NODE_PROPERTY_TPP

#include "node.hpp"

namespace ft {

template <typename T, typename Allocator>
bool rb_node<T, Allocator>::has_both_child(node_type type) const {
  return has_left_child(type) and has_right_child(type);
}

template <typename T, typename Allocator>
bool rb_node<T, Allocator>::has_left_child(node_type type) const {
  switch (type) {
    case NON_NIL:
      return left != u_nullptr;
    case BLACK:
      return left == u_nullptr or left->is_black;
    case RED:
      return left != u_nullptr and left->is_red();
  }
}

template <typename T, typename Allocator>
bool rb_node<T, Allocator>::has_right_child(node_type type) const {
  switch (type) {
    case NON_NIL:
      return right != u_nullptr;
    case BLACK:
      return right == u_nullptr or right->is_black;
    case RED:
      return right != u_nullptr and right->is_red();
  }
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
