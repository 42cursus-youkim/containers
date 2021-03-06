#ifndef ITER_MAP_TPP
#define ITER_MAP_TPP

#include "map.hpp"

namespace ft {

/// Constructors & Destructor
template <typename Iterator>
map_iterator<Iterator>::map_iterator() {}

template <typename Iterator>
map_iterator<Iterator>::map_iterator(const Iterator other)
    : it_(other) {}

template <typename Iterator>
map_iterator<Iterator>::~map_iterator() {}

/// Assignment Operator
template <typename Iterator>
map_iterator<Iterator>& map_iterator<Iterator>::operator=(
    const map_iterator& other) {
  it_ = other.it_;
  return (*this);
}

/// Getter
template <typename Iterator>
Iterator map_iterator<Iterator>::base() {
  return it_;
}

}  // namespace ft

#endif  // ITER_MAP_TPP
