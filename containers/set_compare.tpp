#ifndef CONTAINERS_SET_COMPARE_TPP
#define CONTAINERS_SET_COMPARE_TPP

#include "set.hpp"

namespace ft {

template <typename T, typename Compare, typename Allocator>
typename set<T, Compare, Allocator>::key_compare
set<T, Compare, Allocator>::key_comp() const {
  return comp_;
}

template <typename T, typename Compare, typename Allocator>
typename set<T, Compare, Allocator>::value_compare
set<T, Compare, Allocator>::value_comp() const {
  return comp_;
}

}  // namespace ft

#endif  // CONTAINERS_SET_COMPARE_TPP
