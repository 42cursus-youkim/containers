#ifndef GENERAL_BINARY_FUNCTION_HPP
#define GENERAL_BINARY_FUNCTION_HPP

// FIXME: remove?

namespace ft {
template <typename Arg1, typename Arg2, typename Result>
struct binary_function {
  typedef Arg1 first_argument_type;
  typedef Arg2 second_argument_type;
  typedef Result result_type;
};
}  // namespace ft

#endif  // GENERAL_BINARY_FUNCTION_HPP
