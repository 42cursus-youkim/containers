#ifndef RBTREE_RBTREE_ROTATE_TPP
#define RBTREE_RBTREE_ROTATE_TPP

#include "rbtree.hpp"

namespace ft {
/// rotate
template <typename T, typename Compare>
void rbtree<T, Compare>::rotate_right(node_pointer node) {
  node_pointer left_child = node->left;
  node->left              = left_child->right;
  if (node->left != u_nullptr)
    node->left->parent = node;
  left_child->parent = node->parent;
  if (is_left_child(node))
    node->parent->left = left_child;
  else
    node->parent->right = left_child;
  left_child->right = node;
  node->parent      = left_child;
}

template <typename T, typename Compare>
void rbtree<T, Compare>::rotate_left(node_pointer node) {
  node_pointer right_child = node->right;
  node->right              = right_child->left;
  if (node->right != u_nullptr)
    node->right->parent = node;
  right_child->parent = node->parent;
  if (is_left_child(node))
    node->parent->left = right_child;
  else
    node->parent->right = right_child;
  right_child->left = node;
  node->parent      = right_child;
}

template <typename T, typename Compare>
void rbtree<T, Compare>::rebuild_insert(node_pointer new_node) {
  new_node->is_black = new_node == root();
  while (new_node != root() && !new_node->parent->is_black) {
    if (is_left_child(new_node->parent)) {
      node_pointer uncle = new_node->parent->parent->right;
      if (uncle != u_nullptr && !uncle->is_black) {
        new_node           = new_node->parent;
        new_node->is_black = true;
        new_node           = new_node->parent;
        new_node->is_black = new_node == root();
        uncle->is_black    = true;
      } else {
        if (!is_left_child(new_node)) {
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
      if (uncle != u_nullptr && !uncle->is_black) {
        new_node           = new_node->parent;
        new_node->is_black = true;
        new_node           = new_node->parent;
        new_node->is_black = new_node == root();
        uncle->is_black    = true;
      } else {
        if (is_left_child(new_node)) {
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
  node_pointer remove =
      (node->left == u_nullptr || node->right == u_nullptr)
          ? node
          : next_node(node);
  node_pointer succesor =
      remove->left != u_nullptr ? remove->left : remove->right;
  node_pointer sibling = u_nullptr;
  if (succesor != u_nullptr)
    succesor->parent = remove->parent;
  if (is_left_child(remove)) {
    remove->parent->left = succesor;
    if (remove != root)
      sibling = remove->parent->right;
    else
      root = succesor;
  } else {
    remove->parent->right = succesor;
    sibling               = remove->parent->left;
  }
  bool removed_black = remove->is_black;
  if (remove != node) {
    remove->parent = node->parent;
    if (is_left_child(node))
      remove->parent->left = remove;
    else
      remove->parent->right = remove;
    remove->left         = node->left;
    remove->left->parent = remove;
    remove->right        = node->right;
    if (remove->right != u_nullptr)
      remove->right->parent = remove;
    remove->is_black = node->is_black;
    if (root == node)
      root = remove;
  }
  if (removed_black && root != u_nullptr) {
    if (succesor != u_nullptr)
      succesor->is_black = true;
    else {
      while (true) {
        if (!is_left_child(sibling)) {
          if (!sibling->is_black) {
            sibling->is_black         = true;
            sibling->parent->is_black = false;
            rotate_left(sibling->parent);
            if (root == sibling->left)
              root = sibling;
            sibling = sibling->left->right;
          }
          if ((sibling->left == u_nullptr ||
               sibling->left->is_black) &&
              (sibling->right == u_nullptr ||
               sibling->right->is_black)) {
            sibling->is_black = false;
            succesor          = sibling->parent;
            if (succesor == root || !succesor->is_black) {
              succesor->is_black = true;
              break;
            }
            sibling = is_left_child(succesor)
                          ? succesor->parent->right
                          : succesor->parent->left;
          } else {
            if (sibling->right == u_nullptr ||
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
          if ((sibling->left == u_nullptr ||
               sibling->left->is_black) &&
              (sibling->right == u_nullptr ||
               sibling->right->is_black)) {
            sibling->is_black = false;
            succesor          = sibling->parent;
            if (!succesor->is_black || succesor == root) {
              succesor->is_black = true;
              break;
            }
            sibling = is_left_child(succesor)
                          ? succesor->parent->right
                          : succesor->parent->left;
          } else {
            if (sibling->left == u_nullptr ||
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
        if (node->left != u_nullptr) {
          p_node = &(node->left);
          node   = node->left;
        } else {
          parent = node;
          return parent->left;
        }
      } else if (comp_(node->data, data)) {
        if (node->right != u_nullptr) {
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

template <typename T, typename Compare>
typename rbtree<T, Compare>::node_pointer&
rbtree<T, Compare>::find_pos(iterator        hint,
                             node_pointer&   parent,
                             node_pointer&   dummy,
                             const_reference data) {
  if (hint == end() || comp_(data, *hint)) {
    iterator prev = hint;
    if (hint == begin() || comp_(*--prev, data)) {
      if (hint.base()->left == u_nullptr) {
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
    if (next == end() || comp_(data, *next)) {
      if (hint.base()->right == u_nullptr) {
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
