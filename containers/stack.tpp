#ifndef STACK_STACK_TPP
#define STACK_STACK_TPP

#include "stack.hpp"

namespace ft {

/// Constructors & Destructor
template <typename T, typename Container>
stack<T, Container>::stack(const container_type& ctnr) : c(ctnr) {}

template <typename T, typename Container>
stack<T, Container>::~stack() {}

template <typename T, typename Container>
bool stack<T, Container>::empty() const {
  return c.empty();
}

}  // namespace ft

#endif  // STACK_STACK_TPP
