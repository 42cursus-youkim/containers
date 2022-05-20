#ifndef CONST_ITER_SET_HPP
#define CONST_ITER_SET_HPP

namespace ft {
template <typename T1>
class set_iterator;

template <typename Iterator>
class set_const_iterator {
 public:
  typedef typename Iterator::value_type        value_type;
  typedef typename Iterator::node_pointer      node_pointer;
  typedef typename Iterator::difference_type   difference_type;
  typedef typename Iterator::size_type         size_type;
  typedef const value_type*                    pointer;
  typedef const value_type&                    reference;
  typedef typename Iterator::iterator_category iterator_category;
  typedef ft::set_iterator<typename Iterator::tree_iterator>
      tree_iterator;

 private:
  Iterator _it;

 public:
  /// Constructors & Destructor

  set_const_iterator();
  set_const_iterator(const Iterator other);
  set_const_iterator(tree_iterator other);
  ~set_const_iterator();

  /// Copy Assignment Operator

  set_const_iterator& operator=(const set_const_iterator& other);

  Iterator            base() const;

  reference           operator*() const;
  pointer             operator->() const;

  set_const_iterator& operator++();
  set_const_iterator  operator++(int);

  set_const_iterator& operator--();
  set_const_iterator  operator--(int);

  bool operator==(const set_const_iterator& other) const;
  bool operator!=(const set_const_iterator& other) const;
};
}  // namespace ft

#include "set.tpp"
#include "set_operator.tpp"

#endif  // CONST_ITER_SET_HPP
