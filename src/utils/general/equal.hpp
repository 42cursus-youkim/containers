#ifndef GENERAL_EQUAL_HPP
#define GENERAL_EQUAL_HPP

namespace ft {
template <class InputIterator1, class InputIterator2>
bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2);

template <class InputIterator1, class InputIterator2, class BinaryPredicate>
bool equal(InputIterator1 first1,
           InputIterator1 last1,
           InputIterator2 first2,
           BinaryPredicate pred);
}  // namespace ft

#endif // GENERAL_EQUAL_HPP