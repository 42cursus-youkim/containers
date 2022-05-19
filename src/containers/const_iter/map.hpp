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
  typedef const value_type&                    reference; // FIXME
  typedef typename Iterator::iterator_category iterator_category;
  typedef ft::map_iterator<typename Iterator::non_const_iterator>
      non_const_iterator;

 private:
  Iterator _it;

 public:
  map_const_iterator() {}

  map_const_iterator(const Iterator other) : _it(other) {}

  map_const_iterator(non_const_iterator other) : _it(other.base()) {}

  ~map_const_iterator() {}

  map_const_iterator& operator=(const map_const_iterator& other) {
    _it = other._it;
    return (*this);
  }

  Iterator            base() { return _it; }

  reference           operator*() const { return *_it; }

  pointer             operator->() const { return &(*_it); }

  map_const_iterator& operator++() {
    ++_it;
    return *this;
  }

  map_const_iterator operator++(int) {
    map_const_iterator temp(*this);
    ++(*this);
    return temp;
  }

  map_const_iterator& operator--() {
    --_it;
    return *this;
  }

  map_const_iterator operator--(int) {
    map_const_iterator temp(*this);
    --(*this);
    return temp;
  }

  bool operator==(const map_const_iterator& other) const {
    return this->_it == other._it;
  }

  bool operator!=(const map_const_iterator& other) const {
    return this->_it != other._it;
  }
};
}  // namespace ft

#endif  // CONST_ITER_MAP_HPP
