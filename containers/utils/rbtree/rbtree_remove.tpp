#ifndef RBTREE_RBTREE_REMOVE_TPP
#define RBTREE_RBTREE_REMOVE_TPP

#include "rbtree.hpp"

namespace ft {

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
            if (succesor == root or not succesor->is_black) {
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
          if (not sibling->is_black) {
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
            if (not succesor->is_black or succesor == root) {
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

}  // namespace ft

#endif  // RBTREE_RBTREE_REMOVE_TPP
