#ifndef CONTAINERS_STACK_RELATIONAL_TPP
#define CONTAINERS_STACK_RELATIONAL_TPP

#include "stack.hpp"

namespace ft {

/// relational operator
template <typename T, typename Container>
bool operator==(const stack<T, Container>& left,
                const stack<T, Container>& right) {
  return left.container_ == right.container_;
}

template <typename T, typename Container>
bool operator!=(const stack<T, Container>& left,
                const stack<T, Container>& right) {
  return left.container_ != right.container_;
}

template <typename T, typename Container>
bool operator<(const stack<T, Container>& left,
               const stack<T, Container>& right) {
  return left.container_ < right.container_;
}

template <typename T, typename Container>
bool operator<=(const stack<T, Container>& left,
                const stack<T, Container>& right) {
  return left.container_ <= right.container_;
}

template <typename T, typename Container>
bool operator>(const stack<T, Container>& left,
               const stack<T, Container>& right) {
  return left.container_ > right.container_;
}

template <typename T, typename Container>
bool operator>=(const stack<T, Container>& left,
                const stack<T, Container>& right) {
  return left.container_ >= right.container_;
}

}  // namespace ft

#endif // CONTAINERS_STACK_RELATIONAL_TPP
