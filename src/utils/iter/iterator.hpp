#ifndef ITERATOR_ITERATOR_HPP
#define ITERATOR_ITERATOR_HPP

#include <cstddef>

namespace ft {

template <class Category,
          class T,
          class Distance = ptrdiff_t,
          class Pointer = T*,
          class Reference = T&>
class iterator {
 public:
  typedef T value_type;
  typedef Distance difference_type;
  typedef Pointer pointer;
  typedef Reference reference;
  typedef Category iterator_category;
};

}  // namespace ft

#endif  // ITERATOR_ITERATOR_HPP
