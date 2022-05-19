#ifndef TEST_PAIR_HPP
#define TEST_PAIR_HPP

#include <typeinfo>
#include <utility>
#include <utils/pair/pair.hpp>
#include "utils/util/util.hpp"

#define PAIR_TEST_MEMBER_EQ(a, b)                  \
  do {                                             \
    ASSERT_EQ(a.first, b.first);                   \
    ASSERT_EQ(a.second, b.second);                 \
    ASSERT_EQ(typeid(a.first), typeid(b.first));   \
    ASSERT_EQ(typeid(a.second), typeid(b.second)); \
  } while (0)

#define PAIR_TEST_EQ(a, b)           \
  do {                               \
    ASSERT_EQ(a, b);                 \
    ASSERT_EQ(typeid(a), typeid(b)); \
    PAIR_TEST_MEMBER_EQ(a, b);       \
  } while (0)

#define PAIR_DOUBLE_DECL(type, param) \
  std::type<T1, T2> std_##type param; \
  ft::type<T1, T2> ft_##type param;

#define PAIR_DOUBLE_ASGN(type, assign)        \
  std::type<T1, T2> std_##type = std::assign; \
  ft::type<T1, T2>  ft_##type  = ft::assign;

namespace test {
namespace pair {

template <typename T1, typename T2>
void test_pair(T1 a, T2 b) {
  TEST_SUBJECT;
  PAIR_DOUBLE_DECL(pair, (a, b));

  PAIR_TEST_MEMBER_EQ(std_pair, ft_pair);
}

template <typename T1, typename T2>
void test_make_pair(T1 a, T2 b) {
  TEST_SUBJECT;
  PAIR_DOUBLE_ASGN(pair, make_pair(a, b));

  PAIR_TEST_MEMBER_EQ(std_pair, ft_pair);
}

template <typename T1, typename T2>
void test_pair_is_make_pair(T1 a, T2 b) {
  TEST_SUBJECT;
  ft::pair<T1, T2> direct(a, b);
  ft::pair<T1, T2> from_make = ft::make_pair(a, b);

  PAIR_TEST_EQ(direct, from_make);
}

template <typename T1, typename T2>
void test_all(T1 a, T2 b) {
  header("pair");
  test_pair(a, b);
  test_make_pair(a, b);
  test_pair_is_make_pair(a, b);
}

}  // namespace pair
}  // namespace test

#endif  // TEST_PAIR_HPP
