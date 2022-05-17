#ifndef GENERAL_u_nullptrPTR_HPP
#define GENERAL_u_nullptrPTR_HPP

namespace ft {

const class nullptr_t {
 public:
  /// converts to any type pointer that is u_nullptr
  template <typename T>
  operator T*() const {
    return 0;
  }

  /// converts to any member u_nullptr pointer
  template <typename C, typename T>
  operator T C::*() const {
    return 0;
  }

 private:
  /// disable referencing (get its address)
  void operator&() const;

} u_nullptr;

}  // namespace ft

#endif  // GENERAL_u_nullptrPTR_HPP
