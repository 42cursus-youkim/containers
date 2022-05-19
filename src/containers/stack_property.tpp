#ifndef CONTAINERS_STACK_PROPERTY_TPP
#define CONTAINERS_STACK_PROPERTY_TPP

#include "stack.hpp"

namespace ft {

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

}  // namespace ft

#endif // CONTAINERS_STACK_PROPERTY_TPP
