#ifndef ITERATOR_TAG_HPP
#define ITERATOR_TAG_HPP

namespace ft {

/**
 * @brief empty tag to identify categories of iterators.
 */
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};

}  // namespace ft

#endif  // ITERATOR_TAG_HPP
