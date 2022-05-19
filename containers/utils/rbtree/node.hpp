#ifndef RBTREE_NODE_HPP
#define RBTREE_NODE_HPP

#include <memory>
#include <utils/general/nullptr.hpp>

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
  explicit rb_node();
  explicit rb_node(value_type data);
};

}  // namespace ft

#include "node.tpp"

#endif  // RBTREE_NODE_HPP
