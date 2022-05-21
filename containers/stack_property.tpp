#ifndef CONTAINERS_STACK_PROPERTY_TPP
#define CONTAINERS_STACK_PROPERTY_TPP

#include "stack.hpp"

namespace ft {

template <typename T, typename Container>
typename stack<T, Container>::size_type stack<T, Container>::size()
    const {
  return c.size();
}

template <typename T, typename Container>
typename stack<T, Container>::value_type& stack<T, Container>::top() {
  return c.back();
}

template <typename T, typename Container>
const typename stack<T, Container>::value_type&
stack<T, Container>::top() const {
  return c.back();
}

}  // namespace ft

#endif  // CONTAINERS_STACK_PROPERTY_TPP
