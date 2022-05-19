#ifndef CONTAINERS_SET_FIND_TPP
#define CONTAINERS_SET_FIND_TPP

#include "set.hpp"

namespace ft {

template <typename T, typename Compare, typename Allocator>
typename set<T, Compare, Allocator>::iterator
set<T, Compare, Allocator>::find(const value_type& val) {
  return tree_.find(val);
}

template <typename T, typename Compare, typename Allocator>
typename set<T, Compare, Allocator>::const_iterator
set<T, Compare, Allocator>::find(const value_type& val) const {
  return tree_.find(val);
}

template <typename T, typename Compare, typename Allocator>
typename set<T, Compare, Allocator>::size_type
set<T, Compare, Allocator>::count(const key_type& key) const {
  return find(key) != end();
}

template <typename T, typename Compare, typename Allocator>
typename set<T, Compare, Allocator>::iterator
set<T, Compare, Allocator>::lower_bound(const key_type& key) {
  return tree_.lower_bound(key);
}

template <typename T, typename Compare, typename Allocator>
typename set<T, Compare, Allocator>::const_iterator
set<T, Compare, Allocator>::lower_bound(
    const key_type& key) const {
  return tree_.lower_bound(key);
}

template <typename T, typename Compare, typename Allocator>
typename set<T, Compare, Allocator>::iterator
set<T, Compare, Allocator>::upper_bound(const key_type& key) {
  return tree_.upper_bound(key);
}

template <typename T, typename Compare, typename Allocator>
typename set<T, Compare, Allocator>::const_iterator
set<T, Compare, Allocator>::upper_bound(
    const key_type& key) const {
  return tree_.upper_bound(key);
}

template <typename T, typename Compare, typename Allocator>
pair<typename set<T, Compare, Allocator>::iterator,
     typename set<T, Compare, Allocator>::iterator>
set<T, Compare, Allocator>::equal_range(const key_type& key) {
  return pair<iterator, iterator>(lower_bound(key), upper_bound(key));
}

template <typename T, typename Compare, typename Allocator>
pair<typename set<T, Compare, Allocator>::const_iterator,
     typename set<T, Compare, Allocator>::const_iterator>
set<T, Compare, Allocator>::equal_range(
    const key_type& key) const {
  return pair<const_iterator, const_iterator>(lower_bound(key),
                                              upper_bound(key));
}

}  // namespace ft

#endif  // CONTAINERS_SET_FIND_TPP
