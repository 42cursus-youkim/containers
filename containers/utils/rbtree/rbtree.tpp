#ifndef RBTREE_RBTREE_TPP
#define RBTREE_RBTREE_TPP

#include "rbtree.hpp"

namespace ft {
/// Constructors & Destructor
template <typename T, typename Compare>
rbtree<T, Compare>::rbtree(const compare_type& comp)
    : size_(0), alloc_(allocator_type()), comp_(comp) {
  end_ = alloc_.allocate(1);
  alloc_.construct(end_, node_type());
  begin_ = end_;
}

template <typename T, typename Compare>
rbtree<T, Compare>::rbtree(const rbtree& other)
    : size_(0), alloc_(other.alloc_), comp_(other.comp_) {
  end_ = alloc_.allocate(1);
  alloc_.construct(end_, node_type());
  begin_ = end_;
  *this  = other;
}

template <typename T, typename Compare>
rbtree<T, Compare>::~rbtree() {
  clear();
  deallocate_node(end_);
}

///  Operators
template <typename T, typename Compare>
rbtree<T, Compare>& rbtree<T, Compare>::operator=(
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
