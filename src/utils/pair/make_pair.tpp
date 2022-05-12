#ifndef PAIR_MAKE_PAIR_TPP
#define PAIR_MAKE_PAIR_TPP

namespace ft {

template <class T1, class T2>
pair<T1, T2> make_pair(T1 x, T2 y) {
  return (ft::pair<T1, T2>(x, y));
}

}  // namespace ft

#endif  // PAIR_MAKE_PAIR_TPP
