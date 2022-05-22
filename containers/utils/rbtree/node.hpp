#ifndef RBTREE_NODE_HPP
#define RBTREE_NODE_HPP

#include <memory>

namespace ft {

enum node_type { NON_NIL, BLACK, RED };

template <typename T, typename Allocator = std::allocator<T> >
struct rb_node {
  typedef T        value_type;
  typedef rb_node* node_pointer;

  value_type       data;
  bool             is_black;
  node_pointer     left, right, parent;

  /// Constructor
  explicit rb_node();
  explicit rb_node(value_type data);

  /// Property
  bool has_both_child(node_type type = NON_NIL) const;
  bool has_left_child(node_type type = NON_NIL) const;
  bool has_right_child(node_type type = NON_NIL) const;
  bool is_left_child() const;
  bool is_right_child() const;
  bool is_red() const;
};

}  // namespace ft

#include "node.tpp"
#include "node_property.tpp"

#endif  // RBTREE_NODE_HPP
