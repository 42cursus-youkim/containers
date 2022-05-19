#ifndef ITER_ITERATOR_HPP
#define ITER_ITERATOR_HPP

#include <cstddef>

namespace ft {

template <typename Category,
          typename T,
          typename Distance  = ptrdiff_t,
          typename Pointer   = T*,
          typename Reference = T&>
class iterator {
 public:
  typedef T         value_type;
  typedef Distance  difference_type;
  typedef Pointer   pointer;
  typedef Reference reference;
  typedef Category  iterator_category;
};

}  // namespace ft

#endif  // ITER_ITERATOR_HPP
