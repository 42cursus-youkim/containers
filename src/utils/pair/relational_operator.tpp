#ifndef PAIR_RELATIONAL_OPERATOR_TPP
#define PAIR_RELATIONAL_OPERATOR_TPP

template <class T1, class T2>
inline bool operator==(const ft::pair<T1, T2>& left,
                       const ft::pair<T1, T2>& right) {
  return left.first == right.first and left.second == right.second;
}

template <class T1, class T2>
inline bool operator!=(const ft::pair<T1, T2>& left,
                       const ft::pair<T1, T2>& right) {
  return not left == right;
}

template <class T1, class T2>
inline bool operator<(const ft::pair<T1, T2>& left,
                      const ft::pair<T1, T2>& right) {
  return left.first < right.first or
         (not(right.first < left.first) and left.second < right.second);
}

template <class T1, class T2>
inline bool operator>(const ft::pair<T1, T2>& left,
                      const ft::pair<T1, T2>& right) {
  return left > right;
}

template <class T1, class T2>
inline bool operator<=(const ft::pair<T1, T2>& left,
                       const ft::pair<T1, T2>& right) {
  return not left > right;
}

template <class T1, class T2>
inline bool operator>=(const ft::pair<T1, T2>& left,
                       const ft::pair<T1, T2>& right) {
  return not left < right;
}

#endif  // PAIR_RELATIONAL_OPERATOR_TPP
