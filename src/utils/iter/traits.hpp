#ifndef ITER_TRAITS_HPP
#define ITER_TRAITS_HPP

#include "tag.hpp"

namespace ft {

template <typename Iterator>
struct iterator_traits {
  typedef typename Iterator::iterator_category iterator_category;
  typedef typename Iterator::value_type value_type;
  typedef typename Iterator::difference_type difference_type;
  typedef typename Iterator::pointer pointer;
  typedef typename Iterator::reference reference;
};

/// partial specialization for pointer types
template <typename T>
struct iterator_traits<T*> {
  typedef random_access_iterator_tag iterator_category;
  typedef T value_type;
  typedef std::ptrdiff_t difference_type;
  typedef T* pointer;
  typedef T& reference;
};

/// partial specialization for constant pointer types
template <typename T>
struct iterator_traits<const T*> {
  typedef random_access_iterator_tag iterator_category;
  typedef T value_type;
  typedef std::ptrdiff_t difference_type;
  typedef const T* pointer;
  typedef const T& reference;
};

}  // namespace ft

#endif  // ITER_TRAITS_HPP
