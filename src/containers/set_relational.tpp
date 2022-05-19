#ifndef CONTAINERS_SET_RELATIONAL_TPP
#define CONTAINERS_SET_RELATIONAL_TPP

#include "set.hpp"

namespace ft {

template <typename T, typename Comp, typename Allocator>
bool operator==(const set<T, Comp, Allocator>& other,
                const set<T, Comp, Allocator>& y) {
  return other.size() == y.size() &&
         ft::equal(other.begin(), other.end(), y.begin());
}

template <typename T, typename Comp, typename Allocator>
bool operator!=(const set<T, Comp, Allocator>& other,
                const set<T, Comp, Allocator>& y) {
  return not (other == y);
}

template <typename T, typename Comp, typename Allocator>
bool operator<(const set<T, Comp, Allocator>& other,
               const set<T, Comp, Allocator>& y) {
  return ft::lexicographical_compare(other.begin(), other.end(),
                                     y.begin(), y.end());
}

template <typename T, typename Comp, typename Allocator>
bool operator>(const set<T, Comp, Allocator>& other,
               const set<T, Comp, Allocator>& y) {
  return y < other;
}

template <typename T, typename Comp, typename Allocator>
bool operator<=(const set<T, Comp, Allocator>& other,
                const set<T, Comp, Allocator>& y) {
  return not(y < other);
}

template <typename T, typename Comp, typename Allocator>
bool operator>=(const set<T, Comp, Allocator>& other,
                const set<T, Comp, Allocator>& y) {
  return not(other < y);
}

}  // namespace ft

#endif // CONTAINERS_SET_RELATIONAL_TPP
