#ifndef CONTAINERS_MAP_HPP
#define CONTAINERS_MAP_HPP

#include <containers/const_iter/map.hpp>
#include <containers/iter/map.hpp>
#include <functional>
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
  // * typedef
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

  typedef ft::rbtree<value_type, value_compare>          tree_type;
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

  /// Operators
  map& operator=(const map& x) {
    if (this != &x) {
      this->clear();
      alloc_ = x.alloc_;
      comp_  = x.comp_;
      insert(x.begin(), x.end());
    }
    return (*this);
  }

  // * iterator
  iterator         begin() { return tree_.begin(); }

  const_iterator   begin() const { return tree_.begin(); }

  iterator         end() { return tree_.end(); }

  const_iterator   end() const { return tree_.end(); }

  reverse_iterator rbegin() { return reverse_iterator(tree_.end()); }

  const_reverse_iterator rbegin() const {
    return reverse_iterator(tree_.end());
  }

  reverse_iterator rend() { return reverse_iterator(tree_.begin()); }

  const_reverse_iterator rend() const {
    return reverse_iterator(tree_.begin());
  }

  // * capacity
  bool         empty() const { return tree_.size() == 0; }

  size_type    size() const { return tree_.size(); }

  size_type    max_size() const { return tree_.max_size(); }

  // * access
  mapped_type& operator[](const key_type& k) {
    ft::pair<iterator, bool> p =
        insert(ft::make_pair(k, mapped_type()));
    return (p.first)->second;
  }

  // * modifiers
  ft::pair<iterator, bool> insert(const value_type& val) {
    return tree_.insert(val);
  }

  iterator insert(iterator position, const value_type& val) {
    return tree_.insert(position.base(), val);
  }

  template <typename InputIterator>
  void insert(InputIterator first, InputIterator last) {
    tree_.insert(first, last);
  }

  void      erase(iterator position) { tree_.erase(position.base()); }

  size_type erase(const key_type& k) {
    iterator target = find(k);
    if (target != end()) {
      erase(target);
      return 1;
    }
    return 0;
  }

  void erase(iterator first, iterator last) {
    while (first != last)
      erase(first++);
  }

  void swap(map& x) {
    tree_.swap(x.tree_);
    std::swap(comp_, x.comp_);
    std::swap(alloc_, x.alloc_);
  }

  void           clear() { tree_.clear(); }

  // * observers
  key_compare    key_comp() const { return comp_; }

  value_compare  value_comp() const { return value_compare(comp_); }

  // * operations
  iterator       find(const key_type& k) { return tree_.find(k); }

  const_iterator find(const key_type& k) const {
    return tree_.find(k);
  }

  size_type count(const key_type& k) const {
    return find(k) != end();
  }

  iterator lower_bound(const key_type& k) {
    return tree_.lower_bound(k);
  }

  const_iterator lower_bound(const key_type& k) const {
    return tree_.lower_bound(k);
  }

  iterator upper_bound(const key_type& k) {
    return tree_.upper_bound(k);
  }

  const_iterator upper_bound(const key_type& k) const {
    return tree_.upper_bound(k);
  }

  pair<iterator, iterator> equal_range(const key_type& k) {
    return pair<iterator, iterator>(lower_bound(k), upper_bound(k));
  }

  pair<const_iterator, const_iterator> equal_range(
      const key_type& k) const {
    return pair<const_iterator, const_iterator>(lower_bound(k),
                                                upper_bound(k));
  }

  // * allocator
  allocator_type get_allocator() const { return alloc_; }
};

template <typename Key, typename T, typename Comp, typename Allocator>
bool operator==(const map<Key, T, Comp, Allocator>& x,
                const map<Key, T, Comp, Allocator>& y) {
  return x.size() == y.size() &&
         ft::equal(x.begin(), x.end(), y.begin());
}

template <typename Key, typename T, typename Comp, typename Allocator>
bool operator!=(const map<Key, T, Comp, Allocator>& x,
                const map<Key, T, Comp, Allocator>& y) {
  return !(x == y);
}

template <typename Key, typename T, typename Comp, typename Allocator>
bool operator<(const map<Key, T, Comp, Allocator>& x,
               const map<Key, T, Comp, Allocator>& y) {
  return ft::lexicographical_compare(x.begin(), x.end(), y.begin(),
                                     y.end());
}

template <typename Key, typename T, typename Comp, typename Allocator>
bool operator>(const map<Key, T, Comp, Allocator>& x,
               const map<Key, T, Comp, Allocator>& y) {
  return y < x;
}

template <typename Key, typename T, typename Comp, typename Allocator>
bool operator<=(const map<Key, T, Comp, Allocator>& x,
                const map<Key, T, Comp, Allocator>& y) {
  return !(y < x);
}

template <typename Key, typename T, typename Comp, typename Allocator>
bool operator>=(const map<Key, T, Comp, Allocator>& x,
                const map<Key, T, Comp, Allocator>& y) {
  return !(x < y);
}

}  // namespace ft

#include "map.tpp"

#endif  // CONTAINERS_MAP_HPP
