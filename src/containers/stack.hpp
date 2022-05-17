#ifndef STACK_STACK_HPP
#define STACK_STACK_HPP

#include "vector.hpp"

namespace ft {

template <typename T, typename Container = ft::vector<T> >
class stack {
 public:
  typedef T value_type;
  typedef Container container_type;
  typedef size_t size_type;

 protected:
  container_type container_;

 public:
  /// Constructors & Destructor
  explicit stack(const container_type& ctnr = container_type());
  ~stack();

  /// getters
  bool empty() const;
  size_type size() const;
  value_type& top();
  const value_type& top() const;

  /// modifiers
  void push(const value_type& val);
  void pop();

  /// friend relational operator
  template <typename Tn, typename ContainerN>
  friend bool operator==(const stack<Tn, ContainerN>& lhs,
                         const stack<Tn, ContainerN>& rhs);

  template <typename Tn, typename ContainerN>
  friend bool operator!=(const stack<Tn, ContainerN>& lhs,
                         const stack<Tn, ContainerN>& rhs);

  template <typename Tn, typename ContainerN>
  friend bool operator<(const stack<Tn, ContainerN>& lhs,
                        const stack<Tn, ContainerN>& rhs);

  template <typename Tn, typename ContainerN>
  friend bool operator<=(const stack<Tn, ContainerN>& lhs,
                         const stack<Tn, ContainerN>& rhs);

  template <typename Tn, typename ContainerN>
  friend bool operator>(const stack<Tn, ContainerN>& lhs,
                        const stack<Tn, ContainerN>& rhs);

  template <typename Tn, typename ContainerN>
  friend bool operator>=(const stack<Tn, ContainerN>& lhs,
                         const stack<Tn, ContainerN>& rhs);
};

}  // namespace ft

#include "stack.tpp"

#endif  // STACK_STACK_HPP
