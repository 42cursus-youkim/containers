#ifndef CONTAINERS_MAP_TPP
#define CONTAINERS_MAP_TPP

#include "map.hpp"

namespace ft {

template <typename Key,
          typename T,
          typename Compare,
          typename Allocator>
class map<Key, T, Compare, Allocator>::value_compare
    : public ft::binary_function<value_type, value_type, bool> {
  friend class map<Key, T, Compare, Allocator>;

 protected:
  key_compare comp;

  /// Constructors & Destructor
  value_compare(key_compare comparator) : comp(comparator) {}

 public:
  bool operator()(const value_type& left,
                  const value_type& right) const {
    return comp(left.first, right.first);
  }

  bool operator()(const value_type& left,
                  const key_type&   right) const {
    return comp(left.first, right);
  }

  bool operator()(const key_type&   left,
                  const value_type& right) const {
    return comp(left, right.first);
  }
};

/// Constructors & Destructor
template <typename Key,
          typename T,
          typename Compare,
          typename Allocator>
map<Key, T, Compare, Allocator>::map(const key_compare&    comp,
                                     const allocator_type& alloc)
    : comp_(comp), alloc_(alloc), tree_(value_compare(comp)) {}

template <typename Key,
          typename T,
          typename Compare,
          typename Allocator>
template <typename InputIterator>
map<Key, T, Compare, Allocator>::map(InputIterator         first,
                                     InputIterator         last,
                                     const key_compare&    comp,
                                     const allocator_type& alloc)
    : comp_(comp), alloc_(alloc), tree_(value_compare(comp_)) {
  insert(first, last);
}

template <typename Key,
          typename T,
          typename Compare,
          typename Allocator>
map<Key, T, Compare, Allocator>::map(const map& other)
    : comp_(other.comp_), alloc_(other.alloc_), tree_(other.tree_) {}

template <typename Key,
          typename T,
          typename Compare,
          typename Allocator>
map<Key, T, Compare, Allocator>::~map() {}

}  // namespace ft

#endif  // CONTAINERS_MAP_TPP
