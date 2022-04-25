#ifndef __IMPL_ITERATOR_H__
#define __IMPL_ITERATOR_H__

#include <iterator>

namespace ft {

/**
 * @brief  base class provided to simplify definitions
 *         of the required types for iterators.
 *
 * @tparam Category category of the iterator.
 *         Must be one of iterator category tags.
 * @tparam T The type that can be optained by dereferencing the iterator.
 * @tparam Distance type that can be used to identify distance between iterators
 * @tparam Pointer defines a pointer to the type iterated over (T)
 * @tparam Reference defines a reference to the type iterated over (T)
 *
 * https://en.cppreference.com/w/cpp/iterator/iterator
 */
template <class Category,
          class T,
          class Distance = std::ptrdiff_t,
          class Pointer = T*,
          class Reference = T&>
struct iterator {
  typedef Category iterator_category;
  typedef T value_type;
  typedef Distance difference_type;
  typedef Pointer pointer;
  typedef Reference reference;
};

/**
 * @brief Traits interface for iterators.
 *
 * https://en.cppreference.com/w/cpp/iterator/iterator_traits
 */
template <typename Iter>
struct iterator_traits {
  typedef typename Iter::difference_type difference_type;
  typedef typename Iter::value_type value_type;
  typedef typename Iter::pointer pointer;
  typedef typename Iter::reference reference;
  typedef typename Iter::iterator_category iterator_category;
};

#include "impl_iterator.tpp"

}  // namespace ft

#endif  // __IMPL_ITERATOR_H__
