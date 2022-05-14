#ifndef TEST_PAIR_HPP
#define TEST_PAIR_HPP

#include <typeinfo>
#include <utility>
#include <pair/pair.hpp>
#include "util.hpp"

#define TEST_PAIR_MEMBER_EQ(a, b)                  \
  do {                                             \
    ASSERT_EQ(a.first, b.first);                   \
    ASSERT_EQ(a.second, b.second);                 \
    ASSERT_EQ(typeid(a.first), typeid(b.first));   \
    ASSERT_EQ(typeid(a.second), typeid(b.second)); \
  } while (0)

#define TEST_PAIR_EQ(a, b)           \
  do {                               \
    ASSERT_EQ(a, b);                 \
    ASSERT_EQ(typeid(a), typeid(b)); \
    TEST_PAIR_MEMBER_EQ(a, b);       \
  } while (0)

namespace test {
namespace pair {

template <typename T1, typename T2>
void test_pair(T1 a, T2 b) {
  std::pair<T1, T2> std_pair(a, b);
  ft::pair<T1, T2> ft_pair(a, b);

  TEST_PAIR_MEMBER_EQ(std_pair, ft_pair);
}

template <typename T1, typename T2>
void test_make_pair(T1 a, T2 b) {
  std::pair<T1, T2> std_pair = std::make_pair(a, b);
  ft::pair<T1, T2> ft_pair = ft::make_pair(a, b);

  TEST_PAIR_MEMBER_EQ(std_pair, ft_pair);
}

template <typename T1, typename T2>
void test_pair_is_make_pair(T1 a, T2 b) {
  ft::pair<T1, T2> direct(a, b);
  ft::pair<T1, T2> from_make = ft::make_pair(a, b);

  TEST_PAIR_EQ(direct, from_make);
}
}  // namespace pair
}  // namespace test

#endif  // TEST_PAIR_HPP
