#ifndef RBTREE_NODE_TPP
#define RBTREE_NODE_TPP

#include <utils/general/nullptr.hpp>
#include "node.hpp"

namespace ft {
template <typename T, typename Allocator>
rb_node<T, Allocator>::rb_node()
    : is_black(true),
      left(u_nullptr),
      right(u_nullptr),
      parent(u_nullptr) {}

template <typename T, typename Allocator>
rb_node<T, Allocator>::rb_node(value_type data)
    : data(data),
      is_black(false),
      left(u_nullptr),
      right(u_nullptr),
      parent(u_nullptr) {}

}  // namespace ft

#endif  // RBTREE_NODE_TPP
