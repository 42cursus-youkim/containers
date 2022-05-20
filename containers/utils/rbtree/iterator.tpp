#ifndef RBTREE_ITERATOR_TPP
#define RBTREE_ITERATOR_TPP

#include "iterator.hpp"
namespace ft {

/// Constructors & Destructor
template <typename T>
tree_iterator<T>::tree_iterator() {}

template <typename T>
tree_iterator<T>::tree_iterator(const node_pointer base)
    : node_(base) {}

template <typename T>
tree_iterator<T>::tree_iterator(const tree_iterator& other)
    : node_(other.base()) {}

template <typename T>
tree_iterator<T>::tree_iterator(const tree_const_iterator<T>& other)
    : node_(other.base()) {}

template <typename T>
tree_iterator<T>::~tree_iterator() {}

}  // namespace ft

#endif  // RBTREE_ITERATOR_TPP
