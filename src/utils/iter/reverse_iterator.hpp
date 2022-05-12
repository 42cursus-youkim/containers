#ifndef ITERATOR_REVERSE_ITERATOR_HPP
#define ITERATOR_REVERSE_ITERATOR_HPP

namespace ft {
template <class Iterator>
class reverse_iterator {
 public:
  typedef T value_type;
  typedef Distance difference_type;
  typedef Pointer pointer;
  typedef Reference reference;
  typedef Category iterator_category;

  public:
  explicit reverse_iterator(const iterator_type &it) : current_(it) {}

  // template <typename
};
}  // namespace ft

#endif  // ITERATOR_REVERSE_ITERATOR_HPP
