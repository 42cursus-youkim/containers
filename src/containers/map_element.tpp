#ifndef CONTAINERS_MAP_ELEMENT_TPP
#define CONTAINERS_MAP_ELEMENT_TPP

#include "map.hpp"

namespace ft {
template <typename Key,
          typename T,
          typename Compare,
          typename Allocator>
typename map<Key, T, Compare, Allocator>::mapped_type&
map<Key, T, Compare, Allocator>::operator[](const key_type& key) {
  ft::pair<iterator, bool> p =
      insert(ft::make_pair(key, mapped_type()));
  return (p.first)->second;
}

}  // namespace ft

#endif  // CONTAINERS_MAP_ELEMENT_TPP
