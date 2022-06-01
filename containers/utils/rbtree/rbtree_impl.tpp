#ifndef RBTREE_RBTREE_IMPL_TPP
#define RBTREE_RBTREE_IMPL_TPP

#include "rbtree.hpp"

namespace ft {
template <typename T, typename Compare, typename Alloc>
typename rbtree<T, Compare, Alloc>::node_pointer
rbtree<T, Compare, Alloc>::root() const {
  return end_->left;
}

template <typename T, typename Compare, typename Alloc>
typename rbtree<T, Compare, Alloc>::node_pointer*
rbtree<T, Compare, Alloc>::rootPtr() const {
  return &end_->left;
}

template <typename T, typename Compare, typename Alloc>
typename rbtree<T, Compare, Alloc>::node_pointer
rbtree<T, Compare, Alloc>::min_node(node_pointer node) const {
  node_pointer temp = node;
  while (temp->has_left_child())
    temp = temp->left;
  return temp;
}

template <typename T, typename Compare, typename Alloc>
typename rbtree<T, Compare, Alloc>::node_pointer
rbtree<T, Compare, Alloc>::max_node(node_pointer node) const {
  node_pointer temp = node;
  while (temp->has_right_child())
    temp = temp->right;
  return temp;
}

template <typename T, typename Compare, typename Alloc>
typename rbtree<T, Compare, Alloc>::node_pointer
rbtree<T, Compare, Alloc>::create_node(const_reference data) {
  node_pointer temp = node_alloc_.allocate(1);
  node_alloc_.construct(temp, node_type(data));
  return temp;
}

template <typename T, typename Compare, typename Alloc>
typename rbtree<T, Compare, Alloc>::node_pointer
rbtree<T, Compare, Alloc>::next_node(node_pointer node) const {
  if (node->has_right_child())
    return min_node(node->right);
  while (not node->is_left_child())
    node = node->parent;
  return node->parent;
}

template <typename T, typename Compare, typename Alloc>
typename rbtree<T, Compare, Alloc>::node_pointer
rbtree<T, Compare, Alloc>::sibling_node_of(node_pointer node) const {
  return node->is_left_child() ? node->parent->right
                               : node->parent->left;
}

}  // namespace ft

#endif  // RBTREE_RBTREE_IMPL_TPP
