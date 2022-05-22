#ifndef _VECTOR_ITERATOR_HPP
#define _VECTOR_ITERATOR_HPP

#include <memory>
#include <vector>
#include <utils/iter/reverse_iterator.hpp>
#include <utils/iter/tag.hpp>
#include <utils/tmp/enable_if.hpp>

namespace ft {

template <typename, typename>
struct are_same {
  enum { value = 0 };
  typedef false_type type;
};
template <typename _Tp>
struct are_same<_Tp, _Tp> {
  enum { value = 1 };
  typedef true_type type;
};

template <typename Iterator, typename Container>
class normal_iterator {
 protected:
  Iterator                          current_;
  typedef iterator_traits<Iterator> traits_type;

 public:
  typedef Iterator                                iterator_type;
  typedef typename traits_type::iterator_category iterator_category;
  typedef typename traits_type::value_type        value_type;
  typedef typename traits_type::difference_type   difference_type;
  typedef typename traits_type::reference         reference;
  typedef typename traits_type::pointer           pointer;
  normal_iterator() : current_(Iterator()) {}
  explicit normal_iterator(const Iterator& i) : current_(i) {}
  // Allow iterator to const_iterator conversion
  template <typename Iter>
  normal_iterator(
      const normal_iterator<
          Iter,
          typename enable_if<
              (are_same<Iter, typename Container::pointer>::value),
              Container>::type>& i)
      : current_(i.base()) {}
  // Forward iterator requirements
  reference        operator*() const { return *current_; }
  pointer          operator->() const { return current_; }
  normal_iterator& operator++() {
    ++current_;
    return *this;
  }
  normal_iterator operator++(int) {
    return normal_iterator(current_++);
  }
  // Bidirectional iterator requirements
  normal_iterator& operator--() {
    --current_;
    return *this;
  }
  normal_iterator operator--(int) {
    return normal_iterator(current_--);
  }
  // Random access iterator requirements
  reference operator[](difference_type n) const {
    return current_[n];
  }
  normal_iterator& operator+=(difference_type n) {
    current_ += n;
    return *this;
  }
  normal_iterator operator+(difference_type n) const {
    return normal_iterator(current_ + n);
  }
  normal_iterator& operator-=(difference_type n) {
    current_ -= n;
    return *this;
  }
  normal_iterator operator-(difference_type n) const {
    return normal_iterator(current_ - n);
  }
  const Iterator& base() const { return current_; }
};

// Forward iterator requirements
template <typename IteratorL, typename IteratorR, typename Container>
inline bool operator==(
    const normal_iterator<IteratorL, Container>& left,
    const normal_iterator<IteratorR, Container>& right) {
  return left.base() == right.base();
}
template <typename _Iterator, typename Container>
inline bool operator==(
    const normal_iterator<_Iterator, Container>& left,
    const normal_iterator<_Iterator, Container>& right) {
  return left.base() == right.base();
}
template <typename IteratorL, typename IteratorR, typename Container>
inline bool operator!=(
    const normal_iterator<IteratorL, Container>& left,
    const normal_iterator<IteratorR, Container>& right) {
  return left.base() != right.base();
}
template <typename _Iterator, typename Container>
inline bool operator!=(
    const normal_iterator<_Iterator, Container>& left,
    const normal_iterator<_Iterator, Container>& right) {
  return left.base() != right.base();
}
// Random access iterator requirements
template <typename IteratorL, typename IteratorR, typename Container>
inline bool operator<(
    const normal_iterator<IteratorL, Container>& left,
    const normal_iterator<IteratorR, Container>& right) {
  return left.base() < right.base();
}
template <typename _Iterator, typename Container>
inline bool operator<(
    const normal_iterator<_Iterator, Container>& left,
    const normal_iterator<_Iterator, Container>& right) {
  return left.base() < right.base();
}
template <typename IteratorL, typename IteratorR, typename Container>
inline bool operator>(
    const normal_iterator<IteratorL, Container>& left,
    const normal_iterator<IteratorR, Container>& right) {
  return left.base() > right.base();
}
template <typename _Iterator, typename Container>
inline bool operator>(
    const normal_iterator<_Iterator, Container>& left,
    const normal_iterator<_Iterator, Container>& right) {
  return left.base() > right.base();
}
template <typename IteratorL, typename IteratorR, typename Container>
inline bool operator<=(
    const normal_iterator<IteratorL, Container>& left,
    const normal_iterator<IteratorR, Container>& right) {
  return left.base() <= right.base();
}
template <typename _Iterator, typename Container>
inline bool operator<=(
    const normal_iterator<_Iterator, Container>& left,
    const normal_iterator<_Iterator, Container>& right) {
  return left.base() <= right.base();
}
template <typename IteratorL, typename IteratorR, typename Container>
inline bool operator>=(
    const normal_iterator<IteratorL, Container>& left,
    const normal_iterator<IteratorR, Container>& right) {
  return left.base() >= right.base();
}
template <typename _Iterator, typename Container>
inline bool operator>=(
    const normal_iterator<_Iterator, Container>& left,
    const normal_iterator<_Iterator, Container>& right) {
  return left.base() >= right.base();
}


// According to the resolution of DR179 not only the various
// comparison operators but also operator- must accept mixed
// iterator/const_iterator parameters.
template <typename IteratorL, typename IteratorR, typename Container>

inline typename normal_iterator<IteratorL, Container>::difference_type
operator-(const normal_iterator<IteratorL, Container>& left,
          const normal_iterator<IteratorR, Container>& right) {
  return left.base() - right.base();
}
template <typename _Iterator, typename Container>
inline typename normal_iterator<_Iterator, Container>::difference_type
operator-(const normal_iterator<_Iterator, Container>& left,
          const normal_iterator<_Iterator, Container>& right) {
  return left.base() - right.base();
}
template <typename _Iterator, typename Container>
inline normal_iterator<_Iterator, Container> operator+(
    typename normal_iterator<_Iterator, Container>::difference_type n,
    const normal_iterator<_Iterator, Container>& i) {
  return normal_iterator<_Iterator, Container>(i.base() + n);
}

}  // namespace ft

#endif  // _VECTOR_ITERATOR_HPP
