#ifndef RBTREE_RBTREE_INSERT_TPP
#define RBTREE_RBTREE_INSERT_TPP

#include "rbtree.hpp"

namespace ft {

template <typename T, typename Compare, typename Alloc>
pair<typename rbtree<T, Compare, Alloc>::iterator, bool>
rbtree<T, Compare, Alloc>::insert(const_reference data) {
  node_pointer  Parent;
  node_pointer& dest     = where_to_attach(Parent, data);
  node_pointer  ret      = dest;
  bool          inserted = false;

  if (dest == u_nullptr) {
    node_pointer new_node = create_node(data);
    dest                  = new_node;
    ret                   = dest;
    dest->parent          = Parent;
    if (begin_->has_left_child())
      begin_ = begin_->left;
    rebalance_tree(new_node);
    inserted = true;
    ++size_;
  }
  return pair<iterator, bool>(iterator(ret), inserted);
}

template <typename T, typename Compare, typename Alloc>
typename rbtree<T, Compare, Alloc>::iterator
rbtree<T, Compare, Alloc>::insert(iterator        from,
                                  const_reference data) {
  node_pointer  Parent;
  node_pointer  dummy;
  node_pointer& dest = where_to_attach(from, Parent, dummy, data);
  node_pointer  ret  = dest;

  if (dest == u_nullptr) {
    node_pointer new_node = create_node(data);
    dest                  = new_node;
    ret                   = dest;
    dest->parent          = Parent;
    if (begin_->has_left_child())
      begin_ = begin_->left;
    rebalance_tree(new_node);
    ++size_;
  }
  return iterator(ret);
}

template <typename T, typename Compare, typename Alloc>
template <typename InputIterator>
void rbtree<T, Compare, Alloc>::insert(InputIterator first,
                                       InputIterator last) {
  for (; first != last; ++first)
    insert(*first);
}

}  // namespace ft

#endif  // RBTREE_RBTREE_INSERT_TPP
