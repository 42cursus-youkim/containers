#ifndef CONST_ITER_MAP_OPERATOR_TPP
#define CONST_ITER_MAP_OPERATOR_TPP

#include "map.hpp"

namespace ft {

template <typename Iterator>
typename map_const_iterator<Iterator>::reference
map_const_iterator<Iterator>::operator*() const {
  return *_it;
}

template <typename Iterator>
typename map_const_iterator<Iterator>::pointer
map_const_iterator<Iterator>::operator->() const {
  return &(*_it);
}

template <typename Iterator>
map_const_iterator<Iterator>&
map_const_iterator<Iterator>::operator++() {
  ++_it;
  return *this;
}

template <typename Iterator>
map_const_iterator<Iterator> map_const_iterator<Iterator>::operator++(
    int) {
  map_const_iterator temp(*this);
  ++(*this);
  return temp;
}

template <typename Iterator>
map_const_iterator<Iterator>&
map_const_iterator<Iterator>::operator--() {
  --_it;
  return *this;
}

template <typename Iterator>
map_const_iterator<Iterator> map_const_iterator<Iterator>::operator--(
    int) {
  map_const_iterator temp(*this);
  --(*this);
  return temp;
}

template <typename Iterator>
bool map_const_iterator<Iterator>::operator==(
    const map_const_iterator& other) const {
  return this->_it == other._it;
}

template <typename Iterator>
bool map_const_iterator<Iterator>::operator!=(
    const map_const_iterator& other) const {
  return this->_it != other._it;
}

}  // namespace ft

#endif  // CONST_ITER_MAP_OPERATOR_TPP
