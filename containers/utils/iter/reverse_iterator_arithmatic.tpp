#ifndef ITER_REVERSE_ITERATOR_ARITHMATIC_TPP
#define ITER_REVERSE_ITERATOR_ARITHMATIC_TPP

#include "reverse_iterator.hpp"

namespace ft {
/// addition and subtraction operator

template <typename Iterator>
reverse_iterator<Iterator> operator+(
    typename reverse_iterator<Iterator>::difference_type n,
    const reverse_iterator<Iterator>&                    rev_it) {
  return reverse_iterator<Iterator>(rev_it.base() - n);
}

template <typename Iterator1, typename Iterator2>
typename reverse_iterator<Iterator1>::difference_type operator-(
    const reverse_iterator<Iterator1>& left,
    const reverse_iterator<Iterator2>& right) {
  return right.base() - left.base();
}
}  // namespace ft

#endif // ITER_REVERSE_ITERATOR_ARITHMATIC_TPP
