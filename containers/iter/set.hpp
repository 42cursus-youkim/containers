#ifndef ITER_SET_HPP
#define ITER_SET_HPP

namespace ft {
template <typename T1>
class set_const_iterator;

template <typename Iterator>
class set_iterator {
 public:
  typedef typename Iterator::value_type        value_type;
  typedef typename Iterator::node_pointer      node_pointer;
  typedef const value_type*                    pointer;
  typedef const value_type&                    reference;
  typedef typename Iterator::difference_type   difference_type;
  typedef typename Iterator::size_type         size_type;
  typedef typename Iterator::iterator_category iterator_category;
  typedef ft::set_const_iterator<typename Iterator::const_iterator>
      const_iterator;

 private:
  Iterator it_;

 public:
  /// Constructors & Destructor
  set_iterator();
  set_iterator(const Iterator other);
  set_iterator(const_iterator other);
  ~set_iterator();

  /// Copy Assignment Operator
  set_iterator& operator=(const set_iterator& other);

  Iterator      base() const;
  
  /// Operators
  reference     operator*() const;
  pointer       operator->() const;

  set_iterator& operator++();
  set_iterator  operator++(int);

  set_iterator& operator--();
  set_iterator  operator--(int);

  bool          operator==(const set_iterator& other) const;
  bool          operator!=(const set_iterator& other) const;
};
}  // namespace ft

#include "set.tpp"
#include "set_operator.tpp"

#endif  // ITER_SET_HPP
