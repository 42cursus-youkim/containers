#ifndef PAIR_CONSTRUCTOR_TPP
#define PAIR_CONSTRUCTOR_TPP

namespace ft {

typedef pair<T1, T2>::first_type first_type;
typedef pair<T1, T2>::second_type second_type;

/** @brief default constructor.
 *
 * value initialized.
 */
pair<class T1, class T2>::pair() : first(), second() {}

/** @brief copy constructor.
 *
 *  @param a
 */
pair<class T1, class T2>::pair(const first_type& a, const second_type& b)
    : first(a), second(b) {}

/**
 * @brief initialization constructor.
 *
 * @param pr
 */
template <class U, class V>
pair<class T1, class T2>::pair(const pair<U, V>& pr)
    : first(pr.first), second(pr.second) {}
}  // namespace ft

#endif  // PAIR_CONSTRUCTOR_TPP
