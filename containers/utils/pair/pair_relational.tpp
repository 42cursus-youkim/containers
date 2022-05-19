#ifndef PAIR_PAIR_RELATIONAL_TPP
#define PAIR_PAIR_RELATIONAL_TPP

#include "pair.hpp"

namespace ft {

template <typename T1, typename T2>
bool operator==(const pair<T1, T2>& left, const pair<T1, T2>& right) {
  return left.first == right.first and left.second == right.second;
}

template <typename T1, typename T2>
bool operator!=(const pair<T1, T2>& left, const pair<T1, T2>& right) {
  return not(left == right);
}

template <typename T1, typename T2>
bool operator<(const pair<T1, T2>& left, const pair<T1, T2>& right) {
  return (left.first < right.first) or
         (not(right.first < left.first) and
          left.second < right.second);
}

template <typename T1, typename T2>
bool operator>(const pair<T1, T2>& left, const pair<T1, T2>& right) {
  return right < left;  // NOTE: right and left position reversed
}

template <typename T1, typename T2>
bool operator<=(const pair<T1, T2>& left, const pair<T1, T2>& right) {
  return not(right < left);  // NOTE: right and left position reversed
}

template <typename T1, typename T2>
bool operator>=(const pair<T1, T2>& left, const pair<T1, T2>& right) {
  return not(left < right);
}

}  // namespace ft

#endif // PAIR_PAIR_RELATIONAL_TPP
