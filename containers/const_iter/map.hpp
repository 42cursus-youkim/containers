#ifndef CONST_ITER_MAP_HPP
#define CONST_ITER_MAP_HPP

namespace ft {

template <typename Iterator>
class map_iterator;

template <typename Iterator>
class map_const_iterator {
 public:
  typedef typename Iterator::value_type        value_type;
  typedef typename Iterator::node_pointer      node_pointer;
  typedef typename Iterator::difference_type   difference_type;
  typedef typename Iterator::size_type         size_type;
  typedef const value_type*                    pointer;
  typedef const value_type&                    reference;
  typedef typename Iterator::iterator_category iterator_category;
  typedef ft::map_iterator<typename Iterator::tree_iterator>
      tree_iterator;

 private:
  Iterator it_;

 public:
  /// Constructors & Destructor
  map_const_iterator();
  map_const_iterator(const Iterator other);
  map_const_iterator(tree_iterator other);
  ~map_const_iterator();

  /// Copy Assignment Operator
  map_const_iterator& operator=(const map_const_iterator& other);

  /// Getters
  Iterator            base();

  /// Operators
  reference           operator*() const;
  pointer             operator->() const;

  map_const_iterator& operator++();
  map_const_iterator  operator++(int);

  map_const_iterator& operator--();
  map_const_iterator  operator--(int);

  bool operator==(const map_const_iterator& other) const;
  bool operator!=(const map_const_iterator& other) const;
};
}  // namespace ft

#include "map.tpp"
#include "map_operator.tpp"

#endif  // CONST_ITER_MAP_HPP
