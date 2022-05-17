#ifndef STACK_STACK_TPP
#define STACK_STACK_TPP

#include "stack.hpp"

namespace ft {

/// Constructors & Destructor
template <typename T, typename Container>
stack<T, Container>::stack(const container_type& ctnr) : container_(ctnr) {}

template <typename T, typename Container>
stack<T, Container>::~stack() {}

template <typename T, typename Container>
bool stack<T, Container>::empty() const {
  return container_.empty();
}

/// getters
template <typename T, typename Container>
typename stack<T, Container>::size_type stack<T, Container>::size() const {
  return container_.size();
}

template <typename T, typename Container>
typename stack<T, Container>::value_type& stack<T, Container>::top() {
  return container_.back();
}

template <typename T, typename Container>
const typename stack<T, Container>::value_type& stack<T, Container>::top()
    const {
  return container_.back();
}

/// modifiers
template <typename T, typename Container>
void stack<T, Container>::push(const value_type& val) {
  container_.push_back(val);
}

template <typename T, typename Container>
void stack<T, Container>::pop() {
  container_.pop_back();
}

/// relational operator
template <typename T, typename Container>
bool operator==(const stack<T, Container>& lhs,
                const stack<T, Container>& rhs) {
  return lhs.container_ == rhs.container_;
}

template <typename T, typename Container>
bool operator!=(const stack<T, Container>& lhs,
                const stack<T, Container>& rhs) {
  return lhs.container_ != rhs.container_;
}

template <typename T, typename Container>
bool operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
  return lhs.container_ < rhs.container_;
}

template <typename T, typename Container>
bool operator<=(const stack<T, Container>& lhs,
                const stack<T, Container>& rhs) {
  return lhs.container_ <= rhs.container_;
}

template <typename T, typename Container>
bool operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
  return lhs.container_ > rhs.container_;
}

template <typename T, typename Container>
bool operator>=(const stack<T, Container>& lhs,
                const stack<T, Container>& rhs) {
  return lhs.container_ >= rhs.container_;
}

}  // namespace ft

#endif  // STACK_STACK_TPP
