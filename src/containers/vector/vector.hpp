#ifndef VECTOR_VECTOR_HPP
#define VECTOR_VECTOR_HPP

#include <iter/reverse_iterator.hpp>
#include <iter/traits.hpp>
#include <iterator>
#include <memory>
#include <vector>

namespace ft {

template <class T, class Alloc = std::allocator<T> >
class vector {
 public:
  /// base type
  typedef T value_type;
  typedef Alloc allocator_type;
  typedef ptrdiff_t difference_type;
  typedef size_t size_type;

  /// pointers and reference
  typedef typename allocator_type::reference reference;
  typedef typename allocator_type::const_reference const_reference;
  typedef typename allocator_type::pointer pointer;
  typedef typename allocator_type::const_pointer const_pointer;

  /// iterators
  typedef std::iterator<pointer, vector>
      iterator;  //< convertible to const_iterator
  typedef std::iterator<const_pointer, vector> const_iterator;
  typedef ft::reverse_iterator<iterator> reverse_iterator;
  typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

 private:
  /// members
  value_type* data_;
  size_type size_;
  size_type capacity_;
  allocator_type allocator_;

 public:
  /// constructors
  explicit vector(const allocator_type& alloc = allocator_type());

  explicit vector(size_type n,
                  const value_type& val = value_type(),
                  const allocator_type& alloc = allocator_type());

  template <class InputIterator>
  vector(InputIterator first,
         InputIterator last,
         const allocator_type& alloc = allocator_type());

  vector(const vector& other);

  /// copy assignemnt operator
  vector& operator=(const vector& other);

  /// destructor
  ~vector();

};

}  // namespace ft

#include "vector.tpp"

#endif  // VECTOR_VECTOR_HPP
