#ifndef GENERAL_NULLPTR_HPP
#define GENERAL_NULLPTR_HPP

namespace ft {

const class nullptr_t {
 public:
  /// converts to any type pointer that is NULL
  template <typename T>
  operator T*() const {
    return 0;
  }

  /// converts to any member NULL pointer
  template <typename C, typename T>
  operator T C::*() const {
    return 0;
  }

 private:
  /// disable referencing (get its address)
  void operator&() const;

} u_nullptr;

}  // namespace ft

#endif  // GENERAL_NULLPTR_HPP
