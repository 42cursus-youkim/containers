#ifndef __CONT_VECTOR_H__
#define __CONT_VECTOR_H__


#include <memory>

using std::allocator;

namespace ft {

// template <typename T>
// class VectorIterator

template <typename T, class Alloc = allocator<T> >
class Vector {
  typedef T value_type;
  typedef Alloc allocator_type;
  typedef allocator_type::reference reference;
  typedef allocator_type::const_reference const_reference;
  typedef allocator_type::pointer pointer;
  typedef allocator_type::const_pointer const_pointer;
  typedef iterator;
  typedef const_iterator;
  typedef reverse_iterator;
  typedef const_reverse_iterator;
  typedef difference_type;
  typedef size_type;
};
}  // namespace ft

#include "cont_vector.tpp"


#endif // __CONT_VECTOR_H__
