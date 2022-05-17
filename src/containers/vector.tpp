#ifndef VECTOR_VECTOR_TPP
#define VECTOR_VECTOR_TPP

#include <utils/general/lexicographical_compare.hpp>
#include <utils/general/nullptr.hpp>
#include <utils/tmp/enable_if.hpp>
#include <utils/tmp/is_integral.hpp>
#include "utils/util/util.hpp"
#include "vector.hpp"

#define VEC vector<T, Allocator>

namespace ft {

/// default constructor (empty)
template <class T, class Allocator>
VEC::vector(const Allocator& alloc)
    : data_start_(u_nullptr),
      data_end_(u_nullptr),
      capacity_ptr_(u_nullptr),
      allocator_(alloc) {}

/// fill constructor (container with n val)
template <class T, class Allocator>
VEC::vector(size_type n, const T& val, const Allocator& alloc)
    : data_start_(u_nullptr),
      data_end_(u_nullptr),
      capacity_ptr_(u_nullptr),
      allocator_(alloc) {
  insert(begin(), n, val);
}

/// fill constructor, has ambiguity with integer, therefore using dispatch
template <class T, class Allocator>
template <class InputIterator>
VEC::vector(InputIterator first,
            InputIterator last,
            const typename VEC::allocator_type& alloc)
    : data_start_(u_nullptr),
      data_end_(u_nullptr),
      capacity_ptr_(u_nullptr),
      allocator_(alloc) {
  typedef typename is_integral<InputIterator>::type is_integral;
  initialize_dispatch(first, last, is_integral());
}

/// resolve ambiguity
template <class T, class Allocator>
template <class Integer>
void VEC::initialize_dispatch(Integer n, Integer val, true_type) {
  reserve(FT_VECTOR_INITIAL_SIZE);
  data_end_ = UninitializedFillN(begin(), static_cast<size_type>(n), val);
}

template <class T, class Allocator>
template <class InputIterator>
void VEC::initialize_dispatch(InputIterator first,
                              InputIterator last,
                              false_type) {
  insert(end(), first, last);
}

/// copy constructor
template <class T, class Allocator>
VEC::vector(const vector& other)
    : data_start_(u_nullptr),
      data_end_(u_nullptr),
      capacity_ptr_(u_nullptr),
      allocator_(other.get_allocator()) {
  insert(begin(), other.begin(), other.end());
}

/// copy assignment operator
template <class T, class Allocator>
VEC& VEC::operator=(const vector& other) {
  if (this != &other) {
    clear();
    insert(end(), other.begin(), other.end());
  }
  return *this;
}

/// destructor
template <class T, class Allocator>
VEC::~vector() {
  clear();
  allocator_.deallocate(data_start_, capacity());
}

/// capacity

template <class T, class Allocator>
void VEC::reserve(size_type n) {
  if (n > capacity())
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

/// range
template <class T, class Allocator>
template <class InputIterator>
void VEC::assign(InputIterator first, InputIterator last) {
  // clear();
  // insert(begin(), first, last);
  typedef typename is_integral<InputIterator>::type is_integral;
  assign_dispatch(first, last, is_integral());
}

/// fill
template <class T, class Allocator>
void VEC::assign(size_type n, const value_type& val) {
  /// TODO: make it into FILL_ASSIGN impl
  clear();
  insert(begin(), n, val);
}

template <class T, class Allocator>
template <typename Integer>
void VEC::assign_dispatch(Integer n, Integer val, true_type) {
  clear();
  insert(begin(), n, val);
}

template <class T, class Allocator>
template <typename InputIterator>
void VEC::assign_dispatch(InputIterator first, InputIterator last, false_type) {
  clear();
  insert(begin(), first, last);
}

template <class T, class Allocator>
void VEC::push_back(const value_type& val) {
  if (size() == capacity())
    reserve(GetNewCapacity(size() + 1));
  allocator_.construct(data_end_, val);
  ++data_end_;
}

template <class T, class Allocator>
void VEC::pop_back() {
  allocator_.destroy(data_end_ - 1);
  --data_end_;
}

/// single element
template <class T, class Allocator>
typename VEC::iterator VEC::insert(iterator position, const value_type& val) {
#ifdef FT_VECTOR_DEBUG
  FUN << "pos: " << position << " value: " << val << END "\n";
#endif
  iterator new_position = RightShift(position, 1);

#ifdef FT_VECTOR_DEBUG
  FUN << "new position: " << Index(new_position) << END "\n";
#endif
  allocator_.construct(new_position, val);
  return new_position;
}

/// fill
template <class T, class Allocator>
void VEC::insert(iterator position, size_type n, const value_type& val) {
  iterator new_position = RightShift(position, n);
  for (size_type i = 0; i < n; ++i)
    allocator_.construct(new_position + i, val);
}

/// range
template <class T, class Allocator>
template <class InputIterator>
void VEC::insert(iterator position, InputIterator first, InputIterator last) {
  typedef typename is_integral<InputIterator>::type is_integral;
  insert_dispatch(position, first, last, is_integral());
}

template <class T, class Allocator>
template <class Integer>
void VEC::insert_dispatch(iterator position,
                          Integer n,
                          Integer val,
                          true_type) {
  // TODO: make these an implementation to fix DRY
  iterator new_position = RightShift(position, static_cast<size_type>(n));
  for (size_type i = 0; i < static_cast<size_type>(n); ++i)
    allocator_.construct(new_position + i, val);
}

template <class T, class Allocator>
template <class InputIterator>
void VEC::insert_dispatch(iterator position,
                          InputIterator first,
                          InputIterator last,
                          false_type) {
  // TODO: make these an implementation to fix DRY
  const difference_type count = std::distance(first, last);
  iterator new_position = RightShift(position, static_cast<size_type>(count));

  for (difference_type i = 0; i < count; ++i)
    allocator_.construct(new_position + i, first[i]);
}

template <class T, class Allocator>
typename VEC::iterator VEC::erase(iterator position) {
  return LeftShift(position, 1);
}

template <class T, class Allocator>
typename VEC::iterator VEC::erase(iterator first, iterator last) {
  return LeftShift(first, size_type(std::distance(first, last)));
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

/// allocator

template <class T, class Allocator>
typename VEC::allocator_type VEC::get_allocator() const {
  return allocator_;
}

/// implementation details

/// returns
template <class T, class Allocator>
typename VEC::iterator VEC::UninitializedFillN(iterator from,
                                               size_type count,
                                               const value_type& val) {
  size_type i = 0;
  try {
    for (; i < count; ++i)
      allocator_.construct(from + i, val);
  } catch (...) {
    for (; i >= 0; --i)
      allocator_.destroy(from + i);
  }
  return from + count;
}

template <class T, class Allocator>
typename VEC::size_type VEC::Index(iterator it) const {
  return size_type(it - begin());
}

/// @brief move a single element to a new position.
/// @param to any element in to
template <class T, class Allocator>
inline typename VEC::iterator VEC::UnsafeMove(iterator from, iterator to) {
  data_start_[Index(to)] = data_start_[Index(from)];
  return to;
}

/// creates new storage, rellocates all elements to new one
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
typename VEC::iterator VEC::LeftShift(iterator from, size_type diff) {
  if (diff == 0)
    return from;

  for (iterator it = from; it + diff < end(); ++it) {
    // TODO: call allocator_.destory()?
    // allocator_.destroy(&data_start_[to_i]);
    *it = it[diff];
  }
  for (iterator it = end() - 1; it + diff > end(); --it)
    allocator_.destroy(it);
  data_end_ -= diff;

  return from;
}

/// @brief Moves from amount elements to the right
template <class T, class Allocator>
typename VEC::iterator VEC::RightShift(iterator from, size_type diff) {
  if (diff == 0)
    return from;

  const size_type from_index = Index(from);
  const size_type new_size = size() + diff;
  const size_type affected = size() - from_index;

  if (new_size >= capacity())
    reserve(GetNewCapacity(new_size));

  for (size_type i = 0; i < affected; i++) {
    size_type from_i = from_index + (affected - i - 1);
    size_type to_i = from_i + diff;
    data_start_[to_i] = data_start_[from_i];
  }

  data_end_ = data_start_ + new_size;
  return data_start_ + from_index;
}

/// capacity (getter)

template <class T, class Allocator>
bool VEC::empty() const {
  return size() == 0;
}

template <class T, class Allocator>
typename VEC::size_type VEC::size() const {
  return size_type(data_end_ - data_start_);
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
  return data_end_[-1];
}

template <class T, class Allocator>
typename VEC::const_reference VEC::back() const {
  return data_end_[-1];
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
/// non-member function overloads

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

template <class T, class Alloc>
void swap(vector<T, Alloc>& x, vector<T, Alloc>& y) {
  x.swap(y);
}

}  // namespace ft

#endif  // VECTOR_VECTOR_TPP
