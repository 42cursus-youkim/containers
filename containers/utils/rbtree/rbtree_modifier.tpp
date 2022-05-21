#ifndef RBTREE_RBTREE_MODIFIER_TPP
#define RBTREE_RBTREE_MODIFIER_TPP

#include "rbtree.hpp"

namespace ft {
template <typename T, typename Compare>
pair<typename rbtree<T, Compare>::iterator, bool>
rbtree<T, Compare>::insert(const_reference data) {
  node_pointer  Parent;
  node_pointer& dest     = find_pos(Parent, data);
  node_pointer  ret      = dest;
  bool          inserted = false;
  if (dest == u_nullptr) {
    node_pointer new_node = create_node(data);
    dest                  = new_node;
    ret                   = dest;
    dest->parent          = Parent;
    if (begin_->has_left_child())
      begin_ = begin_->left;
    rebuild_insert(new_node);
    inserted = true;
    ++size_;
  }
  return pair<iterator, bool>(iterator(ret), inserted);
}

template <typename T, typename Compare>
typename rbtree<T, Compare>::iterator rbtree<T, Compare>::insert(
    iterator        hint,
    const_reference data) {
  node_pointer  Parent;
  node_pointer  dummy;
  node_pointer& dest = find_pos(hint, Parent, dummy, data);
  node_pointer  ret  = dest;

  if (dest == u_nullptr) {
    node_pointer new_node = create_node(data);
    dest                  = new_node;
    ret                   = dest;
    dest->parent          = Parent;
    if (begin_->has_left_child())
      begin_ = begin_->left;
    rebuild_insert(new_node);
    ++size_;
  }
  return iterator(ret);
}

template <typename T, typename Compare>
template <typename InputIterator>
void rbtree<T, Compare>::insert(InputIterator first,
                                InputIterator last) {
  for (; first != last; ++first)
    insert(*first);
}

/// modify
template <typename T, typename Compare>
void rbtree<T, Compare>::erase(iterator pos) {
  remove_node_pointer(pos.base());
}

template <typename T, typename Compare>
void rbtree<T, Compare>::clear() {
  delete_tree(root());
  begin_     = end_;
  size_      = 0;
  end_->left = u_nullptr;
}

template <typename T, typename Compare>
void rbtree<T, Compare>::swap(rbtree& other) {
  std::swap(end_, other.end_);
  std::swap(begin_, other.begin_);
  std::swap(comp_, other.comp_);
  std::swap(alloc_, other.alloc_);
  std::swap(size_, other.size_);
}
}  // namespace ft

#endif  // RBTREE_RBTREE_MODIFIER_TPP
