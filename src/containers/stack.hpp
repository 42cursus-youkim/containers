#ifndef STACK_STACK_HPP
#define STACK_STACK_HPP

#include "vector.hpp"

namespace ft {

template <typename T, typename Container = ft::vector<T> >
class stack {
 public:
  typedef T         value_type;
  typedef Container container_type;
  typedef size_t    size_type;

 protected:
  container_type container_;

 public:
  /// Constructors & Destructor
  explicit stack(const container_type& ctnr = container_type());
  ~stack();

  /// getters
  bool              empty() const;
  size_type         size() const;
  value_type&       top();
  const value_type& top() const;

  /// modifiers
  void              push(const value_type& val);
  void              pop();

  /// friend relational operator
  template <typename Tn, typename ContainerN>
  friend bool operator==(const stack<Tn, ContainerN>& left,
                         const stack<Tn, ContainerN>& right);

  template <typename Tn, typename ContainerN>
  friend bool operator!=(const stack<Tn, ContainerN>& left,
                         const stack<Tn, ContainerN>& right);

  template <typename Tn, typename ContainerN>
  friend bool operator<(const stack<Tn, ContainerN>& left,
                        const stack<Tn, ContainerN>& right);

  template <typename Tn, typename ContainerN>
  friend bool operator<=(const stack<Tn, ContainerN>& left,
                         const stack<Tn, ContainerN>& right);

  template <typename Tn, typename ContainerN>
  friend bool operator>(const stack<Tn, ContainerN>& left,
                        const stack<Tn, ContainerN>& right);

  template <typename Tn, typename ContainerN>
  friend bool operator>=(const stack<Tn, ContainerN>& left,
                         const stack<Tn, ContainerN>& right);
};

}  // namespace ft

#include "stack.tpp"
#include "stack_modifier.tpp"
#include "stack_property.tpp"
#include "stack_relational.tpp"

#endif  // STACK_STACK_HPP
