#ifndef PAIR_PAIR_TPP
#define PAIR_PAIR_TPP

#ifndef PAIR_PAIR_HPP
#error __FILE__ should not be included twice
#endif

namespace ft {

template <class T1, class T2>
pair<T1, T2> make_pair(T1 x, T2 y) {
  return (pair<T1, T2>(x, y));
}

/// relational operators

template <class T1, class T2>
inline bool operator==(const pair<T1, T2>& left, const pair<T1, T2>& right) {
  return left.first == right.first and left.second == right.second;
}

template <class T1, class T2>
inline bool operator!=(const pair<T1, T2>& left, const pair<T1, T2>& right) {
  return not(left == right);
}

template <class T1, class T2>
inline bool operator<(const pair<T1, T2>& left, const pair<T1, T2>& right) {
  return left.first < right.first or
         (not(right.first < left.first) and left.second < right.second);
}

template <class T1, class T2>
inline bool operator>(const pair<T1, T2>& left, const pair<T1, T2>& right) {
  return left > right;
}

template <class T1, class T2>
inline bool operator<=(const pair<T1, T2>& left, const pair<T1, T2>& right) {
  return not(left > right);
}

template <class T1, class T2>
inline bool operator>=(const pair<T1, T2>& left, const pair<T1, T2>& right) {
  return not(left < right);
}

}  // namespace ft

#endif  // PAIR_MAKE_PAIR_TPP
