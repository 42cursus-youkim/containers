#ifndef VECTOR_VECTOR_TPP
#define VECTOR_VECTOR_TPP

#include "vector.hpp"

namespace ft {

/// default constructor (empty)
template <class T, class Alloc>
vector<T, Alloc>::vector(const allocator_type& alloc)
    : data_(NULL), size_(0), capacity_(0), allocator_(alloc) {}

/// fill constructor (container with n val)
template <class T, class Alloc>
vector<T, Alloc>::vector(size_type n,
                         const value_type& val,
                         const allocator_type& alloc)
    : data_(alloc.allocate(n)), size_(n), capacity_(n), allocator_(alloc) {
  for (size_type i = 0; i < n; ++i)
    allocator_.construct(data_ + i, val);
}

/// fill constructor
template <class T, class Alloc>
template <class InputIterator>
vector<T, Alloc>::vector(
    InputIterator first,
    InputIterator last,
    const typename ft::vector<T, Alloc>::allocator_type& alloc)
    : data_(alloc.allocate(last - first)),
      size_(last - first),
      capacity_(last - first),
      allocator_(alloc) {
  for (size_type i = 0; i < size_; ++i)
    allocator_.construct(data_ + i, *(first + i));
}

/// copy constructor
template <class T, class Alloc>
vector<T, Alloc>::vector(const vector& other)
    : data_(other.allocator_.allocate(other.size_)),
      size_(other.size_),
      capacity_(other.size_),
      allocator_(other.allocator_) {
  for (size_type i = 0; i < size_; ++i)
    allocator_.construct(data_ + i, other.data_[i]);
}

/// copy assignment operator
// template <class T, class Alloc>
// vector<T, Alloc>& vector<T, Alloc>::operator=(const vector& other) {
//   if (this != &other) {
//     clear();
//     insert(end(), other.begin(), other.end());
//   }
//   return *this;
// }

/// destructor
template <class T, class Alloc>
vector<T, Alloc>::~vector() {
  for (size_type i = 0; i < size_; ++i) {
    allocator_.destroy(data_ + i);
  }
  allocator_.deallocate(data_, capacity_);
}

}  // namespace ft

#endif  // VECTOR_VECTOR_TPP
