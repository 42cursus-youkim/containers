#ifndef CONTAINERS_VECTOR_RELATIONAL_TPP
#define CONTAINERS_VECTOR_RELATIONAL_TPP

#include "vector.hpp"

namespace ft {

/// relational operators

template <typename T, typename Allocator>
bool operator==(const vector<T, Allocator>& left,
                const vector<T, Allocator>& right) {
  if (left.size() != right.size())
    return false;
  typename vector<T>::const_iterator first1 = left.begin();
  typename vector<T>::const_iterator first2 = right.begin();
  for (; first1 != left.end(); ++first1, ++first2) {
    if (first2 == right.end() or *first1 != *first2)
      return false;
  }
  return true;
}

template <typename T, typename Allocator>
bool operator!=(const vector<T, Allocator>& left,
                const vector<T, Allocator>& right) {
  return not(left == right);
}

template <typename T, typename Allocator>
bool operator<(const vector<T, Allocator>& left,
               const vector<T, Allocator>& right) {
  return ft::lexicographical_compare(left.begin(), left.end(),
                                     right.begin(), right.end());
}

template <typename T, typename Allocator>
bool operator<=(const vector<T, Allocator>& left,
                const vector<T, Allocator>& right) {
  return left == right or left < right;
}

template <typename T, typename Allocator>
bool operator>(const vector<T, Allocator>& left,
               const vector<T, Allocator>& right) {
  return right < left;
}

template <typename T, typename Allocator>
bool operator>=(const vector<T, Allocator>& left,
                const vector<T, Allocator>& right) {
  return left == right or left > right;
}
}  // namespace ft

#endif  // CONTAINERS_VECTOR_RELATIONAL_TPP
