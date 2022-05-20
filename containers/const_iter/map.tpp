#ifndef CONST_ITER_MAP_TPP
#define CONST_ITER_MAP_TPP

#include "map.hpp"

namespace ft {

/// Constructors & Destructor
template <typename Iterator>
map_const_iterator<Iterator>::map_const_iterator() {}

template <typename Iterator>
map_const_iterator<Iterator>::map_const_iterator(const Iterator other)
    : _it(other) {}

template <typename Iterator>
map_const_iterator<Iterator>::map_const_iterator(tree_iterator other)
    : _it(other.base()) {}

template <typename Iterator>
map_const_iterator<Iterator>::~map_const_iterator() {}

/// Copy Assignment Operator
template <typename Iterator>
map_const_iterator<Iterator>& map_const_iterator<Iterator>::operator=(
    const map_const_iterator& other) {
  _it = other._it;
  return (*this);
}

/// Getters
template <typename Iterator>
Iterator map_const_iterator<Iterator>::base() {
  return _it;
}

}  // namespace ft

#endif  // CONST_ITER_MAP_TPP
