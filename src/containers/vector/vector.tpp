#ifndef VECTOR_VECTOR_TPP
#define VECTOR_VECTOR_TPP

#include <general/lexicographical_compare.hpp>
#include "vector.hpp"

#define VEC vector<T, Allocator>

#define VEC_RET(type)                               \
  template <class T, class Allocator> \
  type

#define VEC_RET_TYPE(type)                          \
  template <class T, class Allocator> \
  typename VEC::type

namespace ft {

/// default constructor (empty)
template <class T, class Allocator>
VEC::vector(const Allocator& alloc)
    : data_begin_(NULL), size_(0), capacity_(0), allocator_(alloc) {}

/// fill constructor (container with n val)
// template <class T, class Allocator>
// VEC::vector(size_type n,
//             const T& val,
//             const Allocator& alloc)
//     : data_begin_(alloc.allocate(n)), size_(n), capacity_(n), allocator_(alloc) {
//   for (size_type i = 0; i < n; ++i)
//     allocator_.construct(data_begin_ + i, val);
// }

/// fill constructor
// template <class T, class Allocator>
// template <class InputIterator>
// VEC::vector(InputIterator first,
//             InputIterator last,
//             const typename ft::VEC::Allocator& alloc)
//     : data_begin_(alloc.allocate(last - first)),
//       size_(last - first),
//       capacity_(last - first),
//       allocator_(alloc) {
//   for (size_type i = 0; i < size_; ++i)
//     allocator_.construct(data_begin_ + i, *(first + i));
// }

/// copy constructor
// template <class T, class Allocator>
// VEC::vector(const vector& other)
//     : data_begin_(other.allocator_.allocate(other.size_)),
//       size_(other.size_),
//       capacity_(other.size_),
//       allocator_(other.allocator_) {
//   for (size_type i = 0; i < size_; ++i)
//     allocator_.construct(data_begin_ + i, other.data_begin_[i]);
// }

/// copy assignment operator
// template <class T, class Allocator>
// VEC& VEC::operator=(const vector& other) {
//   if (this != &other) {
//     clear();
//     insert(end(), other.begin(), other.end());
//   }
//   return *this;
// }

/// destructor
template <class T, class Allocator>
VEC::~vector() {
  for (size_type i = 0; i < size_; ++i)
    allocator_.destroy(data_begin_ + i);

  allocator_.deallocate(data_begin_, capacity_);
}

/// iterators

VEC_RET_TYPE(iterator) VEC::begin() {
  return data_begin_;
}
VEC_RET_TYPE(const_iterator) VEC::begin() const {
  return data_begin_;
}
VEC_RET_TYPE(iterator) VEC::end() {
  return data_begin_ + size_;
}
VEC_RET_TYPE(const_iterator) VEC::end() const {
  return data_begin_ + size_;
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
  size_type old_capacity = capacity();
  if (n <= old_capacity)
    return;
  if (n > max_size())
    throw std::length_error("ft::vector::reserve: maximum capacity exceeded");

  T* new_data = allocator_.allocate(n);
  for (size_type i = 0; i < size(); ++i) {
    allocator_.construct(data_begin_ + i, data_begin_[i]);
    allocator_.destroy(data_begin_ + i);
  }
  allocator_.deallocate(data_begin_, old_capacity);
  data_begin_ = new_data;
  capacity_ = n;
}

VEC_RET(void) VEC::resize(size_type n, T val) {
  (void)n;
  (void)val;
}

/// element access

VEC_RET_TYPE(reference) VEC::front() {
  return data_begin_[0];
}

VEC_RET_TYPE(const_reference) VEC::front() const {
  return data_begin_[0];
}

VEC_RET_TYPE(reference) VEC::back() {
  return data_begin_[size_ - 1];
}

VEC_RET_TYPE(const_reference) VEC::back() const {
  return data_begin_[size_ - 1];
}

VEC_RET_TYPE(reference) VEC::at(size_type n) {
  if (n >= size_)
    throw std::out_of_range("vector::at");
  return data_begin_[n];
}

VEC_RET_TYPE(const_reference) VEC::at(size_type n) const {
  if (n >= size_)
    throw std::out_of_range("vector::at");
  return data_begin_[n];
}

VEC_RET_TYPE(reference) VEC::operator[](size_type n) {
  return data_begin_[n];
}

VEC_RET_TYPE(const_reference) VEC::operator[](size_type n) const {
  return data_begin_[n];
}

// VEC_RET_TYPE(iterator) VEC::insert(iterator position, const T& val) {}

/// relational operators

template <class T, class Allocator>
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

template <class T, class Allocator>
bool operator!=(const VEC& lhs, const VEC& rhs) {
  return not(lhs == rhs);
}

template <class T, class Allocator>
bool operator<(const VEC& lhs, const VEC& rhs) {
  return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(),
                                 rhs.end());
}

template <class T, class Allocator>
bool operator<=(const VEC& lhs, const VEC& rhs) {
  return lhs == rhs or lhs < rhs;
}

template <class T, class Allocator>
bool operator>(const VEC& lhs, const VEC& rhs) {
  return rhs < lhs;
}

template <class T, class Allocator>
bool operator>=(const VEC& lhs, const VEC& rhs) {
  return lhs == rhs or lhs > rhs;
}

}  // namespace ft

#endif  // VECTOR_VECTOR_TPP
