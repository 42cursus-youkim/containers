#ifndef ITER_REVERSE_ITERATOR_RELATIONAL_TPP
#define ITER_REVERSE_ITERATOR_RELATIONAL_TPP

#include "reverse_iterator.hpp"

/// Non-member function overloads

namespace ft {

template <typename Iterator1, typename Iterator2>
bool operator==(const reverse_iterator<Iterator1>& left,
                const reverse_iterator<Iterator2>& right) {
  return left.base() == right.base();
}

template <typename Iterator1, typename Iterator2>
bool operator!=(const reverse_iterator<Iterator1>& left,
                const reverse_iterator<Iterator2>& right) {
  return left.base() != right.base();
}

template <typename Iterator1, typename Iterator2>
bool operator<(const reverse_iterator<Iterator1>& left,
               const reverse_iterator<Iterator2>& right) {
  return left.base() > right.base();
}

template <typename Iterator1, typename Iterator2>
bool operator<=(const reverse_iterator<Iterator1>& left,
                const reverse_iterator<Iterator2>& right) {
  return left.base() >= right.base();
}

template <typename Iterator1, typename Iterator2>
bool operator>(const reverse_iterator<Iterator1>& left,
               const reverse_iterator<Iterator2>& right) {
  return left.base() < right.base();
}

template <typename Iterator1, typename Iterator2>
bool operator>=(const reverse_iterator<Iterator1>& left,
                const reverse_iterator<Iterator2>& right) {
  return left.base() <= right.base();
}
}  // namespace ft

#endif // ITER_REVERSE_ITERATOR_RELATIONAL_TPP
