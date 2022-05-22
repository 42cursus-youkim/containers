#ifndef _MAP_NONMEMBER_TPP
#define _MAP_NONMEMBER_TPP

#include "map.hpp"

namespace ft {

template <typename T, typename Compare, typename Alloc>
void swap(map<T, Compare, Alloc>& x, map<T, Compare, Alloc>& y) {
  x.swap(y);
}

}  // namespace ft

#endif  // _MAP_NONMEMBER_TPP
