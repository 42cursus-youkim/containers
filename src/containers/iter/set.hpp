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
  //  typedef typename Iterator::pointer pointer;
  //  typedef typename Iterator::reference reference;
  typedef const value_type*                    pointer;
  typedef const value_type&                    reference;
  typedef typename Iterator::difference_type   difference_type;
  typedef typename Iterator::size_type         size_type;
  typedef typename Iterator::iterator_category iterator_category;
  typedef ft::set_const_iterator<typename Iterator::const_iterator>
      const_iterator;

 private:
  Iterator _it;

 public:
  set_iterator() {}

  set_iterator(const Iterator x) : _it(x) {}

  set_iterator(const_iterator x) : _it(x.base()) {}

  ~set_iterator() {}

  set_iterator& operator=(const set_iterator& x) {
    _it = x._it;
    return (*this);
  }

  Iterator      base() const { return _it; }

  reference     operator*() const { return *_it; }

  pointer       operator->() const { return &(*_it); }

  set_iterator& operator++() {
    ++_it;
    return *this;
  }

  set_iterator operator++(int) {
    set_iterator temp(*this);
    ++(*this);
    return temp;
  }

  set_iterator& operator--() {
    --_it;
    return *this;
  }

  set_iterator operator--(int) {
    set_iterator temp(*this);
    --(*this);
    return temp;
  }

  bool operator==(const set_iterator& x) const {
    return this->_it == x._it;
  }

  bool operator!=(const set_iterator& x) const {
    return this->_it != x._it;
  }
};
}  // namespace ft

#endif  // ITER_SET_HPP
