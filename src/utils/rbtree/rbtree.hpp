#ifndef RBTREE_RBTREE_HPP
#define RBTREE_RBTREE_HPP

#include <limits>
#include <utils/pair/pair.hpp>
#include <utils/rbtree/const_iterator.hpp>
#include <utils/rbtree/iterator.hpp>
#include <utils/rbtree/node.hpp>

namespace ft {
template <typename T, typename Compare>
class rb_tree {
 public:
  // * typedef
  typedef T                                           value_type;
  typedef T&                                          reference;
  typedef const T&                                    const_reference;
  typedef Compare                                     compare_type;
  typedef ft::rb_node<T>                              node_type;
  typedef node_type*                                  node_pointer;

  typedef std::allocator<node_type>                   allocator_type;
  typedef typename allocator_type::size_type          size_type;
  typedef typename allocator_type::difference_type    difference_type;

  typedef ft::tree_iterator<value_type, node_pointer> iterator;
  typedef ft::tree_const_iterator<value_type, node_pointer>
      const_iterator;

 private:
  // * private member
  node_pointer   begin_;
  node_pointer   end_;
  size_type      size_;
  allocator_type alloc_;
  compare_type   comp_;

 public:
  // * constructor
  rb_tree(const compare_type& comp = compare_type())
      : size_(0), alloc_(allocator_type()), comp_(comp) {
    end_ = alloc_.allocate(1);
    alloc_.construct(end_, node_type());
    begin_ = end_;
  }

  rb_tree(const rb_tree& x)
      : size_(0), alloc_(x.alloc_), comp_(x.comp_) {
    end_ = alloc_.allocate(1);
    alloc_.construct(end_, node_type());
    begin_ = end_;
    *this  = x;
  }

  rb_tree& operator=(const rb_tree& x) {
    if (this != &x) {
      clear();
      alloc_ = x.alloc_;
      comp_  = x.comp_;
      insert(x.begin(), x.end());
    }
    return (*this);
  }

  ~rb_tree() {
    clear();
    alloc_.destroy(end_);
    alloc_.deallocate(end_, 1);
  }

 private:
  // * tree
  node_pointer  root() const { return end_->left; }

  node_pointer* rootPtr() const { return &end_->left; }

  bool          is_left_child(node_pointer node) const {
             return node == node->parent->left;
  }

  node_pointer min_node(node_pointer node) const {
    node_pointer temp = node;
    while (temp->left != u_nullptr)
      temp = temp->left;
    return temp;
  }

  node_pointer max_node(node_pointer node) const {
    node_pointer temp = node;
    while (temp->right != u_nullptr)
      temp = temp->right;
    return temp;
  }

  node_pointer create_node(const_reference data) {
    node_pointer temp = alloc_.allocate(1);
    alloc_.construct(temp, node_type(data));
    return temp;
  }

  node_pointer next_node(node_pointer node) const {
    if (node->right != u_nullptr)
      return min_node(node->right);
    while (!is_left_child(node))
      node = node->parent;
    return node->parent;
  }

  void rotate_right(node_pointer node) {
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

  void rotate_left(node_pointer node) {
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

  void rebuild_insert(node_pointer new_node) {
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

  iterator remove_node_pointer(node_pointer node) {
    iterator it(node);
    ++it;
    if (node == begin_)
      begin_ = it.base();
    remove_node(root(), node);
    --size_;
    return it;
  }

  void remove_node(node_pointer root, node_pointer node) {
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

  void delete_node(const_reference value) {
    node_pointer remove = find_pos(remove, value);
    if (remove != u_nullptr)
      remove_node(root(), remove);
    --size_;
  }

  void delete_tree(node_pointer node) {
    if (node != u_nullptr) {
      delete_tree(node->left);
      delete_tree(node->right);
      alloc_.destroy(node);
      alloc_.deallocate(node, 1);
    }
  }

  node_pointer& find_pos(node_pointer& parent, const_reference data) {
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

  node_pointer& find_pos(iterator        hint,
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

 public:
  // * map

  // * iterator
  iterator       begin() { return iterator(begin_); }

  const_iterator begin() const { return const_iterator(begin_); }

  iterator       end() { return iterator(end_); }

  const_iterator end() const { return const_iterator(end_); }

  // * capacity
  size_type      size() const { return size_; }

  size_type      max_size() const {
         return std::min<size_type>(
        alloc_.max_size(),
        std::numeric_limits<difference_type>::max());
  }

  // * opearations
  template <typename Key>
  iterator find(const Key& k) {
    iterator it = lower_bound(k);
    if (it != end() && !comp_(k, *it))
      return it;
    return end();
  }

  template <typename Key>
  const_iterator find(const Key& k) const {
    const_iterator it = lower_bound(k);
    if (it != end() && !comp_(k, *it))
      return it;
    return end();
  }

  template <typename Key>
  iterator lower_bound(const Key& k) {
    node_pointer root_node = root();
    node_pointer ret       = end_;
    while (root_node != u_nullptr) {
      if (!comp_(root_node->data, k)) {
        ret       = root_node;
        root_node = root_node->left;
      } else
        root_node = root_node->right;
    }
    return iterator(ret);
  }

  template <typename Key>
  const_iterator lower_bound(const Key& k) const {
    node_pointer root_node = root();
    node_pointer ret       = end_;
    while (root_node != u_nullptr) {
      if (!comp_(root_node->data, k)) {
        ret       = root_node;
        root_node = root_node->left;
      } else
        root_node = root_node->right;
    }
    return const_iterator(ret);
  }

  template <typename Key>
  iterator upper_bound(const Key& k) {
    node_pointer root_node = root();
    node_pointer ret       = end_;

    while (root_node != u_nullptr) {
      if (comp_(k, root_node->data)) {
        ret       = root_node;
        root_node = root_node->left;
      } else
        root_node = root_node->right;
    }
    return iterator(ret);
  }

  template <typename Key>
  const_iterator upper_bound(const Key& k) const {
    node_pointer root_node = root();
    node_pointer ret       = end_;

    while (root_node != u_nullptr) {
      if (comp_(k, root_node->data)) {
        ret       = root_node;
        root_node = root_node->left;
      } else
        root_node = root_node->right;
    }
    return const_iterator(ret);
  }

  // * modifiers
  void swap(rb_tree& x) {
    std::swap(end_, x.end_);
    std::swap(begin_, x.begin_);
    std::swap(comp_, x.comp_);
    std::swap(alloc_, x.alloc_);
    std::swap(size_, x.size_);
  }

  pair<iterator, bool> insert(const_reference data) {
    node_pointer  Parent;
    node_pointer  new_node = create_node(data);
    node_pointer& dest     = find_pos(Parent, data);
    node_pointer  ret      = dest;
    bool          inserted = false;
    if (dest == u_nullptr) {
      dest         = new_node;
      ret          = dest;
      dest->parent = Parent;
      if (begin_->left != u_nullptr)
        begin_ = begin_->left;
      rebuild_insert(new_node);
      inserted = true;
      ++size_;
    }
    //    node_pointer ret = reinterpret_cast<node_pointer>(dest);
    return pair<iterator, bool>(iterator(ret), inserted);
  }

  iterator insert(iterator hint, const_reference data) {
    node_pointer  Parent;
    node_pointer  new_node = create_node(data);
    node_pointer  dummy;
    node_pointer& dest = find_pos(hint, Parent, dummy, data);
    node_pointer  ret  = dest;

    if (dest == u_nullptr) {
      dest         = new_node;
      ret          = dest;
      dest->parent = Parent;
      if (begin_->left != u_nullptr)
        begin_ = begin_->left;
      rebuild_insert(new_node);
      ++size_;
    }
    return iterator(ret);
  }

  template <typename InputIterator>
  void insert(InputIterator first, InputIterator last) {
    for (; first != last; ++first)
      insert(*first);
  }

  void erase(iterator pos) { remove_node_pointer(pos.base()); }

  void clear() {
    delete_tree(root());
    begin_     = end_;
    size_      = 0;
    end_->left = u_nullptr;
  }
};
}  // namespace ft

#endif  // RBTREE_RBTREE_HPP
