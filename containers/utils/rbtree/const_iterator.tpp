#ifndef RBTREE_CONST_ITERATOR_TPP
#define RBTREE_CONST_ITERATOR_TPP

#include "const_iterator.hpp"

namespace ft {

/// Constructors & Destructor
template <typename T>
tree_const_iterator<T>::tree_const_iterator() {}

template <typename T>
tree_const_iterator<T>::tree_const_iterator(const node_pointer other)
    : node_(other) {}

template <typename T>
tree_const_iterator<T>::tree_const_iterator(
    const tree_const_iterator& other)
    : node_(other.base()) {}

template <typename T>
tree_const_iterator<T>::tree_const_iterator(
    const tree_iterator<T>& other)
    : node_(other.base()) {}

template <typename T>
tree_const_iterator<T>::~tree_const_iterator() {}

}  // namespace ft

#endif  // RBTREE_CONST_ITERATOR_TPP
