#ifndef RBTREE_RBTREE_ROTATE_TPP
#define RBTREE_RBTREE_ROTATE_TPP

#include "rbtree.hpp"

namespace ft {

/**
 * @brief rotate nodes to right, with left_child as pivot.
 *
 * @b step-1: @c grand_child becomes node's @b new-left-child
 * @b step-2: @c right_child becomes the @b new-node
 * @b step-3: @c node becomes the @b new-right-child
 *
 *  @b start   |  @b step-1  |  @b step-2  |  @b step-3  |
 *      <10>   |     <10>    |    [5]      |    [5]      |
 *     /   \   |     /  \    |   /         |   /  \      |
 *   [5]   12  |   (8)   12  |  2          |  2  <10>    |
 *  /  \       |  /  \       |       <10>  |     /  \    |
 * 2   (8)     | 6   9       |(det.) /  \  |   (8)  12   |
 *     / \     |         [5] |    (8)   12 |   / \       |
 *    6  9     |  (det.) /   |   /  \      |  6  9       |
 *             |       2     |  6   9      |             |
 */
template <typename T, typename Compare, typename Alloc>
void rbtree<T, Compare, Alloc>::rotate_right(node_pointer node) {
  node_pointer left_child  = node->left;         //< <10>
  node_pointer grand_child = left_child->right;  //< (8)

  /// @b step-1
  node->left = grand_child;
  if (node->has_left_child())
    node->left->parent = node;

  /// @b step-2
  left_child->parent = node->parent;
  if (node->is_left_child())
    node->parent->left = left_child;
  else
    node->parent->right = left_child;

  /// @b step-3
  left_child->right = node;
  node->parent      = left_child;
}

/**
 * @brief rotate nodes to left, with right_child as pivot.
 *
 * @b step-1: @c grand_child becomes node's @b new-right-child
 * @b step-2 @c right_child becomes the @b new-node
 * @b step-3 @c node becomes new-node's @b new-left-child
 *
 *  @b start   |  @b step-1  |  @b step-2  |  @b step-3  |
 *    [5]      |   [5]       |     <10>    |      <10>   |
 *   /  \      |  /  \       |        \    |     /   \   |
 *  2  <10>    | 2   (8)     |        12   |   [5]   12  |
 *     /  \    |    /  \     |   [5]       |  /  \       |
 *   (8)  12   |   6   9     |  /  \ (det.)| 2   (8)     |
 *   / \       |        <10> | 2   (8)     |     / \     |
 *  6  9       |   (det.) \  |    /  \     |    6  9     |
 *             |          12 |   6   9     |             |
 */
template <typename T, typename Compare, typename Alloc>
void rbtree<T, Compare, Alloc>::rotate_left(node_pointer node) {
  node_pointer right_child = node->right;        //< <10>
  node_pointer grand_child = right_child->left;  //< (8)

  /// @b step-1
  node->right = grand_child;
  if (node->has_right_child())
    node->right->parent = node;

  /// @b step-2
  right_child->parent = node->parent;
  if (node->is_left_child())
    node->parent->left = right_child;
  else
    node->parent->right = right_child;

  /// @b step-3
  right_child->left = node;
  node->parent      = right_child;
}

template <typename T, typename Compare, typename Alloc>
void rbtree<T, Compare, Alloc>::rebalance_tree(
    node_pointer new_node) {
  new_node->is_black = (new_node == root());

  while (new_node != root() and new_node->parent->is_red()) {
    if ((new_node->parent)->is_left_child()) {
      node_pointer uncle = new_node->parent->parent->right;
      if (uncle != u_nullptr and uncle->is_red()) {
        // Recoloring
        new_node           = new_node->parent;
        new_node->is_black = true;
        new_node           = new_node->parent;
        new_node->is_black = new_node == root();
        uncle->is_black    = true;
      } else {
        // Restructuring
        if (not new_node->is_left_child()) {
          new_node = new_node->parent;
          rotate_left(new_node);
        }
        new_node           = new_node->parent;
        new_node->is_black = true;
        new_node           = new_node->parent;
        new_node->is_black = false;
        rotate_right(new_node);
        break;
      }
    } else {
      node_pointer uncle = new_node->parent->parent->left;
      if (uncle != u_nullptr and uncle->is_red()) {
        // Recoloring
        new_node           = new_node->parent;
        new_node->is_black = true;
        new_node           = new_node->parent;
        new_node->is_black = new_node == root();
        uncle->is_black    = true;
      } else {
        // Restructuring
        if (new_node->is_left_child()) {
          new_node = new_node->parent;
          rotate_right(new_node);
        }
        new_node           = new_node->parent;
        new_node->is_black = true;
        new_node           = new_node->parent;
        new_node->is_black = false;
        rotate_left(new_node);
        break;
      }
    }
  }
}

template <typename T, typename Compare, typename Alloc>
void rbtree<T, Compare, Alloc>::delete_node(const_reference value) {
  node_pointer remove = where_to_attach(remove, value);
  if (remove != u_nullptr)
    remove_node(root(), remove);
  --size_;
}

/// recursively remove every node in the tree
template <typename T, typename Compare, typename Alloc>
void rbtree<T, Compare, Alloc>::delete_tree(node_pointer node) {
  if (node == u_nullptr)
    return;

  delete_tree(node->left);
  delete_tree(node->right);
  deallocate_node(node);
}

template <typename T, typename Compare, typename Alloc>
typename rbtree<T, Compare, Alloc>::node_pointer&
rbtree<T, Compare, Alloc>::where_to_attach(node_pointer&   parent,
                                           const_reference data) {
  node_pointer  node     = root();
  node_pointer* node_ptr = rootPtr();

  if (node == u_nullptr) {
    parent = end_;
    return end_->left;
  }

  while (true) {
    if (comp_(data, node->data)) {
      if (node->has_left_child()) {
        node_ptr = &(node->left);
        node     = node->left;
      } else {
        parent = node;
        return parent->left;
      }
    } else if (comp_(node->data, data)) {
      if (node->has_right_child()) {
        node_ptr = &node->right;
        node     = node->right;
      } else {
        parent = node;
        return parent->right;
      }
    } else {
      parent = node;
      return *node_ptr;
    }
  }
}

template <typename T, typename Compare, typename Alloc>
typename rbtree<T, Compare, Alloc>::node_pointer&
rbtree<T, Compare, Alloc>::where_to_attach(iterator        from,
                                           node_pointer&   parent,
                                           node_pointer&   dummy,
                                           const_reference data) {
  if (from == end() or comp_(data, *from)) {
    iterator prev = from;
    if (from == begin() or comp_(*--prev, data)) {
      // attach node to from
      if (not from.base()->has_left_child()) {
        parent = from.base();
        return parent->left;
      } else {
        parent = prev.base();
        return prev.base()->right;
      }
    }
    return where_to_attach(parent, data);
  } else if (comp_(*from, data)) {
    iterator next = from;
    ++next;
    if (next == end() or comp_(data, *next)) {
      // attach node to from or next one
      if (not from.base()->has_right_child()) {
        parent = from.base();
        return from.base()->right;
      } else {
        parent = next.base();
        return parent->left;
      }
    }
    return where_to_attach(parent, data);
  } else {
    parent = from.base();
    dummy  = from.base();
    return dummy;
  }
}

}  // namespace ft

#endif  // RBTREE_RBTREE_ROTATE_TPP
