#ifndef ITER_SET_TPP
#define ITER_SET_TPP

#include "set.hpp"

namespace ft {
template <typename Iterator>
set_iterator<Iterator>::set_iterator() {}

template <typename Iterator>
set_iterator<Iterator>::set_iterator(const Iterator other)
    : _it(other) {}

template <typename Iterator>
set_iterator<Iterator>::set_iterator(const_iterator other)
    : _it(other.base()) {}

template <typename Iterator>
set_iterator<Iterator>::~set_iterator() {}

template <typename Iterator>
set_iterator<Iterator>& set_iterator<Iterator>::operator=(
    const set_iterator& other) {
  _it = other._it;
  return (*this);
}
}  // namespace ft

#endif  // ITER_SET_TPP
