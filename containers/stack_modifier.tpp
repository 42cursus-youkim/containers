#ifndef CONTAINERS_STACK_MODIFIER_TPP
#define CONTAINERS_STACK_MODIFIER_TPP

#include "stack.hpp"

namespace ft {

template <typename T, typename Container>
void stack<T, Container>::push(const value_type& val) {
  c.push_back(val);
}

template <typename T, typename Container>
void stack<T, Container>::pop() {
  c.pop_back();
}

}  // namespace ft

#endif  // CONTAINERS_STACK_MODIFIER_TPP
