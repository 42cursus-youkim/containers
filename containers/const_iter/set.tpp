#ifndef CONST_ITER_SET_TPP
#define CONST_ITER_SET_TPP

#include "set.hpp"

namespace ft {

/// Constructors & Destructor
template <typename Iterator>
set_const_iterator<Iterator>::set_const_iterator() {}

template <typename Iterator>
set_const_iterator<Iterator>::set_const_iterator(const Iterator other)
    : _it(other) {}

template <typename Iterator>
set_const_iterator<Iterator>::set_const_iterator(
    non_const_iterator other)
    : _it(other.base()) {}

template <typename Iterator>
set_const_iterator<Iterator>::~set_const_iterator() {}

/// Copy Assignment Operator
template <typename Iterator>
set_const_iterator<Iterator>& set_const_iterator<Iterator>::operator=(
    const set_const_iterator& other) {
  _it = other._it;
  return (*this);
}

/// Getters
template <typename Iterator>
Iterator set_const_iterator<Iterator>::base() const {
  return _it;
}

}  // namespace ft

#endif  // CONST_ITER_SET_TPP
