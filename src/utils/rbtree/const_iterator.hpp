#ifndef RBTREE_CONST_ITERATOR_HPP
#define RBTREE_CONST_ITERATOR_HPP

#include <utils/rbtree/iterator.hpp>

namespace ft {

template <class T, class NodePtr>
class tree_const_iterator {
  // * typedef
 public:
  typedef T                              value_type;
  typedef const T*                       pointer;
  typedef const T&                       reference;
  typedef NodePtr                        node_pointer;
  typedef long                           difference_type;
  typedef unsigned long                  size_type;
  typedef ft::bidirectional_iterator_tag iterator_category;
  typedef ft::tree_iterator<T, NodePtr>  non_const_iterator;

 private:
  // * private member
  node_pointer node_;

 public:
  // * constructor
  tree_const_iterator();
  tree_const_iterator(const node_pointer other);
  tree_const_iterator(const tree_const_iterator& other);
  tree_const_iterator(non_const_iterator other);
  ~tree_const_iterator();

  // Getters/Setters

  node_pointer base() const;
  void         tree_min(node_pointer node);
  void         tree_max(node_pointer node);
  bool         tree_is_left_child() const;

  // Operators
  reference    operator*() const;
  pointer      operator->() const;

  bool         operator==(const tree_const_iterator& other) const;
  bool         operator!=(const tree_const_iterator& other) const;

  tree_const_iterator& operator=(const tree_const_iterator& other);

  tree_const_iterator& operator++();
  tree_const_iterator  operator++(int);

  tree_const_iterator& operator--();
  tree_const_iterator  operator--(int);
};

}  // namespace ft

#include "const_iterator.tpp"

#endif  // RBTREE_CONST_ITERATOR_HPP
