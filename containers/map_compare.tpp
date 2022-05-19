#ifndef CONTAINERS_MAP_COMPARE_TPP
#define CONTAINERS_MAP_COMPARE_TPP

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

template <typename Key,
          typename T,
          typename Compare,
          typename Allocator>
typename map<Key, T, Compare, Allocator>::key_compare
map<Key, T, Compare, Allocator>::key_comp() const {
  return comp_;
}

template <typename Key,
          typename T,
          typename Compare,
          typename Allocator>
typename map<Key, T, Compare, Allocator>::value_compare
map<Key, T, Compare, Allocator>::value_comp() const {
  return value_compare(comp_);
}

}  // namespace ft

#endif  // CONTAINERS_MAP_COMPARE_TPP
