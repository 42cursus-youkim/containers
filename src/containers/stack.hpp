#ifndef STACK_STACK_HPP
#define STACK_STACK_HPP

#include "vector.hpp"

namespace ft {

template <class T, class Container = std::vector<T> >
class stack {
 public:
  typedef T value_type;
  typedef Container container_type;
  typedef size_t size_type;

 protected:
  container_type container_;

 public:
  explicit stack(const container_type& ctnr = container_type())
      : container_(ctnr) {}

  ~stack() {}

  bool empty() const { return container_.empty(); }
  size_type size() const { return container_.size(); }
  value_type& top() { return container_.back(); }
  const value_type& top() const { return container_.back(); }
  void push(const value_type& val) { container_.push_back(val); }
  void pop() { container_.pop_back(); }

  template <class Tn, class ContainerN>
  friend bool operator==(const stack<Tn, ContainerN>& lhs,
                         const stack<Tn, ContainerN>& rhs);

  template <class Tn, class ContainerN>
  friend bool operator!=(const stack<Tn, ContainerN>& lhs,
                         const stack<Tn, ContainerN>& rhs);

  template <class Tn, class ContainerN>
  friend bool operator<(const stack<Tn, ContainerN>& lhs,
                        const stack<Tn, ContainerN>& rhs);

  template <class Tn, class ContainerN>
  friend bool operator<=(const stack<Tn, ContainerN>& lhs,
                         const stack<Tn, ContainerN>& rhs);

  template <class Tn, class ContainerN>
  friend bool operator>(const stack<Tn, ContainerN>& lhs,
                        const stack<Tn, ContainerN>& rhs);

  template <class Tn, class ContainerN>
  friend bool operator>=(const stack<Tn, ContainerN>& lhs,
                         const stack<Tn, ContainerN>& rhs);
};

template <class T, class Container>
bool operator==(const stack<T, Container>& lhs,
                const stack<T, Container>& rhs) {
  return lhs.container_ == rhs.container_;
}

template <class T, class Container>
bool operator!=(const stack<T, Container>& lhs,
                const stack<T, Container>& rhs) {
  return lhs.container_ != rhs.container_;
}

template <class T, class Container>
bool operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
  return lhs.container_ < rhs.container_;
}

template <class T, class Container>
bool operator<=(const stack<T, Container>& lhs,
                const stack<T, Container>& rhs) {
  return lhs.container_ <= rhs.container_;
}

template <class T, class Container>
bool operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
  return lhs.container_ > rhs.container_;
}

template <class T, class Container>
bool operator>=(const stack<T, Container>& lhs,
                const stack<T, Container>& rhs) {
  return lhs.container_ >= rhs.container_;
}

}  // namespace ft

#endif  // STACK_STACK_HPP
