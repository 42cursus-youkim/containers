#ifndef CONTAINERS_MAP_RELATIONAL_TPP
#define CONTAINERS_MAP_RELATIONAL_TPP

#include "map.hpp"

namespace ft {

template <typename Key, typename T, typename Comp, typename Allocator>
bool operator==(const map<Key, T, Comp, Allocator>& x,
                const map<Key, T, Comp, Allocator>& y) {
  return x.size() == y.size() and
         ft::equal(x.begin(), x.end(), y.begin());
}

template <typename Key, typename T, typename Comp, typename Allocator>
bool operator!=(const map<Key, T, Comp, Allocator>& x,
                const map<Key, T, Comp, Allocator>& y) {
  return not(x == y);
}

template <typename Key, typename T, typename Comp, typename Allocator>
bool operator<(const map<Key, T, Comp, Allocator>& x,
               const map<Key, T, Comp, Allocator>& y) {
  return ft::lexicographical_compare(x.begin(), x.end(), y.begin(),
                                     y.end());
}

template <typename Key, typename T, typename Comp, typename Allocator>
bool operator>(const map<Key, T, Comp, Allocator>& x,
               const map<Key, T, Comp, Allocator>& y) {
  return y < x;
}

template <typename Key, typename T, typename Comp, typename Allocator>
bool operator<=(const map<Key, T, Comp, Allocator>& x,
                const map<Key, T, Comp, Allocator>& y) {
  return not(y < x);
}

template <typename Key, typename T, typename Comp, typename Allocator>
bool operator>=(const map<Key, T, Comp, Allocator>& x,
                const map<Key, T, Comp, Allocator>& y) {
  return not(x < y);
}

}  // namespace ft

#endif  // CONTAINERS_MAP_RELATIONAL_TPP
