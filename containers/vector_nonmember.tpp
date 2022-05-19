#ifndef CONTAINERS_VECTOR_NONMEMBER_TPP
#define CONTAINERS_VECTOR_NONMEMBER_TPP

#include "vector.hpp"

namespace ft {
/// non-member function overloads

template <class T, class Alloc>
void swap(vector<T, Alloc>& x, vector<T, Alloc>& y) {
  x.swap(y);
}

}  // namespace ft

#endif // CONTAINERS_VECTOR_NONMEMBER_TPP
