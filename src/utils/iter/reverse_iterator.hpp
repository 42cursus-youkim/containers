#ifndef ITER_REVERSE_ITERATOR_HPP
#define ITER_REVERSE_ITERATOR_HPP

#include "iterator.hpp"

namespace ft {
template <class Iterator>
class reverse_iterator : ft::iterator {
 public:
  typedef T value_type;
  typedef Distance difference_type;
  typedef Pointer pointer;
  typedef Reference reference;
  typedef Category iterator_category;

 public:
  explicit reverse_iterator(const iterator_type& it) : current_(it) {}
};
}  // namespace ft

#endif  // ITER_REVERSE_ITERATOR_HPP
