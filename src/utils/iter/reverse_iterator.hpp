#ifndef ITER_REVERSE_ITERATOR_HPP
#define ITER_REVERSE_ITERATOR_HPP

#include "traits.hpp"

namespace ft {
template <class Iterator>
class reverse_iterator {
 public:
  typedef Iterator iterator_type;
  typedef typename ft::iterator_traits<Iterator>::Distance difference_type;
  typedef typename ft::iterator_traits<Iterator>::Pointer pointer;
  typedef typename ft::iterator_traits<Iterator>::Reference reference;
  typedef typename ft::iterator_traits<Iterator>::Category iterator_category;

 protected:
  Iterator current_;

 public:
  /// default constructor
  reverse_iterator() : current_(){};

  /// copy constructor
  template <class Iter>
  reverse_iterator(const reverse_iterator<Iter>& rev_it)
      : current_(rev_it.base()) {}

  /// initializatioon constructor
  explicit reverse_iterator(iterator_type it) : current_(it){};

  iterator_type base() const { return current_; }

  /// operator
  reference operator*() const;
  // reference operator*() const { return *(get_last_element()); }
  pointer operator->() const { return &(operator*()); }
  reference operator[](difference_type n) const { return current_[-1 - n]; }

  reverse_iterator operator+(difference_type n) const {
    return reverse_iterator(current_ - n);
  }
  reverse_iterator operator-(difference_type n) const {
    return reverse_iterator(current_ + n);
  }

  reverse_iterator& operator+=(difference_type n) {
    current_ -= n;
    return *this;
  }
  reverse_iterator& operator-=(difference_type n) {
    current_ += n;
    return *this;
  }

  reverse_iterator& operator++() {
    --current_;
    return *this;
  }

  reverse_iterator operator++(int) {
    reverse_iterator temp(current_);
    --current_;
    return temp;
  }

  reverse_iterator& operator--() {
    ++current_;
    return *this;
  }

  reverse_iterator operator--(int) {
    reverse_iterator temp(current_);
    ++current_;
    return temp;
  }
};

}  // namespace ft

#include "reverse_iterator.tpp"

#endif  // ITER_REVERSE_ITERATOR_HPP
