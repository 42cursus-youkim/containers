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
          typename Alloc = std::allocator<ft::pair<const Key, T> > >
class map {
 public:
  // * typedef
  typedef Key key_type;
  typedef T mapped_type;
  typedef ft::pair<const key_type, mapped_type> value_type;
  typedef Compare key_compare;
  typedef Alloc allocator_type;

  typedef typename allocator_type::reference reference;
  typedef typename allocator_type::const_reference const_reference;
  typedef typename allocator_type::pointer pointer;
  typedef typename allocator_type::const_pointer const_pointer;
  typedef typename allocator_type::difference_type difference_type;
  typedef typename allocator_type::size_type size_type;

  // * value_compare typename
  class value_compare
      : public ft::binary_function<value_type, value_type, bool> {
    friend class map;

   protected:
    key_compare comp;

    value_compare(key_compare c) : comp(c) {}

   public:
    bool operator()(const value_type& x, const value_type& y) const {
      return comp(x.first, y.first);
    }

    bool operator()(const value_type& x, const key_type& y) const {
      return comp(x.first, y);
    }

    bool operator()(const key_type& x, const value_type& y) const {
      return comp(x, y.first);
    }
  };

  typedef ft::rb_tree<value_type, value_compare> tree_type;
  typedef ft::map_iterator<typename tree_type::iterator> iterator;
  typedef ft::map_const_iterator<typename tree_type::const_iterator>
      const_iterator;
  typedef ft::reverse_iterator<iterator> reverse_iterator;
  typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

 private:
  // * private member
  key_compare _comp;
  allocator_type _alloc;
  tree_type _tree;

 public:
  // * constructor
  explicit map(const key_compare& comp = key_compare(),
               const allocator_type& alloc = allocator_type())
      : _comp(comp), _alloc(alloc), _tree(value_compare(comp)) {}

  template <typename InputIterator>
  map(InputIterator first,
      InputIterator last,
      const key_compare& comp = key_compare(),
      const allocator_type& alloc = allocator_type())
      : _comp(comp), _alloc(alloc), _tree(value_compare(_comp)) {
    insert(first, last);
  }

  map(const map& x)
      : _comp(x._comp), _alloc(x._alloc), _tree(x._tree) {}

  ~map() {}

  map& operator=(const map& x) {
    if (this != &x) {
      this->clear();
      _alloc = x._alloc;
      _comp = x._comp;
      insert(x.begin(), x.end());
    }
    return (*this);
  }

  // * iterator
  iterator begin() { return _tree.begin(); }

  const_iterator begin() const { return _tree.begin(); }

  iterator end() { return _tree.end(); }

  const_iterator end() const { return _tree.end(); }

  reverse_iterator rbegin() { return reverse_iterator(_tree.end()); }

  const_reverse_iterator rbegin() const {
    return reverse_iterator(_tree.end());
  }

  reverse_iterator rend() { return reverse_iterator(_tree.begin()); }

  const_reverse_iterator rend() const {
    return reverse_iterator(_tree.begin());
  }

  // * capacity
  bool empty() const { return _tree.size() == 0; }

  size_type size() const { return _tree.size(); }

  size_type max_size() const { return _tree.max_size(); }

  // * access
  mapped_type& operator[](const key_type& k) {
    //    iterator target = find(k);
    //    if (target != end())
    //      return (*target).second;
    ft::pair<iterator, bool> p =
        insert(ft::make_pair(k, mapped_type()));
    return (p.first)->second;
  }

  // * modifiers
  ft::pair<iterator, bool> insert(const value_type& val) {
    return _tree.insert(val);
  }

  iterator insert(iterator position, const value_type& val) {
    return _tree.insert(position.base(), val);
  }

  template <typename InputIterator>
  void insert(InputIterator first, InputIterator last) {
    _tree.insert(first, last);
  }

  void erase(iterator position) { _tree.erase(position.base()); }

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
    _tree.swap(x._tree);
    std::swap(_comp, x._comp);
    std::swap(_alloc, x._alloc);
  }

  void clear() { _tree.clear(); }

  // * observers
  key_compare key_comp() const { return _comp; }

  value_compare value_comp() const { return value_compare(_comp); }

  // * operations
  iterator find(const key_type& k) { return _tree.find(k); }

  const_iterator find(const key_type& k) const {
    return _tree.find(k);
  }

  size_type count(const key_type& k) const {
    return find(k) != end();
  }

  iterator lower_bound(const key_type& k) {
    return _tree.lower_bound(k);
  }

  const_iterator lower_bound(const key_type& k) const {
    return _tree.lower_bound(k);
  }

  iterator upper_bound(const key_type& k) {
    return _tree.upper_bound(k);
  }

  const_iterator upper_bound(const key_type& k) const {
    return _tree.upper_bound(k);
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
  allocator_type get_allocator() const { return _alloc; }
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

#endif  // CONTAINERS_MAP_HPP
