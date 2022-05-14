#ifndef VECTOR_VECTOR_TPP
#define VECTOR_VECTOR_TPP

#include <general/lexicographical_compare.hpp>
#include "vector.hpp"

#define VEC vector<T, Alloc>

#define VEC_RET(type)             \
  template <class T, class Alloc> \
  type

#define VEC_RET_TYPE(type)        \
  template <class T, class Alloc> \
  typename VEC::type

namespace ft {
/// default constructor (empty)
template <class T, class Alloc>
VEC::vector(const VEC::allocator_type& alloc)
    : data_(NULL), size_(0), capacity_(0), allocator_(alloc) {}

/// fill constructor (container with n val)
template <class T, class Alloc>
VEC::vector(size_type n, const value_type& val, const allocator_type& alloc)
    : data_(alloc.allocate(n)), size_(n), capacity_(n), allocator_(alloc) {
  for (size_type i = 0; i < n; ++i)
    allocator_.construct(data_ + i, val);
}

/// fill constructor
template <class T, class Alloc>
template <class InputIterator>
VEC::vector(InputIterator first,
            InputIterator last,
            const typename ft::VEC::allocator_type& alloc)
    : data_(alloc.allocate(last - first)),
      size_(last - first),
      capacity_(last - first),
      allocator_(alloc) {
  for (size_type i = 0; i < size_; ++i)
    allocator_.construct(data_ + i, *(first + i));
}

/// copy constructor
template <class T, class Alloc>
VEC::vector(const vector& other)
    : data_(other.allocator_.allocate(other.size_)),
      size_(other.size_),
      capacity_(other.size_),
      allocator_(other.allocator_) {
  for (size_type i = 0; i < size_; ++i)
    allocator_.construct(data_ + i, other.data_[i]);
}

/// copy assignment operator
// template <class T, class Alloc>
// VEC& VEC::operator=(const vector& other) {
//   if (this != &other) {
//     clear();
//     insert(end(), other.begin(), other.end());
//   }
//   return *this;
// }

/// destructor
template <class T, class Alloc>
VEC::~vector() {
  for (size_type i = 0; i < size_; ++i)
    allocator_.destroy(data_ + i);

  allocator_.deallocate(data_, capacity_);
}

/// iterators

VEC_RET_TYPE(iterator) VEC::begin() {
  return data_;
}
VEC_RET_TYPE(const_iterator) VEC::begin() const {
  return data_;
}
VEC_RET_TYPE(iterator) VEC::end() {
  return data_ + size_;
}
VEC_RET_TYPE(const_iterator) VEC::end() const {
  return data_ + size_;
}

/// reverse iterators

VEC_RET_TYPE(reverse_iterator) VEC::rbegin() {
  return reverse_iterator(end());
}
VEC_RET_TYPE(const_reverse_iterator) VEC::rbegin() const {
  return const_reverse_iterator(end());
}
VEC_RET_TYPE(reverse_iterator) VEC::rend() {
  return reverse_iterator(begin());
}
VEC_RET_TYPE(const_reverse_iterator) VEC::rend() const {
  return const_reverse_iterator(begin());
}

/// capacity

VEC_RET_TYPE(size_type) VEC::size() const {
  return size_;
}

VEC_RET_TYPE(size_type) VEC::max_size() const {
  return allocator_.max_size();
}

VEC_RET_TYPE(size_type) VEC::capacity() const {
  return capacity_;
}

VEC_RET(bool) VEC::empty() const {
  return size_ == 0;
}

VEC_RET(void) VEC::reserve(size_type n) {
  (void)n;
}

VEC_RET(void) VEC::resize(size_type n, value_type val) {
  (void)n;
  (void)val;
}

/// element access

VEC_RET_TYPE(reference) VEC::front() {
  return data_[0];
}

VEC_RET_TYPE(const_reference) VEC::front() const {
  return data_[0];
}

VEC_RET_TYPE(reference) VEC::back() {
  return data_[size_ - 1];
}

VEC_RET_TYPE(const_reference) VEC::back() const {
  return data_[size_ - 1];
}

VEC_RET_TYPE(reference) VEC::at(size_type n) {
  return data_[n];
}

VEC_RET_TYPE(const_reference) VEC::at(size_type n) const {
  return data_[n];
}

VEC_RET_TYPE(reference) VEC::operator[](size_type n) {
  return data_[n];
}

VEC_RET_TYPE(const_reference) VEC::operator[](size_type n) const {
  return data_[n];
}

/// relational operators
template <class T, class Alloc>
bool operator==(const VEC& lhs, const VEC& rhs) {
  if (lhs.size() != rhs.size())
    return false;
  typename vector<T>::const_iterator first1 = lhs.begin();
  typename vector<T>::const_iterator first2 = rhs.begin();
  for (; first1 != lhs.end(); ++first1, ++first2) {
    if (first2 == rhs.end() or *first1 != *first2)
      return false;
  }
  return true;
}

template <class T, class Alloc>
bool operator!=(const VEC& lhs, const VEC& rhs) {
  return not (lhs == rhs);
}

template <class T, class Alloc>
bool operator<(const VEC& lhs, const VEC& rhs) {
  return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(),
                                 rhs.end());
}

template <class T, class Alloc>
bool operator<=(const VEC& lhs, const VEC& rhs) {
  return lhs == rhs or lhs < rhs;
}

template <class T, class Alloc>
bool operator>(const VEC& lhs, const VEC& rhs) {
  return rhs < lhs;
}

template <class T, class Alloc>
bool operator>=(const VEC& lhs, const VEC& rhs) {
  return lhs == rhs or lhs > rhs;
}

}  // namespace ft

#endif  // VECTOR_VECTOR_TPP
