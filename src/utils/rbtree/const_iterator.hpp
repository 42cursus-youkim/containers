#ifndef RBTREE_CONST_ITERATOR_HPP
#define RBTREE_CONST_ITERATOR_HPP

#include <utils/rbtree/iterator.hpp>

namespace ft {

template <class T, class NodePtr>
class tree_const_iterator {
  // * typedef
 public:
  typedef T value_type;
  typedef const T* pointer;
  typedef const T& reference;
  typedef NodePtr node_pointer;
  typedef long difference_type;
  typedef unsigned long size_type;
  typedef std::bidirectional_iterator_tag iterator_category;
  typedef ft::tree_iterator<T, NodePtr> non_const_iterator;

 private:
  // * private member
  node_pointer node_;

 public:
  // * constructor
  tree_const_iterator() {}

  tree_const_iterator(const node_pointer x) : node_(x) {}

  tree_const_iterator(const tree_const_iterator& x) : node_(x.base()) {}

  tree_const_iterator(non_const_iterator x) : node_(x.base()) {}

  ~tree_const_iterator() {}

  node_pointer base() const { return node_; }

  // * operations
  void tree_min(node_pointer node) {
    while (node->left != u_nullptr)
      node = node->left;
    node_ = node;
  }

  void tree_max(node_pointer node) {
    while (node->right != u_nullptr)
      node = node->right;
    node_ = node;
  }

  tree_const_iterator& operator=(const tree_const_iterator& x) {
    node_ = x.node_;
    return (*this);
  }

  tree_const_iterator& operator++() {
    if (node_->right != u_nullptr) {
      tree_min(node_->right);
      return *this;
    }
    while (!tree_is_left_child())
      node_ = node_->parent;
    node_ = node_->parent;
    return *this;
  }

  tree_const_iterator operator++(int) {
    tree_const_iterator temp(*this);
    ++(*this);
    return temp;
  }

  tree_const_iterator& operator--() {
    if (node_->left != u_nullptr) {
      tree_max(node_->left);
      return *this;
    }
    while (tree_is_left_child())
      node_ = node_->parent;
    node_ = node_->parent;
    return *this;
  }

  tree_const_iterator operator--(int) {
    tree_const_iterator temp(*this);
    --(*this);
    return temp;
  }

  bool operator==(const tree_const_iterator& x) const {
    return this->node_ == x.node_;
  }

  bool operator!=(const tree_const_iterator& x) const {
    return this->node_ != x.node_;
  }

  reference operator*() const { return node_->data; }

  pointer operator->() const { return &node_->data; }

  bool tree_is_left_child() const { return node_ == node_->parent->left; }
};

}  // namespace ft

#endif  // RBTREE_CONST_ITERATOR_HPP
