#ifndef ITER_MAP_HPP
#define ITER_MAP_HPP

namespace ft {
template <typename Iterator>
class map_const_iterator;

template <typename Iterator>
class map_iterator {
 public:
  typedef typename Iterator::value_type        value_type;
  typedef typename Iterator::node_pointer      node_pointer;
  typedef typename Iterator::difference_type   difference_type;
  typedef typename Iterator::size_type         size_type;
  typedef typename Iterator::pointer           pointer;
  typedef typename Iterator::reference         reference;
  typedef typename Iterator::iterator_category iterator_category;

 private:
  Iterator it_;

 public:
  /// Constructors & Destructor
  map_iterator();
  map_iterator(const Iterator other);
  ~map_iterator();

  /// Assignment Operator
  map_iterator& operator=(const map_iterator& other);

  Iterator      base();

  reference     operator*() const;
  pointer       operator->() const;

  map_iterator& operator++();
  map_iterator  operator++(int);

  map_iterator& operator--();
  map_iterator  operator--(int);

  bool          operator==(const map_iterator& other) const;
  bool          operator!=(const map_iterator& other) const;
};

}  // namespace ft

#include "map.tpp"
#include "map_operator.tpp"

#endif  // ITER_MAP_HPP
