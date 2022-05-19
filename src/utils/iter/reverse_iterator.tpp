#ifndef ITER_REVERSE_ITERATOR_TPP
#define ITER_REVERSE_ITERATOR_TPP

#include "reverse_iterator.hpp"

namespace ft {

/// Constructors & Destructor

/// default constructor
template <typename Iterator>
reverse_iterator<Iterator>::reverse_iterator() : current_() {}

/// initialization constructor
template <typename Iterator>
reverse_iterator<Iterator>::reverse_iterator(iterator_type it) : current_(it) {}

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

}  // namespace ft

#endif  // ITER_REVERSE_ITERATOR_TPP
