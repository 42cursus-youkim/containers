#ifndef CONTAINERS_VECTOR_MODIFIER_TPP
#define CONTAINERS_VECTOR_MODIFIER_TPP

#include "vector.hpp"

namespace ft {

/// range
template <typename T, typename Allocator>
template <typename InputIterator>
void vector<T, Allocator>::assign(InputIterator first,
                                  InputIterator last) {
  // clear();
  // insert(begin(), first, last);
  typedef typename is_integral<InputIterator>::type is_integral;
  assign_dispatch(first, last, is_integral());
}

/// fill
template <typename T, typename Allocator>
void vector<T, Allocator>::assign(size_type         n,
                                  const value_type& val) {
  /// TODO: make it into FILL_ASSIGN impl
  clear();
  insert(begin(), n, val);
}

template <typename T, typename Allocator>
template <typename Integer>
void vector<T, Allocator>::assign_dispatch(Integer n,
                                           Integer val,
                                           true_type) {
  clear();
  insert(begin(), n, val);
}

template <typename T, typename Allocator>
template <typename InputIterator>
void vector<T, Allocator>::assign_dispatch(InputIterator first,
                                           InputIterator last,
                                           false_type) {
  clear();
  insert(begin(), first, last);
}

template <typename T, typename Allocator>
void vector<T, Allocator>::push_back(const value_type& val) {
  if (size() == capacity())
    reserve(GetNewCapacity(size() + 1));
  allocator_.construct(data_end_, val);
  ++data_end_;
}

template <typename T, typename Allocator>
void vector<T, Allocator>::pop_back() {
  allocator_.destroy(data_end_ - 1);
  --data_end_;
}

/// single element
template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::insert(
    iterator          position,
    const value_type& val) {
  iterator new_position = RightShift(position, 1);

  allocator_.construct(new_position, val);
  return new_position;
}

/// fill
template <typename T, typename Allocator>
void vector<T, Allocator>::insert(iterator          position,
                                  size_type         n,
                                  const value_type& val) {
  iterator new_position = RightShift(position, n);

  for (size_type i = 0; i < n; ++i, ++new_position)
    allocator_.construct(&*new_position, val);
}

/// range
template <typename T, typename Allocator>
template <typename InputIterator>
void vector<T, Allocator>::insert(iterator      position,
                                  InputIterator first,
                                  InputIterator last) {
  typedef typename is_integral<InputIterator>::type is_integral;
  insert_dispatch(position, first, last, is_integral());
}

template <typename T, typename Allocator>
template <typename Integer>
void vector<T, Allocator>::insert_dispatch(iterator position,
                                           Integer  n,
                                           Integer  val,
                                           true_type) {
  iterator new_position =
      RightShift(position, static_cast<size_type>(n));
  for (size_type i = 0; i < static_cast<size_type>(n);
       ++i, ++new_position)
    allocator_.construct(&*new_position, val);
}

template <typename T, typename Allocator>
template <typename InputIterator>
void vector<T, Allocator>::insert_dispatch(iterator      position,
                                           InputIterator first,
                                           InputIterator last,
                                           false_type) {
  const difference_type count = last - first;
  iterator              new_position =
      RightShift(position, static_cast<size_type>(count));

  InputIterator it = first;
  for (difference_type i = 0; i < count; ++i, ++it)
    allocator_.construct(&new_position[i], *it);
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::erase(
    iterator position) {
  return LeftShift(position, 1);
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::erase(
    iterator first,
    iterator last) {
  return LeftShift(first, size_type(std::distance(first, last)));
}

template <typename T, typename Allocator>
void vector<T, Allocator>::swap(vector& other) {
  std::swap(data_start_, other.data_start_);
  std::swap(data_end_, other.data_end_);
  std::swap(capacity_ptr_, other.capacity_ptr_);
  std::swap(allocator_, other.allocator_);
}

template <typename T, typename Allocator>
void vector<T, Allocator>::clear() {
  for (iterator it = begin(); it != end(); ++it)
    allocator_.destroy(data_start_ + (it - begin()));
  data_end_ = data_start_;
}
}  // namespace ft

#endif  // CONTAINERS_VECTOR_MODIFIER_TPP
