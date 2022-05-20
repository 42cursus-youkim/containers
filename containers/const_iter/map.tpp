#ifndef CONST_ITER_MAP_TPP
#define CONST_ITER_MAP_TPP

#include "map.hpp"

namespace ft {

/// Constructors & Destructor
template <typename Iterator>
map_const_iterator<Iterator>::map_const_iterator() {}

template <typename Iterator>
map_const_iterator<Iterator>::map_const_iterator(const Iterator other)
    : it_(other) {}

template <typename Iterator>
map_const_iterator<Iterator>::map_const_iterator(tree_iterator other)
    : it_(other.base()) {}

template <typename Iterator>
map_const_iterator<Iterator>::~map_const_iterator() {}

/// Copy Assignment Operator
template <typename Iterator>
map_const_iterator<Iterator>& map_const_iterator<Iterator>::operator=(
    const map_const_iterator& other) {
  it_ = other.it_;
  return (*this);
}

/// Getters
template <typename Iterator>
Iterator map_const_iterator<Iterator>::base() {
  return it_;
}

}  // namespace ft

#endif  // CONST_ITER_MAP_TPP
