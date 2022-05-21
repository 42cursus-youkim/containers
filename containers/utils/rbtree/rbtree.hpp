#ifndef RBTREE_RBTREE_HPP
#define RBTREE_RBTREE_HPP

#include <limits>
#include <utils/pair/pair.hpp>
#include <utils/rbtree/const_iterator.hpp>
#include <utils/rbtree/iterator.hpp>
#include <utils/rbtree/node.hpp>

namespace ft {
template <typename T, typename Compare>
class rbtree {
 public:
  typedef T                         value_type;
  typedef T&                        reference;
  typedef const T&                  const_reference;
  typedef Compare                   compare_type;
  typedef ft::rb_node<T>            node_type;
  typedef node_type*                node_pointer;

  typedef std::allocator<node_type> allocator_type;
  typedef typename allocator_type::template rebind<node_type>::other
                                             node_allocator_type;
  typedef typename allocator_type::size_type size_type;
  typedef typename allocator_type::difference_type    difference_type;

  typedef ft::tree_iterator<value_type, node_pointer> iterator;
  typedef ft::tree_const_iterator<value_type, node_pointer>
      const_iterator;

  /// implementaiton
 private:
  node_pointer   begin_;
  node_pointer   end_;
  size_type      size_;
  allocator_type alloc_;
  compare_type   comp_;  //< whether a < b (less)

 private:
  node_pointer  root() const;
  node_pointer* rootPtr() const;

  node_pointer  min_node(node_pointer node) const;
  node_pointer  max_node(node_pointer node) const;
  node_pointer  next_node(node_pointer node) const;

  /// rotate
  void          rotate_right(node_pointer node);
  void          rotate_left(node_pointer node);

  void          rebuild_insert(node_pointer new_node);

  // allocate
  node_pointer  create_node(const_reference data);

  // remove
  void          deallocate_node(node_pointer node);
  iterator      remove_node_pointer(node_pointer node);

  void          remove_node(node_pointer root, node_pointer node);

  void          delete_node(const_reference value);
  void          delete_tree(node_pointer node);

  node_pointer& find_pos(node_pointer& parent, const_reference data);
  node_pointer& find_pos(iterator        hint,
                         node_pointer&   parent,
                         node_pointer&   dummy,
                         const_reference data);

  /// interface
 public:
  /// Constructors & Destructor
  rbtree(const compare_type& comp = compare_type());
  rbtree(const rbtree& other);
  ~rbtree();

  /// Operators
  rbtree& operator=(const rbtree& other);

 public:
  /// iterator
  iterator       begin();
  const_iterator begin() const;
  iterator       end();
  const_iterator end() const;

  // getters
  size_type      size() const;
  size_type      max_size() const;

  // find
  template <typename Key>
  iterator find(const Key& k);

  template <typename Key>
  const_iterator find(const Key& k) const;

  template <typename Key>
  iterator lower_bound(const Key& k);

  template <typename Key>
  const_iterator lower_bound(const Key& k) const;

  template <typename Key>
  iterator upper_bound(const Key& k);

  template <typename Key>
  const_iterator upper_bound(const Key& k) const;

  /// modifiers
  template <typename InputIterator>
  void insert(InputIterator first, InputIterator last);
  pair<iterator, bool> insert(const_reference data);
  iterator             insert(iterator hint, const_reference data);

  void                 swap(rbtree& other);
  void                 erase(iterator pos);
  void                 clear();
};

}  // namespace ft

/// implementations
#include "rbtree.tpp"
#include "rbtree_find.tpp"
#include "rbtree_impl.tpp"
#include "rbtree_iter.tpp"
#include "rbtree_modifier.tpp"
#include "rbtree_remove.tpp"
#include "rbtree_rotate.tpp"

#endif  // RBTREE_RBTREE_HPP
