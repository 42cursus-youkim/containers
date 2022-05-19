#ifndef GENERAL_LEXICOGRAPHICAL_COMPARE_HPP
#define GENERAL_LEXICOGRAPHICAL_COMPARE_HPP

namespace ft {

/// helper function for lexicographical_compare
template <typename InputIterator1,
          typename InputIterator2,
          typename Compare>
static inline bool is_right_bigger(InputIterator1 it1,
                                   InputIterator2 it2,
                                   Compare        comp) {
  /// result of comp(it1, it2) is same as it1 < it2
  return comp(*it1, *it2);
}

template <typename InputIterator1,
          typename InputIterator2,
          typename Compare>
static inline bool is_left_bigger(InputIterator1 it1,
                                  InputIterator2 it2,
                                  Compare        comp) {
  return not is_right_bigger(it1, it2, comp);
}

/// default
template <typename InputIterator1, typename InputIterator2>
bool lexicographical_compare(InputIterator1 first1,
                             InputIterator1 last1,
                             InputIterator2 first2,
                             InputIterator2 last2) {
  for (; first1 != last1; ++first1, ++first2) {
    if (first2 == last2 or *first1 > *first2)
      return false;
    else if (*first1 < *first2)
      return true;
  }
  return (first2 != last2);
}

/// use custom compare function
template <typename InputIterator1,
          typename InputIterator2,
          typename Compare>
bool lexicographical_compare(InputIterator1 first1,
                             InputIterator1 last1,
                             InputIterator2 first2,
                             InputIterator2 last2,
                             Compare        comp) {
  for (; first1 != last1; ++first1, ++first2) {
    if (first2 == last2 or is_left_bigger(first1, first2, comp))
      return false;
    else if (is_right_bigger(*first1, *first2, comp))
      return true;
  }
  return (first2 != last2);
}

}  // namespace ft

#endif  // GENERAL_LEXICOGRAPHICAL_COMPARE_HPP
