#ifndef RBTREE_RBTREE_IMPL_TPP
#define RBTREE_RBTREE_IMPL_TPP

#include "rbtree.hpp"

namespace ft {
template <typename T, typename Compare>
typename rbtree<T, Compare>::node_pointer rbtree<T, Compare>::root()
    const {
  return end_->left;
}

template <typename T, typename Compare>
typename rbtree<T, Compare>::node_pointer*
rbtree<T, Compare>::rootPtr() const {
  return &end_->left;
}

template <typename T, typename Compare>
typename rbtree<T, Compare>::node_pointer
rbtree<T, Compare>::min_node(node_pointer node) const {
  node_pointer temp = node;
  while (temp->has_left_value())
    temp = temp->left;
  return temp;
}

template <typename T, typename Compare>
typename rbtree<T, Compare>::node_pointer
rbtree<T, Compare>::max_node(node_pointer node) const {
  node_pointer temp = node;
  while (temp->has_right_value())
    temp = temp->right;
  return temp;
}

template <typename T, typename Compare>
typename rbtree<T, Compare>::node_pointer
rbtree<T, Compare>::create_node(const_reference data) {
  node_pointer temp = alloc_.allocate(1);
  alloc_.construct(temp, node_type(data));
  return temp;
}

template <typename T, typename Compare>
typename rbtree<T, Compare>::node_pointer
rbtree<T, Compare>::next_node(node_pointer node) const {
  if (node->has_right_value())
    return min_node(node->right);
  while (not node->is_left_child())
    node = node->parent;
  return node->parent;
}

}  // namespace ft

#endif  // RBTREE_RBTREE_IMPL_TPP
