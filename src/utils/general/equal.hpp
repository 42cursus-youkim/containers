#ifndef GENERAL_EQUAL_HPP
#define GENERAL_EQUAL_HPP

namespace ft {

template <class InputIterator1, class InputIterator2, class BinaryPredicate>
static inline bool is_equal(InputIterator1 it1,
                            InputIterator2 it2,
                            BinaryPredicate predicate) {
  return predicate(*it1, *it2) == 0;
}

/// check for equality
template <class InputIterator1, class InputIterator2>
bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
  for (; first1 != last1; ++first1, ++first2) {
    if (*first1 != *first2)
      return false;
  }
  return true;
}

/// uses predicate
template <class InputIterator1, class InputIterator2, class BinaryPredicate>
bool equal(InputIterator1 first1,
           InputIterator1 last1,
           InputIterator2 first2,
           BinaryPredicate predicate) {
  for (; first1 != last1; ++first1, ++first2) {
    if (not is_equal(*first1, *first2, predicate))
      return false;
  }
  return true;
}

}  // namespace ft

#endif  // GENERAL_EQUAL_HPP
