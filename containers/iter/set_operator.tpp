#ifndef ITER_SET_OPERATOR_TPP
#define ITER_SET_OPERATOR_TPP

#include "set.hpp"

namespace ft {

template <typename Iterator>
typename set_iterator<Iterator>::reference
set_iterator<Iterator>::operator*() const {
  return *it_;
}

template <typename Iterator>
typename set_iterator<Iterator>::pointer
set_iterator<Iterator>::operator->() const {
  return &(*it_);
}

template <typename Iterator>
set_iterator<Iterator>& set_iterator<Iterator>::operator++() {
  ++it_;
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
  --it_;
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
  return this->it_ == other.it_;
}

template <typename Iterator>
bool set_iterator<Iterator>::operator!=(
    const set_iterator& other) const {
  return this->it_ != other.it_;
}

}  // namespace ft

#endif  // ITER_SET_OPERATOR_TPP
