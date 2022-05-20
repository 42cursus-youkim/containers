#ifndef RBTREE_RBTREE_ROTATE_TPP
#define RBTREE_RBTREE_ROTATE_TPP

#include "rbtree.hpp"

namespace ft {

template <typename T, typename Compare>
void rbtree<T, Compare>::rotate_right(node_pointer node) {
  node_pointer left_child = node->left;
  node->left              = left_child->right;
  if (node->has_left_child())
    node->left->parent = node;
  left_child->parent = node->parent;
  if (node->is_left_child())
    node->parent->left = left_child;
  else
    node->parent->right = left_child;
  left_child->right = node;
  node->parent      = left_child;
}

/**
 * @brief rotate nodes to left, with right_child as pivot.
 *
 * @b node[5]
 * @b right_child<10>
 * @b grand_child(8)
 *
 * @b step-1: @c grand_child(8) becomes node's @b new-right-child
 * @b step-2 @c right_child<10> becomes the @b new-node
 * @b step-3 @c node[5] becomes new-node's @b new-left-child
 *
 *
 *  @b start   |  @b step-1  |  @b step-2  |  @b step-3  |
 *    [5]      |   [5] <10>  |     <10>    |      <10>   |
 *   /  \      |  /  \    \  |        \    |     /   \   |
 *  2  <10>    | 2   (8)  12 |        12   |   [5]   12  |
 *     /  \    |    /  \     |   [5]       |  /  \       |
 *   (8)  12   |   6   9     |  /  \       | 2   (8)     |
 *   / \       |             | 2   (8)     |     / \     |
 *  6  9       |             |    /  \     |    6  9     |
 *             |             |   6   9     |             |
 */
// FIXME: what happens if there's no grandchild?
template <typename T, typename Compare>
void rbtree<T, Compare>::rotate_left(node_pointer node) {
  node_pointer right_child = node->right; //< <10>
  node_pointer grand_child = right_child->left; //< (8)

  /// @b step-1: @c grand_child becomes node's @b new-right-child
  node->right = grand_child;
  if (node->has_right_child())
    node->right->parent = node;

  /// @b step-2 @c right_child becomes the @b new-node
  right_child->parent = node->parent;
  if (node->is_left_child())
    node->parent->left = right_child;
  else
    node->parent->right = right_child;

  /// @b step-3 @c node becomes new-node's @b new-left-child
  right_child->left = node;
  node->parent      = right_child;
}

template <typename T, typename Compare>
void rbtree<T, Compare>::rebuild_insert(node_pointer new_node) {
  new_node->is_black = (new_node == root());

  while (new_node != root() and not new_node->parent->is_black) {
    if ((new_node->parent)->is_left_child()) {
      node_pointer uncle = new_node->parent->parent->right;
      if (uncle != u_nullptr and not uncle->is_black) {
        new_node           = new_node->parent;
        new_node->is_black = true;
        new_node           = new_node->parent;
        new_node->is_black = new_node == root();
        uncle->is_black    = true;
      } else {
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
      if (uncle != u_nullptr and not uncle->is_black) {
        new_node           = new_node->parent;
        new_node->is_black = true;
        new_node           = new_node->parent;
        new_node->is_black = new_node == root();
        uncle->is_black    = true;
      } else {
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

template <typename T, typename Compare>
typename rbtree<T, Compare>::iterator
rbtree<T, Compare>::remove_node_pointer(node_pointer node) {
  iterator it(node);

  ++it;
  if (node == begin_)
    begin_ = it.base();
  remove_node(root(), node);
  --size_;
  return it;
}

template <typename T, typename Compare>
void rbtree<T, Compare>::remove_node(node_pointer root,
                                     node_pointer node) {
  node_pointer to_remove =
      (node->left == u_nullptr or node->right == u_nullptr)
          ? node
          : next_node(node);
  node_pointer succesor = to_remove->has_left_child()
                              ? to_remove->left
                              : to_remove->right;
  node_pointer sibling  = u_nullptr;

  if (succesor != u_nullptr)
    succesor->parent = to_remove->parent;

  if (to_remove->is_left_child()) {
    to_remove->parent->left = succesor;
    if (to_remove != root)
      sibling = to_remove->parent->right;
    else
      root = succesor;
  } else {
    to_remove->parent->right = succesor;
    sibling                  = to_remove->parent->left;
  }

  bool removed_black = to_remove->is_black;
  if (to_remove != node) {
    to_remove->parent = node->parent;
    if (node->is_left_child())
      to_remove->parent->left = to_remove;
    else
      to_remove->parent->right = to_remove;
    to_remove->left         = node->left;
    to_remove->left->parent = to_remove;
    to_remove->right        = node->right;
    if (to_remove->has_right_child())
      to_remove->right->parent = to_remove;
    to_remove->is_black = node->is_black;
    if (root == node)
      root = to_remove;
  }

  if (removed_black and root != u_nullptr) {
    if (succesor != u_nullptr)
      succesor->is_black = true;
    else {
      while (true) {
        if (not sibling->is_left_child()) {
          if (not sibling->is_black) {
            sibling->is_black         = true;
            sibling->parent->is_black = false;
            rotate_left(sibling->parent);
            if (root == sibling->left)
              root = sibling;
            sibling = sibling->left->right;
          }
          if ((sibling->left == u_nullptr or
               sibling->left->is_black) and
              (sibling->right == u_nullptr or
               sibling->right->is_black)) {
            sibling->is_black = false;
            succesor          = sibling->parent;
            if (succesor == root or !succesor->is_black) {
              succesor->is_black = true;
              break;
            }
            sibling = succesor->is_left_child()
                          ? succesor->parent->right
                          : succesor->parent->left;
          } else {
            if (sibling->right == u_nullptr or
                sibling->right->is_black) {
              sibling->left->is_black = true;
              sibling->is_black       = false;
              rotate_right(sibling);
              sibling = sibling->parent;
            }
            sibling->is_black         = sibling->parent->is_black;
            sibling->parent->is_black = true;
            sibling->right->is_black  = true;
            rotate_left(sibling->parent);
            break;
          }
        } else {
          if (!sibling->is_black) {
            sibling->is_black         = true;
            sibling->parent->is_black = false;
            rotate_right(sibling->parent);
            if (root == sibling->right)
              root = sibling;
            sibling = sibling->right->left;
          }
          if ((sibling->left == u_nullptr or
               sibling->left->is_black) and
              (sibling->right == u_nullptr or
               sibling->right->is_black)) {
            sibling->is_black = false;
            succesor          = sibling->parent;
            if (!succesor->is_black or succesor == root) {
              succesor->is_black = true;
              break;
            }
            sibling = succesor->is_left_child()
                          ? succesor->parent->right
                          : succesor->parent->left;
          } else {
            if (sibling->left == u_nullptr or
                sibling->left->is_black) {
              sibling->right->is_black = true;
              sibling->is_black        = false;
              rotate_left(sibling);
              sibling = sibling->parent;
            }
            sibling->is_black         = sibling->parent->is_black;
            sibling->parent->is_black = true;
            sibling->left->is_black   = true;
            rotate_right(sibling->parent);
            break;
          }
        }
      }
    }
  }
}

template <typename T, typename Compare>
void rbtree<T, Compare>::delete_node(const_reference value) {
  node_pointer remove = find_pos(remove, value);
  if (remove != u_nullptr)
    remove_node(root(), remove);
  --size_;
}

template <typename T, typename Compare>
void rbtree<T, Compare>::delete_tree(node_pointer node) {
  if (node != u_nullptr) {
    delete_tree(node->left);
    delete_tree(node->right);
    alloc_.destroy(node);
    alloc_.deallocate(node, 1);
  }
}

template <typename T, typename Compare>
typename rbtree<T, Compare>::node_pointer&
rbtree<T, Compare>::find_pos(node_pointer&   parent,
                             const_reference data) {
  node_pointer  node   = root();
  node_pointer* p_node = rootPtr();

  if (node != u_nullptr) {
    while (true) {
      if (comp_(data, node->data)) {
        if (node->has_left_child()) {
          p_node = &(node->left);
          node   = node->left;
        } else {
          parent = node;
          return parent->left;
        }
      } else if (comp_(node->data, data)) {
        if (node->has_right_child()) {
          p_node = &node->right;
          node   = node->right;
        } else {
          parent = node;
          return parent->right;
        }
      } else {
        parent = node;
        return *p_node;
      }
    }
  }
  parent = end_;
  return end_->left;
}

// FIXME: leaks!
template <typename T, typename Compare>
typename rbtree<T, Compare>::node_pointer&
rbtree<T, Compare>::find_pos(iterator        hint,
                             node_pointer&   parent,
                             node_pointer&   dummy,
                             const_reference data) {
  if (hint == end() or comp_(data, *hint)) {
    iterator prev = hint;
    if (hint == begin() or comp_(*--prev, data)) {
      if (not hint.base()->has_left_child()) {
        parent = hint.base();
        return parent->left;
      } else {
        parent = prev.base();
        return prev.base()->right;
      }
    }
    return find_pos(parent, data);
  } else if (comp_(*hint, data)) {
    iterator next = hint;
    ++next;
    if (next == end() or comp_(data, *next)) {
      if (not hint.base()->has_right_child()) {
        parent = hint.base();
        return hint.base()->right;
      } else {
        parent = next.base();
        return parent->left;
      }
    }
    return find_pos(parent, data);
  }
  parent = hint.base();
  dummy  = hint.base();
  return dummy;
}

}  // namespace ft

#endif  // RBTREE_RBTREE_ROTATE_TPP
