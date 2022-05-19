#ifndef ITER_MAP_OPERATOR_TPP
#define ITER_MAP_OPERATOR_TPP

#include "map.hpp"

namespace ft {

template <typename Iterator>
typename map_iterator<Iterator>::reference
map_iterator<Iterator>::operator*() const {
  return *_it;
}

template <typename Iterator>
typename map_iterator<Iterator>::pointer
map_iterator<Iterator>::operator->() const {
  return &(*_it);
}

template <typename Iterator>
map_iterator<Iterator>& map_iterator<Iterator>::operator++() {
  ++_it;
  return *this;
}

template <typename Iterator>
map_iterator<Iterator> map_iterator<Iterator>::operator++(int) {
  map_iterator temp(*this);
  ++(*this);
  return temp;
}

template <typename Iterator>
map_iterator<Iterator>& map_iterator<Iterator>::operator--() {
  --_it;
  return *this;
}

template <typename Iterator>
map_iterator<Iterator> map_iterator<Iterator>::operator--(int) {
  map_iterator temp(*this);
  --(*this);
  return temp;
}

template <typename Iterator>
bool map_iterator<Iterator>::operator==(
    const map_iterator& other) const {
  return this->_it == other._it;
}

template <typename Iterator>
bool map_iterator<Iterator>::operator!=(
    const map_iterator& other) const {
  return this->_it != other._it;
}

}  // namespace ft

#endif  // ITER_MAP_OPERATOR_TPP
