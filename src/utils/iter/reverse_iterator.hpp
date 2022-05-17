#ifndef ITER_REVERSE_ITERATOR_HPP
#define ITER_REVERSE_ITERATOR_HPP

#include "traits.hpp"

namespace ft {
template <typename Iterator>
class reverse_iterator {
 public:
  typedef Iterator iterator_type;
  typedef typename ft::iterator_traits<Iterator>::value_type value_type;
  typedef
      typename ft::iterator_traits<Iterator>::difference_type difference_type;
  typedef typename ft::iterator_traits<Iterator>::pointer pointer;
  typedef typename ft::iterator_traits<Iterator>::reference reference;
  typedef typename ft::iterator_traits<Iterator>::iterator_category
      iterator_category;

 private:
  Iterator current_;

 public:
  /// default constructor
  reverse_iterator();
  /// initialization constructor
  explicit reverse_iterator(iterator_type it);
  /// copy constructor
  template <class Iter>
  reverse_iterator(const reverse_iterator<Iter>& rev_it);

  /// getters
  iterator_type base() const;

  /// operator
  reference operator*() const;
  pointer operator->() const;
  reference operator[](difference_type n) const;

  reverse_iterator operator+(difference_type n) const;
  reverse_iterator operator-(difference_type n) const;

  reverse_iterator& operator+=(difference_type n);
  reverse_iterator& operator-=(difference_type n);

  reverse_iterator& operator++();
  reverse_iterator operator++(int);
  reverse_iterator& operator--();
  reverse_iterator operator--(int);
};

}  // namespace ft

#include "reverse_iterator.tpp"

#endif  // ITER_REVERSE_ITERATOR_HPP
