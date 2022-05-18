#ifndef ITER_MAP_HPP
#define ITER_MAP_HPP

namespace ft {
template <typename Iterator>
class map_iterator {
 public:
  typedef typename Iterator::value_type value_type;
  typedef typename Iterator::node_pointer node_pointer;
  typedef typename Iterator::pointer pointer;
  typedef typename Iterator::reference reference;
  typedef typename Iterator::difference_type difference_type;
  typedef typename Iterator::size_type size_type;
  typedef typename Iterator::iterator_category iterator_category;

 private:
  Iterator _it;

 public:
  map_iterator() {}

  map_iterator(const Iterator x) : _it(x) {}

  ~map_iterator() {}

  map_iterator& operator=(const map_iterator& x) {
    _it = x._it;
    return (*this);
  }

  Iterator base() { return _it; }

  reference operator*() const { return *_it; }

  pointer operator->() const { return &(*_it); }

  map_iterator& operator++() {
    ++_it;
    return *this;
  }

  map_iterator operator++(int) {
    map_iterator temp(*this);
    ++(*this);
    return temp;
  }

  map_iterator& operator--() {
    --_it;
    return *this;
  }

  map_iterator operator--(int) {
    map_iterator temp(*this);
    --(*this);
    return temp;
  }

  bool operator==(const map_iterator& x) const {
    return this->_it == x._it;
  }

  bool operator!=(const map_iterator& x) const {
    return this->_it != x._it;
  }
};

}  // namespace ft

#endif // ITER_MAP_HPP
