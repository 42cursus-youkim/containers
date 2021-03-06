#ifndef RBTREE_RBTREE_MODIFIER_TPP
#define RBTREE_RBTREE_MODIFIER_TPP

#include "rbtree.hpp"

namespace ft {

/// modify
template <typename T, typename Compare, typename Alloc>
void rbtree<T, Compare, Alloc>::erase(iterator pos) {
  remove_node_pointer(pos.base());
}

template <typename T, typename Compare, typename Alloc>
void rbtree<T, Compare, Alloc>::clear() {
  delete_tree(root());
  begin_     = end_;
  size_      = 0;
  end_->left = u_nullptr;
}

template <typename T, typename Compare, typename Alloc>
void rbtree<T, Compare, Alloc>::swap(rbtree& other) {
  std::swap(end_, other.end_);
  std::swap(begin_, other.begin_);
  std::swap(comp_, other.comp_);
  std::swap(alloc_, other.alloc_);
  std::swap(node_alloc_, other.node_alloc_);
  std::swap(size_, other.size_);
}
}  // namespace ft

#endif  // RBTREE_RBTREE_MODIFIER_TPP
