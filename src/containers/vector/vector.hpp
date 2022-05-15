#ifndef VECTOR_VECTOR_HPP
#define VECTOR_VECTOR_HPP

#include <iter/reverse_iterator.hpp>
#include <iter/traits.hpp>
#include <iterator>
#include <memory>
#include <tmp/enable_if.hpp>
#include <vector>

#define FT_VECTOR_DEBUG 1

#define VECTOR_TYPE_ENABLE_IF_INPUTIT(type_)                           \
  typename enable_if<__is_input_iterator_tag<typename iterator_traits< \
                         InputIterator>::iterator_category>::value,    \
                     type_>::type

namespace ft {
template <class T, class Allocator = std::allocator<T> >
class vector {
 public:
  /// base type
  typedef T value_type;
  typedef Allocator allocator_type;
  typedef ptrdiff_t difference_type;
  typedef size_t size_type;

  /// pointers and reference
  typedef typename allocator_type::reference reference;
  typedef typename allocator_type::const_reference const_reference;
  typedef typename allocator_type::pointer pointer;
  typedef typename allocator_type::const_pointer const_pointer;

  /// iterators
  typedef pointer iterator;
  typedef const_pointer const_iterator;
  typedef ft::reverse_iterator<iterator> reverse_iterator;
  typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

 private:
  /// members
  pointer data_start_;
  pointer data_end_;
  pointer capacity_ptr_;
  Allocator allocator_;

 public:
  /// constructors

  explicit vector(const allocator_type& alloc = allocator_type());

  explicit vector(size_type n,
                  const value_type& val = value_type(),
                  const allocator_type& alloc = allocator_type());

  // template <class InputIterator>
  // vector(InputIterator first,
  //        VECTOR_ENABLE_IF_INPUTIT last,
  //        const allocator_type& alloc = allocator_type());

  vector(const vector& other);

  /// copy assignemnt operator
  vector& operator=(const vector& other);

  /// destructor
  ~vector();

  /// iterators
  iterator begin();
  const_iterator begin() const;
  iterator end();
  const_iterator end() const;

  /// reverse iterators
  reverse_iterator rbegin();
  const_reverse_iterator rbegin() const;
  reverse_iterator rend();
  const_reverse_iterator rend() const;

  /// capacity
  size_type size() const;
  size_type max_size() const;
  size_type capacity() const;
  bool empty() const;

  void reserve(size_type n);
  void resize(size_type n, value_type val = value_type());

  /// element access
  reference front();
  const_reference front() const;
  reference back();
  const_reference back() const;
  reference at(size_type n);
  const_reference at(size_type n) const;
  reference operator[](size_type n);
  const_reference operator[](size_type n) const;

  /// modifiers
  /// range
  template <class InputIterator>
  void assign(InputIterator first, InputIterator last);
  /// fill
  void assign(size_type n, const value_type& val);

  void push_back(const value_type& val);
  void pop_back();

  /// single element
  iterator insert(iterator position, const value_type& val);
  /// fill
  void insert(iterator position, size_type n, const value_type& val);
  /// range
  template <class InputIterator>
  VECTOR_TYPE_ENABLE_IF_INPUTIT(void)
  insert(iterator position, InputIterator first, InputIterator last);

  iterator erase(iterator position);
  iterator erase(iterator first, iterator last);

  void swap(vector& other);
  void clear();

  /// allocator
  allocator_type get_allocator() const;

 protected:
  /// implementation details
  iterator UninitializedFillN(size_type count, const value_type& val);
  size_type Index(iterator it) const;
  size_type GetNewCapacity(size_type at_least) const;
  inline iterator UnsafeMove(iterator from, iterator to);
  void DoGrow(size_type new_capacity);
  iterator LeftShift(iterator from, size_type amount);
  iterator RightShift(iterator from, size_type amount);
};

/// relational operators
template <class T, class Allocator>
bool operator==(const vector<T, Allocator>& lhs,
                const vector<T, Allocator>& rhs);

template <class T, class Allocator>
bool operator!=(const vector<T, Allocator>& lhs,
                const vector<T, Allocator>& rhs);

template <class T, class Allocator>
bool operator<(const vector<T, Allocator>& lhs,
               const vector<T, Allocator>& rhs);

template <class T, class Allocator>
bool operator<=(const vector<T, Allocator>& lhs,
                const vector<T, Allocator>& rhs);

template <class T, class Allocator>
bool operator>(const vector<T, Allocator>& lhs,
               const vector<T, Allocator>& rhs);

template <class T, class Allocator>
bool operator>=(const vector<T, Allocator>& lhs,
                const vector<T, Allocator>& rhs);

}  // namespace ft

#include "vector.tpp"

#endif  // VECTOR_VECTOR_HPP
