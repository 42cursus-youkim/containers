#ifndef UTILS_BINARY_FUNCTION_HPP
#define UTILS_BINARY_FUNCTION_HPP

namespace ft {

template <class Arg1, class Arg2, class Result>
struct binary_function {
  typedef Arg1 first_argument_type;
  typedef Arg2 second_argument_type;
  typedef Result result_type;
};

}  // namespace ft

#endif // UTILS_BINARY_FUNCTION_HPP
