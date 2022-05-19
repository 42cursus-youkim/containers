#ifndef ITER_REVERSE_ITERATOR_OPERATOR_TPP
#define ITER_REVERSE_ITERATOR_OPERATOR_TPP

#include "reverse_iterator.hpp"

namespace ft {

template <typename Iterator>
typename reverse_iterator<Iterator>::reference
reverse_iterator<Iterator>::operator*() const {
  Iterator temp(current_);
  return *--temp;
}

template <typename Iterator>
typename reverse_iterator<Iterator>::pointer
reverse_iterator<Iterator>::operator->() const {
  return &(operator*());
}

template <typename Iterator>
typename reverse_iterator<Iterator>::reference
reverse_iterator<Iterator>::operator[](difference_type n) const {
  return current_[-1 - n];
}

template <typename Iterator>
reverse_iterator<Iterator> reverse_iterator<Iterator>::operator+(
    difference_type n) const {
  return reverse_iterator(current_ - n);
}

template <typename Iterator>
reverse_iterator<Iterator> reverse_iterator<Iterator>::operator-(
    difference_type n) const {
  return reverse_iterator(current_ + n);
}

template <typename Iterator>
reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator+=(
    difference_type n) {
  current_ -= n;
  return *this;
}

template <typename Iterator>
reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator-=(
    difference_type n) {
  current_ += n;
  return *this;
}

template <typename Iterator>
reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator++() {
  --current_;
  return *this;
}

template <typename Iterator>
reverse_iterator<Iterator> reverse_iterator<Iterator>::operator++(
    int) {
  reverse_iterator temp(current_);
  --current_;
  return temp;
}

template <typename Iterator>
reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator--() {
  ++current_;
  return *this;
}

template <typename Iterator>
reverse_iterator<Iterator> reverse_iterator<Iterator>::operator--(
    int) {
  reverse_iterator temp(current_);
  ++current_;
  return temp;
}
}  // namespace ft

#endif // ITER_REVERSE_ITERATOR_OPERATOR_TPP
