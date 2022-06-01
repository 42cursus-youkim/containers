#ifndef RBTREE_RBTREE_REMOVE_TPP
#define RBTREE_RBTREE_REMOVE_TPP

#include "rbtree.hpp"

namespace ft {

/// @brief: naively deallocate a node from @b memory, not from tree
template <typename T, typename Compare, typename Alloc>
void rbtree<T, Compare, Alloc>::deallocate_node(node_pointer node) {
  alloc_.destroy(&node->data);
  node_alloc_.deallocate(node, 1);
}

template <typename T, typename Compare, typename Alloc>
typename rbtree<T, Compare, Alloc>::iterator
rbtree<T, Compare, Alloc>::remove_node_pointer(node_pointer node) {
  iterator it(node);

  ++it;
  if (node == begin_)
    begin_ = it.base();
  remove_node(root(), node);
  --size_;
  return it;
}

/**
 * @brief six cases
 *
 * https://medium.com/analytics-vidhya/deletion-in-red-black-rb-tree-92301e1474ea
 * https://assortrock.com/88
 *
 * case
 * <1> it's a red leaf -> just delete it
 * <2> it's root ->
 * <3>
 *
 *      10
 *     /  \
 * @b 5 @b 30 <- <3>
 *   / \  / \
 *  2  9 25 40
 *          /
 *      @b 38 <- <1>
 */
template <typename T, typename Compare, typename Alloc>
void rbtree<T, Compare, Alloc>::remove_node(node_pointer root,
                                            node_pointer node) {
  node_pointer to_pop =
      node->has_both_child() ? next_node(node) : node;
  node_pointer succesor =
      to_pop->has_left_child() ? to_pop->left : to_pop->right;

  if (succesor != u_nullptr)
    succesor->parent = to_pop->parent;

  node_pointer sibling =
      to_pop != root ? sibling_node_of(to_pop) : u_nullptr;

  if (to_pop->is_left_child()) {
    if (to_pop == root)
      root = succesor;
    to_pop->parent->left = succesor;
  } else {
    to_pop->parent->right = succesor;
  }

  bool removed_red = to_pop->is_red();

  if (to_pop != node) {
    to_pop->parent = node->parent;
    if (node->is_left_child())
      to_pop->parent->left = to_pop;
    else
      to_pop->parent->right = to_pop;

    to_pop->left         = node->left;
    to_pop->left->parent = to_pop;

    to_pop->right = node->right;
    if (to_pop->has_right_child())
      to_pop->right->parent = to_pop;

    to_pop->is_black = node->is_black;

    if (root == node)
      root = to_pop;
  }

  deallocate_node(node);

  if (removed_red or root == u_nullptr)
    return;

  if (succesor != u_nullptr) {
    succesor->is_black = true;
    return;
  }

  fix_double_black_node(root, sibling, succesor);
}

template <typename T, typename Compare, typename Alloc>
void rbtree<T, Compare, Alloc>::fix_double_black_node(
    node_pointer root,
    node_pointer sibling,
    node_pointer succesor) {
  while (true) {
    if (sibling->is_right_child()) {
      if (sibling->is_red()) {
        sibling->is_black         = true;
        sibling->parent->is_black = false;
        rotate_left(sibling->parent);
        if (root == sibling->left)
          root = sibling;
        sibling = sibling->left->right;
      }
      if (sibling->has_both_child(BLACK)) {
        sibling->is_black = false;
        succesor          = sibling->parent;
        if (succesor->is_red() or succesor == root) {
          succesor->is_black = true;
          break;
        }
        sibling = sibling_node_of(succesor);
      } else {
        if (sibling->has_right_child(BLACK)) {
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
      if (sibling->is_red()) {
        sibling->is_black         = true;
        sibling->parent->is_black = false;
        rotate_right(sibling->parent);
        if (root == sibling->right)
          root = sibling;
        sibling = sibling->right->left;
      }
      if (sibling->has_both_child(BLACK)) {
        sibling->is_black = false;
        succesor          = sibling->parent;
        if (succesor->is_red() or succesor == root) {
          succesor->is_black = true;
          break;
        }
        sibling = sibling_node_of(succesor);
      } else {
        if (sibling->has_left_child(BLACK)) {
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

}  // namespace ft

#endif  // RBTREE_RBTREE_REMOVE_TPP
