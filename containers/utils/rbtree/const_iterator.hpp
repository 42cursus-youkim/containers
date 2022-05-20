#ifndef RBTREE_CONST_ITERATOR_HPP
#define RBTREE_CONST_ITERATOR_HPP

#include <utils/rbtree/iterator.hpp>

namespace ft {

template <typename T, typename NodePtr>
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
  typedef ft::tree_iterator<T, NodePtr>  tree_iterator;

 private:
  node_pointer node_;

 public:
  /// Constructors & Destructor
  tree_const_iterator();
  tree_const_iterator(const node_pointer base);
  tree_const_iterator(const tree_const_iterator& other);
  tree_const_iterator(const tree_iterator &other);

  ~tree_const_iterator();

  /// Copy Assignment Operator
  tree_const_iterator& operator=(const tree_const_iterator& other);

  /// Getters/Setters

  node_pointer         base() const;
  node_pointer         min_child_from(node_pointer node) const;
  node_pointer         max_child_from(node_pointer node) const;
  bool                 is_left_child() const;

  // Operators
  reference            operator*() const;
  pointer              operator->() const;

  bool operator==(const tree_const_iterator& other) const;
  bool operator!=(const tree_const_iterator& other) const;

  tree_const_iterator& operator++();
  tree_const_iterator  operator++(int);

  tree_const_iterator& operator--();
  tree_const_iterator  operator--(int);
};

}  // namespace ft

#include "const_iterator.tpp"
#include "const_iterator_getter.tpp"
#include "const_iterator_operator.tpp"

#endif  // RBTREE_CONST_ITERATOR_HPP
