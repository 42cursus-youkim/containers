#ifndef RBTREE_ITERATOR_HPP
#define RBTREE_ITERATOR_HPP

#include <utils/general/nullptr.hpp>
#include <utils/iter/tag.hpp>

namespace ft {
template <typename T, typename Node>
class tree_const_iterator;

template <typename T, typename Node>
class tree_iterator {
 public:
  typedef T                                value_type;
  typedef T*                               pointer;
  typedef T&                               reference;
  typedef Node                             node_pointer;
  typedef long                             difference_type;
  typedef unsigned long                    size_type;
  typedef ft::bidirectional_iterator_tag   iterator_category;
  typedef ft::tree_const_iterator<T, Node> const_iterator;

 private:
  node_pointer node_;

 public:
  /// Constructors & Destructor
  tree_iterator();
  tree_iterator(const node_pointer base);
  tree_iterator(const tree_iterator& other);
  tree_iterator(const const_iterator& other);

  ~tree_iterator();

  // getters
  node_pointer   base() const;

  node_pointer   min_child_from(node_pointer node) const;
  node_pointer   max_child_from(node_pointer node) const;
  bool           is_left_child() const;

  /// operator
  reference      operator*() const;
  pointer        operator->() const;

  bool           operator==(const tree_iterator& other) const;
  bool           operator!=(const tree_iterator& other) const;

  tree_iterator& operator=(const tree_iterator& other);

  tree_iterator& operator++();
  tree_iterator  operator++(int);

  tree_iterator& operator--();
  tree_iterator  operator--(int);
};

}  // namespace ft

#include "iterator.tpp"
#include "iterator_getter.tpp"
#include "iterator_operator.tpp"

#endif  // RBTREE_ITERATOR_HPP
