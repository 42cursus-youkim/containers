#ifndef VECTOR_VECTOR_HPP
#define VECTOR_VECTOR_HPP

#include <iter/reverse_iterator.hpp>
#include <iter/traits.hpp>
#include <memory>
#include <vector>

namespace ft {

template <class T, class Alloc = std::allocator<T> >
class vector {
 public:
  typedef T value_type;
  typedef Alloc allocator_type;
  typedef allocator_type::reference reference;
  typedef allocator_type::const_reference const_reference;
  typedef allocator_type::pointer pointer;
  typedef allocator_type::const_pointer const_pointer;
  typedef pointer iterator;  //< convertible to const_iterator
  typedef const_pointer const_iterator;
  typedef reverse_iterator<iterator> reverse_iterator;
  typedef reverse_iterator<const_iterator> const_reverse_iterator;
  typedef ptrdiff_t difference_type;
  typedef size_t size_type;

 private:
  value_type* data_;
  size_type size_;
  size_type capacity_;
  allocator_type allocator_;

  public:
  // TODO: constructor
  // getters
};

}  // namespace ft

#endif  // VECTOR_VECTOR_HPP
