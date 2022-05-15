#ifndef VECTOR_VECTOR_TPP
#define VECTOR_VECTOR_TPP

#include <general/lexicographical_compare.hpp>
#include "util.hpp"
#include "vector.hpp"

#define VEC vector<T, Allocator>

namespace ft {

/// default constructor (empty)
template <class T, class Allocator>
VEC::vector(const Allocator& alloc)
    : data_start_(NULL), data_end_(NULL), capacity_ptr_(0), allocator_(alloc) {}

/// fill constructor (container with n val)
// template <class T, class Allocator>
// VEC::vector(size_type n, const T& val, const Allocator& alloc)
//     : data_start_(alloc.allocate(n)), s capacity_ptr_(n), allocator_(alloc) {}

/// fill constructor
// template <class T, class Allocator>
// template <class InputIterator>
// VEC::vector(InputIterator first,
//             InputIterator last,
//             const typename ft::VEC::Allocator& alloc)
//     : data_start_(alloc.allocate(last - first)),
//       size()(last - first),
//       capacity_ptr_(last - first),
//       allocator_(alloc) {
//   for (size_type i = 0; i < size(); ++i)
//     allocator_.construct(data_start_ + i, *(first + i));
// }

/// copy constructor
// template <class T, class Allocator>
// VEC::vector(const vector& other)
//     : data_start_(other.allocator_.allocate(other.size())),
//       size()(other.size()),
//       capacity_ptr_(other.size()),
//       allocator_(other.allocator_) {
//   for (size_type i = 0; i < size(); ++i)
//     allocator_.construct(data_start_ + i, other.data_start_[i]);
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
  clear();
  allocator_.deallocate(data_start_, capacity());
}

/// capacity

template <class T, class Allocator>
void VEC::reserve(size_type n) {
  if (n > size_type())
    DoGrow(n);
}

template <class T, class Allocator>
void VEC::resize(size_type n, T val) {
  if (n > size())
    insert(end(), n - size(), val);
  else
    erase(begin() + n, end());
}

/// modifiers
template <class T, class Allocator>
void VEC::push_back(const value_type& val) {
  if (size() == capacity())
    reserve(GetNewCapacity(size() + 1));
  allocator_.construct(data_end_, val);
  ++data_end_;
}

template <class T, class Allocator>
typename VEC::iterator VEC::insert(iterator position, const value_type& val) {
  iterator new_position = RightShift(position, 1);
  allocator_.construct(new_position, val);
}

template <class T, class Allocator>
typename VEC::iterator VEC::erase(iterator position) {
  return LeftShift(position, 1);
}

template <class T, class Allocator>
typename VEC::iterator VEC::erase(iterator first, iterator last) {
  return LeftShift(last, std::distance(first, last));
}

template <class T, class Allocator>
void VEC::swap(vector& other) {
  std::swap(data_start_, other.data_start_);
  std::swap(data_end_, other.data_end_);
  std::swap(capacity_ptr_, other.capacity_ptr_);
  std::swap(allocator_, other.allocator_);
}

template <class T, class Allocator>
void VEC::clear() {
  for (iterator it = data_start_; it != data_end_; ++it)
    allocator_.destroy(it);
  data_end_ = data_start_;
}

/// implementation details

/// returns
template <class T, class Allocator>
typename VEC::iterator VEC::UninitializedFillN(size_type count, const value_type& val) {
  for (size_type i = 0; i < count; ++i)
    allocator_.construct(data_start_ + i, val);
  return data_start_ + count;
}

template <class T, class Allocator>
typename VEC::size_type VEC::Index(iterator it) const {
  return it - begin();
}

/// @brief move a single element to a new position.
/// @param to any element in to
template <class T, class Allocator>
inline typename VEC::iterator VEC::UnsafeMove(iterator from, iterator to) {
  data_start_[Index(to)] = data_start_[Index(from)];
}

template <class T, class Allocator>
void VEC::DoGrow(size_type new_capacity) {
  if (new_capacity > max_size())
    throw std::length_error("ft::vector::reserve: maximum capacity exceeded");

  const size_type length = size();
  const size_type old_capacity = capacity();

  pointer new_data_begin = allocator_.allocate(new_capacity);
  for (size_type i = 0; i < length; ++i) {
    allocator_.construct(new_data_begin + i, data_start_[i]);
    allocator_.destroy(data_start_ + i);
  }
  allocator_.deallocate(data_start_, old_capacity);

  data_start_ = new_data_begin;
  data_end_ = data_start_ + length;
  capacity_ptr_ = data_start_ + new_capacity;
}

/// get suitable new capacity
template <class T, class Allocator>
typename VEC::size_type VEC::GetNewCapacity(size_type at_least) const {
  const size_type max_possible_size(max_size());
  const size_type current_capacity(capacity());

  if (at_least > max_possible_size)
    throw std::length_error("ft::vector::reserve: maximum capacity exceeded");
  else if (current_capacity > max_possible_size / 2)
    return at_least;
  return std::max(at_least, 2 * current_capacity);
}

template <class T, class Allocator>
typename VEC::iterator VEC::LeftShift(iterator from, difference_type amount) {
  if (from == end())
    return from;
  for (iterator it = from + amount; it != end(); ++it, ++from)
    UnsafeMove(from, it);
  return from;
}

template <class T, class Allocator>
typename VEC::iterator VEC::RightShift(iterator from, difference_type amount) {
  if (size() == capacity())
    reserve(GetNewCapacity(size() + amount));

  for (iterator it = from + amount; it-- != from;) {
    UnsafeMove(it, it + amount);
  }
}

/// capacity (getter)

template <class T, class Allocator>
typename VEC::size_type VEC::size() const {
  LOG_VAL(data_start_);
  LOG_VAL(data_end_);
  return size_type(data_end_ - data_start_);
}

template <class T, class Allocator>
bool VEC::empty() const {
  return size() == 0;
}

template <class T, class Allocator>
typename VEC::size_type VEC::max_size() const {
  return allocator_.max_size();
}

template <class T, class Allocator>
typename VEC::size_type VEC::capacity() const {
  return size_type(capacity_ptr_ - data_start_);
}

/// element access

template <class T, class Allocator>
typename VEC::reference VEC::front() {
  return data_start_[0];
}

template <class T, class Allocator>
typename VEC::const_reference VEC::front() const {
  return data_start_[0];
}

template <class T, class Allocator>
typename VEC::reference VEC::back() {
  return data_end_[1];
}

template <class T, class Allocator>
typename VEC::const_reference VEC::back() const {
  return data_end_[1];
}

template <class T, class Allocator>
typename VEC::reference VEC::at(size_type n) {
  if (n >= size())
    throw std::out_of_range("vector::at");
  return data_start_[n];
}

template <class T, class Allocator>
typename VEC::const_reference VEC::at(size_type n) const {
  if (n >= size())
    throw std::out_of_range("vector::at");
  return data_start_[n];
}

template <class T, class Allocator>
typename VEC::reference VEC::operator[](size_type n) {
  return data_start_[n];
}

template <class T, class Allocator>
typename VEC::const_reference VEC::operator[](size_type n) const {
  return data_start_[n];
}

/// iterators

template <class T, class Allocator>
typename VEC::iterator VEC::begin() {
  return data_start_;
}
template <class T, class Allocator>
typename VEC::const_iterator VEC::begin() const {
  return data_start_;
}
template <class T, class Allocator>
typename VEC::iterator VEC::end() {
  return data_end_;
}
template <class T, class Allocator>
typename VEC::const_iterator VEC::end() const {
  return data_end_;
}

/// reverse iterators

template <class T, class Allocator>
typename VEC::reverse_iterator VEC::rbegin() {
  return reverse_iterator(end());
}
template <class T, class Allocator>
typename VEC::const_reverse_iterator VEC::rbegin() const {
  return const_reverse_iterator(end());
}
template <class T, class Allocator>
typename VEC::reverse_iterator VEC::rend() {
  return reverse_iterator(begin());
}
template <class T, class Allocator>
typename VEC::const_reverse_iterator VEC::rend() const {
  return const_reverse_iterator(begin());
}

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
  return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
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
