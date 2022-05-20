#ifndef RBTREE_CONST_ITERATOR_TPP
#define RBTREE_CONST_ITERATOR_TPP

#include "const_iterator.hpp"

namespace ft {

/// Constructors & Destructor
template <typename T, typename Node>
tree_const_iterator<T, Node>::tree_const_iterator() {}

template <typename T, typename Node>
tree_const_iterator<T, Node>::tree_const_iterator(
    const node_pointer other)
    : node_(other) {}

template <typename T, typename Node>
tree_const_iterator<T, Node>::tree_const_iterator(
    const tree_const_iterator& other)
    : node_(other.base()) {}

template <typename T, typename Node>
tree_const_iterator<T, Node>::tree_const_iterator(
    const tree_iterator& other)
    : node_(other.base()) {}

template <typename T, typename Node>
tree_const_iterator<T, Node>::~tree_const_iterator() {}

}  // namespace ft

#endif  // RBTREE_CONST_ITERATOR_TPP
