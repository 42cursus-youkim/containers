#ifndef _SET_NONMEMBER_TPP
#define _SET_NONMEMBER_TPP

#include "set.hpp"

namespace ft {

template <typename T, typename Compare, typename Alloc>
void swap(set<T, Compare, Alloc>& x, set<T, Compare, Alloc>& y){
  x.swap(y);
}

}  // namespace ft

#endif // _SET_NONMEMBER_TPP
