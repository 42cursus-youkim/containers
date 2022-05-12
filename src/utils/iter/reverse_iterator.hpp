#ifndef ITER_REVERSE_ITERATOR_HPP
#define ITER_REVERSE_ITERATOR_HPP

#include "iterator.hpp"
#include "traits.hpp"

namespace ft {
template <class Iterator>
class reverse_iterator
    : public ft::iterator<
          typename ft::iterator_traits<Iterator>::iterator_category,
          typename ft::iterator_traits<Iterator>::value_type,
          typename ft::iterator_traits<Iterator>::difference_type,
          typename ft::iterator_traits<Iterator>::pointer,
          typename ft::iterator_traits<Iterator>::reference> {
 public:
  typedef Iterator iterator_type;
  typedef Distance difference_type;
  typedef Pointer pointer;
  typedef Reference reference;
  typedef Category iterator_category;

 protected:
  Iterator current_;
  pointer get_last_element() {
    iterator_type temp(current_);
    return --temp;
  }

 public:
  /// default constructor
  reverse_iterator() : current_(){};

  /// copy constructor
  template <class Iter>
  reverse_iterator(const reverse_iterator<Iter>& rev_it)
      : current_(rev_it.base()){};

  /// initializatioon constructor
  explicit reverse_iterator(iterator_type it) : current_(it){};

  iterator_type base() const { return current_; }

  /// operator
  reference operator*() const;
  // reference operator*() const { return *(get_last_element()); }
  pointer operator->() const { return &(operator*()); }
  reference operator[](difference_type n) const {
    return *(get_last_element() - n);
  }

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
