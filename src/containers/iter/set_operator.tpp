#ifndef ITER_SET_OPERATOR_TPP
#define ITER_SET_OPERATOR_TPP

#include "set.hpp"

namespace ft {

template <typename Iterator>
typename set_iterator<Iterator>::reference
set_iterator<Iterator>::operator*() const {
  return *_it;
}

template <typename Iterator>
typename set_iterator<Iterator>::pointer
set_iterator<Iterator>::operator->() const {
  return &(*_it);
}

template <typename Iterator>
set_iterator<Iterator>& set_iterator<Iterator>::operator++() {
  ++_it;
  return *this;
}

template <typename Iterator>
set_iterator<Iterator> set_iterator<Iterator>::operator++(int) {
  set_iterator temp(*this);
  ++(*this);
  return temp;
}

template <typename Iterator>
set_iterator<Iterator>& set_iterator<Iterator>::operator--() {
  --_it;
  return *this;
}

template <typename Iterator>
set_iterator<Iterator> set_iterator<Iterator>::operator--(int) {
  set_iterator temp(*this);
  --(*this);
  return temp;
}

template <typename Iterator>
bool set_iterator<Iterator>::operator==(
    const set_iterator& other) const {
  return this->_it == other._it;
}

template <typename Iterator>
bool set_iterator<Iterator>::operator!=(
    const set_iterator& other) const {
  return this->_it != other._it;
}

}  // namespace ft

#endif  // ITER_SET_OPERATOR_TPP
