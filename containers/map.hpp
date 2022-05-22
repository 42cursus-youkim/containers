#ifndef CONTAINERS_MAP_HPP
#define CONTAINERS_MAP_HPP

#include <const_iter/map.hpp>
#include <functional>
#include <iter/map.hpp>
#include <memory>
#include <utils/general/binary_function.hpp>
#include <utils/general/equal.hpp>
#include <utils/general/lexicographical_compare.hpp>
#include <utils/iter/reverse_iterator.hpp>
#include <utils/pair/pair.hpp>
#include <utils/rbtree/rbtree.hpp>
namespace ft {

template <typename Key,
          typename T,
          typename Compare = std::less<Key>,
          typename Allocator =
              std::allocator<ft::pair<const Key, T> > >
class map {
 public:
  typedef Key                                      key_type;
  typedef T                                        mapped_type;
  typedef ft::pair<const key_type, mapped_type>    value_type;
  typedef Compare                                  key_compare;
  typedef Allocator                                allocator_type;

  typedef typename allocator_type::reference       reference;
  typedef typename allocator_type::const_reference const_reference;
  typedef typename allocator_type::pointer         pointer;
  typedef typename allocator_type::const_pointer   const_pointer;
  typedef typename allocator_type::difference_type difference_type;
  typedef typename allocator_type::size_type       size_type;

  // value_compare
  class value_compare;

 private:
  typedef ft::rbtree<value_type, value_compare> tree_type;

 public:
  typedef ft::map_iterator<typename tree_type::iterator> iterator;
  typedef ft::map_const_iterator<typename tree_type::const_iterator>
                                               const_iterator;
  typedef ft::reverse_iterator<iterator>       reverse_iterator;
  typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

 private:
  key_compare    comp_;
  allocator_type alloc_;
  tree_type      tree_;

 public:
  /// Constructors & Destructor
  explicit map(const key_compare&    comp  = key_compare(),
               const allocator_type& alloc = allocator_type());

  template <typename InputIterator>
  map(InputIterator         first,
      InputIterator         last,
      const key_compare&    comp  = key_compare(),
      const allocator_type& alloc = allocator_type());

  map(const map& other);

  ~map();

  /// operators
  map&                     operator=(const map& other);

  /// allocator
  allocator_type           get_allocator() const;

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

  /// element access
  mapped_type&             operator[](const key_type& key);

  /// modifiers
  ft::pair<iterator, bool> insert(const value_type& val);
  iterator insert(iterator position, const value_type& val);
  template <typename InputIterator>
  void           insert(InputIterator first, InputIterator last);

  void           erase(iterator position);
  size_type      erase(const key_type& key);
  void           erase(iterator first, iterator last);

  void           swap(map& other);

  void           clear();

  // observers
  key_compare    key_comp() const;
  value_compare  value_comp() const;

  // operations
  iterator       find(const key_type& key);
  const_iterator find(const key_type& key) const;
  size_type      count(const key_type& key) const;
  iterator       lower_bound(const key_type& key);
  const_iterator lower_bound(const key_type& key) const;
  iterator       upper_bound(const key_type& key);
  const_iterator upper_bound(const key_type& key) const;
  pair<iterator, iterator> equal_range(const key_type& key);
  pair<const_iterator, const_iterator> equal_range(
      const key_type& key) const;
};

/// non-member function overloads

/// swap
template <typename T, typename Compare, typename Alloc>
void swap(map<T, Compare, Alloc>& x, map<T, Compare, Alloc>& y);

}  // namespace ft

#include "map.tpp"
#include "map_compare.tpp"
#include "map_element.tpp"
#include "map_find.tpp"
#include "map_iter.tpp"
#include "map_modifier.tpp"
#include "map_nonmember.tpp"
#include "map_property.tpp"
#include "map_relational.tpp"

#endif  // CONTAINERS_MAP_HPP
