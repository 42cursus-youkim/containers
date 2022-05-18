#ifndef CONST_ITER_SET_HPP
#define CONST_ITER_SET_HPP

namespace ft {
template <typename T1>
class set_iterator;

template <typename Iterator>
class set_const_iterator {
 public:
  typedef typename Iterator::value_type value_type;
  typedef typename Iterator::node_pointer node_pointer;
  typedef typename Iterator::difference_type difference_type;
  typedef typename Iterator::size_type size_type;
  typedef const value_type* pointer;
  typedef const value_type& reference;
  typedef typename Iterator::iterator_category iterator_category;
  typedef ft::set_iterator<typename Iterator::non_const_iterator>
      non_const_iterator;

 private:
  Iterator _it;

 public:
  set_const_iterator() {}

  set_const_iterator(const Iterator x) : _it(x) {}

  set_const_iterator(non_const_iterator x) : _it(x.base()) {}

  ~set_const_iterator() {}

  set_const_iterator& operator=(const set_const_iterator& x) {
    _it = x._it;
    return (*this);
  }

  Iterator base() const { return _it; }

  reference operator*() const { return *_it; }

  pointer operator->() const { return &(*_it); }

  set_const_iterator& operator++() {
    ++_it;
    return *this;
  }

  set_const_iterator operator++(int) {
    set_const_iterator temp(*this);
    ++(*this);
    return temp;
  }

  set_const_iterator& operator--() {
    --_it;
    return *this;
  }

  set_const_iterator operator--(int) {
    set_const_iterator temp(*this);
    --(*this);
    return temp;
  }

  bool operator==(const set_const_iterator& x) const {
    return this->_it == x._it;
  }

  bool operator!=(const set_const_iterator& x) const {
    return this->_it != x._it;
  }
};
}  // namespace ft

#endif  // CONST_ITER_SET_HPP
