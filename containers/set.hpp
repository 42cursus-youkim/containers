#ifndef CONTAINERS_SET_HPP
#define CONTAINERS_SET_HPP

#include <const_iter/set.hpp>
#include <functional>
#include <iter/set.hpp>
#include <memory>
#include <utils/general/binary_function.hpp>
#include <utils/general/equal.hpp>
#include <utils/general/lexicographical_compare.hpp>
#include <utils/iter/reverse_iterator.hpp>
#include <utils/pair/pair.hpp>
#include <utils/rbtree/rbtree.hpp>

namespace ft {

template <typename T,
          typename Compare   = std::less<T>,
          typename Allocator = std::allocator<T> >
class set {
 public:
  typedef T                                        key_type;
  typedef T                                        value_type;
  typedef Compare                                  key_compare;
  typedef Compare                                  value_compare;

  typedef Allocator                                allocator_type;
  typedef typename allocator_type::reference       reference;
  typedef typename allocator_type::const_reference const_reference;
  typedef typename allocator_type::pointer         pointer;
  typedef typename allocator_type::const_pointer   const_pointer;
  typedef typename allocator_type::difference_type difference_type;
  typedef typename allocator_type::size_type       size_type;

  typedef ft::rbtree<value_type, key_compare>      tree_type;
  typedef ft::set_iterator<typename tree_type::iterator> iterator;
  typedef ft::set_const_iterator<typename tree_type::const_iterator>
                                               const_iterator;
  typedef ft::reverse_iterator<iterator>       reverse_iterator;
  typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

 private:
  key_compare    comp_;
  allocator_type alloc_;
  tree_type      tree_;

 public:
  /// Constructors & Destructor
  explicit set(const key_compare&    comp  = key_compare(),
               const allocator_type& alloc = allocator_type());

  template <typename InputIterator>
  set(InputIterator         first,
      InputIterator         last,
      const key_compare&    comp  = key_compare(),
      const allocator_type& alloc = allocator_type());

  set(const set& other);
  ~set();

  /// Operators
  set&                     operator=(const set& other);

  /// iterator
  iterator                 begin();
  const_iterator           begin() const;
  iterator                 end();
  const_iterator           end() const;

  reverse_iterator         rbegin();
  const_reverse_iterator   rbegin() const;
  reverse_iterator         rend();
  const_reverse_iterator   rend() const;

  /// capacity
  bool                     empty() const;
  size_type                size() const;
  size_type                max_size() const;

  /// modifiers
  ft::pair<iterator, bool> insert(const value_type& val);
  iterator insert(iterator position, const value_type& val);
  template <typename InputIterator>
  void           insert(InputIterator first, InputIterator last);
  void           erase(iterator position);
  size_type      erase(const value_type& val);
  void           erase(iterator first, iterator last);
  void           swap(set& other);
  void           clear();

  // observers
  key_compare    key_comp() const;
  value_compare  value_comp() const;

  // operations
  iterator       find(const value_type& val);
  const_iterator find(const value_type& val) const;
  size_type      count(const key_type& key) const;
  iterator       lower_bound(const key_type& key);
  const_iterator lower_bound(const key_type& key) const;
  iterator       upper_bound(const key_type& key);
  const_iterator upper_bound(const key_type& key) const;
  pair<iterator, iterator> equal_range(const key_type& key);
  pair<const_iterator, const_iterator> equal_range(
      const key_type& key) const;

  // allocator
  allocator_type get_allocator() const;
};

}  // namespace ft

#include "set.tpp"
#include "set_compare.tpp"
#include "set_element.tpp"
#include "set_find.tpp"
#include "set_iter.tpp"
#include "set_modifier.tpp"
#include "set_property.tpp"
#include "set_relational.tpp"

#endif  // CONTAINERS_SET_HPP
