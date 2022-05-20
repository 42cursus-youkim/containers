#ifndef RBTREE_NODE_HPP
#define RBTREE_NODE_HPP

#include <memory>

namespace ft {

template <typename T, typename Allocator = std::allocator<T> >
class rb_node {
 public:
  typedef T        value_type;
  typedef rb_node* node_pointer;

  value_type       data;
  bool             is_black;
  node_pointer     left, right, parent;

 public:
  /// Constructor
  explicit rb_node();
  explicit rb_node(value_type data);

  /// Property
  bool has_left_child() const;
  bool has_right_child() const;
  bool is_left_child() const;
};

}  // namespace ft

#include "node.tpp"
#include "node_property.tpp"

#endif  // RBTREE_NODE_HPP
