#ifndef ITER_REVERSE_ITERATOR_TPP
#define ITER_REVERSE_ITERATOR_TPP

#include "reverse_iterator.hpp"

namespace ft {

/// relational operators use inverted base iterator comparison

template <class Iterator>
bool operator==(const reverse_iterator<Iterator>& lhs,
                const reverse_iterator<Iterator>& rhs) {
  return lhs.base() == rhs.base();
}

template <class Iterator>
bool operator!=(const reverse_iterator<Iterator>& lhs,
                const reverse_iterator<Iterator>& rhs) {
  return lhs != rhs;
}

template <class Iterator>
bool operator<(const reverse_iterator<Iterator>& lhs,
               const reverse_iterator<Iterator>& rhs) {
  return rhs.base() > lhs.base();
}

template <class Iterator>
bool operator<=(const reverse_iterator<Iterator>& lhs,
                const reverse_iterator<Iterator>& rhs) {
  return rhs.base() >= lhs.base();
}

template <class Iterator>
bool operator>(const reverse_iterator<Iterator>& lhs,
               const reverse_iterator<Iterator>& rhs) {
  return rhs.base() < lhs.base();
}

template <class Iterator>
bool operator>=(const reverse_iterator<Iterator>& lhs,
                const reverse_iterator<Iterator>& rhs) {
  return rhs.base() <= lhs.base();
}

/// arithmetic operators

template <class Iterator>
reverse_iterator<Iterator> operator+(
    typename reverse_iterator<Iterator>::difference_type n,
    const reverse_iterator<Iterator>& rev_it) {
  return reverse_iterator<Iterator>(rev_it.base() - n);
}

template <class Iterator>
typename reverse_iterator<Iterator>::difference_type operator-(
    const reverse_iterator<Iterator>& lhs,
    const reverse_iterator<Iterator>& rhs) {
  return rhs.base() - lhs.base();
  // FIXME: this is wrong
}

}  // namespace ft

#endif  // ITER_REVERSE_ITERATOR_TPP
