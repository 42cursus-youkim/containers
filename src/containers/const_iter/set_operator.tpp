#ifndef CONST_ITER_SET_OPERATOR_TPP
#define CONST_ITER_SET_OPERATOR_TPP

#include "set.hpp"

namespace ft {

template <typename Iterator>
typename set_const_iterator<Iterator>::reference
set_const_iterator<Iterator>::operator*() const {
  return *_it;
}

template <typename Iterator>
typename set_const_iterator<Iterator>::pointer
set_const_iterator<Iterator>::operator->() const {
  return &(*_it);
}

template <typename Iterator>
set_const_iterator<Iterator>&
set_const_iterator<Iterator>::operator++() {
  ++_it;
  return *this;
}

template <typename Iterator>
set_const_iterator<Iterator> set_const_iterator<Iterator>::operator++(
    int) {
  set_const_iterator temp(*this);
  ++(*this);
  return temp;
}

template <typename Iterator>
set_const_iterator<Iterator>&
set_const_iterator<Iterator>::operator--() {
  --_it;
  return *this;
}

template <typename Iterator>
set_const_iterator<Iterator> set_const_iterator<Iterator>::operator--(
    int) {
  set_const_iterator temp(*this);
  --(*this);
  return temp;
}

template <typename Iterator>
bool set_const_iterator<Iterator>::operator==(
    const set_const_iterator& other) const {
  return this->_it == other._it;
}

template <typename Iterator>
bool set_const_iterator<Iterator>::operator!=(
    const set_const_iterator& other) const {
  return this->_it != other._it;
}
}  // namespace ft
#endif // CONST_ITER_SET_OPERATOR_TPP
