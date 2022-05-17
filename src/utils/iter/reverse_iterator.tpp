#ifndef ITER_REVERSE_ITERATOR_TPP
#define ITER_REVERSE_ITERATOR_TPP

#include "reverse_iterator.hpp"

namespace ft {

/// Constructors & Destructor

/// default constructor
template <typename Iterator>
reverse_iterator<Iterator>::reverse_iterator() : current_(){}

/// initialization constructor
template <typename Iterator>
reverse_iterator<Iterator>::reverse_iterator(iterator_type it) : current_(it){}

/// copy constructor
template <typename Iterator>
template <typename Iter>
reverse_iterator<Iterator>::reverse_iterator(
    const reverse_iterator<Iter>& rev_it)
    : current_(rev_it.base()) {}

/// getters
template <typename Iterator>
typename reverse_iterator<Iterator>::iterator_type
reverse_iterator<Iterator>::base() const {
  return current_;
}

/// operator
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
reverse_iterator<Iterator> reverse_iterator<Iterator>::operator++(int) {
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
reverse_iterator<Iterator> reverse_iterator<Iterator>::operator--(int) {
  reverse_iterator temp(current_);
  ++current_;
  return temp;
}

/// Non-member function overloads

/// relational operators

template <typename Iterator1, typename Iterator2>
bool operator==(const reverse_iterator<Iterator1>& lhs,
                const reverse_iterator<Iterator2>& rhs) {
  return lhs.base() == rhs.base();
}

template <typename Iterator1, typename Iterator2>
bool operator!=(const reverse_iterator<Iterator1>& lhs,
                const reverse_iterator<Iterator2>& rhs) {
  return lhs.base() != rhs.base();
}

template <typename Iterator1, typename Iterator2>
bool operator<(const reverse_iterator<Iterator1>& lhs,
               const reverse_iterator<Iterator2>& rhs) {
  return lhs.base() > rhs.base();
}

template <typename Iterator1, typename Iterator2>
bool operator<=(const reverse_iterator<Iterator1>& lhs,
                const reverse_iterator<Iterator2>& rhs) {
  return lhs.base() >= rhs.base();
}

template <typename Iterator1, typename Iterator2>
bool operator>(const reverse_iterator<Iterator1>& lhs,
               const reverse_iterator<Iterator2>& rhs) {
  return lhs.base() < rhs.base();
}

template <typename Iterator1, typename Iterator2>
bool operator>=(const reverse_iterator<Iterator1>& lhs,
                const reverse_iterator<Iterator2>& rhs) {
  return lhs.base() <= rhs.base();
}

/// addition and subtraction operator

template <typename Iterator>
reverse_iterator<Iterator> operator+(
    typename reverse_iterator<Iterator>::difference_type n,
    const reverse_iterator<Iterator>& rev_it) {
  return reverse_iterator<Iterator>(rev_it.base() - n);
}

template <typename Iterator1, typename Iterator2>
typename reverse_iterator<Iterator1>::difference_type operator-(
    const reverse_iterator<Iterator1>& lhs,
    const reverse_iterator<Iterator2>& rhs) {
  return rhs.base() - lhs.base();
}

}  // namespace ft

#endif  // ITER_REVERSE_ITERATOR_TPP
