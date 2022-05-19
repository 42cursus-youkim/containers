#ifndef RBTREE_ITERATOR_TPP
#define RBTREE_ITERATOR_TPP

#include "iterator.hpp"
namespace ft {

/// Constructors & Destructor
template <typename T, typename Node>
tree_iterator<T, Node>::tree_iterator() {}

template <typename T, typename Node>
tree_iterator<T, Node>::tree_iterator(const node_pointer other)
    : node_(other) {}

template <typename T, typename Node>
tree_iterator<T, Node>::tree_iterator(const tree_iterator& other)
    : node_(other.base()) {}

template <typename T, typename Node>
tree_iterator<T, Node>::tree_iterator(const const_iterator& other)
    : node_(other.base()) {}

template <typename T, typename Node>
tree_iterator<T, Node>::~tree_iterator() {}

}  // namespace ft

#endif  // RBTREE_ITERATOR_TPP
