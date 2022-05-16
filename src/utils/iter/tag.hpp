#ifndef ITER_TAG_HPP
#define ITER_TAG_HPP

#include <utils/tmp/integral_constant.hpp>

namespace ft {

/**
 * @brief empty tag to identify categories of iterators.
 */
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};

/// template boolean for enable_if

template <typename T>
struct __is_input_iterator_tag : false_type {};

template <>
struct __is_input_iterator_tag<input_iterator_tag> : true_type {};

template <>
struct __is_input_iterator_tag<forward_iterator_tag> : true_type {};

template <>
struct __is_input_iterator_tag<bidirectional_iterator_tag> : true_type {};

template <typename T>
struct __is_random_access_iterator_tag : false_type {};

template <>
struct __is_random_access_iterator_tag<random_access_iterator_tag> : true_type {
};

}  // namespace ft

#endif  // ITER_TAG_HPP
