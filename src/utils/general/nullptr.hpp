#ifndef GENERAL_NULLPTR_HPP
#define GENERAL_NULLPTR_HPP

namespace ft {

/**
 * @brief nullptr implementation.
 *
 * creates a const object nullptr that is not copyable and not assignable.
 *
 * https://www.stroustrup.com/N1488-nullptr.pdf
 */
const class {
 public:
  template <typename T>
  operator T*() const {
    return 0;
  }
  template <typename C, typename T>
  operator T C::*() const {
    return 0;
  }

 private:
  // address of it cannot be taken.
  void operator&() const;
} nullptr = {};

}  // namespace ft

#endif // GENERAL_NULLPTR_HPP
