#ifndef CONST_ITER_SET_TPP
#define CONST_ITER_SET_TPP

#include "set.hpp"

namespace ft {

/// Constructors & Destructor
template <typename Iterator>
set_const_iterator<Iterator>::set_const_iterator() {}

template <typename Iterator>
set_const_iterator<Iterator>::set_const_iterator(const Iterator other)
    : it_(other) {}

template <typename Iterator>
set_const_iterator<Iterator>::set_const_iterator(tree_iterator other)
    : it_(other.base()) {}

template <typename Iterator>
set_const_iterator<Iterator>::~set_const_iterator() {}

/// Copy Assignment Operator
template <typename Iterator>
set_const_iterator<Iterator>& set_const_iterator<Iterator>::operator=(
    const set_const_iterator& other) {
  it_ = other.it_;
  return (*this);
}

/// Getters
template <typename Iterator>
Iterator set_const_iterator<Iterator>::base() const {
  return it_;
}

}  // namespace ft

#endif  // CONST_ITER_SET_TPP
