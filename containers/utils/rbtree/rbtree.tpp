#ifndef RBTREE_RBTREE_TPP
#define RBTREE_RBTREE_TPP

#include "rbtree.hpp"

namespace ft {
/// Constructors & Destructor
template <typename T, typename Compare, typename Alloc>
rbtree<T, Compare, Alloc>::rbtree(const compare_type& comp)
    : size_(0),
      alloc_(allocator_type()),
      node_alloc_(node_allocator_type()),
      comp_(comp) {
  end_ = node_alloc_.allocate(1);
  node_alloc_.construct(end_, node_type());
  begin_ = end_;
}

template <typename T, typename Compare, typename Alloc>
rbtree<T, Compare, Alloc>::rbtree(const rbtree& other)
    : size_(0),
      alloc_(other.alloc_),
      node_alloc_(other.node_alloc_),
      comp_(other.comp_) {
  end_ = node_alloc_.allocate(1);
  node_alloc_.construct(end_, node_type());
  begin_ = end_;
  *this  = other;
}

template <typename T, typename Compare, typename Alloc>
rbtree<T, Compare, Alloc>::~rbtree() {
  clear();
  deallocate_node(end_);
}

///  Operators
template <typename T, typename Compare, typename Alloc>
rbtree<T, Compare, Alloc>& rbtree<T, Compare, Alloc>::operator=(
    const rbtree& other) {
  if (this != &other) {
    clear();
    alloc_ = other.alloc_;
    comp_  = other.comp_;
    insert(other.begin(), other.end());
  }
  return (*this);
}

}  // namespace ft

#endif  // RBTREE_RBTREE_TPP
