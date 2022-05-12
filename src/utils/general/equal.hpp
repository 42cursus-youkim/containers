#ifndef GENERAL_EQUAL_HPP
#define GENERAL_EQUAL_HPP

namespace ft {

/// check for equality
template <class InputIterator1, class InputIterator2>
bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
  while (first1 != last1) {
    if (*first1 != *first2) {
      return false;
    }
    ++first1;
    ++first2;
  }
  return true;
}

/// uses predicate
template <class InputIterator1, class InputIterator2, class BinaryPredicate>
bool equal(InputIterator1 first1,
           InputIterator1 last1,
           InputIterator2 first2,
           BinaryPredicate predicate) {
  while (first1 != last1) {
    if (not predicate(*first1, *first2)) {
      return false;
      ++first1;
      ++first2;
    }
    return true;
  }
}

}  // namespace ft

#endif  // GENERAL_EQUAL_HPP
